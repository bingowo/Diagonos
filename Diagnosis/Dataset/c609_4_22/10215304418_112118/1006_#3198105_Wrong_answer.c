#include <stdio.h>
#include <stdlib.h>

int mapp[10010];
int ans[10010];
int o[10010];

int main()
{
    int t;
    scanf("%d",&t);
    for (int l=1;l<=t;l++){
        char a[100010];
        scanf("%s",a);
        for (int i=0;i<strlen(a);i++){
            if (a[i]>='0' && a[i]<='9') o[i]=a[i]-'0';
            else if (a[i]>='a' && a[i]<='z') o[i]=a[i]-'a'+10;
            else if (a[i]>='A' && a[i]<='Z') o[i]=a[i]-'A'+50;
        }
        for (int i=0;i<=100;i++)
            mapp[i]=-1;
        int k=0;
        long long answ=0;
        int p=0;
        for (int i=0;i<strlen(a);i++){
            if (mapp[o[i]]!=-1) {
                ans[i]=mapp[o[i]];
            }
            else {
                if (i==0){
                    mapp[o[i]]=1;
                    ans[i]=1;
                    p++;
                }
                else{
                    mapp[o[i]]=k;
                    ans[i]=k;
                    if (k==0) k+=2;
                    else k++;
                    p++;
                }
            }
        }
        if (p==1) p=2;
        for (int i=0;i<strlen(a);i++){
            answ*=p;
            answ+=ans[i];
        }
        printf("case #%d:\n%d\n",l-1,answ);
    }
    return 0;
}
