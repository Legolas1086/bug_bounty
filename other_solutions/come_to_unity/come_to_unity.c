#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    int n,op=0;
    
    scanf("%d",&n);
    
    while(n!=1){
            
        if((n&1)==1){
                
            if((n-1)/2==1){
                n-=1;
            }
            else if((((n+1)/2)&1)!=1){
                n+=1;
            }else{ 
                n-=1;
            }
                
            ++op;
                
        }else{
            n=n>>1;
            ++op;
        }
            
    } 
    printf("%d",op);
    return 0;
}