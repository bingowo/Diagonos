#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

void zh1(char*s1,char c)
{
    char s2[1100]={'\0'};
    s2[0]=c;
    strcpy(s2+1,s1);
    strcpy(s1,s2);
    
}
void zh2(char*s1,char c)
{
    char s2[1100]={'\0'};
    strcpy(s2,s1);
    int len=strlen(s1);
    s2[len]=c;
    strcpy(s1,s2);
}


int main()
{
    char s0[1100],s1[1100]={'\0'},s2[1100]={'\0'};
    scanf("%s",s0);
    int len=strlen(s0);
    s1[0]=s0[0];
    for(int i=1;i<len;i++)
    {
        if(s0[i]>='a'&&s0[i]<='z') s0[i]-=32;
        strcpy(s2,s1);printf("%s",s2);
        zh1(s1,s0[i]);printf("%s",s1);
        zh2(s2,s0[i]);printf("%s",s2);
        if(strcmp(s1,s2)<0) strcpy(s1,s2);
    }
    printf("%s",s1);
    return 0;
}
    
    
   