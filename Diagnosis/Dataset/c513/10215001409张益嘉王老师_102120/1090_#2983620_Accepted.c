int main()
{
    int i,k;
    double n,a;
    while(1)
    {
        scanf("%lf",&n);
        if(n==0) break;
        k=n*log10(n);
        a=pow(10,(n*log10(n))-k);
        printf("%d\n",(int)a);
    }
    return 0;
}