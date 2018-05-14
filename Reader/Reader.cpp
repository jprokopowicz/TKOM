#include "Reader.h"

Reader::Reader (std::istream& stream_):stream(stream_){
    sign = 0;
    //nextLine = false;
}

char Reader::get(){
    stream.get(sign);
    position.sign++;
    if(sign=='\n'){
        //nextLine = false;
        position.sign = 1;
        position.line++;
    }
    //if (sign == '\n')
    //    nextLine = true;
    return sign;
}

char Reader::peek(){
    return (char)stream.peek();
}

bool Reader::eof(){
    stream.peek();
    return stream.eof();
}

Position Reader::getPosition() {
    return position;
}

