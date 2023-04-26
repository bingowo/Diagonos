int main()
{
    int t,c=0;
    int a[33];
    long long n;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        scanf("%lld",&n);
        while(n!=0)
    {

        a[c]=n%2333;
        n=n/2333;
        c++;
    }
    c--;
    for(;c!=-1;c--)
    {
        printf("%d",a[c]);
        if(c!=0) printf(" ");
    }
    if(c==-1) printf("%d",0);
        c=0;
    printf("\n");
    }

    return 0;
}
