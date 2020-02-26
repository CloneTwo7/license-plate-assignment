#include "plate.h"

void LNR(Node root) {
	if(root->left != NULL) {
		LNR(root->left);
	}
	printf("%s\n",root->plate); 
	if(root->right != NULL) {
		LNR(root->right);
	}

}

void NLR(Node root) {
	printf("%s\n",root->plate);
	if(root->left != NULL) {
		NLR(root->left);
	}
	if(root->right != NULL) {
		NLR(root->right);
	}

}

void LRN(Node root) {
	if(root->left != NULL) {
		LRN(root->left);
	}
	if(root->right != NULL) {
		LRN(root->right);
	}
	printf("%s\n",root->plate);

}
