//Stack
//Stack Work on principle Last In First Out   or   First In Last Out

// #include <stdio.h>
// #include <stdlib.h>

// struct stack{
//     int size;
//     int top;
//     int *arr;                                                                                      //integer pointer to hold the address of the array. we dynamically allocate memory 
// };

// int isempty(struct stack *ptr){
//     if(ptr->top==-1){
//         return 1;
//     }
//     else {
//         return 0;
//         }
// }

// int isfull(struct stack *ptr){
//     if(ptr->top==ptr->size-1){
//         return 1;
//     }
//     else {
//         return 0;
//         }
// }

// int main(){
//     struct stack *s=(struct stack *)malloc(sizeof(struct stack *));                                //(keep in mind) this will give us the instence of strcut stack dynamically. and then we will use size, top, arr using arrow operator

//     s->size = 80;
//     s->top = -1;                                                                                   //default is -1 becuase at this point there is no element in array and its point non
//     s->arr=(int *)malloc(s->size * sizeof(int));                                                   //int beacuse we add integer numbers

//     //adding element manually
//     s->arr[0]=4;
//     s->top++;

//     //checking if stack is full
//     if(isfull(s)){                                                                                 //this will work when function return 1 same as 'isfull(s)==1'
//         printf("stack is full\n");
//     }
//     else{
//         printf("stack is not full\n");
//     }

//     //checking if stack is empty
//     if(isempty(s)){
//         printf("stack is empty\n");
//     }
//     else{
//         printf("stack is not empty\n");
//     }
    

//     return 0;
// }



//implimention of push, pop, peek, top, bottom in stack using array

// #include <stdio.h>
// #include <stdlib.h>

// struct stack{
//     int size;
//     int top;
//     int *arr;
// };

// // void display(struct stack *ptr){                                                                   //this display is not coorect because it does not valid for LIFO rule
// //     if(ptr->top==-1){                                                                              
// //         printf("no element\n");
// //     }
// //     else{
// //         for(int i=0;i<=ptr->top;i++){                                                              //(keep in mind) for display         
// //         printf("%d\n",ptr->arr[i]);
// //         }
// //     }
// // }

// void push(struct stack *ptr, int value){
//     if(ptr->top==ptr->size-1){                                                                     //Don’t forget to first check if our stack still has some space left to push elements
//         printf("stack is overflow \n");                                                            //ptr->top==ptr->size-1 here -1 because index start from 0.
//     }
//     else {
//         ptr->top++;                                                                                //here we first increment our top value by 1 and then add element on that space 
//         ptr->arr[ptr->top]=value;
//     }
// }

// int pop(struct stack *ptr){
//     if(ptr->top==-1){                                                                              //Don’t forget to first check if our stack still has some elements left to pop elements
//         printf("stack is underflow \n");
//     }
//     else {
//         int val=ptr->arr[ptr->top];                                                                //here we store our poped elemnt in variable beacuse we will return it
//         ptr->top--;                                                                                //simply decrement top value by 1, it will point previous element
//         return val;
//     }
// }

// int peek(struct stack *ptr,int i){                                                                 //Peek refers to looking for the element at a specific index in a stack. 
//     int arr_index=ptr->top-i+1;                                                                    //store the index of the array to be returned. This is just (top-position +1). (keep in mind) 
//     if(arr_index<0){
//         printf("stack in invalid\n");
//     }  
//     else{
//         return ptr->arr[arr_index];
//     }
// }

// int stack_top(struct stack *ptr){
//     return ptr->arr[ptr->top];
// }

// int stack_bottom(struct stack *ptr){
//     return ptr->arr[0];
// }



// int main(){
//     struct stack *sp=(struct stack *)malloc(sizeof(struct stack *));                               //(keep this in mind)allocate the structure in heap memory
//     sp->size=10;
//     sp->top=-1;
//     sp->arr=(int *)malloc(sp->size*sizeof(int *));

//     // printf("stact\n");
//     // display(sp);

