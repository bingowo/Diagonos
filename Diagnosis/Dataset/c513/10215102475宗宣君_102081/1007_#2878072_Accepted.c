#include <stdio.h>
int main()
{
    int T,n[10],i,p[32],j ,k;
    scanf("%d",&T);
    for(i = 0;i<T;i++)
        scanf("%d",&n[i]);
    for(i =0;i<T;i++)
    {   j = 0;
        while(n[i]!=0)
        {
            p[j] = n[i]%2;
            n[i] = n[i]/2;
            j++;
        }
        int m[] = {1,1};
        for(k = 1;k<j;k++)
        {
            if(p[k]==p[k-1]) m[0] = 1;
            else m[0]++;
            m[1] = m[1]>m[0]?m[1]:m[0];
        }
        printf("case #%d:\n%d\n",i,m[1]);
    }
    return 0;
}
