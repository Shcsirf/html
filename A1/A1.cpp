#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

void bf(string s, string p){
	int n = s.length();
	int m = p.length();
	for (int i=0; i<=(n-m); i++){
		int j=0;
		while((j<m) and (s[i+j] == p[j])){
			j=j+1;
		}
		if(j==m){
			cout<< (i+1) << " ";
		}
	}
}

vector<int> compute_MP_map(string p){
	int m = p.length();
	vector<int> MP_map(m, -1);
	int i=0;
	int j = MP_map[i];
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

void MP(string s, string p){
	vector<int> MP_map = compute_MP_map(p);
	int i = 0;
	int n = s.length();
	int m = p.length();
	for(int j=0; j<=n-1; j++){
		while((i>=0) and (s[j] != p[i])){
			i = MP_map[i];
		}
		i = i + 1;
		if(i==m){
			int pst = (j-m)+1;
			cout<< (pst+1) << " ";
			i = MP_map[i];
		}
	}
}

int main(){
        cout<< "Enter bf or mp, your pattern in double quotes, and your file name" << endl;
	cout<< "Example: \n" << "bf " << "\"pattern\" " << "FileName.txt" << endl;
        string input, pattern, file, line;
	ifstream ifs;
	bool exit = false;
	while(!exit){
		getline(cin, input);
		if(input == "exit"){
			break;
		}
		if(input.length() < 4){
			cout<< "Please make sure you use the correct format" << endl;
			break;
		}
		else if(input.at(3) == '"'){
			bool pck = true;
			int r;
			for(r=4; r < input.length(); r++){
				if(input.at(r) == '"'){
					r = r+2;
					pck = false;
				}	
				if(pck){	
					pattern = pattern + input.at(r);
				}
				else{
					file = file + input.at(r);
				}
			}
		}
		else{
			cout<< "Please make sure you use correct format" << endl;
			break;
		}
		int i = 1;
		ifs.open(file.c_str());
		if(ifs.fail()){
			cerr<< "Error: Could not open file, did you use the correct format? " << file << endl;
			ifs.clear();
		}		
		else{
			if((input.at(0) == 'b') and (input.at(1) == 'f')){
				while(getline(ifs, line)){
					cout << "Line " << i++ << ": ";  
					bf(line, pattern);
					cout<< endl;	
				}
				ifs.close();
			}                                 
			else if((input.at(0) == 'm' ) and (input.at(1) == 'p' )){
				while(getline(ifs, line)){
					cout << "Line " << i++ << ": ";  
					MP(line, pattern); 
					cout<< endl;	

				}
				ifs.close();
			}
			else{                             
				cout<< "Not the correct format" << endl;
			}                                 
		}
		line = "";
		input = "";
		pattern = "";
		file = "";
	}
        return 0;                         
}   
