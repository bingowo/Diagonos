#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
char s2[100];
int cal(char *s1,int k){
    if(k==-1&&*s1!=0){
        k=0;
        s2[k]=*s1;
        return cal(s1+1,k);
    }
    if(k==-1&&*s1==0)return 0;
    if(*s1==s2[k]){
        int i=1;
        s1++;
        while(*s1==s2[k]){i++;s1++;}
        s2[k--]=0;
        return 2*i+cal(s1,k);
    }
    else if(*s1!=0&&*s1!=s2[k]){
        s2[++k]=*s1;
        return cal(s1+1,k);
    }
    else return 0;
}
int main(){
    int t;
    scanf("%d\n",&t);
    for(int i=0;i<t;i++){
        char s1[101]={0},c,s3[2]={0};
        scanf("%s",s1);
        int k=0,max=0,sum=0;
        s2[0]=s1[0];
        if(strlen(s1)!=0){
            char s4[100]={0};
            for(int m=1;m<strlen(s1)-1;m++){
                strcpy(s4,s1);
                s3[0]=s4[m];
                s4[m]=0;
                strcat(s4,s3);
                s4[m]=s3[0];
                strcat(s4,s1+m);
                sum=cal(s4+1,0);
                strcpy(s4,s1);
                max=max>sum?max:sum;
            }
        }
        else max++;
        printf("case #%d:\n%d\n",i,max);
    }
    return 0;
}