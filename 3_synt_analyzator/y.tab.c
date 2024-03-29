#ifndef lint
static const char yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93";
#endif

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20130304

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)

#define YYPREFIX "yy"

#define YYPURE 0

#line 2 "ll.y"
/*
TynaLang=syntax;
syntax=expr | fce;
expr=term, expr1;
expr1="+",term,expr1 |;
term=factor, term1;
term1="*", factor, term1 |;
factor="(", expr , ")" | number;
number=hexaNum | intNum | binNum;
hexaNum="0x", hexaDigit, {hexaDigit};
intNum="0" | nonZeroDigits, {digits};
binNum="b", binDigit, {binDigit};
hexaDigit="1"|"2"|"3"|"4"|"5"|"6"|"7"|"8"|"9"|"0"|"A"|"B"|"C"|"D"|"E"|"F";
nonZeroDigits="1"|"2"|"3"|"4"|"5"|"6"|"7"|"8"|"9";
digits="1"|"2"|"3"|"4"|"5"|"6"|"7"|"8"|"9"|"0";
binDigit="0"|"1";
fce=fceName, "(", expr, ")";
fceName="inkr" | "dekr";
*/

#include <stdio.h>
/*#include "prk-stack.h"*/
/*#include "prints.h"*/

int yylex();
void yyerror(const char *s);
extern int yylineno;

#line 32 "ll.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union {
  int int_value;
  char* str_value;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 60 "y.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define L_BR 257
#define R_BR 258
#define PLUS 259
#define MPY 260
#define HEX_NUM 261
#define INT_NUM 262
#define BIN_NUM 263
#define FCE_INKR 264
#define FCE_DEKR 265
#define LINE_END 266
#define YYERRCODE 256
static const short yylhs[] = {                           -1,
    0,    0,    1,    1,    2,    5,    5,    4,    7,    7,
    6,    6,    8,    8,    8,    3,    9,    9,
};
static const short yylen[] = {                            2,
    3,    2,    1,    1,    2,    3,    0,    2,    3,    0,
    3,    1,    1,    1,    1,    4,    1,    1,
};
static const short yydefred[] = {                         0,
    0,   13,   14,   15,   17,   18,    0,    0,    3,    4,
    0,    0,   12,    0,    0,    0,    2,    0,    5,    0,
    8,    0,   11,    1,    0,    0,    0,    6,    9,   16,
};
static const short yydgoto[] = {                          7,
    8,    9,   10,   11,   19,   12,   21,   13,   14,
};
static const short yysindex[] = {                      -256,
 -238,    0,    0,    0,    0,    0, -256, -264,    0,    0,
 -247, -246,    0, -244, -243, -250,    0, -238,    0, -238,
    0, -238,    0,    0, -247, -246, -241,    0,    0,    0,
};
static const short yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
 -248, -255,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0, -248, -255,    0,    0,    0,    0,
};
static const short yygindex[] = {                         0,
   13,   -1,    0,    4,    1,    7,    2,    0,    0,
};
#define YYTABLESIZE 28
static const short yytable[] = {                         15,
    1,   17,   10,   10,    2,    3,    4,    5,    6,    7,
   10,   18,   22,   20,   23,   24,   30,    7,    1,   16,
   27,   25,    2,    3,    4,   28,   26,   29,
};
static const short yycheck[] = {                          1,
  257,  266,  258,  259,  261,  262,  263,  264,  265,  258,
  266,  259,  257,  260,  258,  266,  258,  266,  257,    7,
   22,   18,  261,  262,  263,   25,   20,   26,
};
#define YYFINAL 7
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 266
#if YYDEBUG
static const char *yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"L_BR","R_BR","PLUS","MPY",
"HEX_NUM","INT_NUM","BIN_NUM","FCE_INKR","FCE_DEKR","LINE_END",
};
static const char *yyrule[] = {
"$accept : TynaLang",
"TynaLang : TynaLang syntax LINE_END",
"TynaLang : syntax LINE_END",
"syntax : expr",
"syntax : fce",
"expr : term expr1",
"expr1 : PLUS term expr1",
"expr1 :",
"term : factor term1",
"term1 : MPY factor term1",
"term1 :",
"factor : L_BR expr R_BR",
"factor : number",
"number : HEX_NUM",
"number : INT_NUM",
"number : BIN_NUM",
"fce : fceName L_BR expr R_BR",
"fceName : FCE_INKR",
"fceName : FCE_DEKR",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  500
#endif
#endif

#define YYINITSTACKSIZE 500

typedef struct {
    unsigned stacksize;
    short    *s_base;
    short    *s_mark;
    short    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 99 "ll.y"

void yyerror(const char *s) {
    printf("%s\n", s);
}

void main() {
    // yydebug = 1;
    printf("Entering the main");
    yyparse();
}
#line 229 "y.tab.c"

#if YYDEBUG
#include <stdio.h>		/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    short *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return -1;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (short *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return -1;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return -1;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack)) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = YYLEX) < 0) yychar = 0;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    yyerror("syntax error");

    goto yyerrlab;

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yystack.s_mark]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == 0) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 1:
#line 51 "ll.y"
	{ printf("Syntax OK, Rule1\n"); }
break;
case 2:
#line 52 "ll.y"
	{ printf("Syntax OK, Rule2\n"); }
break;
case 3:
#line 56 "ll.y"
	{ printf("Rule3\n"); }
break;
case 4:
#line 57 "ll.y"
	{ printf("Rule4\n"); }
break;
case 5:
#line 61 "ll.y"
	{ printf("Rule5\n"); }
break;
case 6:
#line 65 "ll.y"
	{ printf("Rule6\n"); }
break;
case 7:
#line 66 "ll.y"
	{ printf("Rule7\n"); }
break;
case 8:
#line 70 "ll.y"
	{ printf("Rule8\n"); }
break;
case 9:
#line 74 "ll.y"
	{ printf("Rule9\n"); }
break;
case 10:
#line 75 "ll.y"
	{ printf("Rule10\n"); }
break;
case 11:
#line 79 "ll.y"
	{ printf("Rule11\n"); }
break;
case 12:
#line 80 "ll.y"
	{ printf("Rule12\n"); }
break;
case 13:
#line 84 "ll.y"
	{ printf("Rule13\n"); }
break;
case 14:
#line 85 "ll.y"
	{ printf("Rule14\n"); }
break;
case 15:
#line 86 "ll.y"
	{ printf("Rule15\n"); }
break;
case 16:
#line 90 "ll.y"
	{ printf("Rule16\n"); }
break;
case 17:
#line 94 "ll.y"
	{ printf("Rule17\n"); }
break;
case 18:
#line 95 "ll.y"
	{ printf("Rule18\n"); }
break;
#line 507 "y.tab.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            if ((yychar = YYLEX) < 0) yychar = 0;
#if YYDEBUG
            if (yydebug)
            {
                yys = 0;
                if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
                if (!yys) yys = "illegal-symbol";
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == 0) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
    {
        goto yyoverflow;
    }
    *++yystack.s_mark = (short) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    yyerror("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
