#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 2200
int p[26];
int cmp(const void* e1,const void* e2)
{
    char* s1;char* s2;
    s1=(char*)e1;
    s2=(char*)e2;
    char sn1,sn2;
    int i,j;
    for(i=0,j=0;s1[i]&&s2[j];)
    {
        sn1=s1[i]>='a'?s1[i]-32:s1[i];
        sn2=s2[i]>='a'?s2[i]-32:s2[i];
        if(p[sn2-'A']!=p[sn1-'A'])
        {
            return p[sn1-'A']-p[sn2-'A'];
        }
        else
        {
            i++;
            j++;
        }
    }
    if(s1[i]==0)
    return -1;
    else 
    return 1;
}
int main()
{
    char b[27];
    while(scanf("%s",b)==1)
   { int i=0;char s[100][21];char str[2200];
   gets(str);
    int count=0;
    while(1)
    {
        int j=0;
        while(str[i]!=' '&&str[i])
        {
            s[count][j++]=str[i];
        }
        s[count][j]='\0';
        count++;
        if(!str[i])break;
        else i++;
    }
    qsort(s,i,sizeof(s[0]),cmp);
    int j;
    for(j=0;j<i-1;j++)
    printf("%s ",s[j]);
    printf("%s\n",s[j]);
   }
}