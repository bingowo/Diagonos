#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int MAX(int a,int b){
    if(a>=b) return a;
    else return b;
}

int del(char *ostr){
    char str[101],t[101];
    strcpy(str,ostr);
    int slen=strlen(str),lent=0,i,l=0;//slen为原始字符串的长度，lent为消除后剩余字符串的长度
    if(slen==0) return 0;
    str[slen]='$';
    str[slen+1]='\0';
    for(i=0;i<slen+1;i++){
        if(str[i]!=str[i-1]){ //相邻字符不相等,未被消除的字符保存在数组t中
        if(l==i-1) t[lent++]=str[i-1];
        l=i;
        }
    }
    t[lent]='\0';
    if(slen==lent) return 0;
    return slen-lent+del(t);
}

int main()
{
    char s[101],temp[101];
    int m,n;
    scanf("%d",&m);
    for(n=0;n<m;n++){
    scanf("%s",s);
    int i,len=strlen(s),ans=0;
    for(i=0;i<=len;i++){
        strncpy(temp,s,i);
        temp[i]='\0';
        strcat(temp,"A");
        strcat(temp,s+i);
        ans=MAX(ans,del(temp));//insert A

        strncpy(temp,s,i);
        temp[i]='\0';
        strcat(temp,"B");
        strcat(temp,s+i);
        ans=MAX(ans,del(temp));//insert B
        
        strncpy(temp,s,i);
        temp[i]='\0';
        strcat(temp,"C");
        strcat(temp,s+i);
        ans=MAX(ans,del(temp));//insert C
        strncmp(temp,s,i);
        temp[i]='\0';
        strcat(temp,"D");
        strcat(temp,s+i);
        ans=MAX(ans,del(temp));//insert D
}

printf("case #%d:\n%d\n",n,ans);

}
}
