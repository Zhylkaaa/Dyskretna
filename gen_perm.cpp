#include "/Users/dimazhylko/CPPProjects/bits/stdc++.h"
//#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

#define DIM 11

int P[DIM];

void print(int P[], int n){
	for(int i = 0;i<n;i++){
			cout<<P[i]<<" ";
		}
		cout<<'\n';
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;

    for(int i = 0;i<n;i++){
    	P[i]=i+1;
    }

    while(true){

    	print(P,n);

    	int i;
    	for(i = n-2;i>=0;i--){
    		if(P[i] < P[i+1])break;
    	}

    	if(i==-1)break;

    	int j;
    	for(j = n-1;j>i;j--){	
    		if(P[j] > P[i])break;
    	}

    	swap(P[i],P[j]);

    	
    	for(int k = 1;k<=(n-i-1)/2;k++){
    		swap(P[i+k], P[n-k]);
    	}
    }


	return 0;
}