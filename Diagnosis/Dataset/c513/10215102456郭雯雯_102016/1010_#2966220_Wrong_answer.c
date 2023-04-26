#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void trans(int a,int l){//将a转换为l位二进制数,并输出
    char s[15]="000000000000000";
    int m=l-1;
    while(a>0){
        s[m]=(a%2)+'0';
        a/=2;m--;
    }
    for(int i=0;i<l;i++)printf("%c",s[i]);
}
int main(){
    char que[500],ans[5600],s[4];
    scanf("%s",que);
    printf("0001");
    int l=strlen(que),i,a=0;
    trans(l,10);
    for(i=0;i<l-2;i+=3){
        s[4]="0000";
        strncpy(s,que+i,3);
        a=atoi(s);
        printf(" %d ",a);
        trans(a,10);
    }
    if(l%3==1){
        s[4]="0000";
        strncpy(s,que+i,1);
        a=atoi(s);printf(" %d ",a);
        trans(a,4);
    }
    if(l%3==2){
        s[4]="0000";
        strncpy(s,que+i,2);
        a=atoi(s);printf(" %d ",a);
        trans(a,7);
    }
}