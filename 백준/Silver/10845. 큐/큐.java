import java.io.*;
import java.util.*;

public class Main
{
    public static void main(String[] args) throws IOException {
        BufferedReader bf=new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        StringBuilder sb=new StringBuilder();
        int n= Integer.parseInt(bf.readLine());
        var queue=new LinkedList<Integer>();
        while(n-->0){
            st=new StringTokenizer(bf.readLine()," ");
            switch (st.nextToken()){
                case "push":
                    int k= Integer.parseInt(st.nextToken());
                    queue.add(k);
                    break;
                case "pop":
                    if(queue.peek()==null){
                        sb.append(-1).append("\n");
                    }
                    else{
                        sb.append(queue.poll()).append("\n");
                    }
                    break;
                case "size":
                    sb.append(queue.size()).append("\n");
                    break;
                case "empty":
                    if(queue.isEmpty()) sb.append(1).append("\n");
                    else sb.append(0).append("\n");
                    break;
                case "front":
                    if(queue.peek()==null) sb.append(-1).append("\n");
                    else sb.append(queue.peek()).append("\n");
                    break;
                case "back":
                    if(queue.isEmpty()) sb.append(-1).append("\n");
                    else{
                        for(int i=0;i<queue.size()-1;i++){
                            queue.add(queue.remove());
                        }
                        sb.append(queue.peek()).append("\n");
                        queue.add(queue.remove());
                    }
                    break;
            }
        }
        System.out.print(sb);
    }
}