#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,j;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("case #%d:\n",i);
        int t,weishu=0;;
        scanf("%d",&t);
        int t1=t;
        while(t){
           weishu++;
           t/=10;
        }
        int a[weishu],min=10;
        for(j=weishu-1;j>=0;j--){
            a[j]=t1%10;
            t1/=10;
            if(a[j]<=min){
                min=a[j];
            }
        }
        int x;
        j=weishu-1;

        for(j=weishu-1;j>=0;j--){
            if(a[j]!=min){
            if(a[j]>a[j-1]){
                x=a[j-1];
                a[j-1]=a[j];
                a[j]=x;
               // break;
            }
            else {
            x=a[j];
            int y=j-1;
            while(x<=a[y]){
                a[y+1]=a[y];
                y--;
            }
            a[y+1]=a[y];
            a[y]=x;

        }

        for(j=0;j<weishu;j++){
            printf("%d",a[j]);
        }
        printf("\n");
        break;
    }
    else{
        if(min==0){
            for(j=0;j<weishu;j++){
            printf("%d",a[j]);
        }
        printf("0\n");
        break;
        }
        else{
            continue;
        }
        /*for(j=0;j<weishu;j++){
            printf("%d",a[j]);
        }
        printf("0\n");*/
        }
    }


    }
return 0;
    }
