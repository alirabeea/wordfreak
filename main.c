#include "BST.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h> 
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

void readFile(char* argv){
    int fdin;
    char* buf = (char*)malloc(sizeof(char)*10000);
    char* tempstr = (char*)malloc(sizeof(char)*1024);
    ssize_t c; 
    if(strcmp(argv,"0")==0){
        fdin = 0;
        //for normal arguments/ environment 
        int i = 0;
        while ((c = read(fdin, buf, 1)) > 0) {
            char* dummystr = (char*)malloc(sizeof(char)*10000);
            //printf("%s", buf);
            //checks if the char is an alphabet and then makes it lowercase
            if(isalpha(buf[0])){
                tempstr[i] = tolower(buf[0]);
                i++;
            }
            else{
                tempstr[i] = '\0'; //adds a cut off point after the word in order to prevent unwanted characters
                if(isalpha(tempstr[0])){//checks if the first letter of the is an alphabet, and if so inserts it into the hashtable
                    //printf("%s ",tempstr);
                    int index = getHash(tempstr[0]);//gets the hash of the word by using the first letter
                    if(hashTable[index] == NULL){//if the root is null, then the word becomes the first node in the BST for that letter
                        hashTable[index] = insert(hashTable[index], tempstr);
                    }
                    else if(findNode(hashTable[index],tempstr) != NULL){//if it finds the same word already in the BST, then it increments it
                        findNode(hashTable[index],tempstr)->count++;
                    }
                    else if(hashTable[index] != NULL && findNode(hashTable[index],tempstr) == NULL){//if it cant find a similar word and the root exists, then it just adds it to the BST
                        insert(hashTable[index], tempstr);
                    }
                }
                strcpy(tempstr,dummystr);
                i=0;
            }
        }   
        if(isalpha(tempstr[0])){// same code from earlier to add the last word.
            //printf("%s ",tempstr);
            int index = getHash(tempstr[0]);
                if(hashTable[index] == NULL){
                    hashTable[index] = insert(hashTable[index], tempstr);
                }
                else if(findNode(hashTable[index],tempstr) != NULL){
                    findNode(hashTable[index],tempstr)->count++;
                }
                else if(hashTable[index] != NULL && findNode(hashTable[index],tempstr) == NULL){
                    insert(hashTable[index], tempstr);
                }
        }   
        if ((close(fdin)) == -1) {//closing the file error
            printf("File cannot be closed. \n");
        }
        
    }
    else{
        //checks to open file
        if ((fdin = open(argv, O_RDONLY)) == -1) {
            printf("File cannot be opened. \n");
        }
        //for normal arguments/ environment
        else { 
        int i = 0;
        while ((c = read(fdin, buf, 1)) > 0) {
            char* dummystr = (char*)malloc(sizeof(char)*10000);
            //printf("%s", buf);
            //checks if the char is an alphabet and then makes it lowercase
            if(isalpha(buf[0])){
                tempstr[i] = tolower(buf[0]);
                i++;
            }
            else{
                tempstr[i] = '\0'; //adds a cut off point after the word in order to prevent unwanted characters
                if(isalpha(tempstr[0])){//checks if the first letter of the is an alphabet, and if so inserts it into the hashtable
                    //printf("%s ",tempstr);
                    int index = getHash(tempstr[0]);//gets the hash of the word by using the first letter
                    if(hashTable[index] == NULL){//if the root is null, then the word becomes the first node in the BST for that letter
                        hashTable[index] = insert(hashTable[index], tempstr);
                    }
                    else if(findNode(hashTable[index],tempstr) != NULL){//if it finds the same word already in the BST, then it increments it
                        findNode(hashTable[index],tempstr)->count++;
                    }
                    else if(hashTable[index] != NULL && findNode(hashTable[index],tempstr) == NULL){//if it cant find a similar word and the root exists, then it just adds it to the BST
                        insert(hashTable[index], tempstr);
                    }
                }
                strcpy(tempstr,dummystr);
                i=0;
            }
        }   
        if(isalpha(tempstr[0])){// same code from earlier to add the last word.
            //printf("%s ",tempstr);
            int index = getHash(tempstr[0]);
                if(hashTable[index] == NULL){
                    hashTable[index] = insert(hashTable[index], tempstr);
                }
                else if(findNode(hashTable[index],tempstr) != NULL){
                    findNode(hashTable[index],tempstr)->count++;
                }
                else if(hashTable[index] != NULL && findNode(hashTable[index],tempstr) == NULL){
                    insert(hashTable[index], tempstr);
                }
        }   
        if ((close(fdin)) == -1) {//closing the file error
            printf("File cannot be closed. \n");
        }
    }
    }

    int output = open("output.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);//making output.txt

    if(output == -1){//error message for output.txt
        printf("Output File cannot be opened. \n");
    }
    
    int max = 0;//finding max strlen amongst all the words
    for(int i = 0; i<26; i++){
        if(findMax(hashTable[i],max)>max){
            max = findMax(hashTable[i],max);
        }
    }
    
    for(int i = 0; i<26; i++){// writes the words into the output.txt
        //print(hashTable[i]);
        writeFile(hashTable[i],output, max);
    }
}

int main(int argc,char *argv[]) {
    createHashtable(hashTable);//initiallizes the hashtable to NULL

    int i = 1;
    while(argv[i]){//reads all the inputs from the arguments
        readFile(argv[i]);
        i++;
    }

    char* environ = getenv("WORD_FREAK");// gets environ input

    if(environ != NULL){//if not null, then is read
        readFile(environ);
    }

    readFile("0");


    return 0;
}