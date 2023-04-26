#include<stdio.h>
int ti(int n)
{
    int t=0;
    int a=0,b=1,c=1,i=3;
    if(n==0) return 0;
    else if(m==1) return 1;
    else if(m==2) return 1;
    for(i=3;i<m+1;i++)
    {
        t=a+b+c;
        a=b;
        b=c;
        c=t;
    }
    return t;
}
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