/* A recursive-descent parser generated by peg 0.1.15 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define YYRULECOUNT 16

#include <stdio.h>
int vars[26];

#ifndef YY_MALLOC
#define YY_MALLOC(C, N)		malloc(N)
#endif
#ifndef YY_REALLOC
#define YY_REALLOC(C, P, N)	realloc(P, N)
#endif
#ifndef YY_FREE
#define YY_FREE(C, P)		free(P)
#endif
#ifndef YY_LOCAL
#define YY_LOCAL(T)	static T
#endif
#ifndef YY_ACTION
#define YY_ACTION(T)	static T
#endif
#ifndef YY_RULE
#define YY_RULE(T)	static T
#endif
#ifndef YY_PARSE
#define YY_PARSE(T)	T
#endif
#ifndef YYPARSE
#define YYPARSE		yyparse
#endif
#ifndef YYPARSEFROM
#define YYPARSEFROM	yyparsefrom
#endif
#ifndef YYRELEASE
#define YYRELEASE	yyrelease
#endif
#ifndef YY_BEGIN
#define YY_BEGIN	( yy->__begin= yy->__pos, 1)
#endif
#ifndef YY_END
#define YY_END		( yy->__end= yy->__pos, 1)
#endif
#ifdef YY_DEBUG
# define yyprintf(args)	fprintf args
#else
# define yyprintf(args)
#endif
#ifndef YYSTYPE
#define YYSTYPE	int
#endif
#ifndef YY_STACK_SIZE
#define YY_STACK_SIZE 128
#endif

#ifndef YY_BUFFER_SIZE
#define YY_BUFFER_SIZE 1024
#endif

#ifndef YY_PART

typedef struct _yycontext yycontext;
typedef void (*yyaction)(yycontext *yy, char *yytext, int yyleng);
typedef struct _yythunk { int begin, end;  yyaction  action;  struct _yythunk *next; } yythunk;

struct _yycontext {
  char     *__buf;
  int       __buflen;
  int       __pos;
  int       __limit;
  char     *__text;
  int       __textlen;
  int       __begin;
  int       __end;
  int       __textmax;
  yythunk  *__thunks;
  int       __thunkslen;
  int       __thunkpos;
  YYSTYPE   __;
  YYSTYPE  *__val;
  YYSTYPE  *__vals;
  int       __valslen;
#ifdef YY_CTX_MEMBERS
  YY_CTX_MEMBERS
#endif
};

#ifdef YY_CTX_LOCAL
#define YY_CTX_PARAM_	yycontext *yyctx,
#define YY_CTX_PARAM	yycontext *yyctx
#define YY_CTX_ARG_	yyctx,
#define YY_CTX_ARG	yyctx
#ifndef YY_INPUT
#define YY_INPUT(yy, buf, result, max_size)		\
  {							\
    int yyc= getchar();					\
    result= (EOF == yyc) ? 0 : (*(buf)= yyc, 1);	\
    yyprintf((stderr, "<%c>", yyc));			\
  }
#endif
#else
#define YY_CTX_PARAM_
#define YY_CTX_PARAM
#define YY_CTX_ARG_
#define YY_CTX_ARG
yycontext _yyctx= { 0, 0 };
yycontext *yyctx= &_yyctx;
#ifndef YY_INPUT
#define YY_INPUT(buf, result, max_size)			\
  {							\
    int yyc= getchar();					\
    result= (EOF == yyc) ? 0 : (*(buf)= yyc, 1);	\
    yyprintf((stderr, "<%c>", yyc));			\
  }
#endif
#endif

YY_LOCAL(int) yyrefill(yycontext *yy)
{
  int yyn;
  while (yy->__buflen - yy->__pos < 512)
    {
      yy->__buflen *= 2;
      yy->__buf= (char *)YY_REALLOC(yy, yy->__buf, yy->__buflen);
    }
#ifdef YY_CTX_LOCAL
  YY_INPUT(yy, (yy->__buf + yy->__pos), yyn, (yy->__buflen - yy->__pos));
#else
  YY_INPUT((yy->__buf + yy->__pos), yyn, (yy->__buflen - yy->__pos));
#endif
  if (!yyn) return 0;
  yy->__limit += yyn;
  return 1;
}

YY_LOCAL(int) yymatchDot(yycontext *yy)
{
  if (yy->__pos >= yy->__limit && !yyrefill(yy)) return 0;
  ++yy->__pos;
  return 1;
}

YY_LOCAL(int) yymatchChar(yycontext *yy, int c)
{
  if (yy->__pos >= yy->__limit && !yyrefill(yy)) return 0;
  if ((unsigned char)yy->__buf[yy->__pos] == c)
    {
      ++yy->__pos;
      yyprintf((stderr, "  ok   yymatchChar(yy, %c) @ %s\n", c, yy->__buf+yy->__pos));
      return 1;
    }
  yyprintf((stderr, "  fail yymatchChar(yy, %c) @ %s\n", c, yy->__buf+yy->__pos));
  return 0;
}

YY_LOCAL(int) yymatchString(yycontext *yy, const char *s)
{
  int yysav= yy->__pos;
  while (*s)
    {
      if (yy->__pos >= yy->__limit && !yyrefill(yy)) return 0;
      if (yy->__buf[yy->__pos] != *s)
        {
          yy->__pos= yysav;
          return 0;
        }
      ++s;
      ++yy->__pos;
    }
  return 1;
}

YY_LOCAL(int) yymatchClass(yycontext *yy, unsigned char *bits)
{
  int c;
  if (yy->__pos >= yy->__limit && !yyrefill(yy)) return 0;
  c= (unsigned char)yy->__buf[yy->__pos];
  if (bits[c >> 3] & (1 << (c & 7)))
    {
      ++yy->__pos;
      yyprintf((stderr, "  ok   yymatchClass @ %s\n", yy->__buf+yy->__pos));
      return 1;
    }
  yyprintf((stderr, "  fail yymatchClass @ %s\n", yy->__buf+yy->__pos));
  return 0;
}

YY_LOCAL(void) yyDo(yycontext *yy, yyaction action, int begin, int end)
{
  while (yy->__thunkpos >= yy->__thunkslen)
    {
      yy->__thunkslen *= 2;
      yy->__thunks= (yythunk *)YY_REALLOC(yy, yy->__thunks, sizeof(yythunk) * yy->__thunkslen);
    }
  yy->__thunks[yy->__thunkpos].begin=  begin;
  yy->__thunks[yy->__thunkpos].end=    end;
  yy->__thunks[yy->__thunkpos].action= action;
  ++yy->__thunkpos;
}

YY_LOCAL(int) yyText(yycontext *yy, int begin, int end)
{
  int yyleng= end - begin;
  if (yyleng <= 0)
    yyleng= 0;
  else
    {
      while (yy->__textlen < (yyleng + 1))
	{
	  yy->__textlen *= 2;
	  yy->__text= (char *)YY_REALLOC(yy, yy->__text, yy->__textlen);
	}
      memcpy(yy->__text, yy->__buf + begin, yyleng);
    }
  yy->__text[yyleng]= '\0';
  return yyleng;
}

YY_LOCAL(void) yyDone(yycontext *yy)
{
  int pos;
  for (pos= 0;  pos < yy->__thunkpos;  ++pos)
    {
      yythunk *thunk= &yy->__thunks[pos];
      int yyleng= thunk->end ? yyText(yy, thunk->begin, thunk->end) : thunk->begin;
      yyprintf((stderr, "DO [%d] %p %s\n", pos, thunk->action, yy->__text));
      thunk->action(yy, yy->__text, yyleng);
    }
  yy->__thunkpos= 0;
}

YY_LOCAL(void) yyCommit(yycontext *yy)
{
  if ((yy->__limit -= yy->__pos))
    {
      memmove(yy->__buf, yy->__buf + yy->__pos, yy->__limit);
    }
  yy->__begin -= yy->__pos;
  yy->__end -= yy->__pos;
  yy->__pos= yy->__thunkpos= 0;
}

YY_LOCAL(int) yyAccept(yycontext *yy, int tp0)
{
  if (tp0)
    {
      fprintf(stderr, "accept denied at %d\n", tp0);
      return 0;
    }
  else
    {
      yyDone(yy);
      yyCommit(yy);
    }
  return 1;
}

YY_LOCAL(void) yyPush(yycontext *yy, char *text, int count)
{
  yy->__val += count;
  while (yy->__valslen <= yy->__val - yy->__vals)
    {
      long offset= yy->__val - yy->__vals;
      yy->__valslen *= 2;
      yy->__vals= (YYSTYPE *)YY_REALLOC(yy, yy->__vals, sizeof(YYSTYPE) * yy->__valslen);
      yy->__val= yy->__vals + offset;
    }
}
YY_LOCAL(void) yyPop(yycontext *yy, char *text, int count)   { yy->__val -= count; }
YY_LOCAL(void) yySet(yycontext *yy, char *text, int count)   { yy->__val[count]= yy->__; }

#endif /* YY_PART */

