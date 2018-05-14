//
// Created by jacek on 12.05.18.
//

#include "Return.h"

Return::Return(Variable *variable) : variable(NULL) {}

Return::~Return() {
    if(variable)
        delete variable;
}
