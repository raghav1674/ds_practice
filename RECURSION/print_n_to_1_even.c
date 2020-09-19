
#include<stdio.h>
void print(int n){
    
    if(n==1)
        printf("%d ",2);
    else{
         printf("%d ",2*n);
        print(n-1);
       
      
    }
    
}


int main(){
    
    print(100);
    
    
    return 0;
}