import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class P1707_이분_그래프 {
    static ArrayList<Integer>[] A;
    static int[] check;
    static boolean[] visited;
    static boolean IsEven;
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int testCase = Integer.parseInt(br.readLine());
        for(int t =0; t<testCase; t++){
            String[] s = br.readLine().split(" ");
            int V = Integer.parseInt(s[0]);
            int E = Integer.parseInt(s[1]);

            A = new ArrayList[V+1];
            visited = new boolean[V+1];
            check = new int[V+1];
            IsEven = true;
            for(int i= 1; i<=V; i++){
                A[i]= new ArrayList<Integer>();
            }
            for(int i =0; i<E; i++) {
                s = br.readLine().split(" ");
                int start = Integer.parseInt(s[0]);
                int end = Integer.parseInt(s[1]);
                A[start].add(end);
                A[end].add(start);
            }
            for(int i=1; i<V; i++){
                if(IsEven){
                    DFS(1);
                }else{
                    break;
                }
            }

            if(IsEven) System.out.println("Yes");
            else System.out.println("No");


        }

    }
    private static void DFS(int start){
        visited[start]=true;
        for(int i : A[start]){
            if(!visited[i]){
                check[i] = (check[start]+1)%2;
                DFS(i);
            }else if(check[start]==check[i]){
                IsEven = false;
            }

        }
    }
}
