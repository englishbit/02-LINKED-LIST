#include<stdio.h>
#include<stdlib.h>
//defining the structure 
struct node{
    int data;
    struct node* next;
};

//logic for creating a node;
struct node* crt_node(int data){

        struct node* new_node=(struct node*)malloc(sizeof(struct node));

        new_node->data=data;
        new_node->next=NULL;
        return new_node;
}

//logic for adding a node at the last position of a node
void add( struct node** head_point,int new_data){

    struct node* newnode=crt_node(new_data);

    if(*head_point==NULL){
        *head_point=newnode;
        newnode->next=newnode;
        return;
    }
  
    

    struct node* last=*head_point;

    while(last->next!=*head_point){
        last=last->next;
    }


    last->next=newnode;
    newnode->next=*head_point;

}

int main(){
    struct node* head=NULL;

    //logic for calling function
    add(&head,2);
    add(&head,4);
    add(&head,5);
    add(&head,9);
    add(&head,3);
    return 0;
}


