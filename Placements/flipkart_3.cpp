#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int>score(n);
	for(int i=0; i<n; i++)
		cin >> score[i];
	sort(score.begin(),score.end());
	int pos = 0, neg = 0;
	for(int i=0; i<n; i++)
	{
		if(i>0 && score[i] == score[i-1])
		{
			if(score[i] >= 0)
				neg += score[i];
			else
				pos += score[i];
		}
		else if(score[i]>=0)
			pos += score[i];
		else
			neg += score[i];

	}
	cout << pos-neg << endl;
    return 0;
}