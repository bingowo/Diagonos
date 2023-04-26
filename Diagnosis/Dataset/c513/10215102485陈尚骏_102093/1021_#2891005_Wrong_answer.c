#include <stdio.h>
#include <stdlib.h>

int p[26]={0};
char alph[27];

int cmp(const void *a,const void *b)
{
    char *s1,*s2; char ch1,ch2;
    s1=(char*)a; s2=(char*)b;
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
    char s[100][21];
    int count=0,k=0,t=0;
    char c[2200];
    gets(c);
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
