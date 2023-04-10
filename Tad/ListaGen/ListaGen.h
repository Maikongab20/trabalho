#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "Arquivo.h"


// struct

union Termo{
    float valor;
    char operador;
    char function[20];
};

struct ListGen{
    char terminal;
    union Termo info;
    struct ListGen *Head;
    struct ListGen *Tail;
};

struct Pilha{
    struct ListGen *Head;
    struct Pilha *right;

};
struct Fila{};


typedef struct ListGen listgen;
typedef struct Pilha pilha;
typedef struct Fila fila;

// strutura para criar a listagen

listgen *CriaT(char funcao[20],char operator,float valor){
    listgen *L = (listgen*) malloc(sizeof(listgen));
    L->teminal = 1;
    L->info.operador = operator;
    L->info.valor = valor;
    strcpy(L->info.function,funcao);
    return L;

}

char Nula(listgen *L){
    return  L == NULL;
}

char Atomo(listegen *L){
    return !NUla(L) && L->terminal;
}

listgen *Cons(listgen *H, listgen *T){

    if(Atomo(T)){
        prinntf("Cons: Segundo argumento nao pode ser atomo!");
        retur NULL;
    }
    else{
        listgen * L = (listgen *) malloc(sizeof(listgen));
        L->terminal = 0;
        L->Head = H;
        L->Tail = T;
        return L;
    }
}

// Pilha 


void StartPilhaL(pilha **P){
    *p = NULL;
}

void IsEmptyPilha(pilha *P){
    return P == NULL;  
}

// listgen *Pop( p **P,listgen **L){

//     if(!IsEmpty(P)){

//     }
// }

void PushPilha( pilha **P,listgen *L){
    p *nova = (p *)malloc(sizeof(p));
    nova->Head = L;
    nova->right = P;
    *P = nova;
}

void PopPilha(pilha **P, listgen **L){
    p *aux;
    if(!IsEmpty(P)){
        *L = *P;
        aux = *P;
        *P = (*P)->right;
        free(aux);
    }
    else{
        *L = -1;
    }
}

// montando a lista generalized

listgen *CreateListGen(words *start, words *end){
    listgen *L = NULL; *atual;
    words *Lc = start;
    pilha = *pi;

    while(Lc != NULL){
        if(L == NULL){
            L = atual = Cons(CriaT(Lc->word), NULL);
        }
        if(strcmp(Lc->word, "(") == 0){
            atual->Tail = Cons(CriaT("0"), NUll);
            PushPilha(&Pi,atual);
            atual = atual->Tail;
            Lc = Lc->right;
            atual->Head = Cons(CriaT(Lc->word), NUll);
            atual = atual->Tail;
        }

        else{
            if(strcmp(Lc->word,")" == 0)){
                PopPilha(&Pi,&atual);
            }
            else{
                atual->Tail = Cons(CriaT(Lc->word), NUll);
                atual = atual->Tail;
            }
        }
        Lc = Lc->right;
    }
}

float Resolver(listgen **L){

    pilha *P;
    fila *F;
    StartPilhaL(&L);
    StartFilaL(&F);
    listgen *aux = *L;
    float results;

    while(!IsEmpty(F)){
        dequeue(&F,&aux);
        while(aux != NULL){
            if(aux->Head != NULL){
                pushPilha(&P, aux->Head);
            }
            aux = aux->Tail;
        }

        while(!IsEmptyPilha(P)){
            PopPilha(&P,&aux);
            if(aux != *L){
                aux->info.valor = Calcula(aux->Head);
            }
            else{
                results = Calcula(aux);
            }
            *L = NULL;
        }
    }
    return results;
}


float Calcula(listagen *L){

    pilha *P1;
    pilha *Equacao;


    while(!NulaL(l)){
        if(L->info.operador,"0"){
            PushPilha(&P1, L);
        }
    }

    PopPilha(&P1,&L);
    while(P != NULL){
        while(!NUla(L)){
            if(strcmp(L->info.funcao,"")){}
        }
        PopPilha(&P,&L);
    }
}