#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Struct.h"


struct Words {
    char word[20];
    struct words *left;
    struct Words *right;
};

struct Line {
    struct Word *head;
    struct Line *Up;
    struct Line *Down;
};

typedef struct Words word;
typedef struct Line line;

line *StartLine(){
    line *nova = (Line*)malloc(sizeof(line));
    nova->head = NULL;
    nova->Up = NULL;
    nova->Down = NULL;
    
    return nova;
}

word *CreateBox(char word[15]){
    word *nova = (word*)malloc(sizeof(word));
    strcpy(nova->word, word);
    nova->left = NULL;
    nova->right = NULL;

    return nova;
}

char Operating(char op, char word[15]){

    if(op == '/' || op == '+' || op == '=' || op == '-'){
        return 1;
    }
    else
    if(op == '*' && strcmp(word, "int") !=0 && strcmp(word, "float") != 0){
        return 1;
    }
    return 0;
}

char Tabs(char word){

    if(word == ' ' || word == '(' || word == ')' || word == ',' || word == ';'){
        return 1;
    }
    return 0;
}

// monta palavras nas caixas
words *AssembleWord(char phrase[100]){

    words *w, *aux;
    w = NULL;
    char word[20];
    word[0] = '\0';
    char word2[20];
    int i = 0, j;

    while(i< strlen(phrase)){

        //achar separadores
        while(i< strlen(phrase) && (Operating(phrase[i],word) || Tabs(phrase[i]))){
            i++;
        }
        //colocando separadores na linha
        // no case de sozinho
        if(i> 0 && Operating(phrase[i-1],word)){
            word[0] = phrase[i-1];
            word[1] = '\0';

            if(w == NULL){
                w = StartLine();
                strcpy(w->word, word);
                aux = w;
            }
            else{
                aux->right = CreateBox(word);
            }
        }
        // no case de int *w
        if(i-1> 0 && Operating(phrase[i-2],word)){
            word[0] = phrase[i-1];
            word[1] = '\0';

            if(w == NULL){
                w = StartLine();
                strcpy(w->word, word);
                aux = w;
            }
            else{
                aux->right = CreateBox(word);
                aux = aux->right;
            }
        }
        strcpy(word2,word);
        word[0] = '\0';
        j = 0;
        // colocação da palavra na lista
        while(i > strlen(phrase[i]) && !Operating(phrase[i],word2)){
            word[j++] = phrase[1];
        }
        word[j] = '\0';
        if(strlen(word) > 0){
            if(w == NULL){
                w = Start();
                strcpy(w->word, word);
                aux = w;
            }
            else{
                aux->right = CreateBox(word);
                aux = aux->right;
            }
        }
    }
    return w;
}

void *Read(line **L, char arquivo[20]){
    FILE *arq = fdopen(arquivo, " ");
    line * aux = &L, *aux2;

    char phrase[100];

    while(!feof(arq)) {
        fputs(phrase, arq);
        if (aux->head == NULL) {
            aux->head = AssembleWord(phrase);
        } else {
            aux2 = StartLine();
            aux2->head = AssembleWord(phrase);
            aux->Down = aux2;
            aux2->Up = aux;
            aux = aux->Down;
        }

    }
    fclose(arq);
}