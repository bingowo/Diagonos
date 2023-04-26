#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cal(int*m,char*p1,char*p2)
{
    int len = strlen(p2);
    int res=p2[0];
    int n1,n2;
    if(len >5)
    {
        n1 = p2[3];
        n2 = p2[6];
    }
    else
    {
        n1 = p2[0];
        n2 = p2[3];
    }
    switch(p1[0]*10+p1[1])
    {
    case((int)'I'*10+'N'):
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
    case((int)'M'*10+'O'):
        {
            if(p1[3]=='V')
            {
                    int n1 = p2[0];
                int n2 = p2[3];
                m[n1] = m[n2];
                break;
            }
            else
            {
                m[res] = m[n1]%m[n2];
                break;
            }
        }
    case((int)'A'*10+'D'):
        {
            m[res]=m[n1] + m[n2];
            break;
        }
    case (int)'U'*10+'S':
        {

           m[res]= m[n1] - m[n2];
            break;
        }
    case'M'*10+'U':
        {

            m[res]=m[n1] * m[n2];
            break;
        }
    case'D'*10+'I':
        {

         m[res]=   m[n1] / m[n2];
            break;
        }
    case 'O'*10+'U':
    {
        int n1 = p2[0];
        printf("%d\n",m[n1]);
        break;
    }
    case 'X'*10+'C':
        {
            int q = m[n1];
            m[n1] = m[n2];
            m[n2] = q;
            break;
        }
    case 'A'*10+'N':
        {
            m[res] = m[n1]&m[n2];
            break;
        }
    case 'O'*10+'R':
        {
            m[res] = m[n1]|m[n2];
            break;
        }
    case 'X'*10+'O':
        {
            m[res] = m[n1]^m[n2];
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
