//Zahra Agriphinna (2357051022)

#include <bits/stdc++.h>
using namespace std;

bool isOperator(char x){
	if(x == '+' || x == '-' || x == '*' || x == '/' || x == '%'){
		return true;
	}else{
		return false;
	}
}

int precendence(string x){
	if(x == "+" || x == "-"){
		return 1;
	}
	if(x == "*" || x == "/" || "%"){
		return 2;
	}
	return 0;
}

bool bigOne(string x, string y){
	int xValue, yValue;
	xValue = precendence(x);
	yValue = precendence(y);
	return xValue <= yValue;
}

vector <string> infix;
vector <string> postfix;
string temp;
vector <string>::iterator itr;
vector <string>::iterator it;

void input(){
	string str;
	char ch;
	while(cin.get(ch)){
		if(ch == '\n'){
			break;
		}
		if(ch != ' '){
			str.push_back(ch);
		}
	}
	int length = str.length();
	
	for(int i = 0; i < length; i++){
		if(str[i] == '(' || str[i] == ')'){
			if(temp.length() != 0){
				infix.push_back(temp);
				temp.clear();
			}
			infix.push_back(str.substr(i, 1));
		}
		if(isdigit(str[i]) || (str[i] == '-' && i == 0 && isdigit(str[i+1]))){
			temp.push_back(str[i]);
			continue;
		}
		if(isOperator(str[i])){
			if(temp.length() != 0){
				infix.push_back(temp);
				temp.clear();
			}
			if((str[i] == '-' && isOperator(str[i-1])) || (str[i] == '-' && i == 0 && str[i+1] == '(') || (str[i] == '-' && str[i-1] == '(')){
				infix.push_back("-1");
				infix.push_back("*");
			}else{
				infix.push_back(str.substr(i, 1));
			}
		}
	}
	if(temp.length() != 0){
		infix.push_back(temp);
		temp.clear();
	}
}

void toPostfix(){
	stack <string> temp2;
	int i = 0;
	for(itr = infix.begin(); itr != infix.end() ; itr++, i++){
		if(isdigit(infix[i].back())){
			postfix.push_back(infix[i]);
			continue;
		}
		if(infix[i] == "("){
			temp2.push(infix[i]);
			continue;
		}
		if(infix[i] == ")"){
			while(!temp2.empty() && (temp2.top() != "(")){
				string toPush = temp2.top();
				postfix.push_back(toPush);
				temp2.pop();
			}
			temp2.pop();
			continue;
		}
		if(isOperator(infix[i][0])){
			if(temp2.empty() || temp2.top() == "("){
				temp2.push(infix[i]);
			}
			else{
				while(!temp2.empty() && (temp2.top() != "(") && bigOne(infix[i], temp2.top())){
					string toPush = temp2.top();
					postfix.push_back(toPush);
					temp2.pop();
				}
				temp2.push(infix[i] );
			}
			continue;
		}
	}
	while(!temp2.empty()){
		string toPush = temp2.top();
		postfix.push_back(toPush);
		temp2.pop();
	}
}

int main(){
	input();
	toPostfix();
	for(it = postfix.begin(); it != postfix.end() ; it++){
		cout << *it << " ";
	}
}
