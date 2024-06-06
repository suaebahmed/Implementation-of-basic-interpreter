class Base {
public:
    virtual void execute(std::vector<std::vector<string>> arr, map<string, double> &variables, int &line, int lines) = 0;
    virtual ~Base() {} // Virtual destructor
};