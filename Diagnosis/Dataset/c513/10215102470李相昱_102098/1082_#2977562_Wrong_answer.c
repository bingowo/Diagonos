#include <stdio.h>
#include <string.h>
int main() {
    char s1[501];
    char s2[501];
    int ret[1001]={0};
    int N;
    scanf("%s%s%d",s1,s2,&N);
    char *p1,*p2;
    p1= strchr(s1,'.');
    if(p1!=NULL){
        int pos=p1-&s1[0];
        for(int i=pos-1,j=500;i>=0;i--,j--){
            ret[j]=s1[i]-'0';
        }
        for(int p=pos+1,q=501;p< strlen(s1);p++,q++){
            ret[q]=s1[p]-'0';
        }
    } else{
        for(int i= strlen(s1)-1,j=500;i>=0;i--,j--){
            ret[j]=s1[i]-'0';
        }
    }
    p2= strchr(s2,'.');
    int carry=0;
    int j=500;
    if(p2!=NULL){
        int pos=p2-&s2[0];
        for(int p= strlen(s2)-1,q=500+ strlen(s2)-pos-1;p>pos;p--,q--){
            ret[q]=ret[q]+s2[p]-'0'+carry;
            carry = ret[q]/10;
            ret[q]=ret[q]%10;
            if(q==500+N+1&&ret[q]>=5){
                carry++;
            }
        }
        for(int i=pos-1;i>=0;i--,j--){
            ret[j]=ret[j]+s2[i]-'0'+carry;
            carry = ret[j]/10;
            ret[j]=ret[j]%10;
        }
    } else{
        for(int i= strlen(s2)-1;i>=0;i--,j--){
            ret[j]=s2[i]-'0'+ret[j]+carry;
            carry = ret[j]/10;
            ret[j]=ret[j]%10;
        }

    }
    while(carry){
        ret[j]=ret[j]+carry;
        carry=ret[j]/10;
        ret[j]=ret[j]%10;
        j--;
    }
    int t=0;
    while (ret[t]==0&&t<=500){
        t++;
    }
    if(t==501){
        printf("0");
    }else{
        for(;t<=500;t++){
            printf("%d",ret[t]);
        }
    }
    printf(".");
    for(;t<=500+N;t++){
        printf("%d",ret[t]);
    }
    return 0;
}
