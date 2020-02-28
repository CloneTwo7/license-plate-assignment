#include "plate.h"

Node getData(Node root, char database[200]) {
    //flag variable called "reading"
    int reading = true;

    //creates file pointer and opens file for reading
    FILE *fp;
    fp = fopen(database, "r");

    //ensures file is not NULL
    if(fp == NULL) {
        return(0);
    }

    //buffer variables to hold plate, first, and last values
    char w1[200];
    char w2[200];
    char w3[200];
    char ch = ' '; //sets readable character equal to space to ensure it is not EOF

    int i = 0;
    //loops while the character read from the file is not EOF
    while(ch != EOF) {
        int wordcount = 0;
        while(wordcount < 3) {
            char buffer[200];
            while( (ch = fgetc(fp)) != '\n' && ch != ' ' && ch != EOF) {
                buffer[i] = ch;
                i++;
            }
            buffer[i] = '\0';
            if(wordcount == 0)
                strcpy(w1, buffer); //places plate into w1
            if(wordcount == 1)
                strcpy(w2, buffer);
            if(wordcount == 2)
                strcpy(w3, buffer);
            wordcount++;
            i = 0;
        }
        if(ch != EOF) {
            root = add(root,w1,w2,w3);
        }
    }
    fclose(fp);
    return(root);
}
