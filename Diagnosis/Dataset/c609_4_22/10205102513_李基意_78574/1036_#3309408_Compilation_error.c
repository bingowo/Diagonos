#include <stdio.h>
#include <string.h>
int main()
{
    char s[55];
    scanf("%s", s);
    int len = strlen(s);
    itn score=0;
    int top=-1;
    int stack[55]={0};
    for (int i = 0; i < len; ++i)     
   {
        if (s[i] == '(') stack[++top] = 0;    
        else{
            int cur_score = 0;
            while (top >= 0 && stack[top] != 0)
            {
                cur_score += stack[top--];            
            }
            --top;
            if (cur_score == 0) stack[++top] = 1;
            else stack[++top] = cur_score * 2;
        }
   }
    while (top >= 0) score += stack[top--];
    printf("%d\n", score);
    return 0;
}