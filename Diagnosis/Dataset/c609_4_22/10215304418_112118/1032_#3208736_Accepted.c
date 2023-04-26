#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int main(){
    char st[123];
    int a[123];
    scanf("%s",st);
    int maxn=1;
    a[0]=1;
    for (int i=1;i<strlen(st);i++){
        if (st[i]!=st[i-1]){
            a[i]=a[i-1]+1;
            if (a[i]>maxn) maxn=a[i];
        }
        else a[i]=1;
    }
    printf("%d\n",maxn);
    return 0;
}
