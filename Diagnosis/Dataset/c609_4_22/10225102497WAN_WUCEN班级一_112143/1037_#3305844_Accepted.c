#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char string[1000002];
    int len=0,maxsublen=0,maxsub=0;
    fgets(string,1000002,stdin);
    string[strlen(string)-1]='\0';
    len=strlen(string);
    for(int i=0;i<len;i++)
    {
        for(int sublen=0;;sublen++)
        {
            int k=i+sublen;
            short repitition=0;
            for(int j=i;j<k;j++)
                if(string[k]==string[j])
                {
                    repitition=j+1;
                    break;
                }
            if(repitition||!string[k])
            {
                if(maxsublen<sublen)
                {
                    maxsublen=sublen;
                    maxsub=i;
                    i=repitition-1;
                }
                break;
            }
        }
    }
    for(int i=0;i<maxsublen;i++)
        printf("%c",string[maxsub+i]);
    return 0;
}
