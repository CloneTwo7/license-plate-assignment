#include "plate.h"

int height(Node root) {
	//checks to see if current node is null
	if(root == NULL) {
		//returns -1 if null
		return(-1);
	}
	//finds heights or right and left
	int r = height(root->right);
	int l = height(root->left);
	//returns the greater height
	if( l > r ) {
		return(l+1);
	}
	else {
		return(r+1);
	}
}
