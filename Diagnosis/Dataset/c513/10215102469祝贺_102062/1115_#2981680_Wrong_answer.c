#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main(){
    int pro;scanf("%d",&pro);
    for(int index=0;index<pro;index++){
        printf("case #%d:\n",index);
        char s[30]={'0'};scanf("%s",s+1);
        char a[100]={0},b[100]={0},c[100]={0};
        int i=strlen(s)-1;
        for(;i>=0;i--){
            int minlarger=i;
            for(int j=i+1;j<strlen(s);j++){
                if(s[j]>s[i] && (s[j]<s[minlarger] || minlarger==i)) minlarger=j;
            }
            if(minlarger!=i){
                strncpy(a,s,i);strncpy(b+1,s+i,minlarger-i);strcpy(c,s+minlarger+1);
                b[0]=s[minlarger];
                break;
            }
        }
        int t=(a[0]=='0'?1:0);
        printf("%s%s%s\n",a+t,b,c);
    }
    return 0;
}
