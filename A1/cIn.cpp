#include <iostream>
#include <sstream>
using namespace std;

int main(){
	cout << "please enter something for me to read" << endl;
	string input;
	bool exit = false;
	while(!exit){
		getline(cin, input);
		if((input.at(0) == 'b') and (input.at(1) == 'f') and (input.at(2) == ' ')){
			cout << "Answer: " << input[0] << endl;
		}
		else if(input == "exit"){
			exit = true;
		}
		else{
			cout << "Not the correct format" << endl;
		}
	
	}
	return 0;	
}
