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
    public: string makePostFix() {
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
        return res;
    }

};

string conditionToPostfix(vector<string>&exp) {
    string res = "";
    bool elseAche = false;
    int elseIfAche = 0;
    for(int i=0;i<exp.size();i++) {
        if(exp[i]=="if")continue;
        if(exp[i]=="else" and (i+1<exp.size() and exp[i+1]=="if")) {
            elseIfAche++;
            i++;
            continue;
        }
        if(exp[i]=="else") {
            elseAche = true;
            continue;
        }
        if(exp[i]=="then")continue;
        string postFix = InfixToPost(exp[i]).makePostFix();
        res+=postFix;
        if(elseAche) {
            res+="?";
            elseAche = false;
            while(elseIfAche>0) {
                res+="?";
                elseIfAche--;
            }
        }
    }
    return res;
}

int main() {
    string exp;
    getline(cin,exp);
    vector<string>expArr;
    for(int i=0;i<exp.size();i++) {
        string temp = "";
        while(i<exp.size() and exp[i]!=' ') {
            temp += exp[i];
            i++;
        }
        expArr.push_back(temp);
    }
    cout << "Input: " << exp << endl;
    cout << "Output: " << conditionToPostfix(expArr) << endl;
    return 0;
}