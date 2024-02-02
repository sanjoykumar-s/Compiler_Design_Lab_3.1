#include<bits/stdc++.h>
using namespace std;

class Recognizer{
    string token;
    vector<string>type = {"Keyword","Identifier","Operator","Constant","Undefined"};
    vector<string> keyWord = {"abs","alignas", "alignof", "and", "and_eq", "asm", "auto", "bitand", "bitor", "bool", "break", "case", "catch", "char", "char8_t", "char16_t", "char32_t", "class", "compl", "concept", "const", "consteval", "constexpr", "const_cast", "continue", "co_await", "co_return", "co_yield", "decltype", "default", "delete", "do", "double", "dynamic_cast", "else", "enum", "explicit", "export", "extern", "false", "float", "for", "friend", "goto", "if", "inline", "int", "long", "mutable", "namespace", "new", "noexcept", "not", "not_eq", "nullptr", "operator", "or", "or_eq", "private", "protected", "public", "reflexpr", "register", "reinterpret_cast", "requires", "return", "short", "signed", "sizeof", "static", "static_assert", "static_cast", "struct", "switch", "synchronized", "template", "this", "thread_local", "throw", "true", "try", "typedef", "typeid", "typename", "union", "unsigned", "using", "virtual", "void", "volatile", "wchar_t", "while", "xor", "xor_eq"};
    vector<string> operators = {
        "+", "-", "*", "/", "%",         // Arithmetic Operators
        "==", "!=", "<", ">", "<=", ">=", // Relational Operators
        "&&", "||", "!",                 // Logical Operators
        "&", "|", "^", "~", "<<", ">>",   // Bitwise Operators
        "=", "+=", "-=", "*=", "/=", "%=",
        "&=", "|=", "^=", "<<=", ">>=",  // Assignment Operators
        "++", "--",                      // Increment/Decrement Operators
        "?",                             // Conditional (Ternary) Operator
        ".", "->",                       // Member Access Operators
        "&",                             // Address-of Operator
        "*",                             // Pointer Dereference Operator
        "sizeof",                        // Sizeof Operator
        ",",                             // Comma Operator
    };
    public: Recognizer(string token) {
        this->token = token;
    }
    public: string getType() {
        if(find(keyWord.begin(),keyWord.end(),token)!=keyWord.end())return type[0];
        if(regex_match(token,regex("[a-zA-Z_][a-zA-Z0-9_]*")))return type[1];
        if(find(operators.begin(),operators.end(),token)!=operators.end())return type[2];
        if(regex_match(token,regex("\\d+")))return type[3];
        return type[4];
    }
};

int main() {
    freopen("input.txt","r",stdin);
    string token;
    while(cin >> token) {
        Recognizer r(token);
        cout << "Token: " << token << "      Type: " << r.getType() << endl;
    }
    return 0;
}