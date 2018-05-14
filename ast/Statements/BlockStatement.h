//
// Created by jacek on 12.05.18.
//

#ifndef TKOM_BLOCKSTATEMENT_H
#define TKOM_BLOCKSTATEMENT_H

#include <unordered_map>
#include <list>
#include "../Variable.h"
#include "Statement.h"
#include "../../Token/Token.h"

class BlockStatement : public Statement{
private:
    BlockStatement *parentBlock;
    std::list<Statement*> instructions;
    std::unordered_map<std::string, Variable *> variables;
public:
    explicit BlockStatement(BlockStatement* = nullptr);
    /* BlockStatement(const BlockStatement &) = delete;

    BlockStatement &operator=(BlockStatement &) = delete;

    BlockStatement &operator=(BlockStatement &&other) = default;
    */
    const BlockStatement * getParentBlock() const;
    void addInstruction(Statement *);
    void addVariable(std::string &, Variable &&);
    Variable & findVariable(std::string &,Token = Token());
    void eraseVariable(std::string);
    bool existVariable(std::string);

    Return run() override;

};


#endif //TKOM_BLOCKSTATEMENT_H
