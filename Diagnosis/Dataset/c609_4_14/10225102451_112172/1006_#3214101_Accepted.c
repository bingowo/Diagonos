int main()
{
    int t;
    scanf("%d",&t);
    for(int k;k<t;k++){
        char s[61];
        scanf("%s",s);
        int a[128];
        for(int i=0;i<128;i++)a[i]=-1;
        char *p=s;
        a[*p]=1;
        int r=0;
        while(*++p){
            if(a[*p]==-1){
                a[*p]=r;
                r=r?r+1:2;
            }
        }
        if(r<2)r=2;
        long long int n=0;
        p=s;
        while(*p){
            n=n*r+a[*p++];
        }
        printf("case #%d:\n%lld\n",k,n);
    }
    return 0;
}