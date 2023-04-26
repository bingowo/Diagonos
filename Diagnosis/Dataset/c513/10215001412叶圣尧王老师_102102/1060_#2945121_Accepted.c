#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main()
{
    char s[101];scanf("%s",s);
    int i=0,max=0,j;
    while(i<strlen(s))
    {
        while(s[i]=='0')i++;
        int k=0;
        if(isdigit(s[i]))
        {
            while(isdigit(s[i])){k++;i++;}
            max=max>k?max:k;
        }
        else i++;
    }
    printf("%d",max);
}