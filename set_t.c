#include "set_t.h"

set_t* set_create_empty() {
  set_t * new_empty = (set_t*) malloc(sizeof(set_t));//create a global instance of set_t
  new_empty->length = 0;//define the default length
  return new_empty;//passback to user
}

int set_size(set_t* A) {
  return A->length;//return length
}

void set_insert(set_t* A, int x) {
  for (unsigned int i = 0; i < A->length; i++) {
    if (A->value[i]==x) {
      return;//do not add to set if already exists in set
    }
  }
  A->value[A->length] = x;//otherwise add
  A->length +=1;
}

void set_remove(set_t* A, int x) {
  for (unsigned int i = 0; i < A->length; i++) {
    if (A->value[i]==x) {//find position of value to remove
      for (unsigned int i2 = i; i2 < A->length; i2++) {
        A->value[i2] = A->value[i2+1];//reposition existing values
      }
      A->length-=1;
      break;//break for processing
    }
  }
}

bool set_contains(set_t* A, int x) {
  for (unsigned int i = 0; i < A->length; i++) {
    if (A->value[i]==x) {//if value found return true
      return true;
    }
  }
  return false;//else return false
}

int set_map(set_t* A, int (*f)(int)) {
  set_t * temp = set_create_empty();//create temporary set_t for processing
  temp->length = A->length;//copy length
  for (unsigned int j = 0; j < A->length; j++) {
    temp->value[j] = f(A->value[j]);//apply changes but copy them to new temporary set_t
  }
  A->length = 0;
  for (unsigned int i = 0; i < temp->length; i++) {//copy back to original
    if (set_contains(A, temp->value[i])) {//if there is a double skip re adding
      continue;
    } else {
      A->value[A->length] = temp->value[i];
      A->length+=1;
    }
  }
  free(temp);//free temp
  return A->length;//return new length
}

void set_free(set_t* A) {
  free(A);//free A
}
