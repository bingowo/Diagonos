#include<stdio.h>
#include<math.h>
#include<string.h>

int main()
{
    char s[10001] = {'\0'};
    char num[3] = {0};
    int num_len = 1;
    char letter[10001] = {'\0'};
    gets(s);
    int s_p = 0;
    int letter_len = 0;

    for(;s_p<strlen(s);s_p++)
    {
        if(s[s_p]<48||s[s_p]>57)
        {
            letter_len++;
        }
        else
        {
            for(int i = 0;i<letter_len;i++)
            {
                letter[i] = s[s_p-letter_len+i];

            }

            num[0] = s[s_p];
            if(s[s_p+1]>=48&&s[s_p+1]<=57)
            {

                num[1] = s[s_p+1];
                s_p++;
                num_len++;
            }
            if(s[s_p+1]>=48&&s[s_p+1]<=57)
            {

                num[2] = s[s_p+1];
                s_p++;
                num_len++;
            }

            int times;
            if(num_len == 3)
            {
                times = (num[0]-48)*pow(10,num_len-1)+(num[1]-48)*pow(10,num_len-2)+(num[2]-48)*pow(10,num_len-3);
            }
            else if(num_len == 2)
            {
                times = (num[0]-48)*pow(10,num_len-1)+(num[1]-48)*pow(10,num_len-2);

            }
            else{
                times = (num[0]-48)*pow(10,num_len-1);
            }

            for(int j = 0;j<times;j++)
            {
                printf("%s",letter);
            }
            int n = 0;
            while(n<letter_len)
            {
                letter[n]='\0';
                n++;
            }
            letter_len = 0;
            num[0]=0;num[1]=0;num[2]=0;
            num_len = 1;

        }
    }
    if(letter_len!=0)
        {
            for(int cnt = strlen(s)-letter_len;cnt<strlen(s);cnt++)
            {
                printf("%c",s[cnt]);
            }
        }

    return 0;
}