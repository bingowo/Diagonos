#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAXN 101
int Add1(char A[],int k){ 
    int i = k;
    while(i>=0){
        A[i]+=1;
        if(A[i]<='9') return i;
        A[i] = '0';
        i--;
    }
    return i;
}

int main(){
    int k, t;
    scanf("%d", &t);
    for(k = 0; k < t; k++){
        printf("case #%d:\n", k);
    char A[MAXN]={'0'};
    scanf("%s",A+1); //保留A[0]存放进位
    int len=strlen(A);
    int i,j;
    Add1(A,len-1);
    for(i=1;i<len;i++){
        if(A[i]==A[i-1])break;
    }
    if(i != len){
        i=Add1(A,i);
        while(i>0) {
            if(A[i] != A[i-1]) break;
            i=Add1(A,i);
        }
        for(j=i+1;j<len;j++){
            A[j] = (j-i+1)%2+'0'; //填充0101…
        }
    }
    if(A[0]!='0') printf("%c",A[0]);
    printf("%s\n",A+1);}
    system("pause");
	return 0;
}