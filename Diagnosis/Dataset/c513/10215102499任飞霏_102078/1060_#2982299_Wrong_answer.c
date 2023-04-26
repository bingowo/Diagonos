#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char s[101]={0};
    scanf("%s",s);
    int len=strlen(s),d=0;
    char tmp[101]={0};
    int i=0,l=0,max=0;
    for(i=0;i<len;i++){
        if(s[i]>='0'&&s[i]<='9'){
            tmp[d++]=s[i];
            l++;
        }
        else{
            int t=0;
            while(tmp[t]=='0'&&tmp[t]!='\0'){
                t++;
                l--;
            }
            if(l>max)max=l;
            l=0;
            for(int j=0;j<strlen(tmp);j++)tmp[j]=0;
        }

    }
    printf("%d",max);
    return 0;
}
