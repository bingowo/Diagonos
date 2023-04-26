#include <stdio.h>
int main()
{
    int T,a[123],i,j,n,m,p,q,k,l;
    long long int res;
    scanf("%d",&T);
    char b[T][61];
    for(i = 0;i<T;i++)
        scanf("%s",b[i]);
    for(i = 0;i<T;i++)
    {   for(l = 0;l<123;l++)
        a[l] = -1;
        res = 0;
        p = b[i][0];
        a[p] = 1;
        j = 1;n = 2;
        while(b[i][j] !='\0')
        {
            q = b[i][j];
            if(a[q]==-1)
            {
                if(n==2) a[q]=0;
                else a[q] = n-1;
                n++;
            }
            j++;
        }
        for(m = 0;m<j;m++)
        {   k = b[i][m];
            res = res*(n-1>2?n-1:2)+a[k];
        }
        printf("case #%d:\n%lld\n",i,res);

    }
    return 0;
}