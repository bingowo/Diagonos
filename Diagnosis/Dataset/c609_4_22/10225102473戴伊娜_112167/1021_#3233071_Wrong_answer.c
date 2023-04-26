#include <stdio.h>
#include <stdlib.h>


int main()
{
    int p[26];
    char s[27];
    int i;
    while(scanf("%s",s)!=EOF)
    {
        for(i=0;i<26;i++)
            p[s[i]-'A']=i;
    }
    char str[2200];
    char a[100][21];
    gets(str);
    int count,j;
    count=0;
    while(1)
        {
            j=0;
            while(str[i]!=' '&&str[i])
                {
                    a[count][j++]=str[i];
                    i++;
                }
                    a[count][j]='\0';
            if(!str[i])
                break;
            else
                {
                    i++;
                    count++;
                }
        }
        int cmp(const void*a,const void*b)
{
    char*s1;
    char*s2;
    char c1,c2;
    s1=(char*)a;
    s2=(char*)b;
    while(*s1&&*s2)
    {
        c1=*s1>'a'?*s1-32:*s1;
        c2=*s2>'a'?*s2-32:*s2;
        if(p[c1-'A']!=p[c2-'A'])
        return p[c1-'A']-p[c2-'A'];
        if(p[c1-'A']==p[c2-'A'])
            {s1++;s2++;}
    }
    if(*s1==0)
        return -1;
    else
        return 1;

}
    qsort(a,count,sizeof(a[0]),cmp);
    for(i=0;i<count-1;i++)
        printf("%s ",a[i]);
    printf("%s",a[i]);
    return 0;
}
