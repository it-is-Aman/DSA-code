//Binery Tree

/*
We use the concept of doubly-linked lists to represent a node.
The left pointer of this node points to the left child and the right pointer points to the right child,
and if there is no left or right child, we represent that using a NULL.
*/


// Creating node in Binery tree


// #include<stdio.h>
// #include<stdlib.h>

// typedef struct node{
//     int data;
//     struct node *left;
//     struct node *right;
// }NODE;

// NODE * Creat_Node(int val){

//     NODE *node = (NODE *)malloc(sizeof(NODE));                                                     //cerating a node pointer and allocating memory in heap                                                 
//     node->data=val;                                                                                //setting the data
//     node->left=NULL;                                                                               //setting the left children to NULL     
//     node->right=NULL;                                                                              //setting the right children to NULL     

//     return node;                                                                                   //finally return the created node
// }

// int main(){
//     /*
//     Method 1 of Constructing Binary tree node

//     NODE *root = (NODE *)malloc(sizeof(NODE));                                                     //constructing root node
//     root->data=7;
//     root->left=NULL;
//     root->right=NULL;

//     NODE *a1 = (NODE *)malloc(sizeof(NODE));                                                       //constructing second node                         
//     a1->data=3;
//     a1->left=NULL;
//     a1->right=NULL;

//     NODE *a2 = (NODE *)malloc(sizeof(NODE));                                                       //constructing third node                         
//     a2->data=4;
//     a2->left=NULL;
//     a2->right=NULL;

//     root->left=a1;
//     root->right=a2;
//     */

//     //Method 2 of Constructing Binary tree node using function
//     NODE * root=Creat_Node(7);
//     NODE * a1=Creat_Node(3);
//     NODE * a2=Creat_Node(4);

//     // Linking the root node with left and right children
//     root->left=a1;
//     root->right=a2;

//     return 0;
// }




// Traversal in pre-order, inorder, post-order
/*
    Pre-order =  node -> left tree -> right tree
    In-order =  left tree -> node -> right tree
    Post-order =    left tree -> right tree -> node
*/

// #include<stdio.h>
// #include<stdlib.h>

// typedef struct node{
//     int data;
//     struct node* left;
//     struct node* right;
// }NODE;

// NODE * create_Node(int val){
//     NODE* node=(NODE*)malloc(sizeof(NODE));
//     node->data=val;
//     node->left=NULL;
//     node->right=NULL;

//     return node;
// }

// void preOrder(NODE* node){                                                                         //execute recursively like Pre-order condition
//     if(node!=NULL){                                                                                //only work if node are not NULL
//         printf("%d ",node->data);                                                                  //first print value of node then 
//         preOrder(node->left);                                                                      //function execute recursively and work on left sub-tree then
//         preOrder(node->right);                                                                     //function execute recursively and work on right sub-tree
//     }
// }
// void inOrder(NODE* node){                                                                          //execute recursively like In-order condition
//     if(node!=NULL){
//         inOrder(node->left);                                                                       
//         printf("%d ",node->data);                                                                       
//         inOrder(node->right);                                                                       
//     }
// }
// void postOrder(NODE* node){                                                                        //execute recursively like Post-order condition
//     if(node!=NULL){
//         postOrder(node->left);
//         postOrder(node->right);
//         printf("%d ",node->data);
//     }
// }

// int main(){

//     NODE* root=create_Node(7);

//     NODE* row1=create_Node(1);
//     NODE* row2=create_Node(2);

//     NODE* row1_row1=create_Node(5);
//     NODE* row1_row2=create_Node(6);

//     root->left=row1;
//     root->right=row2;

//     row1->left=row1_row1;
//     row1->right=row1_row2;

//     // Finally The tree looks like this:
//     //      7
//     //     / \
//     //    1   2
//     //   / \
//     //  5   6  

//     printf("Preorder = ");
//     preOrder(root);
//     printf("\nInorder = ");
//     inOrder(root);
//     printf("\nPostorder = ");
//     postOrder(root);

//     return 0;
// }





//Check whether Binary tree is Binary search tree or not

