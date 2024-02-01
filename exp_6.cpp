#include<bits/stdc++.h>
using namespace std;

bool isCharVar(string &s) {
    if(s.size()<4)return false;
    if(s.substr(0,3)!="ch_")return false;
    for(int i=3;i<s.size();i++) {
        bool ok=false;
        if(s[i]>='a' and s[i]<='z')ok=true;
        else if(s[i]>='A' and s[i]<='Z')ok=true;
        else if(s[i]>='0' and s[i]<='9')ok=true;
        if(!ok)return false;
    }return true;
}
bool isBinaryVar(string &s) {
    if(s.size()<4)return false;
    if(s.substr(0,3)!="bn_")return false;
    for(int i=3;i<s.size();i++) {
        bool ok=false;
        if(s[i]>='a' and s[i]<='z')ok=true;
        else if(s[i]>='A' and s[i]<='Z')ok=true;
        else if(s[i]>='0' and s[i]<='9')ok=true;
        if(!ok)return false;
    }return true;
}

bool isBinaryNum(string &s) {
    if(s.size()<2 or s[0]!='0')return false;
    for(int i=1;i<s.size();i++) {
        if(s[i]!='0' and s[i]!='1')return false;
    }return true;

}

int main() {
    freopen("input.txt","r",stdin);
    string s;
    cin >> s;
    if(isCharVar(s))cout << "Input is a Character Variable.\n";
    else if(isBinaryVar(s))cout << "Input is a Binary Variable.\n";
    else if(isBinaryNum(s))cout << "Input is a Binary Number.\n";
    else cout << "Undefined Input.\n";
    return 0;
}