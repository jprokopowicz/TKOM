//
// Created by jacek on 07.05.18.
//

#ifndef TKOM_VARIABLE_H
#define TKOM_VARIABLE_H

#include <ostream>
#include <list>
#include "../Positon/Position.h"

class Variable {
public:
    enum Type{
        Int_,
        Float_,
        Bool_,
        String_,
        None_
    };

    Type type = None_;
    std::string identifier;
    ///value
    int value_i = 0;
    double value_f = 0.0;
    bool value_b = false;
    std::string value_s = "";
    ///value
    explicit Variable(std::string, Type, int = 0, double = 0.0, bool = false, std::string = "");
    Variable(const Variable&);

    bool operator<(const Variable&) const;

    bool operator>(const Variable&) const;
    bool operator<=(const Variable&) const;
    bool operator>=(const Variable&) const;
    bool operator==(const Variable&) const;
    bool operator!=(const Variable&) const;

    Variable operator+(Variable&);
    Variable operator-(Variable&);
    Variable operator*(Variable&);
    Variable operator/(Variable&);

    Variable operator-();

    Variable operator%(Variable&);

    Variable operator|(Variable&);
    Variable operator&(Variable&);

    Variable operator!();

private:
    void throwIncompatibleOperator(std::list<Variable::Type>, std::string) const ;
};


#endif //TKOM_VARIABLE_H