/* Reprentation of correct Binary Search Tree

//                     (7) [min,max]                         here min=INT_MIN , max=INT_MAX
//                   /       \
//                  /         \
//              (3)[min,7]   (9)[7,max]                       here node(3) value is not <=min neither >=7  so, it return 1 (means BST)
//               /   \                                        if  node contain 12 instead of 3 then value is not <=min but >=7 so, return 0 (means not a BST)
//              /     \
//        (1)[min,3]  (6)[3,max] 

// (keep in mind) each node->data should be under [ __ , __ ] range      whether [min value , max value]



//                Not a Binary Search Tree
//                  (7) [min,max]
//                   /       \
//                  /         \
//              (13)[min,7]   (9)[7,max]                      here 13 is not <=min but >=7 so its not a Binary Search tree (condition false)
//               /   \                                        
//              /     \
//        (1)[min,3]  (6)[3,max] 

*/


// #include<stdio.h>
// #include<limits.h>
// #include<stdlib.h>

// typedef struct node{
//     int data;
//     struct node* left;
//     struct node* right;
// }NODE;

// NODE * create_Node(int val){
//     NODE* node=(NODE*)malloc(sizeof(NODE));
//     node->data=val;
//     node->left=NULL;
//     node->right=NULL;

//     return node;
// }

// int isBST(NODE* node,int min,int max){
//     if(node==NULL){                                                                                //if node is NULL so it simply return 1
//         return 1;
//     }
//     else if((node->data <= min)||(node->data >= max)){                                             //( || ) OR operator because if any child of node is minimum or maximum than node->data. so, simply it doesn't BST
//         return 0;
//     }

//     //first we call function recursively on left sub-tree and another for right sub-tree     
//     //left sub-tree so, that node data should be in [min , node->data] range..    and node->data would be the parent node data and it compare with their children node data
//     //right sub-tree so, that node data should be in [node->data , max] range..
//     //if both condition satisfied. so, it return 1.

//     else{
//         return ( isBST(node->left,min,node->data) && isBST(node->right,node->data,max) );          
//     }
// }

// int main(){

//     NODE* root=create_Node(7);
//     NODE* A1=create_Node(3);
//     NODE* A2=create_Node(9);

//     NODE* B1=create_Node(1);
//     NODE* B2=create_Node(6);

//     //linking root node
//     root->left=A1;
//     root->right=A2;

//     A1->left=B1;
//     A1->right=B2;

//     // Finally The Binary Search tree looks like this:
//     //      7
//     //     / \
//     //    3   9
//     //   / \
//     //  1   6 

//     if(isBST(root,INT_MIN,INT_MAX)){
//         printf("It's a Binary tree");
//     }
//     else{
//         printf("Not a Binary tree");
//     }

//     return 0;
// }





//Searching in Binery search tree


// #include<stdio.h>
// #include<stdlib.h>

// typedef struct node{
//     int data;
//     struct node * left;
//     struct node * right;
// }NODE;

// NODE* create_Node(int val){
//     NODE* node=(NODE*)malloc(sizeof(NODE));
//     node->data=val;
//     node->left=NULL;
//     node->right=NULL;
//     return node;
// }

// NODE* search_1(NODE* node,int key){                                                                //this will return that node where value stores

//     if(key==node->data){                                                                           //if the node we are currently at has the data element equal to the key then return current node
//         return node;
//     }
//     else if(key<node->data){                                                                       //if 'val' less than node->data so, we would reduce our search space and recursively start searching in the left subtree.
//         return search_1(node->left,key);
//     }
//     else if(key>node->data){                                                                       //if 'val' greater than node->data so, we would reduce our search space and recursively start searching in the right subtree.             
//         return search_1(node->right,key);
//     }
//     else{                                                                                          //we haven’t found our key, and we‘ll simply return NULL.
//         return NULL;
//     }
// }

// NODE* search_iterative(NODE* node,int key){
//     while(node!=NULL){                                                                             //run until our node becomes NULL, or we find the key and return from the function.
//         if(key==node->data){                                                                           
//             return node;
//         }
//         else if(key<node->data){                                                                       
//             node=node->left;                                                                       //we will make the root node pointer now point to the left child of the root,
//         }
//         else if(key>node->data){                                                                       
//             node=node->right;
//         }
//     }
//     return NULL;                                                                                   //if coouldn’t find the key, we would return NULL.
// }

