#include "plate.h"

int main() {
	Node root = NULL;
	root = add(root, "zebra", "stephan", "colbert");
	root = add(root, "hello", "donald", "glover");
	root = add(root, "goodbye", "John", "Smith");
	root = add(root, "thisisplate", "Jackie","Brown");
	printf("%s\n", root->left->first);
	int h = height(root);
	printf("%d\n",h);
	char first[200];
	char last[200];
	int i = search(root, "zebra", first, last);
	printf("%d\t%s\t%s", i, first, last);
	
}
