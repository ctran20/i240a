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
binaryExprToString(std::string op, ExprPtr left, ExprPtr right)
{
  std::stringstream s;
  s << "(" << *left << ") " << op << " (" << *right << ")";
  return s.str();
}

static std::string
binaryExprToDcCode(std::string op, ExprPtr left, ExprPtr right)
{
	std::stringstream s;
	s << left->dcCode() << " " << right->dcCode() << " " << op;
	return s.str();
}

std::string
AddExpr::toString() const
{
  return binaryExprToString("+", left, right);
}

std::string
SubExpr::toString() const
{
  return binaryExprToString("-", left, right);
}

std::string
MulExpr::toString() const
{
  return binaryExprToString("*", left, right);
}

std::string
DivExpr::toString() const
{
  return binaryExprToString("/", left, right);
}

std::string
IntExpr::dcCode() const {
	return toString();
}

std::string
AddExpr::dcCode() const {
	return binaryExprToDcCode("+", left, right);
}

std::string
SubExpr::dcCode() const {
	return binaryExprToDcCode("-", left, right);
}

std::string
MulExpr::dcCode() const {
	return binaryExprToDcCode("*", left, right);
}

std::string
DivExpr::dcCode() const {
	return binaryExprToDcCode("/", left, right);
}