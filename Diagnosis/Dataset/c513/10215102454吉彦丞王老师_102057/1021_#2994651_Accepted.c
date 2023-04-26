#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int p[26]; 
int cmp(const void *pa,const void *pb)
{
    char *a,*b;
    char ch1,ch2;
    a=(char *)pa;
    b=(char *)pb;
    while(*a&&*b)
    {
        ch1=(*a)>='a'?*a-32:*a;
        ch2=(*b)>='a'?*b-32:*b;
        if(p[ch1-'A']!=p[ch2-'A'])
        {
            return p[ch1-'A']-p[ch2-'A'];
        }
        else
        {
            a++;
            b++;
        }
    }
    if(*a==0)
    {
        return -1;
    }
    else
    {
        return 1;
    }
}
int main()
{
    char s[27];
    while(scanf("%s\n",s)!=EOF)
    {
        for(int i=0;i<26;i++)
        {
            p[s[i]-'A']=i;
        }
        char str[2200];
        char a[100][21];
        gets(str);
        int count=0,i=0;
        while(1)
        {
            int j=0;
            while(str[i]!=' '&&str[i])
            {
                a[count][j++]=str[i++];
            }
            a[count][j]='\0';
            count++;
            if(!str[i])
            {
                break;
            }
            else
            {
                i++;
            }
        }
        qsort(a,count,sizeof(a[0]),cmp);
        for(int i=0;i<count-1;i++)
        {
            printf("%s ",a[i]);
        }
        printf("%s\n",a[count-1]);
    }
    return 0;
}