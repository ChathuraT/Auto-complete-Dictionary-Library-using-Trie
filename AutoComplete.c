#include "AutoCompleteImpl.h"
#include <stdbool.h>
#include <time.h>

#define INPUT_WORD_SIZE (100)

// this function is used to take inputs from the user
char *receiveInput(char *s){
    scanf("%99s", s);
    return s;
}

// this function is used to validate the user's input
bool isValidWord(char *word){
	int len = strlen(word);
	int i;

	for(i = 0; i < len; i++){
		if((int)word[i] < 97 || (int)word[i] > 122){
			return false;
			}
		} 
	return true;
}

int main(){
	TrieNode root;
	int i;
	char word[INPUT_WORD_SIZE];
	char input[INPUT_WORD_SIZE];
	
	// setting the main root as 'not a word'
	root.isEndOfWord = 0;
	
	// setting the main roots childrens to null
	for(i = 0; i < 26; i++){
		root.children[i] = NULL;
		} 
	
	// opening resource file to populate the trie
	FILE *fp = fopen("resources/dictionary.txt", "r");
	if(fp == 0){
		fprintf(stderr, "Error while opening dictionary file");
		exit(1);
	}
	
	// populating the trie by taking inputs from the file line by line
	while(!feof (fp)){
		fscanf(fp, "%s", word);
		insert(&root, word);
	}
	
	fclose(fp);

	// taking user inputs and output the suggestions
	while(1){ 	
		printf("Enter keyword: ");
       
        receiveInput(input);
        printf("\n==========================================================\n");
        printf("\n********************* Possible Words ********************\n");
		
		if(isValidWord(input)){
			clock_t begin = clock();
			search (&root, input);
			clock_t end = clock();
			double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
			printf("%f", time_spent);
		}else
			printf("\n===================== Invalid Input =====================\n");
		
	
        printf("==========================================================\n");
	}

	return 0;
}
