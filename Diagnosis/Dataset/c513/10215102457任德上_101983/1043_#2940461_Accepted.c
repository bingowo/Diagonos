#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
int flag=1;
int del(char *s,int len){
    flag=0;
    char *s1,s2[101]={0},*s3;
    s1=s;
    int sum=0;
    while(*(s1+1)){
        if(*s1==*(s1+1)){
            flag=1;
            while(*s1==*(s1+1)&&s1-s<len-1){*s1='0';s1++;sum++;}
            *s1='0';
            sum++;
        }
        s1++;

    }
    if(flag==0)return sum;
    s1=s2;
    s3=s;
    while(*s3){
        if(*s3!='0'){*s1=*s3;s1++;}
        s3++;
    }
    s3=s;
    while(*s3){*s3=0;s3++;}
    strcpy(s,s2);
    return sum;
}
int main(){
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        char s1[101]={0},s2[101]={0},s3[2];
        int sum=0,max=0,len;
        scanf("%s",s1);
        len=strlen(s1);
        for(int m=1;m<len-1;m++){   //从第2个字符到倒数第二个字符插入相同，计算消去字符的个数，再取最大值。
            flag=1;
            strcpy(s2,s1);
            s3[0]=s2[m];
            s2[m]=0;
            strcat(s2,s3);
            s2[m]=s3[0];
            strcat(s2,s1+m);
            s2[len+1]=0;
            while(flag==1){sum+=del(s2,strlen(s2));}
            max=max>sum?max:sum;
            sum=0;
        }
        printf("case #%d:\n%d\n",i,max);

    }


}