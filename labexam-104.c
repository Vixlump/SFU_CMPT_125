#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "labexam.h"



bool is_reverse(const char* str1, const char* str2) {
  // implement me
  unsigned int length = 0;
  length = strlen(str2);
  if (length != strlen(str1)) {
  	return false;
  }
  char * temp = (char *) malloc((length+1)*sizeof(char));
  int j = 0;
  temp[length] = '\0';
  for (int i = length-1; i>=0; i--) {
  	temp[i] = str2[j];
  	j++;
  }
  printf("%s\n",temp);
  if (strcmp(str1, temp)==0) {
  	free(temp);
  	return true;	
  }
  free(temp);
  return false;
}


LL_t* array_to_LL(int* ar, int n) {
  // implement me
  LL_t * return_ll = LL_create();
  for (int i = 0; i < n; i++) {
  	LL_add_to_tail(return_ll, ar[i]);
  }
  return return_ll;
}


int stack_forget(stack_t* s, int k) {
  // implement me
  int removed_elements = 0;
  int length = 0;
  stack_t * temp = stack_create();
  while (!stack_is_empty(s)) {
  	length++;
  	stack_push(temp, stack_pop(s));
  	//printf("%d\n",stack_pop(s));
  }
  for (int i = 0; i < length; i++) {
  	if (i>=k){
  		stack_push(s, stack_pop(temp));
  	} else {
  		stack_pop(temp);
  	}
  }
  stack_free(temp);
  return removed_elements;
}



