#include "libnez.h"
#include <stdio.h>

void nez_PrintErrorInfo(const char *errmsg) {
  fprintf(stderr, "%s\n", errmsg);
  exit(EXIT_FAILURE);
}

void nez_consume(ParsingContext ctx) {
  if(ctx->pos < ctx->input_size) {
    if(ctx->inputs[ctx->pos] != 0) {
      ctx->pos++;
    }
  }
  else {
    nez_PrintErrorInfo("input over flow");
  }
}

void nez_backtrack(ParsingContext ctx, long pos) {
  if(pos != ctx->pos) {
    if(pos < ctx->input_size) {
      if(pos > ctx->pos) {
        nez_PrintErrorInfo("backtrack error");
      }
      ctx->pos = pos;
    }
    else {
      fprintf(stderr, "%ld, %ld, %ld\n", ctx->pos, ctx->input_size, pos);
      nez_PrintErrorInfo("backtrack error");
    }
  }
}

char *loadFile(const char *filename, size_t *length) {
  size_t len = 0;
  FILE *fp = fopen(filename, "rb");
  char *source;
  if (!fp) {
    nez_PrintErrorInfo("fopen error: cannot open file");
    return NULL;
  }
  fseek(fp, 0, SEEK_END);
  len = (size_t)ftell(fp);
  fseek(fp, 0, SEEK_SET);
  source = (char *)malloc(len + 1);
  if (len != fread(source, 1, len, fp)) {
    nez_PrintErrorInfo("fread error: cannot read file collectly");
  }
  source[len] = '\0';
  fclose(fp);
  *length = len;
  return source;
}

ParsingContext nez_CreateParsingContext(const char *filename) {
  ParsingContext ctx = (ParsingContext)malloc(sizeof(struct ParsingContext));
  ctx->pos = ctx->input_size = 0;
  // ctx->startPoint = 1;
  // ctx->mpool = (MemoryPool)malloc(sizeof(struct MemoryPool));
  ctx->inputs = loadFile(filename, &ctx->input_size);
  ctx->cur = ctx->inputs;
  // ctx->stack_pointer_base =
  //     (StackEntry)malloc(sizeof(union StackEntry) * PARSING_CONTEXT_MAX_STACK_LENGTH);
  // ctx->stack_pointer = &ctx->stack_pointer_base[0];
  // ctx->stack_pointer_base =
  //     (long *)malloc(sizeof(long) * PARSING_CONTEXT_MAX_STACK_LENGTH);
  // ctx->call_stack_pointer_base = (NezVMInstruction **)malloc(
  //     sizeof(NezVMInstruction *) * PARSING_CONTEXT_MAX_STACK_LENGTH);
  // ctx->stack_pointer = &ctx->stack_pointer_base[0];
  // ctx->call_stack_pointer = &ctx->call_stack_pointer_base[0];
  return ctx;
}

void nez_DisposeParsingContext(ParsingContext ctx) {
  free(ctx->inputs);
  // free(ctx->call_stack_pointer_base);
  free(ctx);
}