//     // printf("after push\n");
//     push(sp,1);
//     push(sp,2);
//     push(sp,3);
//     push(sp,4);
//     push(sp,5);
//     push(sp,6);
//     push(sp,7);
//     push(sp,8);
//     push(sp,9);
//     push(sp,10);
//     // push(sp,11);                                                                                   //could not add because there will be no space
//     // display(sp);
    
//     // printf("after pop\n");
//     printf("poped element %d \n",pop(sp));                                                         //last element will be poped which is 10
//     printf("poped element %d \n",pop(sp));                                                         //new last element will be poped whic his 9
//     // display(sp);


//     printf("element at position %d is %d\n",3,peek(sp,3));                                         //this will print 6 beacuse 10 and 9 are poped and 6 is the 3rd element which works on LIFO

//     printf("Top most value of stack is %d \n",stack_top(sp));
//     printf("Bottom most value of stack is %d \n",stack_bottom(sp));


//     return 0;
// }



//Time complexities of other operations:
/*
isEmpty(): This operation just checks if the top member equals -1. This works in a constant time, hence, O(1).
isFull(): This operation just checks if the top member equals size -1. Even this works in a constant time, hence, O(1).
push(): Pushing an element in a stack needs you to just increase the value of top by 1 and insert the element at the index. This is again a case of O(1).
pop(): Popping an element in a stack needs you to just decrease the value of top by 1 and return the element we ignored. This is again a case of O(1).
peek(): Peeking at a position just returns the element at the index, (top - position + 1), which happens to work in a constant time. So, even this is an example of O(1).
top() and bottom(): Both these operations happen to work in a constant runtime, that is O(1). Because we are just accessing an element at an index, and that works in a constant time in an array.
So, basically all the operations we discussed follow a constant time complexity.
*/



//Implement Stack Using Linked List


// #include<stdio.h>
// #include<stdlib.h>

// struct node {
//     int data;
//     struct node *next;
// };

// int LinkedListTraversal(struct node *ptr){
//     while(ptr!=NULL){
//         printf("Element is %d\n",ptr->data);
//         ptr=ptr->next;
//     }
// }

// int isEmpty(struct node *top){
//     if(top==NULL){                                                                                 //just checks if our top element is NULL. 
//         return 1;
//     }
//     else{
//         return 0;
//     }
// }

// int isFull(struct node *top){
//     struct node *n=(struct node*)malloc(sizeof(struct node*));                                     //Create a new struct Node* pointer n, and assign it a new memory location in the heap. only if no more nodes are being created, return 1
//     if(n==NULL){
//         return 1;
//     }
//     else{
//         return 0;
//     }
// }

// struct node* push(struct node *top,int value){
//     if(isFull(top)){                                                                               //Check if the stack is already not full
//         printf("stack is Overflow");
//     }
//     else{
//         struct node *new=(struct node*)malloc(sizeof(struct node*));                               //Create a new struct Node* pointer new, and assign it a new memory location in the heap. so we can add value in it and link this node with top node
//         new->data=value;

//         new->next=top;
//         top=new;
//         return top;                                                                                //Return this pointer new, since this is our new top node.
//     }
// }

// int pop(struct node **top){                                                                        //here we use pointer of pointer, so that our head pointer in main() function will update with new top pointer                                                         
//     if(isEmpty(*top)){
//         printf("Stack is Underflow");
//     }
//     else{
//         struct node * new=*top;                                                                    //Create a new struct Node* pointer new, and make it point to the current top
//         int val=new->data;
//         *top=(*top)->next;
//         free(new);                                                                                 //Free the pointer new. And return val
//         return val;
//     }
// }


// int main(){
//     struct node *head=(struct node*)malloc(sizeof(struct node*));
//     head=NULL;

//     if(isEmpty(head)){
//         printf("Stack is Underflow\n");
//     }

//     if(isFull(head)){
//         printf("Stack is Overflow\n");
//     }

//     head=push(head,1);
//     head=push(head,2);
//     head=push(head,3);
//     head=push(head,4);
//     LinkedListTraversal(head);

