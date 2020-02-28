#include "plate.h"

int search(Node root, char *plate, char *first, char *last) {
	//first check to see node is NULL
	//if it's null that means it's reached the end of the list and the plate doesn't exist
	if(root == NULL) {
		return(0);
	}

	//if current root's plate is equal to the plate passed to it,
	//then it loads the first and last values with the values in this node
	else if((strcmp(root->plate,plate)) == 0) {
		first = malloc(strlen(root->first)+1);
		last = malloc(strlen(root->last)+1);
		strcpy(first,root->first);
		strcpy(last,root->last);
		return(1);
	}

	//if it's not null and not equal to the plate passed to it,
	//figures out whether the plate should be to the left or right
	else if((strcmp(root->plate, plate)) > 0) {
		search(root->left, plate, first, last);
		
	}
	else {
		search(root->right, plate, first, last);
	}
}
