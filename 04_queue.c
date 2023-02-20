//QUEUE

//implementing queue using array

// #include<stdio.h>
// #include<stdlib.h>

// typedef struct queue {
//     int size;
//     int f;                                                                                         //f to store the front end index
//     int r;                                                                                         //r to store the index of the rear end
//     int *arr;                                                                                      //integer pointer arr to store the address of the dynamically allocated array.
// }Queue;

// int isEmpty(Queue *q){
//     if(q->r==q->f)
//         return 1;
//     else
//         return 0;
// }
// int isFull(Queue *q){
//     if(q->r==q->size-1)
//         return 1;
//     else
//         return 0;
// }

// void enqueue(Queue *q,int val){
//     if(isFull(q))
//         printf("Queue Overflow\n");
//     else{
//         q->r++;
//         q->arr[q->r]=val;
//     }
// }
// int dequeue(Queue *q){
//     int num=-1;                                                                                     //here because if no element dequeue, so it simply return -1
//     if(isEmpty(q))
//         printf("Queue Underflow\n");
//     else{
//         q->f++;
//         num=q->arr[q->f];
//     }
//     return num;
// }

// int main(){
//     // Queue q;
//     // q.size=100;
//     // q.f=-1;                                                                                        
//     // q.r=-1;                                                                                        
//     // // q.f=q.r=-1;                                                                                 //or simply written this way
//     // q.arr=(int *)malloc(q.size*(sizeof(int)));                                                     //allocate memory in heap for arr 


//     // enqueue(&q,12);
//     // enqueue(&q,55);
//     // printf("delete element is %d\n",dequeue(&q));

//     ////        *************   OR   *************  above is written in simple, so use '.' and '&' when pass queue to function. and below is in pointer, so have to declare memory in heap, and use '->' and simply pass queue to function (keep in mind)

//     Queue *q=(Queue *)malloc(sizeof(Queue));
//     q->size=100;
//     q->f=-1;
//     q->r=-1;
//     // q->f=q->r=-1;                                                                                 
//     q->arr=(int *)malloc(q->size*(sizeof(int)));

//     enqueue(q,12);
//     enqueue(q,55);
//     printf("delete element is %d\n",dequeue(q));


//     return 0;
// }



//Circular Queue
/*Circular increment lets us access the queue indices circularly, which means, after we finish visiting the 7th index in the above illustration, we again come at the zeroth index.
isEmpty = (q->r==q->f)         same
isFull = (q->r+1%q->size)==q->f          Use circular increment (modulus) means increment q->r by 1 but cirecular (keep in mind)
enqueue = [simple queue q->r++]     [circular queue q->r=(q->r+1)%q->size]   same but here q->r circular increment
dequeue = [simple queue q->f++]     [circular queue q->f=(q->f+1)%q->size]   same but circular increment
*/

// #include<stdio.h>
// #include<stdlib.h>

// typedef struct queue {
//     int size;
//     int f;                                                                                         //f to store the front end index
//     int r;                                                                                         //r to store the index of the rear end
//     int *arr;                                                                                      //integer pointer arr to store the address of the dynamically allocated array.
// }circularQueue;

// int isEmpty(circularQueue *q){
//     if(q->r==q->f)
//         return 1;
//     else
//         return 0;
// }
// int isFull(circularQueue *q){
//     if((q->r+1%q->size)==q->f)                                                                     //(r element of q) +1 is equal to the (f element of q). use circular increment
//         return 1;
//     else
//         return 0;
// }

// void enqueue(circularQueue *q,int val){
//     if(isFull(q))
//         printf("Queue Overflow\n");
//     else{
//         q->r=(q->r+1)%q->size;
//         q->arr[q->r]=val;
//     }
// }
// int dequeue(circularQueue *q){
//     int num=-1;                                                                                     //here because if no element dequeue, so it simply return -1
//     if(isEmpty(q))
//         printf("Queue Underflow\n");
//     else{
//         q->f=(q->f+1)%q->size;
//         num=q->arr[q->f];
//     }
//     return num;
// }
// void display(circularQueue *q){                                                                    //made just for check
//     for(int i=q->f;i!=q->r;i=(i+1)%q->size){
//         printf("%d\n",q->arr[i]);
//     }
// }

// int main(){
//     circularQueue *q=(circularQueue *)malloc(sizeof(circularQueue));
//     q->size=5;
//     q->f=q->r= 0;                                                                                  //initialize circular queues’ f and r with 0. Since -1 is unreachable in circular incrementation                                                                                 
//     q->arr=(int *)malloc(q->size*(sizeof(int)));

