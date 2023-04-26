#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void*a,const void*b){
    char*s1=(char*)a;
    char*s2=(char*)b;
    int l1,l2,i;
    char str1[32]=*s1;
    char str2[32]=*s2;
    l1=strlen(str1);l2=strlen(str2);
    int sum1=0,sum2=0,flag1=0,flag2=0;
    for(i=0;i<l1;i++){
        if(str1[i]>='0'&& str1[i]<='9'){
            flag1=1;
            sum1=sum1*10+str1[i]-'0';
        }
    }
    for(i=0;i<l2;i++){
        if(str2[i]>='0'&& str2[i]<='9'){
            flag2=1;
            sum2=sum2*10+str2[i]-'0';
        }
    }
    if (flag1 && ~flag2) return 1;
    else if (flag1 && flag2 && sum1>sum2) return 1;
    else if(~flag1 && ~flag2) return strcmp(str1,str2);
}

int main()
{   char s[100][32];
    int n=0;
    while(scanf("%s",s[n++])!=EOF);
    qsort(s[100],n-1,sizeof(char*),cmp);
    for(int i=0;i<n-1;i++)
        printf("%s ",s[i]);
    return 0;
}
