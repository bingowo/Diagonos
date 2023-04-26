int main()
{
    int T,i,j,k;
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        printf("case #%d:\n",i);
        int num;
        scanf("%d",&num);
        int a[32],temp=0;
        for(j=0;(num/2==0)&&(j<32);j++)
        {
            if(num%2==0) a[j]=0;
            else a[j]=1;
            num=num/2;
        }
        for(k=0;k<31;k++)
        {
            if(a[k]!=a[k+1])temp++;
        }
        printf("%d\n",temp);
    }
    return 0;
}


