#pragma once
class Expression;
class Tokenizer;

class Parser
{
public:
	Parser(char* line);
	~Parser();

	Expression* statement();
private:
	Tokenizer* tokens;

	Expression* assignment();
	Expression* calculation();
	Expression* sum();
	Expression* product();
	Expression* factor();
	Expression* power();
	Expression* term();
	Expression* group();
};
