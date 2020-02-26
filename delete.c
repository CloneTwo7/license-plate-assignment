#include "plate.h"

Node delete(Node root, char *plate) {
	//calls search to verify that the node being deleted exists
	char* first, last;	
	if(search(root, plate, first, last) == 0) {
		return(root);
	}
	Node prev = root;

	//checks to see if the current node is the node being deleted
	if( ((strcmp(root->plate, plate)) == 0)) {
		//if the root node of the tree is the function is the plate being deleted
		//and there are no other nodes on the left of the root node
		//then it sets the node to the right of the root to be the new root node
		//and frees the old root's memory
		if(root -> left == NULL) { 
			//creates new poniter for old root
			Node oldRoot = root;
			//sets old root equal to the node to the right of the original root
			root = root -> right;
			//free oldRoot
			free(oldRoot);
			//returns new root 
			return(root);
		}
		else if(

		} 
	}
}
