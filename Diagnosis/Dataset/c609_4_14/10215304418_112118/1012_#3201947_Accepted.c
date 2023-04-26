#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

char st[100100];
int a[12345];
int b[12345];
int ans[12345];

int main(){
    int t;
    scanf("%d",&t);
    for (int l=1;l<=t;l++){
        scanf("%s",st);
        for (int i=strlen(st)-1;i>=2;i--){
            a[strlen(st)-i]=st[i]-'0';
        }
        for (int j=1;j<=200;j++)
            ans[j]=0;
        for (int k=1;k<strlen(st)-1;k++){
            for (int j=1;j<=200;j++)
                b[j]=0;
            for (int j=1;j<=200;j++){
                int t=ans[j]*125;
                b[j+1]+=t/100;
                b[j+2]+=(t%100)/10;
                b[j+3]+=t%10;
            }
            int t=a[k]*125;
            b[1]+=t/100;
            b[2]+=(t%100)/10;
            b[3]+=t%10;
            for (int j=200;j>=1;j--){
                b[j]+=b[j+1]/10;
                b[j+1]=b[j+1]%10;
            }
            for (int j=1;j<=200;j++){
                ans[j]=b[j];
            }
        }
        int i=200;
        while (ans[i]==0) i--;
        printf("case #%d:\n",l-1);
        printf("0.");
        for (int j=1;j<=i;j++){
            printf("%d",ans[j]);
        }
        printf("\n");
    }
    return 0;
}
