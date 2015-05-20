/* A recursive-descent parser generated by peg 0.1.15 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define YYRULECOUNT 18

# include "json.h"
# include "tree.h"
# include "version.h"

# include <time.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <libgen.h>
# include <assert.h>

  typedef struct Header Header;

  struct Header {
    char   *text;
    Header *next;
  };

  FILE *input= 0;

  int   verboseFlag= 0;

  static int	 lineNumber= 0;
  static char	*fileName= 0;
  static char	*trailer= 0;
  static Header	*headers= 0;

  void makeHeader(char *text);
  void makeTrailer(char *text);

  void yyerror(char *message);

# define YY_INPUT(buf, result, max)		\
  {						\
    int c= getc(input);				\
    if ('\n' == c || '\r' == c) ++lineNumber;	\
    result= (EOF == c) ? 0 : (*(buf)= c, 1);	\
  }

# define YY_LOCAL(T)	static T
# define YY_RULE(T)	static T

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
#define YYSTYPE	JSON*
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

YY_RULE(int) yy_DIGIT(yycontext *yy); /* 18 */
YY_RULE(int) yy_EXP(yycontext *yy); /* 17 */
YY_RULE(int) yy_FRAC(yycontext *yy); /* 16 */
YY_RULE(int) yy_INT(yycontext *yy); /* 15 */
YY_RULE(int) yy_str(yycontext *yy); /* 14 */
YY_RULE(int) yy_False(yycontext *yy); /* 13 */
YY_RULE(int) yy_True(yycontext *yy); /* 12 */
YY_RULE(int) yy_Null(yycontext *yy); /* 11 */
YY_RULE(int) yy_Number(yycontext *yy); /* 10 */
YY_RULE(int) yy_Value(yycontext *yy); /* 9 */
YY_RULE(int) yy_NAMESEP(yycontext *yy); /* 8 */
YY_RULE(int) yy_String(yycontext *yy); /* 7 */
YY_RULE(int) yy_VALUESEP(yycontext *yy); /* 6 */
YY_RULE(int) yy_Member(yycontext *yy); /* 5 */
YY_RULE(int) yy_Array(yycontext *yy); /* 4 */
YY_RULE(int) yy_JSONObject(yycontext *yy); /* 3 */
YY_RULE(int) yy_S(yycontext *yy); /* 2 */
YY_RULE(int) yy_File(yycontext *yy); /* 1 */

