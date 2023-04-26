#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int f(char c1,char c2)
{
    int d;
    if(!isdigit(c1))d=(c1-55)*16;
    else d=(c1-'0')*16;
    if(!isdigit(c2))d+=c2-55;
    else d+=c2-'0';
    return d;
}

void GPS(char*s,int*time)
{
    if(s[0]=='$'&&s[1]=='G'&&s[2]=='P'&&s[3]=='R'&&s[4]=='M'&&s[5]=='C'){
    int i,j;long long d1=s[1];
    for(i=2;i<strlen(s);i++)
    {
        if(s[i]=='*')break;
        d1=d1^s[i]%65536;
    }
    if(f(s[i+1],s[i+2])==d1%65536&&s[18]=='A'){
    time[0]=((s[7]-'0')*10+s[8]-'0'+8)%24;
    time[1]=(s[9]-'0')*10+s[10]-'0';
    time[2]=(s[11]-'0')*10+s[12]-'0';
}}
}

int main()
{
    char word[200];
    int time[3];
    scanf("%s",word);
    while(strcmp(word,"END")!=0)
    {
        GPS(word,time);
        scanf("%s",word);
    }
    printf("%02d:%02d:%02d",time[0],time[1],time[2]);
}