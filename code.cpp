#include<bits/stdc++.h>
using namespace std;
bool isSafe(int num,vector<vector<int>> &v,int i,int j)
{
	for(int k=0;k<9;k++)
	if(v[i][k]==num||v[k][j]==num)
	return false;
	int l=(i/3)*3;
	int m=(j/3)*3;
	for(int p=l;p<l+3;p++)
	for(int q=m;q<m+3;q++)
	if(v[p][q]==num)
	return false;
	return true;
}
bool Solve(vector<vector<int>>&v,int i,int j)
{
	if(i==9)
	return true;
	if(j==9)
	return Solve(v,i+1,0);
	if(v[i][j]==0)
	{
		for(int num=1;num<=9;num++)
		{
			if(isSafe(num,v,i,j))
			{
			v[i][j]=num;
			bool r=Solve(v,i,j+1);
			if(r)
			return true;
			v[i][j]=0;
		}
	}
	return false;
	}
	else
	return Solve(v,i,j+1);
}
int main()
{
	int n;
	cin>>n;
	vector<vector<int>>v;
	for(int i=0;i<n;i++)
	{
		vector<int>v1;
		for(int j=0;j<n;j++)
		{
			int p;
			cin>>p;
			v1.push_back(p);
		}
		v.push_back(v1);
	}
	bool r=Solve(v,0,0);
	if(r)
	{
		 for (int i = 0; i < v.size(); i++) { 
        for (int j = 0; j < v[i].size(); j++) 
            cout << v[i][j] << " "; 
        cout << endl; 
    } 
	}
	return 0;

}