YY_ACTION(void) yy_2_Number(yycontext *yy, char *yytext, int yyleng)
{
#define __ yy->__
#define yypos yy->__pos
#define yythunkpos yy->__thunkpos
  yyprintf((stderr, "do yy_2_Number\n"));
  {
   __ = json_new_integer(atoi(yytext)); ;
  }
#undef yythunkpos
#undef yypos
#undef yy
}
YY_ACTION(void) yy_1_Number(yycontext *yy, char *yytext, int yyleng)
{
#define __ yy->__
#define yypos yy->__pos
#define yythunkpos yy->__thunkpos
  yyprintf((stderr, "do yy_1_Number\n"));
  {
   __ = json_new_double(atoi(yytext)); ;
  }
#undef yythunkpos
#undef yypos
#undef yy
}
YY_ACTION(void) yy_1_str(yycontext *yy, char *yytext, int yyleng)
{
#define __ yy->__
#define yypos yy->__pos
#define yythunkpos yy->__thunkpos
  yyprintf((stderr, "do yy_1_str\n"));
  {
   __ = json_new_string(yytext); ;
  }
#undef yythunkpos
#undef yypos
#undef yy
}
YY_ACTION(void) yy_1_String(yycontext *yy, char *yytext, int yyleng)
{
#define s yy->__val[-1]
#define __ yy->__
#define yypos yy->__pos
#define yythunkpos yy->__thunkpos
  yyprintf((stderr, "do yy_1_String\n"));
  {
   __ = s; ;
  }
#undef yythunkpos
#undef yypos
#undef yy
#undef s
}
YY_ACTION(void) yy_3_Array(yycontext *yy, char *yytext, int yyleng)
{
#define l yy->__val[-1]
#define f yy->__val[-2]
#define __ yy->__
#define yypos yy->__pos
#define yythunkpos yy->__thunkpos
  yyprintf((stderr, "do yy_3_Array\n"));
  {
   __ = json_new_array(f); ;
  }
#undef yythunkpos
#undef yypos
#undef yy
#undef l
#undef f
}
YY_ACTION(void) yy_2_Array(yycontext *yy, char *yytext, int yyleng)
{
#define l yy->__val[-1]
#define f yy->__val[-2]
#define __ yy->__
#define yypos yy->__pos
#define yythunkpos yy->__thunkpos
  yyprintf((stderr, "do yy_2_Array\n"));
  {
   f = json_add_element(f, json_new_element(l)); ;
  }
#undef yythunkpos
#undef yypos
#undef yy
#undef l
#undef f
}
YY_ACTION(void) yy_1_Array(yycontext *yy, char *yytext, int yyleng)
{
#define l yy->__val[-1]
#define f yy->__val[-2]
#define __ yy->__
#define yypos yy->__pos
#define yythunkpos yy->__thunkpos
  yyprintf((stderr, "do yy_1_Array\n"));
  {
   f = json_new_element(f); ;
  }
#undef yythunkpos
#undef yypos
#undef yy
#undef l
#undef f
}
YY_ACTION(void) yy_7_Value(yycontext *yy, char *yytext, int yyleng)
{
#define a yy->__val[-1]
#define o yy->__val[-2]
#define n yy->__val[-3]
#define s yy->__val[-4]
#define __ yy->__
#define yypos yy->__pos
#define yythunkpos yy->__thunkpos
  yyprintf((stderr, "do yy_7_Value\n"));
  {
   __ = json_new_false(); ;
  }
#undef yythunkpos
#undef yypos
#undef yy
#undef a
#undef o
#undef n
#undef s
}
YY_ACTION(void) yy_6_Value(yycontext *yy, char *yytext, int yyleng)
{
#define a yy->__val[-1]
#define o yy->__val[-2]
#define n yy->__val[-3]
#define s yy->__val[-4]
#define __ yy->__
#define yypos yy->__pos
#define yythunkpos yy->__thunkpos
  yyprintf((stderr, "do yy_6_Value\n"));
  {
   __ = json_new_true(); ;
  }
#undef yythunkpos
#undef yypos
#undef yy
#undef a
#undef o
#undef n
#undef s
}
YY_ACTION(void) yy_5_Value(yycontext *yy, char *yytext, int yyleng)
{
#define a yy->__val[-1]
#define o yy->__val[-2]
#define n yy->__val[-3]
#define s yy->__val[-4]
#define __ yy->__
#define yypos yy->__pos
#define yythunkpos yy->__thunkpos
  yyprintf((stderr, "do yy_5_Value\n"));
  {
   __ = json_new_null(); ;
  }
#undef yythunkpos
#undef yypos
#undef yy
#undef a
#undef o
#undef n
#undef s
}
YY_ACTION(void) yy_4_Value(yycontext *yy, char *yytext, int yyleng)
{
#define a yy->__val[-1]
#define o yy->__val[-2]
#define n yy->__val[-3]
#define s yy->__val[-4]
#define __ yy->__
#define yypos yy->__pos
#define yythunkpos yy->__thunkpos
  yyprintf((stderr, "do yy_4_Value\n"));
  {
   __ = json_new_array_value(a); ;
  }
#undef yythunkpos
#undef yypos
#undef yy
#undef a
#undef o
#undef n
#undef s
}
YY_ACTION(void) yy_3_Value(yycontext *yy, char *yytext, int yyleng)
{
#define a yy->__val[-1]
#define o yy->__val[-2]
#define n yy->__val[-3]
#define s yy->__val[-4]
#define __ yy->__
#define yypos yy->__pos
#define yythunkpos yy->__thunkpos
  yyprintf((stderr, "do yy_3_Value\n"));
  {
   __ = json_new_object_value(o); ;
  }
#undef yythunkpos
#undef yypos
#undef yy
#undef a
#undef o
#undef n
#undef s
}
YY_ACTION(void) yy_2_Value(yycontext *yy, char *yytext, int yyleng)
{
#define a yy->__val[-1]
#define o yy->__val[-2]
#define n yy->__val[-3]
#define s yy->__val[-4]
#define __ yy->__
#define yypos yy->__pos
#define yythunkpos yy->__thunkpos
  yyprintf((stderr, "do yy_2_Value\n"));
  {
   __ = n; ;
  }
#undef yythunkpos
#undef yypos
#undef yy
#undef a
#undef o
#undef n
#undef s
}
YY_ACTION(void) yy_1_Value(yycontext *yy, char *yytext, int yyleng)
{
#define a yy->__val[-1]
#define o yy->__val[-2]
#define n yy->__val[-3]
#define s yy->__val[-4]
#define __ yy->__
#define yypos yy->__pos
#define yythunkpos yy->__thunkpos
  yyprintf((stderr, "do yy_1_Value\n"));
  {
   __ = s; ;
  }
#undef yythunkpos
#undef yypos
#undef yy
#undef a
#undef o
#undef n
#undef s
}
YY_ACTION(void) yy_1_Member(yycontext *yy, char *yytext, int yyleng)
{
#define v yy->__val[-1]
#define s yy->__val[-2]
#define __ yy->__
#define yypos yy->__pos
#define yythunkpos yy->__thunkpos
  yyprintf((stderr, "do yy_1_Member\n"));
  {
   __ = json_new_member(s, v); ;
  }
#undef yythunkpos
#undef yypos
#undef yy
#undef v
#undef s
}
YY_ACTION(void) yy_2_JSONObject(yycontext *yy, char *yytext, int yyleng)
{
#define l yy->__val[-1]
#define f yy->__val[-2]
#define __ yy->__
#define yypos yy->__pos
#define yythunkpos yy->__thunkpos
  yyprintf((stderr, "do yy_2_JSONObject\n"));
  {
   __ = json_new_object(f); ;
  }
#undef yythunkpos
#undef yypos
#undef yy
#undef l
#undef f
}
YY_ACTION(void) yy_1_JSONObject(yycontext *yy, char *yytext, int yyleng)
{
#define l yy->__val[-1]
#define f yy->__val[-2]
#define __ yy->__
#define yypos yy->__pos
#define yythunkpos yy->__thunkpos
  yyprintf((stderr, "do yy_1_JSONObject\n"));
  {
   f = json_add_member(f, l); ;
  }
#undef yythunkpos
#undef yypos
#undef yy
#undef l
#undef f
}
YY_ACTION(void) yy_2_File(yycontext *yy, char *yytext, int yyleng)
{
#define a yy->__val[-1]
#define o yy->__val[-2]
#define __ yy->__
#define yypos yy->__pos
#define yythunkpos yy->__thunkpos
  yyprintf((stderr, "do yy_2_File\n"));
  {
   JSON *jsona = a; ;
  }
#undef yythunkpos
#undef yypos
#undef yy
#undef a
#undef o
}
YY_ACTION(void) yy_1_File(yycontext *yy, char *yytext, int yyleng)
{
#define a yy->__val[-1]
#define o yy->__val[-2]
#define __ yy->__
#define yypos yy->__pos
#define yythunkpos yy->__thunkpos
  yyprintf((stderr, "do yy_1_File\n"));
  {
   JSON *jsono = o; //json_print(stdout, jsono); ;
  }
#undef yythunkpos
#undef yypos
#undef yy
#undef a
#undef o
}

