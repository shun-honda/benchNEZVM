#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <sys/time.h> // gettimeofday

#ifndef LIBNEZ_H
#define LIBNEZ_H

struct ParsingContext {
  char *inputs;
  char *cur;
  size_t input_size;
  long pos;

  long bytecode_length;
  long startPoint;

  // long *stack_pointer;
  // struct NezVMInstruction **call_stack_pointer;
  // long *stack_pointer_base;
  // struct NezVMInstruction **call_stack_pointer_base;
};

typedef struct ParsingContext *ParsingContext;

int level;
static void dump_func(const char* name) {
  level++;
  for(int i = 0; i < level; i++) {
    fprintf(stderr, "  ");
  }
  fprintf(stderr, "%s:%d\n", name, level);
}

static void dec() {
  level--;
}

static uint64_t timer() {
  struct timeval tv;
  gettimeofday(&tv, NULL);
  return tv.tv_sec * 1000 + tv.tv_usec / 1000;
}

void nez_consume(ParsingContext ctx);
void nez_backtrack(ParsingContext ctx, long pos);
int nez_match(ParsingContext ctx, char c);
int nez_not_match(ParsingContext ctx, char c);

#define PARSING_CONTEXT_MAX_STACK_LENGTH 1024
ParsingContext nez_CreateParsingContext(const char *filename);
void nez_DisposeParsingContext(ParsingContext ctx);

void nez_PrintErrorInfo(const char *errmsg);

#endif
