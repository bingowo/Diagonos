#include <stdio.h>
#include <string.h>

int main()
{
    enum{
        status0 =0,
        status1 =1,
        status2 =2,
        status3 = 3,
    }state;
    char ch,temp;
    state = status0;
    char s[500][20];
    int i=0,j=0;

    while ((ch = getchar()) != EOF)
    {

        switch(state){
            case 0:
                if(ch == '0')
                {
                    state=status1;
                }
                break;
            case 1:
                if(ch == 'x')
                {
                    state=status2;
                } else if(ch == '0')
                {
                    state=status1;
                }
                else
                {
                    state=status0;

                }
                break;
            case 2:
                if((ch>'0' && ch <= '9') || (ch >= 'a' && ch <= 'f'))
                {
                    state=status2;
                    s[j][i++] = ch;
                }else if(ch == '0')
                {
                    state=status3;
                    temp = ch;
                }else
                {
                    state=status0;
                    if(strlen(s[j]) != 0)
                    {
                        j++;
                        i=0;
                    }
                }break;
            case 3:
                if(ch == '0')
                {
                    s[j][i++]=temp;
                    state=status3;
                    temp=ch;
                }
                else if(ch == 'x')
                {
                    state=status2;
                    j++;
                    i=0;
                }
                else if((ch >'0' && ch <='9') ||(ch >= 'a' && ch <= 'f'))
                {
                    state=status2;
                    s[j][i++] = ch;
                }
                else
                {
                    state=status0;
                    j++;
                    i=0;
                }break;
        }
    }
    int n[5000];
    memset(n,0,5000);
    for(int k=0,y=0;k<j;k++,y++)
    {
        for(int x=0;s[k][x] != '\0';x++)
        {
            if(s[k][x] >= 'a' && s[k][x] <= 'f')
                s[k][x] = s[k][x] - 'a'+10;
            else
                s[k][x]= s[k][x] - '0';
            n[y]= n[y]*16+s[k][x];
        }
    }
    for(int y=0;y<j;y++)
    printf("%d ",n[y]);


}
