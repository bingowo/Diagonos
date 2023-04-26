#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    char s[510] = "";
    gets(s);
    int res[100000] = {0};
    res[0]=0, res[1]=0,res[2]=0,res[3]=1;
    int slen = strlen(s);
    int index = 4;
    for (int i = 9; i >= 0; i--){
        res[index++] = (slen>>i)&1;           
    }
    int i;
    for (i=0;s[3*i+2];i++){
        int num = (s[3*i]-'0')*100+(s[3*i+1]-'0')*10+(s[3*i+2]-'0');
        for (int j=9;j>=0;j--) res[index++] = (num>>j)&1;
    }
    if (slen % 3 == 1){
        int num = s[slen-1] - '0';
        for (int i=3; i >= 0; i--) res[index++] = (num>>i)&1;
    }
    else if (slen % 3 == 2){
        int num = (s[slen-2]-'0')*10 + s[slen-1] - '0';
        for (int i=6; i >= 0; i--) res[index++] = (num>>i)&1;
    }
    for (int i = 0; i < index; i++){
        printf("%d", res[i]);
    }
    printf("\n");
    return 0;
}

