// Sorting

/*
Criteria for Analysis sorting algorithm in detail:

Time Complexity
Space Complexity
Stability
Internal & External Sorting Algorithms
Adaptivity
Recursiveness
*/

// Bubble sort

/*
size of the unsorted array, 6, hence we made 5 comparisons. And for every subsequent pass(steps), we made 4, 3, 2, and 1 comparison
    size of array is 5 so,
        1 pass -> 4 comparision and 4 possible swap (size-1)
        2 pass -> 3 comparision and 3 possible swap (size-2)
        3 pass -> 2 comparision and 2 possible swap (size-3)
        4 pass -> 1 comparision and 1 possible swap (size-4)       here array is sorted so loop run till size-1
*/

// #include<stdio.h>

// void bubbleSort(int *arr,int size){
//     int temp,isSort=1;
//     for(int i=0;i<size-1;i++){                                                                     //loop 1 for steps...loop run until size-1 because last digit will automatically be sorted in last step
//         printf("steps %d of Sort\n",i+1);
//         for(int j=0;j<size-1-i;j++){                                                        //loop 2 for bubble comparsion...loop run until size-1-i because each time we compare two digit and after complete one step we have to compare arr without last digit
//             if(arr[j]>arr[j+1]){                                                                   //swap if 1st digit is larger then 2nd digit
//                 temp=arr[j];
//                 arr[j]=arr[j+1];
//                 arr[j+1]=temp;
//                 isSort=0;                                                                          //if array comes in loop 2 then it means array just sort so put isSort=0
//             }
//         }
//         if(isSort==1){                                                                             //here if array did't go in loop 2 so it means array all sorted and simply return the function (exits)
//             return ;                                                                               //This syntax is used in function just as a jump statement in order to break the flow of the function and jump out of it. One can think of it as an alternative to “break statement” to use in functions.
//         }
//     }
// }
// void display(int *arr,int size){
//     for(int i=0;i<size;i++){
//     printf("%d ",arr[i]);
//     }
//     printf("\n");
// }

// int main(){
//     int arr[]={1,3,6,8,9,4,2,5,1,0};
//     // int arr[]={0,1,2,3,4,5,6,7,8,9};                                                               //this will only run for one step(pass) of comparsion . thats why we used isSort variable in bubbleSort()
//     int size=10;

//     printf("Before sorting\n");
//     display(arr,size);
//     bubbleSort(arr,size);
//     printf("After sorting\n");
//     display(arr,size);

//     return 0;
// }

// Insertion sort
/*
Already Adaptive - no need to creat seperate variable for checking if array is sorted like we did in bubble sort

    size of array is 5 so,
        1 pass -> 1 comparision and 1 possible swap
        2 pass -> 2 comparision and 2 possible swap
        3 pass -> 3 comparision and 3 possible swap
        4 pass -> 4 comparision and 4 possible swap       here array is sorted so loop run till size-1
*/

