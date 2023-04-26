#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(){
    char s[20];
    scanf("%s",s);
    int x=0;
    char s1[20]={'\0'};
    if(s[x]=='-'||s[x]=='+'){
        int y=0;
        while(x<strlen(s)){
            s1[y]=s[x];
            y++;
            x++;
        }
    }
    else{
        s1[0]='+';
        int y=1;
        while(x<strlen(s)){
            s1[y]=s[x];
            y++;
            x++;
        }
    }
    int a=0,b=0,c=0;
    for(int i=0;i<strlen(s1);i++){
        if(s1[i]=='+'||s1[i]=='-'){
            int flag=1;
            if(s1[i]=='+'){flag=1;}
            else if(s1[i]=='-'){flag=-1;}
            int sum=0;
            int j=i+1;
            while(isdigit(s1[j])){
                sum=sum*10+s1[j]-48;
                j++;
            }
            sum=sum*flag;
            if(sum==0&&s1[j-1]!='0')sum=flag;
            if(s1[j]=='x'){
                if(s1[j+2]=='2'&&s1[j+1]=='^'){
                    a=sum;
                }
                else{
                    b=sum;
                }
            }
            else{
                c=sum;
            }
        }
    }
    //printf("%d %d %d\n",a,b,c);
    int a1,c1,a2,c2;
    if(c!=0){
    int flag=0; 
    int p1[200][2];
    int len1=0;
    for(int i=1;i<=(a/2)+1;i++){
        if(a%i==0){
            p1[len1][0]=i;
            p1[len1][1]=a/i;
            len1++;
        }
    }
    int len=len1;
    for(int i=0;i<len;i++){
        p1[i+len1][0]=p1[i][1];
        p1[i+len1][1]=p1[i][0];
        len1++;
    }
    int p2[200][2];
    int len2=0;
    if(c>0){
    for(int i=1;i<=(c/2)+1;i++){
        if(c%i==0){
            p2[len2][0]=i;
            p2[len2][1]=c/i;
            len2++;
        }
    }
    int len=len2;
    for(int i=0;i<len;i++){
        p2[len2+i][0]=-p2[i][1];
        p2[len2+i][1]=-p2[i][0];
        len2++;
    }
    }
    if(c<0){
    c=-c;
    for(int i=1;i<=(c/2)+1;i++){
        if(c%i==0){
            p2[len2][0]=-i;
            p2[len2][1]=c/i;
            len2++;
        }
    }
    int len=len2;
    for(int i=0;i<len;i++){
        p2[len2+i][0]=-p2[i][1];
        p2[len2+i][1]=-p2[i][0];
        len2++;
    }
    }
    for(int i=0;i<len1;i++){
        for(int j=0;j<len2;j++){
            //printf("%d %d\n",i,j);
            //printf("%d %d %d %d \n",p1[i][0],p2[j][0],p1[i][1],p2[j][1]);
            if((p1[i][0]*p2[j][1]+p1[i][1]*p2[j][0])==b){
                a1=p1[i][0];
                c2=p2[j][1];
                a2=p1[i][1];
                c1=p2[j][0];
                flag=1;
                break;
            }
        }
    }
    
    if(flag)printf("%d %d %d %d ",a1,c1,a2,c2);
    else printf("No Answer!");
    }
    else{
        a1=1;
        a2=a;
        if(b>=0){
            c1=0;
            c2=b;
        }
        else{
            c1=b;
            c2=0;
        }
        printf("%d %d %d %d ",a1,c1,a2,c2);
    }

}
