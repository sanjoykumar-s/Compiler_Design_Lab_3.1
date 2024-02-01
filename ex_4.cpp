#include<bits/stdc++.h>
using namespace std;

bool isIntegerVar(string &s) {
    if(s.size()<2)return false;
    if(!((s[0]>='i' and s[0]<='n') or (s[0]>='I' and s[0]<='N')))return false;
    for(int i=1;i<s.size();i++) {
        bool ok=false;
        if(s[i]>='a' and s[i]<='z')ok=true;
        else if(s[i]>='A' and s[i]<='Z')ok=true;
        else if(s[i]>='0' and s[i]<='9')ok=true;
        if(!ok)return false;
    }return true;
}

bool isShortInreger(string &s) {
    if(s.size()<1 or s.size()>4)return false;
    char lch = '1', rch = '9';
    for(int i=0;i<s.size();i++) {
        if(s[i]<lch or s[i]>rch)return false;
        if(i==0)lch='0';
    }
    return true;
}

bool isLongInteger(string &s) {
    if(s.size()<5)return false;
    char lch = '1', rch = '9';
    for(int i=0;i<s.size();i++) {
        if(s[i]<lch or s[i]>rch)return false;
        if(i==0)lch='0';
    }
    return true;
}

int main() {
    freopen("input.txt","r",stdin);
    string s;
    cin >> s;
    if(isIntegerVar(s))cout << "Input is a Integer Variable.\n";
    else if(isShortInreger(s))cout << "Input is a Short Integer.\n";
    else if(isLongInteger(s))cout << "Input is a Long Integer.\n";
    else cout << "Undefined Input.\n";
    return 0;
}