#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cal(int*m,char*p1,char*p2)
{
    switch(p1[0]+p1[1])
    {
    case('I'+'N'):
    {
        int po = p2[0];
        int n = 1;
        int z =0;
        while(*p2!=',')p2++;p2++;
        if(*p2=='-')
        {
            n*=-1;
            p2++;
        }
        while(*p2!=0)
        {
            z=z*10+*p2-'0';
            p2++;
        }
        m[po] = z*n;
        break;

    }
    case('M'+'O'):
        {
            int n1 = p2[0];
            int n2 = p2[3];
            m[n1] = m[n2];
            break;
        }
    case('A'+'D'):
        {
            int n1 = p2[0];
            int n2 = p2[3];
            m[n1] += m[n2];
            break;
        }
    case 'U'+'S':
        {
              int n1 = p2[0];
            int n2 = p2[3];
            m[n1] -= m[n2];
            break;
        }
    case'M'+'U':
        {
            int n1 = p2[0];
            int n2 = p2[3];
            m[n1] *= m[n2];
            break;
        }
    case'D'+'I':
        {
             int n1 = p2[0];
            int n2 = p2[3];
            m[n1] /= m[n2];
            break;
        }
    case 'O'+'U':
    {
        int n1 = p2[0];
        printf("%d",m[n1]);
        break;
    }
}
}

int main()
{
    char order[20];
    char next[20];
    int mid[200];
    memset(mid,0,sizeof(mid));
    while(scanf("%s%s",order,next)!=EOF)
    {
        cal(mid,order,next);
    }
    return 0;
}