// int main(){

//     NODE* root=create_Node(7);
//     NODE* A1=create_Node(3);
//     NODE* A2=create_Node(9);

//     NODE* B1=create_Node(1);
//     NODE* B2=create_Node(6);

//     //linking root node
//     root->left=A1;
//     root->right=A2;

//     A1->left=B1;
//     A1->right=B2;

//     // Finally The Binary Search tree looks like this:
//     //      7
//     //     / \
//     //    3   9
//     //   / \
//     //  1   6 

//     /*Method 1 for searching -> recursive approach, you start with the root and compare your key with the root
//                                 node’s data,and if it's smaller than the key, you select the whole left subtree
//                                 and start searching in it thinking of it as another smaller tree.
//     */
//     // NODE* ptr =search_1(root,1);
//     // if(ptr!=NULL){
//     //     printf("Found %d",ptr->data);
//     // }
//     // else{
//     //     printf("Not Found ");
//     // }

//     /*Method 2 for searching is iterative -> iterative approach, we have the tree intact the whole time. We just make a pointer
//                                              run from the root to the place we expect our key to be.
//     */
//     NODE* ptr =search_iterative(root,0);
//     if(ptr!=NULL){
//         printf("Found %d",ptr->data);
//     }
//     else{
//         printf("Not Found ");
//     }


//     return 0;
// }




//Insertion in BST


// #include<stdio.h>
// #include<stdlib.h>

// typedef struct node{
//     int data;
//     struct node* left;
//     struct node* right;
// }NODE;

// NODE* create_Node(int val){
//     NODE* node=(NODE*)malloc(sizeof(NODE));
//     node->data=val;
//     node->left=NULL;
//     node->right=NULL;

//     return node;
// }

// void insertBST(NODE* root, int key){
//     //two struct pointers to traverse through the array. One of them would be our root which we would traverse through the nodes,
//     //and the other one would be prev which stores the pointer to the previous root

//     NODE* prev=NULL;                                                                               
//     while(root!=NULL){
//         prev=root;                                                                                 //stores the pointer to the previous root and assume root at 3 so prev=root and then condition will check if loop end so root become NULL but, prev store that node means (previous node) which helps to link new_node                                              
//         if(key==root->data)
//             return;                                                                                //acts like break statement but in function
//         else if(key>root->data)                                                                    
//             root=root->right;                                                                      //we will check left side of root
//         else if(key<root->data)                                                                    
//             root=root->left;                                                                       //if the element you want to insert is less than the current root.Then update the root to the left element of the struct root
//     }
//     NODE* new_node=create_Node(key);                                                               //we create new node which store our key value and that are going to be store in BST
//     if(key>prev->data)                                                                             //if key > previous node data so, link new_node to right side of prev node
//         prev->right=new_node;
//     else if(key<prev->data)                                                                        //if key < previous node data so, link new_node to left side of prev node
//         prev->left=new_node;        
// }

// int main(){
//     NODE* root=create_Node(7);
//     NODE* A1=create_Node(3);
//     NODE* A2=create_Node(9);

//     NODE* B1=create_Node(1);
//     NODE* B2=create_Node(6);

//     root->left=A1;
//     root->right=A2;

//     A1->left=B1;
//     A1->right=B2;

// // Finally The Binary Search tree looks like this:
// //     //      7
// //     //     / \
// //     //    3   9
// //     //   / \
// //     //  1   6 

//     insertBST(root,4);
//     printf("%d ",root->left->right->left->data);

//     return 0;
// }




//Deletion in BST

// #include<stdio.h>
// #include<stdlib.h>

// typedef struct node{
//     int data;
//     struct node* left;
//     struct node* right;
// }NODE;

// NODE* create_Node(int val){
//     NODE* node=(NODE*)malloc(sizeof(NODE));

//     node->data=val;
//     node->left=NULL;
//     node->right=NULL;

