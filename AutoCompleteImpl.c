#include "AutoCompleteImpl.h"

// this function concatenates a letter to agiven set of letters
char *concat(char *begin, char letter){
	//allocating memory for the new char set
	char *result = malloc(sizeof (char)* (strlen (begin) + 2));
	int i = 0;
	
	//coping the existing prefix to new memory
	while(begin[i]!='\0'){
		result[i] = begin[i];
		i++;
	} 
	
	//put the letter to end of it
	result[i++] = letter;
	result[i] = '\0';
	
	//returning the reference of concatenated chars
	return result;
}


// this function inserts a new word to the trie creating appropriate nodes
void insert(TrieNode *node, char *word){

	int len = strlen(word);		
	int i;
	
	//populating the new word to the trie
	for(i = 0; i<len; i++){
		TrieNode *currentNode = node->children[word[i] % 97];
		
		//creating a new node if a matching node is not present in the trie
		if(currentNode == NULL){
			int i;
			currentNode = malloc(sizeof(TrieNode));
			currentNode->isEndOfWord = 0;
			for(i = 0; i < 26; i++)currentNode->children[i] = NULL;
		}
		
		//setting the last node corresponding to the last letter of the word as 'end of a word'
		if(i + 1 == len){
			currentNode->isEndOfWord = 1;
			}

		node->children[word[i] % 97] = currentNode;
		node = node->children[word[i] % 97];
	}

}

// this function prints all the words from a given prefix root
void print(TrieNode *subRoot, char *prefix){

	//base case returning if the node is null
	if(subRoot == NULL) 
		return;
	
	//start printing if 'is end of word' is set
	if(subRoot->isEndOfWord){
		printf("%s\n", prefix);
		}
	
	//recursive calling with the next letter concatinated
	int i;
	for(i = 0; i < 26; i++){
		if(subRoot->children[i] != NULL){
			print(subRoot->children[i], concat(prefix, i + 97));
		}
	}
}

//this function finds the subroot of a given prefix and call print
//to print all the words from that subroot
void search(TrieNode *root, char *prefix){
	TrieNode *subRoot = root;
	int len = strlen(prefix);
	int i;
	
	//iterating until the subroot
	for(i = 0; i < len; i++){
		subRoot = subRoot->children[prefix[i] % 97];
		} 
	
	//calling print to print all the words starting from that subroot
	print(subRoot, prefix);
}
