#include<stdio.h>
#include<string.h>
int main()
{
    char input[101]={'\0'};
    while(scanf("%s",input)!=EOF)
    {
        char output[210][101]={'\0'};
        output[101][0]=input[0];
        int idx=101;
        for(int i=1;i<strlen(input);i++)
        {
            if(input[i]<input[i-1])
            {
                idx--;
                for(int j=strlen(output[idx]);j<i;j++) output[idx][j]=' ';
                output[idx][i]=input[i];
            }
            else if(input[i]>input[i-1])
            {
                idx++;
                for(int j=strlen(output[idx]);j<i;j++) output[idx][j]=' ';
                output[idx][i]=input[i];
            }
            else
            {
                for(int j=strlen(output[idx]);j<i;j++) output[idx][j]=' ';
                output[idx][i]=input[i];
            }
        }
        for(int i=210;i>=0;i--)
            //if(strlen(output[i])!=0)
                printf("%s\n",output[i]);
    }
    return 0;
}