//     // int deleted_val=pop(head);                                                                  //not work corredctly because we changed our head pointer on pop() function which doesn't change here. we have to return top pointer in order to work just like push() function but we had already return deleted element.
//     int deleted_val=pop(&head);                                                                    //(keep in mind) We’ll pass the reference of the current head pointer in the function. We are passing the reference this time, because we are not returning the updated top from the function.
//     printf("deleted element is %d\n",deleted_val);
//     LinkedListTraversal(head);


//     return 0;
// }



//Implementation of isempty, isfull, push, pop, peek, top, bottom in stack using linked list with help of global pointer decleration

/*
You must have observed we used the pointer to a pointer while popping elements from the stack.
We referenced and unreferenced twice. So, to avoid all these complexities, I still have a better
way to implement that thing. We can declare the top pointer globally. Earlier we used to declare
it under main. Declaring it globally gives its access to all our functions without passing them as a parameter.
*/


// #include<stdio.h>
// #include<stdlib.h>

// struct node {
//     int data;
//     struct node *next;
// };

// struct node* top = NULL;
 

// int LinkedListTraversal(struct node *ptr){
//     while(ptr!=NULL){
//         printf("Element is %d\n",ptr->data);
//         ptr=ptr->next;
//     }
// }

// int isEmpty(struct node *top){
//     if(top==NULL){                                                                                 
//         return 1;
//     }
//     else{
//         return 0;
//     }
// }

// int isFull(struct node *top){
//     struct node *n=(struct node*)malloc(sizeof(struct node*));                                     
//     if(n==NULL){
//         return 1;
//     }
//     else{
//         return 0;
//     }
// }

// struct node* push(struct node *top,int value){
//     if(isFull(top)){                                                                               
//         printf("stack is Overflow");
//     }
//     else{
//         struct node *new=(struct node*)malloc(sizeof(struct node*));                               
//         new->data=value;

//         new->next=top;
//         top=new;
//         return top;                                                                                
//     }
// }

// int pop(struct node *tp){                                                                          //(keep this in mind) this pointer name should be different the one use in globally   
//     if(isEmpty(tp)){
//         printf("Stack is Underflow");
//     }
//     else{
//         struct node * new=tp;                                                                    
//         int val=new->data;
//         top=tp->next;                                                                              //(keep this in mind) at this place globally top is updated
//         free(new);                                                                                 
//         return val;
//     }
// }

// int peek(int pos){
//     struct node *ptr=top;                                                                          //Since we have made the stack pointer global, we should not use that pointer to traverse; otherwise, we will lose the pointer to the top node. Rather create a new struct Node pointer ptr and give it the value of top.
//     for(int i=0;(i<pos-1&&ptr!=NULL);i++){                                                         //Run a loop from 0 to pos-1, since we are already at the first position. 
//         ptr=ptr->next;
//     }   
//     if(ptr!=NULL){                                                                                 //If the current pointer found the position and it is not equal to NULL, return the data
//         return ptr->data;                                                                   
//     }
//     else{
//         return -1;
//     }
// }

// int stack_top(){
//     return top->data;
// }

// int stack_bottom(){
//     struct node *ptr=top;
//     for(int i=0;ptr->next!=NULL;i++){                                                              //(keep in mind) here we check if next node is not NULL then only loop will run. if next node is NULL then loop stop and it will return that node data.
//         ptr=ptr->next;
//     }                                                                                
//     return ptr->data;                                                                   
    
// }



// int main(){

//     if(isEmpty(top)){
//         printf("Stack is Underflow\n");
//     }

//     if(isFull(top)){
//         printf("Stack is Overflow\n");
//     }

//     top=push(top,1);
//     top=push(top,2);
//     top=push(top,3);
//     top=push(top,4);
//     LinkedListTraversal(top);

//     // int deleted_val=pop(top);                                                                  
//     // printf("deleted element is %d\n",deleted_val);
//     // LinkedListTraversal(top);

//     printf("element at pos 4 is %d\n",peek(4));

//     printf("element at top is %d\n",stack_top());
//     printf("element at bottom is %d\n",stack_bottom());


//     return 0;
// }


