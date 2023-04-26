#include <iostream>
#include <stack>
using namespace std;

int main(){
    char table[36] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    stack<char> s;
    int T, N, R;
    cin>>T;
    for(int i = 0; i < T; i++){
        cin>>N>>R;
        int flag = 0;
        if(N<0) {N*=-1; flag = 1;}
        while(N){
            int tmp = N%R;
            s.push(table[tmp]);
            N/=R;
        }
        if(flag) cout<<'-';
        while(!s.empty()){
            cout<<s.top();
            s.pop();
        }
        cout<<endl;
    }
    return 0;
}