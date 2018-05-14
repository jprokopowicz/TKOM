//
// Created by jacek on 07.05.18.
//


#include "Variable.h"
#include "../Exceptions/Exception.h"

Variable::Variable(std::string id,Type type_, int i, double f, bool b, std::string s)
        :identifier(id), type(type_), value_i(i), value_f(f), value_b(b), value_s(s){}

Variable::Variable(const Variable & other): identifier(other.identifier), type(other.type) {
    value_i = other.value_i;
    value_f = other.value_f;
    value_b = other.value_b;
    value_s = other.value_s;
}

bool Variable::operator<(const Variable & other) const {
    if((type == Variable::Type::Int_ || type == Variable::Type::Float_)&&(other.type == Variable::Type::Int_ || other.type == Variable::Type::Float_))
        return (type==Variable::Type ::Int_?value_i:value_f) < (other.type == Variable::Type ::Int_?other.value_i:value_f);
    throwIncompatibleOperator({Variable::Type::Bool_,Variable::Type ::String_}, "<");
}

bool Variable::operator>(const Variable & other) const {
    if((type == Variable::Type::Int_ || type == Variable::Type::Float_)&&(other.type == Variable::Type::Int_ || other.type == Variable::Type::Float_))
        return (type==Variable::Type ::Int_?value_i:value_f) > (other.type == Variable::Type ::Int_?other.value_i:value_f);
    throwIncompatibleOperator({Variable::Type::Bool_,Variable::Type ::String_}, ">");
}

bool Variable::operator<=(const Variable & other) const {
    if((type == Variable::Type::Int_ || type == Variable::Type::Float_)&&(other.type == Variable::Type::Int_ || other.type == Variable::Type::Float_))
        return (type==Variable::Type ::Int_?value_i:value_f) <= (other.type == Variable::Type ::Int_?other.value_i:value_f);
    throwIncompatibleOperator({Variable::Type::Bool_,Variable::Type ::String_}, "<=");
}

bool Variable::operator>=(const Variable & other) const {
    if((type == Variable::Type::Int_ || type == Variable::Type::Float_)&&(other.type == Variable::Type::Int_ || other.type == Variable::Type::Float_))
        return (type==Variable::Type ::Int_?value_i:value_f) >= (other.type == Variable::Type ::Int_?other.value_i:value_f);
    throwIncompatibleOperator({Variable::Type::Bool_,Variable::Type ::String_}, ">=");
}

bool Variable::operator==(const Variable & other) const {
    if(type == Variable::Type::Bool_ || other.type == Variable::Type::Bool_)
        return value_b == other.value_b;
    if(type == Variable::Type::String_ || other.type == Variable::Type::String_)
        return value_s == other.value_s;
    if((type == Variable::Type::Int_ || type == Variable::Type::Float_)&&(other.type == Variable::Type::Int_ || other.type == Variable::Type::Float_))
        return (type==Variable::Type ::Int_?value_i:value_f) == (other.type == Variable::Type ::Int_?other.value_i:value_f);
    else
        throw Exception("Incompatible types in operator ==");
}

bool Variable::operator!=(const Variable & other) const {
    return !(*this==other);
}

Variable Variable::operator+(Variable & other) {
    if((type == Variable::Type::Int_ || type == Variable::Type::Float_)&&(other.type == Variable::Type::Int_ || other.type == Variable::Type::Float_)){
        if(type == Variable::Type::Int_ &&  other.type == Variable::Type::Int_)
            return Variable(identifier + other.identifier,Variable::Type::Int_,value_i + other.value_i);
        if(type == Variable::Type::Int_ &&  other.type == Variable::Type::Float_)
            return Variable(identifier + other.identifier,Variable::Type::Float_,0,(double)value_i + other.value_f);
        if(type == Variable::Type::Float_ &&  other.type == Variable::Type::Int_)
            return Variable(identifier + other.identifier,Variable::Type::Float_,0,value_f + (double)other.value_i);
        if(type == Variable::Type::Float_ &&  other.type == Variable::Type::Float_)
            return Variable(identifier + other.identifier,Variable::Type::Float_,0,value_f + other.value_f);
    }else
    throwIncompatibleOperator({Variable::Type::Bool_,Variable::Type::String_},"+");
}

Variable Variable::operator-(Variable & other) {
    if((type == Variable::Type::Int_ || type == Variable::Type::Float_)&&(other.type == Variable::Type::Int_ || other.type == Variable::Type::Float_)){
        if(type == Variable::Type::Int_ &&  other.type == Variable::Type::Int_)
            return Variable(identifier + other.identifier,Variable::Type::Int_,value_i - other.value_i);
        if(type == Variable::Type::Int_ &&  other.type == Variable::Type::Float_)
            return Variable(identifier + other.identifier,Variable::Type::Float_,0,(double)value_i - other.value_f);
        if(type == Variable::Type::Float_ &&  other.type == Variable::Type::Int_)
            return Variable(identifier + other.identifier,Variable::Type::Float_,0,value_f - (double)other.value_i);
        if(type == Variable::Type::Float_ &&  other.type == Variable::Type::Float_)
            return Variable(identifier + other.identifier,Variable::Type::Float_,0,value_f - other.value_f);
    }else
        throwIncompatibleOperator({Variable::Type::Bool_,Variable::Type::String_},"+");
}


