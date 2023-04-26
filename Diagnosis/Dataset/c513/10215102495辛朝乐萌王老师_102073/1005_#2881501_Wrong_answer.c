#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#include <ctype.h>

void solve(){
    char Octal[55],decimal[155];
    int len;
    int numbers = 0;
    int digit;
    int temp;
    scanf("%s",Octal);
    len = strlen(Octal)-1;
    for (; len != 1; --len) {
        digit = Octal[len]-'0';
        int j =0;
        do{
            if(j<numbers)
                temp=digit*10+decimal[j]-'0';
            else
                temp=digit*10;
            decimal[j++] = temp/8+'0';
            digit = temp%8;
        }while(digit!=0 || j<numbers);
        numbers=j;
    }
    decimal[numbers]='0';
    printf("0.%s",decimal);
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("case #%d:\n",i);
        solve();
        printf("\n");
    }
}