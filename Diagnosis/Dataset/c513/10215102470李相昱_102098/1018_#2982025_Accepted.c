#include <stdio.h>
#include <string.h>
int main() {
    int a[26]={1,2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,
               53,59,61,67,71,73,79,83,89,97};
    char s[100];
    scanf("%s",s);
    int len = strlen(s);
    int s2[25]={0};
    int j=0;
    for(int i=0;i<len;i++){
        if(s[i]==','){
            j++;
        }else{
            s2[j]= s2[j]*10+s[i]-'0';
        }
    }
    int num=0;
    int ret[37];
    memset(ret,0,sizeof(ret));
    ret[0]=s2[0];
    for(int m=1;m<=j;m++){
        int p=0;
        for(;p<=num;p++){
            ret[p]=ret[p]*a[j-m+1];
            if(p==0){
                ret[p]=ret[p]+s2[m];
            }
        }
        int carry=0;
        int t=0;
        for(;t<=num||carry!=0;t++){
            ret[t]=ret[t]+carry;
            carry=ret[t]/10;
            ret[t]=ret[t]%10;
        }
        num=t-1;
    }
    for(int q=num;q>=0;q--){
        printf("%d",ret[q]);
    }
    return 0;
}
