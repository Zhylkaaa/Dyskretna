//generacja podzialów na k bloki 

#include "/Users/dimazhylko/CPPProjects/bits/stdc++.h"
//#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 4;

int k = 1;

vector<int> bl;
vector<int> res[N+1];

void print(){
	for(int i = 0;i<N;i++){
		res[bl[i]].push_back(i+1);
	}

	for(int i = 1;i<=N;i++){
		if(res[i].size()==0)break;
		cout<<"{";
		for(int j = 0;j<res[i].size();j++){
			cout<<res[i][j]<<",";
		}
		cout<<"} ";
		res[i].clear();
	}
	cout<<endl;
}

void gen_bloki(int i, int l){
	for(int j = 1;j<=l+1;j++){
		bl.push_back(j);
		if(i==N-1){
			if((k==l && j<=l) || (k==l+1 && j==k))print();
		} else {
			if(j<l+1){
				if(k-l<=N-1-i)gen_bloki(i+1, l);
			} else {
				if(l+1 <= k)gen_bloki(i+1,l+1);
			}
		}
		bl.pop_back();
	}
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

	gen_bloki(0,0);

	return 0;
}