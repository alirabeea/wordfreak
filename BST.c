#include "BST.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h> 
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

struct BSTNode *createNode(char* data){
    struct BSTNode *node = (struct BSTNode*) malloc(sizeof(struct BSTNode));
    char* word = (char*)malloc(sizeof(char));
    strcpy(word,data);
    node->data = word;
    node->count = 1;
    return node;
}

int getHash(char key){
    if(key == 'a'){
        return 0;
    }
    if(key == 'b'){
        return 1;
    }
    if(key == 'c'){
        return 2;
    }
    if(key == 'd'){
        return 3;
    }
    if(key == 'e'){
        return 4;
    }
    if(key == 'f'){
        return 5;
    }
    if(key == 'g'){
        return 6;
    }
    if(key == 'h'){
        return 7;
    }
    if(key == 'i'){
        return 8;
    }
    if(key == 'j'){
        return 9;
    }
    if(key == 'k'){
        return 10;
    }
    if(key == 'l'){
        return 11;
    }
    if(key == 'm'){
        return 12;
    }
    if(key == 'n'){
        return 13;
    }
    if(key == 'o'){
        return 14;
    }
    if(key == 'p'){
        return 15;
    }
    if(key == 'q'){
        return 16;
    }
    if(key == 'r'){
        return 17;
    }
    if(key == 's'){
        return 18;
    }
    if(key == 't'){
        return 19;
    }
    if(key == 'u'){
        return 20;
    }
    if(key == 'v'){
        return 21;
    }
    if(key == 'w'){
        return 22;
    }
    if(key == 'x'){
        return 23;
    }
    if(key == 'y'){
        return 24;
    }
    if(key == 'z'){
        return 25;
    }
    return -1;
}

struct BSTNode* insert(struct BSTNode* node, char* key) {
 
    if (node == NULL){
        return createNode(key);
    }
    if (strcmp(key,node->data) < 0) {
        node->left  = insert(node->left, key); 
    }    
    else if (strcmp(key,node->data) > 0) {
        node->right = insert(node->right, key);   
    }    
    return node; 
}

struct BSTNode* findNode(struct BSTNode* node, char* key){
     if (node == NULL) {
        return NULL; 
    }  

    //findNode(node->left, key);

    if(strcmp(node->data,key)==0){
        return node;
    }
    if(strcmp(node->data,key) > 0){
        return findNode(node->right, key);
    }
    //if(strcmp(node->data,key) > 0){
        return findNode(node->left, key); 
    //}
    //return findNode(node->right, key);  
}

void createHashtable(){
    int i;
    for(i = 0; i < 26; i++){
        hashTable[i] = NULL;
    }
}

void print(struct BSTNode* node) { 
    if (node == NULL) {
        return; 
    } 

    print(node->left); 

    printf("%s: %i\n",node->data, node->count); 

    print(node->right);   
} 

void writeFile(struct BSTNode* node, int file, int max) { 
    if (node == NULL) {
        return; 
    } 

    writeFile(node->left, file, max); 

    write(file, node->data, strlen(node->data));
    for(int i = 0; i<25-strlen(node->data); i++){
        write(file, " ", 1);
    }
    write(file, ":", 1);
    write(file, " ", 1);
   
    char* buff = (char*)malloc(4);
    sprintf(buff,"%4d", node->count);
    write(file, buff, 4);
    free(buff);
    write(file, "\n", 1);

    writeFile(node->right, file, max);   
} 

int findMax(struct BSTNode* node, int max) { 

    if (node == NULL) {
        return -1; 
    } 

    findMax(node->left, max); 

    if(strlen(node->data)>max){   
        return strlen(node->data);
    }

    findMax(node->right, max); 

    return -1;  
} 
