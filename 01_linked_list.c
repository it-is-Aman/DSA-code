//*******DSA*******


//Linked list
/*An element in a linked list is a struct Node.
  It is made to hold integer data and a pointer of data type struct Node*, as it has to point to another struct Node. 
*/

// #include <stdio.h>
// #include <stdlib.h>

// struct node {
//     int data;
//     struct node* next;
// };

// void linkedlistTraversal(struct node * ptr){                                                       //head pointer take in ptr
//     while(ptr!=NULL){                                                                              //run until ptr points NULL (keep in mind that last node points NULL so, there is no address in it)
//     printf("value is %d\n",ptr->data);
//     ptr=ptr->next;                                                                                 //this will keep pointing to next node
//     }
// }

// int main(){

//     struct node * head;                                                                            
//     struct node * first;
//     struct node * second;
    
//     //Allocate memory for nodes in the linked list in Heap
//     head = (struct node *)malloc(sizeof(struct node*));                                            //Request the memory location for each of these nodes from heap via malloc
//     first = (struct node *)malloc(sizeof(struct node*));
//     second = (struct node *)malloc(sizeof(struct node*));

//     // Link first and second nodes
//     head->data=1;                                                                                  //this will store value in that location (data)
//     head->next=first;                                                                              //this will point to the next node (not the data value) and stores their address
    
//     first->data=2;
//     first->next=second;

//     //Terminate the list at the third node
//     second->data=3;
//     second->next=NULL;                                                                             //it points to NULL and have NULL address

//     linkedlistTraversal(head);

//     return 0;
// }


//insertion in linked list
/*
    we would first need to create that extra node. And then, we overwrite the current connection and make new connections
*/

// #include <stdio.h>
// #include <stdlib.h>

// struct node {
//     int data;
//     struct node* next;
// };

// void linkedlistTraversal(struct node * ptr){
//     while(ptr!=NULL){
//     printf("value is %d\n",ptr->data);
//     ptr=ptr->next;
//     }
// }

// //Insertion at the beginning:
// struct node* insertatstart(struct node *head,int data){
//     struct node * ptr =(struct node *)malloc(sizeof(struct node *));                                 //Create a new struct Node* pointer ptr, and assign it a new memory location in the heap.
//     ptr->data=data;                                                                                  //stores value in data

//     ptr->next=head;                                                                                  //point (new node ptr) to head node. Assign head to the next member of the ptr structure using ptr-> next = head 
//     return ptr;                                                                                      //return ptr because it acts as a head node or first node in linked list
// }

// //Insertion in between:  
// struct node* insertatindex(struct node * head,int data,int index){
//     struct node * ptr =(struct node *)malloc(sizeof(struct node *));                                 
//     ptr->data=data;
//     struct node * p = head;                                                                        //new struct Node* pointer pointing to head beacuse we don't want to loss our head

//     for(int i=1;i!=index-1;i++){
//         p=p->next;                                                                                 //this will keep pointing p to next node
//     }

//     ptr->next=p->next;                                                                             //Assign p->next to the next member of the ptr structure using ptr-> next = p->next (link ptr->next to the node which was in p->next)
//     p->next=ptr;                                                                                   //Break the connection between p and p->next and assigning p->next the new pointer. That is, p->next = ptr. (now link p->next to ptr node)
//     return head;
// }

// //Insertion at the end:
// struct node* insertatend(struct node * head,int data){
// struct node * ptr =(struct node *)malloc(sizeof(struct node *));                                 
//     ptr->data=data;
//     struct node * p = head;                                                                        

//     while(p->next!=NULL){                                                                          //we run a loop until the pointer reaches the end and points to NULL. (p->next contain NULL in the end it is the absolute end) and we need to add data in the end
//         p=p->next;                                                                                 //if there is p!=NULL then it means it runs until last node have value but in p->next!=NULL it see the very last node memory address which we are need for insertion at end
//     }

//     p->next=ptr;                                                                                   //Assign NULL to the next member of the new ptr structure using ptr-> next = NULL,
//     ptr->next=NULL;                                                                                //Break the connection between p and NULL by assigning p->next the new pointer. That is, p->next = ptr.
//     return head;    
// }

// //Insertion after a given node:
// struct node* insertafternode(struct node * head,struct node * prevptr,int data){
// struct node * ptr =(struct node *)malloc(sizeof(struct node *));                                 
//     ptr->data=data;                                                                        

//     ptr->next=prevptr->next;                                                                          //Assign prevNode->next to the next member of the ptr structure using ptr-> next = prevNode->next,
//     prevptr->next=ptr;                                                                                //Break the connection between prevNode and prevNode->next by assigning prevNode->next the new pointer. That is, prevNode->next = ptr.
//     return head;    
// }

