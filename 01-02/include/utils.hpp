#include <string>
#include <vector>

bool checkBrackets(std::string x);

bool isDigit(char& ch);

bool isNum(std::string n);

bool isAllowedChar(char& ch);

void removeLastEqualSignIfExist(std::string& e);

std::string optimizeBrackets(std::string e);

std::string formatExpression(std::string e);

std::vector<std::string> getBySign(std::string e, char sign);

float calculate(std::string e);