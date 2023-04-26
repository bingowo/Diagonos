#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 105

int addOne(char s[],int k)
{
    while(k>=0){
        s[k]++;
        if(s[k]<='9')return k;
        s[k--]='0';
    }
    return k;
}

int F_repeat(char s[])
{
    int len=strlen(s)-1;
    if(len==1)return -1;
    for(int i=2;i<=len;++i){
        if(s[i]==s[i-1])return i;
    }
    return -1;
}

void trans(char input[])
{
    int len = strlen(input);
    int st=F_repeat(input);
    if(st!=-1){
        int _st=addOne(input,st);
        for(int j=_st+1;j<len;){
            input[j++]='0';
            if(j<len)input[j++]='1';
            else break;
        }
    }
    else{
        int k=addOne(input,len-1);
    }
}

int main()
{
    int T,x=0;
    scanf("%d\n",&T);
    while(x<T){
        char input[N];
        for(int i=0;i<N;++i)input[i]=0;
        input[0]='0';
        scanf("%s",input+1);
        printf("case #%d:\n",x++);
        trans(input);
        while(F_repeat(input)!=-1)trans(input);
        if(input[0]!='0')printf("%s\n",input);
        else printf("%s\n",input+1);
    }
    return 0;
}