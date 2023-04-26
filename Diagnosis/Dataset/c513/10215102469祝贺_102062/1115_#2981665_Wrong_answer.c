#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main(){
    int pro;scanf("%d",&pro);
    for(int index=0;index<pro;index++){
        printf("case #%d:\n",index);
        char s[30]={'0'};scanf("%s",s+1);
        int i=strlen(s)-1;
        for(;i>=0;i--){
            int minlarger=i;
            for(int j=i+1;j<strlen(s);j++){
                if(s[j]>s[i] && (s[j]<s[minlarger] || minlarger==i)) minlarger=j;
            }
            if(minlarger!=i){
                char c=s[minlarger];s[minlarger]=s[i];s[i]=c;
                break;
            }
        }
        int t=(s[0]=='0'?1:0);
        printf("%s\n",s+t);
        /*
        if(strlen(s)==2){s[0]=s[1];s[1]='0';}
        else{
            int i=strlen(s)-2;int minmin,minmax;
            if(s[i]<s[i+1]){minmin=i;minmax=i+1;}
            else{minmin=i+1;minmax=i;}
            for(i=i-1;i>=0 && minmax<minmin;i--){
                if(s[i]<s[minmin]){minmax=minmin;minmin=i;break;}
                else if(s[i]<minmax){minmax=i;}
            }
        }*/
    }
    return 0;
}
