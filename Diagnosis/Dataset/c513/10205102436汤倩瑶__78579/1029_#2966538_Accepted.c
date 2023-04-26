#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int cmp(const void*a,const void*b )
{
    return *((char*)a)-*((char*)b);

}
int main()
{
    int T;
    char s[205];
    scanf("%d",&T);
    gets(s);
    for(int i;i<T;i++)
    {
        printf("case #%d:\n",i);
        gets(s);
        int l=strlen(s);
        char p[205];
        int a[205]={0};
        int cnt=0;
        for(int j=0;j<l;j++)
        {
            if(s[j]>='A'&&s[j]<='Z'){p[cnt++]=s[j];a[j]=1;}
        }
        p[cnt]='\0';

        qsort(p,cnt,sizeof(p[0]),cmp);
        cnt=0;
        for(int j=0;j<l;j++)
        {
            if(a[j]==1){printf("%c",p[cnt]);cnt++;}
            else printf("%c",s[j]);
        }
        printf("\n");

    }

}
