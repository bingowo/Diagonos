#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t;
    int lena,lenb;
    int a[26],b[26],d[26];
    int p[25]= {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
    scanf("%d\n",&t);

    for (int y=0; y<t; y++)
    {
        memset(a,0,sizeof(int));
        memset(b,0,sizeof(int));
        memset(d,0,sizeof(int));
        lena=0;
        lenb=0;
        char c;
        while (!isspace(c=getchar())) if (c!=',')
            {
                a[lena]=c-'0'+a[lena]*10;
            }
            else lena++;
        lena++;
        while (!isspace(c=getchar())) if (c!=',')
            {
                b[lenb]=c-'0'+b[lenb]*10;
            }
            else lenb++;
        lenb++;
        for (int i=0; i<=lena/2-1; i++)
        {
            int l;
            l=a[i];
            a[i]=a[lena-1-i];
            a[lena-1-i]=l;
        }
        for (int i=0; i<=lenb/2-1; i++)
        {
            int l;
            l=b[i];
            b[i]=b[lenb-1-i];
            b[lenb-1-i]=l;
        }
        printf("case #%d:\n",y);
        int n;
        n=(lena>lenb)?lena:lenb;
        for (int i=0; i<n; i++)
        {
            d[i]=a[i]+b[i]+d[i];
            if (d[i]>=p[i])
            {
                d[i]=d[i]%p[i];
                d[i+1]=d[i+1]+1;
                if (n==i+1) printf("1,");
            }
        }

        for (int i=n-1; i>0; i--) printf("%d,",d[i]);
        printf("%d\n",d[0]);

    }



    return 0;
}