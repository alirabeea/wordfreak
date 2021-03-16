#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h> 
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define SIZE 26

struct BSTNode
{
  struct BSTNode* left;
  struct BSTNode* right;
  char* data;
  int count;
};

struct BSTNode *hashTable[26];

struct BSTNode *createNode(char* data);

int getHash(char key);

struct BSTNode *getRoot(char str[]);

//void insert(char* data);

struct BSTNode* insert(struct BSTNode* node, char* key);

struct BSTNode* findNode(struct BSTNode* node, char* key);

void createHashtable();

void printHelper(struct BSTNode* node);

void print(struct BSTNode* node); 

void writeFile(struct BSTNode* node, int file, int max);

int findMax(struct BSTNode* node, int max);