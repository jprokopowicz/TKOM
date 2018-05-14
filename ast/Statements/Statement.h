//
// Created by jacek on 12.05.18.
//

#ifndef TKOM_STATEMENT_H
#define TKOM_STATEMENT_H


#include "../Return.h"

class Statement {
public:
    Statement();

    virtual Return run();
};


#endif //TKOM_STATEMENT_H
