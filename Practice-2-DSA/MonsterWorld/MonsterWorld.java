import java.io.*;
import java.util.*;

public class Solution {

    public static void main(String[] args) {
        Scanner scanner=new Scanner(System.in);
        int Num=scanner.nextInt();
        int Radius=scanner.nextInt();
        int Monsters[]=new int[Num];
        for(int i=0;i<Num;i++)
        {
            Monsters[i]=scanner.nextInt();
        }
        int radiusSum=0;
        int blastCounter=0;
        int Pos=-1;
        Arrays.sort(Monsters);
        for(int i=Num-1;i>=0;i--)
        {
            if(Monsters[i]-radiusSum>0 && Monsters[i]!=Pos)
            {
                radiusSum+=Radius;
                blastCounter++;
                Pos=Monsters[i];
            }
        }
        System.out.println(blastCounter);
    }
}