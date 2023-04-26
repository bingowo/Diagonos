#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int p[26]={0};

int cmp(const void*a,const void*b)
{
    char *s1,*s2;
    char ch1,ch2;
    s1=(char*)a;
    s2=(char*)b;
    while(*s1&&*s2){
        ch1=(*s1)>='a'?*s1-32:*s1;
        ch2=(*s2)>='a'?*s2-32:*s2;
        if(p[ch1-'A']!=p[ch2-'A'])
            return p[ch1-'A']-p[ch2-'A'];
        else{
            s1++;
            s2++;}}
        if(*s1==0)
            return -1;
        else return 1;
}

int main()
{
    int count,k,t;
    char alph[27];
    while(scanf("%s\n",alph)!=EOF)
    {
        for(int i=0;i<26;i++)
            p[alph[i]-'A']=i;
    char s[100][21];
    char c[2200];
    gets(c);
    count=0;
    t=0;
     while(1){
        k=0;
        while(c[t]!=' '&&c[t])
            s[count][k++]=c[t++];
        s[count][k]='\0';
        count++;
        if(!c[t])break;
        else t++;}
    qsort(s,count,sizeof(s[0]),cmp);
    for(k=0;k<count-1;k++)
        printf("%s ",s[k]);
    printf("%s\n",s[k]);
    }
    return 0;
}
