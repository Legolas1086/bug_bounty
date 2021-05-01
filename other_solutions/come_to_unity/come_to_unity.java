import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

class Solution {
    public static void main(String args[]){
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int op=0;
        while(n!=1){     
            if((n&1)==1){
                if((n-1)/2==1){
                    n-=1;
                }
                else if((((n+1)/2)&1)!=1){
                    n+=1;
                }
                else{ 
                    n-=1;
                }
                ++op;
            }
            else{
                n=n>>1;
                ++op;
            }
        }
        System.out.println(op);
    }
}