#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char s[100];
    scanf("%s",s);
    int len=strlen(s);
    int b[63],i;
    for(i=0;i<63;i++){
        b[i]=-1;
    }
    for(i=0;i<len;i++){
        if(s[i]>='0'&&s[i]<='9'){
            b[s[i]-'0']++;
        }
        else if(s[i]>='a'&&s[i]<='z'){
            b[s[i]-'a'+10]++;
        }
        else{
            b[s[i]-'A'+37]++;
        }
   // }
  // for(i=0;i<len;i++){
        if(s[i]>='0'&&s[i]<='9'){
            if(b[s[i]-'0']==0){
                printf("%c",s[i]);
            }
        }
        else if(s[i]>='a'&&s[i]<='z'){
            if(b[s[i]-'a'+10]==0){
                 printf("%c",s[i]);
            }
        }
        else{
            if(b[s[i]-'A'+37]==0){
                 printf("%c",s[i]);
            }
        }
   }
}
