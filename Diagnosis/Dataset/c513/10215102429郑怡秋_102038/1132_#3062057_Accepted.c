#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        int n,r;
        scanf("%d%d",&n,&r);
        int ans[30]={0};
        int j=0;
        while(n>0)
        {
            ans[j]=n%r;
            n/=r;
            j++;
        }
        int an=0;
        for(int k=0;k<j;k++) an+=ans[k];
        char A[30]={0};
        int p=0;
        while(an>0) A[p]=(an%r<0||an%r>9)?(an%r-10+'A'):an%r+'0',an/=r,p++;
        printf("case #%d:\n",i);
        for(int h=p-1;h>=0;h--) printf("%c",A[h]);
        printf("\n");
    }
    return 0;
}