/* Show case of how the insertion sort is implemented
   // -1   0    1   2   3   4   5
   //      12,| 54, 65, 07, 23, 09 --> i=1, key=54, j=0
   //      12,| 54, 65, 07, 23, 09 --> 1st pass done (i=1)!

   //      12, 54,| 65, 07, 23, 09 --> i=2, key=65, j=1
   //      12, 54,| 65, 07, 23, 09 --> 2nd pass done (i=2)!
                                                                                key value will be same
   //      12, 54, 65,| 07, 23, 09 --> i=3, key=7, j=2                              [j]>key so, put [j+1]=[j] and j--
   //      12, 54, 65,| 65, 23, 09 --> i=3, key=7, j=1                              [j]>key so, put [j+1]=[j] and j--
   //      12, 54, 54,| 65, 23, 09 --> i=3, key=7, j=0                              [j]>key so, put [j+1]=[j] and j--
   //      12, 12, 54,| 65, 23, 09 --> i=3, key=7, j=-1                             loop terminate so, put [j+1]=key
   //      07, 12, 54,| 65, 23, 09 --> i=3, key=7, j=-1--> 3rd pass done (i=3)!
                                                                                key value will be same
   //      07, 12, 54, 65,| 23, 09 --> i=4, key=23, j=3                             [j]>key so, put [j+1]=[j] and j--
   //      07, 12, 54, 65,| 65, 09 --> i=4, key=23, j=2                             [j]>key so, put [j+1]=[j] and j--
   //      07, 12, 54, 54,| 65, 09 --> i=4, key=23, j=1                             loop terminate so, put [j+1]=key
   //      07, 12, 23, 54,| 65, 09 --> 4th pass done (i=4)!
                                                                                key value will be same
   //      07, 12, 23, 54, 65,| 09 --> i=5, key=09, j=4                             [j]>key so, put [j+1]=[j] and j--
   //      07, 12, 23, 54, 65,| 65 --> i=5, key=09, j=3                             [j]>key so, put [j+1]=[j] and j--
   //      07, 12, 23, 54, 54,| 09 --> i=5, key=09, j=2                             [j]>key so, put [j+1]=[j] and j--
   //      07, 12, 23, 23, 65,| 09 --> i=5, key=09, j=1                             [j]>key so, put [j+1]=[j] and j--
   //      07, 12, 12, 54, 65,| 09 --> i=5, key=09, j=0                             loop terminate so, put [j+1]=key
   //      07, 09, 12, 23, 54, 65| --> 5th pass done (i=5)!
*/

/* An array of length 5 using insertion sort algorithm, we made a total of 4 passes, which is
obviously, 5-1. So, for an array of length n, we would make (n-1) passes. But this time
the loop starts from the 1st index, and not from the 0th since the first element is sorted
whatsoever. So, make this loop run from 1 to (n-1).

Create another index variable j, which would be used to iterate through the sorted subarray,
and to find a perfect position for the key. The index variable j holds the value i-1.

Make a while loop run until either we finish through the sorted subarray and reach the last
position, or else we find an index fit for the key. And until we come out of the loop, keep
shifting the elements to their right and reduce j by 1. And once we come out, insert the
key at the current value of j+1. And this would go on for n-1 passes.
*/

// #include<stdio.h>

// void display(int *arr, int size){
//     for(int i=0;i<size;i++){
//         printf("%d ",arr[i]);
//     }
//     printf("\n");
// }

// void insertionSort(int *arr,int size){
//     int key,j;

//     //loop 1 for pass(steps)
//     for(int i=1;i<size;i++){                                                                       //start i=1 because we compare from 2nd element (index 1). loop run till (size - 1) but we took 'i=1' thats why run till (i<size)
//         key=arr[i];                                                                                //(keep in mind) here we store element in key, which are going to be compare in next loop
//         j=i-1;                                                                                     //j=i-1 because we compare from prev. element of [i]

//         //loop 2 for comparison
//         while(j>=0 && arr[j]>key){                                                                 //if arr[i] larger than key and j>=0 so
//             arr[j+1]=arr[j];                                                                       //put arr[j] in arr[j+1] which is position of 'key', but arr[i] means 'key' element still in 'key' which helps us in another comparison
//             j--;                                                                                   //decrement j by 1, so we compare backward element arr[j] from 'key' element
//         }
//         arr[j+1]=key;                                                                              //(keep in mind) put 'key' value means arr[i] in arr[j+1], because j already (behind -1 position) beacuse of while loop.
//     }
// }

// int main(){
//     int arr[]={1,4,2,7,8,9,6,5};
//     int size=8;

//     printf("Before sorting\n");
//     display(arr,size);
//     insertionSort(arr,size);
//     printf("After sorting\n");
//     display(arr,size);
//     return 0;
// }

// Selection sort
/*
    size of array is 5 so,
        1 pass -> 4 comparision and 1 possible swap
        2 pass -> 3 comparision and 1 possible swap
        3 pass -> 2 comparision and 1 possible swap
        4 pass -> 1 comparision and 1 possible swap       here array is sorted so loop run till size-1
*/

