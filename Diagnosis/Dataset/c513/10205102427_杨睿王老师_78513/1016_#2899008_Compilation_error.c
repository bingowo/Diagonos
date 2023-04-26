#include <cstdio>
#include <cstring>
#include <stack>
#include <vector>
#include <algorithm>
#include <cmath>

int mod(int a, int b){
    for(int i = 0; i < abs(b); i++){
        if(!((a-i) % b)) return i;
    }
    return 0;
}

int main(){
    int N, R;
    scanf("%d %d",&N,&R);
    if(!N){
        printf("0\n");
        return 0;
    }
    char table[20] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
	stack<char> s;
    while(N){
        int num = mod(N, R);
        s.push(table[abs(num)]);
        N -= num;
        N /= R;
    }
    while(!s.empty()){
        printf("%d",s.top());
        s.pop();
    }
    printf("\n");
    return 0;
}