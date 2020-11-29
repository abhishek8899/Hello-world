#include <bits/stdc++.h>
using namespace std;

int maxShared(int nodes, vector<int> from, vector<int> to, vector<int> w)
{
	int n=from.size();
	set<int> neig[nodes+5];
	
	for(int i=0;i<n;i++)
	{
		neig[from[i]].insert(w[i]);
		neig[to[i]].insert(w[i]);
	}
	long long int mx=0;
	int maxCon=0;
	for(int i=1;i<=nodes;i++)
		for(int j=i+1;j<=nodes;j++)
		{
			int cnt=0;
			for(auto it=neig[i].begin();it!=neig[i].end();it++)
			{
				auto it1=neig[j].find(*it);
				if(it1!=neig[j].end())
					cnt++;
			}
			if(cnt>maxCon)
			{
				mx=i*j;
				maxCon=cnt;
			}
			else if(cnt==maxCon)
				mx=max(mx,(long long int)i*j);
		}
	return mx;
}

int main()
{
	int nodes=4;
	vector<int> from{1,1,2,2,2};
	vector<int> to{2,2,3,3,4};
	vector<int> w{2,3,1,3,4};
	cout << maxShared(nodes, from, to, w);
}
