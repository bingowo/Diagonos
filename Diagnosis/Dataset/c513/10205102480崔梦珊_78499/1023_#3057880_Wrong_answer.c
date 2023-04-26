#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct str
{
    char s[35];
    int flag;
    int data;
};

int strnumcmp(const void* a,const void* b)
{
    struct str* x=(struct str*)a;
    struct str* y=(struct str*)b;
    if(x->flag==0&&y->flag==0)
    {
        return strcmp(x->s,y->s);
    }
    if(x->flag==1&&y->flag==1)
    {
        if(x->data==y->data)
        {
            return strcmp(x->s,y->s);
        }
        return x->data-y->data;
    }
    return x->flag-y->flag;
}

int main()
{
    struct str ans[101];
    int n=0;
    int f=0;
    char c;
    for(int i=0;i<101;i++)
    {
        ans[i].data=0;
        ans[i].flag=0;
        for(int j=0;j<35;j++)
        {
            ans[i].s[j]='\0';
        }
    }
    while((c=getchar())!='\n')
    {
        printf("%c\n",c);
        if(c==' ')
        {
            n++;
            f=0;
        }
        else if(c>='0'&&c<='9')
        {
            ans[n].s[f]=c;
            ans[n].data=ans[n].data*10+c-48;
            f++;
            ans[n].flag=1;
        }
        else
        {
            ans[n].s[f]=c;
            f++;
        }
    }
    /*for(int i=0;i<n;i++)
    {
        printf("%s ",ans[i].s);
    }*/
    qsort(ans,n+1,sizeof(ans[0]),strnumcmp);
    for(int i=0;i<n;i++)
    {
        printf("%s ",ans[i].s);
    }
    printf("%s",ans[n].s);
}
