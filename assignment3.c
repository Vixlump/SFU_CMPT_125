#include "assignment3.h"


int compare_strings(const void *input1, const void *input2) { 
    const char **temp1 = (const char **)input1;//cast const voids to something more useable
    const char **temp2 = (const char **)input2;
    int diff = strlen(*temp1)-strlen(*temp2);//compute difference
    if (!diff) {//if no differenece return asci string compair
      return strcmp(*temp1, *temp2);
    } else {//otherwise return the difference in length
      return diff;
    }
}

void sort_strings(const char* A[], int n) {
  qsort(A, n, sizeof(char*), compare_strings);//implimentation of qsort using compate_strings function
}  

int* insertion_sort(int* array, int n) {
  int current;//int to hold what we are looking at
  unsigned int operations;//int to count total shifts done on any given value
  int * returned_array = (int *) malloc(n*sizeof(int));//define array to return
  if (n>0) returned_array[0] = 0;//ensure require size for sorting is met
  for (unsigned int i=1; i < n; i++) {
    current = array[i];//set current to array[i]
    operations = 0;//reset operations
    int i2;//define i2 outside of for loop so it can be used after for loop is concluded
    for (i2 = i-1;current<array[i2] && i2>=0; i2--) {//if i2 is greater then or equal zero determain using current if it is needed to move value or simply append it
      array[i2+1]=array[i2];//move value
      operations++;//keep track of times value was moved
    }
    array[i2+1] = current;//apply changes
    returned_array[i] = operations;//store operations made on value
  }
  return returned_array;//return list of changes to values
}


int find(int* A, int n, bool (*pred)(int)) {
  for (unsigned int i = 0; i<n; i++) {
    if (pred(A[i])) {//loop through values applying pred to each and determining if they are true
      return i;//if true return the position
    }
  }
  return -1;//otherwise return -1
}


int count(int* A, int n, bool (*pred)(int)) {
  unsigned int tracker = 0;//value to store number of
  for (unsigned int i = 0; i<n; i++) {
    if (pred(A[i])) {//for each value of pred==true add one to tracker
      tracker++;
    }
  }
  return tracker;//return tracker
}


void map(int* A, int n, int (*f)(int)) {
  for (unsigned int i = 0; i<n; i++) {
    A[i] = f(A[i]);//for all values apply f
  }
}


int reduce(int* A, int n, int (*f)(int,int)) {
  int accumulator = A[0];//set accumulator to initial value
  for (unsigned int i = 1; i<n; i++) {//for every value after initial apply f (whatever that may be)
    accumulator = f(accumulator, A[i]);
  }
  return accumulator;//then return when done
}