YY_RULE(int) yy_DIGIT(yycontext *yy)
{  int yypos0= yy->__pos, yythunkpos0= yy->__thunkpos;
  yyprintf((stderr, "%s\n", "DIGIT"));  if (!yymatchClass(yy, (unsigned char *)"\000\000\000\000\000\000\377\003\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000")) goto l1;
  yyprintf((stderr, "  ok   %s @ %s\n", "DIGIT", yy->__buf+yy->__pos));
  return 1;
  l1:;	  yy->__pos= yypos0; yy->__thunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "DIGIT", yy->__buf+yy->__pos));
  return 0;
}
YY_RULE(int) yy_EXP(yycontext *yy)
{  int yypos0= yy->__pos, yythunkpos0= yy->__thunkpos;
  yyprintf((stderr, "%s\n", "EXP"));  if (!yymatchClass(yy, (unsigned char *)"\000\000\000\000\000\000\000\000\040\000\000\000\040\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000")) goto l2;
  {  int yypos3= yy->__pos, yythunkpos3= yy->__thunkpos;
  {  int yypos5= yy->__pos, yythunkpos5= yy->__thunkpos;  if (!yymatchChar(yy, '-')) goto l6;  goto l5;
  l6:;	  yy->__pos= yypos5; yy->__thunkpos= yythunkpos5;  if (!yymatchChar(yy, '+')) goto l3;
  }
  l5:;	  goto l4;
  l3:;	  yy->__pos= yypos3; yy->__thunkpos= yythunkpos3;
  }
  l4:;	  if (!yy_DIGIT(yy)) goto l2;
  l7:;	
  {  int yypos8= yy->__pos, yythunkpos8= yy->__thunkpos;  if (!yy_DIGIT(yy)) goto l8;  goto l7;
  l8:;	  yy->__pos= yypos8; yy->__thunkpos= yythunkpos8;
  }
  yyprintf((stderr, "  ok   %s @ %s\n", "EXP", yy->__buf+yy->__pos));
  return 1;
  l2:;	  yy->__pos= yypos0; yy->__thunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "EXP", yy->__buf+yy->__pos));
  return 0;
}
YY_RULE(int) yy_FRAC(yycontext *yy)
{  int yypos0= yy->__pos, yythunkpos0= yy->__thunkpos;
  yyprintf((stderr, "%s\n", "FRAC"));  if (!yymatchChar(yy, '.')) goto l9;  if (!yy_DIGIT(yy)) goto l9;
  l10:;	
  {  int yypos11= yy->__pos, yythunkpos11= yy->__thunkpos;  if (!yy_DIGIT(yy)) goto l11;  goto l10;
  l11:;	  yy->__pos= yypos11; yy->__thunkpos= yythunkpos11;
  }
  yyprintf((stderr, "  ok   %s @ %s\n", "FRAC", yy->__buf+yy->__pos));
  return 1;
  l9:;	  yy->__pos= yypos0; yy->__thunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "FRAC", yy->__buf+yy->__pos));
  return 0;
}
YY_RULE(int) yy_INT(yycontext *yy)
{  int yypos0= yy->__pos, yythunkpos0= yy->__thunkpos;
  yyprintf((stderr, "%s\n", "INT"));
  {  int yypos13= yy->__pos, yythunkpos13= yy->__thunkpos;  if (!yymatchChar(yy, '0')) goto l14;  goto l13;
  l14:;	  yy->__pos= yypos13; yy->__thunkpos= yythunkpos13;  if (!yymatchClass(yy, (unsigned char *)"\000\000\000\000\000\000\376\003\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000")) goto l12;
  l15:;	
  {  int yypos16= yy->__pos, yythunkpos16= yy->__thunkpos;  if (!yy_DIGIT(yy)) goto l16;  goto l15;
  l16:;	  yy->__pos= yypos16; yy->__thunkpos= yythunkpos16;
  }
  }
  l13:;	
  yyprintf((stderr, "  ok   %s @ %s\n", "INT", yy->__buf+yy->__pos));
  return 1;
  l12:;	  yy->__pos= yypos0; yy->__thunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "INT", yy->__buf+yy->__pos));
  return 0;
}
YY_RULE(int) yy_str(yycontext *yy)
{  int yypos0= yy->__pos, yythunkpos0= yy->__thunkpos;
  yyprintf((stderr, "%s\n", "str"));
  l18:;	
  {  int yypos19= yy->__pos, yythunkpos19= yy->__thunkpos;
  {  int yypos20= yy->__pos, yythunkpos20= yy->__thunkpos;  if (!yymatchString(yy, "\\\"")) goto l21;  goto l20;
  l21:;	  yy->__pos= yypos20; yy->__thunkpos= yythunkpos20;  if (!yymatchString(yy, "\\\\")) goto l22;  goto l20;
  l22:;	  yy->__pos= yypos20; yy->__thunkpos= yythunkpos20;
  {  int yypos23= yy->__pos, yythunkpos23= yy->__thunkpos;  if (!yymatchChar(yy, '"')) goto l23;  goto l19;
  l23:;	  yy->__pos= yypos23; yy->__thunkpos= yythunkpos23;
  }  if (!yymatchDot(yy)) goto l19;
  }
  l20:;	  goto l18;
  l19:;	  yy->__pos= yypos19; yy->__thunkpos= yythunkpos19;
  }  yyDo(yy, yy_1_str, yy->__begin, yy->__end);
  yyprintf((stderr, "  ok   %s @ %s\n", "str", yy->__buf+yy->__pos));
  return 1;
  l17:;	  yy->__pos= yypos0; yy->__thunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "str", yy->__buf+yy->__pos));
  return 0;
}
YY_RULE(int) yy_False(yycontext *yy)
{  int yypos0= yy->__pos, yythunkpos0= yy->__thunkpos;
  yyprintf((stderr, "%s\n", "False"));  if (!yymatchString(yy, "false")) goto l24;
  yyprintf((stderr, "  ok   %s @ %s\n", "False", yy->__buf+yy->__pos));
  return 1;
  l24:;	  yy->__pos= yypos0; yy->__thunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "False", yy->__buf+yy->__pos));
  return 0;
}
YY_RULE(int) yy_True(yycontext *yy)
{  int yypos0= yy->__pos, yythunkpos0= yy->__thunkpos;
  yyprintf((stderr, "%s\n", "True"));  if (!yymatchString(yy, "true")) goto l25;
  yyprintf((stderr, "  ok   %s @ %s\n", "True", yy->__buf+yy->__pos));
  return 1;
  l25:;	  yy->__pos= yypos0; yy->__thunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "True", yy->__buf+yy->__pos));
  return 0;
}
YY_RULE(int) yy_Null(yycontext *yy)
{  int yypos0= yy->__pos, yythunkpos0= yy->__thunkpos;
  yyprintf((stderr, "%s\n", "Null"));  if (!yymatchString(yy, "null")) goto l26;
  yyprintf((stderr, "  ok   %s @ %s\n", "Null", yy->__buf+yy->__pos));
  return 1;
  l26:;	  yy->__pos= yypos0; yy->__thunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "Null", yy->__buf+yy->__pos));
  return 0;
}
YY_RULE(int) yy_Number(yycontext *yy)
{  int yypos0= yy->__pos, yythunkpos0= yy->__thunkpos;
  yyprintf((stderr, "%s\n", "Number"));
  {  int yypos28= yy->__pos, yythunkpos28= yy->__thunkpos;  if (!yymatchChar(yy, '-')) goto l28;  goto l29;
  l28:;	  yy->__pos= yypos28; yy->__thunkpos= yythunkpos28;
  }
  l29:;	  if (!yy_INT(yy)) goto l27;
  {  int yypos30= yy->__pos, yythunkpos30= yy->__thunkpos;  if (!yy_FRAC(yy)) goto l31;
  {  int yypos32= yy->__pos, yythunkpos32= yy->__thunkpos;  if (!yy_EXP(yy)) goto l32;  goto l33;
  l32:;	  yy->__pos= yypos32; yy->__thunkpos= yythunkpos32;
  }
  l33:;	  yyDo(yy, yy_1_Number, yy->__begin, yy->__end);  goto l30;
  l31:;	  yy->__pos= yypos30; yy->__thunkpos= yythunkpos30;  if (!yymatchString(yy, "")) goto l27;  yyDo(yy, yy_2_Number, yy->__begin, yy->__end);
  }
  l30:;	
  yyprintf((stderr, "  ok   %s @ %s\n", "Number", yy->__buf+yy->__pos));
  return 1;
  l27:;	  yy->__pos= yypos0; yy->__thunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "Number", yy->__buf+yy->__pos));
  return 0;
}
YY_RULE(int) yy_Value(yycontext *yy)
{  int yypos0= yy->__pos, yythunkpos0= yy->__thunkpos;  yyDo(yy, yyPush, 4, 0);
  yyprintf((stderr, "%s\n", "Value"));
  {  int yypos35= yy->__pos, yythunkpos35= yy->__thunkpos;  if (!yy_String(yy)) goto l36;  yyDo(yy, yySet, -4, 0);  yyDo(yy, yy_1_Value, yy->__begin, yy->__end);  goto l35;
  l36:;	  yy->__pos= yypos35; yy->__thunkpos= yythunkpos35;  if (!yy_Number(yy)) goto l37;  yyDo(yy, yySet, -3, 0);  yyDo(yy, yy_2_Value, yy->__begin, yy->__end);  goto l35;
  l37:;	  yy->__pos= yypos35; yy->__thunkpos= yythunkpos35;  if (!yy_JSONObject(yy)) goto l38;  yyDo(yy, yySet, -2, 0);  yyDo(yy, yy_3_Value, yy->__begin, yy->__end);  goto l35;
  l38:;	  yy->__pos= yypos35; yy->__thunkpos= yythunkpos35;  if (!yy_Array(yy)) goto l39;  yyDo(yy, yySet, -1, 0);  yyDo(yy, yy_4_Value, yy->__begin, yy->__end);  goto l35;
  l39:;	  yy->__pos= yypos35; yy->__thunkpos= yythunkpos35;  if (!yy_Null(yy)) goto l40;  yyDo(yy, yy_5_Value, yy->__begin, yy->__end);  goto l35;
  l40:;	  yy->__pos= yypos35; yy->__thunkpos= yythunkpos35;  if (!yy_True(yy)) goto l41;  yyDo(yy, yy_6_Value, yy->__begin, yy->__end);  goto l35;
  l41:;	  yy->__pos= yypos35; yy->__thunkpos= yythunkpos35;  if (!yy_False(yy)) goto l34;  yyDo(yy, yy_7_Value, yy->__begin, yy->__end);
  }
  l35:;	
  yyprintf((stderr, "  ok   %s @ %s\n", "Value", yy->__buf+yy->__pos));  yyDo(yy, yyPop, 4, 0);
  return 1;
  l34:;	  yy->__pos= yypos0; yy->__thunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "Value", yy->__buf+yy->__pos));
  return 0;
}
YY_RULE(int) yy_NAMESEP(yycontext *yy)
{  int yypos0= yy->__pos, yythunkpos0= yy->__thunkpos;
  yyprintf((stderr, "%s\n", "NAMESEP"));
  l43:;	
  {  int yypos44= yy->__pos, yythunkpos44= yy->__thunkpos;  if (!yy_S(yy)) goto l44;  goto l43;
  l44:;	  yy->__pos= yypos44; yy->__thunkpos= yythunkpos44;
  }  if (!yymatchChar(yy, ':')) goto l42;
  l45:;	
  {  int yypos46= yy->__pos, yythunkpos46= yy->__thunkpos;  if (!yy_S(yy)) goto l46;  goto l45;
  l46:;	  yy->__pos= yypos46; yy->__thunkpos= yythunkpos46;
  }
  yyprintf((stderr, "  ok   %s @ %s\n", "NAMESEP", yy->__buf+yy->__pos));
  return 1;
  l42:;	  yy->__pos= yypos0; yy->__thunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "NAMESEP", yy->__buf+yy->__pos));
  return 0;
}
YY_RULE(int) yy_String(yycontext *yy)
{  int yypos0= yy->__pos, yythunkpos0= yy->__thunkpos;  yyDo(yy, yyPush, 1, 0);
  yyprintf((stderr, "%s\n", "String"));  if (!yymatchChar(yy, '"')) goto l47;  if (!yy_str(yy)) goto l47;  yyDo(yy, yySet, -1, 0);  if (!yymatchChar(yy, '"')) goto l47;  yyDo(yy, yy_1_String, yy->__begin, yy->__end);
  yyprintf((stderr, "  ok   %s @ %s\n", "String", yy->__buf+yy->__pos));  yyDo(yy, yyPop, 1, 0);
  return 1;
  l47:;	  yy->__pos= yypos0; yy->__thunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "String", yy->__buf+yy->__pos));
  return 0;
}
YY_RULE(int) yy_VALUESEP(yycontext *yy)
{  int yypos0= yy->__pos, yythunkpos0= yy->__thunkpos;
  yyprintf((stderr, "%s\n", "VALUESEP"));
  l49:;	
  {  int yypos50= yy->__pos, yythunkpos50= yy->__thunkpos;  if (!yy_S(yy)) goto l50;  goto l49;
  l50:;	  yy->__pos= yypos50; yy->__thunkpos= yythunkpos50;
  }  if (!yymatchChar(yy, ',')) goto l48;
  l51:;	
  {  int yypos52= yy->__pos, yythunkpos52= yy->__thunkpos;  if (!yy_S(yy)) goto l52;  goto l51;
  l52:;	  yy->__pos= yypos52; yy->__thunkpos= yythunkpos52;
  }
  yyprintf((stderr, "  ok   %s @ %s\n", "VALUESEP", yy->__buf+yy->__pos));
  return 1;
  l48:;	  yy->__pos= yypos0; yy->__thunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "VALUESEP", yy->__buf+yy->__pos));
  return 0;
}
YY_RULE(int) yy_Member(yycontext *yy)
{  int yypos0= yy->__pos, yythunkpos0= yy->__thunkpos;  yyDo(yy, yyPush, 2, 0);
  yyprintf((stderr, "%s\n", "Member"));  if (!yy_String(yy)) goto l53;  yyDo(yy, yySet, -2, 0);  if (!yy_NAMESEP(yy)) goto l53;  if (!yy_Value(yy)) goto l53;  yyDo(yy, yySet, -1, 0);  yyDo(yy, yy_1_Member, yy->__begin, yy->__end);
  yyprintf((stderr, "  ok   %s @ %s\n", "Member", yy->__buf+yy->__pos));  yyDo(yy, yyPop, 2, 0);
  return 1;
  l53:;	  yy->__pos= yypos0; yy->__thunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "Member", yy->__buf+yy->__pos));
  return 0;
}
YY_RULE(int) yy_Array(yycontext *yy)
{  int yypos0= yy->__pos, yythunkpos0= yy->__thunkpos;  yyDo(yy, yyPush, 2, 0);
  yyprintf((stderr, "%s\n", "Array"));  if (!yymatchChar(yy, '[')) goto l54;
  {  int yypos55= yy->__pos, yythunkpos55= yy->__thunkpos;
  l57:;	
  {  int yypos58= yy->__pos, yythunkpos58= yy->__thunkpos;  if (!yy_S(yy)) goto l58;  goto l57;
  l58:;	  yy->__pos= yypos58; yy->__thunkpos= yythunkpos58;
  }  if (!yy_Value(yy)) goto l55;  yyDo(yy, yySet, -2, 0);  yyDo(yy, yy_1_Array, yy->__begin, yy->__end);
  l59:;	
  {  int yypos60= yy->__pos, yythunkpos60= yy->__thunkpos;  if (!yy_VALUESEP(yy)) goto l60;  if (!yy_Value(yy)) goto l60;  yyDo(yy, yySet, -1, 0);  yyDo(yy, yy_2_Array, yy->__begin, yy->__end);  goto l59;
  l60:;	  yy->__pos= yypos60; yy->__thunkpos= yythunkpos60;
  }  goto l56;
  l55:;	  yy->__pos= yypos55; yy->__thunkpos= yythunkpos55;
  }
  l56:;	
  l61:;	
  {  int yypos62= yy->__pos, yythunkpos62= yy->__thunkpos;  if (!yy_S(yy)) goto l62;  goto l61;
  l62:;	  yy->__pos= yypos62; yy->__thunkpos= yythunkpos62;
  }  if (!yymatchChar(yy, ']')) goto l54;  yyDo(yy, yy_3_Array, yy->__begin, yy->__end);
  yyprintf((stderr, "  ok   %s @ %s\n", "Array", yy->__buf+yy->__pos));  yyDo(yy, yyPop, 2, 0);
  return 1;
  l54:;	  yy->__pos= yypos0; yy->__thunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "Array", yy->__buf+yy->__pos));
  return 0;
}
YY_RULE(int) yy_JSONObject(yycontext *yy)
{  int yypos0= yy->__pos, yythunkpos0= yy->__thunkpos;  yyDo(yy, yyPush, 2, 0);
  yyprintf((stderr, "%s\n", "JSONObject"));  if (!yymatchChar(yy, '{')) goto l63;
  {  int yypos64= yy->__pos, yythunkpos64= yy->__thunkpos;
  l66:;	
  {  int yypos67= yy->__pos, yythunkpos67= yy->__thunkpos;  if (!yy_S(yy)) goto l67;  goto l66;
  l67:;	  yy->__pos= yypos67; yy->__thunkpos= yythunkpos67;
  }  if (!yy_Member(yy)) goto l64;  yyDo(yy, yySet, -2, 0);
  l68:;	
  {  int yypos69= yy->__pos, yythunkpos69= yy->__thunkpos;  if (!yy_VALUESEP(yy)) goto l69;  if (!yy_Member(yy)) goto l69;  yyDo(yy, yySet, -1, 0);  yyDo(yy, yy_1_JSONObject, yy->__begin, yy->__end);  goto l68;
  l69:;	  yy->__pos= yypos69; yy->__thunkpos= yythunkpos69;
  }  goto l65;
  l64:;	  yy->__pos= yypos64; yy->__thunkpos= yythunkpos64;
  }
  l65:;	
  l70:;	
  {  int yypos71= yy->__pos, yythunkpos71= yy->__thunkpos;  if (!yy_S(yy)) goto l71;  goto l70;
  l71:;	  yy->__pos= yypos71; yy->__thunkpos= yythunkpos71;
  }  if (!yymatchChar(yy, '}')) goto l63;  yyDo(yy, yy_2_JSONObject, yy->__begin, yy->__end);
  yyprintf((stderr, "  ok   %s @ %s\n", "JSONObject", yy->__buf+yy->__pos));  yyDo(yy, yyPop, 2, 0);
  return 1;
  l63:;	  yy->__pos= yypos0; yy->__thunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "JSONObject", yy->__buf+yy->__pos));
  return 0;
}
YY_RULE(int) yy_S(yycontext *yy)
{  int yypos0= yy->__pos, yythunkpos0= yy->__thunkpos;
  yyprintf((stderr, "%s\n", "S"));  if (!yymatchClass(yy, (unsigned char *)"\000\046\000\000\001\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000")) goto l72;
  yyprintf((stderr, "  ok   %s @ %s\n", "S", yy->__buf+yy->__pos));
  return 1;
  l72:;	  yy->__pos= yypos0; yy->__thunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "S", yy->__buf+yy->__pos));
  return 0;
}
YY_RULE(int) yy_File(yycontext *yy)
{  int yypos0= yy->__pos, yythunkpos0= yy->__thunkpos;  yyDo(yy, yyPush, 2, 0);
  yyprintf((stderr, "%s\n", "File"));
  l74:;	
  {  int yypos75= yy->__pos, yythunkpos75= yy->__thunkpos;  if (!yy_S(yy)) goto l75;  goto l74;
  l75:;	  yy->__pos= yypos75; yy->__thunkpos= yythunkpos75;
  }
  {  int yypos76= yy->__pos, yythunkpos76= yy->__thunkpos;  if (!yy_JSONObject(yy)) goto l77;  yyDo(yy, yySet, -2, 0);  yyDo(yy, yy_1_File, yy->__begin, yy->__end);  goto l76;
  l77:;	  yy->__pos= yypos76; yy->__thunkpos= yythunkpos76;  if (!yy_Array(yy)) goto l73;  yyDo(yy, yySet, -1, 0);
  }
  l76:;	
  l78:;	
  {  int yypos79= yy->__pos, yythunkpos79= yy->__thunkpos;  if (!yy_S(yy)) goto l79;  goto l78;
  l79:;	  yy->__pos= yypos79; yy->__thunkpos= yythunkpos79;
  }  yyDo(yy, yy_2_File, yy->__begin, yy->__end);
  yyprintf((stderr, "  ok   %s @ %s\n", "File", yy->__buf+yy->__pos));  yyDo(yy, yyPop, 2, 0);
  return 1;
  l73:;	  yy->__pos= yypos0; yy->__thunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "File", yy->__buf+yy->__pos));
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
  return YYPARSEFROM(YY_CTX_ARG_ yy_File);
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


