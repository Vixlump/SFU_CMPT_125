
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "assignment2.h"

//basic one way long strings tokenization (make a string into a unique number to be more usefull and secure)
const unsigned long UIRN(char const *s, unsigned int count) {//basic long hash function for producing a unique identifying random number from a string input
  //if count is true
  //then call resurion of function with the same input but with the count reduced by one
  //xor return the value of the symbol of s in position count-1 multiplied by a constant value
  //otherwise return a different constant value
  //thus for every value of an asci value passed into the function determine a unique number to return based on the strings input
  return count ? (UIRN(s, count - 1) ^ s[count - 1]) * 16777619ul : 2166136261ul;
}
//macro for simplifying UIRN hash function to one input
#define CRYPT(X) UIRN(X, strlen(X))

//make my "endless" loops more stylish
#define loop_for_ever while(true)

const char delimit[2] = ";";//change for custom text formatting between username and password

int check_user_password(const char* file_name, const char* username, const char* password) {
  // implement me
  FILE * read_file = fopen(file_name, "r");
  if (!read_file) {//check if file exists
    return -1;//file not found return -1
  }
  char * spliter;//value to point to username and password when parced from line
  char line[43];//value to hold line read from file, 40 digits for max length of 2 unsigned longs + 1 for delimiter + 2 for '\n' and'\0' chars
  while (fgets(line, sizeof(line), read_file)) {//read directed file
    spliter = strtok(line, delimit);//split file along delimiter of ';'
    //strtoul converts string to unsigned long using char * input, and ending char (NULL) and a base unit (10)
    if (strtoul(spliter, NULL, 10)==CRYPT(username)) {//check if ulong encrypted username matches stored encrypted username
      while (spliter != NULL) {//make sure password exists
        spliter = strtok(NULL, delimit);//point to password in place of username
        spliter[strcspn(spliter, "\n")] = '\0';//strip \n from ending of encrypted password by replacing with \0 char
        if (strtoul(spliter, NULL, 10)==CRYPT(password)) {//match encrypted password to stored password
          fclose(read_file);
          return 1;//return found both
        }
        break;
      }
      fclose(read_file);
      return -3;//return found username but not password
    }
  }
  fclose(read_file);
  return -2;//return not found username
}



int add_user_password(const char* file_name, const char* username, const char* password) {
  // implement me
  FILE * output_to_file = fopen(file_name, "a");
  switch (check_user_password(file_name, username, password)) {//check current state of user in file
    case 1:
    case -3://if the users is already in the file the function does not modify the file and returns 0.
      fclose(output_to_file);//correction added file closers
      return 0;
    case -1://if the file does not exist the function creates a new with the given name adds the pair to the file and return 1.
    case -2://if the user is not in the file the function adds the pair to the file and returns 1.
      //correction moved FILE * output_to_file = fopen(file_name, "a") outside of case
      fprintf(output_to_file, "%lu%s%lu\n", CRYPT(username), delimit, CRYPT(password));//CRYPT is there to ensure minimum string length and password security converting string to unique unsigned long int
      fclose(output_to_file);
      return 1;
    default:
      break;
  }
  fclose(output_to_file);//corection added files closers
  return 0;
}


int fib3_p(unsigned int n, unsigned int p) {
  // implement me
  if (n<3) {
    return n;//check if n is less then 3 and if it is just output n
  } else {
    int * return_fib3 = (int *) malloc((n+1)*sizeof(int));//allocate space for calculating sequence
    int passback_number;//local value to return result
    return_fib3[0] = 0; return_fib3[1] = 1; return_fib3[2] = 2;//define known awnsers
    for (unsigned int i = 3; i <=n; i++) {//while i is less then n perform math sequence and fill allocated spaces
      return_fib3[i] = (return_fib3[i-1] + return_fib3[i-2] + return_fib3[i-3])%p;//non recursive solution to fib3_p(n-1)+fib3_p(n-2)+fib3_p(n-3)%p
    }
    passback_number = return_fib3[n];//return final allocated space as result
    free(return_fib3);//free allocated memory
    return passback_number;
  }

  return -1;//this should never be called but I keep it around to not make the compiler freak out
}

char* evolve(const char* state) {
  size_t state_len = strlen(state);
  char * next_state = (char*) malloc((state_len+1)*sizeof(char));//allocate space for evolution calculation
  //values to hold position to neerest pebbles
  int neighbor_left;
  int neighbor_right;
  next_state[state_len] = '\0';//prevent segfaults
  memset(next_state, '-', state_len);//set next evolution of board to blank in order to be filled with pebbles
  // implement me
  for (int i = 0; i<state_len; i++) {
    neighbor_left = 0; neighbor_right = 0;//reset trackers
    if (state[i]=='@') {//detect if position has a pebble
      //find location of neighboring pebbles (and if the exist):
        for (int i_left = i-1; i_left >= 0; i_left--) {//look left
          if (state[i_left]=='@') {
            neighbor_left = i - i_left;
            break;
          }
        }
        for (int i_right = i+1; i_right < state_len; i_right++) {//look right
          if (state[i_right]=='@') {
            neighbor_right = i_right - i;
            break;
          }
        }
      //do something with the info about neighbors by enforcing the game rules:
        if (neighbor_left==0&&neighbor_right==0) {//rule G
          next_state[i] = state[i];
          break;
        } else if (neighbor_left==neighbor_right) {//rule B
          continue;//continue is used for optimizing the if statements
        } else if ((neighbor_left!=0&&neighbor_left<neighbor_right)||neighbor_right==0) {//rule D & A
          if (next_state[i-1]!='@') {//rule E protection
            next_state[i-1] = '@';
          } else {
            next_state[i-1] = '-';
          }
          continue;
        } else if ((neighbor_right!=0&&neighbor_left>neighbor_right)||neighbor_left==0) {//rule C & A
          if (next_state[i+1]!='@') {//rule E protection
            next_state[i+1] = '@';
          } else {
            next_state[i+1] = '-';
          }
          continue;
        } else {
          printf("this should never be printed\n");
        }
    }
  }
  //printf("Original: %s NextState: %s\n",state, next_state);//debugging line
  return next_state;
}  

char* last_state(const char* state) {
  // implement me
  size_t state_len = strlen(state);
  char * past_state = (char *) malloc((state_len+1)*sizeof(char));//allocate space to track the previous state
  char * current_state = (char *) malloc((state_len+1)*sizeof(char));//allocate space to track the current state
  strcpy(current_state, state);
  loop_for_ever {//loop until conditions are met for game to end
    strcpy(past_state, current_state);//back up current state before evolition
    current_state = evolve(current_state);//evolve state to next frame
    //printf("%s\n",current_state);
    if (strcmp(past_state, current_state)==0) {//end game if past state ever matches current state
      break;
    }
  }
  free(past_state);
  return current_state;//return final state
}  
  
