#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void reverse(char s[],char t[])
{
    int len=strlen(s);
    for(int i=0;i<len;i++){
        t[i]=s[len-1-i];
    }
}
int main()
{
    int m;
    scanf("%d",&m);
    getchar();
    for(int i=0;i<m;i++){
        printf("case #%d:\n",i);
        char s1[81],s2[81];
        char s[81],t[81],t1[81],t2[81];
        for(int k=0;k<81;k++){
            s1[k]=0;
            s2[k]=0;
            s[k]=0;
            t[k]=0;
            t1[k]=0;
            t2[k]=0;
        }
        gets(s1);
        gets(s2);
        gets(s);
        int lens=strlen(s);
        int lens1=strlen(s1);
        int lens2=strlen(s2);
        //char* c=strstr(s,s1);
        //printf("%s",c);
        if(strcmp(s,s1)==0&&strcmp(s,s2)==0){
            printf("0\n");
        }
        else{
        int p1=strstr(s,s1)-s;
        //printf("%d",IsSubString(s,s1));
        int p2=strstr(s,s2)-s;
        //printf("%d",IsSubString(s,s2));
        reverse(s,t);
        reverse(s1,t1);
        reverse(s2,t2);
        int p3=-(strstr(t,t1)-t)+lens-lens1;
        int p4=-(strstr(t,t2)-t)+lens-lens2;

        if(strstr(s,s1)==NULL||strstr(s,s2)==NULL){
            printf("0\n");
            continue;
        }
        int zhong2,zhong1;
        if(p2<p3){
            zhong2=lens2;
        }
        else{
            zhong2=lens1;
        }
        if(p1<p4){
            zhong1=lens2;
        }
        else{
            zhong1=lens1;
        }
        int x1=abs(p1-p4)-zhong1;
        //printf("%d",x1);
        int x2=abs(p2-p3)-zhong2;
        if(x1>x2){
            printf("%d\n",x1);
        }
        else{
            printf("%d\n",x2);
        }
        }
    }
}
