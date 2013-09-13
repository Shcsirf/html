#include <iostream>
#include <fstream>
#include <vector>

using std::string;
using std::cout;
using std::endl;
using std::ifstream;
using std::cin;
using std::cerr;

int main(){
	string input, algo, file1, file2;
	ifstream ifs1, ifs2;
	cout << "Please enter slow or fast followed by a space, your first ";
	cout << "file followed by a space, then your second file. Example:" << endl;
	cout << "slow file1 file2" << endl;
	while(getline(cin, input)){
		if(input == "exit"){
			break;
		}
		int spaceCounter = 0;
		for(int i=0; i<input.length(); i++){
			if(input.at(i) == ' '){
				spaceCounter++;
				i++;
			}
			if(spaceCounter == 1){
				file1 += input.at(i);
			}
			else if(spaceCounter == 2){
				file2 += input.at(i);	
			}
			else{
				algo += input.at(i);
			}
		}	
		ifs1.open(file1.c_str());
		ifs2.open(file2.c_str());
		if(ifs1.fail() || ifs2.fail()){
			cerr << "Error: Are you sure you're using the correct format?" << endl;
			continue;
		}
		
	}
	
	return 0;
}
