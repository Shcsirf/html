#include <iostream>
#include <vector>
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
	return 0;
}

vector<int> compute_MP_map(string p){
	m = p.length();
	vector<int> MP_map = [-1]*(m+1);
	i=0;
	j = MP_map[i];
	while(i<m){
		while((j>=0) and (p[i] != p[j])){
			j=MP_map[j];
		}
		j = j+1;
		i = i+1;
		MP_map[i]=j;
	}
	return MP_map;
}

