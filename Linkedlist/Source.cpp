#include "iostream"
#include "fstream"
#include"string"
using namespace std;
 

class Student {
	
	friend class StudentList;

private: 
	
	int id;  /**id of a student*/
	string name;  /**name of a student*/
	float cgpa;  /**cgpa of a student*/ 
	Student* next; /**address of the next available object*/
public:
	Student(int id, string name, float cgpa, Student* next) /**constructor*/
	{
		this->id = id;
		this->name = name;
		this->cgpa = cgpa;
		this->next = next;


	}
		
		
	void studentDetails() const /**displays the student informaton*/
	{
		
		cout << "Student id :"<<id << endl;
		cout <<"Student name :" <<name << endl;
		cout <<"Student cgpa :" <<cgpa << endl;

	}

};

class StudentList {

private:
	
	Student* head;  /**start of the list*/  
	Student* cursor;  /**current item of the list*/

public:
	StudentList() {

		head = NULL;

		cursor = NULL;

	}
	void insert(const Student& newStd) {

		Student* temp=new Student(newStd.id, newStd.name, newStd.cgpa,NULL);
		if (head == NULL) {
			
			head = temp;
			cursor = temp->next;


		}
		else {

			cursor->next = temp;

			cursor = temp->next;
		}

	}
	void remove(int id) 
	{

		if (head == NULL) {
			cout << "list is empty" << endl;
		}else if(head->id == id) {

			delete head;
			head = NULL;
		}
		else 
		{

			
			Student* temp=head->next;
			Student* temp_pre=head;

			while (temp->id != id)
			{
				temp_pre = temp;
				temp = temp->next;
			}
		
			
			if (temp->next == NULL)
			{
				delete temp;
				temp_pre -> next = NULL;
				cursor = head;
			}else if (cursor->id == temp->id) {

				cursor = cursor->next;

				temp_pre = temp->next;
				delete temp;

			}
			else {


				temp_pre = temp->next;
				delete temp;
			

			}
			


		
		}
	}void search(float cgpa) const {

		Student* temp = head;

		while (temp->next != NULL) {

			if (temp->cgpa == cgpa) {
		
				temp->studentDetails();

			}

			temp = temp->next;
		}


	}void replace(const Student& newStd)
	{
		Student* temp = new Student(newStd.id, newStd.name, newStd.cgpa, NULL);
		Student* cur = head->next;

		if (head == NULL) {
			cout << "empty list";
		}
		else if (head->id == temp->id)
		{
			head = temp;
		}
		else {

			while (cur->next != NULL) {

				if (cur->id == temp->id) {
				
					cur= temp;
					cursor = cur;
					exit(0);
				}
				cur = cur->next;

			}
			cur->next = temp;
			cursor = cur;
			//temp->next = NULL;

		}
	}bool isEmpty() const {

		
		return (head->next == NULL);
	}void gotoBeginning() {

		cursor = head;
	}
	void gotoEnd() {

		Student* temp = head;

		while (temp->next != NULL) {

			temp = temp->next;
		}
		cursor = temp;

	}bool gotoNext() {

		if (cursor->next != NULL) {

			cursor = cursor->next;
			return true;
		}
		return false;
	}bool gotoPrior() {
		Student* temp=head;

		if (cursor == head) {
			return false;
		}

		while (temp->next == cursor) {
			temp = temp->next;
		}
		cursor = temp;
	}Student  getCursor() {

		return *cursor;
	}void showStructure() const {

		if (head == NULL)
		{
			cout << "Empty list" << endl;
		}
		else {
			Student* temp = head;
			while (temp->next != NULL) {

				temp->studentDetails();
			}

		}
	
	
	}


	~StudentList()/**destructor*/
	{

	}
};


int main() {

	

	ifstream inf("input.txt");

	if (!inf) {
		cerr << "file not open" << endl;
		exit(0);
	}
	int id;
	string str;
	float cgpa;

	inf >> id;
	inf >> str;
	inf >> cgpa;

	Student s1(id, str, cgpa,NULL);
	s1.studentDetails();
	StudentList  l1;

	l1.insert(s1);
	if (l1.isEmpty()) {
		cout << "list not emptu";
	}
	else {
		cout << "list emptu";

	}
	
	l1.showStructure();

	return 0;                          
}