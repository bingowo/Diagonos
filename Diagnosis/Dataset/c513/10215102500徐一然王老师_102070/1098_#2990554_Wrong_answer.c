#include <stdio.h>
#include <string.h>

int main()
{
    int count,count1;
    scanf("%d\n",&count);
    count1=count;
    char s[105];
    while(count--)
    {
        gets(s);
        char *p=s;
        char *p1=s;
        char t[5];
        int R=0,B=0,Y=0,G=0;
        while(*p)
        {
            if(*p!='!')
            {
                p1=p;
                while(*p1!='!'&&p1-p<4)
                {

                    t[p1-p]=*p1;
                    p1++;
                }
                if(p1-p==4||p1-p==3)
                {
                    break;
                }
            }
            p++;
        }
        if(strlen(s)==3)
        {
            if(t[0]!='R'&&t[1]!='R'&&t[2]!='R')
            {
                t[3]=='R';
                R++;
            }
            if(t[0]!='G'&&t[1]!='G'&&t[2]!='G')
            {
                t[3]=='G';
                G++;
            }
            if(t[0]!='Y'&&t[1]!='Y'&&t[2]!='Y')
            {
                t[3]=='Y';
                Y++;
            }
            if(t[0]!='B'&&t[1]!='B'&&t[2]!='B')
            {
                t[3]=='B';
                B++;
            }
            p1++;
        }
        p--;
        p1++;

        char *d=t+3;
        char *d1=t;
        while(p-s>=0)
        {
            if(*p=='!')
            {
                if(*d=='R')
                {
                    R++;
                }
                if(*d=='Y')
                {
                    Y++;
                }
                if(*d=='G')
                {
                    G++;
                }
                if(*d=='B')
                {
                    B++;
                }
            }
            if(d==t)
            {
                d=t+3;
            }
            else d--;
            p--;
        }


        while(*p1)
        {
            if(*p1=='!')
            {
                if(*d1=='R')
                {
                    R++;
                }
                if(*d1=='Y')
                {
                    Y++;
                }
                if(*d1=='G')
                {
                    G++;
                }
                if(*d1=='B')
                {
                    B++;
                }
            }
            if(d1==t+3)
            {
                d1=t;
            }
            else d++;
            p1++;
        }

        printf("case #%d:\n",count1-count-1);
        printf("%d %d %d %d\n",R,B,Y,G);
    }
}
