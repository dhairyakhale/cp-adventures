#include<iostream>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int i;
		for(i=0; i<3; i++)
		{
			char c;
			cin >> c;
			cout << c;
			if(i == 0 && (c == 'y' || c == 'Y')) continue;
			else if(i == 1 && (c == 'e' || c == 'E')) continue;
			else if(i == 2 && (c == 's' || c == 'S')) continue;
			else break;
		}
		if(i == 3) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}