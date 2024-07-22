#include<stdio.h>
void PrintArray(int *A,int n){
    for(int i=0;i<n;i++){
        printf("Elements of Array: %d\n",A[i]);
    }
}
void BubbleSort(int *A,int n){
    int temp;
    int isSorted=0;
    for(int i=0;i<n;i++){
        printf("Working on pass  number %d\n",i+1);
        isSorted=1;
        for(int j=0;j<n-1-i;j++){
            if(A[j]>A[j+1]){
                temp=A[j];
                A[j]=A[j+1];
                A[j+1]=temp;
                isSorted=0;
            }
            
        }
        if(isSorted){
                return;
            }
    }
}
int main(){
    // int A[]={1,2,10,4,89,6};
    int A[]={1,2,3,4,5,6};
    int n=6;
    printf("Array before  sort\n");
    PrintArray(A,n);
    BubbleSort(A,n);
    printf("Array after Bubble sort\n");
     PrintArray(A,n);
    return 0;
}