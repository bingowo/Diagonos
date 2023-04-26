#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 150

int main(){
    char s1[N],s2[N],t[N];
    int l1,l2,l=0,i;
    int ans[N];
    while(scanf("%s%s",s1,s2)!=EOF){
        l1=strlen(s1);l2=strlen(s2);
        if(l1<l2) {
            strcpy(t,s1);
            strcpy(s1,s2);
            strcpy(s2,t);
        }
        if(l1==l2){
            for(i=0;i<l1;i++){
                if(s1[i]<s2[i]){
                    strcpy(t,s1);
                    strcpy(s1,s2);
                    strcpy(s2,t);
                    break;
                }
            }
        }
        l1--;l2--;
        while(l2>=0){
            ans[l++]=s1[l1--]-s2[l2--];
        }
        while(l1>=0)
            ans[l++]=s1[l1--];
        for(i=0;i<l;i++){
            if(ans[i]<0){
                ans[i]+=10;
                ans[i+1]-=1;
            }
        }
        for(i=l-1;i>=0;i--)
            printf("%d",ans[i]);
        printf("\n");
    }
    return 0;
}