#include <iostream>
using namespace std;

int bf(string s, string p){
	int n = s.length();
	int m = p.length();
	for (int i=0; i<n-m; i++){
		j=0;
		while((j<m) and (s[i+j] = p[j])){
			j=j+1;
		}
		if(j==m){
			return i;}
	}
	return void;
}
