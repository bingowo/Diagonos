#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

int main()
{
    int i,j,k,T,l;
    int s[10007]={0};
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        int a,n;
        scanf("%d%d",&a,&n);
        printf("case #%d:\n",i);
        if(n==0) printf("1\n");
        else
        {
        s[0]=1;
        for(j=0,k=0;j<n;j++)
        {
            for(l=0;l<=k;l++)
                s[l]*=a;
            for(l=0;l<=k;l++)
            {
                if(s[l]>=10)
                {
                    s[l+1]+=s[l]/10;
                    s[l]%=10;
                    if(l==k) k++;
                }
            }
        }
        if(s[k]==0) k--;
        char p;
        for(l=0;l<=k/2;l++)
        {
            p=s[l];
            s[l]=s[k-l];
            s[k-l]=p;
        }
        for(l=0;l<=k;l++)
            printf("%d",s[l]);
        printf("\n");
        for(j=0;j<=k;j++) s[j];
        }
    }
    return 0;
}
