int main()
{
    int T,i;
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        printf("case #%d:\n",i);
        int n;
        scanf("%d",&n);
        printf("%d\n",n/5+n/25+n/125+n/625);
    }
        return 0;
}
