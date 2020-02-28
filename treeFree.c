#include "plate.h"

void treeFree(Node root) {
	if(root->left != NULL) {
		treeFree(root->left);
	}
	if(root->right != NULL) {
		treeFree(root->right);
	}
	free(root->plate);
	free(root->first);
	free(root->last);
	free(root);
}
