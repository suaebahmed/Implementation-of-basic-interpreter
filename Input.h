//INPUT FUNCTION
class INPUT:public base
{
public:
	void execute(std::vector<std::vector<string> >arr,map<string, double> &variables,int &line,int lines){

		//extract value from string and assign to map
		string key = arr[line][2];
		//checks if inputed value is integer//
		if (isInteger(key)==false){
			double val;
			cin >> val;
			variables[key] = val;
		}
		else{
			throw NumberInputException();  //throws exeception
		}

	}
	inline bool isInteger(const std::string & s);

	~INPUT() = default;
};
//checks whether an argument is an integer or not
inline bool INPUT:: isInteger(const std::string & s)
{
	if(s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+'))) return false ;
	char * p ;
	strtol(s.c_str(), &p, 10) ;
	return (*p == 0) ;
}

