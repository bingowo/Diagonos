#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void* a,const void* b)
{
    int x=*((int*)a);
    int y=*((int*)b);
    return x-y;
}

int gcd(int a,int b)
{
    int c=a%b;
    while(c!=0){
        a=b;
        b=c;
        c=a%b;
    }
    return b;
}

int main()
{
    int n,s;
    scanf("%d%d",&n,&s);
    int a[1000];
    for(int i=0;i<1000;i++)a[i]=1001;
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    qsort(a,n,sizeof(a[0]),cmp);
    int height=0,i=0;
    while(s>0){
        height++;
        for(i=0;a[i]<height;i++);
        if(s<i)break;
        else{
            for(int i=0;a[i]<height;i++){
            s--;
            }
        }
    }
    if(s==0){
        printf("%d",height);
    }

    else{
        int g=gcd(s,i);
        if(height-1!=0)printf("%d+",height-1);
        printf("%d/%d",s/g,i/g);
    }
    return 0;
}
