//include files
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//defines and typdefs
#define true 1
#define false 0
typedef struct node* Node;

//struct node
struct node {
	char *plate;
	char *first;
	char *last;
	struct node *left;
	struct node *right;
};

//function prototypes
Node getData(Node root, char data[200]);							
	//takes in the root node and the file name
	//opens file as read-only and filters the plate
	//first, and last strings into their own variables, 
	//then adds the units to the binary tree
	//returns 1 if added successfully
	//returns 0 if file was not openable
int height(Node root);											//done
	//returns the height of the tree
int balanced(Node root);										//done
	//returns 1 if tree is balanced
	//returns 0 if tree is unbalanced
Node add(Node root, char *plate, char *first, char *lats);		//done
	//adds a new node to the current tree
	//returns the location of the root node
int search(Node root, char *plate, char *first, char *last);	//done
	//traverses the tree for the plate passed to it
	//if the plate is found, load the values into first and last
	//if not found, returns 0
Node delete(Node root, char *plate);							//done
	//searches for the plate passed to it
	//if found, deletes it and returns the root node
	//if not found, return 0
void LNR(Node root);											//done
	//prints the tree contents in left, node, right order
void NLR(Node root);											//done
	//prints the tree in node, left, right order
void LRN(Node root);											//done
	//prints the tree in left, right, node order
void treeFree(Node root);										
	//releases all memory associated with the tree