//     return node;
// }

// void inorder(NODE* node){
//     if(node!=NULL){
//         inorder(node->left);
//         printf("%d ",node->data);
//         inorder(node->right);
//     }
// }

// NODE* inOrderPredecessor(NODE* root){                                                              //Inorder predecessor of a node is the rightmost node of its left subtree.
//     root=root->left;
//     while(root->right!=NULL){                                                                      //we find root not their null so loop run till root->right!=NULL  not  root!=NULL
//         root=root->right;
//     }
//     return root;
// }

// NODE* deleteBST(NODE* root,int key){
//     NODE* iPre;
//     if(root==NULL){                                                                                //if node is NULL so simply return NULL
//         return NULL;
//     }
//     if(root->left==NULL && root->right==NULL){                                                     //if both left and right child are NULL means node is leaf node so simply free it and return NULL
//         free(root);
//         return NULL;
//     }

//     //searching for the node to be deleted
//     if(key > root->data){
//         root->right = deleteBST(root->right,key);                                                  //key greater than the root node’s data, simply recursively call the function to its right subtree, and pass the same value into it                                                                    
//     }
//     else if(key < root->data){
//         root->left = deleteBST(root->left,key);                                                    //same as here, key less than root node's data, We do this until we reach the node we want to delete, or to the NULL                                                            
//     }
//     //deletion strategy when the node is found
//     else{                                                                                                               //After doing so much recursion. In the end key==root->data so, 2nd if ladder work means we found leaf node and it will return NULL. then other function run recursively. 
//         iPre=inOrderPredecessor(root);                                                             //find the Inorder predecessor of the root node you want to delete and store it in a struct node pointer iPre....  here we have choice to choose b/w inorder pre or post predecessor
//         root->data=iPre->data;                                                                     //just copy the data of that predecessor node to our root node. And call the deleteNode function recursively to the left subtree of the root node, and with the value of the InOrder predecessor’s data.
//         root->left=deleteBST(root->left,iPre->data);                                               //the InOrder predecessor of a node always lies on the left subtree of the node. And since you have replaced your root node with its InOrder predecessor, you have to now delete it from the left subtree. here we go iPre->left because we choose inorder pre

//     }
//     return root;
// }

// int main(){
//     NODE* root=create_Node(7);
//     NODE* A1=create_Node(3);
//     NODE* A2=create_Node(9);

//     NODE* B1=create_Node(1);
//     NODE* B2=create_Node(6);

//     root->left=A1;
//     root->right=A2;

//     A1->left=B1;
//     A1->right=B2;

// // Finally The Binary Search tree looks like this:
// //     //      7
// //     //     / \
// //     //    3   9
// //     //   / \
// //     //  1   6 

//     inorder(root);
//     deleteBST(root,3);
//     printf("\n");
//     inorder(root);


//     return 0;
// }



//AVL tree

// #include<stdio.h>
// #include<stdlib.h>

// typedef struct node{
//     int key;
//     struct node* left;
//     struct node* right;
//     int height;                                                                                    //height of that node for the ease of calculating the absolute balance factor
// }NODE;

// int getHeight(NODE *n){                                                                            //pass the pointer to the struct node you want to get the height of as the only parameter
//     if(n==NULL){
//         return 0;
//     }
//     return n->height;
// }

// int max(int a,int b){
//     return (a>b)?a:b;
// }

// NODE * createNode(int key){
//     NODE* node=(NODE*)malloc(sizeof(NODE));
//     node->key=key;
//     node->left=NULL;
//     node->right=NULL;
//     node->height=1;                                                                                // Now, set the height element of this node as 1, because any new node would be a leaf node that has a height of 1
//     return node;
// }

// //three most important functions of all when we implement the AVL tree. First is the getBalanceFactor, the second is the leftRotate and the third is the rightRotate.

// int getBalanceFactor(NODE *n){
//     if(n==NULL){
//         return 0;
//     }
//     return (getHeight(n->left) - getHeight(n->right));                                               //subtracting the height of the right child with that of the left child of the node
// }

