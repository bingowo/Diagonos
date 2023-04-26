#include <stdio.h>
#include <math.h>
#include <string.h>

char map[22]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J','K','\0'};

void toM(int n, double m, char *s)
{
    int temp=0, remain=0,mm= (int)m, index = 50;
    do
    {
       temp = (int)ceil(n/m);
       remain = n - temp*mm;
       s[index--] = map[remain];
       n=temp;
    }
    while(n!=0);
    memmove(s,s+index+1,50-index);
    s[50-index]='\0';
    return;

}

int main()
{
     int n,m;
     scanf("%d %d", &n, &m);
     char s[51];
     toM(n,(double)m,s);
     printf("%s\n",s);
     return 0;
}