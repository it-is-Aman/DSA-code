//SERACHING

// # include<stdio.h>

// // Liner search
// int linerSearch(int arr[],int size,int element){
//     for(int i=0;i<size;i++){
//         if(arr[i]==element){
//             return i;
//         }
//     }
        
//     return printf("element not found\n");
// }
        
// // Binery search
// int binerySearch(int arr[],int size,int element){
//     int middle;
//     int low=0;
//     int high=size-1;
//     while(low<=high){
//         middle=(low+high)/2;
//         if(arr[middle]==element){
//             return middle;
//         }
//         if(arr[middle]<element){
//             low=middle+1;
//         }
//         else{
//             high=middle-1;
//         }
//     }
//     return printf("element not found\n");
// }


// int main(){

//     int arr[]={1,2,3,4,6,8,99};
//     int size=sizeof(arr)/sizeof(int);
//     int element = 123123;
//     printf("element %d is found at index %d\n",element,linerSearch(arr,size,element));

//     printf("element %d is found at index %d\n",element,binerySearch(arr,size,element));


//     return 0;
// }