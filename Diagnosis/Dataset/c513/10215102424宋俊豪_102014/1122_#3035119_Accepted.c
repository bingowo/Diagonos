int main()
{
    int T,i;
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        int count=0;
        int j;
        unsigned long long n;
        scanf("%llu",&n);
        int a[20];
        if(n==0)
        {
            a[count++]=0;
        }
        else
        {
            while(n>0)
            {
                a[count++]=n%2333;
                n=n/2333;
            }
        }
            for(j=count-1;j>=0;j--)
            {
                printf("%d ",a[j]);
            }
            printf("\n");
    }
    return 0;
}