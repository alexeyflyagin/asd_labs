#pragma once
#include <string>

inline constexpr char PLUS = '+';
inline constexpr char MINUS = '-';
inline constexpr char OPENING_BRACKET = '(';
inline constexpr char CLOSING_BRACKET = ')';
inline constexpr char OPENING_CURLY_BRACKET = '{';
inline constexpr char CLOSING_CURLY_BRACKET = '}';
inline constexpr char OPENING_SQUARE_BRACKET = '[';
inline constexpr char CLOSING_SQUARE_BRACKET = ']';
inline constexpr char MULTIPLY = '*';
inline constexpr char DIVIDE = '/';
inline constexpr char SPACE = ' ';
inline constexpr char POINT = '.';
inline constexpr char RUSSIAN_POINT = ',';
inline constexpr char EQUAL = '=';
inline const std::string CLOSING_BRACKETS = std::string() + CLOSING_BRACKET + CLOSING_CURLY_BRACKET + CLOSING_SQUARE_BRACKET;
inline const std::string BRACKETS = std::string() + CLOSING_BRACKETS + CLOSING_BRACKET + CLOSING_CURLY_BRACKET + CLOSING_SQUARE_BRACKET;
inline const std::string DIGITS = "0123456789";
inline const std::string NUM_CHARS = DIGITS + POINT + RUSSIAN_POINT;
inline const std::string ALLOWED_CHARS = DIGITS + DIVIDE + MULTIPLY + MINUS + PLUS + OPENING_BRACKET + CLOSING_BRACKET + POINT + RUSSIAN_POINT;

inline const std::string ENTER_LINE = "Введите строку: ";
inline const std::string LINE_EXISTS = "Строка существует";
inline const std::string LINE_DOESNT_EXIST = "Строка не существует";

inline const std::string INCORRECT_EXPRESSION = "ОШИБКА! Выражение некорректно";
inline const std::string ZERO_DIVISION = "ОШИБКА! Деление на 0 недопустимо!";