#define	YYACCEPT	yyAccept(yy, yythunkpos0)

YY_RULE(int) yy_CLOSE(yycontext *yy); /* 16 */
YY_RULE(int) yy_OPEN(yycontext *yy); /* 15 */
YY_RULE(int) yy_NUMBER(yycontext *yy); /* 14 */
YY_RULE(int) yy_DIVIDE(yycontext *yy); /* 13 */
YY_RULE(int) yy_TIMES(yycontext *yy); /* 12 */
YY_RULE(int) yy_Value(yycontext *yy); /* 11 */
YY_RULE(int) yy_MINUS(yycontext *yy); /* 10 */
YY_RULE(int) yy_PLUS(yycontext *yy); /* 9 */
YY_RULE(int) yy_Product(yycontext *yy); /* 8 */
YY_RULE(int) yy_Sum(yycontext *yy); /* 7 */
YY_RULE(int) yy_ASSIGN(yycontext *yy); /* 6 */
YY_RULE(int) yy_ID(yycontext *yy); /* 5 */
YY_RULE(int) yy_EOL(yycontext *yy); /* 4 */
YY_RULE(int) yy_Expr(yycontext *yy); /* 3 */
YY_RULE(int) yy__(yycontext *yy); /* 2 */
YY_RULE(int) yy_Stmt(yycontext *yy); /* 1 */

