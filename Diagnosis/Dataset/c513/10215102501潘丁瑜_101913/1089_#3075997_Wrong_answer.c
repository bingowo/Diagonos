#include <stdio.h>
#include <stdlib.h>
#define L 100
void mult (int *p, int a)
{
    int c = 0, t, i;
    for (i = L; i>0; i--)
    {
        t = p[i] * a + c;
        p[i] = t % 10;
        c = t / 10;
	}
}

void output(int a[],int n)
{
    int i=0;
    for(i=L-n+1;i<L;i++)
        printf("%d",a[i]);
    printf("%d\n",a[i]);
}
int main()
{
    int t,i,j;
    int a,b,n;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        scanf("%d",&a);
        scanf("%d",&b);
        scanf("%d",&n);
        int p[L+1]={0};
        p[L] = 1;
        printf("case #%d:\n",i);

        if(b == 0)
            printf("1\n");
        else
        {
            for(j=0;j<b;j++)
            {
                mult(p,a);
            }
            output(p,n);
        }

    }
    return 0;
}