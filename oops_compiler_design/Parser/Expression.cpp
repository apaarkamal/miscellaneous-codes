#include "Expression.h"
#include <cmath>

std::map<std::string, double> Expression::vars;

Expression::Expression() {}
Expression::~Expression() {}

double Expression::lookUp(const std::string& var) {
	if (vars.find(var) != vars.end())
		return vars[var];
	return 0;
}

void Expression::record(const std::string& var, double value)
{
	vars[var] = value;
}

NumberExpression::NumberExpression(double val) : value(val) 
{
}

double NumberExpression::evaluate() {
	return value;
}

VariableExpression::VariableExpression(const std::string& var) : variable(var)
{
}

double VariableExpression::evaluate() {
	return Expression::lookUp(variable);
}

ArithmeticExpression::ArithmeticExpression(char ch, Expression *l, Expression *r)
	: left(l), right(r), op(ch)
{
}

ArithmeticExpression::~ArithmeticExpression() {
	if (left)
		delete left;
	if (right)
		delete right;
}

double ArithmeticExpression::evaluate() {
	if (left == nullptr || right == nullptr)
		return 0;

	double result = 0;
	double a = left->evaluate();
	double b = right->evaluate();
	switch (op) {
	case '+':
		result = a + b;
		break;
	case '-':
		result = a - b;
		break;
	case '*':
		result = a * b;
		break;
	case '/':
		result = a / b;
		break;
	case '^':
		result = std::pow(a, b);
		break;
	}
	return result;
}

AssignmentExpression::AssignmentExpression(VariableExpression *v, Expression *val)
	: var(v), value(val)
{
}

AssignmentExpression::~AssignmentExpression() {
	if (var)
		delete var;
	if (value)
		delete value;
}

double AssignmentExpression::evaluate() {
	double x = 0;
	if (value)
		x = value->evaluate();
	if (var) {
		Expression::record(var->getVar(), x);
	}
	return x;
}
