#include<bits/stdc++.h>
using namespace std;

void getInput(string &inputStrings) {
    getline(cin,inputStrings);
}


int main() {
    string inputStrings;
    getInput(inputStrings);
    map<string,string> dictionary;
    dictionary["Computer Science & Engineering, 3rd year, 1st semester, Compiler Design, Theory"] = "CSE-3141";
    dictionary["Computer Science & Engineering, 3rd year, 1st semester, Compiler Design, Lab"] = "CSE-3142";

    dictionary["Computer Science & Engineering, 3rd year, 1st semester, Software Engineering, Theory"] = "CSE-3111";
    dictionary["Computer Science & Engineering, 3rd year, 1st semester, Software Engineering, Lab"] = "CSE-3112";
    
    dictionary["Computer Science & Engineering, 3rd year, 1st semester, Database Management Systems, Theory"] = "CSE-3121";
    dictionary["Computer Science & Engineering, 3rd year, 1st semester, Database Management Systems, Lab"] = "CSE-3122";
    
    dictionary["Computer Science & Engineering, 3rd year, 1st semester, Web Engineering, Theory"] = "CSE-3131";
    dictionary["Computer Science & Engineering, 3rd year, 1st semester, Web Engineering, Lab"] = "CSE-3132";
    
    dictionary["Computer Science & Engineering, 3rd year, 1st semester, Engineering Ethics and Environment Protection, Theory"] = "CSE-3151";
    dictionary["Computer Science & Engineering, 3rd year, 1st semester, Communication Engineering, Lab"] = "CSE-3161";
    
    dictionary["Computer Science & Engineering, 3rd year, 1st semester, Mobile Application Development Lab, Theory"] = "CSE-3162";
    
    if(dictionary.find(inputStrings) != dictionary.end()) {
        cout << dictionary[inputStrings] << endl;
    }else cout << "Not Found" << endl;

    return 0;
}