YY_ACTION(void) yy_1_ID(yycontext *yy, char *yytext, int yyleng)
{
#define __ yy->__
#define yypos yy->__pos
#define yythunkpos yy->__thunkpos
  yyprintf((stderr, "do yy_1_ID\n"));
  {
   __= yytext[0] - 'a'; ;
  }
#undef yythunkpos
#undef yypos
#undef yy
}
YY_ACTION(void) yy_1_NUMBER(yycontext *yy, char *yytext, int yyleng)
{
#define __ yy->__
#define yypos yy->__pos
#define yythunkpos yy->__thunkpos
  yyprintf((stderr, "do yy_1_NUMBER\n"));
  {
   __= atoi(yytext); ;
  }
#undef yythunkpos
#undef yypos
#undef yy
}
YY_ACTION(void) yy_3_Value(yycontext *yy, char *yytext, int yyleng)
{
#define i yy->__val[-1]
#define __ yy->__
#define yypos yy->__pos
#define yythunkpos yy->__thunkpos
  yyprintf((stderr, "do yy_3_Value\n"));
  {
   __= i; ;
  }
#undef yythunkpos
#undef yypos
#undef yy
#undef i
}
YY_ACTION(void) yy_2_Value(yycontext *yy, char *yytext, int yyleng)
{
#define i yy->__val[-1]
#define __ yy->__
#define yypos yy->__pos
#define yythunkpos yy->__thunkpos
  yyprintf((stderr, "do yy_2_Value\n"));
  {
   __= vars[i]; ;
  }
#undef yythunkpos
#undef yypos
#undef yy
#undef i
}
YY_ACTION(void) yy_1_Value(yycontext *yy, char *yytext, int yyleng)
{
#define i yy->__val[-1]
#define __ yy->__
#define yypos yy->__pos
#define yythunkpos yy->__thunkpos
  yyprintf((stderr, "do yy_1_Value\n"));
  {
   __= atoi(yytext); ;
  }
#undef yythunkpos
#undef yypos
#undef yy
#undef i
}
YY_ACTION(void) yy_3_Product(yycontext *yy, char *yytext, int yyleng)
{
#define r yy->__val[-1]
#define l yy->__val[-2]
#define __ yy->__
#define yypos yy->__pos
#define yythunkpos yy->__thunkpos
  yyprintf((stderr, "do yy_3_Product\n"));
  {
   __= l; ;
  }
#undef yythunkpos
#undef yypos
#undef yy
#undef r
#undef l
}
YY_ACTION(void) yy_2_Product(yycontext *yy, char *yytext, int yyleng)
{
#define r yy->__val[-1]
#define l yy->__val[-2]
#define __ yy->__
#define yypos yy->__pos
#define yythunkpos yy->__thunkpos
  yyprintf((stderr, "do yy_2_Product\n"));
  {
   l /= r; ;
  }
#undef yythunkpos
#undef yypos
#undef yy
#undef r
#undef l
}
YY_ACTION(void) yy_1_Product(yycontext *yy, char *yytext, int yyleng)
{
#define r yy->__val[-1]
#define l yy->__val[-2]
#define __ yy->__
#define yypos yy->__pos
#define yythunkpos yy->__thunkpos
  yyprintf((stderr, "do yy_1_Product\n"));
  {
   l *= r; ;
  }
#undef yythunkpos
#undef yypos
#undef yy
#undef r
#undef l
}
YY_ACTION(void) yy_3_Sum(yycontext *yy, char *yytext, int yyleng)
{
#define r yy->__val[-1]
#define l yy->__val[-2]
#define __ yy->__
#define yypos yy->__pos
#define yythunkpos yy->__thunkpos
  yyprintf((stderr, "do yy_3_Sum\n"));
  {
   __= l; ;
  }
#undef yythunkpos
#undef yypos
#undef yy
#undef r
#undef l
}
YY_ACTION(void) yy_2_Sum(yycontext *yy, char *yytext, int yyleng)
{
#define r yy->__val[-1]
#define l yy->__val[-2]
#define __ yy->__
#define yypos yy->__pos
#define yythunkpos yy->__thunkpos
  yyprintf((stderr, "do yy_2_Sum\n"));
  {
   l -= r; ;
  }
#undef yythunkpos
#undef yypos
#undef yy
#undef r
#undef l
}
YY_ACTION(void) yy_1_Sum(yycontext *yy, char *yytext, int yyleng)
{
#define r yy->__val[-1]
#define l yy->__val[-2]
#define __ yy->__
#define yypos yy->__pos
#define yythunkpos yy->__thunkpos
  yyprintf((stderr, "do yy_1_Sum\n"));
  {
   l += r; ;
  }
#undef yythunkpos
#undef yypos
#undef yy
#undef r
#undef l
}
YY_ACTION(void) yy_2_Expr(yycontext *yy, char *yytext, int yyleng)
{
#define s yy->__val[-1]
#define i yy->__val[-2]
#define __ yy->__
#define yypos yy->__pos
#define yythunkpos yy->__thunkpos
  yyprintf((stderr, "do yy_2_Expr\n"));
  {
   __= s; ;
  }
#undef yythunkpos
#undef yypos
#undef yy
#undef s
#undef i
}
YY_ACTION(void) yy_1_Expr(yycontext *yy, char *yytext, int yyleng)
{
#define s yy->__val[-1]
#define i yy->__val[-2]
#define __ yy->__
#define yypos yy->__pos
#define yythunkpos yy->__thunkpos
  yyprintf((stderr, "do yy_1_Expr\n"));
  {
   __= vars[i]= s; ;
  }
#undef yythunkpos
#undef yypos
#undef yy
#undef s
#undef i
}
YY_ACTION(void) yy_2_Stmt(yycontext *yy, char *yytext, int yyleng)
{
#define e yy->__val[-1]
#define __ yy->__
#define yypos yy->__pos
#define yythunkpos yy->__thunkpos
  yyprintf((stderr, "do yy_2_Stmt\n"));
  {
   printf("error\n"); ;
  }
#undef yythunkpos
#undef yypos
#undef yy
#undef e
}
YY_ACTION(void) yy_1_Stmt(yycontext *yy, char *yytext, int yyleng)
{
#define e yy->__val[-1]
#define __ yy->__
#define yypos yy->__pos
#define yythunkpos yy->__thunkpos
  yyprintf((stderr, "do yy_1_Stmt\n"));
  {
   printf("%d\n", e); ;
  }
#undef yythunkpos
#undef yypos
#undef yy
#undef e
}

