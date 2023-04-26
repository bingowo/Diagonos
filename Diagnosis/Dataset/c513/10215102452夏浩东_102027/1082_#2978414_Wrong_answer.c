#include <stdio.h>
#include <string.h>
int main()
{
    char s1[1100],s2[1100],s[1100];
    int num=0;
    scanf("%s %s %d",s1,s2,&num);
    int len1=(int)strlen(s1),len2=(int)strlen(s2);
    int dot1=-1,dot2=-1;
    for(int i=0;i<len1;i++) if(s1[i]=='.'){dot1=i;break;}
    for(int i=0;i<len2;i++) if(s2[i]=='.'){dot2=i;break;}
    if(dot1==-1) dot1=len1;
    if(dot2==-1) dot2=len2;
    int dot = dot1>dot2?dot1:dot2;
    if(dot1>dot2) {
        int mov = dot1-dot2;
        for(int i=len2;i>=0;i--)
        {
            s2[i+mov]=s2[i];
        }
        for(int i=0;i<mov;i++) s2[i]='0';
        len2+=mov;
    }
    else{
        int mov = dot2-dot1;
        for(int i=len1;i>=0;i--)
        {
            s1[i+mov]=s1[i];
        }
        for(int i=0;i<mov;i++) s1[i]='0';
        len1+=mov;
    }
    for(int i=len1;i<1100;i++) s1[i]='0';
    for(int i=len2;i<1100;i++) s2[i]='0';
    int left=0;
    if((s1[dot+num+1]+s2[dot+num+1]-'0'-'0')>=15)left=2;
    else if((s1[dot+num+1]+s2[dot+num+1]-'0'-'0')>=5) left=1;
    for(int i=dot+num;i>=0;i--)
    {
        if(i==dot) s[i]='.';
        else{
            char c=(char)(s1[i]+s2[i]+left-'0');
            left = (c-'0')/10;
            s[i] = (char)((c-'0')%10+'0');
        }
    }
    if(dot==0 && left==0) printf("0");
    else if(left!=0) printf("%d",left);
    for(int i=0;i<=dot+num;i++) printf("%c",s[i]);
    return 0;
}