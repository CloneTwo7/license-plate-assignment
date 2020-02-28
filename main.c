/***********************************************************\
|This is the main program in which the user will interact	|
|with the hashed data to view and test different license	|
|plates.													|
\***********************************************************/
 #include "plate.h"

int main(int argc, char **argv) {
	//variable size to initialize the hashTable
	int size;
	//checks to see if too few command line arguments were passed
	if(argc < 2) {
		//if so, print error and exit
		printf("please include database\n");
		return (0);
	}

	//checks to see if user wished to use a non-default hashTableSize
	if(argc > 2) {
		//using sscanf to parse user input and check user is passing valid integer
		int valid = sscanf(argv[2], "%d", &size);
		if(valid == 0) {
			printf("\"%s\" is not a valid size\n", argv[1]);
		}
	}
	
	//if user entered the default # of command line arguments, set size = to the default of 100
	if(argc == 2) {
		size = DEFAULT_HASHSIZE;
	}
	
	//initializes new hashTable called list
	hashEntry *list = hashInit(size);

	//getData reads from the desired file and sorts it all into the hash table
	getData(list,argv[1]);
	
	//friendly greeting
	printf("Good evening sir or madam.\n");

	//declares variables for parsing and loops
	char input[400];							//input acts as a buffer for user input
	char command[200];							//command is the parsed-version of input (stores whatever command the user is trying to use)
	int number;									//number is a generic num variable that's typically used for *DUMP
	
	char first[200];							//declared space for first name if user attempts to "find" a sepcific plate
	char last[200];								//declared space for last name if user attempts to "find" a specific plate

	//prompt
	printf("Enter Plate: ");

	//loop runs while user does not enter EOF via ctrl-D
	//conditional statement stores user input.
	while(NULL != fgets(input,400,stdin)) { 
		//parses user input into both command and number variables
		int argc = sscanf(input, "%s" "%d", command, &number);

		//checks argc of user input
		//if agrc == 2, then user wants to print a specific linkedList
		if((argc == 2) && (0 == strcmp(command, "*DUMP"))) {
			//checks to see if number is within a valid range
			if(number < size && number >= 0) {
				printf("printing one hashtable\n");
				hashDump(list, number);
			}
			//if not within a valid range, print error message
			else {
				printf("Cell %d does not exist\n", number);
			}
		}
		//if user didn't input a number along wit *DUMP, prints entire hashTable
		else if( 0 == strcmp(command, "*DUMP")) {
			printf("printing all hashtables\n");
			for(int i = 0; i < size; i++) {
				hashDump(list, i);
			}
		}
		//if user wanted to use *LOAD, then calls *LOAD
		else if( 0 == strcmp(command, "*LOAD")) {
			hashLoad(list);
		}
	
		//if user didn't enter any other commands, then it assumes user is searching for a specific plate
		else {
			//passes command (assumed to be a plate value) and pointers for first and last to hashFind
			//if hashFind returns 1...
			if( 1 == hashFind(list, command, first, last)) { 
				//prints first and last name of person who owns license plate
				printf("First name: %s\n", first);
				printf("Last name: %s\n", last);
			}
			//if hashFind returns 0...
			else {
				printf("NODE NOT FOUND\n");
			}
		}
		//ends loop with prompt
		printf("Enter Plate: ");
	}
	//prints new line for visual's sake
	printf("\n");
	//hashFree frees data
	hashFree(list);
}
