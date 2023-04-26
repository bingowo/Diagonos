#include<stdio.h>
int main()
{
    int a,b,n;
    scanf("%d",&n);
    for(int j=0;j<n;j++)
    {
        scanf("%d %d",&a,&b);
        int ans[200000],count=0,yu[100000],test=0,mem=0;
        for(int i=0;i<100000;i++) yu[i]=-1;
    while(a)
    {
        ans[count++]=a/b;
        a%=b;
        if(yu[a]==-1) yu[a]=count-1;
        else
        {
            mem=yu[a];
            test=1;
            break;
        }
        a*=10;
        if(test==1) break;
    }
    printf("case #%d:\n",j);
    if(test==0)
    {
        printf("0.");
        for(int i=1;i<count;i++) printf("%d",ans[i]);
        printf("\n");
    }
    else
    {
        printf("0.");
        for(int i=1;i<count;i++) printf("%d",ans[i]);
        printf("\n");
        printf("%d-%d",mem+1,count-1);
    }
    }
}
