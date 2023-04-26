#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void divide(char s0[1100],int d){
   for(int i=0;i<strlen(s0)-1;i++){
       s0[i+1]=s0[i+1]+((s0[i]-48)%2)*10;
       s0[i]=(s0[i]-48)/2+48;
       //printf("\n%d %d\n\n",s0[i],s0[i+1]);
   }
   s0[strlen(s0)-1]=(s0[strlen(s0)-1]-48)/2+48;
}

void tentotwo(char s0[1100],char s1[1100],int len){
    if((s0[strlen(s0)-1]-48)%2==1)s1[len]='1';
    else s1[len]='0';
    //printf("%s\n",s1);
    //printf("%s\n\n",s0);
    divide(s0,2);
    int flag=0;
    for(int i=0;i<strlen(s0);i++){
        if(s0[i]!='0'){
            flag=1;
            break;
        }
    }
    if(flag)tentotwo(s0,s1,len+1);
    else return;
}

void add(int p0[1100],int p1[1100]){
    for(int i=0;i<1100;i++){
        p0[i]=p0[i]+p1[i];
    }
    int fin=0;
    for(int i=0;i<1100;i++){
        if(p0[i]!=0){
            fin=i;
            break;
        }
    }
    for(int i=1099;i>=fin;i--){
        p0[i-1]=p0[i-1]+p0[i]/10;
        p0[i]=p0[i]%10;
    }
}

void multiply(int p1[1100],int d){
    for(int i=0;i<1100;i++){
        p1[i]=p1[i]+p1[i];
    }
    int fin=0;
    for(int i=0;i<1100;i++){
        if(p1[i]!=0){
            fin=i;
            break;
        }
    }
    for(int i=1099;i>=fin;i--){
        p1[i-1]=p1[i-1]+p1[i]/10;
        p1[i]=p1[i]%10;
    }
}

int main(){
    int T;
    scanf("%d",&T);
    for(int t=0;t<T;t++){
        char s0[1100]={0};
        scanf("%s",s0);
        char s1[1100]={'0'};
        //printf("\n%d\n",strlen(s0));
        tentotwo(s0,s1,0);
        int index=0;
        for(int i=0;i<strlen(s1);i++){
            if(s1[i]!='0'){
                    index=i;
                    break;
            }
        }
        int p0[1100]={0};
        int p1[1100]={0};
        p1[1099]=1;

        for(int i=strlen(s1)-1;i>=index;i--){
            //printf("%s",s1);
            if(s1[i]=='1'){
                add(p0,p1);
            }
            multiply(p1,2);
        }

        int beg=-1;
        for(int i=0;i<1100;i++){
            if(p0[i]!=0){
                beg=i;
                break;
            }
        }
        printf("case #%d:\n",t);
        if(beg==-1)printf("0");
        else{ 
            for(int i=beg;i<1100;i++){
                printf("%d",p0[i]);
            }
        }
        printf("\n");
    }
}