/*NOTE-
we use struct stack in push() of linked list because we update our list and return that updated list.
we use void in push() of array beacause we already crerated the desired size and just insert value in that size. 
*/



//Parenthesis Checking

// #include<stdio.h>
// #include<stdlib.h>

// struct stack {
//     int size;
//     int top;
//     char* arr;
// };

// int isEmpty(struct stack *ptr){
//     if(ptr->top == -1){
//         return 1;
//     }
//     else{
//         return 0;
//     }
// }
// int isFull(struct stack *ptr){
//     if(ptr->top == ptr->size-1){
//         return 1;
//     }
//     else{
//         return 0;
//     }
// }
// void push(struct stack *ptr,int value){
//     if(isFull(ptr)){
//         printf("stack is overflow\n");
//     }
//     else{
//         ptr->top++;
//         ptr->arr[ptr->top]=value;
//     }
// }
// char pop(struct stack *ptr){
//     if(isEmpty(ptr)){
//         printf("stack is underflow\n");
//         return -1;
//     }
//     else{
//         int del=ptr->arr[ptr->top];
//         ptr->top--;
//         return del;
//     }
// }

// int Parenthesis_Checking(char *exp){                                                               //creating an integer function paranthesisMatch, and pass the reference to a character array(expression) exp in the function
//     struct stack *st=(struct stack*)malloc(sizeof(struct stack));                                  //(keep this in mind)create a stack pointer st 
//     st->size=100;                                                                                  //initilize the stack in here rather then in main()
//     st->top=-1;
//     st->arr=(char *)malloc(st->size * sizeof(char));                                               //assign the array pointer a memory location in the heap, because here we only store character

//     for(int i=0;exp[i]!='\0';i++){
//         if(exp[i]=='('){
//             push(st,'(');                                                                          //here we store '(' into st stack. that's why we take arr in char datatype
//         }
//         else if(exp[i]==')'){
//             if(isEmpty(st)){
//                 return 0;
//             }
//             pop(st);               
//             }
//     } 
//     if(isEmpty(st)){
//         return 1;
//     }
//     else{
//         return 0;
//     }
// }

// int main(){
//     char * exp="((8)(*--$$9))";
//     if(Parenthesis_Checking(exp)){
//         printf("Parenthesis is matching");
//     }
//     else{
//         printf("Parenthesis is not matching");
//     }
//     return 0;
// }



//Multiple Parenthesis Matching

// #include<stdio.h>
// #include<stdlib.h>

// struct stack {
//     int size;
//     int top;
//     char* arr;
// };

// int isEmpty(struct stack *ptr){
//     if(ptr->top == -1){
//         return 1;
//     }
//     else{
//         return 0;
//     }
// }
// int isFull(struct stack *ptr){
//     if(ptr->top == ptr->size-1){
//         return 1;
//     }
//     else{
//         return 0;
//     }
// }
// void push(struct stack *ptr,int value){
//     if(isFull(ptr)){
//         printf("stack is overflow\n");
//     }
//     else{
//         ptr->top++;
//         ptr->arr[ptr->top]=value;
//     }
// }
// char pop(struct stack *ptr){
//     if(isEmpty(ptr)){
//         printf("stack is underflow\n");
//         return -1;
//     }
//     else{
//         int del=ptr->arr[ptr->top];
//         ptr->top--;
//         return del;
//     }
// }
// int match(char a,char b){
//     if(a=='('&&b==')' || a=='{'&&b=='}' || a=='['&&b==']'){
//         return 1;
//     }
//     else{
//         return 0;
//     }
// }

// int Parenthesis_Checking(char *exp){
//     struct stack *st=(struct stack*)malloc(sizeof(struct stack));
//     st->size=100;
//     st->top=-1;
//     st->arr=(char *)malloc(st->size * sizeof(char));
//     char popped_char;

