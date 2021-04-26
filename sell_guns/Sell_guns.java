import java.io.*;
import java.util.*;
import java.util.stream.*;
import static java.util.stream.Collectors.toList;

class FindPrice{
    public int Prices(int n,List<String> extras){
        int total_cost = 0;
        if(extras.size()==1){
            return total_cost;
        }
        for(int i = 0;i<extras.size();i++){
            if(extras.get(i).equals("odin")){
                total_cost = total_cost+10000;
            }

            else if (extras.get(i).equals("bucky")) {
                total_cost = total_cost+5000;
            }

            else if (extras.get(i).equals("bulldog")) {
                total_cost = total_cost+7000;
            }

            else if(extras.get(i).equals("ghost")){
                total_cost = total_cost+2000;
            }

            else if(extras.get(i).equals("operator")){
                total_cost = total_cost+8000;
            }

            else if(extras.get(i).equals("ares")){
                total_cost = total_cost+9000;
            }
        }
        return total_cost;
    }

    int findExtra(int n,List<String> guns){
        List<String> extras  = new ArrayList<String>(); 
        for(int i = 0;i<n-1;i++){
            for(int j = i+1;j<n;j++){
                if(guns.get(i).equals(guns.get(j))){
                    extras.add(guns.get(i));
                    break;
                }
            }
        }
        int total_cost = Prices(n,extras);
        return total_cost;
    }
}

public class Sell_guns{
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
    
        int n = Integer.parseInt(bufferedReader.readLine().trim());
        List<String> guns = Stream.of(bufferedReader.readLine().split(" ")).collect(toList());

        FindPrice findPrice = new FindPrice();
        int result = findPrice.findExtra(n, guns);
        System.out.println(result);

        bufferedReader.close();
    }
}
