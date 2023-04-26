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
    int t;
    while(scanf("%s\n",alph)!=EOF)
    {
        for(int i=0;i<26;i++)
            p[alph[i]-'A']=i;
        char s[100][50];
        int count=0,k=0;
        char str[2200];
        gets(str);
        while(1)
        {
            k=0;
            while(str[t]!=' '&&str[t])
                s[count][k++]=str[t++];
        s[count][k]='\0';
        count++;
        if(!str[t]) break;
        else t++;
        }
        qsort(s,count,sizeof(s[0]),cmp);
        for(int i=0;i<count-1;i++){
                printf("%s",s[i]);
        k=i;
        }
        printf("%s\n",s[k]);
    }
    return 0;
}
