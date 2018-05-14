#ifndef TKOM_READER_H
#define TKOM_READER_H

#include <istream>
#include <sstream>
#include "../Positon/Position.h"

class Reader {
private:
    std::istream& stream;
    char sign;
    //bool nextLine;
    Position position;
public:
    explicit Reader() = delete;
    explicit Reader (std::istream&);
    Reader(const Reader &) = delete;
    const Reader &operator=(const Reader &) = delete;


    char get();
    char peek();
    bool eof();
    Position getPosition();
};

#endif //TKOM_READER_H