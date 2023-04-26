#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n,m,count,add=0;
    char mn[100],mn2[100];
    scanf("%d%s%d",&n,mn,&m);
    int max=0,bet=1,mn1;
    for(int i=strlen(mn)-1;i>=0;i--){
        if(mn[i]>='A'&&mn[i]<='Z')mn1=mn[i]-'A'+10;
        else if(mn[i]>='a'&&mn[i]<='z')mn1=mn[i]-'a'+10;
        else mn1=mn[i]-'0';
        max+=mn1*bet;

        bet*=n;

    }
    do{
        count=max%m;
        if(count>=0 && count<=9)mn2[add++]=count+'0';
        else mn2[add++]=count-10+'A';
    }while(max/=m);
    for(int j=add-1;j>=0;j--)printf("%c",mn2[j]);
    printf("\n");
    return 0;
}
