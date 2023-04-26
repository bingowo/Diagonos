#include <stdio.h>
#include <stdlib.h>

int GCD(int m, int n)
{
        if(n%m!=0)
                return GCD(n%m,m);
        else
                return m;
}

int main()
{
    int n;
    scanf("%d",&n);
    char c1;
    c1=getchar();
    for(int i=0; i<n; i++)
    {
            char c;
            int j=0,count=0;
            while((c=getchar())!='\n')
            {
                    int m=(int)c;
                    for(int z=0; z<8; z++)
                    {
                            if((m&(1<<z))!=0)
                                count++;
                    }
                    j++;
            }
            int n=GCD(count,j*8);
            printf("%d/%d\n",count/n,j*8/n);
    }
    return 0;
}
