#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main()
{
    char *s=malloc(1000001*sizeof(char));scanf("%s",s);
    int i,j,max=0,tail;
    int len=strlen(s),start=0;
    for(i=0;i<len-max;i++)
    {
        int p[150]={0};
        int k=0;j=i;
        while(p[s[j]]==0&&j<len)
        {
            p[s[j]]=1;
            k++;
            if(k>max){tail=j;max=k;}
            j++;
        }
    }
    for(i=tail-max+1;i<=tail;i++)
        printf("%c",s[i]);
}
