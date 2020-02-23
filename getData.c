#include "plate.h"

//getdata will read a text file that was found in the command line
//the functin will return 0 if the file is unreadable or it will
//return 1 if there were no problems reading the file
int getData(Node root, char data[200]) {
	//flag variable for reading
	int reading = true;

	//opens the file pointer
	FILE *fp;
	fp = fopen(data, "r");

	//if it's unreadable, returns NULL
	if(fp == NULL) {
		return (0);
	}

	//string buffers for reading the file
	char w1[200];
	char w2[200];
	char w3[200];
	
	//creates empty character store temporary characters in
	char ch = ' ';
	
	//counting variables for 
	int i = 0;
	int entries = 0;
	while(ch != EOF) {
		int wordcount = 0;
		while(wordcount < 3) {
			char buffer[200];
			while( (ch = fgetc(fp)) != '\n' && ch != ' ' && ch != EOF) {
				buffer[i] = ch;
				i++;
			}
			buffer[i]='\0';
			if(wordcount == 0)
				strcpy(w1, buffer);
			if(wordcount == 1)
				strcpy(w2, buffer);
			if(wordcount == 2)
				strcpy(w3, buffer);
			wordcount++;
			i = 0;
		}
		if( ch != EOF) {
			add(root, w1, w2, w3);
			entries++;
		}
	}
	
	fclose(fp);
	return (1);

}
