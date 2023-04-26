#include<stdio.h>
#include<string.h>

int main()
{
    int n,N=100;
    int i,j,x,y,result,r=1,z,c=1;
    int s;
    int a[N];
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",s);
        for(j=0;s!=0;j++){
            a[j]=s%2;
            s=s/2;
        }
        for(x=1;a[x]!=EOF;x++){
            if(a[x]!=a[x-1]){r++;}
            if(a[x]==a[x-1]){if(r>=c){c=r;}r=1;

        }


        }
















        printf("case #%d:\n",i);
        printf("%d\n",c);
    }






   return 0;
}
