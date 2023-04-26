#include<stdio.h>
int main()
{
    int T=0;
    int j=0,m=0;
    scanf("%d\n",&T);
    for(j=0;j<T;j++)
    {
        int n=0;
        int arr[74];
        scanf("%d\n",&n);
        for(m=0;m<n;m++)
        {
            if(n==0) {arr[m]=0;break;}
            else if(m==1) {arr[m]=1;break;}
            else if(m==2) {arr[m]=1;break;}
            arr[m]=arr[m-1]+arr[m-2]+arr[m-3];
        }
        printf("case #%d:\n",j);
        printf("%d\n",arr[m]);
    }
    return 0;
}