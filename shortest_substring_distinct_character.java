import java.util.*;
public class Main{
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		String s=sc.next();
		int n=s.length();
		HashMap<Character,Integer> mp=new HashMap<>();
		int ans=Integer.MAX_VALUE;
		Set<Character> disval=new HashSet<>();
		for(char ch:s.toCharArray()){
			disval.add(ch);
		}
		int discnt=disval.size();
		int i=0;
		int j=0;
		while(j<n){
			mp.put(s.charAt(j),mp.getOrDefault(s.charAt(j),0)+1);
			while(i<n && mp.size()>=discnt){
				ans=Math.min(ans,j-i+1);
				mp.put(s.charAt(i),mp.get(s.charAt(i))-1);
				if(mp.get(s.charAt(i))==0){
					mp.remove(s.charAt(i));
				}
				i++;
			}
			j++;
		}
		System.out.print(ans);
	}
}
