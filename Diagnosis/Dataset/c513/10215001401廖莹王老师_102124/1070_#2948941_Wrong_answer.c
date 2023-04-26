#include <stdio.h>
#include <stdlib.h>
int a[100];
int jisuan(int n)
{
   a[0]=0; a[1]=2;a[2]=4;a[3]=7;
    if(n>=4)
    {
        if(a[n-1]==-1)a[n-1]=jisuan(n-1);
        else if(a[n-2]==-1)a[n-2]=jisuan(n-2);
        else if(a[n-3]==-1)a[n-3]=jisuan(n-3);
        a[n]=2*a[n-1]-a[n-2]+a[n-3];
    }
    return a[n];

}
int main()
{
    int n;
    int i=0;
        for(i=0;i<100;i++)a[i]==-1;
    while(1)
    {

        scanf("%d",&n);
        if(n==-1)break;
        else
        {
            int m=jisuan(n);
            printf("%d\n",m);
        }

    }
    return 0;
}
