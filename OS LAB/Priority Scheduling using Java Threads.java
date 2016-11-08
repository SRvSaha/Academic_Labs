class Priority_Scheduling implements Runnable{
	Thread t;
	String name;
	public Priority_Scheduling(String name,int p) {
		this.name=name;
		t=new Thread(this,name);
		t.setPriority(p);
		System.out.println(this.name+" is created");
		t.start();
	}
	@Override
	public void run() {
		for(int i=5;i>0;i--){
			System.out.println(this.name +": "+i);
		}
		System.out.println(this.name + " is Exited");
	}
}
public class Priority {
	
	public static void main(String[] args) throws Exception {
		
		Priority_Scheduling obj1=new Priority_Scheduling("First",Thread.MAX_PRIORITY);
		Priority_Scheduling obj2=new Priority_Scheduling("Second",Thread.MIN_PRIORITY);
		Priority_Scheduling obj3=new Priority_Scheduling("Third",Thread.NORM_PRIORITY);
		
		obj1.t.join();
		obj2.t.join();
		obj3.t.join();
		
		System.out.println("Main thread is Exited");
	}

}
