#include "plate.h"

Node add(Node root, char *plate, char *first, char *last) {
	//if root is null, then it is an uninitialized segment of the tree
	//in this case, the plate that is being added will be added to the new spot
	if(root == NULL) {
		root = malloc(sizeof(struct node));
		root -> plate = malloc(strlen(plate+1));
		strcpy(root->plate, plate);
		root -> first = malloc(strlen(first+1));
		strcpy(root->first, first);
		root -> last = malloc(strlen(last+1));
		strcpy(root->last, last);
		root -> left = NULL;
		root -> right = NULL;
	}
	//If the root is not null, then it traverses the tree to the spot the entry should go in
	//if it's greater than the root, places it to the left of the root
	else if(strcmp(root->plate, plate) > 0) {
		root -> left = add(root->left, plate, first, last);
	}
	//If it's less than the root, places it to the right of the root
	else if(strcmp(root->plate, plate) < 0) {
		root -> right = add(root->right, plate, first, last);
	}
	return(root);
}
