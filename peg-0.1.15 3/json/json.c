#include "json.h"

//JSON *json_parser(FILE *fp) {
//	extern FILE *yyin;
//	extern JSONValue *json;
//
//	yyin = fp;
//
//	if (yyparse()) {
//		return NULL;
//	}
//
//	return json;
//}

JSON *json_new_value() {
	JSON *value = (JSON *)malloc(sizeof(JSON));
	return value;
}

JSON *json_new_integer(int i) {
	JSON *value = json_new_value();

	value->type    = JSON_VALUE_TYPE_INTEGER;
	value->i_value = i;

	return value;
}

JSON *json_new_double(double d) {
	JSON *value = json_new_value();

	value->type    = JSON_VALUE_TYPE_DOUBLE;
	value->d_value = d;

	return value;
}

JSON *json_new_string(char *str) {
	return json_new_nstring(str, strlen(str));
}

JSON *json_new_nstring(char *str, int size) {
	JSON *value = json_new_value();

	value->type    = JSON_VALUE_TYPE_STRING;
	value->s_value = (char *)malloc(size + 1);
	strncpy(value->s_value, str, size);
	value->s_value[size] = '\0';

	return value;
}

JSON *json_new_object_value(JSON *object) {
	JSON *value;

	if (!object) {
		return NULL;
	}

	value = json_new_value();
	value->type    = JSON_VALUE_TYPE_OBJECT;
	value->o_value = object;

	return value;
}

JSON *json_new_array_value(JSON *array) {
	JSON *value;

	if (!array) {
		return NULL;
	}
	value = json_new_value();
	value->type    = JSON_VALUE_TYPE_ARRAY;
	value->a_value = array;

	return value;
}

JSON *json_new_true() {
	JSON *value = json_new_value();

	value->type    = JSON_VALUE_TYPE_TRUE;

	return value;
}

JSON *json_new_false() {
	JSON *value = json_new_value();

	value->type    = JSON_VALUE_TYPE_FALSE;

	return value;
}

JSON *json_new_null() {
	JSON *value = json_new_value();

	value->type    = JSON_VALUE_TYPE_NULL;

	return value;
}

void json_free_value(JSON *value) {
	if (!value) {
		return;
	}

	if (value->type == JSON_VALUE_TYPE_STRING) {
		free(value->s_value);
	} else if (value->type == JSON_VALUE_TYPE_OBJECT) {
		json_free_object(value->o_value);
	} else if (value->type == JSON_VALUE_TYPE_ARRAY) {
		json_free_array(value->a_value);
	}

	free(value);
}

void json_print_value(FILE *fp, JSON *value, int depth) {

	switch (value->type) {
		case JSON_VALUE_TYPE_INTEGER:
			fprintf(fp, "%d", value->i_value);
			break;
		case JSON_VALUE_TYPE_DOUBLE:
			fprintf(fp, "%f", value->d_value);
			break;
		case JSON_VALUE_TYPE_STRING:
			fprintf(fp, "\"%s\"", value->s_value);
			break;
		case JSON_VALUE_TYPE_OBJECT:
			json_print_object(fp, value->o_value, depth );
			break;
		case JSON_VALUE_TYPE_ARRAY:
			json_print_array(fp, value->a_value, depth);
			break;
		case JSON_VALUE_TYPE_TRUE:
			fprintf(fp, "true");
			break;
		case JSON_VALUE_TYPE_FALSE:
			fprintf(fp, "false");
			break;
		case JSON_VALUE_TYPE_NULL:
			fprintf(fp, "null");
			break;
	}
}

JSON *json_new_element(JSON *value) {
	JSON *element = (JSON *)malloc(sizeof(JSON));

	element->value = value;
	element->next  = NULL;

	return element;
}

void json_free_element(JSON *element) {
	if (!element) {
		return;
	}

	json_free_element(element->next);
	free(element);
}

JSON *json_add_element(JSON *element, JSON *value) {
	JSON *e;

	if (!element) {
		return json_new_element(value);
	}

	for (e = element; e->next; e = e->next) {}
	e->next = json_new_element(value);

	return element;
}

void json_print_element(FILE *fp, JSON *element, int depth) {
	for (; element; element = element->next) {
		json_print_indent(fp, depth); json_print_value(fp, element->value, depth);
		if (element->next) {
			fprintf(fp, ", ");
		}
		fprintf(fp, "\n");
	}
}

JSON *json_new_array(JSON *element) {
	JSON *array = (JSON *)malloc(sizeof(JSON));

	array->child = element;

	return array;
}

