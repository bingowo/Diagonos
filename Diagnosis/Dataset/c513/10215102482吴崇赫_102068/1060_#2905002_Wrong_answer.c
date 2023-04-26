#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define N 105

int Max(int a,int b)
{
    return a>b?a:b;
}

int main()
{
    char input[N]={0};
    scanf("%s",input);
    int max=0,n=strlen(input);
    for(int i=0;i<n;){
        if(isalpha(input[i])||input[i]=='0')i++;
        else {
            int cnt=0;
            while(input[i]<='9'&&input[i]>='1'){i++;cnt++;}
            max=Max(max,cnt);

        }
    }
    printf("%d",max);
    return 0;
}
