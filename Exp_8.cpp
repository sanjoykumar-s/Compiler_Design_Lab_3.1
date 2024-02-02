#include<bits/stdc++.h>
using namespace std;

class Recognizer{
    string token;
    vector<string>type = {"Keyword","Identifier","Undefined"};
    vector<string> keyWord = {"abs","alignas", "alignof", "and", "and_eq", "asm", "auto", "bitand", "bitor", "bool", "break", "case", "catch", "char", "char8_t", "char16_t", "char32_t", "class", "compl", "concept", "const", "consteval", "constexpr", "const_cast", "continue", "co_await", "co_return", "co_yield", "decltype", "default", "delete", "do", "double", "dynamic_cast", "else", "enum", "explicit", "export", "extern", "false", "float", "for", "friend", "goto", "if", "inline", "int", "long", "mutable", "namespace", "new", "noexcept", "not", "not_eq", "nullptr", "operator", "or", "or_eq", "private", "protected", "public", "reflexpr", "register", "reinterpret_cast", "requires", "return", "short", "signed", "sizeof", "static", "static_assert", "static_cast", "struct", "switch", "synchronized", "template", "this", "thread_local", "throw", "true", "try", "typedef", "typeid", "typename", "union", "unsigned", "using", "virtual", "void", "volatile", "wchar_t", "while", "xor", "xor_eq"};
    vector<string> arithmetic = {"+","-","*","/","%"};
    vector<string> relational = {"==","!=",">","<",">=","<="};
    vector<string> logical = {"&&","||","!"};
    vector<string> bitwise = {"&","|","^","~","<<",">>"};
    vector<string> assignment = {"=","+=","-=","*=","/=","%=","&=","|=","^=","<<=",">>="};
    vector<string> increment = {"++","--"};
    vector<string> conditional = {"?"};
    public: Recognizer(string token) {
        this->token = token;
    }
    public: string getType() {
        if(find(keyWord.begin(),keyWord.end(),token)!=keyWord.end())return type[0];
        if(regex_match(token,regex("[a-zA-Z_][a-zA-Z0-9_]*")))return type[1];
        if(find(arithmetic.begin(),arithmetic.end(),token)!=arithmetic.end())return "Arithmetic Operator";
        if(find(relational.begin(),relational.end(),token)!=relational.end())return "Relational Operator";
        if(find(logical.begin(),logical.end(),token)!=logical.end())return "Logical Operator";
        if(find(bitwise.begin(),bitwise.end(),token)!=bitwise.end())return "Bitwise Operator";
        if(find(assignment.begin(),assignment.end(),token)!=assignment.end())return "Assignment Operator";
        if(find(increment.begin(),increment.end(),token)!=increment.end())return "Increment/Decrement Operator";
        if(find(conditional.begin(),conditional.end(),token)!=conditional.end())return "Conditional Operator";
        if(regex_match(token,regex("[0-9]+\\.[0-9]+"))) {
            if(regex_match(token,regex("[0-9]+\\.[0-9][0-9][0-9]+")))return "Double";
            return "Float";
        }else if(regex_match(token,regex("[0-9]+"))) {
            if(token.size()>9)return "Long Integer";
            return "Integer";
        }
        return type[2];
    }
};

int main() {
    freopen("input.txt","r",stdin);
    string token;
    while(cin>>token) {
        Recognizer r(token);
        cout<< "Token: " << token << "   Type: "<<r.getType()<<endl;
    }
    return 0;
}