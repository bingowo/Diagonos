#include <stdio.h>
#include <string.h>
int main() {
    char s1[502],s2[502];
    while (scanf("%s%s",s1,s2)!=EOF){
        int a[500]={0},b[500]={0},sign=1;
        int len1= strlen(s1),len2= strlen(s2);
        for(int i=len1-1,j=0;i>=0;i--,j++){
            a[j] = s1[i]-'0';
        }
        for(int i=len2-1,j=0;i>=0;i--,j++){
            b[j] = s2[i]-'0';
        }
        if(len2>len1){
            sign=-1;
        }else if(len2==len1){
            int p=len1-1;
            while((s1[p]==s2[p])&&(p>=0)){
                p--;
            }
            if(s2[p]>s1[p]){
                sign=-1;
            }
            if(p==-1){
                sign=0;
            }
        }
        if(sign!=0){
            int ret[500]={0};
            int i=0;
            if(sign==1){
                for(;i<len2;i++){
                    if(a[i]<b[i]){
                        a[i]+=10;
                        a[i+1]--;
                    }
                    ret[i]=a[i]-b[i];
                }
                for(;i<len1;i++){
                    if(a[i]<0){
                        a[i]+=10;
                        a[i+1]--;
                    }
                    ret[i]=a[i];
                }
            }else{
                for(;i<len1;i++){
                    if(a[i]>b[i]){
                        b[i]+=10;
                        b[i+1]--;
                    }
                    ret[i]=b[i]-a[i];
                }
                for(;i<len2;i++){
                    if(b[i]<0){
                        b[i]+=10;
                        b[i+1]--;
                    }
                    ret[i]=b[i];
                }
            }
            if(sign==-1){
                printf("-");
            }
            i=i-1;
            while (ret[i]==0){
                i--;
            }
            for(;i>=0;i--){
                printf("%d",ret[i]);
            }
            printf("\n");
        }else{
            printf("0\n");
        }

    }
    return 0;
}
