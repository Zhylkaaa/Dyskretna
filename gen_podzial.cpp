//generacja podzialów liczyby k na summu

#include "/Users/dimazhylko/CPPProjects/bits/stdc++.h"
//#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

void print(vector<int> podzial){
	for(int i = 0;i<podzial.size() && podzial[i]!=0; i++){
		cout<<podzial[i]<<" ";
	}
	cout<<endl;
}

void gen_podzial(vector<int> podzial, int l){
	int m = l - 1;
	int sum=0;

	while(true){
		while(m>=0 && podzial[m]==1){
			podzial[m]=0;
			m--;
		}
		if(m<0) return;

		sum = l - m;
		podzial[m]=podzial[m]-1;
		while(sum > 0){
			podzial[m+1]=min(sum, podzial[m]);
			sum-=podzial[m+1];
			m++;
		}
		l=m+1;
		print(podzial);
	}
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;

    vector<int> v(n, 0);
    v[0]=n;

    gen_podzial(v, 1);

	return 0;
}