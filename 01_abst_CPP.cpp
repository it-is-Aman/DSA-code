//DSA


//ADT


// #include <iostream>

// using namespace std;

// class myADT{
//     private:
//         int total_size;
//         int used_size;
//         int *ptr;
//     public :
//         myADT(int total,int used){                                                                 //this constructor create total size and used size sapce initially
//             total_size=total;
//             used_size=used;
//             ptr=new int[total];                                                                    //'total' number of sapce created and ptr points to the first member
//         }
//         void set(void){
//             int n;
//             for(int i=0;i<used_size;i++){                                                          //already in same class so used_size can be accessed
//                 cout<<"enter "<< i+1 <<" value"<<endl;
//                 cin>>n;
//                 ptr[i]=n;                                                                          //value will be stored on that specific ptr location 'if ptr[1] means it points 2 position'
//             }
//         }
//         void insert(void){
//             int ins_pos, ins_val;
//             int temp;
//             cout<<"which position you want to insert"<<endl;
//             cin>>ins_pos;
//             cout<<"enter insert value "<<endl;
//             cin>>ins_val;
//             for(int i=0;i<total_size;i++){                                                          
//                 if((i+1)==ins_pos){                                                                //this loop for edit the value of specific poistion and store it in the end block
//                     temp=ptr[i];
//                     ptr[i]=ins_val;
//                     ptr[used_size]=temp;
//                 }                                                                  
//             }
//         }

//         void display(void){
//             for(int i=0;i<total_size;i++){
//                 cout<< i+1 <<" is "<<ptr[i]<<endl;
//             }
//         }
// };

// int main(){
//     myADT adt1(10,4);
//     adt1.set();
//     adt1.display();

//     adt1.insert();
//     adt1.display();
//     return 0;
// }



// Array travertion, insertion and delection


// #include <iostream>

// using namespace std;

// class array{
//     private:
//         int arr[10]={1,2,3,4,5,6,7};
//         int total_size=10;
//         int used_size=7;
        
//     public:
//         void display(void){                                                                        //for display or travertion
//             for (int i=0;i<used_size;i++){
//                 cout<<arr[i]<<" ";
//             }
//             cout<<endl;
//         }

//         void insertion(int index, int value){
//             for(int i=used_size;i>=index;i--){                                                     //this loop add values to next block 
//                 arr[i]=arr[i-1];
//             }
//             arr[index-1]=value;                                                                    //value will be added on that location
//             used_size++;                                                                           //used_size increase so +1 and it help to print value in display function  
//         }

//         void deletion(int index){
//             for(int i=index;i<used_size;i++){                                                      //this loop add values to previous block
//                 arr[i-1]=arr[i];
//             }
//             arr[used_size-1]=0;                                                                    //in the end both last block have same value so last one will be set as zero
//             used_size--;                                                                           //used_size decrease so -1 and it help to print value in display function  
//         }
// };

// int main(){
//     array a1;
//     a1.display();

//     cout<<"insertion"<<endl;
//     a1.insertion(2,99);
//     a1.display();

//     cout<<"deletion"<<endl;
//     a1.deletion(5);
//     a1.display();

//     return 0;
// }