#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define ALPHABET_SIZE (26)
#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')

typedef struct TrieNode{
    struct TrieNode *children[ALPHABET_SIZE];
    bool isEndOfWord;
} TrieNode;

void insert(TrieNode* root, char* word);
void search(TrieNode *root, char *prefix);
void print(TrieNode *subRoot, char *prefix);
char *concat (char *begin, char letter);
