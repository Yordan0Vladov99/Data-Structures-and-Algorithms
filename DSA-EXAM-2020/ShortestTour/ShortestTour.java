import java.io.*;
import java.util.*;

public class Solution {

        public static int bfs (ArrayList<Integer>[] gr, HashMap<Integer,Boolean> path, int n, int start, int dest){
        LinkedList<Integer> q = new LinkedList<>();
        ArrayList<Boolean> used = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            used.add(false);

        }
        q.add(start);
        int itr = 0;
        int nodesOnLevel = 1;
        int level = 0;

        while (!q.isEmpty()){
            int v = q.pollFirst();
            nodesOnLevel--;
            if(v == dest){
                return level;
            }

            for(int u: gr[v]){
                if(!path.get(u))continue;
                q.add(u);
            }
            if(nodesOnLevel == 0){
                nodesOnLevel = q.size();
                level++;
            }
        }
        return -1;
    }
    public static void main(String[] args) {
        HashMap<Integer,Boolean> path = new HashMap<>();
        ArrayList<Integer> destinations = new ArrayList<>();
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int M = scanner.nextInt();
        ArrayList[] gr = new ArrayList[N];
        for (int i = 0; i < N; i++) {
            gr[i] = new ArrayList<Integer>();
            path.put(i,true);
        }
        for (int i = 0; i < M; i++) {
            int f = scanner.nextInt();
            int t = scanner.nextInt();
            gr[f].add(t);
        }
        int k = scanner.nextInt();
        for (int i = 0; i < k; i++) {
            int num = scanner.nextInt();
            destinations.add(num);
            path.put(num,false);
        }
        int counter = 0;
        int start = 0;
        for (int i = 0; i < destinations.size(); i++) {
            if(i == 0){
                start = destinations.get(i);
                path.put(start,true);
            }
            else{
               int destination =destinations.get(i);
                path.put(destination,true);
                int distance = bfs(gr,path,N,start,destination);
                if(distance == -1){
                    counter = distance;
                    break;
                }
                counter+=distance;
                start = destination;
            }
        }
        System.out.println(counter);
    }
}