#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>

int main()
{
    int T;scanf("%d",&T);
    for(int step=0;step<T;step++){
        printf("case #%d:\n",step);
            int n[26],t=0;
        for(int i=2;t<26;i++){
            int flag=0;
            for(int j=1;j<=sqrt(i);j++){
                if(i%j==0)flag++;
            }
            if(flag<2)n[t++]=i;
        }
        int a[30]={0},b[30]={0},c,a1=0,b1=0;
        do{
            scanf("%d",&a[a1++]);
        }while(c=getchar()==',');
        do{
            scanf("%d",&b[b1++]);
        }while(c=getchar()==',');
        int mp=a1>b1?a1:b1;
        int res[30]={0};
        for(int i=0;i<a1;i++){
            res[i]+=a[a1-1-i];
        }
        for(int i=0;i<b1;i++){
            res[i]+=b[b1-1-i];
        }
        for(int i=0;i<mp;i++){
            if(res[i]>=n[i]){
                res[i+1]+=(res[i]/n[i]);
                res[i]%=n[i];
            }
        }
        int sp=0;
        for(int i=28;i>=0;i--){
            if(res[i]!=0){
                sp=i;
                break;
            }
        }
        for(int i=sp;i>=0;i--){
            printf("%d",res[i]);
            if(i!=0)printf(",");
        }
        printf("\n");
    }
}

