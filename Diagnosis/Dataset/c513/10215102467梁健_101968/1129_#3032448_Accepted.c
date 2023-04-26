#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>

int main()
{
    char s[10001],res[10000000];
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
    int pr=0,pn=0,pj=0,flag=0;
    char jud[10001];
    for(int i=0;i<len;i++){
        if(isalpha(s[i])){
            jud[pj++]=s[i];
            res[pr++]=s[i];
            flag=0;
        }
        if(flag)continue;
        if(isdigit(s[i])){
            //printf("jud=%s\n",jud);
            //printf("time=%d\n",num[pn]);
            flag=1;
            for(int j=0;j<num[pn]-1;j++){
                for(int z=0;z<pj;z++){
                    res[pr++]=jud[z];
                }
            }
            for(int j=0;j<pj+1;j++){
                jud[j]=0;
            }
            pj=0;
            pn++;
        }
    }
    res[pr]=0;
    printf("%s",res);
    return 0;
}
