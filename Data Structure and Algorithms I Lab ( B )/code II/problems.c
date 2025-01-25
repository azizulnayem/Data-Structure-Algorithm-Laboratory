#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define SIZE 50
struct Data{
    int key;
    int id;
    string name;
};
struct Data* array[SIZE];
int hashCode(int key){
    return key%SIZE;
}
void insert(int key,int id, string name){
    struct Data *item=(struct Data*)malloc(sizeof(struct Data));
    item->key=key;
    item->id=id;
    item->name=name;
    int hashIndex=hashCode(key);
    while(array[hashIndex]!=NULL){
        ++hashIndex;
        hashIndex%=SIZE;
    }
    array[hashIndex]=item;
}
void display(){
    int i=0;
    for(i=0;i<SIZE; i++){
        if(array[i]!=NULL){
            printf("%d %d %s",array[i]->key,array[i]->id,array[i]->name);
        }
        else
            printf(" NULL ");
    }
    printf("\n");
}
int main(){
    insert(0,201,Nirob);
    display();
}
















