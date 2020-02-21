#include "plate.h"

Node add(Node root, char *plate, char *first, char *last) {
	if(root == NULL) {
		root = malloc(sizeof(struct node));
		root -> plate = plate;
		root -> first = first;
		root -> last = last;
		root -> left = NULL;
		root -> right = NULL;
		return;
	}
	else {
		if( strcmp(plate, root->plate) < 0 ) {
			add(root->left, plate, first, last);
		}
		else if (strcmp(plate, root->plate) > 0) {
			add(root->right, plate, first, last);
		}
	}
	return(root);
}
