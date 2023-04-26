#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>
int solve(char s1[],char s2[],char s[])
{
    int st1=-1,ed1=0,st2=-1,ed2=0;
    int l1=strlen(s1),l2=strlen(s2),l=strlen(s),j1=0,j2=0;
    for(int i=0;i<l;i++){
        j1=0;
        if(s[i]==s1[0])for(int m=i;m-i<l1;m++){
            if(s[m]==s1[m-i])j1++;
            else break;
        }
        if(j1==l1){st1=i+l1;break;}
    }
    for(int i=0;i<l;i++){
        j2=0;
        if(s[i]==s2[0])for(int m=i;m-i<l2;m++){
            if(s[m]==s2[m-i])j2++;
            else break;
        }
        if(j2==l2){st2=i+l2;break;}
    }
    if(st1==-1||st2==-1)return 0;
    for(int i=0;i<l;i++){
        j1=0;
        if(s[i]==s1[0])for(int m=i;m-i<l1;m++){
            if(s[m]==s1[m-i])j1++;
            else break;
        }
        if(j1==l1)ed1=i;
    }
    for(int i=0;i<l;i++){
        j2=0;
        if(s[i]==s2[0])for(int m=i;m-i<l2;m++){
            if(s[m]==s2[m-i])j2++;
            else break;
        }
        if(j2==l2)ed2=i;
    }
    return abs(st1-ed2)>abs(st2-ed1)?abs(st1-ed2):abs(st2-ed1);
}
int main()
{
    int T;scanf("%d",&T);
    char a=getchar();
    for(int i=0;i<T;i++){
        printf("case #%d:\n",i);
        char s1[80],s2[80],s[80];
        scanf("%s",s1);scanf("%s",s2);scanf("%s",s);
        printf("%d\n",solve(s1,s2,s));
    }
    return 0;
}
