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
        int a,b,n;scanf("%d %d %d",&a,&b,&n);
        int c=a;
        long s[n+1]={0};
        for(int i=0;i<n;i++){
            s[i]=c%10;
            c/=10;
            //printf("%d\n",s[i]);
        }
        for(int i=1;i<b;i++){
            for(int j=0;j<n;j++)s[j]*=a;
            for(int j=0;j<n;j++){
                if(s[j]>9){
                    s[j+1]+=s[j]/10;
                    s[j]%=10;
                    //printf("%d\n",s[j]);
                }
            }
        }
        int res[n+1];
        for(int i=0;i<n;i++)res[i]=s[n-1-i];
        for(int i=0;i<n;i++)printf("%d",res[i]);
        printf("\n");
    }
    return 0;
}
