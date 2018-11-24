#include "/Users/dimazhylko/CPPProjects/bits/stdc++.h"
//#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

bool U[101];

int find_nast(int A[], int n, int el){
	for(int i = 1;i<=n;i++){
		if(A[i]==el)return i;
	}
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int P1[100];
	int P2[100];

    int n;
    cin>>n;

    for(int i = 1;i<=n;i++)cin>>P1[i];
    for(int i = 1;i<=n;i++)cin>>P2[i];

    vector<int> cykl;
	
	int len = 0;
	
	for(int i = 1;i<=n;i++){
		if(!U[P1[i]]){
			U[P1[i]]=true;
			int liczba_pocz = P1[i];
			cykl.push_back(liczba_pocz);
			int liczba_nast = P2[liczba_pocz];

			while(liczba_pocz!=liczba_nast && !U[liczba_nast]){
				U[liczba_nast] = true;
				cykl.push_back(liczba_nast);

				liczba_nast = P2[liczba_nast];
			}

			cout<<"(";
			for(int i = 0;i<cykl.size();i++){
				cout<<cykl[i];
			}
			cout<<")";
			len+=cykl.size()-1;
			cykl.clear();
		}
	}

	cout<<endl;

	if(len%2==0)cout<<"Parzysta"<<endl;
	else cout<<"Nie parzysta"<<endl;
	
	return 0;
}