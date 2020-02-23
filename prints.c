#include "plate.h"

void LNR(Node root) {
	if(root->left != NULL) {
		LNR(root->left);
		printf("%s ", root->plate);
		LNR(root->right);
	}
	else {
		printf("%s ", root->plate);
	}
	

}

void NLR(Node root) {

}

void LRN(Node root) {

}
