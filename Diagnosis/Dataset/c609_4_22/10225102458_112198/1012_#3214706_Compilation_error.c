#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        long long int max=0,min=1,min1;
        int d,cnt=0;
        char s[60];
        scanf("%s",s);
        char s1[strlen(s)*3+2];
        for(int j=2;j<strlen(s);j++){
            min*=8;
        }
        min1=min;
        for(int j=2;j<strlen(s);j++){
            d=s[j]-'0';
            min1/=8;
            max+=d*min1;
        }
        s1[cnt++]='0';
        s1[cnt++]='.';
        max*=10;
        while(max!=0){
            while(max<min){max*=10;s1[cnt++]='0';}
            s1[cnt++]=max/min+'0';
            max=(max%min)*10;
        }
        s1[cnt]='\0';
        printf("case #%d:\n%s\n",i,1
               0.75s1);
    }
    return 0;
}
