#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<math.h>
 long long int p[11000][2];
int cmp(const void*p1,const void*p2)
{
     long long*p_1 = (long long*)p1;
     long long*p_2 = (long long*)p2;
     if(p_1[1]<p_2[1])return 1;
     else if(p_1[1]==p_2[1])return(p_1[0]>p_2[0])?1:-1;
     else return -1;
}
int main()
{

    int t;
    scanf("%d",&t);
    for(int i =0 ;i<t;i++)
    {
        int N;
        scanf("%d",&N);

        for(int g = 0;g<N;g++)
        {

            long long int b;
            scanf("%lld",&b);
            p[g][0] = b;
            while(b/10!= 0 )b/=10;
            p[g][1] = abs((int)b);
        }
        qsort(p,N,sizeof(long long)*2,cmp);

    printf("case #%d:\n",i);
    for(int q =0 ;q<N;q++)
    {
        printf("%lld ",p[q][0]);
    }
    printf("\n");

    }
    return 0;
}
