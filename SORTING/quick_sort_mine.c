#include<stdio.h>

int partition(int *arr,int low,int high){
                   
      
    int pivot=arr[low];
    int i=low+1;
    int j=high; 
    int temp;
    while(i<=j){

        while(arr[i]<=pivot)
                i++;

        while(arr[j]>pivot)
                j--;

        if(i<j){

            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
            i++;
            j--;


        }



    }

    // swap the pivot with the element at the th position

    temp=arr[j];
    arr[j]=arr[low];
    arr[low]=temp;

    return j;



}

void quick_sort(int *arr,int low,int high){
    int p;
  
    for(int i=0;i<11;i++){

        printf("%d ",arr[i]);

    }
        printf("\n");
        p=partition(arr,low,high);
        
        if(p>low+1) // atleast two elements in the left
        quick_sort(arr,low,p-1);

        if(p<high-1)// atleast two elements in the right
        quick_sort(arr,p+1,high);
        

    


}




int main(){


    int a[]={8,3,4,5,10,0,2,3,4,20,12};

    int size=sizeof(a)/sizeof(int);

    quick_sort(a,0,size-1);
    for(int i=0;i<size;i++){

        printf("%d ",a[i]);

    }
}