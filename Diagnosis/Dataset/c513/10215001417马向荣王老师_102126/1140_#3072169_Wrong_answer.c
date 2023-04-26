#include<stdio.h>
#include<string.h>
int main()
{
    int n,m,k=0,c;
    scanf("%d\n",&n);
    int p[101],s[101],q[101];
    m=getchar();
    for(int i=0;i<m;i++)
    {
        scanf("%d ",&p[i]);
    }
    for(int i=0;i<n-1;i++)
    {
        c=getchar();
        for(int j=0;j<c;j++)
        {
            scanf("%d ",&q[j]);
            for(int r=0;r<m;r++)
            {
                if(p[r]==q[j])
                {
                    s[k]=q[j];
                    k++;
                    break;
                }
            }
        }
    }
    for(int i=0;i<k;i++)
    {
        printf("%d ",s[i]);
    }
    return 0;
}