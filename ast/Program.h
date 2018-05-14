//
// Created by jacek on 09.05.18.
//

#ifndef TKOM_PROGRAM_H
#define TKOM_PROGRAM_H


#include <stack>
#include "Variable.h"
#include "Function.h"

class Program {
public:
    std::unordered_map<std::string, Function> functions;

//    Variable* addVariabel(Variable);
};


#endif //TKOM_PROGRAM_H
