#include <stdio.h>
#include <string.h>
int a[1001]={0};
int b[1001]={0};
void Input(int a[]){
    char s[501];
    scanf("%s",s);
    char *p;
    p= strchr(s,'.');
    int pos=p-&s[0];
    if(p!=NULL){
        for(int p= pos+1,q=501;p< strlen(s)-1;p++,q++){
            a[q]=s[p]-'0';
        }
    } 
    for(int i=pos-1,j=500;i>=0;i--,j--){
        a[j]=s[i]-'0';
    }
}
int main() {
    int ret[1001]={0};
    int N;
    Input(a);
    Input(b);
    scanf("%d",&N);
    int carry=0,i=1000;
    for(;i>N;i--){
        ret[i]=a[i]+b[i]+carry;
        carry=ret[i]/10;
        ret[i]=ret[i]%10;
    }
    if(ret[N+1]>=5){
        carry++;
    }
    for(;i>=0;i--){
        ret[i]=a[i]+b[i]+carry;
        carry=ret[i]/10;
        ret[i]=ret[i]%10;
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
