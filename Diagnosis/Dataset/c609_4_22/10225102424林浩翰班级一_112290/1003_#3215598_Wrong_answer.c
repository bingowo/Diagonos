#include<stdio.h>
#include<stdlib.h>
int main()
{
    int t;
    long long n;
    int r,count;
    char *s="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char *temp;
    temp=malloc(sizeof(char)*33);
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        scanf("%lld %d",&t,&r);
        count=0;
        if(n<0){
            n=n*(-1);
            printf("%c",'-');
        }
        while(n!=0){
            temp[count]=s[n%r];
            n/=r;
            count++;
        }
        for(int i=0;i<count;i++){printf("%c",temp[count-i-1]);}
        printf("%c",'\n');
    }
    free(temp);
    return 0;
}
