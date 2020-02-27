#include "plate.h"

Node delete(Node root, char *plate) {
	//calls search to verify that the node being deleted exists
	char* first, last;	
	if(search(root, plate, first, last) == 0) {
		return(root);
	}
	
	int result = strcmp(root->plate,plate);
	
	//checks to see if root is the node being deleted
	if(result == 0) {
		if(root->left != NULL) {
			Node largest = root->left;
			while(root->right != NULL) {
				largest = largest->right;
			}
		}

	}
	else if(result > 0) {
		root = delete(root->left, plate);
	}
	else {
		root = delete(root->right, plate);
	}

}
