#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int p[26];
char alph[27];

int astrcmp(char *s1,char *s2)
{
    int n1=strlen(s1),n2=strlen(s2);
    int i=0,j=0;
    while(i<n1&&j<n2)
    {
        if(s1[i]<s2[i]) return -1;
        else if(s1[i]>s2[i]) return 1;
        else {i++;j++;}
        if(n1>n2) return 1;
        else if(n1<n2) return -1;
        else return 0;
    }
}
int cmp(const char *a,const char *b)
{
    return astrcmp((char*)a,(char*)b);
}
int main()
{
    while(scanf("%s",alph)!=EOF)
    {
        for(int i=0;i<26;i++)
            p[alph[i]-'A']=i;
        getchar();
    char s[100][21];
    int count=0,k=0,t=0;
    char c;
    do{
        c=getchar();
        if(c!=' '&&c!='\n'){
            s[count][k++]=c;
            t=1;
        }
        else if(t)
        {
            s[count][k]='\0';
            count++;
            k=0;
            t=0;
        }
    }while(c!='\n');
    qsort(s,count,sizeof(s[0]),cmp);
    for(k=0;k<count-1;k++)
        printf("%s ",s[k]);
    printf("%s\n",s[k]);
    }
    return 0;
}
