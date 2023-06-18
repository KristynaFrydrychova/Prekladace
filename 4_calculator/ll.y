%{
/*
TynaLang=syntax;
syntax=expr | fceInk | fceDek;
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
fceInk="inkr", "(", expr, ")";
fceDek="dekr", "(", expr, ")";
*/

#include <stdio.h>
//#include "prk-stack.h"
//#include "prints.h"

int yylex();
void yyerror(const char *s);
extern int yylineno;

int inkrement(int x);
int dekrement(int x);

%}

%union {
  int int_value;
  int integer;
  char* str_value;
}

%token L_BR
%token R_BR
%token PLUS
%token MPY
%token<integer> HEX_NUM
%token<integer> INT_NUM
%token<integer> BIN_NUM
%token FCE_INKR
%token FCE_DEKR
%token LINE_END

%type <integer> TynaLang syntax expr expr1 term term1 factor number fceInk fceDek

%%

TynaLang:
    TynaLang syntax LINE_END {
	printf("Syntax OK, Rule1\n");
	printf("Klasický tvar: %d\n", $2);
	printf("\n");
    } //Rule1
    | syntax LINE_END {
	printf("Syntax OK, Rule2\n");
	printf("Klasický tvar: %d\n", $1);
	printf("\n");
    } //Rule2
    ;

syntax:
    expr {
	printf("Rule3\n");
	$$ = $1;
    } // Rule3
    | fceInk {
	printf("Rule4\n");
	$$ = $1;
    } // Rule4
    | fceDek {
	printf("Rule5\n");
	$$ = $1;
    } // Rule5
    ;

expr:
    term expr1 {
	printf("Rule6\n");
	$$ = $1 + $2;
    } // Rule6
    ;

expr1:
    PLUS term expr1 {
	printf("Rule7\n");
	$$ = $2 + $3;
    } // Rule7
    | {
	printf("Rule8\n");
	$$ = 0;
    } // Rule8
    ;

term:
    factor term1 {
	printf("Rule9\n");
	$$ = $1 * $2;
    } // Rule9
    ;

term1:
    MPY factor term1 {
	printf("Rule10\n");
	$$ = $2 * $3;
    } // Rule10
    | {
	printf("Rule11\n");
	$$ = 1;
    } // Rule11
    ;

factor:
    L_BR expr R_BR {
	printf("Rule12\n");
	$$ = $2;
    } // Rule12
    | number {
	printf("Rule13\n");
	$$ = $1;
    } // Rule13
    ;

number:
    HEX_NUM {
	printf("Rule14\n");
	$$ = $1;
    } // Rule14
    | INT_NUM {
	printf("Rule15\n");
	$$ = $1;
    } // Rule15
    | BIN_NUM {
	printf("Rule16\n");
	$$ = $1;
    } // Rule16
    ;

fceInk:
    FCE_INKR L_BR expr R_BR {
	printf("Rule17\n");
        $$ = inkrement($3);
    } // Rule17
    ;

fceDek:
    FCE_DEKR L_BR expr R_BR {
	printf("Rule18\n");
        $$ = dekrement($3);
    } // Rule18
    ;


%%

void yyerror(const char *s) {
    printf("%s\n", s);
}

void main() {
    // yydebug = 1;
    printf("Entering the main");
    yyparse();
}

int inkrement(int x){
    printf("Inkrementace");
    return x+1;
}

int dekrement(int x){
    printf("Dekrementace");
    return x-1;
}


