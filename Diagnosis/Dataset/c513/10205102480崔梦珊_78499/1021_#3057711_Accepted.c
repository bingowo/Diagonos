#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct acm
{
    char str[22];
    int flag[22];
};
int cmp(const void* a,const void* b)
{
    struct acm* x=(struct acm*)a;
    struct acm* y=(struct acm*)b;
    int len1=strlen(x->str);
    int len2=strlen(y->str);
    int shortt=len1;
    if(len1>len2)
    {
        shortt=len2;
    }
    for(int i=0;i<shortt;i++)
    {
        if(x->flag[i]!=y->flag[i])
        {
            return (x->flag[i]-y->flag[i]);
        }
    }
    return len1-len2;

}
char s[55];
int di[500];
int main()
{
    while(scanf("%s",s)!=EOF)
    {
        for(int i=0;i<strlen(s);i++)
        {
            di[s[i]]=i;
            di[s[i]+32]=i;
        }
        struct acm res[101];
        for(int i=0;i<101;i++)
        {
            for(int j=0;j<22;j++)
            {
                res[i].str[j]='\0';
            }
        }
        char c=getchar();
        int i=0,j=0;
        int temp=1;
        while((c=getchar())!='\n')
        {
            if(c==' ')
            {
                j=0;
                i++;
            }
            else
            {
                res[i].str[j]=c;
                res[i].flag[j]=di[c];
                j++;
            }
        }
        int n=i+1;

        /*for(int p=0;p<n;p++)
        {
            for(int q=0;q<strlen(res[p].str);q++)
            {
                printf("%d ",res[p].flag[q]);
            }
            printf("\n");
        }*/

        qsort(res,n,sizeof(res[0]),cmp);
        for(int i=0;i<n-1;i++)
        {
            printf("%s ",res[i].str);
        }
        printf("%s\n",res[n-1].str);
    }
}
