#include "Tokenizer.h"
#include "Expression.h"
#include <cctype>

Tokenizer::Tokenizer(char* data) : str(std::string(data)) {
}

NumberExpression* Tokenizer::number()
{
	this->skipWhiteSpace();
	char ch = str.peek();
	if (std::isdigit(ch)) {
		double x;
		str >> x;
		return new NumberExpression(x);
	}
	return nullptr;
}

VariableExpression* Tokenizer::variable() {
	this->skipWhiteSpace();
	char ch = str.peek();
	std::string s;
	while (std::isalpha(ch)) {
		ch = str.get();
		s += ch;
		ch = str.peek();
	}
	if (s.length() > 0)
		return new VariableExpression(s);
	return nullptr;
}

bool Tokenizer::character(char expected) {
	this->skipWhiteSpace();
	char ch = str.peek();
	if (ch == expected) {
		ch = str.get();
		return true;
	}
	return false;
}

int Tokenizer::mark() {
	return str.tellg();
}

bool Tokenizer::atEnd() {
	return str.eof();
}

void Tokenizer::reset(int mark) {
	str.clear();
	str.seekg(mark);
}

void Tokenizer::skipWhiteSpace() {
	char ch = str.peek();
	while (ch == ' ' || ch == '\t') {
		ch = str.get();
		ch = str.peek();
	}
}