void yyerror(char *message)
{
  fprintf(stderr, "%s:%d: %s", fileName, lineNumber, message);
  if (yyctx->__text[0]) fprintf(stderr, " near token '%s'", yyctx->__text);
  if (yyctx->__pos < yyctx->__limit || !feof(input))
    {
      yyctx->__buf[yyctx->__limit]= '\0';
      fprintf(stderr, " before text \"");
      while (yyctx->__pos < yyctx->__limit)
	{
	  if ('\n' == yyctx->__buf[yyctx->__pos] || '\r' == yyctx->__buf[yyctx->__pos]) break;
	  fputc(yyctx->__buf[yyctx->__pos++], stderr);
	}
      if (yyctx->__pos == yyctx->__limit)
	{
	  int c;
	  while (EOF != (c= fgetc(input)) && '\n' != c && '\r' != c)
	    fputc(c, stderr);
	}
      fputc('\"', stderr);
    }
  fprintf(stderr, "\n");
  exit(1);
}

void makeHeader(char *text)
{
  Header *header= (Header *)malloc(sizeof(Header));
  header->text= strdup(text);
  header->next= headers;
  headers= header;
}

void makeTrailer(char *text)
{
  trailer= strdup(text);
}

static void version(char *name)
{
  printf("%s version %d.%d.%d\n", name, PEG_MAJOR, PEG_MINOR, PEG_LEVEL);
}

static void usage(char *name)
{
  version(name);
  fprintf(stderr, "usage: %s [<option>...] [<file>...]\n", name);
  fprintf(stderr, "where <option> can be\n");
  fprintf(stderr, "  -h          print this help information\n");
  fprintf(stderr, "  -o <ofile>  write output to <ofile>\n");
  fprintf(stderr, "  -v          be verbose\n");
  fprintf(stderr, "  -V          print version number and exit\n");
  fprintf(stderr, "if no <file> is given, input is read from stdin\n");
  fprintf(stderr, "if no <ofile> is given, output is written to stdout\n");
  exit(1);
}

int main(int argc, char **argv)
{
  input= stdin;
  lineNumber= 1;
  fileName= "<stdin>";
  
  for (int i = 0; i < 5; i++) {
    if (argc >= 2) {
      if (!(input = fopen(argv[1], "r"))) {
        fprintf(stderr, "File [%s] is not found!\n", argv[1]);
        return 1;
      }
    }
  
    clock_t start = clock();
    if ((yyparse())) {
      //json_print(stdout, json);
    } else {
      printf("Json error!\n");
    }
    clock_t end = clock();
    
    printf("time: %f\n", (double)(end - start) / CLOCKS_PER_SEC);
  }

  return 0;
}