// int main(){

//     struct node * head;                                                                            
//     struct node * second;
//     struct node * third;
    
//     head = (struct node *)malloc(sizeof(struct node*));                                          
//     second = (struct node *)malloc(sizeof(struct node*));
//     third = (struct node *)malloc(sizeof(struct node*));

//     head->data=1;                                                                                
//     head->next=second;                                                                            
    
//     second->data=2;
//     second->next=third;

//     third->data=3;
//     third->next=NULL;                                                                           

//     printf("\nbefore insertion \n");
//     linkedlistTraversal(head);

//     printf("\nafter insertion \n");
//     // head = insertatstart(head,33);                                                                 //give pointer of head and value to function and after return it store in head pointer
//     // head = insertatindex(head,33,2);                                                                 
//     // head = insertatend(head,33);                                                                 
//     head = insertafternode(head,second,33);                                                                 
//     linkedlistTraversal(head);

//     return 0;
// }


//Deletion in linked list


// #include <stdio.h>
// #include <stdlib.h>

// struct node{
//     int data;
//     struct node * next;
// };

// void trversal(struct node * ptr){
//   while(ptr!=NULL){
//     printf("element is %d \n",ptr->data);
//     ptr=ptr->next;
//   }
// }

// //deletion at fi5rst
// struct node * deletionatfirst(struct node *head){
//   struct node * ptr=head;                                                                          //Create a new struct Node* pointer ptr, and make it point to the current head.
//   head=ptr->next;                                                                                  //Assign head to the next member of the list, by head = ptr->next, because this is going to be the new head of the linked list.
//   free(ptr);                                                                                       //Free the pointer ptr. And return the head
//   return head;
// }

// //deletion at last
// struct node * deletionatlast(struct node *head){
//   struct node * p=head;                                                                            //Create a new struct Node* pointer p pointing to head. (this p pointer points head)
//   struct node * q=head->next;                                                                      //Create a new struct Node* pointer q pointing to head->next.  (this q pointer points next node of head) for easy calculation
//   while(q->next!=NULL){                                                                            //run a loop until the q pointer reaches the end and points to NULL.               
//     p=p->next;                                                              
//     q=q->next;                                                                                     //every time q pointer points one node ahead then p pointer so we easily delete q node and link p pointer to desired node.
//   }
//   p->next=NULL;                                                                                    //Assign NULL to the next member of the p structure using p-> next = NULL.
//   free(q);                                                                                         //Break the connection between q and NULL by freeing the ptr q.
//   return head;
// }

// //deletion at index
// struct node * deletionatindex(struct node *head,int index){
//   struct node * p=head;                                                                            
//   struct node * q=head->next;                                                                         
//   for(int i=0;i!=index-1;i++){                                                                     //run a loop until this q pointer reaches the index, so we can delete the q pointer because q pointer is one node ahead of p pointer.
//     p=p->next;
//     q=q->next;
//   }
//   p->next=q->next;                                                                                 //Assign q->next to the next member of the p structure using p-> next = q->next.
//   free(q);                                                                                         //Free the pointer q, because it has zero connections with the list now.
//   return head;
// }

// //deletion at value
// struct node * deletionatvalue(struct node *head,int value){
//   struct node * p=head;
//   struct node * q=head->next;
//   while(q->data!=value && q->next!=NULL){                                                          //Run a while loop until the pointer q encounters the given value or the list finishes.
//     p=p->next;
//     q=q->next;
//   }
//   if(q->data==value){                                                                              //because if loop did not find same value or reaches end then it will free the last node that's why we use if() 
//   p->next=q->next;                                                                                 //If it encounters the value, delete that node by making p point the next node, skipping the node q. And free q from memory.
//   free(q);
//   }
//   return head;
// }

// int main(){

//   struct node * head;
//   struct node * second;
//   struct node * third;

//   head = (struct node *)malloc(sizeof(struct node *));
//   second = (struct node *)malloc(sizeof(struct node *));
//   third = (struct node *)malloc(sizeof(struct node *));

//   head->data=2;
//   head->next=second;

//   second->data=6;
//   second->next=third;

//   third->data=9;
//   third->next=NULL;

//   printf("\nBefore deletion \n");
//   trversal(head);

//   printf("\nAfter deletion \n");
//   // head = deletionatfirst(head);
//   // head = deletionatlast(head);
//   // head = deletionatindex(head,2);
//   head = deletionatvalue(head,6);
//   trversal(head);

//   return 0;
// }


//Circuler linked list

// #include<stdio.h>
// #include<stdlib.h>

// struct node{
//   int data;
//   struct node *next;
// };

