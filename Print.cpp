//PRINT Class
class Print:public Base{
public:
	bool isInteger(const std::string &s) {
		if(s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+'))) return false;
		char * p;
		strtol(s.c_str(), &p, 10);
		return (*p == 0);
	}
    void execute(std::vector<std::vector<string>>arr, map<string, double> &variables, int &line, int lines){
        int length = arr[line].size();
		// 1 case: 7 PRINT C
		if (length == 3) {
			if (variables.find(arr[line][2]) != variables.end()) {
				std::cout << variables[arr[line][2]] << std::endl;
			} 
			else if(isInteger(arr[line][2])){
				std::cout << arr[line][2] << std::endl;
			}
			else {
            	throw std::runtime_error("Variable is not defined!");
			}
		}
		else{
			// 2 case: 6 PRINT "The sum is ", C
			string str = "";
			int i = 2;
			for (i = 2; i < length; i++) {
				bool isComma = false;
				for(auto c: arr[line][i]){
					if(c == ',') isComma = true;
					if(c == '"' || c == ',') continue;
					str += c;
				}
				if(isComma) break;
				str += " ";
			}
			std::cout << str << " ";
			if(i == length){
				std::cout << std::endl;
				return;
			}
			// print last variable
			if (variables.find(arr[line].back()) != variables.end()) {
				std::cout << variables[arr[line].back()] << " ";
			} 
			else if(isInteger(arr[line].back())){
				std::cout << arr[line].back() << " ";
			}
			else {
				throw std::runtime_error("Variable is not defined!");
			}
			std::cout << std::endl;
		}
    }
    ~Print() = default;
};