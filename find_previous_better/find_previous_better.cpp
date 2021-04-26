#include <bits/stdc++.h>

using namespace std;

void previousBest(int n,int ranks[25])
{
    int i,j=0;
    int stack[25],top=-1,previos_greater[25];
    for(i=0;i<n;++i)
    {
        while(top>=0)
        {
            if(stack[top]>ranks[i])
            {
                previos_greater[j++]=stack[top];
                break;
            }
            else
            {
                top--;
            }
        }
        if(top<0)
            previos_greater[j++]=-1;
        
        stack[++top]=ranks[i];
    }
    
    for(i=0;i<j;++i)
    {
        cout<<previos_greater[i]<<" ";
    }
}

int main()
{
    int n,i;
    cin>>n;
    
    int ranks[n];
    for(i=0;i<n;++i)
        cin>>ranks[i];
                
    previousBest(n,ranks);  
    return 0;
}