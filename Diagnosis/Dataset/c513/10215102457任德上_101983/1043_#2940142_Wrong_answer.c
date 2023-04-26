#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
int cal(char *s,char *com){
    char *c=s+1,s1;
    int now=1,len,sum=0;
    s1=*s;
    while(*c){
        if(*c!=s1)s1=*c;
        else{
            len=2;
            while(*(c+len-1)==s1)len++;
            if(c-1==s){sum=strlen(s);break;}
            *(c-1)=0;
            strcat(s,com+now+len-2);
            sum+=len;

        }
        now++;
        c++;

    }
    return sum;
}
int main(){
    int t;
    scanf("%d\n",&t);
    for(int i=0;i<t;i++){
        char s1[101]={0},c,s3[2]={0};
        scanf("%s",s1);
        int k=0,max=0,sum=0;
        char s4[101]={0};
        for(int m=1;m<strlen(s1)-1;m++){   //从第2个字符到倒数第二个字符插入相同，计算消去字符的个数，再取最大值。
            strcpy(s4,s1);
            s3[0]=s4[m];
            s4[m]=0;
            strcat(s4,s3);
            s4[m]=s3[0];
            strcat(s4,s1+m);
            sum=cal(s4,s1);
            strcpy(s4,s1);
            max=max>sum?max:sum;
        }
        printf("case #%d:\n%d\n",i,max);
    }
    return 0;
}