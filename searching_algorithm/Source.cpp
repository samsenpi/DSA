
#include "iostream"

using namespace std;

int intersection2(int a[], int b[], int *c, int n)
{

	for (int i = 0; i < n; i++)
	{
		
			if (a[i] == b[i])
			{
				c[i] = a[i];
			}
		

	}
	return *c;
}
int intersection1(int a[],int b[],int *c,int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++) {
			if (a[i] == b[j])
			{
				c[i] = a[i];
			}
		}

	}

	return *c;

}

int main() {

	int a[5], b[5], c[5] = {0};
	int j = 4;
	for (int i = 0; i < 5; i++)
	{
		a[i] = i + 1;
		cout<<"b["<<i<<"}"<<endl;
		cin >> b[i];
		
		

	}

	cout << "array A[]:" << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << a[i]<<endl;
	}

	cout << "array b[]:" << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << b[i]<<endl;
	}
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                

	intersection2(a, b, c, 5);
	cout << "After intersectio2:" << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << c[i] << endl;
	}

	return 0;
}