//     enqueue(q,12);                                                                                 //if q->size is 5 then only 4 value can be stored because q->f always have one empty space in it 
//     enqueue(q,7);
//     enqueue(q,5);
//     enqueue(q,4);
//     printf("delete element is %d\n",dequeue(q));
//     // printf("delete element is %d\n",dequeue(q));
//     // printf("delete element is %d\n",dequeue(q));
//     // printf("delete element is %d\n",dequeue(q));

//     display(q);

//     return 0;
// }



//implementing queue using Linked list


// #include<stdio.h>
// #include<stdlib.h>

// typedef struct node{
//     int data;
//     struct node *next;
// }Node;

// Node *f = NULL;                                                                                    //we have creatd f and r node which helps to do operations in queue
// Node *r = NULL;                                                                                    //would be used to mark the front and the rear ends

// void display(Node *ptr){
//     printf("display of queue data\n");
//     while(ptr!=NULL){
//         printf("%d\n",ptr->data);
//         ptr=ptr->next;
//     }
// }

// int isEmpty(){
//     if(f==r)
//         return 1;
//     return 0;
// }

// int isFull(){
//     Node *n = (Node*)malloc(sizeof(Node));
//     if(n==NULL)
//         return 1;
//     return 0;
// }

// void enqueue(int val){
//     Node *n = (Node*)malloc(sizeof(Node));                                                        //assign its memory in heap dynamically using mallo
//     if(isFull())
//         printf("queue overflow\n");
//     else{
//         n->data=val;
//         n->next=NULL;
//         if(f==NULL)                                                                                //at initially both f and r are NULL (special case)
//             f=r=n;
//         else{
//             // n=r->next;                                                                          //even it look same but this condition will not work thats why below condition will work
//             r->next=n;
//             r=n;                                                                                   //r equal to n since n becomes our new rear end
//         }
//     }
// }

// int dequeue(){
//     int val=-1;
//     if(isEmpty())
//         printf("queue underflow\n");
//     else{
//         Node *p=f;                                                                                //created a new Node pointer and assign it to f so, that we free() it in the end 
//         f=f->next;
//         val=p->data;
//         free(p);
//        }
//     return val;
// }

// int main(){
//     enqueue(1);
//     enqueue(2);
//     enqueue(3);
//     enqueue(4);
//     enqueue(5);
//     printf("dequeue element %d\n",dequeue());
//     printf("dequeue element %d\n",dequeue());
//     display(f);                                                                                    //f because its the head of our queue
//     return 0;
// }



//Double Ended queue using Linked List

// #include <stdio.h>
// #include <stdlib.h>

// typedef struct node{
//     int data;
//     struct node *next;    
// }Node;

// Node * f = NULL;
// Node * r = NULL;

// int display(Node *ptr){
//     while(ptr!=NULL){
//         printf("%d\n",ptr->data);
//         ptr=ptr->next;
//     }
// }

// int isEmpty(){
//     if(f==r)
//         return 1;
//     return 0;
// }

// int isFull(){
//     Node *n=(Node*)malloc(sizeof(Node));
//     if(n==NULL)
//         return 1;
//     return 0;
// }

// void enqueueR(int val){
//     Node *n=(Node*)malloc(sizeof(Node));
//     if(isFull())
//         printf("queue overflow\n");
//     else{
//         n->data=val;
//         n->next=NULL;
//         if(f==NULL){
//             f=r=n;
//         }
//         else{
//             r->next=n;
//             r=n;
//         }
//     }
// }

// void enqueueF(int val){                                                                           //we have already understand enqueue at end but its little bit of change enqueue at start
//     Node *n=(Node*)malloc(sizeof(Node));
//     if(isFull())
//         printf("queue overflow\n");
//     else{
//         n->data=val;
//         if(f==NULL){
//             return ;
//         }
//         else{
//             n->next=f;
//             f=n;
//         }
//     }
// }

// int dequeueF(){
//     int val=-1;
//     if(isEmpty())
//         printf("queue underflow\n");
//     else{
//         Node *ptr=f;
//         f=f->next;
//         val=ptr->data;
//         free(ptr);
//     }
//     return val;
// }

// int dequeueR(){                                                                                   //we have already understand dequeue at first but its little bit of change dequeue at end
//     int val=-1;
//     if(isEmpty())
//         printf("queue underflow\n");
//     else{
//         Node *ptr=f;
//         while(ptr->next!=r){                                                                      
//             ptr=ptr->next;
//         }
//         ptr->next=NULL;
//         val=r->data;
//         r=ptr;
//     }
//     return val;
// }


// int main(){
//     enqueueR(1);
//     enqueueR(2);
//     enqueueR(3);
//     enqueueR(4);

//     dequeueF();
//     dequeueR();

//     enqueueF(11);
//     enqueueF(22);

//     display(f);
//     return 0;
// }







