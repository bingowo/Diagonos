#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int carry=0;
int change(char *s1,char *s2){
    if(strlen(s1)<strlen(s2))return -1;
    else if(strlen(s1)>strlen(s2))return 1;
    else return strcmp(s1,s2);
}
void sub(int *a,int *b,int *c,int *carry){
    if(*a+*carry-*b<0){
        *c=10+*a-*b+*carry;
        *carry=-1;
        return;
    }
    else {*c=*a+*carry-*b;*carry=0;}
    return;
}
int main(){
    int a[501]={0},b[501]={0},c[501]={0},item1,item2;
    char s1[501]={0},s2[501]={0};
    while(scanf("%s%s",s1,s2)==2){
        carry=0;
        int len1,len2,flag;
        len1=strlen(s1);
        len2=strlen(s2);
        flag=change(s1,s2);
        if(flag>0){
            for(item1=0;item1<len1;item1++)a[len1-1-item1]=(int)(s1[item1]-'0');
            for(item2=0;item2<len2;item2++)b[len2-1-item2]=(int)(s2[item2]-'0');

        }
        else if(flag<0){
            for(item2=0;item2<len1;item2++)b[len1-1-item2]=(int)(s1[item2]-'0');
            for(item1=0;item1<len2;item1++)a[len2-1-item1]=(int)(s2[item1]-'0');
        }
        else {printf("0\n");continue;}
        a[len1]=10;
        b[len2]=10;
        //for(int i=item1-1;i>=0;i--)printf("%d",a[i]);
        //for(int i=item2-1;i>=0;i--)printf("%d",b[i]);
        int *a1=a,*b1=b,*c1=c,*carry1=&carry;
        do{

            sub(a1,b1,c1,carry1);
            a1++,b1++,c1++;
        }while(*b1!=10);
        while(*a1!=10){
            if(*a1+*carry1<0){*c1=*a1+*carry1+10;*carry1=-1;}
            else {*c1=*a1+*carry1;*carry1=0;}
            a1++;
            c1++;
        }
        int i=500;
        while(c[i]==0)i--;
        if(flag<0)printf("-");
        for(;i>0;i--)printf("%d",c[i]);
        printf("%d\n",c[0]);
    }
    return 0;
}