import java.util.concurrent.Semaphore;
class Items {
	int n;
	static Semaphore semCon = new Semaphore(0);
	static Semaphore semProd = new Semaphore(1);
	void get() {
		try {
			semCon.acquire();
		} catch (Exception e) {
		}
		System.out.println("Got : " + n);
		semProd.release();
	}
	void put(int n) {
		try {
			semProd.acquire();
		} catch (Exception e) {
		}
		this.n = n;
		System.out.println("Put: " + n);
		semCon.release();
	}
}
class Producer implements Runnable {
	Items q;
	public Producer(Items q) {
		// TODO Auto-generated constructor stub
		this.q = q;
		new Thread(this, "Producer").start();
	}
	public void run() {
		for (int i = 0; i < 20; i++)
			q.put(i);
	}
}
class Consumer implements Runnable {
	Items q;
	public Consumer(Items q) {
		this.q = q;
		new Thread(this, "Consumer").start();
	}
	public void run() {
		for (int i = 0; i < 20; i++)
			q.get();
	}
}
public class semprocon {
	public static void main(String[] args) {
		Items q = new Items();
		new Consumer(q);
		new Producer(q);
	}
}
