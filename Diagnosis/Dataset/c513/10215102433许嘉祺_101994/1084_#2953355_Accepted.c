#include <stdio.h>
#include <stdlib.h>
#include<string.h>


int main()
{
    int n;
    int t;
    scanf("%d",&t);
    int a[100];
    int len=0;
    for(int i=0;i<t;i++){
        scanf("%d",&n);
        memset(a,0,sizeof(a));
        len=1;
        a[0]=1;
        for (int j=0;j<n;j++){
            for (int k=0;k<len;k++){
                a[k]*=2;
            }
            int carry=0;
            for (int k=0;k<len;k++){
                a[k]=a[k]+carry;
                carry=a[k]/10;
                a[k]=a[k]%10;

            }
            while(carry)
            {
                a[len]+=carry;
                carry=a[len]/10;
                a[len]=a[len]%10;
                len++;
            }
        }
        printf("case #%d:\n",i);
        for (int i=len-1;i>=0;i--) printf("%d",a[i]);
        printf("\n");

    }

    return 0;
}
