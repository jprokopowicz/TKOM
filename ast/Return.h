//
// Created by jacek on 12.05.18.
//

#ifndef TKOM_RETURN_H
#define TKOM_RETURN_H


#include "Variable.h"

class Return {
public:
    Return(Variable *variable);

    virtual ~Return();

    Variable * variable;
};


#endif //TKOM_RETURN_H
