#include <stdio.h>
void toOctal(int n){
    
    if(n<8){
        printf("%d",n);
      
        
        return;
    }
    
    else{
          
         toBinary(n/8);
          printf("%d",n%8);
    }
}


int main()
{
    
    toOctal(11);

    return 0;
}
