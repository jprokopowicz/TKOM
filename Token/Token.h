#ifndef TKOM_TOKEN_H
#define TKOM_TOKEN_H

#include <string>
#include <ostream>
#include "../Positon/Position.h"

class Token {
public:
    enum Type : unsigned int{
        ///key words
        Main,
        Fun,
        Str,
        Return,
        If,
        Else,
        Loop,
        Read,
        Write,
        Var,
        Int,
        Float,
        Bool,
        String,
        True,
        False,
        Run,
        Path,
        Program,
        ///Operators with 1 sign
        Plus,
        Minus,
        Star,
        Slash,
        Modulo,
        Or,
        And,
        Not,
        Greater,
        Lesser,
        Dot,
        Comma,
        Semicolon,
        Assignment,
        OpenBracket,
        CloseBracket,
        OpenStatement,
        CloseStatement,
        ///Operators with 2 signs
        GreaterEqual,
        LesserEqual,
        Equal,
        NotEqual,
        OpenProgramExp,
        CloseProgramExp,
        ///Expressions
        StringExpression,
        Identifier,
        NumberInt,
        NumberFloat,
        ///Other
        Invalid,
        EndOfFile,
        Comment,
    };

    Type type;
    std::string value;
    Position position;

    explicit Token();

    static Type FindKeyword(const std::string&);

    static Type FindSign(const char &);

    static std::string getName(const Type &type);

    friend std::ostream& operator<<(std::ostream &os, const Token& token);

};

inline std::ostream& operator<<(std::ostream &os, const Token& token){
    os<< "Token:\t" << Token::getName(token.type) << " \tValue:\t" << token.value <<" \t\tPosition:\t"<< token.position<< "\t";
    return os;
}

#endif //TKOM_TOKEN_H
