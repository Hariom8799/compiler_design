// 2. a) S -> aS
//          S -> Sb
//          S -> ab
// String of the form : aab
// 2. b) S -> aSa
//          S -> bSb
//          S -> a
//          S -> b
// The Language generated is : All Odd Length Palindromes
// 2. c) S -> aSbb
//          S -> abb
// The Language generated is : anb2n , where n>1
// 2. d) S -> aSb
//          S -> ab
// The Language generated is : anbn, where n>0


#include <bits/stdc++.h>

using namespace std;

int check(string g) {
    if(g.size() < 2 || g[0] != 'a' || g[g.size() - 1] == 'a'){
        return 0;  
    } 

    for(int i = 0; i < g.size()-1; i++){
        if(g[i] != 'a' && g[i] != 'b') return 0;
        if(g[i] == 'b' && g[i+1] == 'a') return 0;
    }
    return 1;
}

int main()
{
    string gram;
    cout << "Enter the String :- ";
    cin>> gram;
    if(check(gram)){
        cout<<"String belongs to grammer";
    }
    else{
        cout<<"String does not belongs to grammer";
    }
    return 0;
}

