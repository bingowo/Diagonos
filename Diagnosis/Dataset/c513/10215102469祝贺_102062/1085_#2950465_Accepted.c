#include<stdio.h>
#include<string.h>
typedef struct{
    int num[505];
    int p;
}bint;
void sub(bint* ret,bint* n1,bint* n2){
    ret->p=n1->p>n2->p?n1->p:n2->p;
    for(int i=0;i<ret->p;i++){
        ret->num[i]=n1->num[i]-n2->num[i];
    }
    for(int i=0;i<ret->p;i++){
        if(ret->num[i]<0){
            ret->num[i+1]--;
            ret->num[i]+=10;
        }
    }
    while(ret->num[ret->p-1]==0 && ret->p>1)ret->p--;
}
int main(){
    char s1[505],s2[505];
    while(scanf("%s%s",s1,s2)!=EOF){
        int sign=1;
        bint n1={{0},0},n2={{0},0},ret={{0},0};
        for(int i=strlen(s1)-1;i>=0;i--){
            n1.num[n1.p++]=s1[i]-'0';
        }
        for(int i=strlen(s2)-1;i>=0;i--){
            n2.num[n2.p++]=s2[i]-'0';
        }
        if(strcmp(s1,s2)>=0)sub(&ret,&n1,&n2);
        else{sign=-1;sub(&ret,&n2,&n1);}
        if(sign==-1)printf("-");
        for(int i=ret.p-1;i>=0;i--)printf("%d",ret.num[i]);
        printf("\n");
    }
    return 0;
}
