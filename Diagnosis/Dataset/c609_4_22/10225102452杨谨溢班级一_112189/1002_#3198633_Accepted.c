int main()
{
    int T;
    scanf("%d",&T);
    for (int j = 0;j<T;++j)
    {
        int n;
        scanf("%d",&n);
        int out = 0;
        int i = 0;
        int L[40] = {0};
        while(n>0)
        {
            int a = 0;
            a = n & 1;
            L[i++] = a;
            //printf("%d",a);
            n = n>>1;
        }
        //printf("\nHHHHHHHHHHHHHHHHHHHHHHHHHHH");
        int sum = 1;
        for (int e = 0;e<i-1;++e)
        {
            if (L[e] != L[e+1]) {sum++;}/*printf("%d---",sum);*/
            else {
            out=(out>sum?out:sum);
            //printf("%d   MMMMMMMMMM\n",out);
            sum = 1;}
        }
        printf("case #%d:\n%d\n",j,out>sum?out:sum);
    }
    return 0;
}
