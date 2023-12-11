#include <bits/stdc++.h>
using namespace std;

bool isAKeyword(string word)
{
    string keywords[] = {
        "alignas", "alignof", "and", "and_eq", "asm", "auto","bitand", "bitor", "bool", "break","case", "catch", "char", "char8_t", "char16_t", "char32_t", "class", "compl", "concept", "const", "consteval", "constexpr", "const_cast", "continue","co_await", "co_return", "co_yield","decltype", "default", "delete", "do", "double", "dynamic_cast","else", "enum", "explicit", "export", "extern","false", "float", "for","friend","goto","if", "inline","int","long","mutable","namespace", "new", "noexcept", "not", "not_eq", "nullptr","operator", "or", "or_eq","private", "protected", "public","register", "reinterpret_cast", "requires", "return","short", "signed", "sizeof", "static", "static_assert", "static_cast", "struct", "switch","template", "this", "thread_local", "throw", "true", "try", "typedef", "typeid", "typename","union", "unsigned", "using","virtual", "void", "volatile","wchar_t", "while","xor", "xor_eq"};

    for (string keyword : keywords)
    {
        if (keyword == word)
        {
            return true;
        }
    }

    return false;
}

string fileRead(string fileName)
{
    ifstream file(fileName);

    if (!file.is_open())
    {
        cerr << "Error: Could not open the file." << endl;
        return "File Not Found";
    }

    string fileContents((istreambuf_iterator<char>(file)),
                        istreambuf_iterator<char>());

    file.close();

    return fileContents;
}

int main()
{
    unordered_map<string, int> keywordCount;

    string fileName;
    cout << "Enter file name ";
    cin >> fileName;

    string fileContent = fileRead(fileName);
    if (fileContent == "File Not Found")
    {
        cout << "file not found please enter valid file name";
        return 0;
    }

    istringstream token(fileContent);
    string word;

    while (token >> word)
    {
        if (isAKeyword(word))
        {
            keywordCount[word]++;
        }
    }

    for (auto word : keywordCount)
    {
        cout << word.first << " : " << word.second<<endl;
    }

    return 0;
}