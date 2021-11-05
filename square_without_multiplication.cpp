#include<bits/stdc++.h>
using namespace std;
int fabo(int counter, int a, int b)
{
	if(counter!=0)
	{
		int c = a+b;
		cout<<c<<" ";
		b = c;
		a = b;
		counter--;
		fabo(counter, a, b);
	}
	return 0;
}
int main()
{
	fabo(10, 0, 1);
	return 0;
}