/* Show case of how the selection sort is implemented
// Input Array (There will be total n-1 passes. 5-1 = 4 in this case!)
    //  00  01  02  03  04
    // |03, 05, 02, 13, 12             i=0, indexSmall=0, j=1                 [indexSmall]=03  [j]=05  and j++
    // |03, 05, 02, 13, 12             i=0, indexSmall=0, j=2                 [indexSmall]=03  [j]=02  [j]<[indexSmall] so, swap

    // After first pass
    //  00  01  02  03  04
    //  02,|05, 03, 13, 12             i=1, indexSmall=1, j=2                 [indexSmall]=05  [j]=03  [j]<[indexSmall] so, swap

    // After second pass
    // 00  01  02  03  04
    // 02, 03,|05, 13, 12              i=2, indexSmall=2, j=3                 [indexSmall]=05  [j]=13

    // After third pass
    // 00  01  02  03  04
    // 02, 03, 05,|13, 12              i=3, indexSmall=3, j=4                 [indexSmall]=13  [j]=12  [j]<[indexSmall] so, swap

    // After fourth pass
    // 00  01  02  03  04
    // 02, 03, 05, 12,|13              Sorted in total (size-1) passes(steps)
*/

/*create a for loop that tracks the number of passes. If you recall, to sort an
array of length 5 using the selection sort algorithm, we made a total of 4 passes.
So, for an array of length n, we would make (n-1) passes. And the loop starts from
the 0th index and ends at (n-1)th.

At each pass, we first initialize the indexOfMin to be the first index of the unsorted
part. So, inside this loop, initialize the indexOfMin to be i, which is always the first
index of the unsorted part of the array.

Create another loop to iterate over the rest of the elements in the unsorted part to
find if there is any lesser element than the one at indexOfMin. Make this loop run
from i+1 to the last. And compare the elements at every index. If you find an element
at index j, which is less than the element at indexOfMin, then update indexOfMin to j.

And finally, when you finish iterating through the second loop, just swap the elements at indices i & indexOfMin.
*/

// #include <stdio.h>

// void display(int *arr, int size){
//     for(int i=0;i<size;i++){
//         printf("%d ",arr[i]);
//     }
//     printf("\n");
// }

// void selectionSort(int *arr, int size){
//     int indexSmall, temp;

//     //loop 1 for passes(steps)
//     for(int i=0 ; i<size-1 ; i++){                                                                 //(keep in mind)run from (0th index to (n-1)th index) if length=5 run from index 0 to index 3, because we compare 'index 0 element till last, means index 4' but in last pass(step) we compare 'index 3 with index 4'
//         indexSmall = i;                                                                            //Here we initialize first index of unsorted array in every pass(step)

//         //loop 2 for comparison
//         for(int j=i+1 ; j<size ; j++){                                                             //start from 1 index ahead from 'i' and run till (size-1) means last index
//             if(arr[j] < arr[indexSmall]){                                                          //(keep in mind)if [j]<[indexSmall] then put index of [j] in indexSmall, so from now here [indexSmall] is the smallest element in unsorted array
//                 indexSmall = j;
//             }
//         }
//         //swap
//         temp=arr[i];                                                                               //swap [i] with [indexSmall] means, first index element of every pass(step) loop with smallest element from unsorted array. so, their both position swap
//         arr[i]=arr[indexSmall];
//         arr[indexSmall]=temp;
//     }                                                                                              //and after new loop 1 indexsmall will be change according to value of i
// }

// int main(){

//     int arr[]={1,4,2,7,8,9,6,5};
//     int size=8;

//     printf("Before sorting\n");
//     display(arr , size);
//     selectionSort(arr , size);
//     printf("After sorting\n");
//     display(arr , size);

//     return 0;
// }

// Quick sort

