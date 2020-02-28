#include "plate.h" 

int main(int argc, char **argv) {
	Node root = NULL;
	//checks to see if there are the right amount of arguments
	if(argc != 2) {
		printf("Wrong number of arguments\n");
		return(0);
	}
	char *database;
	strcpy(database, argv[1]);
	root = getData(root, database);

	printf("height: %d\n", height(root));
	printf("Balanced: %d\n", balanced(root));
	printf("---------LNR-------\n");
	LNR(root);
	root = delete(root,"NW-TRMP");
	printf("--------====-------\n");
	LNR(root);
}
