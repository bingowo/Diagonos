#include<stdio.h>
#include<string.h>
int main()
{
    int i;
    char s[60]={0};
    scanf("%s",s);
    int score = 0, level = 0,temp=0;
    int length = strlen(s);
    for (i = 0; i < length; i++) 
    {
        if (s[i] == '(') 
        {
            level++;
        } 
        else 
        {
            level--;
            if (s[i-1] == '(') 
            {
                temp = 1<< level;
                score += temp;
            }
        }
    }
    printf("%d\n",score);
    return 0;
}