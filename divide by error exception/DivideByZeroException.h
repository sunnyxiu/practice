#ifndef DIVIDEBYZERO
#define	DIVIDEBYZERO
#include<stdexcept>

class DivideByZeroException:public std::runtime_error
{
public:
	DivideByZeroException() :std::runtime_error{ "attempted to divide by zero" } {};
};

#endif