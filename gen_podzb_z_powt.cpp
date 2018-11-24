#include "/Users/dimazhylko/CPPProjects/bits/stdc++.h"
//#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

void print(int A[], int n){
	for(int i=0;i<n;i++){
		cout<<A[i]<<" ";
	}
	cout<<'\n';
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin>>n>>k;

    int A[20];

    for(int i = 0;i<k;i++){
    	A[i]=1;
    }

    print(A, k);

    while(true){
    	while(A[k-1]<n){
    		A[k-1]++;
    		print(A,k);
    	}

    	int i = k-2;
    	while(i>=0 && A[i]==A[i+1])i--;
    	if(i==-1)break;

    	A[i]++;
    	for(int j=i+1;j<k;j++){
    		A[j] = A[j-1];
    	}
    	print(A, k);
    }

	return 0;
}