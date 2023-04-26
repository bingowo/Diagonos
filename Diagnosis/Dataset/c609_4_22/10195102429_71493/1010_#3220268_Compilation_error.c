#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,r;
    scanf("%d%d",&n,&r);
    if(n==0){
        printf("0\n");
    }
    int a[10005];
    int i=0;
    int shang,yu;
    while(n){
        yu=n%r;
        shang=n/r;
        if(yu<0){
            yu-=r;
            shang++;
        }
        a[i]=yu;
        i++;
        n=shang;
    }
    for(int j=num-1;j>=0;j--){
            if(a[j]<10){
                printf("%d",a[j]);
            }
            else printf("%d",a[j]-10+'A');
    }
    return 0;
}
