#include "iostream"
using namespace std;

class Student
{
	friend class StudentMaxHeap;
	private:
	double cgpa; /**Student’s CGPA*/
	int rollNo; /**Student’s roll number*/
public:
	Student(int ro=0, double gpa=0.0) {

		rollNo = ro;
		cgpa = gpa;

	}
};
	/**Manages an array of students arranged like a Max Heap.*/
class StudentMaxHeap
{
private:
		Student* arr;
		int curSize; /**Current number of students present in the heap*/
		int maxSize; /**Maximum number of students that can be present in heap*/


		void heapify( int i) {
			int max = i;
			int l = 2 * i + 1;
			int r = 2 * i + 2;

			if (l < curSize && (arr[max].cgpa < arr[l].cgpa ||(arr[l].cgpa == arr[max].cgpa && arr[l].rollNo < arr[max].rollNo))) {
				max=l;
			}

			if (r < curSize && (arr[r].cgpa > arr[max].cgpa ||(arr[r].cgpa == arr[max].cgpa && arr[r].rollNo < arr[max].rollNo))) {
				max=r;
			}

			if (max != i) {
				swap(arr[i], arr[max]);
				heapify(max);
			}
		}

public:
	StudentMaxHeap(int size) {

		this->maxSize = size;
		curSize = 0;
		arr = new Student[maxSize];

	}
	~StudentMaxHeap() {
		delete[] arr;

	}
	bool isEmpty() /**Checks whether the heap is empty or not*/
	{
		if (curSize ==-1) {
			
			return true;
		}
			return false;
		
		

	}
	bool isFull() /**Checks whether the heap is full or not*/
	{
		if (curSize >= maxSize) {
			return true;
		}
		return false;
	}bool insert(int rollNo, double cgpa) {

		if (curSize >= maxSize)
		{
			return false;
		}else 
		{

			
			arr[curSize] = Student(rollNo, cgpa);
			int np = curSize;
			curSize++;
			int parent = (np - 1) / 2;

			
			while (np != 0 ) {
			
				if (arr[np].cgpa > arr[parent].cgpa||arr[np].cgpa == arr[parent].cgpa && arr[np].rollNo < arr[parent].rollNo) {

					swap(arr[np], arr[parent]);
					np = parent;
				}
			}
		}
		return true;
	}bool remove(int& rollNo, double& cgpa) {
		if (isEmpty()) {
			return false;
		}

		rollNo = arr[0].rollNo;
		cgpa = arr[0].cgpa;

		arr[0] = arr[curSize - 1];
		curSize--;

		int currentIndex = 0;
		while (true) {
			int leftChildIndex = 2 * currentIndex + 1;
			int rightChildIndex = 2 * currentIndex + 2;
			int maxIndex = currentIndex;

			if (leftChildIndex < curSize && (arr[leftChildIndex].cgpa > arr[maxIndex].cgpa ||
				(arr[leftChildIndex].cgpa == arr[maxIndex].cgpa &&
					arr[leftChildIndex].rollNo < arr[maxIndex].rollNo))) {
				maxIndex = leftChildIndex;
			}

			if (rightChildIndex < curSize && (arr[rightChildIndex].cgpa > arr[maxIndex].cgpa ||
				(arr[rightChildIndex].cgpa == arr[maxIndex].cgpa &&
					arr[rightChildIndex].rollNo < arr[maxIndex].rollNo))) {
				maxIndex = rightChildIndex;
			}

			if (maxIndex != currentIndex) {
				swap(arr[currentIndex], arr[maxIndex]);
				currentIndex = maxIndex;
			}
			else {
				break;
			}
		}

		return true;
	} void displayStudentList() {
		
		
		Student* displayArr = new Student[curSize];
		copy(arr, arr + curSize, displayArr);

		for (int i = curSize / 2 - 1; i >= 0; i--) {
			heapify( i);
		}
		for (int i = curSize - 1; i > 0; i--) {
		
			swap(displayArr[0], displayArr[i]);
			heapify( i);
		}

		cout << "List of students:" << endl;
		for (int i = 0; i < curSize; i++) {

			cout << "Roll No: " << displayArr[i].rollNo << ", CGPA: " << displayArr[i].cgpa << endl;
		}

		delete[] displayArr;
	}

	void levelOrder() {
		if (isEmpty()) {
			cout << "Heap is empty." << endl;
			
		}

		cout << "Heap: Level order traversal:" << endl;

		int levelSize = 1;
		int levelCount = 0;

		for (int i = 0; i < curSize; i++) {
			cout << arr[i].rollNo << " " << arr[i].cgpa << "  ";
			levelCount++;

			if (levelCount == levelSize) {
				cout << endl;
				levelSize *= 2;
				levelCount = 0;
			}
		}

		cout << endl;
	}




};
int main() {

	
		int maxSize;
		cout << "Enter the maximum number of students in the heap: ";
		cin >> maxSize;

		StudentMaxHeap maxHeap(maxSize);
		cout << "Menu:\n";
		cout << "1. Insert a new student\n";
		cout << "2. Remove (and display) the student with the Max CGPA\n";
		cout << "3. Display the list of students (Descending order of CGPA)\n";
		cout << "4. Display the list of students (Level-order traversal)\n";
		cout << "5. Exit\n";
		
		int count = 0;
		while (count<=3) {
			cout << "Enter your choice: ";
			int choice;
			cin >> choice;
			
			switch (choice) {
			case 1: {
				int rollNo;
				double cgpa;
				cout << "enter roll no.: ";
				cin >> rollNo;
				cout << "enter cgpa: ";
				cin >> cgpa;

				if (maxHeap.insert(rollNo, cgpa)) {
					cout << "Student inserted successfully.\n";
				}
				else {
					cout << "Failed to insert student. Heap is full.\n";
				}
				break;
			}

			case 2: {
				int rollNo;
				double cgpa;
				if (maxHeap.remove(rollNo, cgpa)) {
					cout << "Student removed - Roll No: " << rollNo << ", CGPA: " << cgpa << "\n";
				}
				else {
					cout << "Heap is empty. Unable to remove.\n";
				}
				break;
			}

			case 3:
				maxHeap.displayStudentList();
				break;

			case 4:
				maxHeap.levelOrder();
				break;

			case 5:
				cout << "Exiting the program.\n";
				return 0;

			}
			count++;
		}

	return 0;
}