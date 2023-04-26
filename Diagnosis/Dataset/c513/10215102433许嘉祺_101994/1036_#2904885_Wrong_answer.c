#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>

int cmp(const void*a,const void*b)
{
    int a1=(*(int(*)[3])a)[2],b1=(*(int(*)[3])b)[2];
    if (a1>b1) return -1;
    else return 1;
}
int main()
{
    int a[100][3];
    int n;
    int b[100];
    scanf("%d",&n);
    for (int i=0; i<n; i++)
    {
        scanf("%d %d",&a[i][0],&a[i][1]);
        a[i][2]=abs(a[i][0])+abs(a[i][1]);
    }
    qsort(a,n,sizeof(a[0]),cmp);

    for (int i=0; i<n-1; i++)
        b[i]=abs(a[i][0]-a[i+1][0])+abs(a[i][1]-a[i+1][1]);
    printf("%d\n",b[0]);
    int count=0;
    for (int i=0; i<n-1; i++)
    {
        if (b[i]%2==1)
        {
            while(b[i]>0)
            {
                if (b[i]==1)
                {
                    count++;
                    break;
                }
                else if(b[i]%4==1)
                {
                    count++;
                    b[i]=(b[i]+1)/2;
                }
                else
                {
                    count++;
                    b[i]=(b[i]-1)/2;
                }
            }

        }
        else break;
    }
    printf("%d\n",count);

    return 0;
}