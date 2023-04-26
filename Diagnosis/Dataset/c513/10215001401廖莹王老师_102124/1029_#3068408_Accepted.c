#include <stdio.h>
#include <stdlib.h>
int cmp(const void*a,const void*b)
{
   return *(char*)a-*(char*)b;
}
void jisuan(int h)
{
    char s[250]={0};
    char m[250]={0};
    int i,j=0;
    gets(s);
    for(i=0;s[i];i++)
    {
        if(s[i]>='A' && s[i]<='Z'){m[j]=s[i];j++;}
    }
    qsort(m,j,sizeof(m[0]),cmp);
    j=0;
    for(i=0;s[i];i++)
    {
        if(s[i]>='A' && s[i]<='Z'){s[i]=m[j];j++;}
    }
    printf("case #%d:\n""%s\n",h,s);
}
int main()
{
    int n,h;
    scanf("%d",&n);
    getchar();
    for(h=0;h<n;h++)jisuan(h);
    return 0;
}
