#include <stdio.h>
#include <stdlib.h>
#include<string.h>

double f[30];
int cmp(const void*a,const void*b)
{
    char *c=(char *)a;
    char *d=(char *)b;
    char ch1,ch2;
    int i=0;
    while(*c && *d)
    {
        ch1=*c>='a'?*c-32:*c;
        ch2=*d>='a'?*d-32:*d;
        if(f[ch1-'A'] > f[ch2-'A'])
            return -1;
        else if(f[ch1-'A'] < f[ch2-'A'] )
            return 1;
        else if(*c==*d)
            return *c-*d;
        else
            return *d-*c;
    }
}
int main()
{
    int i=0,j=0;
    char c;
    int T;
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        char s[1000]={0};
        j=0;
        do{scanf("%lf",&f[j++]);}while(c=getchar()!='\n');
        scanf("%s",s);
        qsort(s,strlen(s),sizeof(s[0]),cmp);
        printf("case #%d:\n",i);
        printf("%s\n",s);
    }
    
    return 0;
}
