#include "Expression.h"
#include "Parser.h"
#include "Tokenizer.h"
#include <iostream>

int main() {
	char buffer[128];

	std::cout << "Enter an expression to evaluate, or an empty line to quit." << std::endl;
	while (std::cin.getline(buffer, 128)) {
		if (buffer[0] == '\0')
			break;
		Parser p(buffer);
		Expression *e = p.statement();
		if (e) {
			std::cout << e->evaluate() << std::endl;
			delete e;
		}
		else
			std::cout << "Error" << std::endl;		
	}

	return 0;
}
