//
// Created by jacek on 09.05.18.
//

#ifndef TKOM_EXEPTION_H
#define TKOM_EXEPTION_H


#include <string>
#include "../Positon/Position.h"

struct Exception : public std::exception
{
private:
    std::string s;
public:
    explicit Exception(std::string);

    std::string throwMsg();
};

#endif //TKOM_EXEPTION_H