// //left and right rotate illustration
// /*
//             x                                                 y
//           /   \                left rotation ->             /   \
//         T1     y                                           x     T3
//              /   \            <- right rotation          /   \
//            T2     T3                                    T1    T2

// creating leftRotate and rightRotate function by looking same as these diagram
// */

// NODE* leftRotate(NODE *x){                                                                         //x is the root node initially
//     NODE* y = x->right;                                                                            //initialize y and t2
//     NODE* T2 = y->left;

//     //after rotation x and t2 will change their position
//     y->left=x;                                                      
//     x->right=T2;

//     x->height=max(getHeight(x->right),getHeight(x->left))+1;                                       //Height of x becomes one added to the maximum of the heights of both of its children
//     y->height=max(getHeight(y->right),getHeight(y->left))+1;                                       //Height of y becomes one added to the maximum of the heights of both of its children

//     return y;                                                                                      //since y becomes the new root for the subtree
// }

// NODE* rightRotate(NODE *y){                                                                        //y is the root node initially
//     NODE* x = y->left;                                                                             //initialize x and t2
//     NODE* T2 = x->right;

//     //after rotation y and t2 will change their position
//     x->right=y;                                                      
//     y->left=T2;

//     x->height=max(getHeight(x->right),getHeight(x->left))+1;                                       //Height of x becomes one added to the maximum of the heights of both of its children
//     y->height=max(getHeight(y->right),getHeight(y->left))+1;                                       //Height of y becomes one added to the maximum of the heights of both of its children

//     return x;                                                                                      //since x becomes the new root for the subtree
// }

// NODE * insert(NODE *node, int key){
//     if(node == NULL){
//         return createNode(key);                                                                    //if node is NULL so createNode and insert it in tree
//     }

//     if(key < node->key){                                                                            //simple insertion just like BST
//         node->left = insert(node->left,key);
//     }
//     else if(key > node->key){
//         node->right = insert(node->right,key);
//     }
    

// //Once this new node gets inserted, the balance of the tree might get disturbed, so we would first create an integer variable bf, and store in it the balance factor of the current node we are on while backtracking. And if this node gets imbalanced, four of the possible cases arise

//     node->height = 1 + max(getHeight(node->left),getHeight(node->right));                            //we are insertion from leaf node and keep incrementing from leaf node (don't know this)
//     int bf = getBalanceFactor(node);                                                               //this give us the balance factor which help in these 4 cases

//     //left left case
//     if(bf > 1 && key < node->left->key){                                                           //bf > 1 means left child has more node because we did bf(left - right), new node has data less than the data of the left child of the node, so LL rotation
//         return rightRotate(node);                                                                  //hence we call the rightRotate function once to fix this disturbance. 
//     }
//     //right right case
//     if(bf < -1 && key > node->right->key){                                                         //bf <-1, new node has data greater than the data of the right child of the node, so RR rotation
//         return leftRotate(node);                                                                   //hence we call the leftRotate function once to fix this disturbance. 
//     }
//     //left right case
//     if(bf > 1 && key > node->left->key){                                                           
//         node->left = leftRotate(node->left);                                                       //we call first the leftRotate function passing the left subtree and then call the rightRotate function on this updated node to fix this disturbance. 
//         return rightRotate(node);                                                                  
//     }
//     //right left case
//     if(bf < -1 && key < node->right->key){                                                         
//         node->right = rightRotate(node->right);                                                    //we call first the rightRotate function passing the right subtree and then call the leftRotate function on this updated node to fix this disturbance. 
//         return leftRotate(node);                                                                   
//     }
//     return node;
// }
// //preOrder traversal function to see how our tree would get all balanced after all the insertions
// void preOrder(NODE *root){
//     if(root!=NULL){
//         printf("%d ",root->key);
//         preOrder(root->left);
//         preOrder(root->right);
//     }
// }

// int main(){
//     NODE * root=NULL;

//     root=insert(root,1);
//     root=insert(root,2);
//     root=insert(root,4);
//     root=insert(root,5);
//     root=insert(root,6);
//     root=insert(root,3);
//     preOrder(root);

//     return 0;
// }




// BFS spanning tree

// #include<stdio.h>
// #include<stdlib.h>

