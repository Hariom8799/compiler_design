#include<bits/stdc++.h>
using namespace std;

int check(string g){
    if(g.size() < 2 || g[0] == 'b' || g[g.size()-1] == 'a' || g.size()%2 != 0 )
        return 0;
    
    int countA = 0;

    for(int i=0; i<g.size(); i++){
        if(g[i] != 'a')
            return 0;
        countA++;
    }
    return countA == g.size()/2;
}
int main(){
    
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