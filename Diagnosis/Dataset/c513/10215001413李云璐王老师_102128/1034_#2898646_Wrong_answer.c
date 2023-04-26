#include<string.h>
#include<stdlib.h>
#include<stdio.h>

void sort(char*p,double*s,int len)
{
    int cmp(const void*a1,const void*a2)
    {
        char a=*(char*)a1;
        char b=*(char*)a2;
        int wei1,wei2;
        if(a>='a'&&a<='z') wei1=a-97;
        else wei1=a-65;
        if(b>='a'&&b<='z') wei2=b-97;
        else wei2=b-65;
        if(s[wei1]>s[wei2]) return 1;
        else if(fabs(s[wei1]-s[wei2])<1e-8) 
        if(wei1=wei2) return b-a;
        else return wei1-wei2;
        else return -1;
    }
    qsort(p,len,sizeof(char),cmp);
}
int main()
{
    int n;
    scanf("%d\n",&n);
    for(int i=0;i<n;i++)
    {
        double s[26];
        for(int k=0;k<26;k++)
        scanf("%lf",&s[k]);
        char a[110];
        scanf("%s",a);
        int len=strlen(a);
        sort(a,s,len);
        printf("case #%d:\n",i);
        printf("%s\n",a);
    }
    return 0;
}