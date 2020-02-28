#include "plate.h" 

int main(int argc, char **argv) {
	Node root = NULL;
	root = add(root, "IDK-MAN", "Theresa", "Phan");
	root = add(root, "DRK-DRV", "Bojack", "Horseman");
	root = add(root, "FK-TRMP", "Bernie", "Sanders");
	root = add(root, "NW-TRMP", "Mike", "Bloomberg");
	root = add(root, "XAN-THR", "Rus", "Saranchuk");
	printf("height: %d\n", height(root));
	printf("Balanced: %d\n", balanced(root));
	printf("---------LNR-------\n");
	LNR(root);
	root = delete(root,"NW-TRMP");
	printf("--------====-------\n");
	LNR(root);
}
