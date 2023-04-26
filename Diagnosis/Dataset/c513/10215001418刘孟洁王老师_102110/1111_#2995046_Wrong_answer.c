#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
char zuo[47][47];
int cal(int x,int a3,int a2,int a1,int a0)
{
    int ans = a3*pow(x,3)+a2*pow(x,2)+a1*x+a0;
    return ans;
}

void initial()
{
    int y,x;
    for(y = 0; y < 41; y++)
         {
            for(x = 0; x < 41; x++)zuo[y][x] = '.';
            zuo[y][x] = '\0';
         }
        zuo[0][20] = '^';
        for(y = 1; y < 41; y++)zuo[y][20] = '|';
        for(x = 0; x < 41; x++)zuo[20][x] = '-';
        zuo[20][20] = '+';
        zuo[20][40] = '>';
}

int main()
{
    char s[27];
    int i,x,y,k,sign[4],a[4];
    while(scanf("%s",s)!=EOF)
    {
        k = 0;
        memset(a,0,sizeof(a));
        int a3,a2,a1,a0;
        initial();
        //for(y = 0; y < 41; y++)printf("%s\n",zuo[y]);
        int len = strlen(s);
        for(i = 0; i < len; i++)
            if(s[i] == '=')break;
        a3 = 0,a2 = 0,a1 = 0,a0 = 0;
        for(i += 1; i < len; i++)
        {
          if(isdigit(s[i])&&s[i-1] != '^')
            {
               if(s[i-1] == '+'||i == 5)sign[k] = 1;
               else if(s[i-1] == '-')sign[k] = -1;
               for(; isdigit(s[i]); i++){a[k] = a[k]*10 + s[i]-'0';}
               a[k] *= sign[k];
               if(s[i+1] == '^'&&s[i+2] == '3')a3 = a[k];
               else if(s[i+1] == '^'&&s[i+2] == '2')a2 = a[k];
               else if(s[i] == 'x'&&(s[i+1] == '+'||s[i+1] == '-'||s[i+1] == '\0'))a1 = a[k];
               else if(s[i] == '\0')a0 = a[k];
               k++;
               i--;
            }
           else if(s[i] == 'x'&&!isdigit(s[i-1]))
            {
                if(s[i-1] == '+'||i == 5)a[k] = 1;
                else if(s[i-1] == '-')a[k] = -1;
               if(s[i+1] == '^'&&s[i+2] == '3')a3 = a[k];
               else if(s[i+1] == '^'&&s[i+2] == '2')a2 = a[k];
               else if(s[i] == 'x'&&(s[i+1] == '+'||s[i+1] == '-'||s[i+1] == '\0'))a1 = a[k];
               //else if(s[i] == '\0')a0 = x[k];
               k++;
             }
     }
       for(x = -20; x <= 20; x++)
      {
         y = cal(x,a3,a2,a1,a0);
         if(abs(y) <= 20)zuo[20-y][x+20] = '*';
      }
       for(y = 0; y < 41; y++)printf("%s\n",zuo[y]);
       memset(s,0,sizeof(s));
    }
    return 0;
}

