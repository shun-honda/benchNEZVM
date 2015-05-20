#ifndef __JSON_H__
#define __JSON_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include "MyString.h"

enum {
	JSON_VALUE_TYPE_INTEGER = 0,
	JSON_VALUE_TYPE_DOUBLE,
	JSON_VALUE_TYPE_STRING,
	JSON_VALUE_TYPE_OBJECT,
	JSON_VALUE_TYPE_ARRAY,
	JSON_VALUE_TYPE_TRUE,
	JSON_VALUE_TYPE_FALSE,
	JSON_VALUE_TYPE_NULL,
	ALL_JSON_VALUE_TYPE_NUM,
};

#define JSON_VALUE_NAME_INTEGER "Integer"
#define JSON_VALUE_NAME_DOUBLE  "Double"
#define JSON_VALUE_NAME_String  "String"
#define JSON_VALUE_NAME_Object  "Object"
#define JSON_VALUE_NAME_Array   "Array"
#define JSON_VALUE_NAME_TRUE    "true"
#define JSON_VALUE_NAME_FALSE   "false"
#define JSON_VALUE_NAME_NULL    "null"

#define JSON_TOKEN_EOF     (-1)
#define JSON_TOKEN_ERROR   (0)
#define JSON_TOKEN_LC      '{'
#define JSON_TOKEN_RC      '}'
#define JSON_TOKEN_COMMA   ','
#define JSON_TOKEN_COLON   ':'
#define JSON_TOKEN_LB      '['
#define JSON_TOKEN_RB      ']'
#define JSON_TOKEN_VALUE   'v'

#define IS_HEX_CHAR(c)     (isdigit(c) || (('a' <= c && 'f' >= c) || ('A' <= c && 'F' >= c)))
#define HEX_CHAR2INT(c)    (isdigit(c) ? c - '0' : ('a' <= c && 'f' >= c) || ('A' <= c && 'F' >= c) ? tolower(c) - 'a' + 10 : -1)

/* Debug */
#define JSON_DEBUG_MODE         0
#define JSON_DEBUG_OUT          stderr
#if JSON_DEBUG_MODE
#define JSON_DEBUG(str)    fprintf(JSON_DEBUG_OUT, "%s(%d) : " str "\n", __FILE__, __LINE__)
#else
#define JSON_DEBUG(str)    
#endif
#define JSON_INDENT_STR        "  "

/*static char json_value_name[ALL_JSON_VALUE_TYPE_NUM][8] = {
  JSON_VALUE_NAME_INTEGER,
  JSON_VALUE_NAME_DOUBLE,
  JSON_VALUE_NAME_String,
  JSON_VALUE_NAME_Object,
  JSON_VALUE_NAME_Array,
  JSON_VALUE_NAME_TRUE,
  JSON_VALUE_NAME_FALSE,
  JSON_VALUE_NAME_NULL,
  };*/

typedef struct JSONObject JSONObject;
typedef struct JSONMember JSONMember;
typedef struct JSONArray JSONArray;
typedef struct JSONElement JSONElement;
typedef struct JSONValue JSONValue;
typedef struct JSON JSON;
typedef struct JSONToken JSONToken;

struct JSON {
  int type;
  JSON *key;
  JSON *value;
  JSON *child;
  JSON *next;
	union {
		int        i_value;
		double     d_value;
		char       *s_value;
		JSON *o_value;
		JSON  *a_value;
	};
};

struct JSONObject {
	JSONMember *members;
};

struct JSONMember {
	JSONValue *key;
	JSONValue *value;
	JSONMember *next;
};

struct JSONArray {
	JSONElement *elements;
};

struct JSONElement {
	JSONValue *value;
	JSONElement *next;
};

struct JSONValue {
	int type;
	union {
		int        i_value;
		double     d_value;
		char       *s_value;
		JSON *o_value;
		JSON  *a_value;
	};
};

struct JSONToken {
	char *str;
	char *next;
	int  token;
	JSON *value;
};

//JSONJSON *json_parser(FILE *fp);
//int yylex();
//int yyparse();

JSON *json_new_value();
JSON *json_new_integer(int i);
JSON *json_new_double(double d);
JSON *json_new_string(char *str);
JSON *json_new_nstring(char *str, int size);
JSON *json_new_object_value(JSON *object);
JSON *json_new_array_value(JSON *array);
JSON *json_new_true();
JSON *json_new_false();
JSON *json_new_null();
void json_free_value(JSON *value);
void json_print_value(FILE *fp, JSON *value, int depth);

JSON *json_new_element(JSON *value);
void json_free_element(JSON *element);
JSON *json_add_element(JSON *element, JSON *value);
void json_print_element(FILE *fp, JSON *element, int depth);

JSON *json_new_array(JSON *element);
void json_free_array(JSON *array);
void json_print_array(FILE *fp, JSON *array, int depth);

JSON *json_new_member(JSON *key, JSON *value);
void json_free_member(JSON *member);
//JSON *json_value_add_member(JSON *member, JSON *key, JSON *value);
JSON *json_add_member(JSON *member, JSON *value);
void json_print_member(FILE *fp, JSON *member,int depth);

JSON *json_new_object(JSON *member);
void json_free_object(JSON *object);
void json_print_object(FILE *fp, JSON *object, int depth);

void json_print(FILE *fp, JSON *value);
void json_print_indent(FILE *fp, int depth);

#endif

