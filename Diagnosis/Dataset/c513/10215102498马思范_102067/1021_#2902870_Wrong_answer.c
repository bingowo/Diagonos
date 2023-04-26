#include <stdio.h>
#include <stdlib.h>
int k[26];
int cmp(const void *a,const void *b)
{
    char *s1,*s2;
    char c,d;
    s1=*(char(*)[21])a;
    s2=*(char(*)[21])b;
    while(*s1&&*s2)
    {
        c=(*s1)>='a'?*s1-32:*s1;
        d=(*s2)>='a'?*s2-32:*s2;
        if(k[c-'A']!=k[d-'A'])
        {
            return k[c-'A']-k[d-'A'];
        }
        else
        {
            s1++;
            s2++;
        }
        if(*s1==0) return -1;
        else return 1;
    }
}
int main()
{
    char al[27];
    while (scanf("%s", al) != EOF)
    {
        for (int i = 0; i < 26; i++)
        {
            k[al[i]-'A']=i;
        }
            char a[100][21];
    int count=0,x=0,temp=0;
    char c;
    do {
        c=getchar();
        if(c!=' '&&c!='\n')
        {
            a[count][x]=c;
            temp=1;
            x++;
        }
        else if(temp)
        {
            a[count][x]='\0';
            count++;
            x=0;
            temp=0;
        }
    } while (c!='\n');
    qsort(a,count,sizeof(a[0]), cmp);
    for(int m=0;m<count;m++)
    {
        printf("%s",a[m]);
    }
    return 0;
    }
}