void _10toR(int n,int r)
{
    int a[100]= {0};
    int i=0,j=0;
    while(n!=0)
    {
        if(n%r<0)//余数小于0时特殊处理
        {
            a[i]=n%r-r;
            n=n/r+1;
        }
        else
        {
            a[i]=n%r;
            n/=r;
        }
        i++;
    }

    for(j=i-1; j>=0; j--)
    {
        if(a[j]>9) printf("%c",a[j]+55);
        else printf("%d",a[j]);
    }
    printf("\n");
}

int main()
{

    int n,r;
    scanf("%d %d",&n,&r);

    _10toR(n,r);


    return 0;
}