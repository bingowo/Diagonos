#include <stdio.h>
#include <stdlib.h>
#include <string.h>
const char* s1="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

void reverse (char* s)
{
    int i,j;
    char tmp;
    for (i=0,j=strlen(s)-1;i<j;i++,j--)
    {
        tmp=s[i];
        s[i]=s[j];
        s[j]=tmp;
    }
}



int main()
{
    int N,R,m;
    scanf("%d %d",&N,&R);
    char s[100]={0};
    for (int i=0;N;i++)
    {


        if (N%R<0)
        {
            s[i]=s1[N-(N/R+1)*R];
            N=N/R+1;
        }

        else
        {

            s[i]=s1[N%R];
            N=N/R;
        }



    }
    reverse(s);
    printf("%s\n",s);
    return 0;
}
