#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        char s[109];
        char ans[109]={0};
        scanf("%s",s);
        int num=0;
        int len=strlen(s)-2;
        while(len--){
            int digit=s[len+2]-'0';
            int j=0;
            int temp;
            do{
                if(j<num)temp=digit*10+ans[j]-'0';
                else temp=digit*10;
                ans[j++]=temp/8+'0';
                digit=temp%8;
            }while(digit!=0||j<num);
            num=j;
        }
        ans[num]=0;
        printf("case #%d:\n0.",i);
        for(int l=0;l<num;l++)printf("%c",ans[l]);
        printf("\n");
    }
    return 0;
}
