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
    struct AnggotaNode* next;
    struct AnggotaNode* prev;
}AnggotaNode;

typedef struct {
    AnggotaNode* head;
    AnggotaNode* Pnew;
}listpekerja;

void cekQueue(Queue *queue){
    queue->depan = NULL;
    queue->belakang = NULL;
}
void cekperkeja(listpekerja *list){
    list->head = NULL;
    list->Pnew =  NULL;
}

QueueNode *CreatQueueuNode(const char *tugas){
     QueueNode *newNode = (QueueNode*)malloc(sizeof(QueueNode));
    if (!newNode) {
        printf("tidak bisa mengalokasikan memori!\n");
        exit(EXIT_FAILURE);
    }
    strcpy(newNode->tugas, tugas);
    newNode->next = NULL;
    return newNode;
}
AnggotaNode *Creatnodepekerja(const char *nama){
    AnggotaNode *newnode = (AnggotaNode*)malloc(sizeof(AnggotaNode));
    if(!newnode){
        printf("tidak bisa mengalokasikan memori!\n");
        exit(EXIT_FAILURE);
    }
    strcpy(newnode->nama,nama);
    cekQueue(&newnode->To_do_list);
    newnode->next;
    newnode->prev;
    return newnode;
}
void tambahkanpekerja(listpekerja *list, const char *nama){
    AnggotaNode *nodebaru = Creatnodepekerja(nama);
    if(list->Pnew == NULL){
        list->head = list->Pnew = nodebaru;
    }else {
        list->Pnew->next = nodebaru;
        nodebaru-> prev =list ->Pnew;
        list->Pnew = nodebaru;
    }
}

int main(){
    listpekerja keperluan;
    cekperkeja(&keperluan);
    int pilih;
    char nama[50];
    char jobdeks[50];
    do{
        printf("menu\n");
        printf("1. tambahkan pekerja\n");
        printf("masukan pilihan:");
        scanf("%d", &pilih);
        getchar();
        switch (pilih){
            case 1:
                printf("masukan nama pekerja");
                fgets(nama, sizeof(nama), stdin);
                nama[strcspn(nama,"\n")] = 0;
                tambahkanpekerja(&keperluan, nama);
                break;
            case 2:
                break;
            default:
                break;
        }
    }while(pilih != 1);
    return 0;
}
