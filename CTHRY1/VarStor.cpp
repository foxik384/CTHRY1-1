#include "VarStor.h"
#include "Assert.h"

void VarStor::addVar(const std::string& VarName, const Polynomial& EntireVar)
{
	this->Stor.emplace(VarName, EntireVar);
}

Polynomial* VarStor::getVarByName(const std::string& VarName)
{
	//Find variable
	auto it = Stor.find(VarName);

	//Didn't find variable
	if (it == Stor.end())
		return nullptr;

	return &it->second;
}

#pragma region Calculation

VarStor gVarStorage;

// when a new value is assigned to variable the variable storage must be updated with its value
// update and mark it initialized
void updateStorage(const std::string name, const Polynomial& val)
{
	Polynomial* poly = gVarStorage.getVarByName(name);
	
	if (poly)
		*poly = val;
}

Polynomial createVariable(std::string name)
{
	// empty non-initialized
	Polynomial x;

	if (gVarStorage.variableExists(name))
		x = *gVarStorage.getVarByName(name);
	
	else
	{
		x.assignName(name);
		gVarStorage.addVar(name, x);
	}
	
	return x;
}

/*
| 				|	name	|	empty list (None = true) |
| 				|			|							 |
| polynomial	|	no		|		no					 |
| 				|			|							 |
| variable		|	yes		|	yes if not initalized	 |
| 				|			|	no if initialized		 |
| 				|			|							 |
*/

Polynomial assignVar(Polynomial& leftPoly, Polynomial rightPoly)
{
	const std::string& leftName = leftPoly.getName();
	const std::string& rightName = rightPoly.getName();

	try
	{
		// value can only be assigned to variable, not polynomial
		assert(!leftName.empty(), "Semantic error: value can not be assigned to left operand");

		// if rightpoly is not initialized variable
		assert(!rightPoly.None(), "Semantic error: right operand was used without being initialized");

		leftPoly.getValue() = rightPoly.getValue();
		updateStorage(leftName, leftPoly);
	}

	catch (std::runtime_error e)
	{
		std::string poly_left = leftName.empty() ? leftPoly.out() : "$" + leftName;
		std::string poly_right = rightName.empty() ? rightPoly.out() : "$" + rightName;

		printf("Assignment exception occured: %s\n", e.what());
		printf("Operation [ %s ] = [ %s ]\n", poly_left.c_str(), poly_right.c_str());
		throw std::runtime_error("");
	}

	return leftPoly;
}

//////----------

void check(Polynomial& leftPoly, Polynomial& rightPoly)
{
	const std::string& leftName = leftPoly.getName();
	const std::string& rightName = rightPoly.getName();

	// poly + poly
	if (leftName.empty() && rightName.empty())
		return;

	const char *r = "Semantic error: right operand was used without being initialized";
	const char *l = "Semantic error: left operand was used without being initialized";

	// var + var
	if (!leftName.empty() && !rightName.empty())
	{
		assert(!leftPoly.None(), l);
		assert(!rightPoly.None(), r);
	}

	// var + poly or poly + var
	else
	{
		// poly + var
		if (leftName.empty())
		{
			assert(!rightPoly.None(), r);
		}
		else
		{
			assert(!leftPoly.None(), l);
		}
	}
}

Polynomial calculate(Polynomial a, Polynomial b, char op)
{
	Polynomial c;

	try
	{
		assert(op == '+' || op == '-' || op == '*' || op == '^', "Fatal: unknown operation");
		check(a, b);

		switch (op)
		{
		case '+':
			c = a + b;
			break;

		case '-':
			c = a - b;
			break;

		case '*':
			c = a * b;
			break;

		case '^':
			c = a ^ b;
			break;
		}
	}

	catch (std::runtime_error e)
	{
		std::string poly_a = !a.getName().empty() ? "$" + a.getName() : a.out();
		std::string poly_b = !b.getName().empty() ? "$" + b.getName() : b.out();

		printf("Calculation exception occured: %s\n", e.what());
		printf("Operation: [ %s ] %c [ %s ]\n",
			poly_a.c_str(), op, poly_b.c_str());

		throw std::runtime_error("");
	}


	/* delete names of copies of variables a and b
	to avoid situations with operator '='
	it copies the value and name of the polynomial
	therefore if a or b is variable then var c
	will get the name of one of them*/

	c.untieName();
	return c;
}

#pragma endregion Calculation

#pragma region IO

FILE* gStream = stdout;

#pragma region output

void output(const char* s)
{
	fprintf(gStream, "%s", s);
}

void output(Polynomial& x)
{
	// it's variable
	if (!x.getName().empty())
	{
		std::string s = "Semantic error: variable [ $" + x.getName() + " ] is used without being intialized";
		assert(!x.None(), s);
	}
	
		fprintf(gStream, "%s", x.out().c_str());
}

void output(int x, int ch)
{
	assert(x > 0, "Fatal: error in output stream");
	for (int i = 0; i < x; i++)
		putc(ch, gStream);
}

#pragma endregion output

#pragma endregion IO
