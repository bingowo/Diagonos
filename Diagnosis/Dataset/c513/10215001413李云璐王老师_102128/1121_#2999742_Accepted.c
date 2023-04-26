#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>

int main()
{
    int n;
    scanf("%d",&n);
    int a[10]={0};
    int z=0;
    for(int i=0;i<n;i++)
     {scanf("%d",&a[i]);
     z+=a[i];}
    int ans[59049]={0};
    for(int i=0,h=0;i<pow(3,n);i++,h++)
    {
        int i1=i,f=0;
        int j=n-1;
        while(i1!=0)
        {
            if(i1%3==2) ans[h]+=a[j];
            else if(i1%3==1) ans[h]-=a[j];
            i1/=3;j--;f++;
        }
    }
    //for(int i=0;i<pow(3,n);i++) printf("%d ",ans[i]);
    //printf("%d\n",z);
    for(int k=1;k<=z;k++)
    {
        int i;
        for(i=0;i<pow(3,n);i++)
            if(k==ans[i]) {printf("1");break;}
        if(i==pow(3,n)) printf("0");
    }
    return 0;
}