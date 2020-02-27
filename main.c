#include "plate.h" 

int main(int argc, char **argv) {
	Node root = NULL;
	if(argc != 2) {
		printf("Not the correct amount of arguments\n");
		return(0);
	}
	FILE *fp;
	fp = fopen(argv[1], "r");
	printf("argv[1] == %s\n",argv[1]);
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
	printf("---------LNR-------\n");
	LNR(root);
	root = delete(root, "LOV-MNY");
	LNR(root);
}
