#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
#include<ctype.h>
int main()
{
    int i,n;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        int a[9],j,x,x0,b,k,carry=0;
        for(j=0;j<9;j++)a[j]=0;
        scanf("%d%d%d",&x,&b,&k);
        x=x%((int)pow(10,k));
        j=0;x0=x;
        while(x)
        {
            a[k-1-j]=x%10;
            x/=10;
            j++;
        }
        for(int m=1;m<b;m++){carry=0;;for(j=k-1;j>=0;j--){a[j]*=x0;a[j]+=carry;carry=a[j]/10;a[j]%=10;}}
        printf("case #%d:\n",i);
        for(j=0;j<k;j++)printf("%d",a[j]);
        printf("\n");
    }
}

