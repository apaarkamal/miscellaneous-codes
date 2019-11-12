#pragma once
#include <map>
#include <string>

class Expression
{
public:
	Expression();
	virtual ~Expression();

	static double lookUp(const std::string& var);
	static void record(const std::string& var, double value);

	virtual double evaluate() = 0;
protected:
	static std::map<std::string, double> vars;	
};

class NumberExpression : public Expression
{
public:
	NumberExpression(double val);

	virtual double evaluate();
private:
	double value;
};

class VariableExpression : public Expression
{
public:
	VariableExpression(const std::string& var);

	virtual double evaluate();

	std::string getVar() const { return variable; }
private:
	std::string variable;
};

class ArithmeticExpression : public Expression
{
public:
	ArithmeticExpression(char op, Expression *left, Expression *right);
	virtual ~ArithmeticExpression();

	virtual double evaluate();
private:
	Expression *left, *right;
	char op;
};

class AssignmentExpression : public Expression
{
public:
	AssignmentExpression(VariableExpression *var, Expression *value);
	virtual ~AssignmentExpression();

	virtual double evaluate();
private:
	VariableExpression *var;
	Expression *value;
};
