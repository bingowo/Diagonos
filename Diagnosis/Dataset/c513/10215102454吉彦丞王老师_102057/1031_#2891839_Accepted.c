#include<stdio.h>
#include<stdlib.h>
int cmp(const void *pa,const void *pb)
{
    int a,b;
    a=*((int *)pa);
    b=*((int *)pb);
    return a-b;
}

int main()
{
    int number;
    scanf("%d",&number);
    long long result[number];
    int demonsion[number];
    for(int i=0;i<number;i++)
    {
        scanf("%d",&demonsion[i]);
        int a[demonsion[i]];
        int b[demonsion[i]];
        for(int t=0;t<demonsion[i];t++)
        {
            scanf("%d",&a[t]);
        }
        for(int q=0;q<demonsion[i];q++)
        {
            scanf("%d",&b[q]);
        }
        qsort(a,demonsion[i],sizeof(int),cmp);
        qsort(b,demonsion[i],sizeof(int),cmp);
        int answer=0;
        for(int j=0;j<demonsion[i];j++)
        {
            answer=answer+a[j]*b[demonsion[i]-j-1];
        }
        result[i]=answer;
    }
    for(int k=0;k<number;k++)
    {
        printf("case #%d:\n",k);
        printf("%lld\n",result[k]);
    }
    return 0;
}