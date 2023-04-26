#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node
{
    long long int num;
    int t;

}NODE;
int cmp(const void *a,const void *b)
{
    NODE s1=*(NODE*)a;
    NODE s2=*(NODE*)b;
    if(s1.t!=s2.t)
        return s2.t-s1.t;
    else
    {
        if(s1.num>s2.num)
            return 1;
        else
            return -1;
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        int n;
        scanf("%d",&n);
        NODE a[n];
        char s[100];
        for(int i=0;i<n;i++)
        {
            scanf("%s",s);
            long long int temp=0;
            int len=strlen(s);
            if(s[0]=='-')
            {
                for(int i=1;i<len;i++)
                    temp=temp*10+s[i]-'0';
                a[i].num=-temp;
                a[i].t=s[1];
            }
            else
             {
                for(int i=0;i<len;i++)
                    temp=temp*10+s[i]-'0';
                a[i].num=temp;
                a[i].t=s[0];
            }
        }
         qsort(a,n,sizeof(a[0]),cmp);
         printf("case #%d:\n",i);
         for(int i=0;i<n;i++)
            printf("%lld ",a[i].num);
         printf("\n");
    }
    return 0;
}
