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
        int*num1=malloc(sizeof(int)*n);
        memset(num,0,sizeof(int)*n);
        memset(num1,0,sizeof(int)*n);
        for (int j=0;j<n;j++)
            {num1[j]=a%10;
            a=a/10;
            
            }
        num[0]=1;
        for (int j=0;j<b;j++){
            for (int k=n-1;k>=0;k--)
                for (int l=0;l<=k;l++)
                    if (l==0)
                    num[k]=num[k-l]*num1[l];
                    else num[k]+=num[k-l]*num1[l];
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
        free(num1);
    }
    return 0;
}