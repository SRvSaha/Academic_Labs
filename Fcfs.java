import java.util.Scanner;

public class Fcfs extends Thread{
	long starttime,finishtime;
	long turnaround=0;
	static long systemtime=0;
	static long tm=100;
	Scanner sc=new Scanner(System.in);
	public void run(){
		starttime=System.currentTimeMillis();
		System.out.println(Thread.currentThread().getName());
		for(int i=1;i<=2*100000000;i++);
			
			try{
//				Thread.sleep(100);
			}
			catch(Exception e){	
			}
		 
		
		//tm=tm+100;
		//stoptime=System.currentTimeMillis();
		
		finishtime=System.currentTimeMillis();
		turnaround=finishtime-starttime;
		systemtime=systemtime+turnaround;
		System.out.println("starttime="+starttime);
		System.out.println("finishtime="+finishtime);
		System.out.println("turnaround="+turnaround);
	}
	public static void main(String[] args){
		// TODO Auto-generated method stub
		int n,bt[] = null,at[] = null;
		Scanner sc=new Scanner(System.in);
		System.out.print("Enter the number of processes: ");
		n=sc.nextInt();
//		for(int j=1;j<=n;j++){
//			System.out.println("Enter the arrival time for process "+j);
//			at[j]=sc.nextInt();
//		}
//		for(int j=1;j<=n;j++){
//			System.out.println("Enter the burst time for process "+j);
//			bt[j]=sc.nextInt();
		//}
		Thread t[]=new Thread[n+1];
		for(int j=1;j<=n;j++){
			t[j]=new Fcfs();
			t[j].start();
			try{
			t[j].join();
			}catch(Exception e){	
			}
		}
		System.out.println("systemtime="+systemtime);
	}
}