void json_free_array(JSON *array) {
	if (!array) {
		return;
	}

	json_free_element(array->child);
	free(array);
}

void json_print_array(FILE *fp, JSON *array, int depth) {
	json_print_indent(fp, depth); fprintf(fp, "[\n");
	json_print_element(fp, array->child, depth + 1);
	json_print_indent(fp, depth); fprintf(fp, "]");
}

JSON *json_new_member(JSON *key, JSON *value) {
	JSON *member = (JSON *)malloc(sizeof(JSON));

	member->key   = key;
	member->value = value;
	member->next  = NULL;

	return member;
}

void json_free_member(JSON *member) {
	if (!member) {
		return;
	}

	json_free_member(member->next);
	json_free_value(member->key);
	json_free_value(member->value);
	free(member);
}

//JSONMember *json_value_add_member(JSONMember *member, JSONValue *key, JSONValue *value) {
//	return json_member_add_member(member, json_new_member(key, value));
//}

JSON *json_add_member(JSON *member, JSON *value) {
	JSON *m;

	if (!member) {
		return value;
	}

	for (m = member; m->next; m = m->next) {}
	m->next = value;

	return member;
}

void json_print_member(FILE *fp, JSON *member,int depth) {
	for (; member; member = member->next) {
		json_print_indent(fp, depth);
		json_print_value(fp, member->key, depth);
		fprintf(fp, " : ");
		json_print_value(fp, member->value, depth);
		if (member->next) {
			fprintf(fp, ", ");
		}
		fprintf(fp, "\n");
	}
}

JSON *json_new_object(JSON *member) {
	JSON *object = (JSON *)malloc(sizeof(JSON));

	object->child = member;

	return object;
}

void json_free_object(JSON *object) {
	if (!object) {
		return;
	}

	json_free_member(object->child);
	free(object);
}

void json_print_object(FILE *fp, JSON *object, int depth) {
	json_print_indent(fp, depth); fprintf(fp, "{\n");
	json_print_member(fp, object->child, depth + 1);
	json_print_indent(fp, depth); fprintf(fp, "}");
}

//JSONValue *json_value_at_index(JSON *value, int index) {
//	JSONElement *e;
//
//	if (value->type != JSON_VALUE_TYPE_ARRAY) {
//		return NULL;
//	}
//
//	for (e = value->a_value->elements; index && e; index--, e = e->next) {}
//
//	if (!e) {
//		return NULL;
//	}
//
//	return e->value;
//}
//
//JSONValue *json_value_at_key(JSONValue *value, char *key) {
//	JSONMember *m;
//
//	if (!value || value->type != JSON_VALUE_TYPE_OBJECT) {
//		return NULL;
//	}
//
//	for (m = value->o_value->members; m; m = m->next) {
//		assert(m->key->type == JSON_VALUE_TYPE_STRING);
//		if (strcmp(m->key->s_value, key) == 0) {
//			return m->value;
//		}
//	}
//
//	return NULL;
//}
//
//MyString *get_ustring(char *p) {
//	MyString *str = new_string();
//	char c;
//
//	for (; (c = *p); p++) {
//		switch (c) {
//			case '\\': my_chrcat(str, '\\'); c = '\\'; break;
//			case '/':  my_chrcat(str, '\\'); c = '/'; break;
//			case '"':  my_chrcat(str, '\\'); c = '"'; break;
//			case '\b': my_chrcat(str, '\\'); c = 'b'; break;
//			case '\n': my_chrcat(str, '\\'); c = 'n'; break;
//			case '\r': my_chrcat(str, '\\'); c = 'r'; break;
//			case '\t': my_chrcat(str, '\\'); c = 't'; break;
//			case '\f': my_chrcat(str, '\\'); c = 'f'; break;
//		}
//		my_chrcat(str, c);
//	}
//
//	return str;
//}
//
//unichar unicode2utf8(unichar uc) {
//	return 
//		(0xe0 | ((uc >> 12) & 0x0f)) << 16 |
//		(0x80 | ((uc >>  6) & 0x3f)) << 8  |
//		(0x80 | (uc & 0x3f));
//}

void json_print(FILE *fp, JSON *value) {
	json_print_value(fp, value, 0);
	fprintf(fp, "\n");
}

void json_print_indent(FILE *fp, int depth) {
	int i;

	for (i = 0; i < depth; i++) {
		fprintf(fp, JSON_INDENT_STR);
	}
}
