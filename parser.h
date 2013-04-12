//Parser.h
#include <iostream>
#include <cstdlib>
#include <cctype>
#include <cstring>
using namespace std;

enum types { DELIMITER = 1, VARIABLE, NUMBER};
class parser {
	char *exp_ptr;  // points to the expression
	char token[80]; // holds current token
	char tok_type;  // holds token's type
	
	void eval_exp2(double &result);
	void eval_exp3(double &result);
	void eval_exp4(double &result);
	void eval_exp5(double &result);
	void eval_exp6(double &result);
	void atom(double &result);
	void get_token();
	void serror(int error);
	int isdelim(char c);
public:
	parser();
	double eval_exp(char *exp);
};
