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


//logic for finding the nth node from the start;

int find_nth_node(struct node* node,int val){
        int count=0;


        while(node!=NULL){
            count++;


            if(node->data==val){
                printf("this the %dth node\n",count);
                return count;
            }

            node=node->next;
        }
        
        printf("the node is not present here\n");
        return -1;
        
}


int main(){
    struct node* head=NULL;
    add(&head,2);
    add(&head,4);
    add(&head,5);
    add(&head,9);

    //logic for special case
    int key;
    //logic for taking input
    scanf("%d",&key);
    printf("%d",find_nth_node(head,key));
    return 0;
}

