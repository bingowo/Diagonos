#include <stdio.h>
#include <stdlib.h>
#include<string.h>



int main()
{
    int t;
    scanf("%d",&t);
    int a,b,n;
    int* num;
    for (int i=0;i<t;i++){
            scanf("%d%d%d",&a,&b,&n);
        num=(int*)malloc(sizeof(int)*n);
        memset(num,0,sizeof(int)*n);

        num[0]=1;
        for (int j=0;j<b;j++){
            for (int k=0;k<n;k++)
                num[k]*=a;
                int carry=0;
            for(int k=0;k<n;k++){
                num[k]=num[k]+carry;
                carry=num[k]/10;
                num[k]=num[k]%10;
            }

        }
        printf("case #%d:\n",i);
        for (int j=n-1;j>=0;j--) printf("%d",num[j]);
        printf("\n");
        free(num);
    }
}