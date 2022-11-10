#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "sample.h"


#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define MIN(x, y) (((x) < (y)) ? (x) : (y))


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

bool is_leaf(const BTnode_t * node) {
	return (node->left==NULL&&node->right==NULL);
}
bool is_root(const BTnode_t * node) {
	return (node->parent==NULL);
}

int get_size(BTnode_t * root) {
	if (root==NULL) {
		return 0;
	} else {
		return get_size (root->left) + get_size (root->right) +1;
	}
}
int get_depth (BTnode_t * root) {
	if (root==NULL) {
		return -1;
	} else if (is_leaf(root)) {
		return 0;
	} else {
		return MAX(get_depth(root->left), get_depth(root->right))+1;
	}
}
bool is_descendant (BTnode_t * u, BTnode_t * v) {//check if u is a descendant of v
	if(u==v) {
		//something needs to go here I am not sure what though yet
	}
	BTnode_t * p = u;
	while (p!=NULL) {
		if (p==v) return true;
		p = p->parent;
		
	}
	return false;
}
void traverse_tree(BTnode_t* root, int * collect_sum) {//current used in the form of collecting a sum, also using pre order travers
	if (root==NULL) {
		return;
	}
	printf("%d\n", root->value);
	*collect_sum+=root->value;
	traverse_tree(root->left, collect_sum);
	traverse_tree(root->right, collect_sum);
}

int BT_sum(const BTnode_t* root) {
	BTnode_t* temp = create_node(root->value);
	set_left_child(temp, root->left);
	set_right_child(temp, root->right);
	int collect_sum = 0;
  	traverse_tree(temp, &collect_sum);
  	printf("Sum:%d\n",collect_sum);
  	return collect_sum;
}