Variable Variable::operator*(Variable & other) {
    if((type == Variable::Type::Int_ || type == Variable::Type::Float_)&&(other.type == Variable::Type::Int_ || other.type == Variable::Type::Float_)){
        if(type == Variable::Type::Int_ &&  other.type == Variable::Type::Int_)
            return Variable(identifier + other.identifier,Variable::Type::Int_,value_i * other.value_i);
        if(type == Variable::Type::Int_ &&  other.type == Variable::Type::Float_)
            return Variable(identifier + other.identifier,Variable::Type::Float_,0,(double)value_i * other.value_f);
        if(type == Variable::Type::Float_ &&  other.type == Variable::Type::Int_)
            return Variable(identifier + other.identifier,Variable::Type::Float_,0,value_f * (double)other.value_i);
        if(type == Variable::Type::Float_ &&  other.type == Variable::Type::Float_)
            return Variable(identifier + other.identifier,Variable::Type::Float_,0,value_f * other.value_f);
    }else
        throwIncompatibleOperator({Variable::Type::Bool_,Variable::Type::String_},"+");
}


Variable Variable::operator/(Variable & other) {
    if((type == Variable::Type::Int_ || type == Variable::Type::Float_)&&(other.type == Variable::Type::Int_ || other.type == Variable::Type::Float_)){
        if(type == Variable::Type::Int_ &&  other.type == Variable::Type::Int_)
            return Variable(identifier + other.identifier,Variable::Type::Int_,value_i / other.value_i);
        if(type == Variable::Type::Int_ &&  other.type == Variable::Type::Float_)
            return Variable(identifier + other.identifier,Variable::Type::Float_,0,(double)value_i / other.value_f);
        if(type == Variable::Type::Float_ &&  other.type == Variable::Type::Int_)
            return Variable(identifier + other.identifier,Variable::Type::Float_,0,value_f / (double)other.value_i);
        if(type == Variable::Type::Float_ &&  other.type == Variable::Type::Float_)
            return Variable(identifier + other.identifier,Variable::Type::Float_,0,value_f / other.value_f);
    }else
        throwIncompatibleOperator({Variable::Type::Bool_,Variable::Type::String_},"+");
}


Variable Variable::operator-() {
    if(type == Variable::Type::Int_)
        return Variable("-" + identifier, type,-value_i);
    if(type == Variable::Type::Float_)
        return Variable("-" + identifier, type,0,-value_f);
    throwIncompatibleOperator({Variable::Type::Bool_,Variable::Type::String_},"-");

}

Variable Variable::operator%(Variable & other) {
    if(type == Variable::Type::Int_ && other.type == Variable::Type::Int_)
        return Variable("-" + identifier,Variable::Type::Bool_,value_i % other.value_i);
    throwIncompatibleOperator({Variable::Type::Float_, Variable::Type::Bool_, Variable::Type::String_},"-");
}

Variable Variable::operator|(Variable & other) {
    if(type == Variable::Type::Bool_&& other.type == Variable::Type::Bool_)
        return Variable("!" + identifier,Variable::Type::Bool_,0,0.0,value_b || other.value_b);
    throwIncompatibleOperator({Variable::Type::Int_, Variable::Type::Float_, Variable::Type::String_},"-");
}

Variable Variable::operator&(Variable & other) {
    if(type == Variable::Type::Bool_&& other.type == Variable::Type::Bool_)
        return Variable("!" + identifier,Variable::Type::Bool_,0,0.0,!value_b && other.value_b);
    throwIncompatibleOperator({Variable::Type::Int_, Variable::Type::Float_, Variable::Type::String_},"-");
}

Variable Variable::operator!() {
    if(type == Variable::Type::Bool_)
        return Variable("!" + identifier,Variable::Type::Bool_,0,0.0,!value_b);
    throwIncompatibleOperator({Variable::Type::Int_, Variable::Type::Float_, Variable::Type::String_},"-");
}

void Variable::throwIncompatibleOperator(std::list<Variable::Type> varTypes_, std::string operator_) const {
    std::string communicate = "Incompatible operator " + operator_ + " for one of variable types:  " , varType;
    for(auto I = varTypes_.begin();I!=varTypes_.end();++I) {
        switch (*I) {
            case Int_:
                varType = "integer";
                break;
            case Float_:
                varType = "float";
                break;
            case Bool_:
                varType = "boolean";
                break;
            case String_:
                varType = "string";
                break;
            case None_:
                varType = "Void";
                break;
            default:
                throw Exception("variable type error");
        }
        communicate += (varType + " ");
    }
    throw Exception(communicate);
}


