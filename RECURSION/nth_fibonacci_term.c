#include <stdio.h>
int nthFibTerm(int n){
    
    if(n==1)
        return 0;
    if(n==2)
        return 1;
    
    else
    return nthFibTerm(n-1) + nthFibTerm(n-2);
    
}


int main()
{
    
    printf("%d",nthFibTerm(2));

    return 0;
}