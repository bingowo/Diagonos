#include<stdio.h>
int main()
{
    int T=0,j;
    long long int result[10]= {0};
    scanf("%d",&T);
    for(j=0; j<T; j++)
    {
        char s[61];
        scanf("%s",s);
        int a[122],x=0,R=1,i;
        for (i=0; i<122; i++)
            a[i]=-1;
        char *p=s;
        a[*p]=1;
        while (*++p)
            if (a[*p]==-1)
            {
                a[*p]=x;
                if (x>=2)
                    x++;
                else
                    x = 2;
                R++;
            }
        if (R<2) R=2;
        p=s;
        while (*p)
            result[j]=result[j]*R+a[*p++];
        printf("case #%d:\n%lld\n",j,result[j]);
    }
    return 0;
}
