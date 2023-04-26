int main()
{
    int T,j;
    scanf("%d",&T);
    for(j=0;j<T;j++)
        {
            printf("case #%d:\n",j);
            int m,n,large,small,i;
            unsigned long long P=1;//设置一个64位无符号整数保存结果
            scanf("%d %d",&m,&n);
            if(m>2*n){small=n,large=m-n;}
            else{small=m-n,large=n;}
            for(i=m;i>large;i--)
            {
                if(i==2*small)
                {
                    P=P*2;small--;
                 }
                 else P=P*i;
             }
            while(small>1)
           {
             P=P/small;small--;
           }
            printf("%I64d\n",P);
        }
        return 0;
}
