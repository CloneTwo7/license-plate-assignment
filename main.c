/***********************************************************\
|This is the main program in which the user will interact	|
|with the hashed data to view and test different license	|
|plates.													|
\***********************************************************/
 #include "plate.h"

int main(int argc, char **argv) {
	//checks to see if too few command line arguments were passed
	if(argc != 2) {
		//if so, print error and exit
		printf("please include database\n");
		return (0);
	}
	Node root = NULL;
	root = getData(root,argv[1]);
	
	//friendly greeting
	printf("Good evening sir or madam.\n");

	//declares variables for parsing and loops
	char input[400];							//input acts as a buffer for user input
	char command[200];							//command is the parsed-version of input (stores whatever command the user is trying to use)
	
	char plate[200];
	char first[200];							//declared space for first name if user attempts to "find" a sepcific plate
	char last[200];								//declared space for last name if user attempts to "find" a specific plate

	//prompt
	printf("Enter Plate: ");

	//loop runs while user does not enter EOF via ctrl-D
	//conditional statement stores user input.
	while(NULL != fgets(input,400,stdin)) { 
		//parses user input into both command and number variables
		int argc = sscanf(input, "%s" "%s", command, plate);

		//checks argc of user input
		//if agrc == 2, then user wants to print a specific linkedList
		if(0 == strcmp(command, "*DUMP")) {
			printf("Height: %d\n", height(root));
			int bal = balanced(root);
			if(bal == 1) {
				printf("Balanced: YES\n");
			}
			else {
				printf("Balanced: NO\n");
			}
			printf("------LNR TRAVERSAL------\n");
			LNR(root);
			printf("------NLR TRAVERSAL------\n");
			NLR(root);
			printf("------LRN TRAVERSAL------\n");
			LRN(root);
		}
		else if((argc == 2) && (0 == strcmp(command, "*DELETE"))) {
			if(search(root, plate, first, last)==1) {
				printf("SUCCESS\n");
			}			
			else {
				printf("PLATE NOT FOUND\n");
			}
			root = delete(root, plate);
		}
		//anything else is assumed to be looking for a plate
		else {
			if(search(root, command, first, last)==1) {
				printf("First Name: %s\n", first);
				printf("Last Name: %s\n", last);
			}
			else {
				printf("PLATE NOT FOUND\n");
			}
		}
		//ends loop with prompt
		printf("Enter Plate: ");
	}
	//prints new line for visual's sake
	printf("\n");
	printf("Freeing memory....\n");
	treeFree(root);
}
