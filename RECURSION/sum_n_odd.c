#include<stdio.h>
int sum(int n){
    
    if(n==1)
        return 1;
    return 2*(n)-1 + sum(n-1);
    
}


int main(){
    
    printf("%d",sum(1000));
    
    
    return 0;
}