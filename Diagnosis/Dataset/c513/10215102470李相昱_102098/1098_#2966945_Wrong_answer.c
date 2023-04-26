#include <stdio.h>
#include <string.h>
int main() {
    int T;
    scanf("%d",&T);
    char s[101];
    int s2[100] = {0};
    for(int i=0;i<T;i++){
        int cnt1=0,cnt2=0,cnt3=0,cnt4=0;
        scanf("%s",s);
        int len = strlen(s);
        for(int j=0;j<len;j++){
            if(s[j]=='R'){
                s2[j] = 1;
            }
            if(s[j]=='B'){
                s2[j] = 2;
            }
            if(s[j]=='Y'){
                s2[j] = 4;
            }
            if(s[j]=='G'){
                s2[j] = 8;
            }
        }
        for(int p=0;p<=len-4;p++){
            int sum=0,sign=-1;
            for(int t=0;t<4;t++){
                sum= sum+s2[p+t];
                if(!s2[p+t]){
                    sign = p+t;
                }
            }
            if(sum==14){
                s2[sign] =1;
                cnt1++;
            }
            if (sum==13){
                s2[sign] =2;
                cnt2++;
            }
            if (sum==11){
                s2[sign] =3;
                cnt3++;
            }
            if (sum==7){
                s2[sign] =4;
                cnt4++;
            }
        }
        for(int p=len-1;p>=3;p--){
            int sum=0,sign=-1;
            for(int t=0;t<4;t++){
                sum= sum+s2[p-t];
                if(!s2[p-t]){
                    sign = p-t;
                }
            }
            if(sum==14){
                s2[sign] =1;
                cnt1++;
            }
            if (sum==13){
                s2[sign] =2;
                cnt2++;
            }
            if (sum==11){
                s2[sign] =3;
                cnt3++;
            }
            if (sum==7){
                s2[sign] =4;
                cnt4++;
            }
        }
        printf("case #%d:\n%d %d %d %d\n",i,cnt1,cnt2,cnt2,cnt4);
    }

    return 0;
}
