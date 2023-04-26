#include<stdio.h>
#include<string.h>
#include<ctype.h>
typedef struct{
    int num[500];
    int p;
    int mod;
}bint;
bint init(char* s){
    bint ret={{0},0,0};
    for(int i=strlen(s)-1;i>=0;i--){
        ret.num[ret.p++]=s[i]-'0';
        ret.mod+=s[i]-'0';
    }
    return ret;
}
tadd(bint* a){
    a->num[0]++;
     int carry=0,i=0;
    for(;carry!=0 || i<a->p;i++){
        int tmp=a->num[i]+carry;
        a->num[i]=tmp%10;
        carry=tmp/10;
    }
    a->p=i;
    a->mod++;
}
int main(){
    char s[102];scanf("%s",s);
    bint ans=init(s);
    do{
        tadd(&ans);
        int tag=0,i=0;
        for(;i<ans.p || tag!=0;i++){
            if(ans.num[i]==9){
                ans.num[i]=0;
                ans.mod-=9;
                tag=1;
            }
            else if(ans.num[i]!=9 && tag!=0){
                if(ans.num[i]==8){
                    ans.num[i]=0;
                    ans.mod-=8;
                }
                else{
                    ans.num[i]++;
                    ans.mod++;
                    tag=0;
                }
            }
        }
        ans.p=i;
    }while(ans.mod%9==0);
    for(int i=ans.p-1;i>=0;i--)printf("%d",ans.num[i]);
    return 0;
}
