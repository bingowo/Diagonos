#include <stdio.h>
#include <stdlib.h>

int p[26];
char alph[27];

int cmp(const void *a,const void *b)
{
    char *s1,*s2; char ch1,ch2;
    s1=*(char(*)[21])a; s2=*(char(*)[21])b;
    while(*s1&&*s2)
    {
        ch1=(*s1)>='a'?*s1-32:*s1;
        ch2=(*s1)>='a'?*s2-32:*s2;
        if(p[ch1-'A']!=p[ch2-'A'])
            return p[ch1-'A']-p[ch2-'A'];
        else{
            s1++; s2++;
        }
    }
        if(*s1==0) return -1;
        else return 1;
}

int main()
{
    while(scanf("%s",alph)!=EOF)
    {
        for(int i=0;i<26;i++)
            p[alph[i]-'A']=i;
        getchar();
    }
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
    return 0;
}
