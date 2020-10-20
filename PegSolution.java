//problem: https://vjudge.net/problem/Kattis-peg
//solution
import java.util.Scanner;

public class Main {

    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        char[][] graph = new char[7][];

        int numWays = 0;

        for (int i = 0; i < 7; i++)
        {
            graph[i] = sc.nextLine().toCharArray();
        }
        for (int j = 0; j < 7; j++)
        {
            for (int k = 0; k < graph[j].length; k++)
            {
                if(graph[j][k] != ' ' && graph[j][k] != '.' )
                {
                    try
                    {
                        if(graph[j+1][k] == '.' && graph[j-1][k] == 'o')
                            numWays++;
                    }
                    catch(Exception ignored)
                    {

                    }
                    try
                    {
                        if(graph[j-1][k] == '.' && graph[j+1][k] == 'o')
                            numWays++;
                    }
                    catch(Exception ignored)
                    {

                    }
                    try
                    {
                        if(graph[j][k+1] == '.' && graph[j][k-1] == 'o')
                            numWays++;
                    }
                    catch(Exception ignored)
                    {

                    }
                    try
                    {
                        if(graph[j][k-1] == '.'&& graph[j][k+1] == 'o')
                            numWays++;
                    }
                    catch(Exception ignored)
                    {

                    }
                }


            }
        }
        System.out.println(numWays);
    }
}
