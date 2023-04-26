#include <stdio.h>
#include <stdlib.h>

void sort1(int a[],int n);
void sort2(int a[],int n);

int main()
{
    int T;
    scanf("%d",&T);
    for(int i = 0;i < T;i++){
        printf("case #%d:\n",i);
        int n;
        scanf("%d",&n);
        int a[1000] = {0},b[1000] = {0};
        for(int j = 0;j < n;j++){
            scanf("%d",&a[j]);
        }
        sort1(a,n);
        for(int j = 0;j < n;j++){
            scanf("%d",&b[j]);
        }
        sort2(a,n);
        int ans = 0;
        for(int j = 0;j < n;j++){
            ans = ans + a[j]*b[j];
        }
        printf("%d\n",ans);
    }
    return 0;
}

void sort1(int a[],int n)
{
    for(int i = 0;i < n - 1;i++){
        for(int j = 0;j < n-1-i;j++){
            if(a[j]>a[j+1]){
                int t = a[j];
                a[j] = a[j+1];
                a[j+1] = t;
            }
        }
    }
}

void sort2(int a[],int n)
{
    for(int i = 0;i < n - 1;i++){
        for(int j = 0;j < n-1-i;j++){
            if(a[j]<a[j+1]){
                int t = a[j];
                a[j] = a[j+1];
                a[j+1] = t;
            }
        }
    }
}
