#include <stdio.h>
#include <string.h>
int main()
{
    char s1[1001];
    char s2[1001];
    int  s[2000];
    int num=0,point1=-1,point2=-1,point=0;
    scanf("%s %s %d",s1,s2,&num);
    for(int i=0;s1[i]!='\0';i++)
    {
        if(s1[i]=='.') point1=i;
    }
    for(int i=0;s2[i]!='\0';i++)
    {
        if(s2[i]=='.') point2=i;
    }
    if(point1==-1) point1=(int)strlen(s1);
    if(point2==-1) point2=(int)strlen(s2);
    if(point1>point2)
    {
        for(int i=(int)strlen(s2)-1;i>=0;i--)
        {
            s2[i+point1-point2]=s2[i];
            s2[i]='0';
        }
        point=point1;
    }
    else if(point1<point2)
    {
        for(int i=(int)strlen(s1)-1;i>=0;i--)
        {
            s1[i+point2-point1]=s1[i];
            s1[i]='0';
        }
        point=point2;
    }
    int len=(int)strlen(s1)>(int)strlen(s2)?(int)strlen(s1):(int)strlen(s2);
    int left=0;
    for(int i=len-1;i>=0;i--)
    {
        if(s1[i]=='\0' || s2[i]=='\0')
        {s[i]=(s1[i]+s2[i]-'\0'-'0'+left)%10;left=(s1[i]+s2[i]-'\0'-'0'+left)/10;}
        else if(s1[i]=='.' || s2[i]=='.') s[i]=-1;
        else {s[i]=(s1[i]+s2[i]-'0'-'0'+left)%10;left=(s1[i]+s2[i]-'0'-'0'+left)/10;}
    }
    if(left!=0) printf("%d",left);
    int cnt=-1;
    for(int i=0;cnt<=num;i++)
    {
        if(point==1 && s[0]==0) printf("0");
        else if(s[i]==-1){printf(".");cnt++;}
        else if(cnt!=-1){cnt++;printf("%d",s[i]);}
        else printf("%d",s[i]);
    }
    return 0;
}