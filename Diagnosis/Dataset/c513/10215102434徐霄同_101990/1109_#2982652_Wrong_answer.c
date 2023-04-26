#include <stdio.h>

int main()
{
    int a[9];
    int t,i,j,n;
    scanf("%d",&t);
    for(i=0;i<t;i++){
        for(j=8;j>=0;j--)
            scanf("%d",&a[j]);
        printf("case #%d:\n",i);
        n=8;
        while(n>=0&&a[n]==0)
            n--;
        if(n==-1)
            printf("0\n");
        else{
            for(j=n;j>=2;j--){
                if(a[j]==1){
                    if(j==n)
                        printf("x^%d",j);
                    else
                        printf("+x^%d",j);
                }
                else if(a[j]>1){
                    if(j==n)
                        printf("%dx^%d",a[j],j);
                    else
                        printf("+%dx^%d",a[j],j);
                }
                else if(a[j]==-1)
                    printf("-x^%d",j);
                else if(a[j]<-1)
                    printf("%dx^%d",a[j],j);
            }
            if(a[1]==1){
                if(n==1)
                    printf("x");
                else
                    printf("+x");
            }
            else if(a[1]>1){
                if(n==1)
                    printf("%dx",a[1]);
                else
                    printf("+%dx",a[1]);
            }
            else if(a[1]==-1)
                printf("-x");
            else if(a[1]<-1)
                printf("%dx",a[j]);
            if(a[0]>0){
                if(n==0)
                    printf("+%d",a[0]);
                else
                    printf("%d",a[0]);
            }
            else if(a[0]<0)
                printf("%d",a[0]);
            printf("\n");
        }
    }
    return 0;
}
