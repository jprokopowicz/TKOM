#include <iostream>
#include <fstream>
#include <list>
#include "Lexer/Lexer.h"
//#define N_O_FILES 9
#include "Exceptions/Exception.h"
#include "Parser/Parser.h"
/*
std::string source_paths[N_O_FILES] = {
		"../tests/test code/declarations.txt",
		"../tests/test code/operators.txt",
		"../tests/test code/loop and if.txt",
		"../tests/test code/simple program.txt",
		"../tests/test code/string.txt",
		"../tests/test code/numbers.txt",
		"../tests/test code/struct.txt",
		"../tests/test code/function.txt",
		"../tests/test code/running program.txt",
		
};

std::string results_paths[N_O_FILES] = {
		"../tests/results/declarations.txt",
		"../tests/results/operators.txt",
		"../tests/results/loop and if.txt",
		"../tests/results/simple program.txt",
		"../tests/results/string.txt",
		"../tests/results/numbers.txt",
		"../tests/results/struct.txt",
		"../tests/results/function.txt",
		"../tests/results/running program.txt",
};

std::string read_file(std::string path){
	std::fstream file;
	file.open(path, std::ios::in);
   	if(!file.is_open()) {
   		std::cout << "file open error: " << path << "\n";
   		return "";
   	}
   	std::cout << "opened: " << path << "\n";
   	std::string code;
	code.assign( (std::istreambuf_iterator<char>(file) ) , (std::istreambuf_iterator<char>()  ) );
	return code;
}

void analize_stream(std::istringstream& stream, std::list<Token>& results){
	Lexer lexer(stream);
	do {
		lexer.readNextToken();
		results.push_back(lexer.getToken());
	}while((--results.end())->type != Token::Type::EndOfFile);
}

void save_to_file(std::list<Token>& results, std::string path){
	std::ofstream file;
	file.open(path);
	if(!file.is_open()) {
		std::cout << "file open error: " << path << "\n";
		return;
	}
	std::cout << "file created/overwrite: " << path << "\n";
	for(std::list<Token>::iterator I = results.begin() ; I != results.end() ; ++I)
		file << *I << "\n";
	file.close();
}

int main() {
	for(int i = 0 ; i <N_O_FILES ;++i){
		std::list<Token> results;
		std::istringstream stream(read_file(source_paths[i]));
		analize_stream(stream, results);
		save_to_file(results, results_paths[i]);
	}
	return 0;
}
*/

/*int main(){
    String a("a"), b("b");
    std::cout<<a+b;
    return 0;}*/

int main(){
    try {
        std::istringstream stringstream("asda54523\n{ (");
        Parser p(stringstream);
        p.programParse();
        /*Lexer l(stringstream);
        l.readNextToken();
        std::cout<<Token::getName(l.getToken().type)<<" "<<l.getToken().value<<" "<<l.getToken().position;*/

    }catch (Exception e){
        std::cout<<e.throwMsg();
    }
};