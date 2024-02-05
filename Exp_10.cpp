#include<bits/stdc++.h>
using namespace std;

class Perser{
    map<string,string>mp;
    string expression;
    string finalRes="$";
    public: void addRule(string &rule) {
        string left,right;
        bool isRight=false;
        for(int i=0;i<rule.size();i++) {
            if(rule[i]=='=') {
                isRight=true;
            }else if(isRight) {
                right+=rule.substr(i,1);
            }else {
                left+=rule.substr(i,1);
            }
        }
        mp[right]=left;
        if(finalRes=="$") finalRes+=left;
    }
    public: void addExpression(string &exp) {
        expression = exp;
        expression += "$";
    }
    string stack = "$";
    public: void perse() {
        cout << "Stack\t\t\tInput\t\t\tAction" << endl;
        cout << "-------------------- ------------------- -------------------" << endl;
        cout << setw(20) << stack << setw(20) << expression << setw(20) << "" << endl;
        while(true) {
            int j=stack.size()-1;
            //Reduction
            string temp = "";
            while(j>0) {
                temp = string(1,stack[j])+temp;
                if(mp.count(temp)) {
                    stack = stack.substr(0,j);
                    stack += mp[temp];
                    cout << setw(20) << stack << setw(20) << expression << setw(20) << "Reduce " << mp[temp] << " -> " << temp << endl;
                    break;
                }
                j--;
            }
            //Shift
            if(j==0) {
                if(expression=="$") break;
                if(expression.size()>0 and !isalpha(expression[0])) {
                    stack += expression.substr(0,1);
                    expression = expression.substr(1);
                }else {
                    while(expression.size()>0 and isalpha(expression[0])) {
                        stack += expression.substr(0,1);
                        expression = expression.substr(1);
                    }
                }
                cout << setw(20) << stack << setw(20) << expression << setw(20) << "Shift" << endl;
            }
        }
        if(stack==finalRes) {
            cout << "String Accepted." << endl;
        }else {
            cout << "String Rejected." << endl;
        }
    }


};

int main() {
    //freopen("input.txt","r",stdin);
    string productionRule;
    Perser perser;
    cout << "Enter the production rules ";
    cout << "[Enter END to stop] : \n";
    while(getline(cin,productionRule)) {
        if(productionRule == "END") break;
        perser.addRule(productionRule);
    }
    cout << "Enter the expression :\n";
    string expresssion;
    cin >> expresssion;
    perser.addExpression(expresssion);
    perser.perse();
    return 0;
}