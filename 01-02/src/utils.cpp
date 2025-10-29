#include "utils.hpp"
#include "models.hpp"
#include "constants.hpp"
#include <iostream>

bool checkBrackets(std::string x) {
    CharStack stack;
    try {
        for (size_t i = 0; i < x.size(); ++i) {
            char v = x[i];
            if (v == OPENING_CURLY_BRACKET) stack.push(CLOSING_CURLY_BRACKET);
            else if (v == OPENING_BRACKET) stack.push(CLOSING_BRACKET);
            else if (v == OPENING_SQUARE_BRACKET) stack.push(CLOSING_SQUARE_BRACKET);
            else if (CLOSING_BRACKETS.find(v) != std::string::npos) {
                if (v == stack.peek()) stack.pop();
                else return false;
            }
        }
    } catch (const std::out_of_range& e) { return false; }
    if (!stack.isEmpty()) return false;
    return true;
}

bool isDigit(char& ch) {
    return DIGITS.find(ch) != std::string::npos; 
}

bool isNum(std::string n) {
    for (size_t i = 0; i < n.size(); ++i) {
        if (i == 0 && n[i] == MINUS) continue;
        if (NUM_CHARS.find(n[i]) == std::string::npos) return false;
    }
    return true;
    
}

bool isAllowedChar(char& ch) { 
    return ALLOWED_CHARS.find(ch) != std::string::npos;
}

void removeLastEqualSignIfExist(std::string& e) {
    if (e[e.size() - 1] == EQUAL) e = e.substr(0, e.size() - 1);
}

void replaceRussianPointIfExist(std::string& e) {
    std::string res;
    for (size_t i = 0; i < e.size(); ++i) {
        char ch = e[i];
        if (ch == RUSSIAN_POINT) ch = POINT;
        res += ch;
    }
    e = res;
}

std::string optimizeBrackets(std::string e) {
    if (e[0] != OPENING_BRACKET || e[e.size() - 1] != CLOSING_BRACKET) return e;
    size_t brackets_counter = 0;
    for (size_t i = 0; i < e.size(); ++i) {
        if (e[i] == OPENING_BRACKET && e[e.size() - 1 - i] == CLOSING_BRACKET) brackets_counter++;
        else break;
    }
    for (size_t i = brackets_counter; i > 0; --i) {
        std::string part = e.substr(i, e.size() - i * 2);
        if (checkBrackets(part)) return part;
    }
    return e;
}

std::string formatExpression(std::string e) {
    removeLastEqualSignIfExist(e);
    if (!checkBrackets(e)) throw std::invalid_argument(INCORRECT_EXPRESSION);
    e = optimizeBrackets(e);
    replaceRussianPointIfExist(e);
    std::string res;
    for (size_t i = 0; i < e.size(); ++i) {
        char ch = e[i];
        if (ch == SPACE) continue;
        if (!isAllowedChar(ch)) throw std::invalid_argument(INCORRECT_EXPRESSION);
        if (ch == MINUS && i != 0 && e[i - 1] != PLUS) res += PLUS;
        if (ch == OPENING_BRACKET && i != 0) {
            char prev = e[i - 1];
            if (isDigit(prev)) e += MULTIPLY;
            else if ((prev != MULTIPLY && prev != DIVIDE)) res += "1*";
        }
        if (isDigit(ch) && i != 0 && e[i - 1] == CLOSING_BRACKET) res += MULTIPLY;
        res += ch;
    }
    return res;
}

std::vector<std::string> getBySign(std::string e, char sign) {
    std::vector<std::string> element;
    size_t start_bracket = -1;
    size_t start = 0;
    std::string sub_e;
    CharStack brackets;
    for (size_t i = 0; i < e.size(); ++i) {
        char ch = e[i];
        if (ch == OPENING_BRACKET) {
            brackets.push(CLOSING_BRACKET);
            if (start_bracket == -1) start_bracket = i;
        }
        else if (!brackets.isEmpty() && ch == brackets.peek()) {
            brackets.pop();
            if (brackets.isEmpty()) {
                int count = i - start_bracket + 1;
                sub_e += e.substr(start_bracket, count);
                start_bracket = -1;
            }
        }
        else if (start_bracket != -1) continue;
        else if (ch == sign) {
            element.push_back(sub_e);
            sub_e = "";
            start = i + 1;
        }
        else sub_e += e[i];
    }
    element.push_back(sub_e);
    return element;
}

float calculate(std::string e) {
    e = formatExpression(e);
    if (isNum(e)) return std::stof(e);

    float sum = 0;
    auto summands = getBySign(e, PLUS);
    for (size_t s = 0; s < summands.size(); ++s) {
        if (isNum(summands[s])) {
            sum += std::stof(summands[s]);
            continue;
        }
        auto multipliers = getBySign(summands[s], MULTIPLY);
        float composition = 1;
        for (size_t k = 0; k < multipliers.size(); ++k) {
            if (isNum(multipliers[k])) {
                composition *= std::stof(multipliers[k]);
                continue;
            }
            auto dividors = getBySign(multipliers[k], DIVIDE);
            composition *= calculate(dividors[0]);
            for (size_t i = 1; i < dividors.size(); ++i) {
                float calculation = calculate(dividors[i]);
                if (calculation == 0) throw std::runtime_error(ZERO_DIVISION);
                composition /= calculation;
            }
        }
        sum += composition;
    }
    return sum;
}