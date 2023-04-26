#include<stdio.h>
#include<string.h>
typedef struct{
    int num[130];
    int p;
    int sign;
}bint;
int cmp(bint* n1,bint* n2){
    if(n1->sign!=n2->sign)return n1->sign-n2->sign;
    if(n1->p!=n2->p){
        return n1->sign*(n1->p-n2->p);
    }
    else{
        for(int i=n1->p-1;i>=0;i--){
            if(n1->num[i]!=n2->num[i])return n1->sign*(n1->num[i]-n2->num[i]);
        }
        return 0;
    }
}
void sub(bint* ret,bint* n1,bint* n2){
    ret->p=n1->p>n2->p?n1->p:n2->p;
    for(int i=0;i<ret->p;i++){
        ret->num[i]=n1->num[i]*n1->sign-n2->num[i]*n2->sign;
    }
    for(int i=0;i<ret->p || ret->num[i]<0 || ret->num[i]>9;i++){
        while(ret->num[i]<0 || ret->num[i]>9){
            if(ret->num[i]<0){
                ret->num[i+1]--;
                ret->num[i]+=10;
            }
            else{
                ret->num[i+1]+=ret->num[i]/10;
                ret->num[i]%=10;
            }
        }
    }
    ret->p=130;
    while(ret->num[ret->p-1]==0 && ret->p>1)ret->p--;
}
int main(){
    int n;scanf("%d",&n);
    bint max={{0},-1,-1},min={{0},150,1};
    for(int i=0;i<n;i++){
        char s[200];scanf("%s",s);
        int tag=s[0]=='-'?1:0;
        bint bnum={{0},0,1};
        for(int i=strlen(s)-1;i>=tag;i--)
            bnum.num[bnum.p++]=s[i]-'0';
        bnum.sign=(tag==0?1:-1);
        while(bnum.num[bnum.p-1]==0 && bnum.p>1)bnum.p--;
        if(cmp(&max,&bnum)<0)max=bnum;
        if(cmp(&min,&bnum)>0)min=bnum;
    }
    bint ret={{0},0,1};sub(&ret,&max,&min);
    for(int i=ret.p-1;i>=0;i--)printf("%d",ret.num[i]);
    return 0;
}
