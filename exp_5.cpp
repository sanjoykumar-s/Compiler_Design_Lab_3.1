#include<bits/stdc++.h>
using namespace std;

bool isFloatVar(string &s) {
    if(s.size()<1)return false;
    bool ok = false;
    if((s[0]>='a' and s[0]<='h'))ok=true;
    else if((s[0]>='A' and s[0]<='H'))ok=true;
    else if((s[0]>='o' and s[0]<='z'))ok=true;
    else if((s[0]>='O' and s[0]<='Z'))ok=true;
    if(!ok)return false;
    for(int i=1;i<s.size();i++) {
        ok=false;
        if(s[i]>='a' and s[i]<='z')ok=true;
        else if(s[i]>='A' and s[i]<='Z')ok=true;
        else if(s[i]>='0' and s[i]<='9')ok=true;
        if(!ok)return false;
    }return true;
}

// bool isFloatVar2(string &s) {
//     return regex_match(s,regex("[a-hA-Ho-zO-Z][a-zA-Z0-9]*"));
// }



bool isFloat(string &s) {
    if(s.size()<4)return false;
    string a = "",b="";
    bool isB=false;
    for(int i=0;i<s.size();i++) {
        if(s[i]=='.') {
            isB=true;
            continue;
        }
        if(!isB) a+=s.substr(i,1);
        else b+=s.substr(i,1);
    }
    if(b.size()!=2 or !isdigit(b[0]) or !isdigit(b[1]) or a.size()==0)return false;
    if(a=="0")return true;
    if(a[0]<='0' or a[0]>'9')return false;
    for(int i=1;i<a.size();i++) {
        if(a[i]<'0' or a[i]>'9')return false;
    }
    return true;
}

bool isDouble(string &s) {
    if(s.size()<5)return false;
    string a = "",b="";
    bool isB=false;
    for(int i=0;i<s.size();i++) {
        if(s[i]=='.') {
            isB=true;
            continue;
        }
        if(!isB) a+=s.substr(i,1);
        else b+=s.substr(i,1);
    }
    if(b.size()<3 or a.size()==0)return false;
    for(int i=0;i<b.size();i++) {
        if(b[i]<'0' or b[i]>'9')return false;
    }
    if(a=="0")return true;
    if(a[0]<='0' or a[0]>'9')return false;
    for(int i=1;i<a.size();i++) {
        if(a[i]<'0' or a[i]>'9')return false;
    }
    return true;
}

int main() {
    freopen("input.txt","r",stdin);
    string s;
    cin >> s;
    if(isFloatVar(s))cout << "Input is a float Variable.\n";
    else if(isFloat(s))cout << "Input is a Float Number.\n";
    else if(isDouble(s))cout << "Input is a Double Number.\n";
    else cout << "Undefined Input.\n";
    return 0;
}