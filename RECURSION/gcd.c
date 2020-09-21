#include <stdio.h>
int gcd(int n,int m){
    
    if(m==0)
        return n;
    
    else
    return gcd(m,n%m);
    
}


int main()
{
    
    printf("%d",gcd(3,28));

    return 0;
}