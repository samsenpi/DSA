#include "iostream"
#include "fstream"
using namespace std;

struct Point3D
{
	float x, y, z;
};

class PointList
{
	Point3D* ar;
	int maxSize;
	int curSize;
	int cursor;


public:
	PointList(int s)
	{
		this->maxSize = s;
		this->cursor = -1;
		ar = new Point3D[maxSize];

		for (int i = 0;i < maxSize;i++)
		{
			ar[i].x = 0.0f;
			ar[i].y = 0.0f;
			ar[i].z = 0.0f;

		}


	}
	bool isEmpty()
	{
		int count = 0;
		/*if (curSize == maxSize) {
			return true;
		}
		else {
			return false;
		}*/
		for (int i = 0;i < maxSize;i++)
		{
			if ((ar[i].x == 0.0f)&&(ar[i].y == 0.0f)&&(ar[i].z == 0.0f))
			{
				count++;
			}
		}
		if (count == maxSize)
		{
			return true;
		}
		else {

			return false;
		}
	}
	bool isFull()
	{
		int count = 0;
		for (int i = 0;i < maxSize;i++)
		{
			if ((ar[i].x != 0.0f) || (ar[i].y != 0.0f) || (ar[i].z != 0.0f))
			{
				count++;
			}
		}
		if (count == maxSize)
		{
			return true;
		}
		else {

			return false;
		}

	}
	void showStructor()
	{
		if (this->isFull())
		{
			cout << "Empty list"<<endl;
		}
		else {

			for (int i = 0;i < maxSize;i++)
			{
				cout << "ar[" << i << "]:"<<endl;
				cout<<"x-axis=" << ar[i].x<<endl;
				cout <<"y-axis"<< ar[i].y<<endl;
				cout <<"z-axis"<< ar[i].z<<endl;

			}

		}
	}
	Point3D getCursor()
	{
		Point3D obj;
		int count = 0;
		for (int i = 0;i < maxSize;i++)
		{
			if ((ar[i].x == 0.0f) && (ar[i].y == 0.0f) && (ar[i].z == 0.0f))
			{
				count++;
			}
		}
		if (count != maxSize)
		{
			
			obj.x = ar[cursor].x;
			obj.y = ar[cursor].y;
			obj.z = ar[cursor].z;

			return obj;
		}
		else {
			cout << "error" << endl;

			Point3D obj;
			obj.x = -1;
			obj.y = -1;
			obj.z = -1;
			return obj;
			
		}
		
			


	}
	void insert(Point3D newPoint)
	{
		if (this->isEmpty())
		{
			ar[0] = newPoint;
			cursor = 0;
			curSize++;
		}
		else {

			
			if (!this->isFull())
			{
				ar[maxSize - 1] = newPoint;
			}
			else {
				cout << "list is full";
			}

		}
	}
	void goToBeginning() {

		if (!this->isEmpty())
		{
			cursor = 0;
		}
	}
	void goToEnd() {

		if (!this->isEmpty())
		{
			cursor = curSize;
		}
	}
	bool goToNext() {

		if (cursor != maxSize)
		{
			cursor++;
			return true;
		}
		return false;
	}
	bool goToprior() {

		if (cursor != 0)
		{
			--cursor;
			return true;
		}
		return false;
	}
	void clear() {

		for (int i = 0;i < maxSize;i++)
		{
			ar[i].x = 0.0f;
			ar[i].y = 0.0f;
			ar[i].z = 0.0f;

		}


	}
	bool replace(Point3D newPoint) {

		if (cursor >= 0 || cursor < maxSize)
		{
			ar[cursor].x = newPoint.x;
			ar[cursor].y = newPoint.y;
			ar[cursor].z = newPoint.z;

			return true;
		}
		else {
			return false;
		}
	}
	void remove() {
			
		ar[cursor].x = 0;

		ar[cursor].y = 0;
		ar[cursor].z = 0;
		if (!this->isEmpty()) {
			cursor = curSize;
		}else if((cursor) == maxSize) {
			cursor = 0;
		}


	}
	~PointList() {
		delete[]ar;

	}

};

int main()
{	
	PointList obj1(5);
	
	if (obj1.isEmpty())
	{
		cout << "empty" << endl;
	}
	else {
		cout << "Not empty" << endl;

	}
	if (obj1.isFull())
	{
		cout << "full" << endl;
	}
	else {
		cout << "full" << endl;

	}
	Point3D obj;
	obj.x = 1;
	obj.y = 2;
	obj.z = 3;
	//obj1.showStructor();
	obj1.insert(obj);
	
	
	obj1.showStructor();


	if (obj1.replace(obj))
	{
		cout << "it is replace sucessfully" << endl;

	}
	else {
		cout << "cursor is invalid" << endl;
	}
	obj1.goToEnd();
	if (obj1.goToNext())
	{
		cout << "cursor is not at end" << endl;
	}
	else {
		cout << "cursor is at the end" << endl;
	}
	
	return 0;
}