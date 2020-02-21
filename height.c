#include "plate.h"

int height(Node root) {
	if(root == NULL) {
		return(-1);
	}

	int r = height(root->right);
	int l = height(root->left);

	if( l > r ) {
		return(l+1);
	}
	else {
		return(r+1);
	}
	
}
