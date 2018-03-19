
/*  A Bison parser, made from lex.y with Bison version GNU Bison version 1.24
  */

#define YYBISON 1  /* Identify Bison output.  */

#define	REAL	258
#define	INT	259
#define	ALPHACHAR	260
#define	VAR	261
#define	CSTR	262

#line 6 "lex.y"

	#include "../VarStor.h"
	#define MAXSZ 255
	
	// buf for input string
	char gBuf[MAXSZ + 1] = { 0 };
	int gIndex = 0;
	
	// append one char
	void AppendBuffer(int app);
	
	// clear buf
	void ClearBuffer();
	
	// return buf data as string 
	const char* GetBuffer();	

#line 24 "lex.y"
typedef struct 
{
	Polynomial poly_t;
	
	int int_t;
	double real_t;
} YYSTYPE;
#line 32 "lex.y"


//#define _DEBUG_OUT

// output macros
#ifdef _DEBUG_OUT

#define debug_out_p(val, s) \
printf("%s: %s [%s]\n", s, val##.getName().c_str(), val##.out().c_str())

#else
#define debug_out_p(val, s) 

#endif

#define unused(x) x = 0

#include <malloc.h>

extern void yyerror(const char *s);
extern int yylex();


#ifndef YYLTYPE
typedef
  struct yyltype
    {
      int timestamp;
      int first_line;
      int first_column;
      int last_line;
      int last_column;
      char *text;
   }
  yyltype;

#define YYLTYPE yyltype
#endif

#include <stdio.h>

#ifndef __cplusplus
#ifndef __STDC__
#define const
#endif
#endif



#define	YYFINAL		49
#define	YYFLAG		-32768
#define	YYNTBASE	18

#define YYTRANSLATE(x) ((unsigned)(x) <= 262 ? yytranslate[x] : 26)

static const char yytranslate[] = {     0,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     8,     2,     2,     2,    16,
    17,    14,    13,     2,    10,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,    11,     9,
    12,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,    15,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     1,     2,     3,     4,     5,
     6,     7
};

#if YYDEBUG != 0
static const short yyprhs[] = {     0,
     0,     2,     5,    10,    15,    21,    26,    28,    31,    34,
    38,    42,    45,    49,    51,    53,    57,    61,    64,    66,
    70,    72,    76,    79,    84,    86,    88,    90,    92
};

static const short yyrhs[] = {    19,
     0,     8,     5,     0,    19,     9,    10,    21,     0,    19,
     9,    10,     7,     0,    19,     9,    10,     4,     8,     0,
    19,     9,    10,     8,     0,    11,     0,    18,    11,     0,
    21,    11,     0,    20,    18,    11,     0,    20,    21,    11,
     0,    20,    11,     0,    22,    12,    21,     0,    22,     0,
    23,     0,    22,    13,    23,     0,    22,    10,    23,     0,
    23,     5,     0,    24,     0,    23,    14,    24,     0,    25,
     0,    25,    15,    24,     0,    10,    25,     0,    10,    25,
    15,    24,     0,     5,     0,     3,     0,     4,     0,     6,
     0,    16,    22,    17,     0
};

#endif

#if YYDEBUG != 0
static const short yyrline[] = { 0,
    87,    90,    93,    96,    99,   100,   109,   112,   115,   118,
   119,   120,   133,   134,   141,   142,   143,   152,   154,   155,
   162,   163,   165,   166,   174,   175,   176,   179,   182
};

static const char * const yytname[] = {   "$","error","$undefined.","REAL","INT",
"ALPHACHAR","VAR","CSTR","'$'","'<'","'-'","';'","'='","'+'","'*'","'^'","'('",
"')'","operator","out_operator","operation","expr_equal","expr_add","expr_mul",
"expr_pow","primary",""
};
#endif

static const short yyr1[] = {     0,
    18,    19,    19,    19,    19,    19,    20,    20,    20,    20,
    20,    20,    21,    21,    22,    22,    22,    23,    23,    23,
    24,    24,    24,    24,    25,    25,    25,    25,    25
};

static const short yyr2[] = {     0,
     1,     2,     4,     4,     5,     4,     1,     2,     2,     3,
     3,     2,     3,     1,     1,     3,     3,     2,     1,     3,
     1,     3,     2,     4,     1,     1,     1,     1,     3
};

static const short yydefact[] = {     0,
    26,    27,    25,    28,     0,     0,     7,     0,     0,     1,
     0,     0,    14,    15,    19,    21,     2,    23,     0,     8,
     0,    12,     0,     0,     9,     0,     0,     0,    18,     0,
     0,     0,    29,     0,    10,    11,    17,    13,    16,    20,
    22,    24,    27,     4,     6,     3,     5,     0,     0
};

static const short yydefgoto[] = {     9,
    10,    11,    12,    13,    14,    15,    16
};

static const short yypact[] = {    16,
-32768,-32768,-32768,-32768,    -3,    46,-32768,    38,    -8,     9,
     1,    14,    45,    25,-32768,    13,-32768,    32,    43,-32768,
    19,-32768,    20,    34,-32768,    38,    38,    38,-32768,    38,
    38,    38,-32768,    30,-32768,-32768,    25,-32768,    25,-32768,
-32768,-32768,    51,-32768,-32768,-32768,-32768,    61,-32768
};

static const short yypgoto[] = {    52,
-32768,-32768,   -11,    56,   -18,   -17,    59
};


#define	YYLAST		65


static const short yytable[] = {    24,
    48,    17,    20,     1,     2,     3,     4,    37,     5,    39,
     6,    22,    40,    41,    42,    38,     8,    21,     1,     2,
     3,     4,    46,     5,    25,     6,     7,    31,    34,    29,
    35,     8,     1,    43,     3,     4,    44,    45,    30,     6,
     1,     2,     3,     4,    36,     8,    32,     6,     1,     2,
     3,     4,    26,     8,    26,    28,    27,    28,    47,    33,
    49,     8,    23,    19,    18
};

static const short yycheck[] = {    11,
     0,     5,    11,     3,     4,     5,     6,    26,     8,    28,
    10,    11,    30,    31,    32,    27,    16,     9,     3,     4,
     5,     6,    34,     8,    11,    10,    11,    15,    10,     5,
    11,    16,     3,     4,     5,     6,     7,     8,    14,    10,
     3,     4,     5,     6,    11,    16,    15,    10,     3,     4,
     5,     6,    10,    16,    10,    13,    12,    13,     8,    17,
     0,    16,    11,     8,     6
};
/* -*-C-*-  Note some compilers choke on comments on `#line' lines.  */
#line 3 "bison.simple"

/* Skeleton output parser for bison,
   Copyright (C) 1984, 1989, 1990 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */
   
#ifndef alloca
#ifdef __GNUC__
#define alloca __builtin_alloca
#else /* not GNU C.  */
#if (!defined (__STDC__) && defined (sparc)) || defined (__sparc__) || defined (__sparc) || defined (__sgi)
#include <alloca.h>
#else /* not sparc */
#if defined (MSDOS) && !defined (__TURBOC__)
#include <malloc.h>
#else /* not MSDOS, or __TURBOC__ */
#if defined(_AIX)
#include <malloc.h>
 #pragma alloca
#else /* not MSDOS, __TURBOC__, or _AIX */
#ifdef __hpux
#ifdef __cplusplus
extern "C" {
void *alloca (unsigned int);
};
#else /* not __cplusplus */
void *alloca ();
#endif /* not __cplusplus */
#endif /* __hpux */
#endif /* not _AIX */
#endif /* not MSDOS, or __TURBOC__ */
#endif /* not sparc.  */
#endif /* not GNU C.  */
#endif /* alloca not defined.  */

/* This is the parser code that is written into each bison parser
  when the %semantic_parser declaration is not specified in the grammar.
  It was written by Richard Stallman by simplifying the hairy parser
  used when %semantic_parser is specified.  */

/* Note: there must be only one dollar sign in this file.
   It is replaced by the list of actions, each action
   as one case of the switch.  */

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		-2
#define YYEOF		0
#define YYACCEPT	return(0)
#define YYABORT 	return(1)
#define YYERROR		goto yyerrlab1
/* Like YYERROR except do call yyerror.
   This remains here temporarily to ease the
   transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */
#define YYFAIL		goto yyerrlab
#define YYRECOVERING()  (!!yyerrstatus)
#define YYBACKUP(token, value) \
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    { yychar = (token), yylval = (value);			\
      yychar1 = YYTRANSLATE (yychar);				\
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    { yyerror ("syntax error: cannot back up"); YYERROR; }	\
while (0)

#define YYTERROR	1
#define YYERRCODE	256

#ifndef YYPURE
#define YYLEX		yylex()
#endif

#ifdef YYPURE
#ifdef YYLSP_NEEDED
#ifdef YYLEX_PARAM
#define YYLEX		yylex(&yylval, &yylloc, YYLEX_PARAM)
#else
#define YYLEX		yylex(&yylval, &yylloc)
#endif
#else /* not YYLSP_NEEDED */
#ifdef YYLEX_PARAM
#define YYLEX		yylex(&yylval, YYLEX_PARAM)
#else
#define YYLEX		yylex(&yylval)
#endif
#endif /* not YYLSP_NEEDED */
#endif

/* If nonreentrant, generate the variables here */

#ifndef YYPURE

int	yychar;			/*  the lookahead symbol		*/
YYSTYPE	yylval;			/*  the semantic value of the		*/
				/*  lookahead symbol			*/

#ifdef YYLSP_NEEDED
YYLTYPE yylloc;			/*  location data for the lookahead	*/
				/*  symbol				*/
#endif

int yynerrs;			/*  number of parse errors so far       */
#endif  /* not YYPURE */

#if YYDEBUG != 0
int yydebug;			/*  nonzero means print parse trace	*/
/* Since this is uninitialized, it does not stop multiple parsers
   from coexisting.  */
#endif

/*  YYINITDEPTH indicates the initial size of the parser's stacks	*/

#ifndef	YYINITDEPTH
#define YYINITDEPTH 200
#endif

/*  YYMAXDEPTH is the maximum size the stacks can grow to
    (effective only if the built-in stack extension method is used).  */

#if YYMAXDEPTH == 0
#undef YYMAXDEPTH
#endif

#ifndef YYMAXDEPTH
#define YYMAXDEPTH 10000
#endif

/* Prevent warning if -Wstrict-prototypes.  */
#ifdef __GNUC__
int yyparse (void);
#endif

#if __GNUC__ > 1		/* GNU C and GNU C++ define this.  */
#define __yy_memcpy(FROM,TO,COUNT)	__builtin_memcpy(TO,FROM,COUNT)
#else				/* not GNU C or C++ */
#ifndef __cplusplus

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_memcpy (from, to, count)
     char *from;
     char *to;
     int count;
{
  register char *f = from;
  register char *t = to;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#else /* __cplusplus */

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_memcpy (char *from, char *to, int count)
{
  register char *f = from;
  register char *t = to;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#endif
#endif

#line 192 "bison.simple"

/* The user can define YYPARSE_PARAM as the name of an argument to be passed
   into yyparse.  The argument should have type void *.
   It should actually point to an object.
   Grammar actions can access the variable by casting it
   to the proper pointer type.  */

#ifdef YYPARSE_PARAM
#define YYPARSE_PARAM_DECL void *YYPARSE_PARAM;
#else
#define YYPARSE_PARAM
#define YYPARSE_PARAM_DECL
#endif

int
yyparse(YYPARSE_PARAM)
     YYPARSE_PARAM_DECL
{
  register int yystate;
  register int yyn;
  register short *yyssp;
  register YYSTYPE *yyvsp;
  int yyerrstatus;	/*  number of tokens to shift before error messages enabled */
  int yychar1 = 0;		/*  lookahead token as an internal (translated) token number */

  short	yyssa[YYINITDEPTH];	/*  the state stack			*/
  YYSTYPE yyvsa[YYINITDEPTH];	/*  the semantic value stack		*/

  short *yyss = yyssa;		/*  refer to the stacks thru separate pointers */
  YYSTYPE *yyvs = yyvsa;	/*  to allow yyoverflow to reallocate them elsewhere */

#ifdef YYLSP_NEEDED
  YYLTYPE yylsa[YYINITDEPTH];	/*  the location stack			*/
  YYLTYPE *yyls = yylsa;
  YYLTYPE *yylsp;

#define YYPOPSTACK   (yyvsp--, yyssp--, yylsp--)
#else
#define YYPOPSTACK   (yyvsp--, yyssp--)
#endif

  int yystacksize = YYINITDEPTH;

#ifdef YYPURE
  int yychar;
  YYSTYPE yylval;
  int yynerrs;
#ifdef YYLSP_NEEDED
  YYLTYPE yylloc;
#endif
#endif

  YYSTYPE yyval;		/*  the variable used to return		*/
				/*  semantic values from the action	*/
				/*  routines				*/

  int yylen;

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Starting parse\n");
#endif

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss - 1;
  yyvsp = yyvs;
#ifdef YYLSP_NEEDED
  yylsp = yyls;
#endif

/* Push a new state, which is found in  yystate  .  */
/* In all cases, when you get here, the value and location stacks
   have just been pushed. so pushing a state here evens the stacks.  */
yynewstate:

  *++yyssp = yystate;

  if (yyssp >= yyss + yystacksize - 1)
    {
      /* Give user a chance to reallocate the stack */
      /* Use copies of these so that the &'s don't force the real ones into memory. */
      YYSTYPE *yyvs1 = yyvs;
      short *yyss1 = yyss;
#ifdef YYLSP_NEEDED
      YYLTYPE *yyls1 = yyls;
#endif

      /* Get the current used size of the three stacks, in elements.  */
      int size = yyssp - yyss + 1;

#ifdef yyoverflow
      /* Each stack pointer address is followed by the size of
	 the data in use in that stack, in bytes.  */
#ifdef YYLSP_NEEDED
      /* This used to be a conditional around just the two extra args,
	 but that might be undefined if yyoverflow is a macro.  */
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yyls1, size * sizeof (*yylsp),
		 &yystacksize);
#else
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yystacksize);
#endif

      yyss = yyss1; yyvs = yyvs1;
#ifdef YYLSP_NEEDED
      yyls = yyls1;
#endif
#else /* no yyoverflow */
      /* Extend the stack our own way.  */
      if (yystacksize >= YYMAXDEPTH)
	{
	  yyerror("parser stack overflow");
	  return 2;
	}
      yystacksize *= 2;
      if (yystacksize > YYMAXDEPTH)
	yystacksize = YYMAXDEPTH;
      yyss = (short *) alloca (yystacksize * sizeof (*yyssp));
      __yy_memcpy ((char *)yyss1, (char *)yyss, size * sizeof (*yyssp));
      yyvs = (YYSTYPE *) alloca (yystacksize * sizeof (*yyvsp));
      __yy_memcpy ((char *)yyvs1, (char *)yyvs, size * sizeof (*yyvsp));
#ifdef YYLSP_NEEDED
      yyls = (YYLTYPE *) alloca (yystacksize * sizeof (*yylsp));
      __yy_memcpy ((char *)yyls1, (char *)yyls, size * sizeof (*yylsp));
#endif
#endif /* no yyoverflow */

      yyssp = yyss + size - 1;
      yyvsp = yyvs + size - 1;
#ifdef YYLSP_NEEDED
      yylsp = yyls + size - 1;
#endif

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Stack size increased to %d\n", yystacksize);
#endif

      if (yyssp >= yyss + yystacksize - 1)
	YYABORT;
    }

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Entering state %d\n", yystate);
#endif

  goto yybackup;
 yybackup:

/* Do appropriate processing given the current state.  */
/* Read a lookahead token if we need one and don't already have one.  */
/* yyresume: */

  /* First try to decide what to do without reference to lookahead token.  */

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* yychar is either YYEMPTY or YYEOF
     or a valid token in external form.  */

  if (yychar == YYEMPTY)
    {
#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Reading a token: ");
#endif
      yychar = YYLEX;
    }

  /* Convert token to internal form (in yychar1) for indexing tables with */

  if (yychar <= 0)		/* This means end of input. */
    {
      yychar1 = 0;
      yychar = YYEOF;		/* Don't call YYLEX any more */

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Now at end of input.\n");
#endif
    }
  else
    {
      yychar1 = YYTRANSLATE(yychar);

#if YYDEBUG != 0
      if (yydebug)
	{
	  fprintf (stderr, "Next token is %d (%s", yychar, yytname[yychar1]);
	  /* Give the individual parser a way to print the precise meaning
	     of a token, for further debugging info.  */
#ifdef YYPRINT
	  YYPRINT (stderr, yychar, yylval);
#endif
	  fprintf (stderr, ")\n");
	}
#endif
    }

  yyn += yychar1;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != yychar1)
    goto yydefault;

  yyn = yytable[yyn];

  /* yyn is what to do for this token type in this state.
     Negative => reduce, -yyn is rule number.
     Positive => shift, yyn is new state.
       New state is final state => don't bother to shift,
       just return success.
     0, or most negative number => error.  */

  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrlab;

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Shift the lookahead token.  */

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Shifting token %d (%s), ", yychar, yytname[yychar1]);
#endif

  /* Discard the token being shifted unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  /* count tokens shifted since error; after three, turn off error status.  */
  if (yyerrstatus) yyerrstatus--;

  yystate = yyn;
  goto yynewstate;

/* Do the default action for the current state.  */
yydefault:

  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;

/* Do a reduction.  yyn is the number of a rule to reduce with.  */
yyreduce:
  yylen = yyr2[yyn];
  if (yylen > 0)
    yyval = yyvsp[1-yylen]; /* implement default value of the action */

#if YYDEBUG != 0
  if (yydebug)
    {
      int i;

      fprintf (stderr, "Reducing via rule %d (line %d), ",
	       yyn, yyrline[yyn]);

      /* Print the symbols being reduced, and their result.  */
      for (i = yyprhs[yyn]; yyrhs[i] > 0; i++)
	fprintf (stderr, "%s ", yytname[yyrhs[i]]);
      fprintf (stderr, " -> %s\n", yytname[yyr1[yyn]]);
    }
#endif


  switch (yyn) {

case 1:
#line 87 "lex.y"
{ unused(yyval.int_t); ;
    break;}
case 2:
#line 90 "lex.y"
{ unused(yyval.int_t); ;
    break;}
case 3:
#line 93 "lex.y"
{ unused(yyval.int_t); output(yyvsp[0].poly_t); ;
    break;}
case 4:
#line 96 "lex.y"
{ unused(yyval.int_t); output(GetBuffer()); ;
    break;}
case 5:
#line 99 "lex.y"
{ unused(yyval.int_t); output(int(yyvsp[-1].real_t), '\n'); 			;
    break;}
case 6:
#line 100 "lex.y"
{ unused(yyval.int_t); output(int(1),  '\n'); 			;
    break;}
case 7:
#line 109 "lex.y"
{ unused(yyval.int_t); ;
    break;}
case 8:
#line 112 "lex.y"
{ unused(yyval.int_t); ;
    break;}
case 9:
#line 115 "lex.y"
{ unused(yyval.int_t); ;
    break;}
case 10:
#line 118 "lex.y"
{ unused(yyval.int_t); ;
    break;}
case 11:
#line 119 "lex.y"
{ unused(yyval.int_t); ;
    break;}
case 12:
#line 120 "lex.y"
{ unused(yyval.int_t); ;
    break;}
case 13:
#line 133 "lex.y"
{ yyval.poly_t = assignVar(yyvsp[-2].poly_t, yyvsp[0].poly_t); debug_out_p(yyval.poly_t, "bin '='");;
    break;}
case 16:
#line 142 "lex.y"
{yyval.poly_t = calculate(yyvsp[-2].poly_t, yyvsp[0].poly_t, '+'); debug_out_p(yyval.poly_t, "bin '+'");;
    break;}
case 17:
#line 143 "lex.y"
{yyval.poly_t = calculate(yyvsp[-2].poly_t, yyvsp[0].poly_t, '-'); debug_out_p(yyval.poly_t, "bin '-'");;
    break;}
case 18:
#line 152 "lex.y"
{yyval.poly_t = calculate(yyvsp[-1].poly_t, Polynomial(1, yyvsp[0].int_t), '*'); debug_out_p(yyval.poly_t, "CHAR bin '*'");;
    break;}
case 20:
#line 155 "lex.y"
{yyval.poly_t = calculate(yyvsp[-2].poly_t, yyvsp[0].poly_t, '*'); debug_out_p(yyval.poly_t, "bin '*'");;
    break;}
case 22:
#line 163 "lex.y"
{yyval.poly_t = calculate(yyvsp[-2].poly_t, yyvsp[0].poly_t, '^'); debug_out_p(yyval.poly_t, "bin '^'");;
    break;}
case 23:
#line 165 "lex.y"
{yyval.poly_t = calculate(Polynomial(0), yyvsp[0].poly_t, '-'); debug_out_p(yyval.poly_t, "unary '-'"); ;
    break;}
case 24:
#line 166 "lex.y"
{yyval.poly_t = calculate(Polynomial(0), calculate(yyvsp[-2].poly_t, yyvsp[0].poly_t, '^'), '-'); debug_out_p(yyval.poly_t, "bin '^'; unary '-'"); ;
    break;}
case 25:
#line 174 "lex.y"
{ yyval.poly_t = Polynomial(1, yyvsp[0].int_t); debug_out_p(yyval.poly_t, "CHAR"); ;
    break;}
case 26:
#line 175 "lex.y"
{ yyval.poly_t = Polynomial(yyvsp[0].real_t);    debug_out_p(yyval.poly_t, "REAL"); ;
    break;}
case 27:
#line 176 "lex.y"
{ yyval.poly_t = Polynomial(yyvsp[0].real_t);    debug_out_p(yyval.poly_t, "INT"); ;
    break;}
case 28:
#line 179 "lex.y"
{ yyval.poly_t = createVariable(GetBuffer()); debug_out_p(yyval.poly_t, "Variable"); ;
    break;}
case 29:
#line 182 "lex.y"
{ yyval.poly_t = yyvsp[-1].poly_t; debug_out_p(yyval.poly_t, "(Term)"); ;
    break;}
}
   /* the action file gets copied in in place of this dollarsign */
#line 487 "bison.simple"

  yyvsp -= yylen;
  yyssp -= yylen;
#ifdef YYLSP_NEEDED
  yylsp -= yylen;
#endif

#if YYDEBUG != 0
  if (yydebug)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

  *++yyvsp = yyval;

#ifdef YYLSP_NEEDED
  yylsp++;
  if (yylen == 0)
    {
      yylsp->first_line = yylloc.first_line;
      yylsp->first_column = yylloc.first_column;
      yylsp->last_line = (yylsp-1)->last_line;
      yylsp->last_column = (yylsp-1)->last_column;
      yylsp->text = 0;
    }
  else
    {
      yylsp->last_line = (yylsp+yylen-1)->last_line;
      yylsp->last_column = (yylsp+yylen-1)->last_column;
    }
#endif

  /* Now "shift" the result of the reduction.
     Determine what state that goes to,
     based on the state we popped back to
     and the rule number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTBASE] + *yyssp;
  if (yystate >= 0 && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTBASE];

  goto yynewstate;

yyerrlab:   /* here on detecting error */

  if (! yyerrstatus)
    /* If not already recovering from an error, report this error.  */
    {
      ++yynerrs;

#ifdef YYERROR_VERBOSE
      yyn = yypact[yystate];

      if (yyn > YYFLAG && yyn < YYLAST)
	{
	  int size = 0;
	  char *msg;
	  int x, count;

	  count = 0;
	  /* Start X at -yyn if nec to avoid negative indexes in yycheck.  */
	  for (x = (yyn < 0 ? -yyn : 0);
	       x < (sizeof(yytname) / sizeof(char *)); x++)
	    if (yycheck[x + yyn] == x)
	      size += strlen(yytname[x]) + 15, count++;
	  msg = (char *) malloc(size + 15);
	  if (msg != 0)
	    {
	      strcpy(msg, "parse error");

	      if (count < 5)
		{
		  count = 0;
		  for (x = (yyn < 0 ? -yyn : 0);
		       x < (sizeof(yytname) / sizeof(char *)); x++)
		    if (yycheck[x + yyn] == x)
		      {
			strcat(msg, count == 0 ? ", expecting `" : " or `");
			strcat(msg, yytname[x]);
			strcat(msg, "'");
			count++;
		      }
		}
	      yyerror(msg);
	      free(msg);
	    }
	  else
	    yyerror ("parse error; also virtual memory exceeded");
	}
      else
#endif /* YYERROR_VERBOSE */
	yyerror("parse error");
    }

  goto yyerrlab1;
yyerrlab1:   /* here on error raised explicitly by an action */

  if (yyerrstatus == 3)
    {
      /* if just tried and failed to reuse lookahead token after an error, discard it.  */

      /* return failure if at end of input */
      if (yychar == YYEOF)
	YYABORT;

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Discarding token %d (%s).\n", yychar, yytname[yychar1]);
#endif

      yychar = YYEMPTY;
    }

  /* Else will try to reuse lookahead token
     after shifting the error token.  */

  yyerrstatus = 3;		/* Each real token shifted decrements this */

  goto yyerrhandle;

yyerrdefault:  /* current state does not do anything special for the error token. */

#if 0
  /* This is wrong; only states that explicitly want error tokens
     should shift them.  */
  yyn = yydefact[yystate];  /* If its default is to accept any token, ok.  Otherwise pop it.*/
  if (yyn) goto yydefault;
#endif

yyerrpop:   /* pop the current state because it cannot handle the error token */

  if (yyssp == yyss) YYABORT;
  yyvsp--;
  yystate = *--yyssp;
#ifdef YYLSP_NEEDED
  yylsp--;
#endif

#if YYDEBUG != 0
  if (yydebug)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "Error: state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

yyerrhandle:

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yyerrdefault;

  yyn += YYTERROR;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != YYTERROR)
    goto yyerrdefault;

  yyn = yytable[yyn];
  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrpop;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrpop;

  if (yyn == YYFINAL)
    YYACCEPT;

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Shifting error token, ");
#endif

  *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  yystate = yyn;
  goto yynewstate;
}
#line 186 "lex.y"


void AppendBuffer(int app)
{
	assert(gIndex < MAXSZ, "Input string is too long");
	gBuf[gIndex++] = app;
}

void ClearBuffer()
{
	gIndex = 0;
	memset(gBuf, 0, MAXSZ);
}

const char* GetBuffer()
{
	return gBuf;
}