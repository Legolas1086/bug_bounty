import java.io.*;
import java.util.*;
import java.util.stream.*;
import static java.util.stream.Collectors.toList;


class PreviousBest{
    void previousBest(int n,int[] ranks){
        int[] stac = new int[n+1];
        int top = -1;
        int[] previous_greater = new int[n];
        for(int i=0;i<n;i++){
            while(top>-1){
                if(stac[top]>ranks[i]){
                    previous_greater[i] = stac[top];
                    break;
                }  
                else{
                    top--;
                }  
            }
            if(top<0){
                previous_greater[i] = -1;
            }
            stac[++top] = ranks[i];
            
        }

        for(int i=0;i<n;i++){
            System.out.print(previous_greater[i]+" ");
        }
    }
}

public class find_previous_better {
    public static void main(String[] args)throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(reader.readLine().trim());
        
        List<String> input = Stream.of(reader.readLine().split(" ")).collect(toList());

        int[] ranks = new int[n];
        for(int i=0;i<n;i++){
            ranks[i] = Integer.parseInt(input.get(i));
        }


        PreviousBest best = new PreviousBest();
        best.previousBest(n, ranks);
        
    }
    
}