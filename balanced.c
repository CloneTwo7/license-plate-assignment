#include "plate.h"

int balanced(Node root) {
    //checks to see if the current node is null
    if(root == NULL) {
        //null nodes are concsidered balanced
        return(1);
    }    
    //grabs values of height left and right
    int hl = height(root->left);
    int hr = height(root->right);
    //checks to see if the difference in heights are only 1 away
    if((hl+1==hr)||(hl-1==hr)||(hl==hr)) {
        //checks to see if both subtrees are balanced
        if(balanced(root->left)&&balanced(root->right)) {
            //if so, return 1
            return(1);
        }
    }
    else {
        //if anything isn't balanced, return 0
        return(0);
    }
}