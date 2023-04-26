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
    int ans_int,ans_fz,ans_fm;
    for(int i=1;i<=n;i++){
        int c = (a[i]-a[i-1])*i;
        if(s<c){
            ans_int = a[i-1] + s/i;
            ans_fz = s % i;
            ans_fm = i;
            break;
        }
        else
            s-=c;
    }
    int g = gcd(ans_fz,ans_fm);
    ans_fz /= g;
    ans_fm /= g;
    if(ans_int == 0 && ans_fz > 0){
        printf("%d/%d",ans_fz,ans_fm);
    }
    else{
        printf("%d",ans_int);
        if(ans_fz > 0){
            printf("+%d/%d",ans_fz,ans_fm);
        }
    }
    printf("\n");
    return 0;
}
