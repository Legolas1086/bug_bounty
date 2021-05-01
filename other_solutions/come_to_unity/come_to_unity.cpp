#include <bits/stdc++.h>

using namespace std;

int main() {

    int n,op=0;
    
    cin>>n;
    
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
                
        }
        else{
            n=n>>1;
            ++op;
        }
            
    } 
    cout<<op;
    return 0;
}