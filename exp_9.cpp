#include<bits/stdc++.h>
using namespace std;

class SyntaxAnalysis {
    vector<string> tokens;
    public: SyntaxAnalysis(vector<string> tokens) {
        this->tokens = tokens;
    }
    vector<string>PN = {"Sagor","Selim","Salma","Nipu"};
    vector<string>P = {"he","she","I","we","you","they"};
    vector<string>N = {"book","cow","dog","home","grass","rice","mango"};
    vector<string>V = {"read","eat","take","run","write"};
    bool isPN(string &s) {
        return find(PN.begin(),PN.end(),s) != PN.end();
    }
    bool isP(string &s) {
        return find(P.begin(),P.end(),s) != P.end();
    }
    bool isN(string &s) {
        return find(N.begin(),N.end(),s) != N.end();
    }
    bool isV(string &s) {
        return find(V.begin(),V.end(),s) != V.end();
    }
    bool isSub(string &s) {
        return isPN(s) || isP(s);
    }
    bool isPRED(vector<string>&s) {
        if(s.size()==1 and isV(s[0])) return true;
        if(s.size()==2 and isV(s[0]) and isN(s[1])) return true;
        return false;
    }
    public: bool isValid() {
        if(tokens.size()<2)return false;
        vector<string>PRED = vector<string>(tokens.begin()+1,tokens.end());
        if(isSub(tokens[0]) and isPRED(PRED)) return true;
        return false;
    }
};

int main() {
    vector<string>sentence;
    string word;
    freopen("input.txt","r",stdin);
    while(cin >> word) {
        sentence.push_back(word);
    }
    SyntaxAnalysis sa(sentence);
    if(sa.isValid()) {
        cout<<"Syntactically Valid."<<endl;
    } else {
        cout<<"Syntactically Invalid."<<endl;
    }
    return 0;
}