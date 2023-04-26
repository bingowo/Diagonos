int steps(long long a,long long b)
{
    long long n=1,i=0,j,k,h;
    unsigned long long a1,b1;
    a1=(unsigned long long)(a>0)?a:-a;
    b1=(unsigned long long)(b>0)?b:-b;
    unsigned long long m=a1+b1,m1=m;
    while (m1)
    {
        m1=m1/2;
        i++;
    }
    if (m==0) return 0;
    if (m%2==1) return i;
    else return -1;

}

int main()
{
    long long a,b;
    scanf("%lld %lld",&a,&b);
    printf("%d\n",steps(a,b));
}