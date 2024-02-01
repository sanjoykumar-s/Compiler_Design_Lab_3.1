#include<bits/stdc++.h>
using namespace std;

void getInput(vector<string> &inputStrings) {
    string input;
    while(cin >> input) {
        inputStrings.push_back(input);
    }
}

void howManyVowelandConsonant(vector<string> &inputStrings) {
    int vowel = 0,consonant = 0;
    for(auto word : inputStrings) {
        for(auto ch : word) {
            if(isalpha(ch)) {
                ch = tolower(ch);
                if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                    vowel++;
                }else consonant++;
            }
        }
    }
    cout << "Vowel: " << vowel << endl;
    cout << "Consonant: " << consonant << endl;
}

void printVowelandConsonant(vector<string> &inputStrings) {
    vector<char> vowel,consonant;
    for(auto word : inputStrings) {
        for(auto ch : word) {
            if(isalpha(ch)) {
                ch = tolower(ch);
                if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                    vowel.push_back(ch);
                }else consonant.push_back(ch);
            }
        }
    }
    cout << "Vowel: ";
    for(auto word : vowel) {
        cout << word << " ";
    }
    cout << endl;
    cout << "Consonant: ";
    for(auto word : consonant) {
        cout << word << " ";
    }
    cout << endl;
}

void seperateVowelandConsonant(vector<string> &inputStrings) {
    vector<string> vowel,consonant;
    for(auto word : inputStrings) {
        char ch = word[0];
        if(isalpha(ch)) {
            ch = tolower(ch);
            if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                vowel.push_back(word);
            }else consonant.push_back(word);
        }
    }
    cout << "String where every word is started with Vowel:     "; 
    for(auto word : vowel) {
        cout << word << " ";
    }cout << endl;
    cout << "String where every word is started with Consonant:     ";
    for(auto word : consonant) {
        cout << word << " ";
    }cout << endl;
}

int main() {
    vector<string> inputStrings;
    getInput(inputStrings);
    howManyVowelandConsonant(inputStrings);
    printVowelandConsonant(inputStrings);
    seperateVowelandConsonant(inputStrings);
    return 0;
}
