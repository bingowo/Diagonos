#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
int ans[100];
int k;
char key[]="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

void stob(int n,int num)
{
    if(n!=0||num%4!=0){
        stob(n/2,num+1);
        ans[k++]=n%2;
    }
}

int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        printf("case #%d:\n",i);
        char s[100];
        k=0;
        memset(ans,0,sizeof(ans));
        scanf("%s",s);
        for(int j=0;s[j]!=0;j++){
            stob((int)s[j],0);
        }
        int cnt;
        cnt=k%6==0?k/6:k/6+1;
        for(int j=5;j<6*cnt;j+=6){
            int temp;
            temp=ans[j]+2*ans[j-1]+4*ans[j-2]+8*ans[j-3]+16*ans[j-4]+32*ans[j-5];
            printf("%c",key[temp]);
        }
        if(cnt%4==1)printf("===");
        else if(cnt%4==2)printf("==");
        else if(cnt%4==3)printf("=");
        printf("\n");
    }
    return 0;
}