#include <stdio.h>
#include <string.h>

void insert(char temp[], char c, int pos)
{
    memmove(temp+pos+1, temp+pos, strlen(temp)-pos+1);
    *(temp + pos) = c;
    return ;
}

int del(char s[])
{
    int ret = 0, lens = strlen(s);
    char* pend = s + lens;
    char *pa = s;
    char *pb = pa + 1;
    while(*pa != '\0')
    {
        if(*pa == *pb)  pb++;
        else
        {
           if(pb - pa > 1)
           {
              ret += (pb - pa);
              lens -= (pb - pa);
              memmove(pa, pb, pend - pb +1);
              pend = pa + lens;
              pb = pa + 1;
           }
           else
           {
              pa = pb;
              pb = pa + 1;
              lens--;
           }
        }
    }
    return ret;
}

int main()
{
    int t;
    scanf("%d",&t);
    for(int j=0; j<t; j++)
    {
      char s[102], temp[102];
      scanf("%s", s);
      int max=0, len=strlen(s), num;
      for(int i=0; i<=len; i++)
      {
        for(int k=0; k<3; k++)
        {
            strcpy(temp, s);
            insert(temp, 'A'+k, i);
            num = del(temp);
            if(num > max)  max = num;
        }
      }
      printf("case #%d:\n%d\n", j, max);
    }
    return 0;
}
