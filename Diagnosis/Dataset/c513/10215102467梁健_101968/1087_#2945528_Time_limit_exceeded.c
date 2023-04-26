int main()
{
    int T;scanf("%d",&T);unsigned long long A;
    int judge(unsigned long long a)
    {
        char jud[101];
        unsigned long long c=a;int m=0;
        do{
            jud[m++]=c%10;
            c/=10;
        }while(c>0);
        if(m==1)return 1;
        for(int step=1;step<m;step++){
            if(jud[step]==jud[step-1])break;
            if(step==m-1)return 1;
        }
        return 0;
    }
    for(int i=0;i<T;i++){
        printf("case #%d:\n",i);
        scanf("%llu",&A);A++;
        for(;judge(A)!=1;A++);
        printf("%llu\n",A);
    }
    return 0;
}