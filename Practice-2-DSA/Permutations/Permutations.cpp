import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    public static void main(String[] args) {
        Scanner scanner=new Scanner(System.in);
        int num=scanner.nextInt();
        if(num==0)System.out.println("yes");
        else{
        String word1=scanner.next();
        String word2=scanner.next();
        char Temp1[]=word1.toCharArray();
        char Temp2[]=word2.toCharArray();
        Arrays.sort(Temp1);
        Arrays.sort(Temp2);
        word1=new String(Temp1);
        word2=new String(Temp2);
        if(word1.equals(word2))System.out.println("yes");
        else System.out.println("no");
        }
    }
}