#include <stdio.h>

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        char s[100];
        scanf("%s",s);
        int j=0;
        long long int n=0;
        while(s[j])
        {
            if(s[j]=='-')
                s[j]=-1;
            else
                s[j]-='0';
            n=n*3+s[j];
            j++;
        }
        printf("case #%d:\n%lld\n",i,n);
    }
    return 0;
}
