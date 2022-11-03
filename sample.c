#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "sample.h"


bool contains(const int* a1, int len, const int* a2, int len2) {
  // implement me
  bool is_true;
  for (int i = 0; i < len; i++) {
  	is_true = false;
  	for (int i2 = 0; i2 < len2; i2++) {
  		if (a1[i]==a2[i2]) {
  			is_true = true;
  		}
  	}
  }
  return is_true;
}

 
int last_len(const char* str) {
  // implement me
  char * new_str = (char *) malloc((strlen(str)+1)*sizeof(char));
  strcpy(new_str, str);
  char * parcer;
  parcer = strtok(new_str, " ");
  int length;
  while (parcer != NULL) {
  	length = strlen(parcer);
  	parcer = strtok(NULL, " ");
  }
  free(new_str);
  return length;
}


int BT_sum(const BTnode_t* root) {
  // implement me
  bool lock = true;
  int sum = 0;
  size_t point = &root;
  while(lock) {
  	sum += point->value;
  	if (point==point->right) {
		lock = false;
	}
  	point = &point->right;
  	
  }
  return -1;
}
