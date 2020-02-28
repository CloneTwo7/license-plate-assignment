#include "plate.h" 

int main(int argc, char **argv) {
	Node root = NULL;
	//checks to see if there are the right amount of arguments
	if(argc != 2) {
		printf("Wrong number of arguments\n");
		return(0);
	}
	FILE *fp = fopen(argv[1], "r");
	if(fp == NULL) {
		printf("Cannot open file\n");
	}
	char buffer[300];
	while(fgets(buffer, 300, fp)!= NULL) {
		char plate[200], first[200], last[200];
		sscanf(buffer, "%s" "%s" "%s", plate, first, last);
		printf("adding %s", plate);
		root = add(root, plate, first, last);
	}
	fclose(fp);
	printf("height: %d\n", height(root));
	printf("Balanced: %d\n", balanced(root));
	printf("---------LNR-------\n");
	LNR(root);
}
