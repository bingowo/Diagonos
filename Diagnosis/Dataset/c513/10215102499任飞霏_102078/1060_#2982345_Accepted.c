#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char s[102]={0};
    scanf("%s",s);
    int len=strlen(s),d=0,flag=0;
    //s[len]='a';s[len+1]='\0';
    char tmp[101]={0};
    int i=0,l=0,max=0;
    for(i=0;i<len+1;i++){
        if(s[i]>='0'&&s[i]<='9'){
            tmp[d++]=s[i];
            l++;
        }
        else{
            flag=1;
            int t=0;
            while(tmp[t]=='0'&&tmp[t]!='\0'){
                t++;
                l--;
            }
            if(l>max)max=l;
            l=0;
            d=0;
            for(int j=0;j<101;j++)tmp[j]=0;
        }

    }
    if(flag==0){
        max=i;
        int j=0;
        while(s[j]=='0'){
            max--;
            j++;
        }
    }
    printf("%d",max);
    return 0;
}
