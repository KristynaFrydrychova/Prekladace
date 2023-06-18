%{
/* Variable declaration */
int lines_done=0;
int void_lines_done=0;
int lines_comment=0;
int add_ops=0;
int mpy_ops=0;
int br_left=0;
int br_right=0;
int int_values=0;
int bin_values=0;
int hexa_values=0;
int inkr_function = 0;
int dekr_function = 0;
int errors_detected=0;

#include "ll.h"
#include "y.tab.h"
#include <stdio.h>
#include <stdlib.h>

/* Function prototypes */

int process_pattern(int number, char *Message, int Pattern);
void print_error(int ERRNO);
void print_msg(char *msg);
int hex_to_int(char* hex);
int bin_to_int(char* expr);

%}
%%
^#.*\n  {lines_comment=process_pattern(lines_comment,"Comment deleted.\n",PATT_NO);}
\+      {
	add_ops=process_pattern(add_ops,"Add operator detected.",PATT_PLUS);
	return PLUS;
	}
\*      {
	mpy_ops=process_pattern(mpy_ops,"Multiplication operator detected.",PATT_MPY);
	return MPY;
	}
\(      {
	br_left=process_pattern(br_left,"Opening bracket detected.",PATT_L_BR);
	return L_BR;
	}
\)	{
	br_right=process_pattern(br_right,"Closing bracket detected.",PATT_R_BR);
	return R_BR;
	} 
(?:0|[1-9][0-9]*)  {
	int_values=process_pattern(int_values,"Ineger number detected.",PATT_INT_NUM);
	yylval.integer = atoi(yytext);
        return INT_NUM;
	}
b[0-1]+ {
	bin_values=process_pattern(bin_values,"Binary number detected.",PATT_BIN_NUM);
	yylval.integer = bin_to_int(yytext);
        return BIN_NUM;
	}
0x[0-9A-F]+  {
	hexa_values=process_pattern(hexa_values,"Hexadecimal number detected.",PATT_HEX_NUM);
	yylval.integer = hex_to_int(yytext);
        return HEX_NUM;
	}
inkr	{
	inkr_function=process_pattern(inkr_function,"Inkr function detected.",PATT_FCE_INKR);
	return FCE_INKR;
	}
dekr	{dekr_function=process_pattern(dekr_function,"Dekr function detected.",PATT_FCE_DEKR);
	return FCE_DEKR;
	}
^\n 	{void_lines_done++;
	    print_msg("Void line detected.\n");
	}
\n     	{lines_done++;
	    print_msg("Line detected.\n");
	    return LINE_END;
	}
.      	{errors_detected=process_pattern(errors_detected,"An error detected.\n",PATT_ERR);}
%%
/* Main part */
/*
int main()
    {
        yylex();
        printf("%d of total errors detected in input file.\n",errors_detected);
        printf("%d of int numbers detected.\n",int_values);
	printf("%d of bin numbers detected.\n",bin_values);
        printf("%d of hexa numbers detected.\n",hexa_values);
        printf("%d of comment lines canceled.\n",lines_comment);
        printf("%d of add operators detected.\n",add_ops);
        printf("%d of multiplication operators detected.\n",mpy_ops);
        printf("%d of opening brackets detected.\n",br_left);
        printf("%d of closing brackets detected.\n",br_right);
        printf("%d of inkr function detected.\n",inkr_function);
        printf("%d of dekr function detected.\n",dekr_function);
        printf("%d of void lines ignored.\nFile processed sucessfully.\n",void_lines_done);
        printf("Totally %d of valid code lines in file processed.\nFile processed sucessfully.\n",lines_done);
        
    }*/

/* Function declaration */

int yywrap(void) {
return 1;
}

void print_msg(char *msg){
    #ifdef VERBOSE
        printf("%s",msg);
    #endif
}

void print_error(int ERRNO){
    #ifdef VERBOSE
    char *message = Err_Messages[ERRNO];
    printf("%s - %d - %s\n",ErrMsgMain,ERR_PATTERN,message);
    #endif
}

int process_pattern(int number,char* Message, int Pattern) {
    if (Pattern == PATT_ERR) {       
        print_error(ERR_PATTERN);        
        //exit(ERR_PATTERN);
    }    

    print_msg(Message);
    
    number++;
    return number;
}

int hex_to_int(char* hex) {
    int result = 0;
    int i = 0;
    // Ignorování prefixu "0x"
    if (hex[0] == '0' && hex[1] == 'x')
        i = 2;
    // Konverze hexadecimálního čísla na integer
    for (; hex[i] != '\0'; i++) {
        result = result * 16;
        if (hex[i] >= '0' && hex[i] <= '9')
            result += hex[i] - '0';
        else if (hex[i] >= 'A' && hex[i] <= 'F')
            result += hex[i] - 'A' + 10;
        else {
            printf("Chybný vstup!\n");
            return 0;
        }
    }
    return result;
}

int bin_to_int(char* expr) {
    int count = 0;
    int i = 0;
    // Ignorování prefixu "b"
    if (expr[0] == 'b')
        i = 1;
    // Počítání nul ve zbytku výrazu
    while (expr[i] != '\0') {
	count = count * 2;
        if (expr[i] == '1')
            count++;
        i++;
    }
    return count;
}

