#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct QueueNode {
    char tugas[50];
    struct QueueNode *next;
}QueueNode;

typedef struct{
    QueueNode *depan;
    QueueNode *belakang;
}Queue;

typedef struct AnggotaNode{
    char nama[50];
    Queue To_do_list;
    struct AnggotaNode *next;
    struct AnggotaNode *prev;
}AnggotaNode;

typedef struct {
    AnggotaNode *head;
    AnggotaNode *Pnew;
} WorkerList;

QueueNode *CreatQueueuNode(const char *tugas){
     QueueNode *newNode = (QueueNode*)malloc(sizeof(QueueNode));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    strcpy(newNode->tugas, tugas);
    newNode->next = NULL;
    return newNode;
}

int main(){
int i;

    return 0;
}
