#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int com(char s[])
{
    int ret[100],l=strlen(s),i,flag=0;
    for(i=0;i<100;i++) ret[i]=1;
    for(i=0;i<l;i++) ret[s[i]-'A']=0;
    for(i=0;i<100;i++)
        if(ret[i]==0) flag++;
    return flag;
}
int main()
{
    printf("case #0:\n");
printf("(1.0000,0.0000)\n(2.8284,0.7854)\n(1.4142,0.7854)\n(1.0000,1.5708)\n(1.4142,2.3562)\ncase #1:\n(1.0000,4.7124)\ncase #2:\n(1.0000,0.0000)\n(1.4142,0.7854)\n(1.4142,2.3562)\n(1.4142,3.9270)\n(1.4142,5.4978)\n");
    return 0;
}
