#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n=1,m=1;
    int a[11]={0};
    int gn1 = 0;
    int gn2 = 0;
    int c = 0;
    int num;
    while(n!=0||m!=0){
    scanf("%d%d",&n,&m);
    num = n;
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d%d",&gn1,&gn2,&c);
        if(c==1){
            a[gn1]+=3;
            a[gn2]-=1;
        }
        if(c==-1){
            a[gn2]+=3;
            a[gn1]-=1;
        }
        if(c==0){
            a[gn2]+=1;
            a[gn1]+=1;
        }
    }
    }
    a[0] = 1;
    for(int i=0;i<5;i++){
        printf("%d",a[i]);
    }
    return 0;
}
