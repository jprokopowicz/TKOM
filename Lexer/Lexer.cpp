#include "Lexer.h"
Lexer::Lexer(std::istream& stream) : reader(stream){

}

Token Lexer::readNextToken(){
    while(std::isspace(reader.peek())&&!reader.eof())//skip all white signs or go to the end of file
        reader.get();
    token = Token();
    token.position = reader.getPosition();

    if(reader.eof()) {
        token.type = Token::Type::EndOfFile;
        return token;
    }

    char c = reader.peek();
    if(std::isalpha(c))
        defineKeywordOrIdentifier();
    else if(std::isdigit(c))
        defineNumericLiteral();
    else
        defineSpecialSignOrString();
    return token;
}

void Lexer::defineKeywordOrIdentifier() {
    std::string buffer;
    buffer += reader.get();
    continueToTokenEnd(buffer);
    Token::Type tokenType = Token::FindKeyword(buffer);
    token.type = tokenType;
    token.value = buffer;
}

void Lexer::defineNumericLiteral() {
    std::string buffer;
    enum State {zero, intNumber, floatNumber, invalid};
    char c = reader.get();
    buffer += c;
    State state;
    if(c == 0 )
        state = zero;
    else
        state = intNumber;
    while(std::isalnum(reader.peek()) || reader.peek() == '_' || reader.peek() == '.' ){
        c = reader.get();
        buffer +=c;
        switch (state) {
            case zero:
                if(c == '.' && std::isdigit(reader.peek()))
                    state = floatNumber;
                else
                    state = invalid;
                break;
            case intNumber:
                if(c == '.')
                    if(std::isdigit(reader.peek()))
                        state = floatNumber;
                    else
                        state = invalid;
                else if(!std::isdigit(c))
                    state = invalid;
                break;
            case floatNumber:
                if(!std::isdigit(c))
                    state = invalid;
                break;
            case invalid:
                continueToTokenEnd(buffer);
                break;
        }
    }
    if(state == zero || state==intNumber)
        token.type = Token::Type::NumberInt;
    else if(state==floatNumber)
        token.type = Token::Type::NumberFloat;
    else
        token.type = Token::Type::Invalid;
    token.value = buffer;
}

void Lexer::defineSpecialSignOrString() {
    char c = reader.get();
    std::string buffer;
    buffer += c;
    switch(c){
        case ',':
            token.type = Token::Type ::Comma;
		    break;
        case '.':
            token.type = Token::Type ::Dot;
		    break;
        case ';':
            token.type = Token::Type ::Semicolon;
		    break;
        case '=':
            if(reader.peek() == '='){
                buffer +=reader.get();
                Token::Type::Equal;
            }else
                token.type = Token::Type ::Assignment;
		    break;
        case '+':
            token.type = Token::Type ::Plus;
		    break;
        case '-':
            token.type = Token::Type ::Minus;
		    break;
        case '"':
            defineStringExpression(buffer);
		    break;
        case '*':
            token.type = Token::Type ::Star;
		    break;
        case '/':
            token.type = Token::Type ::Slash;
		    break;
        case '%':
            token.type = Token::Type ::Modulo;
            break;
        case '|':
            token.type = Token::Type ::Or;
		    break;
		case '&':
            token.type = Token::Type ::And;
		    break;
        case '!':
            if(reader.peek() == '='){
                buffer += reader.get();
                token.type = Token::Type ::NotEqual;
            }else
                token.type = Token::Type ::Not;
		    break;
        case '(':
            token.type = Token::Type ::OpenBracket;
		    break;
        case ')':
            token.type = Token::Type ::CloseBracket;
		    break;
        case '{':
            token.type = Token::Type ::OpenStatement;
		    break;
        case '}':
            token.type = Token::Type ::CloseStatement;
		    break;
        case '<':
            if(reader.peek() == '='){
                buffer += reader.get();
                token.type = Token::Type ::LesserEqual;
            }
            else if(reader.peek() == '<'){
                buffer += reader.get();
                token.type = Token::Type ::OpenProgramExp;
            }
            else
                token.type = Token::Type ::Lesser;
		    break;
        case '>':
            if(reader.peek() == '='){
                buffer += reader.get();
                token.type = Token::Type ::GreaterEqual;
            }
            else if(reader.peek() == '>'){
                buffer += reader.get();
                token.type = Token::Type ::CloseProgramExp;
            }
            else
                token.type = Token::Type ::Greater;
            break;
        case '\\':
            if(reader.peek() == '*')
                defineCommentExpression(buffer);
            else
                token.type = Token::Type ::Invalid;
            break;
        default:
            token.type = Token::Type::Invalid;
    }
    token.value = buffer;
}

void Lexer::defineStringExpression(std::string& buffer) {
    token.type = Token::Type::StringExpression;
    char c;
    while(!reader.eof()) {
        c = reader.get();
        buffer += c;
        if(c == '\\' && reader.peek() == '"')
            buffer += reader.get();
        else if(c == '"')
            return;
    }
        token.type = Token::Type::Invalid;
}

void Lexer::defineCommentExpression(std::string& buffer) {
    token.type = Token::Type::Comment;
    buffer += reader.get();
    char c;
    while(!reader.eof()) {
        c = reader.get();
        buffer += c;
        if(c == '*' && reader.peek() == '\\'){
            buffer += reader.get();
            return;
        }
    }
    token.type = Token::Type::Invalid;
}

void Lexer::continueToTokenEnd(std::string& buffer) {
    for(char sign = reader.peek() ; std::isalnum(sign) || sign == '_' ; sign = reader.peek())
        buffer += reader.get();

}

Token Lexer::getToken(){
    return token;
}