/* choose the first element of the unsorted subarray as the pivot. We would need two more index variables, i and j.

1.Define i as the low index, which is the index of the first element of the subarray, and j as the high index,
  which is the index of the last element of the subarray.
2.Set the pivot as the element at the low index i since that is the first index of the unsorted subarray.
3.Increase i by 1 until you reach an element greater than the pivot element.
4.Decrease j by 1 until you reach an element smaller than or equal to the pivot element.
5.Having fixed the values of i and j, interchange the elements at indices i and j.
6.Repeat steps 3, 4, and 5 until j becomes less than or equal to i.
7.Finally, swap the pivot element and the element at the index.

This was the partitioning algorithm. Every time you call a partition, the pivot element gets its final position.
A partition never guarantees a sorted array, but it does guarantee that all the smaller elements are located to
the pivot’s left, and all the greater elements are located to the pivot’s right.
*/

// if you call quicksort passing the above array, It would pass it further to the partition, and the partition would
// return the new index of the pivot element, which is 4. Partition returns 3, the new position of 4. Now, quicksort
// recursively calls itself on the left and the right subarrays

/*  Show case of how the Quick sort is implemented

    // 0   1   2   3   4   5   6   7   8   9
    // 5p, 2i, 3,  1,  7,  8,  9,  4,  0,  6j                                        pivot is 5
    // 5p, 2,  3,  1,  7i, 8,  9,  4,  0j, 6                                         i<j    i and j element swap their places
    // 5p, 2,  3,  1,  0i, 8,  9,  4,  7j, 6                                         i++ until arr[i]>arr[low] and j-- until arr[i]<arr[low]
    // 5p, 2,  3,  1,  0,  8i, 9,  4j, 7,  6                                         i<j    i and j element swap their places
    // 5p, 2,  3,  1,  0,  4i, 9,  8j, 7,  6                                         i++ until arr[i]>arr[low] and j-- until arr[i]<arr[low]
    // 5p, 2,  3,  1,  0,  4j, 9i, 8,  7,  6                                         j<=i so loop stop,   swap arr[j] and arr[low](pivot)
    // 4,  2,  3,  1,  0,  5p, 9,  8,  7,  6                                         smaller element is on left side of pivot and larger on right
    --> first call to partition returns 5


*/

// #include<stdio.h>

// void display(int arr[],int size){
//     for(int i=0;i<size;i++){
//         printf("%d ",arr[i]);
//     }
//     printf("\n");
// }

// int partision(int arr[], int low, int high){

//     //arr[low] is our pivot
//     int i = low + 1;                                                                               //because i=low is our pivot so start after pivot element
//     int j = high;                                                                                  //j have last index of our array
//     int temp;

//     do{
//         while(arr[i]<=arr[low]){                                                                   //we find arr[i] greater than arr[low]. means !(arr[i]>arr[low]). keep i++ run until the index i reaches an element greater than or equal to the pivot or the array finishes
//             i++;
//         }
//         while(arr[j]>arr[low]){                                                                    //we find arr[j] less than or equal to arr[low]. keep j-- run until our index j reaches an element smaller than the pivot or the array finishes.
//             j--;
//         }
//         if(i<j){                                                                                   //(swap the elements at indices i and j) so the smaller element will fits its correct position
//             temp=arr[i];
//             arr[i]=arr[j];
//             arr[j]=temp;
//         }
//     }while(i<j);                                                                                   //run until j will become less than or equal to i   so, arr[j] have less value and arr[i] have greater value w.r.t the pivot(arr[low]) value.

//         //(keep in mind) this swap will only run when j>=i if i<j so, do-while loop will still execute.
//         //swap our pivot with the element at index j                                               //because arr[j] have less value and after swaping with pivot. smaller element is on left side of pivot and greater element on right side.
//         temp=arr[low];                                                                             //(keep in mind) swap with arr[low] because we want to occur change in our array.
//         arr[low]=arr[j];
//         arr[j]=temp;

//     return j;                                                                                      //simply return the index of the pivot

// }

// void quickSort(int arr[], int low, int high){
//     int partisionIndex;

//     if(low < high){                                                                                //The basics of recursion demand a base condition to stop the recursion. Hence, the base condition here would be when our low becomes greater than or equal to our high

//         partisionIndex = partision(arr,low,high);                                                  // Index of pivot after partition

//         // display(arr,10);                                                                           //just to see how to quickSort work in each recursive cycle

