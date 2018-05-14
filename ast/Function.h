//
// Created by jacek on 12.05.18.
//

#ifndef TKOM_FUNCTIONDEFINITION_H
#define TKOM_FUNCTIONDEFINITION_H


#include <string>
#include <list>
#include "Statements/BlockStatement.h"
#include "../Token/Token.h"

class Function {
public:
    Function(Variable::Type,std::string);

    const std::string identifier;
    Variable::Type returnType;
    std::list<Variable> arguments;
    BlockStatement block;


};


#endif //TKOM_FUNCTIONDEFINITION_H
