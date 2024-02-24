#include"iostream"
using namespace std;


template <class T >
class Queue
{
	T* data;
	int front;
	int rear;
	const int max;

public:
	Queue(const int max_s = 5) :max(max_s) {




		data = new T[max];
		front = -1;
		rear = -1;

	}
	void enQueue(const T newItem) {

		if ((rear+1) %max == front )
		{
			cout << "Queue is ful" << endl;
		}
		else {
			if (front == -1) {
				front = 0;
			}
			rear =( (rear + 1) % max);
			data[rear] = newItem;
		}
	}
	void deQueue()
	{
		if (front== -1) {
			cout << "Queue empty;" << endl;
		}
		else {
			if (front == rear) {
				front = rear = -1;
			}
			else {
				front = (front + 1) % max;
				
 			}
		}
	}
	void clear()
	{
		if (front == -1||rear==-1) {
			cout << "stack is already empty;" << endl;

		}
		else {
			front=rear = -1;
		}
	}
	T getFront()const
	{
		return data[front];

	}T getRear()const
	{
		return data[rear];

	}
	bool isEmpty() {

		if (front == -1)
		{
			return true;
		}
		else {

			return false;

		}

	}bool isFull() {

		if (front==(rear+1)%max) {

			return true;
		}
		else {
			return false;
		}
	}
	void showstructure()const {

		cout << "front---->";
		for (int i = front; i<=rear; i++)
		{
			cout << data[i] << endl;
			cout << "\t";
		}
		cout << "\t<--rear" << endl;
		cout << "-----------------------" << endl;
	}
	~Queue() {

		delete[]data;
	}

private:

};

int main() {

	Queue<float>obj;
	obj.enQueue(5.0);
	obj.enQueue(6.5);

	obj.showstructure();
	obj.enQueue(-3.0);
	obj.enQueue(-8.0);

	obj.showstructure();
	obj.deQueue();
	obj.deQueue();
	obj.showstructure();


	return 0;
}