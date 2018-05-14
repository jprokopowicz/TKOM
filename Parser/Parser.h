//
// Created by jacek on 07.05.18.
//

#ifndef TKOM_PARSER_H
#define TKOM_PARSER_H

#include <string>
#include <functional>
#include <list>
#include "../ast/Expresion/Expression.h"
#include "../Lexer/Lexer.h"
#include "../ast/Program.h"

class Parser
{
public:

    Parser(std::istream&);

    void run();
    void programParse();

private:

    Lexer lexer;
    Program program;

    bool accept(Token::Type);
    void acceptOrThrow(Token::Type);
    bool readAndAccept(Token::Type);
    void readAndAcceptOrThrow(Token::Type);
    void throwExpectedTokens(std::list<Token::Type>,Token);


    void mainParse();
    void functionDefinitionParse();
    void parametersParse(Function&);
    Variable variableParse();
    void statementBlockParse(Function&);

    Statement* initStatementParse();
    Statement* assignStatementOrFunctionCallParse(Token& tokenId);
    Statement* assignStatementParse(Variable& variable);
    Statement* functionCallParse(Token &tokenId);
    Statement* ifStatementParse();
    Statement* whileStatementParse();
    Statement* returnStatementParse();
    Statement* printStatementParse();

    Expression* logicExprParse();
    Expression* andExprParser();
    Expression* relationalExprParser();
    Expression* baseLogicParser();
    Expression* mathExprParser();
    Expression* multiplicativeExprParser();
    Expression* baseMathExprParser();
};


#endif //TKOM_PARSER_H
