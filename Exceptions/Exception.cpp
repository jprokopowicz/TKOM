//
// Created by jacek on 09.05.18.
//

#include "Exception.h"

Exception::Exception(std::string s_){
    s=s+s_;
}

std::string Exception::throwMsg() {
    std::string msg;
    msg = "Exception: " + s;
    return msg;
}
