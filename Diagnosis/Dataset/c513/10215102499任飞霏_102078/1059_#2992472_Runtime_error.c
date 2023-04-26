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
    int a[1010];
    for(int i=0;i<1010;i++)a[i]=1010;
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    qsort(a,n,sizeof(a[0]),cmp);
    int height=a[0],i=0;
    for(int i=1;i<=n;i++){
        int c = (a[i]-a[i-1])*i;
        if(s<c){
            break;
        }
        else{
            s-=c;
            height++;
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
