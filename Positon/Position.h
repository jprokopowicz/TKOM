//
// Created by jacek on 07.05.18.
//

#ifndef TKOM_POSITION_H
#define TKOM_POSITION_H


#include <ostream>
#include <string>
class Position {
public:
    unsigned line = 1;
    unsigned sign = 1;
    std::string write(){ return "Line: " + std::to_string(line) + " Sign: " + std::to_string(sign); }
    friend std::ostream& operator<<(std::ostream &os, const Position& pos){
        os<<"Line: "<<pos.line<<" Sign: "<<pos.sign<<" ";
    }
};



#endif //TKOM_POSITION_H
