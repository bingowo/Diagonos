#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char a[3];
    int cnt;
}STRUCT;

int main()
{
    char s[1000];
    scanf("%s",s);
    int len,i;
    len=strlen(s);
    STRUCT n[len];
    for(i=0;i<len;i++){
        n[i].a[0]=s[i];
        n[i].cnt=1;
    }
    for(i=1;i<len;i++){
        if(s[i]!=n[i-1].a[0]){ n[i-1].a[1]=s[i]; n[i-1].cnt++;}
    }

   for(i=0;i<len-1;i++){
        if((s[i]!=n[i+1].a[0])&&(s[i]!=n[i+1].a[1])){ n[i+1].a[2]=s[i]; n[i+1].cnt++;}
    }

    //接下来需要做大整数计算
    /*int result=1;
    for(j=0;j<len;j++){
        result=result*(n[j].cnt);
    }
    printf("%d",result);*/

    int bigint[1000];
    memset(bigint,0,sizeof(bigint));
    bigint[0]=1;
    int j=0,c,t=0;
    for(i=0;i<len;i++){
for(j=0;j<1000;j++){
    c=bigint[j]*n[i].cnt+t;
    bigint[j]=c%10;
    t=c/10;
}
    }
    for(i=999;i>=0;i--){
        if(bigint[i]!=0){break;}
    }
    for(j=i+1;j>=0;j--){
        printf("%d",bigint[j]);
    }



}
