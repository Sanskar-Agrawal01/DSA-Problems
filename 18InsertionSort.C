#include<stdio.h>
void PrintArray(int *A,int n){
    for(int i=0;i<n;i++){
        printf("Elements of Array: %d\n",A[i]);
    }
}
void InsertionSort(int *A,int n){
    int key,j;
    //loop for each pass
    for(int i=1;i<=n-1;i++){
        //loop for each comparison
       key=A[i];
       j=i-1;
       while(j>=0 && A[j]>key){
           A[j+1]=A[j];
           j--;
       }
       A[j+1]=key;
       
    }
}

int main(){
    // -1   0    1   2   3   4   5
   //      12,| 54, 65, 07, 23, 09 --> i=1, key=54, j=0
   //      12,| 54, 65, 07, 23, 09 --> 1st pass done (i=1)!

   //      12, 54,| 65, 07, 23, 09 --> i=2, key=65, j=1
   //      12, 54,| 65, 07, 23, 09 --> 2nd pass done (i=2)!

   //      12, 54, 65,| 07, 23, 09 --> i=3, key=7, j=2
   //      12, 54, 65,| 65, 23, 09 --> i=3, key=7, j=1
   //      12, 54, 54,| 65, 23, 09 --> i=3, key=7, j=0
   //      12, 12, 54,| 65, 23, 09 --> i=3, key=7, j=-1
   //      07, 12, 54,| 65, 23, 09 --> i=3, key=7, j=-1--> 3rd pass done (i=3)!

   // Fast forwarding and 4th and 5th pass will give:
   //      07, 12, 54, 65,| 23, 09 --> i=4, key=23, j=3
   //      07, 12, 23, 54,| 65, 09 --> After the 4th pass

   //      07, 12, 23, 54, 65,| 09 --> i=5, key=09, j=4
   //      07, 09, 12, 23, 54, 65| --> After the 5th pass 
    
    int A[] = {12, 54, 65, 7, 23, 9};
    int n=6;
     printf("Array before  sort\n");
    PrintArray(A,n);
    InsertionSort(A,n);
       printf("Array After inserton sort (increasing order)\n");
    PrintArray(A,n);
    //  InsertionSort(A,n);
    //   printf("Array After inserton sort(for decreasing oreder change the condition of while loop as A[j]<key)\n");
    // PrintArray(A,n);
    return 0;

}