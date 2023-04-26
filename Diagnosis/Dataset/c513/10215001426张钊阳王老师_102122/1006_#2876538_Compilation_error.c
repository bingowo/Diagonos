 int m,i=0,j,count=0;
    long long int sum=0;
    scanf("%d",&m);
    char k[30];
    for(j=0;j<m;j++)
    {
        count=0;
        scanf("%s",k);
        while(k[i])
        {
            count++;
            i++;
        }
        for(i=0;i<count;i++)
        {
            if(k[i]=='-') sum=sum-pow(3,count-i-1);
            if(k[i]=='0')  continue;
            if(k[i]=='1') sum=sum+pow(3,count-i-1);
        }
        printf("case #%d:\n",j);
        printf("%lld\n",sum);
    }
    return 0;
}
