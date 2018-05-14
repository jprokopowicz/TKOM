//
// Created by jacek on 12.05.18.
//

#include "Function.h"

Function::Function(Variable::Type returnType_,std::string identifier_) : returnType(returnType_),identifier(identifier_), block(BlockStatement()) {}