//     for(int i=0;exp[i]!='\0';i++){
//         if(exp[i]=='(' || exp[i]=='{' || exp[i]=='['){
//             push(st,exp[i]);                                                                       //here we store only exp[i] char, into st
//         }
//         else if(exp[i]==')' || exp[i]=='}' || exp[i]==']'){
//             if(isEmpty(st)){
//                 return 0;
//             }
//             popped_char=pop(st);                                                                   //here it popped open brackets from stack         
//             match(popped_char,exp[i]);                                                             //here it compare popped char with closed brackets which is in exp[i]
//             }
//     } 
//     if(isEmpty(st)){
//         return 1;
//     }
//     else{
//         return 0;
//     }
// }

// int main(){
//     char * exp="[(8-9)+{8/4}-[44*3]]";
//     if(Parenthesis_Checking(exp)){
//         printf("Parenthesis is balanced");
//     }
//     else{
//         printf("Parenthesis is not balanced");
//     }
//     return 0;
// }



// infix to postfix in stack
// #include<stdio.h>
// #include<stdlib.h>
// #include<string.h>

// struct stack {
//     int size;
//     int top;
//     char* arr;
// };

// int stackTop(struct stack* sp){
//     return sp->arr[sp->top];
// }
// int isEmpty(struct stack *ptr){
//     if(ptr->top == -1){
//         return 1;
//     }
//     else{
//         return 0;
//     }
// }
// int isFull(struct stack *ptr){
//     if(ptr->top == ptr->size-1){
//         return 1;
//     }
//     else{
//         return 0;
//     }
// }
// void push(struct stack *ptr,int value){
//     if(isFull(ptr)){
//         printf("stack is overflow\n");
//     }
//     else{
//         ptr->top++;
//         ptr->arr[ptr->top]=value;
//     }
// }
// char pop(struct stack *ptr){
//     if(isEmpty(ptr)){
//         printf("stack is underflow\n");
//         return -1;
//     }
//     else{
//         int del=ptr->arr[ptr->top];
//         ptr->top--;
//         return del;
//     }
// }
// int isoperator(char ch){
//     if(ch=='+'||ch=='-'||ch=='/'||ch=='*'){
//         return 1;
//     }
//     else{
//         return 0;
//     }
// }
// int precedence(char ch){
//     if(ch=='/'||ch=='*'){
//         return 3;
//     }
//     else if(ch=='+'||ch=='-'){
//         return 2;
//     }
//     else{
//         return 0;
//     }
// }
// char * infix_postfix(char *infix){
//     struct stack *sp=(struct stack *)malloc(sizeof(struct stack));                                 //Define a struct stack pointer variable sp. And give it the required memory in the heap. Create the instance...   here our operators wil be stored
//     sp->size=100;
//     sp->top=-1;
//     sp->arr=(char *)malloc(sp->size*sizeof(char));
//     char *postfix=(char *)malloc((strlen(infix)+1)*sizeof(char));                                  //Create a character array/pointer postfix, and assign it sufficient memory to hold all the characters of the infix expression in the heap

//     int i=0; //Track infix traversal
//     int j=0; //Track postfix traversal
//     while(infix[i]!='\0'){
//         if(!isoperator(infix[i])){                                                                 //because we need to store operand in postfix and operator in postfix stack
//             postfix[j]=infix[i];                                                                   //add that character into the postfix and increment both the counters by 1
//             i++;
//             j++;
//         }
//         else{
//             if(precedence(infix[i])>precedence(stackTop(sp))){                                     //stacktop because any operator first store in stack and assign top of the stack
//                 push(sp,infix[i]);                                                                 //push it inside the stack. //high precedence so push and low precedence so pop from stack which is sp
//                 i++;
//             }
//             else{
//                 postfix[j]=pop(sp);                                                                //pop the stackTop, and add it back into the postfix. Increment j by 1.
//                 j++;
//             }
//         }
//     }
//     while(!isEmpty(sp)){                                                                           //Reach the EOE, pop every element from the stack
//         postfix[j]=pop(sp);
//         j++;
//     }
//     postfix[j]='\0';
//     return postfix;
// }


// int main(){
//     char * exp="x-y/z-k*d";
//     printf("postfix is %s\n",infix_postfix(exp));
//     return 0;
// }
