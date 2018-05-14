//
// Created by jacek on 12.05.18.
//

#include "BlockStatement.h"

BlockStatement::BlockStatement(BlockStatement* parent_) : parentBlock(parent_){

}

const BlockStatement* BlockStatement::getParentBlock() const {
    return parentBlock;
}

void BlockStatement::addInstruction(Statement *) {

}

void BlockStatement::addVariable(std::string &, Variable &&) {

}

/*Variable &BlockStatement::findVariable(std::string &, Token) {
    return <#initializer#>;
}*/

void BlockStatement::eraseVariable(std::string) {

}

bool BlockStatement::existVariable(std::string) {
    return false;
}

Return BlockStatement::run() {
    return Statement::run();
}

