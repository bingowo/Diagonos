#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>

int main()
{
    char s[10001];
    scanf("%s",s);
    int num[10000],pos=-2,k=0,cnt=0,len=strlen(s);
    for(int i=0;i<len;i++){
        if(isdigit(s[i])){
            if(pos==i-1)cnt*=10;
            cnt+=(s[i]-48);
            pos=i;
            if(isalpha(s[i+1])||i==len-1){
                num[k++]=cnt;
                cnt=0;
            }
        }
    }
    int pn=0,pj=0,flag=0;
    char jud[10001];
    for(int i=0;i<len;i++){
        if(isalpha(s[i])){
            jud[pj++]=s[i];
            flag=0;
        }
        if(flag)continue;
        if(isdigit(s[i])){
            flag=1;
            jud[pj]=0;
            for(int j=0;j<num[pn];j++)printf("%s",jud);
            memset(jud,0,sizeof(char)*pj);
            pj=0;
            pn++;
        }
    }
    
    if(pj!=0)printf("%s",jud);
    return 0;
}
