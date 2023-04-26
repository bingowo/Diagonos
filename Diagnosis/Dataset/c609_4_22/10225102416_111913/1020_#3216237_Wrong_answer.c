#include<stdio.h>
#include<string.h>

int num(char a[]);
int cmp(const void *a,const void *b);
int main()
{
    char a[100][31];
    int i=0;
    while(scanf("%s",a[i])!=EOF) i++;
    if(i==1){
        printf("%s",a[0]);
        return 0;
    }
    return 0;
}