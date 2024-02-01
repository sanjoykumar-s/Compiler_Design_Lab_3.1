#include<bits/stdc++.h>
using namespace std;

void getInput(vector<string> &inputStrings) {
    string input;
    while(cin >> input) {
        inputStrings.push_back(input);
    }
}

void printNumberOfWords(vector<string> &inputStrings) {
    cout << "Number of Words: " <<  inputStrings.size() << endl;
}
void printNumberOfLetters(vector<string> &inputStrings) {
    int count = 0;
    for(auto it : inputStrings) {
        for(auto jt : it) {
            if(isalpha(jt)) {
                count++;
            }
        }
    }
    cout << "Number of Letters: " << count << endl;
}

void printNumberOfDigits(vector<string> &inputStrings) {
    int count = 0;
    for(auto it : inputStrings) {
        for(auto jt : it) {
            if(isdigit(jt)) {
                count++;
            }
        }
    }
    cout << "Number of Digits: " << count << endl;
}

void printNumberOfOtherCharacter(vector<string> &inputStrings) {
    int count = 0;
    for(auto it : inputStrings) {
        for(auto jt : it) {
            if(!isalpha(jt) && !isdigit(jt)) {
                count++;
            }
        }
    }
    cout << "Number of Other Characters: " << count << endl;
}

void printLetters(vector<string> &inputStrings) {
    cout << "Letters: ";
    for(auto it : inputStrings) {
        for(auto ch : it) {
            if(isalpha(ch)) {
                cout << ch << " ";
            }
        }
    }cout << endl;
}

void printDigits(vector<string> &inputStrings) {
    cout << "Digits: ";
    for(auto it : inputStrings) {
        for(auto ch : it) {
            if(isdigit(ch)) {
                cout << ch << " ";
            }
        }
    }cout << endl;
}
void printOtherCharacter(vector<string> &inputStrings) {
    cout << "Other Characters: ";
    for(auto it : inputStrings) {
        for(auto ch : it) {
            if(!isalpha(ch) && !isdigit(ch)) {
                cout << ch << " ";
            }
        }
    }cout << endl;
}

int main() {
    vector<string> inputStrings;
    getInput(inputStrings);
    printNumberOfWords(inputStrings);
    printNumberOfLetters(inputStrings);
    printNumberOfDigits(inputStrings);
    printNumberOfOtherCharacter(inputStrings);
    printLetters(inputStrings);
    printDigits(inputStrings);
    printOtherCharacter(inputStrings);
    return 0;
}
