#include<stdio.h>

void display(int arr[], int n){
    for (int  i = 0; i < n; i++)
    {
       printf("%d\n",arr[i]);
    }
    
}
void linearsearch(int arr[],int element, int size){
    for (int  i = 0; i < size; i++)
    {
       if(arr[i]==element){
        printf("Element: %d is present at %d index",element,i);
       }
       else{
        printf("Elemnt is not present in the Array");
       }
    }
    
}
int main(){
    int arr[10]={2,3,4,5,6};
    int size=5;
    int element;
    printf("Enter element to be found");
    scanf("%d",&element);
    linearsearch(arr,element,size);
    display( arr ,size);



    return 0;
}