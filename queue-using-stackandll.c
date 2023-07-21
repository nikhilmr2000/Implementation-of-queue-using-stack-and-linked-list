// Implementation of queue using stack and linked list


#include <stdio.h>
#include<stdlib.h>

int main() {
    
    struct node{
        int data;
        struct node *next;
    };
    
    struct node *top1=NULL;
    struct node *top2=NULL;
    
    void  push1(int x){
        
        struct node *newnode;
        newnode=(struct node *)malloc(sizeof(struct node));
        newnode->data=x;
        newnode->next=top1;
        
        top1=newnode;
        
    }
    
    int pop1(){
        
        struct node *popnode=NULL;
        
       if(top1==NULL){
           printf("Queue is empty");
       } 
       else{
           popnode=top1;
           top1=top1->next;
       }
       
       return popnode->data;
        
    }
    
    void push2(int x){
        
        struct node *newnode1;
        newnode1=(struct node *)malloc(sizeof(struct node));
        newnode1->data=x;
        
        newnode1->next=top2;
        top2=newnode1;
    }
    
    int pop2(){
        struct node *popnode;
        if(top2==NULL){
            printf("Queue is empty");
        }
        else{
            popnode=top2;
            top2=top2->next;
        }
        return popnode->data;
    }
    
    int count=0;
    
    void enqueue(int value){
        
        push1(value);
        count++;
        
    }
    
    void dequeue(){
        
        for(int i=0;i<count;i++){
            int temp=pop1();
            push2(temp);
            
        }
        
        pop2();
        count--;
        
        for(int i=0;i<count;i++){
            int temp=pop2();
            push1(temp);
        }
        
        
    }
    
    void display(){
        
        struct node *temp;
        temp=top1;
        while(temp!=NULL){
            printf("%d ",temp->data);
            temp=temp->next;
        }
        
    }
    
    
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();
    dequeue();
    enqueue(50);
    printf("\n");
    display();
    dequeue();
    printf("\n");
    display();
    
}
