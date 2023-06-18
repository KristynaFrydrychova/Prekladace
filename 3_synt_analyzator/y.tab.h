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
extern YYSTYPE yylval;