//         quickSort(arr,low,partisionIndex-1);                                                       //sort left subarray
//         quickSort(arr,partisionIndex+1,high);                                                      //sort right subarray
//     }
// }

// int main(){

//     int arr[]={5, 2, 3, 1, 7, 8, 9, 4, 0, 6};
//     int low=0;
//     int size=10;

//     display(arr,size);
//     quickSort(arr,low,size-1);
//     display(arr,size);

//     return 0;
// }

// Merge sort

/*Whenever you are asked to sort an array using the merge sort algorithm, first divide the
array until the size of each subarray becomes 1.
Now, since an array or subarray of size 1 is considered already sorted, we call our merge
function, which merges these subarrays into bigger sorted subarrays.
And finally, you end up with your array fully sorted
*/

/*  Show case of how the Merge sort is implemented

    //arr A   size m=4  i,                    arr B  size n=4  j,
    // 0  1  2  3                             0  1  2  3
    // 4  2  3  5                             1  5  9  0

    //          arr C   size = m+n  k,
    //          0  1  2  3  4  5  6  7
    //          0  1  2  3  4  5  5  9

    int i=0;                                                                                     
    int j=0;                                                                                   
    int k=0;

    while(i<=m && j<=n){                                                                      
        if(A[i]<A[j]){                                                                     
            C[k]=A[i];
            i++;
            k++;
        }
        else{                                                                                      
            C[k]=B[j];
            j++;
            k++;
        }
    }                                                                                              
    while(i<=m){                                                                                 
        C[k]=A[i];
        i++;
        k++;
    }
    while(j<=n){                                                                                
        C[k]=B[j];
        j++;
        k++;
    }

    use this alove as a reference and i gets initialised with low,
                                      j gets initialised with mid+1,
                                      k gets initialised with low only.
    And similar to what we did earlier, i runs from low to mid, j runs from mid+1 to high, and until and unless they both get all their elements merged, we continue filling elements in array B
*/

// #include <stdio.h>

// void display(int arr[], int size)
// {
//     for (int i = 0; i < size; i++)
//     {
//         printf("%d ", arr[i]);
//     }
//     printf("\n");
// }

// void merge(int arr_1[], int low, int mid, int high){
//     int i=low;                                                                                     //i marks the current element of the first subarray of array A
//     int j=mid+1;                                                                                   //j marks the first element of the second subarray
//     int k=low;                                                                                     //k is the iterator for array B to insert the smaller of elements at indices i and j.
//     int arr_2[100];

//     while(i<=mid && j<=high){                                                                      //Run a while loop until either i or j or both reaches the threshold of their corresponding subarray
//         if(arr_1[i]<arr_1[j]){                                                                     //if arr[i] < arr[j] , insert element at index i in index k of array B i.e., arr_2[k] = arr_1[i] and increment both i and k by 1.
//             arr_2[k]=arr_1[i];
//             i++;
//             k++;
//         }
//         else{                                                                                      //else, insert element at index j in index k of array B i.e. arr_2[k] = arr_1[j] and increment both j and k by 1.
//             arr_2[k]=arr_1[j];
//             j++;
//             k++;
//         }
//     }                                                                                              //The above ends when either i or j or both reach its corresponding subarray’s end.
//     while(i<=mid){                                                                                 //run for inserting the remaining elements of arr[i], if left, in the subarrays
//         arr_2[k]=arr_1[i];
//         i++;
//         k++;
//     }
//     while(j<=high){                                                                                //run for inserting the remaining elements of arr[j], if left, in the subarrays
//         arr_2[k]=arr_1[j];
//         j++;
//         k++;
//     }

//     //loop for transfer sorted array(arr_2) in original array(arr_1)
//     for(int i=low;i<=high;i++){                                                                    //just copy the sorted array back again to array arr
//         arr_1[i]=arr_2[i];
//     }
// }

// void mergeSort(int arr[], int low, int high)
// {
//     int mid;

