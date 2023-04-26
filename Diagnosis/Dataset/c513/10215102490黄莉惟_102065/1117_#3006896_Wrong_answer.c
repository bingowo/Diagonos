#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define L 100
typedef struct {
    char xnum[100];
    char ynum[100];
    char maxnum[100];
}Chebyshev;
void minus1(int a[],int b[])
{   int i;
    for(i=L;i>0;i--)
    {
        a[i] -= b[i];
        if(a[i]<0){
            a[i-1]-=1;
            a[i]+=10;
        }
    }
}
int main(){
    char x1[L+1];
    char y1[L+1];
    Chebyshev a[100];
    scanf("%s %s",a[0].xnum,a[0].ynum);
    int n;
    for(int i=1;i<n+1;i++){
        scanf("%s %s",a[i].xnum,a[i].ynum);
        
    }
}