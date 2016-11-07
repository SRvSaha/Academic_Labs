class RR_Scheduling implements Runnable{
	Thread t;
	String name;
	//MyClass m;
	public RR_Scheduling(String name) {
		this.name=name;
		t=new Thread(this, name);
		System.out.println(this.name+" is created");
		t.start();
	}
	@Override
	synchronized public void run() {
		for(int i=1;i<=5;i++){
			System.out.println("Thread "+this.name+"::"+i);
			if(i%2==0){
				try {
					Thread.sleep(2000*2);
				} catch (InterruptedException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
			}
		}
		System.out.println(this.name+" Thread is Exiting");	
	}
}

public class roundrobin {
	public static void main(String[] args) throws Exception{
		// TODO Auto-generated method stub
		//MyClass mm=new MyClass();
		RR_Scheduling obj1=new RR_Scheduling("First");
		RR_Scheduling obj2=new RR_Scheduling("Second");
		RR_Scheduling obj3=new RR_Scheduling("Third");
		
		//Suspending and resuming a thread
		Thread.sleep(2000*2);
		obj1.t.suspend();
		obj1.t.resume();
		Thread.sleep(2000*2);
		obj2.t.suspend();
		obj2.t.resume();
		Thread.sleep(2000*2);
		obj3.t.suspend();
		obj3.t.resume();
		
		//Join the child thread
		obj1.t.join();
		obj2.t.join();
		obj3.t.join();
	}
}
