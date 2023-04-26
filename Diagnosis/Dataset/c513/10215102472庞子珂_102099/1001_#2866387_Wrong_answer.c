#include<stdio.h>
#include<string.h>
int main()
{   int n,r,i;

    while(scanf("%d%d",&n,&r)!=EOF){

        if(n<0)
        {
            printf("-");n=-n;
        }
        if(n==0){printf("0\n");}
        int c=0,a[100];
        while(n)
        {
            a[c]=(n%r);
            c++;
            n/=r;

        }
        for(i=c-1;i>=0;i--)
        {
            if(a[i]>=10){
                printf("%c",'A'+a[i]-10);

            }
            else printf("%d",a[i]);
        }
        printf("\n");}

}
