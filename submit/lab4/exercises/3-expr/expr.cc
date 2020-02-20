#include "expr.hh"

#include <string>
#include <sstream>

std::string
IntExpr::toString() const
{
  std::stringstream s;
  s << value;
  return s.str();
}

static std::string
binaryExprToString(std::string op, ExprPtr left, ExprPtr right, int result)
{
  std::stringstream s;
  s << "(" << *left << ") " << op << " (" << *right << ")" << " = " << result;
  return s.str();
}

std::string
AddExpr::toString() const
{
  return binaryExprToString("+", left, right, eval());
}

std::string
SubExpr::toString() const
{
  return binaryExprToString("-", left, right, eval());
}

std::string
MulExpr::toString() const
{
  return binaryExprToString("*", left, right, eval());
}

std::string
DivExpr::toString() const
{
  return binaryExprToString("/", left, right, eval());
}

int
AddExpr::eval() const
{
  return left->eval() + right->eval();
}

int
SubExpr::eval() const
{
  return left->eval() - right->eval();
}

int
MulExpr::eval() const
{
  return left->eval() * right->eval();
}

int
DivExpr::eval() const
{
  return left->eval() / right->eval();
}
