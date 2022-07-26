#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
string s[10000];
int main()
{
	int n;
	cin>>n;
	s[0]="*";
	for(int i=1;i<n;i*=3)
	{
		for(int j=0;j<i;j++)
		{
			string s1 = s[j]+s[j]+s[j];
			string s2 = s[j]+string(i,' ')+s[j];
			s[j+2*i] = s[j] = s1;
			s[j+i] = s2;
		}
	}
	for(int i=0;i<n;i++)
		cout<<s[i]<<"\n";
}