#include<stdio.h>
#include<stdlib.h>

// ABC :  

void permutation(char s[],int start,int end){

    
    static int count; // count the total number of permutations.
    char temp;

    
    
    int x;
    if(start==end){
        count++;
        printf("%d) %s  ",count,s);
    }
    else{

    
    for(x=start;x<=end;x++){

        
        // swap the char at x with char at start

        temp = s[x];
        s[x]=s[start];
        s[start]=temp;

       
      
        // now call the permutation with next start value.
        permutation(s,start+1,end);

        // again swap back to get the original string after call.

        temp=s[x];
        s[x]=s[start];
        s[start]=temp;



    }
    }





}


int main(){

    char s[]="ABCDE";
    permutation(s,0,4);

}