#include "plate.h"

int main() {
	Node root = NULL;
	char file[200] = "testdata.txt";
	getData(root, file);
	printf("%s\n", root->left->first);
	int h = height(root);
	printf("%d\n",h);
	char first[200];
	char last[200];
	int i = search(root, "R2D-3P0", first, last);
	printf("%d\n", i);
	
}
