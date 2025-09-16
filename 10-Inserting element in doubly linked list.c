#include<stdio.h>
#include<stdlib.h>

//defining a structure
struct node{
    int data;
    struct node* next;
    struct node* prev;
};

//creating a node 
struct node* create(int data){
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=NULL;
    newnode->prev=NULL;
    return newnode;

}

//inserting at the beginning
void insert_beginning(struct node** head,int data){
    struct node* newnode=create(data);
    newnode->next=*head;
    if(*head!=NULL){
        (*head)->prev=newnode;
    }
    *head=newnode;

}

//inserting at the end
void insert_atend(struct node** head,int data){
    struct node* newnode=create(data);
    if(*head==NULL){
        *head=newnode;
        return;
    }

    struct node* temp=*head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newnode;
    newnode->prev=temp;

}
int main(){

    struct node* head=NULL;

    //logic for calling function
    insert_atend(&head,4);
    insert_atend(&head,10);
    insert_atend(&head,3);
    insert_atend(&head,6);
    insert_beginning(&head,10);
    insert_beginning(&head,12);

    return 0;
}
