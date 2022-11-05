//Submition of Name:Cohen ter Heide ID:301549869

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "assignment1.h"

long count_even(long x, long y) {
  long count = 0; //value to store count
  if (x<y) {
  	for (long i = x; i<=y; i++) {//starting loop at x if x is lower
  		if (i%2==0) {count++;} //check if i / 2 has remainder
  	}
  }
  else if (x>y) {
  	for (long i = y; i<=x; i++) {//starting loop at y if y is lower
  		if (i%2==0) {count++;}
  	}
  }
  else {if (x%2==0) {count++;}}
  return count;
}  



int most_frequent(const int* arr, int n) {
  int most_common = arr[0];//define the most common number
  int number_of = -1;//for tracking the number of instances of the most commmon number
  int topic;//the current number of view
  int count;//for storing the number of the current value
    for (int i = 0; i<n; i++) {//iterate through array values
      if (arr[i]==most_common&&number_of!=-1) {continue;}//skip any number we have already tracked
      topic = arr[i];
      count = 0;
      for (int i2 = 0; i2<n; i2++) {//loop through values of interest and record count
        if (topic==arr[i2]) {
          count++;
        }
      }
      if (count>number_of) {most_common = topic; number_of = count;}//if current tracked number is larger count then stored value, replace with new larger value for return
    }
  return most_common;
}

bool is_odd_palindrome(const char* str) {
  int length = strlen(str);//get length of string now so it wont have to call the function every loop
  if (length%2==0) {//check if imput is of even length
    return false;
  }
  for (int i = 0; i < (length/2)+1; i++) {//loop through half rounding up of all letters in the string
    if (str[i]!=str[length-i-1]) {//if any letter is found to not be matching its counter part at the other end of the string return false
      return false;
    }
  }
  return true;//no problems were found there for it must be true! wooot!
}

int longest_odd_subpalindrome(const char* str) {
  int length = strlen(str);//get length of string now so it does not need to call every loop cycle
  int girth_tracker = 0;//value to store longest odd sub string length
  int x;//x for keeping track of string lengths
  //reform x is to be used to make new char values to pass into is_odd_pallendrome function to check for pallendrome size
  char * reform_x = (char*)malloc((length+1)*sizeof(char));//create initial size for reform_x at the maximum possible string size + 1 for the 0 char so we dont have to realloc ever loop;
  for (int i = 0; i < length; i++) {
        x = 0;
        for (int i2 = i; i2 < length; i2++) {
            reform_x[x++] = str[i2];
            if (x%2==0) {//if length is even don't bother checking for palindrome
              continue;
            }
            reform_x[x] = '\0';//add ending char so universe does not explode
            if (is_odd_palindrome(reform_x)) {//check if is odd palendrome
              if (x>girth_tracker) {//if odd palindrome is largest ever found, record size
                girth_tracker = x;
              }
              if (girth_tracker == length) {//if odd palindrome is largest possible jump to endingpoint
                goto endingpoint;
              }
            }
        }
    }
    endingpoint:
    free(reform_x);//give memory back to computer to prevent leaks
    return girth_tracker;
}


char* str_div_by_digit(const char* num, int digit) {
  int length = strlen(num);//get length of string
  char * result = (char*) malloc(1*sizeof(char));//initial value for resulting char
  result[0] = '\0';//preset ending char to make life easier
  char combiner[3] = {'0','0','\0'};//combiner char for merging tow chars into one
  char remaker[2] = {'0','\0'};//char for converting between asci and numbers;
  int remainder = 0; //int for holding remainder value
  int x = 0; //int for performing math calculations
  for (unsigned int i = 0; i < length; i++) {//loop through numbers in string one after the other
    combiner[0] = '0'+ remainder; combiner[1] = num[i];//get remainder from previous cycle and add new number
    x = atoi(combiner);//convert small number to int
    remainder = x%digit;//compute remainder
    x = x/digit;//computer division
    remaker[0] = '0'+x;//conver x back to string
    if (i!=0){//allocate space for result to hold x
      result = (char*)realloc(result, (i+2)*sizeof(char));//+2 space large then i to hold 'R' and remainder
      strcat(result, remaker);//add divided x value to the result
    }
  }
  combiner[0] = 'R';combiner[1] = '0' + remainder;//add remainder in format to back of string using extra 2 chars allocated in realloc
  strcat(result, combiner); //complete result and submit
  return result;
}
