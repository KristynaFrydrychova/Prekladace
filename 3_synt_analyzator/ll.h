/* #define VERBOSE 1 */
#undef VERBOSE

#define _CPP_IOSTREAMS y

/* Define constants for patterns - used in process_pattern function */

#define PATT_NO 0 /* No pattern will be sent to parser */

#define PATT_INT_NUM 1 /* Integer number detected */
#define PATT_BIN_NUM 2 /* Binary number detected */
#define PATT_HEX_NUM 3 /* Hexadecimal number detected */
#define PATT_PLUS 4 /* Plus operator */
#define PATT_MPY 5  /* Multiplication operator */
#define PATT_L_BR 6 /* Left bracket */
#define PATT_R_BR 7 /* Close bracket */
#define PATT_FCE_INKR 8 /* Inkrement function detected */
#define PATT_FCE_DEKR 9 /* Decrement function detected */


#define PATT_ERR 100 /* Error in patterns: exit on errors! */


#define ERR_PATTERN 1 /* Lexer: an error pattern detected. */

char *ErrMsgMain = "Error detected with code:";

char Err_Messages[][255] = {"No Error","Lexer: Wrong character detected. Exiting."};

