#include"iostream"
using namespace std;


template <class T >
class Stack
{
	T* data;
	int top;
	const int max;

public:
	Stack(const int max_s=5):max (max_s){
		
		
		

		data = new T[max];
		top = -1;

	}
	void push(const T newItem) {

		if (top == max - 1)
		{
			cout << "stack overflow" << endl;
		}
		else {
			++top;
			data[top] = newItem;
		}
	}
	void pop()
	{
		if (top == -1) {
			cout << "stack is empty;" << endl;
		}
		else {
			--top;
		}
	}
	void clear()
	{
		if (top == -1) {
			cout << "stack is already empty;" << endl;
		
		}
		else {
			top = -1;
		}
	}
	T getTop()const
	{
		return data[top];

	}
	bool isEmpty() {
		
		if (top == -1)
		{
			return true;
		}
		else {

			return false;

		}

	}bool isFull() {

		if (top == max - 1) {

			return true;

		}
		else {

			return false;

		}
	}
	void showstructure()const {

		cout << "top---->";
		for (int i = top; i >= 0; i--)
		{
			cout << data[i] << endl;
			cout << "\t";
		}
		cout << "-----------------------" << endl;
	}
	~Stack() {

		delete[]data;
	}

private:

};

int main() {

	Stack<float>obj;
	obj.push(5.0);
	obj.push(6.5);

	obj.showstructure();
	obj.push(-3.0);
	obj.push(-8.0);

	obj.showstructure();
	obj.pop();
	obj.pop();
	obj.showstructure();


	return 0;
}