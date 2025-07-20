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
    struct node* last=*head_point;


    if(*head_point==NULL){
        *head_point=newnode;
        return;
    }


    while(last->next!=NULL){
        last=last->next;
    }


    last->next=newnode;

}


//logic for deleting a linked list 
 
void delete(struct node** node){
    
    struct node* current=*node;
    struct node* next_node;
    
    while(current!=NULL){

            next_node=current->next;
            free(current);
            current=next_node;



    }
    *node=NULL;
        




        
}




int main(){
    struct node* head=NULL;
    add(&head,2);
    add(&head,4);
    add(&head,5);
    add(&head,9);
    add(&head,3);

    delete(&head);


    return 0;
}
