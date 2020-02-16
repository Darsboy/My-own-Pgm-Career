#include <bits/stdc++.h>
using namespace std;
int a[3][3], miss[3][3], row[3], col[3], x; string s;
int ord[5][2] = {{1,1}, {0, 1}, {1, 0}, {1, 2}, {2, 1}};
void solveR(int i){
    if(miss[i][0]){ a[i][0] = 2*a[i][1] - a[i][2]; miss[i][0] = 0; col[0]--; }
    if(miss[i][1]){ a[i][1] = (a[i][0] + a[i][2])/2; miss[i][1] = 0; col[1]--;}
    if(miss[i][2]){ a[i][2] = 2*a[i][1] - a[i][0]; miss[i][2] = 0; col[2]--; }
    row[i]--; x--;
}
void solveC(int j){
    if(miss[0][j]){ a[0][j] = 2*a[1][j] - a[2][j]; miss[0][j] = 0; row[0]--;}
    if(miss[1][j]){ a[1][j] = (a[0][j] + a[2][j])/2; miss[1][j] = 0; row[1]--; }
    if(miss[2][j]){ a[2][j] = 2*a[1][j] - a[0][j]; miss[2][j] = 0; row[2]--;}
    col[j]--; x--;
}
void fillCell(int i, int j){
    a[i][j] = 0; miss[i][j] = 0; row[i]--; col[j]--; x--;
}
int main(){
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cin >> s;
            if(s == "X") { miss[i][j]=1; row[i]++; col[j]++; x++; }
            else a[i][j] = stoi(s);
        }
    }
    while(x > 0 && x < 9){
        for(int i=0; i<3; i++)
            if(row[i] == 1) { solveR(i); goto next; }
        for(int j=0; j<3; j++)
            if(col[j] == 1) { solveC(j); goto next; }
        for(int i=0; i<5; i++){
            if(miss[ord[i][0]][ord[i][1]]) { fillCell(ord[i][0], ord[i][1]); goto next;}
        }
        for(int i=0; i<3; i++)
            for(int j=0; j<3; j++)
                if(miss[i][j]) {fillCell(i, j); goto next;}
next: ;
    }
    for(int i=0; i<3; i++, cout<<endl)
        for(int j=0; j<3; j++)
            cout << a[i][j] << " ";
}