YY_RULE(int) yy_CLOSE(yycontext *yy)
{  int yypos0= yy->__pos, yythunkpos0= yy->__thunkpos;
  yyprintf((stderr, "%s\n", "CLOSE"));  if (!yymatchChar(yy, ')')) goto l1;  if (!yy__(yy)) goto l1;
  yyprintf((stderr, "  ok   %s @ %s\n", "CLOSE", yy->__buf+yy->__pos));
  return 1;
  l1:;	  yy->__pos= yypos0; yy->__thunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "CLOSE", yy->__buf+yy->__pos));
  return 0;
}
YY_RULE(int) yy_OPEN(yycontext *yy)
{  int yypos0= yy->__pos, yythunkpos0= yy->__thunkpos;
  yyprintf((stderr, "%s\n", "OPEN"));  if (!yymatchChar(yy, '(')) goto l2;  if (!yy__(yy)) goto l2;
  yyprintf((stderr, "  ok   %s @ %s\n", "OPEN", yy->__buf+yy->__pos));
  return 1;
  l2:;	  yy->__pos= yypos0; yy->__thunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "OPEN", yy->__buf+yy->__pos));
  return 0;
}
YY_RULE(int) yy_NUMBER(yycontext *yy)
{  int yypos0= yy->__pos, yythunkpos0= yy->__thunkpos;
  yyprintf((stderr, "%s\n", "NUMBER"));  yyText(yy, yy->__begin, yy->__end);  {
#define yytext yy->__text
#define yyleng yy->__textlen
if (!(YY_BEGIN)) goto l3;
#undef yytext
#undef yyleng
  }  if (!yymatchClass(yy, (unsigned char *)"\000\000\000\000\000\000\377\003\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000")) goto l3;
  l4:;	
  {  int yypos5= yy->__pos, yythunkpos5= yy->__thunkpos;  if (!yymatchClass(yy, (unsigned char *)"\000\000\000\000\000\000\377\003\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000")) goto l5;  goto l4;
  l5:;	  yy->__pos= yypos5; yy->__thunkpos= yythunkpos5;
  }  yyText(yy, yy->__begin, yy->__end);  {
#define yytext yy->__text
#define yyleng yy->__textlen
if (!(YY_END)) goto l3;
#undef yytext
#undef yyleng
  }  if (!yy__(yy)) goto l3;  yyDo(yy, yy_1_NUMBER, yy->__begin, yy->__end);
  yyprintf((stderr, "  ok   %s @ %s\n", "NUMBER", yy->__buf+yy->__pos));
  return 1;
  l3:;	  yy->__pos= yypos0; yy->__thunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "NUMBER", yy->__buf+yy->__pos));
  return 0;
}
YY_RULE(int) yy_DIVIDE(yycontext *yy)
{  int yypos0= yy->__pos, yythunkpos0= yy->__thunkpos;
  yyprintf((stderr, "%s\n", "DIVIDE"));  if (!yymatchChar(yy, '/')) goto l6;  if (!yy__(yy)) goto l6;
  yyprintf((stderr, "  ok   %s @ %s\n", "DIVIDE", yy->__buf+yy->__pos));
  return 1;
  l6:;	  yy->__pos= yypos0; yy->__thunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "DIVIDE", yy->__buf+yy->__pos));
  return 0;
}
YY_RULE(int) yy_TIMES(yycontext *yy)
{  int yypos0= yy->__pos, yythunkpos0= yy->__thunkpos;
  yyprintf((stderr, "%s\n", "TIMES"));  if (!yymatchChar(yy, '*')) goto l7;  if (!yy__(yy)) goto l7;
  yyprintf((stderr, "  ok   %s @ %s\n", "TIMES", yy->__buf+yy->__pos));
  return 1;
  l7:;	  yy->__pos= yypos0; yy->__thunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "TIMES", yy->__buf+yy->__pos));
  return 0;
}
YY_RULE(int) yy_Value(yycontext *yy)
{  int yypos0= yy->__pos, yythunkpos0= yy->__thunkpos;  yyDo(yy, yyPush, 1, 0);
  yyprintf((stderr, "%s\n", "Value"));
  {  int yypos9= yy->__pos, yythunkpos9= yy->__thunkpos;  if (!yy_NUMBER(yy)) goto l10;  yyDo(yy, yySet, -1, 0);  yyDo(yy, yy_1_Value, yy->__begin, yy->__end);  goto l9;
  l10:;	  yy->__pos= yypos9; yy->__thunkpos= yythunkpos9;  if (!yy_ID(yy)) goto l11;  yyDo(yy, yySet, -1, 0);
  {  int yypos12= yy->__pos, yythunkpos12= yy->__thunkpos;  if (!yy_ASSIGN(yy)) goto l12;  goto l11;
  l12:;	  yy->__pos= yypos12; yy->__thunkpos= yythunkpos12;
  }  yyDo(yy, yy_2_Value, yy->__begin, yy->__end);  goto l9;
  l11:;	  yy->__pos= yypos9; yy->__thunkpos= yythunkpos9;  if (!yy_OPEN(yy)) goto l8;  if (!yy_Expr(yy)) goto l8;  yyDo(yy, yySet, -1, 0);  if (!yy_CLOSE(yy)) goto l8;  yyDo(yy, yy_3_Value, yy->__begin, yy->__end);
  }
  l9:;	
  yyprintf((stderr, "  ok   %s @ %s\n", "Value", yy->__buf+yy->__pos));  yyDo(yy, yyPop, 1, 0);
  return 1;
  l8:;	  yy->__pos= yypos0; yy->__thunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "Value", yy->__buf+yy->__pos));
  return 0;
}
YY_RULE(int) yy_MINUS(yycontext *yy)
{  int yypos0= yy->__pos, yythunkpos0= yy->__thunkpos;
  yyprintf((stderr, "%s\n", "MINUS"));  if (!yymatchChar(yy, '-')) goto l13;  if (!yy__(yy)) goto l13;
  yyprintf((stderr, "  ok   %s @ %s\n", "MINUS", yy->__buf+yy->__pos));
  return 1;
  l13:;	  yy->__pos= yypos0; yy->__thunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "MINUS", yy->__buf+yy->__pos));
  return 0;
}
YY_RULE(int) yy_PLUS(yycontext *yy)
{  int yypos0= yy->__pos, yythunkpos0= yy->__thunkpos;
  yyprintf((stderr, "%s\n", "PLUS"));  if (!yymatchChar(yy, '+')) goto l14;  if (!yy__(yy)) goto l14;
  yyprintf((stderr, "  ok   %s @ %s\n", "PLUS", yy->__buf+yy->__pos));
  return 1;
  l14:;	  yy->__pos= yypos0; yy->__thunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "PLUS", yy->__buf+yy->__pos));
  return 0;
}
YY_RULE(int) yy_Product(yycontext *yy)
{  int yypos0= yy->__pos, yythunkpos0= yy->__thunkpos;  yyDo(yy, yyPush, 2, 0);
  yyprintf((stderr, "%s\n", "Product"));  if (!yy_Value(yy)) goto l15;  yyDo(yy, yySet, -2, 0);
  l16:;	
  {  int yypos17= yy->__pos, yythunkpos17= yy->__thunkpos;
  {  int yypos18= yy->__pos, yythunkpos18= yy->__thunkpos;  if (!yy_TIMES(yy)) goto l19;  if (!yy_Value(yy)) goto l19;  yyDo(yy, yySet, -1, 0);  yyDo(yy, yy_1_Product, yy->__begin, yy->__end);  goto l18;
  l19:;	  yy->__pos= yypos18; yy->__thunkpos= yythunkpos18;  if (!yy_DIVIDE(yy)) goto l17;  if (!yy_Value(yy)) goto l17;  yyDo(yy, yySet, -1, 0);  yyDo(yy, yy_2_Product, yy->__begin, yy->__end);
  }
  l18:;	  goto l16;
  l17:;	  yy->__pos= yypos17; yy->__thunkpos= yythunkpos17;
  }  yyDo(yy, yy_3_Product, yy->__begin, yy->__end);
  yyprintf((stderr, "  ok   %s @ %s\n", "Product", yy->__buf+yy->__pos));  yyDo(yy, yyPop, 2, 0);
  return 1;
  l15:;	  yy->__pos= yypos0; yy->__thunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "Product", yy->__buf+yy->__pos));
  return 0;
}
YY_RULE(int) yy_Sum(yycontext *yy)
{  int yypos0= yy->__pos, yythunkpos0= yy->__thunkpos;  yyDo(yy, yyPush, 2, 0);
  yyprintf((stderr, "%s\n", "Sum"));  if (!yy_Product(yy)) goto l20;  yyDo(yy, yySet, -2, 0);
  l21:;	
  {  int yypos22= yy->__pos, yythunkpos22= yy->__thunkpos;
  {  int yypos23= yy->__pos, yythunkpos23= yy->__thunkpos;  if (!yy_PLUS(yy)) goto l24;  if (!yy_Product(yy)) goto l24;  yyDo(yy, yySet, -1, 0);  yyDo(yy, yy_1_Sum, yy->__begin, yy->__end);  goto l23;
  l24:;	  yy->__pos= yypos23; yy->__thunkpos= yythunkpos23;  if (!yy_MINUS(yy)) goto l22;  if (!yy_Product(yy)) goto l22;  yyDo(yy, yySet, -1, 0);  yyDo(yy, yy_2_Sum, yy->__begin, yy->__end);
  }
  l23:;	  goto l21;
  l22:;	  yy->__pos= yypos22; yy->__thunkpos= yythunkpos22;
  }  yyDo(yy, yy_3_Sum, yy->__begin, yy->__end);
  yyprintf((stderr, "  ok   %s @ %s\n", "Sum", yy->__buf+yy->__pos));  yyDo(yy, yyPop, 2, 0);
  return 1;
  l20:;	  yy->__pos= yypos0; yy->__thunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "Sum", yy->__buf+yy->__pos));
  return 0;
}
YY_RULE(int) yy_ASSIGN(yycontext *yy)
{  int yypos0= yy->__pos, yythunkpos0= yy->__thunkpos;
  yyprintf((stderr, "%s\n", "ASSIGN"));  if (!yymatchChar(yy, '=')) goto l25;  if (!yy__(yy)) goto l25;
  yyprintf((stderr, "  ok   %s @ %s\n", "ASSIGN", yy->__buf+yy->__pos));
  return 1;
  l25:;	  yy->__pos= yypos0; yy->__thunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "ASSIGN", yy->__buf+yy->__pos));
  return 0;
}
YY_RULE(int) yy_ID(yycontext *yy)
{  int yypos0= yy->__pos, yythunkpos0= yy->__thunkpos;
  yyprintf((stderr, "%s\n", "ID"));  yyText(yy, yy->__begin, yy->__end);  {
#define yytext yy->__text
#define yyleng yy->__textlen
if (!(YY_BEGIN)) goto l26;
#undef yytext
#undef yyleng
  }  if (!yymatchClass(yy, (unsigned char *)"\000\000\000\000\000\000\000\000\000\000\000\000\376\377\377\007\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000")) goto l26;  yyText(yy, yy->__begin, yy->__end);  {
#define yytext yy->__text
#define yyleng yy->__textlen
if (!(YY_END)) goto l26;
#undef yytext
#undef yyleng
  }  if (!yy__(yy)) goto l26;  yyDo(yy, yy_1_ID, yy->__begin, yy->__end);
  yyprintf((stderr, "  ok   %s @ %s\n", "ID", yy->__buf+yy->__pos));
  return 1;
  l26:;	  yy->__pos= yypos0; yy->__thunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "ID", yy->__buf+yy->__pos));
  return 0;
}
YY_RULE(int) yy_EOL(yycontext *yy)
{  int yypos0= yy->__pos, yythunkpos0= yy->__thunkpos;
  yyprintf((stderr, "%s\n", "EOL"));
  {  int yypos28= yy->__pos, yythunkpos28= yy->__thunkpos;  if (!yymatchChar(yy, '\n')) goto l29;  goto l28;
  l29:;	  yy->__pos= yypos28; yy->__thunkpos= yythunkpos28;  if (!yymatchString(yy, "\r\n")) goto l30;  goto l28;
  l30:;	  yy->__pos= yypos28; yy->__thunkpos= yythunkpos28;  if (!yymatchChar(yy, '\r')) goto l31;  goto l28;
  l31:;	  yy->__pos= yypos28; yy->__thunkpos= yythunkpos28;  if (!yymatchChar(yy, ';')) goto l27;
  }
  l28:;	
  yyprintf((stderr, "  ok   %s @ %s\n", "EOL", yy->__buf+yy->__pos));
  return 1;
  l27:;	  yy->__pos= yypos0; yy->__thunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "EOL", yy->__buf+yy->__pos));
  return 0;
}
YY_RULE(int) yy_Expr(yycontext *yy)
{  int yypos0= yy->__pos, yythunkpos0= yy->__thunkpos;  yyDo(yy, yyPush, 2, 0);
  yyprintf((stderr, "%s\n", "Expr"));
  {  int yypos33= yy->__pos, yythunkpos33= yy->__thunkpos;  if (!yy_ID(yy)) goto l34;  yyDo(yy, yySet, -2, 0);  if (!yy_ASSIGN(yy)) goto l34;  if (!yy_Sum(yy)) goto l34;  yyDo(yy, yySet, -1, 0);  yyDo(yy, yy_1_Expr, yy->__begin, yy->__end);  goto l33;
  l34:;	  yy->__pos= yypos33; yy->__thunkpos= yythunkpos33;  if (!yy_Sum(yy)) goto l32;  yyDo(yy, yySet, -1, 0);  yyDo(yy, yy_2_Expr, yy->__begin, yy->__end);
  }
  l33:;	
  yyprintf((stderr, "  ok   %s @ %s\n", "Expr", yy->__buf+yy->__pos));  yyDo(yy, yyPop, 2, 0);
  return 1;
  l32:;	  yy->__pos= yypos0; yy->__thunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "Expr", yy->__buf+yy->__pos));
  return 0;
}
YY_RULE(int) yy__(yycontext *yy)
{
  yyprintf((stderr, "%s\n", "_"));
  l36:;	
  {  int yypos37= yy->__pos, yythunkpos37= yy->__thunkpos;  if (!yymatchClass(yy, (unsigned char *)"\000\002\000\000\001\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000")) goto l37;  goto l36;
  l37:;	  yy->__pos= yypos37; yy->__thunkpos= yythunkpos37;
  }
  yyprintf((stderr, "  ok   %s @ %s\n", "_", yy->__buf+yy->__pos));
  return 1;
}
YY_RULE(int) yy_Stmt(yycontext *yy)
{  int yypos0= yy->__pos, yythunkpos0= yy->__thunkpos;  yyDo(yy, yyPush, 1, 0);
  yyprintf((stderr, "%s\n", "Stmt"));
  {  int yypos39= yy->__pos, yythunkpos39= yy->__thunkpos;  if (!yy__(yy)) goto l40;  if (!yy_Expr(yy)) goto l40;  yyDo(yy, yySet, -1, 0);  if (!yy_EOL(yy)) goto l40;  yyDo(yy, yy_1_Stmt, yy->__begin, yy->__end);  goto l39;
  l40:;	  yy->__pos= yypos39; yy->__thunkpos= yythunkpos39;
  l41:;	
  {  int yypos42= yy->__pos, yythunkpos42= yy->__thunkpos;
  {  int yypos43= yy->__pos, yythunkpos43= yy->__thunkpos;  if (!yy_EOL(yy)) goto l43;  goto l42;
  l43:;	  yy->__pos= yypos43; yy->__thunkpos= yythunkpos43;
  }  if (!yymatchDot(yy)) goto l42;  goto l41;
  l42:;	  yy->__pos= yypos42; yy->__thunkpos= yythunkpos42;
  }  if (!yy_EOL(yy)) goto l38;  yyDo(yy, yy_2_Stmt, yy->__begin, yy->__end);
  }
  l39:;	
  yyprintf((stderr, "  ok   %s @ %s\n", "Stmt", yy->__buf+yy->__pos));  yyDo(yy, yyPop, 1, 0);
  return 1;
  l38:;	  yy->__pos= yypos0; yy->__thunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "Stmt", yy->__buf+yy->__pos));
  return 0;
}

