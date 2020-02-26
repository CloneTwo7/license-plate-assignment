#include "plate.h" 

int main() {
	Node root = NULL;
	root = add(root, "R2D-3P0", "Travis", "Peterson");
	root = add(root, "HELP-M3", "Jon", "Snow");
	root = add(root, "DND-HLP", "Nott", "Brave");
	root = add(root, "IDK-MAN", "Theresa", "Phan");
	root = add(root, "DRK-DRV", "Bojack", "Horseman");
	root = add(root, "FK-TRMP", "Bernie", "Sanders");
	root = add(root, "NW-TRMP", "Mike", "Bloomberg");
	root = add(root, "LOV-MNY", "Jeff", "Bezos");
	root = add(root, "HRY-QTM", "Todd", "Chavez");
	printf("height: %d\n", height(root));
	printf("Balanced: %d\n", balanced(root));
	LNR(root);
	printf("-------------------\n");
	NLR(root);
	printf("-------------------\n");
	LRN(root);
}
