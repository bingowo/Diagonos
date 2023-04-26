#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
int cmp(const void *a,const void *b)
{
    long long int t1=0,t2=0;
    long long int x=*(long long int*)a;
    long long int y=*(long long int*)b;
    t1=x;
    t2=y;
    while(t1/10!=0)
        t1=t1/10;
    t1=abs(t1);
    while(t2/10!=0)
        t2=t2/10;
    t2=abs(t2);
    if (t1==t2)
        {
            if (x>y)
                return 1;
            else
                return -1;
        }
    else
        return t2-t1;
}

int main()
{
    int n,n1;;
    long long int a[1000];
    scanf("%d",&n);
    for (int i=0; i<n; i++)
    {
        int cnt=0;
        scanf("%d",&n1);
        for (int j=0; j<1000; j++)
        {
            a[j]=0;
        }
        for (int j=0; j<n1; j++)
        {
            scanf("%lld",&a[j]);
            cnt++;
        }
        qsort(a,cnt,sizeof(long long int),cmp);
        printf("case #%d:\n",i);
        for(int j=0; j<cnt; j++)
            printf("%lld%c",a[j],j==cnt-1?'\n':' ');
    }

}
