#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
    char s[110];
    char t[220];
    scanf("%s",s);
    int len=strlen(s);
    t[0]=s[0];
    int m=0;
    for(int i=1;i<len;i++){
        if(t[m]==s[i]){
            int j=i;
            while(s[j]==s[j+1]&&(j+1)<len){
                j++;
            }
            if(j+1==len){
                m++;
                t[m]=s[i];
                continue;
            }
            if(s[j+1]<t[m]){
                m++;
                t[m]=s[i];
            }else{
                m++;
                t[m]=t[m-1];
                m++;
                t[m]=s[i];
            }
        }else if(t[m]<s[i]){
            m++;
            t[m]=t[m-1];
            m++;
            t[m]=s[i];
        }else{
            m++;
            t[m]=s[i];
        }
    }
    for(int i=0;i<=m;i++){
        printf("%c",t[i]);
    }
    return 0;

}
