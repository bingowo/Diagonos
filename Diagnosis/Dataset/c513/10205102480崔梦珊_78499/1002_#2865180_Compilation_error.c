#include <stdio.h>
int main()
{
    int T;
    scanf("%d", &T);
    for(int s=0;s<T;s++)
    {
        char a[62];
        int b[200]；
        int i=0;
        char c='\n';
        while (c=='\n')
            scanf("%c", &c);
        while(c!='\n')
        {
            a[i++]=c;
            scanf("%c", &c);
        }
        for(int x=0;x<200;x++)
            b[x]=-1;
        int j=1,f=0,k=0;
        for(int x=0;x<i;x++)
        {
            if (b[a[x]]==-1) 
            {
                b[a[x]]=j;
                f=1;
                k++;
            }
            if (f)
            {
                if (j>=2) j++;
                if (j==0) j=2;
                if (j==1) j--;
                f=0;
            }
        }
        if (k==1) k++;
        long long res=0;
        for(int x=0;x<i;x++)
        {
            res=res+b[a[x]];
            res=res*k;
        }
        res=res/k;
        printf("case #%d:\n%lld\n",s,res);
    }
    return 0;
}
