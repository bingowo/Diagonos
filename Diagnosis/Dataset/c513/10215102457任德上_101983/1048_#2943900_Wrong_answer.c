#include<stdio.h>
#include<ctype.h>
void find(char *s,int *co){
    while(*s){
        int sign=1,coef=0,dim=0;
        if(*s=='+')s++;
        else if(*s=='-'){sign=-1;s++;}
        while(isdigit(*s)){coef=coef*10+*s-'0';s++;}
        if(coef==0)coef=1;
        if(*s!='x')co[0]=coef*sign;
        else s++;
        if(*s=='^')s++;
        while(isdigit(*s)){dim=dim*10+*s-'0';s++;}
        if(dim==0)dim=1;
        co[dim]=coef*sign;
        s++;
    }
}
int main(){
    char s1[100],s2[100];
    while(scanf("%s%s",s1,s2)==2){
    int n1[50]={0},n2[50]={0},result[100]={0};
    find(s1,n1);
    find(s2,n2);
    for(int i=0;i<50;i++){
        for(int k=0;k<50;k++){
            result[i+k]=n1[i]*n2[k];
        }
    }
    int flag=0;
    for (int i=99;i>=0;i--){
        if (result[i]){
            flag?printf(" %d",result[i]):printf("%d",result[i]);
            flag=1;
        }
    }
    printf("\n");
    }
    return 0;
}