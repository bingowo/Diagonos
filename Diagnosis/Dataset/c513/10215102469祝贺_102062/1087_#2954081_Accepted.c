#include<stdio.h>
#include<string.h>
typedef struct{
    int num[120];
    int p;
}bint;
bint init(char* s){
    bint ret={{0},0};
    for(int i=strlen(s)-1;i>=0;i--){
        ret.num[ret.p++]=s[i]-'0';
    }
    return ret;
}
void renew(bint* n,int i){
    int carry=0;
    while(carry!=0 || i<n->p){
        int tmp=n->num[i]+carry;
        n->num[i]=tmp%10;
        carry=tmp/10;
        i++;
    }
    n->p=i;
}
int solve(bint* n){
    int rp=n->p-1;int tag=0;
    while(rp>0){
        if(n->num[rp]==n->num[rp-1]){
            tag=1;
            n->num[rp-1]++;
            for(int i=rp-2;i>=0;i--){n->num[i]=0;}
            renew(n,rp-1);
            rp=n->p-1;
        }
        else rp--;
    }
    return tag;
}
int main(){
    int pro;scanf("%d",&pro);
    for(int index=0;index<pro;index++){
        char s[120];scanf("%s",s);
        bint n=init(s);
        if(n.p==1){
            int tmp=n.num[0]+1;
            n.num[0]=tmp%10;
            n.num[1]=tmp/10;
            if(n.num[1]!=0)n.p++;
        }
        else{
           int tag=solve(&n);
           if(tag==0){
                n.num[0]++;
                renew(&n,0);
                solve(&n);
           }
        }
        printf("case #%d:\n",index);
        for(int i=n.p-1;i>=0;i--)printf("%d",n.num[i]);
        printf("\n");
    }
    return 0;
}
