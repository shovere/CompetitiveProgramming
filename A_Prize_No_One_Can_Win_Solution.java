//problem:  https://vjudge.net/problem/Kattis-aprizenoonecanwin
//solution
import java.util.Arrays;
import java.util.Scanner;

public class Main {

    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        int numItems = sc.nextInt();
        int minCost = sc.nextInt();
        int[] itemCosts = new int[numItems];

        int i;
        for (i = 0; i < numItems; i++)
        {
            itemCosts[i] = sc.nextInt();
        }

        Arrays.sort(itemCosts);

        int curr = itemCosts[0];
        int labeled = numItems;


        for (int j = i-1; j > 0; j--)
        {
            curr = itemCosts[j];
            if(curr + itemCosts[j-1] > minCost)
                labeled--;
            else
                break;
        }
        System.out.println(labeled);
    }
}
