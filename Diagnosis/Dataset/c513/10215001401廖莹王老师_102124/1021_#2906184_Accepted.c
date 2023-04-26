#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<ctype.h>
int p[26];
int cmp(const void*a,const void*b)
{
    char*s1,*s2;
    char a1[25],a2[25];
    int k1,k2,i;
    s1=(char*)a;
    s2=(char*)b;
    for(i=0;s1[i];i++)a1[i]=toupper(s1[i]);
    a1[i]='\0';
    for(i=0;s2[i];i++)a2[i]=toupper(s2[i]);
    a2[i]='\0';
    for(i=0;a1[i]&& a2[i];i++)
    {
        k1=p[a1[i]-'A'];
        k2=p[a2[i]-'A'];
        if(k1!=k2)return k1-k2;
    }
    if(s1[i])return 1;
        else return -1;

}
int main()
{
    char s[27];
    while(scanf("%s",s)!=EOF)
    {
        int h=0;
        for(h=0;s[h];h++)
        p[s[h]-'A']=h;

        getchar();
        char str[2500],t[100][22];
        gets(str);
        int i=0,j=0,r=0;
        while(str[i])
        {
            j=0;
            while(str[i]!=' ' && str[i]){t[r][j]=str[i];j++;i++;}
            t[r][j]='\0';
            if(str[i]==' ')r++,i++;
        }
        qsort(t,r+1,sizeof(t[0]),cmp);
        for(i=0;i<r;i++)printf("%s ",t[i]);
        printf("%s\n",t[i]);
    }
    return 0;
}
