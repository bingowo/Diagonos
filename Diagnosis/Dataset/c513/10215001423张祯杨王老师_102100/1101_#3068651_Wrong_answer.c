#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        char s[3][100];
        for(int q=0;q<3;q++) scanf("%s",s[q]);
        int len[3];
        for(int q=0;q<3;q++) len[q]=strlen(s[q]);
        char re1[10][2],re2[10];
        int r1=0,r2=0;
        if(len[3]==1)
        {
            if(len[1]==3&&len[2]==2)
            {
                if(s[2][0]=='A'||s[2][0]=='B')
                  {re1[1][0]='A';re1[2][0]='A';re1[2][1]='B';re1[3][0]='B';
                  r1=3;}
                if(s[2][0]=='O')
                    {re1[1][0]='A';re1[2][0]='B';
                  r1=2;}
                if(s[1][2]=='-'&&s[2][1]=='-')
                    {re2[0]='-';r2=1;
                    }
                 if(s[1][2]!='-'&&s[2][1]!='-')
                    {re2[0]='+';re2[1]='-';r2=2;
                    }

            }
            if(len[1]==2&&len[2]==3)
            {
                if(s[1][0]=='A'||s[1][0]=='B')
                  {re1[1][0]='A';re1[2][0]='A';re1[2][1]='B';re1[3][0]='B';
                  r1=3;}
                if(s[1][0]=='O')
                    {re1[1][0]='A';re1[2][0]='B';
                  r1=2;}
                if(s[1][1]=='-'&&s[2][2]=='-')
                    {re2[0]='-';r2=1;
                    }
                 if(s[1][1]!='-'&&s[2][2]!='-')
                    {re2[0]='+';re2[1]='-';r2=2;
                    }

            }
             if(len[1]==2&&len[2]==2)
            {
               if(s[1][0]=='A')
               {
                   if(s[2][0]=='A'||s[2][0]=='O');
                      {
                          re1[1][0]='A';re1[2][0]='O';
                          r1=2;
                      }
                   if(s[2][0]=='B')
                   {
                       re1[1][0]='A';re1[2][0]='A';re1[2][1]='B';re1[3][0]='B';re1[4][0]='O';
                       r1=4;
                   }
               }
               if(s[1][0]=='B')
               {
                   if(s[2][0]=='B'||s[2][0]=='O');
                      {
                          re1[1][0]='B';re1[2][0]='O';
                          r1=2;
                      }
                   if(s[2][0]=='A')
                   {
                       re1[1][0]='A';re1[2][0]='A';re1[2][1]='B';re1[3][0]='B';re1[4][0]='O';
                       r1=4;
                   }
               }
                if(s[1][1]=='-'&&s[2][1]=='-')
                    {re2[0]='-';r2=1;
                    }
                 if(s[1][1]!='-'&&s[2][1]!='-')
                    {re2[0]='+';re2[1]='-';r2=2;
                    }
            }
        }
        for(int x=1;x<=r1;x++)
        {
            for(int y=0;y<r2;y++)
            {
                printf("%s%s ",re1[x],re2[y]);
            }
        }
    }

    return 0;
}
