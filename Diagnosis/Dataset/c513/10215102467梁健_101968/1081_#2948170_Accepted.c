#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>

int main()
{
    int T;scanf("%d",&T);
    for(int i=0;i<T;i++){
        printf("case #%d:\n",i);
        int a,n;scanf("%d %d",&a,&n);
        int s[101];s[0]=a;
        int len=0;
        for(int r=1;r<101;r++)s[r]=0;
        if(n==0)printf("1\n");
        else{
            for(int step=1;step<n;step++){
                for(int r=0;r<101;r++){
                    s[r]*=a;
                }
                for(int r=0;r<101;r++){
                    if(s[r]>9){
                        s[r+1]=s[r+1]+s[r]/10;
                        s[r]=s[r]%10;
                        if((r+1)>len)len=r+1;
                    }
                }
            }
            for(int r=len;r>=0;r--)printf("%d",s[r]);
            printf("\n");
        }
    }
    return 0;
}
