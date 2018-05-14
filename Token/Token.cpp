#define NUMBER_OF_KEYWORDS 19
#define NUMBER_OF_SPECIAL_SIGNS 21
#define NUMBER_OF_TOKEN_TYPES 50
#include "Token.h"
Token::Token(){
    type = Type::Invalid;
    value = "";
}
Token::Type Token::FindKeyword(const std::string& word){
	static const std::string keyWords[NUMBER_OF_KEYWORDS] = {
			"main",
			"fun",
			"str",
			"return",
			"if",
			"else",
			"loop",
			"read",
			"write",
			"var",
			"int",
			"float",
			"bool",
			"string",
			"true",
			"false",
			"run",
			"path",
			"program",
	};
	unsigned i;
	for(i = 0;i<NUMBER_OF_KEYWORDS;++i){
		if(word == keyWords[i])
			return (Type)i;
	}
	return Type::Identifier;

};
Token::Type Token::FindSign(const char& sign){
	static const char specialSigns[NUMBER_OF_SPECIAL_SIGNS] = {
			'+',
			'-',
			'*',
			'/',
			'%',
			'|',
			'&',
			'!',
			'>',
			'<',
			'.',
			',',
			';',
			'=',
			'(',
			')',
			'{',
			'}',
			'\\'
	};
	unsigned i;
	for(i=0;i<NUMBER_OF_SPECIAL_SIGNS;++i){
		if(sign == specialSigns[i])
			return (Type)(i+NUMBER_OF_KEYWORDS);
	}
	return Type::Invalid;
}

std::string Token::getName(const Type& type){
    static const std::string typeNames[NUMBER_OF_TOKEN_TYPES] = {
    		"main",
		"function",
	 	"struct",
		"return",
	 	"if",
	 	"else",
 		"loop",
		"read",
		"write",
		"variable",
 		"integer",
  		"float",
   		"boolean ",
		"string",
		"true",
		"false",
		"run",
		"path",
		"program",
		"plus",
 		"minus",
  		"star",
   		"slash",
		"modulo",
		"or",
		"and",
		"not",
		"greater",
		"lesser",
		"dot",
		"comma",
		"semicon",
		"assignment",
		"open bracket",
		"close bracket",
		"open statement",
		"close statement",
		"greater or equal",
		"lesser or equal",
		"equal",
		"not equal",
		"open program expression ",
		"close program expression",
		"string expression",
		"identifier",
		"number integer",
		"number float",
		"invalid",
		"end of file",
		"comment",
	};
	return typeNames[(unsigned)type];
}
