#include <stdio.h>
#include <stdlib.h>
typedef struct{
    int num[125];
    int sp;
}bint;
void add(bint*ret,const bint* anum){
    int carry=0,i=0;
    for(;i<anum->sp || carry!=0;i++){
        int tmp=ret->num[i]+anum->num[i]+carry;
        ret->num[i]=tmp%10;
        carry=tmp/10;
    }
    ret->sp=i;
}
void mul(bint*ans,bint*anum){
    bint ret={{0},124};
    for(int i=0;i<anum->sp;i++){
        for(int j=0;j<ans->sp;j++){
            ret.num[i+j]+=(anum->num[i])*(ans->num[j]);
        }
    }
    while(ret.num[ret.sp-1]==0)ret.sp--;
    int carry=0,i=0;
    do{
        int tmp=ret.num[i]+carry;
        ret.num[i]=tmp%10;
        carry=tmp/10;
        i++;
    }while(carry!=0 || i<ret.sp);
    ret.sp=i;
    *ans=ret;
}
void selfmul(bint* anum){
    bint ret={{0},124};
    for(int i=0;i<anum->sp;i++){
        for(int j=0;j<anum->sp;j++){
            ret.num[i+j]+=(anum->num[i])*(anum->num[j]);
        }
    }
    while(ret.num[ret.sp-1]==0)ret.sp--;
    int carry=0,i=0;
    do{
        int tmp=ret.num[i]+carry;
        ret.num[i]=tmp%10;
        carry=tmp/10;
        i++;
    }while(carry!=0 || i<ret.sp);
    ret.sp=i;
    *anum=ret;
}
int main()
{
    int pro;scanf("%d",&pro);
    for(int index=0;index<pro;index++){
        int a,n;scanf("%d%d",&a,&n);
        bint anum={{0},0},ans={{1},1};
        do{
            anum.num[anum.sp++]=a%10;
            a/=10;
        }while(a!=0);
        if(n==0){
            ans.num[0]=1;ans.sp=1;
        }
        while(n!=0){
            if(n%2==1){
                mul(&ans,&anum);
            }
            if(n>1){
                selfmul(&anum);
            }
            n/=2;
        }
        printf("case #%d:\n",pro);
        for(int i=ans.sp-1;i>=0;i--){
            printf("%d",ans.num[i]);
        }
        printf("\n");
    }
    return 0;
}
