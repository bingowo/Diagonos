#include <stdio.h>
#include <stdlib.h>
#include<string.h>



int main()
{
    int t;
    scanf("%d",&t);
    for (int i=0;i<t;i++){
        int a,n;
        scanf("%d %d",&a,&n);
        int b[1001];
        memset(b,0,sizeof(b));
        b[0]=1;
        int len=1;
        for (int j=0;j<n;j++){
            for (int k=0;k<len;k++){
                b[k]=b[k]*a;
            }
            int carry=0;
            for (int k=0;k<len;k++){
                b[k]=b[k]+carry;
                carry=b[k]/10;
                b[k]=b[k]%10;
            }
            while (carry>0) {
                b[len]=carry;
                carry=b[len]/10;
                b[len]=b[len]%10;
                len++;
            }
        }
        printf("case #%d:\n",i);
        for (int j=len-1;j>=0;j--) printf("%d",b[j]);
        printf("\n");

    }
    return 0;
}
