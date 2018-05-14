#ifndef TKOM_LEXER_H
#define TKOM_LEXER_H

#include <cctype>
#include "../Reader/Reader.h"
#include "../Token/Token.h"

class Lexer {
private:
    Reader reader;
    Token token;

    void defineKeywordOrIdentifier();
    void defineNumericLiteral();
    void defineSpecialSignOrString();
    void defineStringExpression(std::string&);
    void defineCommentExpression(std::string&);
    void continueToTokenEnd(std::string&);

public:
    explicit Lexer(std::istream&);
    Lexer(const Lexer&) = delete;
    Lexer& operator=(const Lexer&) = delete;

    Token readNextToken();
    Token getToken();

};


#endif //TKOM_LEXER_H