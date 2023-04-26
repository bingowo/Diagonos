#include <stdio.h>

int main()
{
    int m, n[21]={0};
    n[1]=2;
    n[2]=4;
    n[3]=7;
    for(int i=4; i<21; i++) n[i]=2*n[i-1]-n[i-2]+n[i-3];
    scanf("%d",&m);
    while(m+1){
        printf("%d",n[m]);
        scanf("%d",&m);
    }
    return 0;
}