#include "plate.h"

Node delete(Node root, char *plate) {
/*	first thing this function does, is search the BST
	to verify that it does exist
*/
	char* first;
	char *last;	
	if(search(root, plate, first, last) == 0) {
		return(root);
	}
/*	result variable holds a value that determines whether the current
	node is the node being deleted, is greater value than the node being 
	deleted, or is less value than the node being deleted
*/
	int result = strcmp(root->plate,plate);
/*	if result == 0 then the result has been found.
	The function then determines what the surrounding
	tree looks like and determines how to delete the root
	based off of the surrounding information.

	Otherwise it will recursively call delete based off of the result.
	result > 0 will traverse to the left
	result < 0 will traverse to the right
*/
	if(result == 0) {
/*	if both the right and left subtrees are not null,
	the function will begin delteing here based off
	several edge cases
*/
		if((root->left != NULL)&&(root->right != NULL)) {
	/*	step 1 includes finding the largest node to the left of
		the node being deleted
	*/
			Node prev = root;
			Node largest = root->left;
			while(largest->right != NULL) { 
			//loop to find largest node
				prev = largest;
				largest = largest->right;
			}
				largest -> right = root -> right;
				if(prev != root) {
					prev -> right = largest -> left;
					largest -> left = root -> left;
				}
				free(root);
				return(largest);
		}
		else if(root->left == NULL && root->right != NULL) {
			Node new = root->right;
			free(root);
			return(new);
		}
		else {
			free(root);
			root = NULL;
			return(root);
		}
	}
	else if(result > 0) {//traverse to the left
		root->left = delete(root->left, plate);
	}
	else if(result < 0) { //traverse to the right
		root->right = delete(root->right, plate);
	}
}
