
#include<stdio.h>
void print(int n){
    
    if(n==1)
        printf("%d ",1);
    else{
        print(n-1);
        printf("%d ",n);
       
    }
    
}


int main(){
    
    print(4);
    
    
    return 0;
}