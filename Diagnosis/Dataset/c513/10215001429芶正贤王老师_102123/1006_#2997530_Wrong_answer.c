int main()
{
    int T,i,j,k,t;
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        printf("case#%d:\n",i);
        char s[30];
        int sz=strlen(s);
        scanf("%s",s);
        long long int ansA=0;
        for(j=0;j<sz;j++)
        {
            if(s[j]=='0')ansA=ansA*3;
            if(s[j]=='1')ansA=ansA*3+1;
            if(s[j]=='-')ansA=ansA*3-1;
        }
        printf("%d\n",ansA);
    }
    return 0;
}