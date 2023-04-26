#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int num;
    int v[1006];
}BIGINT;

void add1(BIGINT *a){
    int i=1;
    a->v[0]=a->v[0]+1;
    int carry=a->v[0]/10;
    a->v[0]=a->v[0]%10;
    while(carry!=0&&i<a->num){
        a->v[i]+=carry;
        carry=a->v[i]/10;
        a->v[i]=a->v[i]%10;
        i++;
    }
    if(carry!=0){
        a->v[i]=carry;
        a->num++;
    }
}

void div2(BIGINT *a){
    int carry=0;
    if(a->v[a->num-1]<2)
        a->num--,carry=1;
    for(int i=a->num-1;i>=0;i--){
        int t=carry*10+a->v[i];
        a->v[i]=t/2;
        carry=t%2;
    }
}

void trans(char s[],BIGINT *a){
    int len=strlen(s);
    int j=0;
    if(s[0]=='-') len--,j++;
    a->num=len;
    for(int i=len-1;i>=0;i--,j++){
        a->v[i]=s[j]-'0';
    }
}

int main(){
    int sign=1;
    char s[106];
    int i=0;
    int ans[500]={0};
    BIGINT a={0,{0}};
    scanf("%s",&s);
    if(s[0]=='-') sign=-1;
    trans(s,&a);
    while(a.num>0){
        int temp=a.v[0]%2;
        ans[i++]=temp;
        div2(&a);
        if(sign==-1&&temp) {
            if(a.num==0){
                a.num++;
                a.v[0]=1;
            }
            else add1(&a);
        }
        sign*=-1;
    }
    i--;
    for(;i>=0;i--){
        printf("%d",ans[i]);
    }
    printf("\n");
    return 0;
}