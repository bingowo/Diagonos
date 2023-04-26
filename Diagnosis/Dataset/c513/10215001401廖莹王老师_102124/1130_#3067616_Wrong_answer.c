#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,n;
    double t[200]={0};
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        int j=0,k=0,z=0;
        scanf("%lf",&t[i]);
        printf("%d",(int)t[i]);
        for(j=2;;j++)
        {
            z=(int)pow(t[i],1.0/j);
            if(z<2)break;
            if((pow(t[i],1.0/j)-(double)z)>0);
            else {printf("=%d^%d",z,j);k++;}
        }
        if(k==0)printf(" is powerless.\n");
        else printf("\n");
    }


    return 0;
}
