#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct str
{
    char s[25];
    int num;
};

int cmp(const void* a,const void* b)
{
    struct str* x=(struct str*) a;
    struct str* y=(struct str*) b;
    if(x->num==y->num)
    {
        return strcmp(x->s,y->s);
    }
    return y->num-x->num;
}
int main()
{
    int T;
    scanf("%d\n",&T);
    for(int i=0;i<T;i++)
    {
        int n;
        struct str ans[105];
        for(int m=0;m<105;m++)
        {
            for(int l=0;l<25;l++)
            {
                ans[m].s[l]='\0';
            }
        }
        scanf("%d",&n);
        char c=getchar();
        for(int j=0;j<n;j++)
        {
            ans[j].num=0;
            int temp=0;
            int flag[300]={0};
            while((c=getchar())!='\n')
            {
                ans[j].s[temp]=c;
                if(flag[c]==0)
                {
                    flag[c]=1;
                }
                temp++;
            }
            for(int k=0;k<300;k++)
            {
                ans[j].num=ans[j].num+flag[k];
            }
        }
        qsort(ans,n,sizeof(ans[0]),cmp);
        printf("case #%d:\n",i);
        /*printf("%s\n",ans[1].s);*/
        for(int j=0;j<n;j++)
        {
            printf("%s\n",ans[j].s);
        }
    }
}
