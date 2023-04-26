#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int i,j,len,c;
    char s[500];
    memset(s,0,sizeof(s));
    scanf("%s",&s);

    len=strlen(s); //位数
    c=len;
    int len2[10];
    for(i=0;i<10;i++){      //位数转成十位的二进制 个位在前
        len2[i]=len%2;
        len=len/2;
    }
    printf("0001");

    for(i=9;i>=0;i--){
        printf("%d",len2[i]);
    }
    int yu,zu;
    yu=c%3;
    zu=c/3;
    j=0;
    int total,n;
    for(n=0;n<zu;n++){
        total=0;
        total=(s[j]-'0')*100+(s[j+1]-'0')*10+(s[j+2]-'0');    //一组的三位数
        j+=3;
        int two[10];
        for(i=0;i<10;i++){             //转成十位二进制
          two[i]=total%2;
            total=total/2;}
          for(i=9;i>=0;i--){
        printf("%d",two[i]);}
        }
    if(yu==2){
        total=0;
        total=(s[j]-'0')*10+(s[j+1]-'0');
        int two2[7];
                for(i=0;i<7;i++){             //转成7位二进制
          two2[i]=total%2;
            total=total/2;}
          for(i=6;i>=0;i--){
        printf("%d",two2[i]);}
        }

        if(yu==1){
        total=0;
        total=s[j]-'0' ;
        int two3[4];
                for(i=0;i<4;i++){             //转成4位二进制
          two3[i]=total%2;
            total=total/2;}
          for(i=3;i>=0;i--){
        printf("%d",two3[i]);}
        }

    }