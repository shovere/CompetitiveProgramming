//description:    https://vjudge.net/problem/Kattis-cups

//solution
import java.util.SortedMap;
import java.util.Scanner;
import java.util.TreeMap;

public class Main {

    public static void main(String[] args)
    {
        SortedMap<Integer, String> mss = new TreeMap<Integer, String>();
        Scanner sc = new Scanner(System.in);
        int numCups = 0;
        numCups = sc.nextInt();

        for (int i = 0; i < numCups; i++)
        {
            int tempIn;
            String str;
            if(sc.hasNextInt())
            {
                tempIn = sc.nextInt();
                tempIn = tempIn/2;
                str = sc.next();
            }
            else
            {
                str = sc.next();
                tempIn = sc.nextInt();
            }
            mss.put(tempIn, str);
        }

        for (int i: mss.keySet())
        {
            System.out.println(mss.get(i));
        }
    }
}
