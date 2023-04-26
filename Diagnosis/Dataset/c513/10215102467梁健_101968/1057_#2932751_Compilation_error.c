#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>


int main()
{
    char list[1010];gets(list);strupr(list);
    char s[1010];
    for(int i=0;i<1010;i++)s[i]=0;
    int len=strlen(list);
    s[0]=list[0];
    for(int i=1;i<len;i++){
        if(list[i]<s[0])s[strlen(s)]=list[i];
        else{
            char s1[1010];
            s1[0]=list[i];
            for(int m=0;m<strlen(s);m++){
                s1[m+1]=s[m];
            }
            s1[strlen(s)+1]=0;
            strcpy(s,s1);
        }
    }
    printf("%s",s);
    return 0;
}
