#include <stdio.h>

int main()
{
    char s,ch;int a[100];
    int i=0;
    do{
        scanf("%d",&a[i]);
        i++;
    }
    while ((ch=getchar())!='\n');
    int j;
    for (j=0;j<i;j++){
        if (a[j]>a[j+1]){
            a[j],a[j+1]=a[j+1],a[j];
        }
    }
    for (j=0;j<i;j++){
        if (s=='A'){
            printf("%d",a[j]);
        }
        if (s=='D'){
            printf("%d",a[i-j]);
        }
    }
    return 0;
}