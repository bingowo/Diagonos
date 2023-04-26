#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define N 1005

int find0x(char* s,int l)
{
    int n=strlen(s);
    for(int i=l;i<n-1;++i){
        if(s[i]=='0'&&s[i+1]=='x')return i;
    }
    return -1;
}

int main()
{
    char input[N]={0};
    scanf("%s",input);
    int n=strlen(input);int flag=0;// record the loop times.
    int pl=0,pr=0;  // p_left p_right
    while(pl<n&&pr<n){
        pl=find0x(input,pr);
        if(pl<0||pl+2>=n){
            if(flag)break;
            else {
                printf("-1");return 0;
            }
        }
        int ret=0;
        for(pr=pl+2;((input[pr]>='0'&&input[pr]<='9')||(input[pr]>='a'&&input[pr]<='f'))&&pr<n;++pr){
            ret=ret*16;
            if(input[pr]>='0'&&input[pr]<='9')ret+=input[pr]-'0';
            if(input[pr]>='a'&&input[pr]<='f')ret+=input[pr]-'a'+10;
        }
        if(pr==pl+2)pl=pr;
        else {printf("%d ",ret);flag++;}
    }
    return 0;
}
