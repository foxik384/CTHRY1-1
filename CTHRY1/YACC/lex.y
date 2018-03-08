%token CONST ALPHA
%start expr_add

////////////////------------------- inline C code

%{
	#include "../Poly.h"
%}

%union 
{
	Polynomial poly_t;
	int int_t;
	double real_t;
}

%{

// output macros
#ifdef _DEBUG_OUT
#define _out(val, s) polyResult = val; printf("%s: %s\n", s, polyResult.out().c_str())
#else
#define _out(val, s) polyResult = val;
#endif

#include <malloc.h>
#include <math.h>

	Polynomial polyResult;
	
	extern void yyerror(const char *s);
	extern int yylex();

	YYSTYPE res;
%}


////////////////------------------- inline C code


%type <real_t> CONST
%type <int_t> ALPHA
       
%type <poly_t> primary
%type <poly_t> expr_add
%type <poly_t> expr_mul
%type <poly_t> expr_pow


%%

////////////////////////////------ expr
// binary and unary operations

//------- priority + -
expr_add: 	expr_mul;
expr_add:	expr_add '+' expr_mul 		{$$ = calculate($1, $3, '+'); _out($$, "bin '+'");}
expr_add:	expr_add '-' expr_mul 		{$$ = calculate($1, $3, '-'); _out($$, "bin '-'");}

//------- priority + -



//------- priority * /

// it;s possible to multiply number on letter: 2a, ab
expr_mul:	expr_mul ALPHA 				{$$ = calculate($1, Polynomial(1, $2), '*'); _out($$, "alpha bin '*'");}

expr_mul:	expr_pow;
expr_mul:	expr_mul '*' expr_pow 		{$$ = calculate($1, $3, '*'); _out($$, "bin '*'");}

//------- priority * /



//------- priority ^
expr_pow: 	primary;
expr_pow:	primary '^' expr_pow 		{$$ = calculate($1, $3, '^'); _out($$, "bin '^'");}

expr_pow: 	'-' primary 				{$$ = calculate(Polynomial(0), $2, '-'); _out($$, "unary '-'"); }
expr_pow:	'-' primary '^' expr_pow 	{$$ = calculate(Polynomial(0), calculate($2, $4, '^'), '-'); _out($$, "bin '^'; unary '-'"); }

//------- priority ^


// highest priority: number, letter and brackets with term
primary:	ALPHA						{ $$ = Polynomial(1, $1); _out($$, "Alpha"); }
primary: 	CONST 						{ $$ = Polynomial($1);    _out($$, "Constant"); }
primary: 	'(' expr_add ')' 			{ $$ = $2; _out($$, "(Term)"); }

////////////////////////////------ expr	

%%