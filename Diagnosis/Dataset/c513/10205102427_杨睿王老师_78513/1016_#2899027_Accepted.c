#include <stdio.h>
#include <string.h>
#include <math.h>

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
	char s[101];
	int q=100,p=100;
    while(N){
        int num = mod(N, R);
        s[q]=table[abs(num)];
        q--;
        N -= num;
        N /= R;
    }
    q++;
    while(q!=101){
        printf("%c",s[q]);
        q++;
    }
    printf("\n");
    return 0;
}