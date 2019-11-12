#pragma once
#include <sstream>

class NumberExpression;
class VariableExpression;

class Tokenizer
{
public:
	Tokenizer(char* data);

	NumberExpression* number();
	VariableExpression* variable();
	bool character(char expected);
	bool atEnd();

	int mark();
	void reset(int mark);
private:
	std::stringstream str;

	void skipWhiteSpace();
};
