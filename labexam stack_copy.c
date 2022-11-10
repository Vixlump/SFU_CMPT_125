#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "labexam.h"

int count_hyphens_substrings(const char* str) {
  // implement me
  return -1;
}

int countif(LL_t* list, bool(*pred)(int)) {
  // implement me
  return -1;
}

stack_t* stack_copy(stack_t* orig) {
  // implement me
  stack_t* temp = stack_create();
  int length = 0;
  while(!stack_is_empty(orig)) {
  	stack_push(temp, stack_pop(orig));
  	length++;
  }
  int * store = (int*) malloc(length*sizeof(int));
  stack_t* return_stack = stack_create();
  for (int i = 0; i < length; i++) {
  	store[i] = stack_pop(temp);
  	stack_push(orig, store[i]);
  	stack_push(return_stack, store[i]);
  }
  stack_free(temp);
  free(store);
  return return_stack;
}

