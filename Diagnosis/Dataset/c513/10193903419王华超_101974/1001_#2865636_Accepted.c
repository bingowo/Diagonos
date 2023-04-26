#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
    char s[33];
}qt;
qt qts[100];
void transfer(int n,int r,char *p)
{
    char table[]={"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    int index=0,ys,flag=0;
    if (n<0)
    {
        n=-n;
        flag=1;
    }
    while (n)
    {
        ys=n%r;
        *p=table[ys];
        n=n/r;
        p++;
    }
    if (flag==1){
        *p='-';
        p++;
    }
    *p='\0';
}
int main()
{
    int t,index=0;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        int n,r;
        scanf("%d %d",&n,&r);
        char ps[33];
        transfer(n,r,ps);
        strcpy(qts[index].s,ps);
        index++;
    }
    for(int i=0;i<t;i++){
        for(int j=strlen(qts[i].s)-1;j>=0;j--){
            printf("%c",qts[i].s[j]);
        }
        printf("\n");
    }
    return 0;
}
