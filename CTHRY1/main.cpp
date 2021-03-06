﻿/*

Pavel Knyazev
Alexey Palyoniy

Code for linux and windows

Compile using visual studio 2017 compiler
or place files into one folder and: g++ ErrorProcess.cpp main.cpp parse.cpp Poly.cpp VarStor.cpp
In linux use unix end line endings. In windows use windows line endings

*/
 

#ifdef _WIN32
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <ctype.h>
#include <cstring>

#include "ErrorProcess.h"
#include "parse.cpp.h"

#define YYPARSE_PARAM
extern int yyparse(YYPARSE_PARAM);

FILE* fin = nullptr;

void usage()
{
	printf("Usage: program.exe <file>\n");
}


int main(int argc, char** argv)
{
	int c;
	printf("Polynomial Language Interpreter is running\n\n");

	if (argc != 2)
	{
		usage();
		goto main_end;
	}

	fin = fopen(argv[1], "r");
	if (!fin)
	{
		printf("Could not open file '%s'. Exitting\n", argv[1]);
		goto main_end;
	}

	c = fgetc(fin);
	fclose(fin);
	fin = nullptr;
	
	// empty file -> do nothing
	if (c == EOF)
		goto main_end;

	try
	{
		// launch the copy without comments 
		removeComments(argv[1], CODEFILE);

		fin = fopen(CODEFILE, "r");
		if (!fin)
		{
			printf("Could not open file '%s'. Exitting\n", CODEFILE);
			goto main_end;
		}

		yyparse();
	}

	catch (std::runtime_error e) 
	{
		putchar('\n');
		if (strlen(e.what()) > 0)
			printf("Exception occured: %s\n", e.what());
		
		if (fin)
		{
			unsigned n = ftell(fin);
			showErrorLine(fin);

			fseek(fin, n, SEEK_SET);
			showErrorPos(argv[1], fin);
		}
	}


	//If it needs
	if (fin)
		fclose(fin);
	remove(CODEFILE);
	
	
main_end:

#ifdef _DEBUG 
	printf("Press any key to exit\n");
	getchar();
#endif // _DEBUG 

	return 0;
}


extern void AppendBuffer(int app);
extern void ClearBuffer();
extern const char* GetBuffer();

//////////////////////////

char getUntil(FILE* f, bool(*stop_if)(int))
{
	int c = fgetc(f);
	while (!stop_if(c) && c != EOF)
	{
		AppendBuffer(c);
		c = fgetc(f);
	}
	
	return c;
}

int yylex()
{
	int c = fgetc(fin);

	// obtain variable name
	if (c == '$')
	{
		ClearBuffer();
		c = getUntil(fin, [](int x) { return !isalnum(x); });
		ungetc(c, fin);

		// it's only '$'
		if (strlen(GetBuffer()) == 0)
			return '$';

		return VAR;
	}

	// obtain const string
	if (c == '\'')
	{
		ClearBuffer();
		getUntil(fin, [](int x) { return (x == '\''); });
		return CSTR;
	}

	if (isalpha(c))
	{
		yylval.int_t = c;
		return ALPHACHAR;
	}

	if (isdigit(c))
	{
		ClearBuffer();
		while (isdigit(c))
		{
			AppendBuffer(c);
			c = fgetc(fin);
		}

		// seems to be real
		if (c == '.')
		{
			AppendBuffer(c);
			c = fgetc(fin);
			while (isdigit(c))
			{
				AppendBuffer(c);
				c = fgetc(fin);
			}

			// return last read symbol
			ungetc(c, fin);
			yylval.real_t = std::atof(GetBuffer());
			ClearBuffer();
			return REAL;
		}

		// seems to be int
		else
		{
			ungetc(c, fin);
			yylval.real_t = std::atof(GetBuffer());
			ClearBuffer();
			return INT;
		}

	}

	return c;
}

void yyerror(const char *s)
{
	throw std::runtime_error("Syntax error: ");
}
