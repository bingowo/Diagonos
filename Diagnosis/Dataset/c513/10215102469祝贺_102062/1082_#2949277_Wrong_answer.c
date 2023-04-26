#include <stdio.h>
#include <stdlib.h>
#include<string.h>
typedef struct{
    int num[505];
    int sp;
}bint;
void add(bint*ret,const bint* anum){
    int carry=0,i=0;
    for(;i<anum->sp || carry!=0;i++){
        int tmp=ret->num[i]+anum->num[i]+carry;
        ret->num[i]=tmp%10;
        carry=tmp/10;
    }
    ret->sp=i<ret->sp?ret->sp:i;
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
    char s1[502],s2[502];int n;scanf("%s%s%d",s1,s2,&n);
    bint n1={{0},2,0},n2={{0},2,0};
    int p1=strchr(s1,'.')==NULL?0:strlen(s1)-(strchr(s1,'.')-s1)-1;
    int p2=strchr(s2,'.')==NULL?0:strlen(s2)-(strchr(s2,'.')-s2)-1;
    int len=p1<p2?p2:p1;
    int dot=len;
    int t=0;
    for(;t<len-p1;t++)n1.num[t]=0;
    for(int i=0;strlen(s1)>=i+1;t++,i++){
        if(s1[strlen(s1)-1-i]=='.'){t--;}
        else n1.num[t]=s1[strlen(s1)-1-i]-'0';
    }
    n1.sp=t;
    while(t<len)n1.num[t]=0;
    for(t=0;t<len-p2;t++)n2.num[t]=0;
    for(int i=0;strlen(s2)>=i+1;t++,i++){
        if(s2[strlen(s2)-1-i]=='.'){t--;}
        else n2.num[t]=s2[strlen(s2)-1-i]-'0';
    }
    n2.sp=t;
    add(&n1,&n2);
    if(n1.sp<=dot+1)n1.sp=dot+1;
    if(dot-n>0){
        if(dot-n-1!=0 && n1.num[dot-n-1]>=5){
            n1.num[dot-n]++;
            bint zero={{0},1};
            add(&zero,&n1);
            n1=zero;
        }
        if(dot-n-1>=0)n1.num[dot-n-1]=-1;
        for(int i=n1.sp-1;i>=dot;i--){
            printf("%d",n1.num[i]);
        }
        printf("%c",'.');
        for(int i=dot-1;i>=0 && n1.num[i]>=0;i--){
            printf("%d",n1.num[i]);
        }
    }
    else{
        for(int i=n1.sp-1;i>=dot;i--){
            printf("%d",n1.num[i]);
        }
        printf("%c",'.');
        for(int i=dot-1;i>=0;i--){
            printf("%d",n1.num[i]);
        }
        for(int i=0;i<n-dot;i++)printf("%d",0);
    }
    return 0;
}
