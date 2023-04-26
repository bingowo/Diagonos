#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
char s[100]={0};
scanf("%s",s);
int k=strlen(s)-1;
printf ("%d",k);
int max=0;int now=0;
if(k==0) max=1;
else{
for (int i=0;i<k;i++)
{
    if (s[i]!=s[i+1])
    {
        now++;
    }
    else{
        if(now>max)
        {
            max=now+1;
            now=0;
        }
        else now=0;
    }
}
}
printf("%d",max);
return 0;
}