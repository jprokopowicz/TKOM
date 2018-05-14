#ifndef SIMPLELANGUAGEINTERPRETER_EXPRESSION_H
#define SIMPLELANGUAGEINTERPRETER_EXPRESSION_H

#include <iostream>
#include "../../Positon/Position.h"

class Expression {
public:
    Expression();
    virtual ~Expression();
    //Position position;
    //virtual std::string toString() const = 0;
};


#endif //SIMPLELANGUAGEINTERPRETER_EXPRESSION_H