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

//logic for counting nodes of a linked list
int find(struct node* node,int num){
        int count=0;


        while(node!=NULL){
            count++;


            if(node->data==num){
                printf("the data is found at %d position\n",count);
                return count;
            }

            node=node->next;
        }

        printf("the data is not found\n");
        return -1;
        
}




int main(){
    struct node* head=NULL;
    add(&head,2);
    add(&head,4);
    add(&head,5);
    add(&head,9);

    //logic for special case
    int m;
    scanf("%d",&m);
    if(m<0){
        printf("wrong input");
    }


    printf(find(head,m));











    return 0;
}