#include <stdio.h>

int main()
{
    int n,i,i0,j,f,l,x,s;
    int a[20];
    scanf("%d",&n);
    while(n!=-1){
        x=1;
        for(i=0;i<n;i++)
            x=x*2;
        s=0;
        for(i=0;i<x;i++){
            i0=i;
            f=0;
            l=0;
            while(i0>0){
                a[l]=i0%2;
                i0=i0/2;
                l++;
            }
            for(j=0;j<l-2;j++)
                if(a[j]==1&&a[j+1]==0&&a[j+2]==1)
                    f=1;
            if(f==0)
                s++;
        }
        printf("%d\n",s);
        scanf("%d",&n);
    }
    return 0;
}
