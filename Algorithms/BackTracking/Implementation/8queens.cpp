#include <bits/stdc++.h> 
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
using namespace std; 


int rows[8]; 

bool isValid(int row, int column) {
    for(int prev = 0; prev < column; prev++) {
        if(rows[prev] == row || abs(rows[prev]-row) == abs(prev-column)) {
            return false;
        }
    }
    return true;
}

void solve(int column) { 
    if (column == 8) {
        for(int i = 0 ; i<8; i++) {
            cout<<"[" << rows[i]+1<< "]";
        }
        cout<<endl;
        return;
    }  
    for(int row=0;row<8;row++) {   
        if(isValid(row,column)){  
            rows[column] = row;    
            solve(column + 1);  
        }
    }
}
int main () {
    solve(0);
}