// typedef struct queue{
//     int size;
//     int f,r;
//     int *arr;
// }QUEUE;

// int isEmpty(QUEUE *q){
//     if(q->r==q->f){
//         return 1;
//     }
//     return 0;
// }
// int isFull(QUEUE *q){
//     if(q->r==q->size-1){
//         return 1;
//     }
//     return 0;
// }
// void enQueue(QUEUE *q,int val){
//     if(!isFull(q)){
//         q->r++;
//         q->arr[q->r]=val;
//     }
// }
// int deQueue(QUEUE *q){
//     int num=-1;
//     if(!isEmpty(q)){
//         q->f++;
//         num=q->arr[q->f];
//     }
//     return num;
// }


// int main(){

//     QUEUE *q;
//     q->size=100;
//     q->r=q->f=-1;
//     q->arr=(int*)malloc(q->size*sizeof(int));

//     // BFS Implementation

//     //which we will use to traverse the graph
//     int node;

//     //which node we are current at
//     int i=0;

//     //integer array visited to store the status of a node (of size 7 here), no node is already visited when we first start, therefore we’ll fill this array with all zeros.
//     int visited[7]={0,0,0,0,0,0,0};

//     //adjacency matrix corresponding to the graph
//     int adj[7][7] = {
//         {0,1,1,1,0,0,0},
//         {1,0,1,0,0,0,0},
//         {1,1,0,1,1,0,0},
//         {1,0,1,0,1,0,0},
//         {0,0,1,1,0,1,1},
//         {0,0,0,0,1,0,0}, 
//         {0,0,0,0,1,0,0} 
//     };

//     //we would print the source node we have chosen, here node 1.
//     printf("%d",i);

//     //Also, mark this node visited, which means make the ith index of the visited array 1.
//     visited[i]=1;

//     //since we are now interested in exploring the nodes connected to this source node, we would first enqueue this node into the queue q.
//     enQueue(q,i);                                                                                  //enqueue i for exploration

//     //pluck the top element of the queue using dequeue and store it in an integer variable node. Run another for loop using j as the iterator, and since the size of our graph is 7, we’ll make this loop run from 0 to 7.
//     //Now, every time we find edges node & j connected (that is cell a[node][j] equal to 1) and the node j unvisited, we mark it visited, and enqueue this newly visited node j in the queue. We'll print these nodes 
//     while(!isEmpty(q)){
//         int node=deQueue(q);
//         for(int j=0;j<7;j++){
//             if(adj[node][j]==1 && visited[j]==0){
//                 printf("%d",j);
//                 visited[j]=1;                                                                      //this will put j=visited 
//                 enQueue(q,j);                                                                      //enqueue j for exploration  //enqueue j value and repeat so, after that it enqueue all j value which is connected with i. 
//             }                                                                                      //and in next loop it dequeue first j value and perform operation into them. cycle repeat ...
//         }
//     }

//     return 0;
// }



// DFS spanning tree

// #include<stdio.h>
// #include<stdlib.h>

// int visited[7]={0,0,0,0,0,0,0};                                                                    //we define it globally 
// int adj[7][7] = {
//         {0,1,1,1,0,0,0},
//         {1,0,1,0,0,0,0},
//         {1,1,0,1,1,0,0},
//         {1,0,1,0,1,0,0},
//         {0,0,1,1,0,1,1},
//         {0,0,0,0,1,0,0}, 
//         {0,0,0,0,1,0,0} 
// };

// //create a void function DFS which will have the node i we want to visit as the only parameter.
// void DFS(int i){
//     //Inside that function, since that node which the function received as the parameter is the one to be visited now, we would mark it visited and print it at the same time
//     printf("%d ",i);
//     visited[i]=1;

//     //If any of them is not visited and there is an edge in between i and j, we would recursively call DFS passing this node j. 
//     for(int j=0;j<7;j++){
//         if(adj[i][j]==1 && visited[j]==0){
//             DFS(j);
//         }
//     }
// }

// int main(){
//     // DFSImplementation
//     DFS(0);                                                                                        //we wants to start from 0 node

//     return 0;
// }
