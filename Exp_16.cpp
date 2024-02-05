#include<bits/stdc++.h>
using namespace std;

class InfixToPost{
    string exp="(";
    public: InfixToPost(string &exp) {
        this->exp += exp;
    }
    string stack;
    map<char,int>precedence = {
        {'+',1},{'-',1},
        {'*',2},{'/',2},
        {'^',3},
        {'(',4},{'(',4}
    };
    public: void makePostFix() {
        exp+=")";
        stack = "";
        string res = "";
        for(int i=0;i<exp.size();i++) {
            if(isalpha(exp[i])) {
                res += exp[i];
            }else if(exp[i]=='(') {
                stack += exp[i];
            }else if(exp[i]==')') {
                while(stack.size()>0 and stack[stack.size()-1]!='(') {
                    res += stack[stack.size()-1];
                    stack = stack.substr(0,stack.size()-1);
                }
                stack = stack.substr(0,stack.size()-1);
            }else {
                while(stack.size()>0 and stack[stack.size()-1]!='(' and precedence[stack[stack.size()-1]]>=precedence[exp[i]]) {
                    res += stack[stack.size()-1];
                    stack = stack.substr(0,stack.size()-1);
                }
                stack += exp[i];
            }
        }
        while(stack.size()>0) {
            res += stack[stack.size()-1];
            stack = stack.substr(0,stack.size()-1);
        }
        cout << "Postfix Expression: " << res << endl;
    }

};

int main() {

    cout << "Enter a Expression\n";
    string exp;
    cin >> exp;
    InfixToPost infixToPost(exp);
    infixToPost.makePostFix();
    return 0;
}