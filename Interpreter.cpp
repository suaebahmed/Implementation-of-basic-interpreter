#include<iostream>
#include<stdlib.h>
#include<map>
#include<string>
#include<sstream>
#include<vector>
#include<cstring>
#include<vector>
#include<fstream>
#include<ctype.h>
#include<bits/stdc++.h>

using namespace std;
#ifndef ONLINE_JUDGE
#include<debug.h>
#else
#define dbg(x...)
#endif

//Exception declarations
class EndQuotesException{};
class InitialQuotesException{};
class NumberInputException{};
class ENDIFException{};
class GOTOEXException{};
class WrongstatementException{};
class Nonexistentvariable{};

#include "Base.h"
#include "Let.h"
#include "GOTO.h"
#include "IF.h"
#include "Print.cpp"

//MAIN PROGRAM CLASS
class program{

private:
	string Filename;
	std::vector<std::vector<string>> arr;
	map<string, double> mymap;
	std::map<int, Base*> lines;
	int line=0;
	int length=0;
public:

	void File(const char* const FileName);
	vector<string> separate(string line);
	void create();
	int errorcheck(int i);
	void execute();

};

void program::create(){
    if(arr[line][1]=="LET")
    {
        Let* ptr = new Let();
        lines[line] = ptr;
        // Check if all variables used in the Let statement are defined
        try {
            lines[line]->execute(arr, mymap, line, length);
        } catch (std::runtime_error& e) {
            std::cerr << "Error: " << e.what() << ". Please ensure all variables are defined before they are used." << std::endl;
            exit(EXIT_FAILURE);
        }
    }
	else if(arr[line][1]=="IF")
	{
		IF* ptr=new IF();
		lines[line]=ptr;
		lines[line]->execute(arr,mymap,line,length);
	}
	else if(arr[line][1]=="PRINT")
	{
		Print* ptr=new Print();
		lines[line]=ptr;
		lines[line]->execute(arr,mymap,line,length);
	}
	else if(arr[line][1]=="GOTO")
	{
		GOTO* ptr=new GOTO();
		lines[line]=ptr;
		lines[line]->execute(arr,mymap,line,length);
	}
	line++;

}
//separates the each line by spaces and returns the words within a line as an array.
vector<string> program::separate(string line)
{
	string buff;
	stringstream ss(line);
	vector<string> tokens;
	while(ss>>buff) tokens.push_back(buff);

	// // cout<<"\n--------token from each line---------------\n";
	// for(auto& token: tokens) cout<<token<<" | ";
	// cout<<endl;

	return tokens;
}

//uses the function separate to create a 2D vector and does this for each of the lines
void program::File(const char* const FileName)
{

	std::ifstream infile(FileName);
	string line1;
	length=0;
	while (std::getline(infile, line1))
	{
		length++;
		vector<string> tokens = separate(line1);
		arr.push_back(tokens);
		if(errorcheck(length - 1)==0){
			throw WrongstatementException();
		}
	}
}

//INITIAL ERRORCHECKING
int program::errorcheck(int i){
	//checks that the statements entered are correct
	if(arr[i][1]=="PRINT"||"LET"||"GOTO"||"IF"||"INPUT"||"ENDIF") return 1;
	return 0;
}

//EXECUTE FUNCTION- STARTS THE LINE READING AND STATEMENT EXECUTION
void program::execute()
{
	while(line<length)
	{    //while loop goes through each line and executes the statement
		create(); //creates the nodes dynamically
	}
	lines.clear();   //clears the map once program in is finished//
}

int main(int argc, char** argv)
{
	program p;
	//catches exception for errors in different classes
	try {
		p.File(argv[1]);
		p.execute();
	}
	catch (EndQuotesException& e){
		cerr << "Missing end quotes" << endl;
	}
	catch (InitialQuotesException& e){
		cerr << "Missing beginning quotes"<<endl;
	}
	catch (NumberInputException& e){
		cerr << "Invalid key, cannot be integer"<<endl;
	}
	catch (ENDIFException& e){
		cerr << "Non matching IFs and ENDIFs"<<endl;
	}
	catch (GOTOEXException& e){
		cerr << "LINE number is not defined!"<<endl;
	}
	catch (WrongstatementException& e)
	{
		cerr << "Incorrect statement"<<endl; //catches exception for wrong statement
	}
}
