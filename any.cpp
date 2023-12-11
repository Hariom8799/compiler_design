#include <iostream>
#include <vector>
#include <unordered_set>
#include <stack>

using namespace std;

// Data structure to represent a production rule
struct Production
{
    string left;
    string right;
};

// Function to check if the grammar is operator precedence
bool isOperatorPrecedence(const vector<Production> &productions)
{
    unordered_set<string> terminals;
    unordered_set<string> nonTerminals;
    unordered_set<string> operators;

    // Collect terminals, non-terminals, and operators
    for (const Production &production : productions)
    {
        nonTerminals.insert(production.left);
        for (char symbol : production.right)
        {
            string symbolStr(1, symbol);
            if (isalpha(symbol) && islower(symbol))
            {
                terminals.insert(symbolStr);
            }
            else
            {
                operators.insert(symbolStr);
            }
        }
    }

    // Check for overlapping symbols between terminals and operators
    for (const string &terminal : terminals)
    {
        if (operators.find(terminal) != operators.end())
        {
            return false;
        }
    }

    // Check if the grammar is operator precedence
    for (const Production &production : productions)
    {
        string right = production.right;
        if (right.length() >= 2 && isalpha(right[0]) && isalpha(right[1]) && isupper(right[1]))
        {
            return false; // Invalid adjacent non-terminals
        }
    }

    return true;
}

int main()
{
    // Define the grammar with production rules
    vector<Production> productions = {
        {"E", "E+T"},
        {"E", "T"},
        {"T", "T*F"},
        {"T", "F"},
        {"F", "(E)"},
        {"F", "id"}};

    // Check if the grammar is operator precedence
    if (isOperatorPrecedence(productions))
    {
        cout << "The grammar is operator precedence." << endl;
    }
    else
    {
        cout << "The grammar is not operator precedence." << endl;
    }

    return 0;
} 
