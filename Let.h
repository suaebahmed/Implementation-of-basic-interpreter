#include <sstream>
#include <map>
#include <vector>
#include <string>
#include <stdexcept>

class Let : public Base {
private:
    std::vector<string> input;
    char operatorChar;
    std::string operand1, operand2;
    int operandValue1, operandValue2;
    std::string resultVar;
    int resultValue;

public:
    void parseInput();
    bool isInteger(const std::string & s);
    void validateVariables(std::map<std::string, double>& variables);
    int compute(int operand1, int operand2, char operatorChar);
    void execute(std::vector<std::vector<std::string>> arr, std::map<std::string, double>& variables, int& line, int lines);
    ~Let() {}
};
// Identify the operator and operands
void Let::parseInput() {
    std::string operators = "+*-/";
    operatorChar = '=';
    for(int i=1; i<input.size(); i++){
        if(input[i].size() > 1) continue;
        for(int j=0; j<4; j++){
            if(operators[j] == input[i][0]) 
                operatorChar = input[i][0];
        }
    }
    // 1 LET A = 100;
    resultVar = input[2];
    operand1 = input[4];
    if(input.size() <= 5) return;

    // 1 LET A = 100 + 433
    operand2 = input[6];
}

bool Let::isInteger(const std::string &s) {
    if(s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+'))) return false;
    char * p;
    strtol(s.c_str(), &p, 10);
    return (*p == 0);
}

void Let::validateVariables(std::map<std::string, double>& variables) {
    if (isInteger(operand1)) {
        operandValue1 = std::stoi(operand1);
    } else {
        if (variables.find(operand1) != variables.end()) {
            operandValue1 = variables[operand1];
        } else {
            throw std::runtime_error("Variable is not defined!");
        }
    }

    if(operand2.empty()){
        operandValue2 = 0;
        return;
    }
    if (isInteger(operand2)) {
        operandValue2 = std::stoi(operand2);
    } else {
        if (variables.find(operand2) != variables.end()) {
            operandValue2 = variables[operand2];
        } else {
            throw std::runtime_error("Variable is not defined!");
        }
    }
}

int Let::compute(int operand1, int operand2, char operatorChar) {
    switch (operatorChar) {
        case '+': return operand1 + operand2;
        case '-': return operand1 - operand2;
        case '*': return operand1 * operand2;
        case '/': return operand1 / operand2;
        case '=': return operand1;
        default: throw std::runtime_error("Invalid operator");
    }
}

void Let::execute(std::vector<std::vector<std::string>> arr, std::map<std::string, double>& variables, int& line, int lines) {
    input = arr[line];
    parseInput();
    validateVariables(variables);
    resultValue = compute(operandValue1, operandValue2, operatorChar);
    variables[resultVar] = resultValue;
    // dbg(input, operatorChar, operand1, operand2, operandValue1, operandValue2, resultValue, resultVar);
}
