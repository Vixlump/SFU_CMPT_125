#include "assignment4.h"


/* Question 1 */

int queue_size(queue_str_t* q) {//currently only this works so take this code with a grain of salt
  queue_str_t * temp = queue_create();
  unsigned int count = 0;
  while (!queue_is_empty(q)) {
    enqueue(temp, dequeue(q));
    count++;
  }
  while (!queue_is_empty(temp)) {
    enqueue(q, dequeue(temp));
  }
  queue_free(temp);
  return count;
}


bool queue_equal(queue_str_t* q1, queue_str_t* q2) {
  // implement me;
  bool is_equal = true;
  queue_str_t * temp1 = queue_create();
  queue_str_t * temp2 = queue_create();
  unsigned int count1 = 0;
  unsigned int count2 = 0;
  while(!queue_is_empty(q1)) {
    enqueue(temp1, dequeue(q1));
    count1++;
  }
  while(!queue_is_empty(q2)) {
    enqueue(temp2, dequeue(q2));
    count2++;
  }
  if (count1!=count2) {
    is_equal = false;
    goto ending_point;
  }
  char * str1;
  char * str2;
  while(!queue_is_empty(temp1)) {
    str1 = dequeue(temp1);
    str2 = dequeue(temp2);
    if (strcmp(str1, str2)!=0) {
      is_equal = false;
    }
    enqueue(q1, str1);
    enqueue(q2, str2);
  }
  //free(str1);
  //free(str2);
  ending_point:
  queue_free(temp1);
  queue_free(temp2);
  return is_equal;
}

char* queue_str_to_string(queue_str_t* q) {
  // implement me;
  char * str;
  unsigned int length = 0;
  queue_str_t * temp = queue_create();
  while (!queue_is_empty(q)) {
    str = dequeue(q);
    length+=strlen(str);
    enqueue(temp, str);
  }
  char * return_string = (char *) malloc((length+1)*sizeof(char));
  return_string[length] = '\0';
  while (!queue_is_empty(temp)) {
    str = dequeue(temp);
    strcat(return_string, str);
    enqueue(q, str);
  }
  //free(str);
  return return_string;
}


/* Question 2 */

BTnode_t* find(BTnode_t* root, bool (*pred)(int)) {
  // implement me;
  return NULL;
}  


void map(BTnode_t* root, int (*f)(int)) {
  // implement me;
}


int sum_of_leaves(const BTnode_t* root) {
  // implement me;
  return -1;
}


/* Question 3 */

BTnode_t* next_preorder(BTnode_t* node) {
  // implement me;
  return NULL;
}

