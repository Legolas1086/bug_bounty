import java.io.*;
import java.util.*;
import java.util.stream.*;
import static java.util.stream.Collectors.toList;

class BestTeam{
    public int convertedRanks(String rank){
        int j=0;
        if(rank.equals("iron")){
            j=1;
        }

        else if(rank.equals("bronze")){
            j=2;
        }
         
            
        else if(rank.equals("silver")){
            j=3;
        }
            
        else if(rank.equals("gols")){
            j=4;
        }

        else if(rank.equals("platinum")){
            j=5;
        }
            
        else if(rank.equals("diamond")){
            j=6;
        }
            
        else if(rank.equals("immortal")){
            j=7;
        }
            
        else if(rank.equals("radiant")){
            j=8;
        } 
        return j;
        
    }

    int partition(int[] arr,int low,int high){
        int i = low-1;
        int pivot = arr[high];
        for(int j=low;j<high;j++){
            if(arr[j]>=pivot){
                i = i+1;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;

            }

        }
        int temp_1 = arr[i+1];
        arr[i+1] = arr[high];
        arr[high] = temp_1;
        return i+1;
    }


    void arrangeScore(int[] score_of_players,int low,int high){
        if(low<high){
            int pi = partition(score_of_players,low,high);

            arrangeScore(score_of_players,low,pi-1);
            arrangeScore(score_of_players,pi+1,high);
        }    
    }




    int bestTeam(int n,List<String> ranks,List<Integer> communication){
        int[] score_of_players = new int[n];
        for(int i=0;i<n;i++){
            score_of_players[i] = convertedRanks(ranks.get(i))+communication.get(i);
        }

        arrangeScore(score_of_players,0,n-1);
        
        int score = 0;
        for(int i = 0;i<4;i++){
            score = score + score_of_players[i];
        }
        return score;

    }
}


public class Valorant_squad{
    public static void main(String[] args)throws IOException{
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(reader.readLine().trim());
        List<String> ranks = Stream.of(reader.readLine().split(" ")).collect(toList());
        List<Integer> communication = Stream.of(reader.readLine().replaceAll("\\s+$", "").split(" "))
            .map(Integer::parseInt)
            .collect(toList());

        if(n<4){
            System.out.println("Cannot form team, at least 4 players required");
        }    
        
        BestTeam best = new BestTeam();
        int result = best.bestTeam(n, ranks, communication);
        System.out.println(result);

        reader.close();


    }
}