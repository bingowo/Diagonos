#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
void gps(char s[],int t[])
{
    int i,int1,int2;
    if(s[0]=='$'&&s[1]=='G'&&s[2]=='P'&&s[3]=='R'&&s[4]=='M'&&s[5]=='C'&&s[6]!='\0')
    {
        int sum=0;
        for(i=1;s[i]!='*';i++)
            sum=sum^s[i];
        char c1=s[i+1],c2=s[i+2];
        if(c1>='A'&&c1<='F')
            int1=10+c1-'A';
        else
            int1=c1-'0';
        if(c2>='A'&&c2<='F')
            int2=10+c1-'A';
        else
            int2=c2-'0';
        int num=int1*16+int2;
        for(i=7;s[i]!='*';i++)
            if(s[i]==',')break;
        if(s[i+1]=='A'&&sum==num)
        {
            int h=10*(s[7]-'0')+s[8]-'0';
            h=(h+8)%24;
            t[0]=h;
            t[1]=10*(s[9]-'0')+s[10]-'0';
            t[2]=10*(s[11]-'0')+s[12]-'0';
        }
    }
}
int main()
{
    char word[1000];
    char end[]="END";
    int time[3]={0};
    do
    {
        scanf("%s",word);
        gps(word,time);
    }while(strcmp(word,end)!=0);
    printf("%02d:%02d:%02d\n",time[0],time[1],time[2]);
    return 0;
}
