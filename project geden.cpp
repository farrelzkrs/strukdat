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
    struct AnggotaNode* prev;
    struct AnggotaNode* next;
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
    newnode->next = NULL;
    newnode->prev = NULL;
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
    printf("pekerja %s baru saja di tambahkan\n", nama);
}

void tampilkananggota(listpekerja *list){
    if(list->head == NULL){
        printf("tidak ada pekerja");
        return;
    }
    AnggotaNode* data = list->head;
    printf("pekerja: ");
    while(data != NULL){
        printf("%s\t", data->nama);
        data = data->next;
    }
    printf("\n");
}

void enqueue(Queue *queue, const char *jobdeks){
    QueueNode *tugas = CreatQueueuNode(jobdeks);
    if(queue->belakang == NULL){
        queue->depan = queue->belakang = tugas;
    }else{
        queue->belakang->next = tugas;
        queue->belakang = tugas;
    }
    printf("tugas %s baru saja ditambahkan\n");
}

void tambahkan_Jobdeks(listpekerja *list, const char *namapekerja, const char *jobdeks){
    AnggotaNode *data = list->head;
    while(data != NULL){
        if (strcmp(data->nama, namapekerja) == 0){
            enqueue(&data->To_do_list, jobdeks);
            return;
        }
        data = data->next;
    }
    printf("nama %s tidak ditemukan dalam tim\n", namapekerja);
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
        printf("2. tambahkan jobdeks\n");
        printf("masukan pilihan:");
        scanf("%d", &pilih);
        getchar();
        switch (pilih){
            case 1:
                printf("masukan nama pekerja: ");
                fgets(nama, sizeof(nama), stdin);
                nama[strcspn(nama,"\n")] = 0;
                tambahkanpekerja(&keperluan, nama);
                break;
            case 2:
                tampilkananggota(&keperluan);
                printf("masukan nama pekerja: ");
                fgets(nama, sizeof(nama), stdin);
                nama[strcspn(nama,"\n")] = 0;
                printf("masukan jobdeks: ");
                fgets(jobdeks, sizeof(jobdeks), stdin);
                jobdeks[strcspn(jobdeks,"\n")] = 0;
                tambahkan_Jobdeks(&keperluan, nama, jobdeks);
                break;
            default:
                break;
        }
    }while(pilih != 3);
    return 0;
}
