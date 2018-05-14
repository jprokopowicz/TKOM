//
// Created by jacek on 07.05.18.
//

#include "Parser.h"
#include "../Exceptions/Exception.h"
#include "../ast/Function.h"

Parser::Parser(std::istream& istream) : lexer(istream){
}


bool Parser::accept(Token::Type type_) {
    return lexer.getToken().type == type_;
}

bool Parser::readAndAccept(Token::Type type_) {
    lexer.readNextToken();
    return accept(type_);
}

void Parser::acceptOrThrow(Token::Type type_) {
    if(!accept(type_)){
        auto currentToken = lexer.getToken();
        throwExpectedTokens({type_},currentToken);
    }
}

void Parser::readAndAcceptOrThrow(Token::Type type_) {
    lexer.readNextToken();
    acceptOrThrow(type_);
}

void Parser::throwExpectedTokens(std::list<Token::Type> expTokens,Token unexpToken) {
    std::string s ="In " + unexpToken.position.write() + " expected tokens:  [";
    for (auto &&token : expTokens)
        s+= Token::getName(token) + ", ";
    s+= "] and not [" + Token::getName(unexpToken.type) + "]";
    throw Exception(s);

}

void Parser::programParse() {
    while(lexer.readNextToken().type!=Token::Type::EndOfFile){
        if(accept(Token::Fun)){
            functionDefinitionParse();
        }else if(accept(Token::Main)){
            mainParse();
        }else
            throwExpectedTokens({Token::Fun,Token::Main},lexer.getToken());
    }

}

void Parser::functionDefinitionParse() {
    Variable::Type returnType;
    switch (lexer.readNextToken().type){
        case Token::Type::Int:
            returnType = Variable::Type::Int_;
            break;
        case Token::Type::Float:

            returnType = Variable::Type::Int_;
            break;
        case Token::Type::Bool:
            returnType = Variable::Type::Int_;
            break;
        case Token::Type::String:
            returnType = Variable::Type::Int_;
            break;
        default:
            throwExpectedTokens({Token::Type::Int,Token::Type::Float,Token::Type::Bool,Token::Type::String,},lexer.getToken());
    }
    readAndAcceptOrThrow(Token::Type::Identifier);
    Function function(returnType,lexer.getToken().value);

    readAndAcceptOrThrow(Token::Type::OpenBracket);
    parametersParse(function);

    readAndAcceptOrThrow(Token::Type::OpenStatement);
    statementBlockParse(function);

}

void Parser::parametersParse(Function & function) {
    if(readAndAccept(Token::Type::CloseBracket))
        return;
    Variable newVariable = variableParse();
    function.arguments.push_back(newVariable);
    while(readAndAccept(Token::Type::Comma)) {
        lexer.readNextToken();
        newVariable = variableParse();
        function.arguments.push_back(newVariable);
    }
    acceptOrThrow(Token::Type::CloseBracket);
    return;
}

Variable Parser::variableParse() {
    acceptOrThrow(Token::Type::Var);
    Token::Type t = lexer.readNextToken().type;
    Variable::Type var_t;
    if(t != Token::Type::Int && t != Token::Type::Float && t != Token::Type::Bool && t !=Token::Type::String)
            throwExpectedTokens({Token::Type::Int,Token::Type::Float,Token::Type::Bool,Token::Type::String,},lexer.getToken());
    switch (t){
        case Token::Type::Int:
            var_t = Variable::Type ::Int_;
            break;
        case Token::Type::Float:
            var_t = Variable::Type ::Float_;
            break;
        case Token::Type::Bool:
            var_t = Variable::Type ::Bool_;
            break;
        case Token::Type::String:
            var_t = Variable::Type ::String_;
            break;
        default:
            throwExpectedTokens({Token::Type::Int,Token::Type::Float,Token::Type::Bool,Token::Type::String,},lexer.getToken());
    }
    readAndAcceptOrThrow(Token::Type::Identifier);
    return Variable(lexer.getToken().value,var_t);
}

void Parser::statementBlockParse(Function &) {

}

void Parser::mainParse() {
    Function main(Variable::Type::None_,lexer.getToken().value);
    readAndAcceptOrThrow(Token::Type::OpenStatement);

}



