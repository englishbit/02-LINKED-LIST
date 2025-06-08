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


//logic for deleting a node from the linked list
 
void delete(struct node** node,int indx){
    
    int count=0;


    if(*node==NULL){
        printf("the list is empty\n");
        return;
    }


    
    struct node* temp=*node;
    struct node* prev=NULL;



    if(indx==0){
        *node=temp->next;
        free(temp);
        return;


    }

    while(temp!=NULL&&count<indx){
            prev=temp;
            temp=temp->next;

            count++;


    }
    
    if(temp==NULL){
        return;
    }


    prev->next=temp->next;
    free(temp);

        
}




int main(){
    struct node* head=NULL;
    add(&head,2);
    add(&head,4);
    add(&head,5);
    add(&head,9);
    add(&head,3);


    int pos;
    scanf("%d",&pos);

    if(pos<0||pos>4){
        printf("wrong input\n");
        return -1;
    }

    delete(&head,pos);








    return 0;
}
