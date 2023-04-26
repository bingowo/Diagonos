void Max(long long int *a, long long int *b)
{
    long long int *tmp;
    if(*a<*b)
    {
      *tmp=*a;
      *a=*b;
      *b=*tmp;
    }
}

int main()
{
    long long int x,y,re;
    unsigned long long int s;
    scanf("%lld %lld",&x,&y);
    Max(&x,&y);
    while(y != 0)
    {
        re=x/y;
        s+=re*y*4;
        x-=re*y;
        Max(&x,&y);
    }
    printf("%llu",s);
    return 0;
}