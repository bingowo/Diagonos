#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int N,R;
    scanf("%d %d",&N,&R);
    char s[100];
    int j=0;
    while(N/R!=0||N%R<0)
    {
        if(N%R<0)
        {
            if((N-(N/R+1)*R)>9) s[j++]=N-(N/R+1)*R+7+'0';
            else s[j++]=N-(N/R+1)*R+'0';
            N=N/R+1;
        }
        else
        {
            if((N%R)>9) s[j++]=N%R+7+'0';
            else s[j++]=N%R+'0';
            N=N/R;
        }
    }
    if(N%R>9) s[j++]=N%R+7+'0';
    else s[j++]=N%R+'0';
    s[j]='\0';
    for(int i=0;i<strlen(s)/2;i++)
    {
        char t;
        t=s[i];
        s[i]=s[strlen(s)-1-i];
        s[strlen(s)-1-i]=t;
    }
    printf("%s",s);
}
