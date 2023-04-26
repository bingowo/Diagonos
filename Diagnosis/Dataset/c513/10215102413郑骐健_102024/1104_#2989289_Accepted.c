#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cal(long long *m,char*p1,char*p2)
{
    int len = strlen(p2);
    int res=p2[0];
    int n1,n2;
    if(len >6)
    {
        n1 = p2[3];
        n2 = p2[6];
    }
    else if(len>3)
    {
        n1 = p2[0];
        n2 = p2[3];
    }

    switch(p1[0]*26+p1[1])
    {
    case((int)'I'*26+'N'):
    {
        int n = 1;
        long long z =0;
        while(*p2!='-'&&(!isdigit(*p2)))p2++;
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
        m[res] = z*n;
        break;

    }
    case((int)'M'*26+'O'):
        {
            if(p1[2]=='V')
            {
                m[n1] = m[n2];
                break;
            }
            else
            {
            m[res] = m[n1]%m[n2];
                break;
            }
        }
    case((int)'A'*26+'D'):
        {
            m[res]=m[n1] + m[n2];
            break;
        }
    case (int)'S'*26+'U':
        {

           m[res]= m[n1] - m[n2];
            break;
        }
    case'M'*26+'U':
        {

            m[res]=m[n1] * m[n2];
            break;
        }
    case'D'*26+'I':
        {

         m[res]=   m[n1] / m[n2];
            break;
        }
    case 'O'*26+'U':
    {
        printf("%d\n",m[res]);
        break;
    }
    case 'X'*26+'C':
        {
            long long q = m[n1];
            m[n1] = m[n2];
            m[n2] = q;
            break;
        }
    case 'A'*26+'N':
        {
            m[res] = m[n1]&m[n2];
            break;
        }
    case 'O'*26+'R':
        {
            m[res] = m[n1]|m[n2];
            break;
        }
    case 'X'*26+'O':
        {
            m[res] = m[n1]^m[n2];
            break;
        }
}
}

int main()
{
    char order[1000];
    char next[1000];
    long long mid[2000];
    memset(mid,0,sizeof(mid));
    while(scanf("%s%s",order,next)!=EOF)
    {
        cal(mid,order,next);
    }
    return 0;
}
