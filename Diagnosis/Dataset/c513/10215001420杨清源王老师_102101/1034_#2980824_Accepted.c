#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double alp[26];

int main()
{
    double trans(char a,double *x);
    int cmp(const void *a1,const void *b1);
    int m;
    scanf("%d",&m);
    for(int z=0; z<m; z++)
    {
        for(int i=0; i<26; i++)
            scanf("%lf",&alp[i]);
        char s[100];

        scanf("%s",s);
        int l=strlen(s);

        //以上为输入部分

        qsort(s,l,sizeof(s[0]),cmp);

        printf("case #%d:\n",z);

        printf("%s",s);

        printf("\n");
    }
    return 0;
}

int cmp(const void *a1,const void *b1)
{
    double trans(char a,double *x);
    char a=*(char *)a1;
    char b=*(char *)b1;
    int num1,num2;
    if(a>='a'&&a<='z') num1=a-'a';
    if(a>='A'&&a<='Z') num1=a-'A';
    if(b>='a'&&b<='z') num2=b-'a';
    if(b>='A'&&b<='Z') num2=b-'A';
    double a0=trans(a,alp);
    double b0=trans(b,alp);
    if(a0>b0) return -1;
    else if(a0<b0) return 1;
    else if(a0==b0)
    {
        if(num1==num2)
        {
            if(a>=b) return -1;
            if(a<b) return 1;
        }
        else return (int)(a-b);
    }
}

double trans(char a,double *x)
{
    int i;
    int num;
    double ans;
    if(a>='a'&&a<='z')
    {
        num=a-'a';
        ans=x[num];
    }
    else if(a>='A'&&a<='Z')
    {
        num=a-'A';
        ans=x[num];
    }
    return ans;
}
