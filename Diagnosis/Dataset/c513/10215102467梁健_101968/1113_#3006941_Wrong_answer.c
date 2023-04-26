#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
int k,n;
long double f[200];
int main()
{
    scanf("%d %d",&k,&n);
    f[1]=0;f[2]=1;
    for(int i=3;i<=n;i++)f[i]=0;
    for(int i=3;i<=n;i++){
        if(k>=i){
            for(int j=1;j<i;j++){
                f[i]+=f[j];
            }
        }
        else for(int j=i-k;j<i;j++){
            f[i]+=f[j];
        }
    }
    printf("%.0llf",f[n]);
    return 0;
}