//     if(low < high)                                                                                 //recursively call this function only if low is less than high
//     {
//         mid = (low + high) / 2;
//         mergeSort(arr, low, mid);                                                                  //for left subarray
//         mergeSort(arr, mid + 1, high);                                                             //for right subarray
//         merge(arr, low, mid, high);                                                                //here we simply merge(arrange) them so give all parameters, this would return a sorted array.
//     }
// }

// int main()
// {

//     int arr[] = {2, 4, 1, 3, 5, 6, 9, 8, 7, 0};
//     int size = 10;

//     int low = 0;
//     int high = 9;

//     display(arr, size);
//     mergeSort(arr, low, high);
//     display(arr, size);

//     return 0;
// }



// Count sort

/* Show case of how the Merge sort is implemented
    given array
    // 0  1  2  3  4  
    // 2, 4, 0, 1, 1,                                  max element is 4 so, size of count = 4+1

                                                            arr[0]=2 so, count[2]++;
                                                            arr[1]=4 so, count[4]++;
                                                            arr[2]=0 so, count[0]++;
                                                            arr[3]=1 so, count[1]++;
                                                            arr[4]=1 so, count[1]++;

                            i=counter for count array  and  j=counter for given array 

    count array
    // 0  1  2  3  4  

    // 1  2  1  0  1                           i=0 j=0  count[i]>0  so arr[j]=i  j++  count[i]--
    // 0  2  1  0  1                           i=0 j=1  count[i]<=0  so i++
    // 0  2  1  0  1                           i=1 j=1  count[i]>0  so arr[j]=i  j++  count[i]--
    // 0  1  1  0  1                           i=1 j=2  count[i]>0  so arr[j]=i  j++  count[i]--
    // 0  0  1  0  1                           i=1 j=3  count[i]<=0  so i++
    // 0  0  1  0  1                           i=2 j=3  count[i]>0  so arr[j]=i  j++  count[i]--
    // 0  0  0  0  1                           i=2 j=4  count[i]<=0  so i++
    // 0  0  0  0  1                           i=3 j=4  count[i]>0  so i++
    // 0  0  0  0  1                           i=4 j=4  count[i]>0  so arr[j]=i  j++  count[i]--
    // 0  0  0  0  0                           --------> completed
    

                                                                                

    given array sorted
    // 0  1  2  3  4
    // 0  1  1  2  4                                


*/


// #include<stdio.h>
// #include<stdlib.h>

// void display(int *arr, int size){
//     for(int i=0;i<size;i++){
//         printf("%d ",arr[i]);
//     }
//     printf("\n");
// }

// int maximum_size(int arr[],int size){
//     int max=0;
//     for(int i=0;i<size;i++){
//         if(max<arr[i]){
//             max=arr[i];
//         }
//     }
//     return max;                                                                                    //return max element in given array.
// }

// void countSort(int *arr, int size){
//     int i,j;

//     //Find the maximum element in arr
//     int max = maximum_size(arr, size);

//     //Create the count array
//     int * count = (int *)calloc((max+1),sizeof(int));                                              //create max+1 size arr (count) and each element is initialize with 0.
    
//     //Increment the corresponding index in the count array
//     for(int i=0;i<size;i++){                                                                       //iterate through the given array and increase the value of the corresponding element index in the count array by 1.
//         count[arr[i]]++;                                                                           //(keep this in mind) if arr[1]=5  so, count[5] will now have 1.
//     }

//     i =0; // counter for count array
//     j =0; // counter for given array arr

//     while(i<=max){                                                                                 
//         if(count[i]>0){                                                                            
//             arr[j]=i;                                                                              //insert i at the jth index of the given array  
//             count[i]--;                                                                            //decrement the element in the count array at ith index by 1
//             j++;                                                                                   //increase the value of j by 1. element is assign in given_arr so now point next space for adding new element
//         }
//         else{
//             i++;                                                                                   //increase the value of j by 1
//         }
//     }

// }

// int main(){

//     int arr[]={2,5,4,1,3,6,9,7,8,0};
//     int size = 10;
//     display(arr,size);
//     countSort(arr,size);
//     display(arr,size);


//     return 0;
// }