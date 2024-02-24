
#include"iostream"
#include "fstream"
#include "stack"
#include "string"
using namespace std;


//bool delimiterOk(const string& expre)
//{
//	
//	stack<char>obj;
//	int l = expre.length();
//	char top;
//
//	 //int count = 0,count2=0,count3=0,count4=0;
//	if (l <= 1) {
//
//		if (expre[0] != '(' || expre[0] != '[' || expre[0] != ')' || expre[0] != ']') {
//			return true;
//		}
//		else {
//			return false;
//		}
//	}
//	
//	
//	for (int i = 0; i < l; i++)
//	{
//		if ( expre[i] == '(' || expre[i] == '[')
//		{
//			obj.push(expre[i]);
//			
//		}
//		if (expre[i] == ')' && obj.top() == '(')
//		{
//			obj.pop();
//			
//		}
//		 if (expre[i] == ']' && obj.top() == '[')
//		{
//			 obj.pop();
//			
//		}
//		
//		
//	}	
//	if(obj.empty())
//	 return true;
//	else {
//		return false;
//	}
//}

int main()
{
	int a, b;
	int sum = (a + b/*[a]*/);
		cout << sum;
	/*ifstream inf("input.txt");

	if (!inf)
	{
		cerr << "file not open";
		exit(0);
	}
	
	string exp;

	while(getline(inf, exp))
	{
		if (delimiterOk(exp))
		{
			cout << "valid" << endl;
		}
		else {

			cout << "invalid" << endl;
		}
	

	}
	*/	
		
	return 0;
}