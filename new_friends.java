import java.util.*;
public class Main{
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		int N=sc.nextInt();
		int edge=sc.nextInt();
		int[] ldr=new int[N+1];
		for(int i=0;i<N+1;i++){
			ldr[i]=i;
		}
		int[] left=new int[edge];
		int[] right=new int[edge];
		for(int i=0;i<edge;i++){
			left[i] = sc.nextInt();
			right[i]=sc.nextInt();
		}
		int[] gcnt=new int[N+1];
		int[] ecnt=new int[N+1];
		
		for(int i=0;i<edge;i++){
			join(ldr,left[i],right[i]);
		}
		
		for(int i=1;i<=N;i++){
			int lead=find(ldr,i);
			gcnt[lead]++;
		}
		
		for(int i=0;i<edge;i++){
			int lead=find(ldr,left[i]);
			ecnt[lead]++;
		}
		long ans=0;
		
		for(int i=1;i<N+1;i++){
			int gc=gcnt[i];
			int ec=ecnt[i];
			ans+=((long)gc*(gc-1)/2);
			ans-=ec;
		}
		System.out.print(ans);
		
	}
	private static void join(int[] ldr,int left,int right){
		ldr[find(ldr,left)]=find(ldr,right);
		
	}
	private static int find(int[] ldr,int node){
		if(ldr[node]!=node){
			ldr[node]=find(ldr,ldr[node]);
		}
		return ldr[node];
	}
}