#ifndef YY_PART

typedef int (*yyrule)(yycontext *yy);

YY_PARSE(int) YYPARSEFROM(YY_CTX_PARAM_ yyrule yystart)
{
  int yyok;
  if (!yyctx->__buflen)
    {
      yyctx->__buflen= YY_BUFFER_SIZE;
      yyctx->__buf= (char *)YY_MALLOC(yyctx, yyctx->__buflen);
      yyctx->__textlen= YY_BUFFER_SIZE;
      yyctx->__text= (char *)YY_MALLOC(yyctx, yyctx->__textlen);
      yyctx->__thunkslen= YY_STACK_SIZE;
      yyctx->__thunks= (yythunk *)YY_MALLOC(yyctx, sizeof(yythunk) * yyctx->__thunkslen);
      yyctx->__valslen= YY_STACK_SIZE;
      yyctx->__vals= (YYSTYPE *)YY_MALLOC(yyctx, sizeof(YYSTYPE) * yyctx->__valslen);
      yyctx->__begin= yyctx->__end= yyctx->__pos= yyctx->__limit= yyctx->__thunkpos= 0;
    }
  yyctx->__begin= yyctx->__end= yyctx->__pos;
  yyctx->__thunkpos= 0;
  yyctx->__val= yyctx->__vals;
  yyok= yystart(yyctx);
  if (yyok) yyDone(yyctx);
  yyCommit(yyctx);
  return yyok;
}

YY_PARSE(int) YYPARSE(YY_CTX_PARAM)
{
  return YYPARSEFROM(YY_CTX_ARG_ yy_Stmt);
}

YY_PARSE(yycontext *) YYRELEASE(yycontext *yyctx)
{
  if (yyctx->__buflen)
    {
      yyctx->__buflen= 0;
      YY_FREE(yyctx, yyctx->__buf);
      YY_FREE(yyctx, yyctx->__text);
      YY_FREE(yyctx, yyctx->__thunks);
      YY_FREE(yyctx, yyctx->__vals);
    }
  return yyctx;
}

#endif


int main()
{
  while (yyparse());

  return 0;
}

