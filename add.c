#include "plate.h"

Node add(Node root, char *plate, char *first, char *last) {
	if(root == NULL) {
		root = malloc(sizeof(struct node));
		root -> plate = plate;
		root -> first = first;
		root -> last = last;
		root -> left = NULL;
		root -> right = NULL;
	}
	else if(strcmp(root->plate, plate) > 0) {
		Node new = add(root->left, plate, first, last);
		root -> left = new;
	}
	else if(strcmp(root->plate, plate) < 0) {
		Node new = add(root->right, plate, first, last);
		root -> right = new;
	}
	return(root);
}