// void display(struct node *head){
//   struct node *ptr=head;
//   do{                                                                                              //do while loop is used for printing circuler linked list
//     printf("%d\n",ptr->data);
//     ptr=ptr->next;
//   }while(ptr!=head);
// }

// struct node * insertathead(struct node *head,int value){
//   struct node *ptr=(struct node *)malloc(sizeof(struct node *));                                   //create new pointer using DMA in heap
//   ptr->data=value;                                                                                 //simply assign value in it

//   struct node *p=head;
//   // do{
//   //   p=p->next;
//   // }while(p->next!=head);                                                                           //At this point p points to the last node of this circular linked list

//   while(p->next!=head){                                                                            //we also make while loop here but not in traverse(display)
//     p=p->next;
//   }
//   p->next=ptr;                                                                                     //keep all these in mind
//   ptr->next=head;
//   head=ptr;                                                                                        //here the new head is ptr
//   return head;

// }

// struct node * insertatend(struct node *head,int value){
//   struct node *ptr=(struct node *)malloc(sizeof(struct node *));                                   
//   ptr->data=value;                                                                                 

//   struct node *p=head;
//   // do{
//   //   p=p->next;
//   // }while(p->next!=head);                                                                           

//   while(p->next!=head){                                                                            
//     p=p->next;
//   }

//   p->next=ptr;                                                                                     
//   ptr->next=head;                                                                                    
//   return head;

// }

// int main(){
//   struct node *head;
//   struct node *second;
//   struct node *third;

//   head=(struct node*)malloc(sizeof(struct node*));
//   second=(struct node*)malloc(sizeof(struct node*));
//   third=(struct node*)malloc(sizeof(struct node*));

//   head->data=2;
//   head->next=second;

//   second->data=4;
//   second->next=third;
  
//   third->data=8;
//   third->next=head;

//   printf("Before insertion\n");
//   display(head);
//   head=insertathead(head,99);
//   head=insertatend(head,69);
//   printf("After insertion\n");
//   display(head);

//   return 0;
// }


//Doubly Linked Lists

// #include<stdio.h>
// #include<stdlib.h>

// struct node {
//   int data;
//   struct node *prev;
//   struct node *next;
// };

// void trversal_next(struct node *ptr){
//   while(ptr!=NULL){
//     printf("%d\n",ptr->data);
//     ptr=ptr->next;
//   }
// }

// void trversal_prev(struct node *ptr){
//   while(ptr!=NULL){
//     printf("%d\n",ptr->data);
//     ptr=ptr->prev;
//   }
// }

// // struct node* insert_index(struct node *head,int index,int num){
// //   struct node *ptr=(struct node*)malloc(sizeof(struct node*));                                     //create new node and assign data in it
// //   ptr->data=num;

// //   struct node *p=head;                                                                             //keep in mind we don't want to leave our head node
// //   struct node *q=head->next;
// //   for(int i=1;i<index-1;i++){
// //     p=p->next;                                                                                     //create two node second one is ahead of the first one so, we simply put new node between them 
// //     q=q->next;
// //   }

// //   p->next=ptr;
// //   ptr->next=q;

// //   return head;
// //   }

//                                             //OR

// struct node* insert_index(struct node *head,int index,int num){
//   struct node *ptr=(struct node*)malloc(sizeof(struct node*));
//   ptr->data=num;

//   struct node *p=head;
//   for(int i=1;i<index-1;i++){
//     p=p->next;
//   }

//   ptr->next=p->next;                                                                               //here we simply point ptr next to p next node
//   p->next=ptr;                                                                                     //p next node points to ptr node

//   return head;
//   }

//   void delete_index(struct node *head,int index){
//     struct node *p=head;
//     struct node *q=head->next;                                                                     //create two node and q will delete
//     for(int i=1;i<index-1;i++){
//       p=p->next;
//       q=q->next;
//     }
//       p->next=q->next;
//       free(q);
//       return head;
//   }

// int main(){

//   struct node *head=(struct node*)malloc(sizeof(struct node*));
//   struct node *second=(struct node*)malloc(sizeof(struct node*));
//   struct node *third=(struct node*)malloc(sizeof(struct node*));

//   head->data=5;
//   head->prev=NULL;
//   head->next=second;

//   second->data=7;
//   second->prev=head;
//   second->next=third;

//   third->data=9;
//   third->prev=second;
//   third->next=NULL;

//   trversal_next(head);
//   printf("\n");
//   trversal_prev(third);
//   printf("\n");

//   head=insert_index(head,3,66);
//   trversal_next(head);
//   printf("\n");

//   delete_index(head,3);
//   trversal_next(head);

//   return 0;

//   }