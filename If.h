class IF : public Base {
private:
    char operatorChar;
    std::string operand1, operand2;
    int operandValue1, operandValue2;
    std::string resultVar;
    int resultValue;

public:
	int checkCondition(int A,int B,string Operator){
		if (Operator==">"){if(A>B){return 1;} else{return 0;}}
		if(Operator=="<"){if(A<B){return 1;} else{return 0;}}
		if(Operator=="=="){if(A==B){return 1;} else{return 0;}}
		return 0;
	}
	bool isInteger(const std::string &s) {
		if(s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+'))) return false;
		char * p;
		strtol(s.c_str(), &p, 10);
		return (*p == 0);
	}
	int compute(int operand1, int operand2, char operatorChar) {
		switch (operatorChar) {
			case '+': return operand1 + operand2;
			case '-': return operand1 - operand2;
			case '*': return operand1 * operand2;
			case '/': return operand1 / operand2;
			case '=': return operand1;
			default: throw std::runtime_error("Invalid operator");
		}
	}
    void execute(std::vector<std::vector<string>>arr, map<string, double> &variables, int &line, int lines){

        string var1 = arr[line][2];
		string op = arr[line][3];
        string var2 = arr[line][4];

		int A = 0, B = 0;

        resultVar = arr[line][6];
		if(resultVar == "BREAK"){
			line++;
			return;
		}

		operand1 = arr[line][8];
        operatorChar = arr[line][9][0];
		operand2 = arr[line][10];



        
		// 1st case: 1 IF A < B THEN C = C + 1
		if(isInteger(var1)) A = std::stoi(var1);
		else if(variables.find(var1) != variables.end()) A = variables[var1];
		else throw std::runtime_error("Variable is not defined!");
		
		if(isInteger(var2)) B = std::stoi(var2);
		else if(variables.find(var2) != variables.end()) B = variables[var2];
		else throw std::runtime_error("Variable is not defined!");
		

		if(checkCondition(A, B, op)){
			if(isInteger(operand1)) operandValue1 = std::stoi(operand1);
			else{
				if (variables.find(operand1) != variables.end()) {
					operandValue1 = variables[operand1];
				} else {
					throw std::runtime_error("Variable is not defined!");
				}
			}
			if(isInteger(operand2)) operandValue2 = std::stoi(operand2);
			else{
				if (variables.find(operand2) != variables.end()) {
					operandValue2 = variables[operand2];
				} else {
					throw std::runtime_error("Variable is not defined!");
				}
			}
			if (variables.find(resultVar) == variables.end()) throw std::runtime_error("Variable is not defined!");
			
			resultValue = compute(operandValue1, operandValue2, operatorChar);
			variables[resultVar] = resultValue;
		}
    }
};

