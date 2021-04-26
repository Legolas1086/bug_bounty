n=int(input())
op=0

while n!=1:           
    if((n&1)==1):        
        if((n-1)//2==1):
            n-=1    
        elif((((n+1)//2)&1)!=1):
            n+=1
        else: 
            n-=1                
        op+=1
    else:
        n=n>>1
        op+=1      
print(op)
