//GOTO CLASS
class GOTO: public Base{
public:
	inline bool isInteger(const std::string & s);
	void execute(std::vector<std::vector<string> >arr,map<string, double> &variables,int &line,int lines);
	~GOTO() = default;
};
inline bool GOTO::isInteger(const std::string & s)
{
	if(s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+'))) return false ;
	char * p ;
	strtol(s.c_str(), &p, 10) ;
	return (*p == 0) ;
}

//execute checks if line number is a number and finds the corresponding line with the same characters in the stored vector
void GOTO::execute(std::vector<std::vector<string> >arr,map<string, double> &variables,int &line,int lines)
{
	string element = arr[line][2];
	if (isInteger(element))
	{
		for(int i=0; i<lines; i++)
		{
			if(arr[i][0]==element)
			{
				line = i - 1;
				return;
			}
		}
	}
	throw GOTOEXException();
}