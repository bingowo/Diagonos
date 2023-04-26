#include <stdio.h>

int main()
{
    int AX=0,BX=0,CX=0,DX=0;
    char s[1000];
    while(1)
    {
        gets(s);
        char *p=s;
        if(s[0]=='I')
        {
            while(*p)
            {
                p++;
                if(*p==' ')
                    break;

            }
            p++;
            if(*p=='A')
            {
                AX=0;
                    while(*p)
                {
                    if(*p==',')
                        break;
                    p++;
                }
                p++;
                while(*p)
                {
                    AX=AX*10+*p-'0';

                    p++;
                }

            }
            else if(*p=='B')
            {
                BX=0;
                while(*p)
                {
                    if(*p==',')
                        break;
                    p++;
                }
                p++;
                while(*p)
                {
                    BX=BX*10+*p-'0';p++;
                }
            }
            else if(*p=='C')
            {
                CX=0;
                while(*p)
                {
                    if(*p==',')
                        break;
                    p++;
                }
                p++;
                while(*p)
                {
                    CX=CX*10+*p-'0';p++;
                }
            }
            else
            {
                DX=0;
                while(*p)
                {
                    if(*p==',')
                        break;
                    p++;
                }
                p++;
                while(*p)
                {
                    DX=DX*10+*p-'0';p++;
                }
            }


        }
        else if(s[0]=='M'&&s[1]=='O')
        {
            while(*p)
            {
                if(*p=='X')break;
                p++;
            }
            p--;
            if(*p=='A')
            {
                p=p+2;
                while(*p)
                {
                    if(*p=='X')break;
                    p++;
                }p--;
                if(*p=='A')
                {
                    AX=AX;
                }
                else if(*p=='B')
                {
                    AX=BX;
                }
                else if(*p=='C')
                {
                    AX=CX;
                }
                else
                {
                    AX=DX;
                }
            }
            else if(*p=='B')
            {
                p=p+2;
                while(*p)
                {
                    if(*p=='X')break;
                    p++;
                }p--;
                if(*p=='A')
                {
                    BX=AX;
                }
                else if(*p=='B')
                {
                    BX=BX;
                }
                else if(*p=='C')
                {
                    BX=CX;
                }
                else
                {
                    BX=DX;
                }
            }
            else if(*p=='C')
            {
                p=p+2;
                while(*p)
                {
                    if(*p=='X')break;
                    p++;
                }p--;
                if(*p=='A')
                {
                    CX=AX;
                }
                else if(*p=='B')
                {
                    CX=BX;
                }
                else if(*p=='C')
                {
                    CX=CX;
                }
                else
                {
                    CX=DX;
                }
            }
            else if(*p=='D')
            {
                p=p+2;
                while(*p)
                {
                    if(*p=='X')break;
                    p++;
                }p--;
                if(*p=='A')
                {
                    DX=AX;
                }
                else if(*p=='B')
                {
                    DX=BX;
                }
                else if(*p=='C')
                {
                    DX=CX;
                }
                else
                {
                    DX=DX;
                }
            }
        }
        else if(s[0]=='M'&&s[1]=='U')
        {
            while(*p)
            {
                if(*p=='X')break;
                p++;
            }p--;
            if(*p=='A')
            {
                p=p+2;
                while(*p)
                {
                    if(*p=='X')break;
                    p++;
                }p--;
                if(*p=='A')
                {
                    AX=AX*AX;
                }
                else if(*p=='B')
                {
                    AX=AX*BX;
                }
                else if(*p=='C')
                {
                    AX=AX*CX;
                }
                else
                {
                    AX=AX*DX;
                }
            }
            else if(*p=='B')
            {
                p=p+2;
                while(*p)
                {
                    if(*p=='X')break;
                    p++;
                }p--;
                if(*p=='A')
                {
                    BX=BX*AX;
                }
                else if(*p=='B')
                {
                    BX=BX*BX;
                }
                else if(*p=='C')
                {
                    BX=BX*CX;
                }
                else
                {
                    BX=BX*DX;
                }
            }
            else if(*p=='C')
            {
                p=p+2;
                while(*p)
                {
                    if(*p=='X')break;
                    p++;
                }p--;
                if(*p=='A')
                {
                    CX=CX*AX;
                }
                else if(*p=='B')
                {
                    CX=CX*BX;
                }
                else if(*p=='C')
                {
                    CX=CX*CX;
                }
                else
                {
                    CX=CX*DX;
                }
            }
            else if(*p=='D')
            {
                p=p+2;
                while(*p)
                {
                    if(*p=='X')break;
                    p++;
                }p--;
                if(*p=='A')
                {
                    DX=DX*AX;
                }
                else if(*p=='B')
                {
                    DX=DX*BX;
                }
                else if(*p=='C')
                {
                    DX=DX*CX;
                }
                else
                {
                    DX=DX*DX;
                }
            }

        }
        else if(s[0]=='A')
        {
            while(*p)
            {
                if(*p=='X')break;
                p++;
            }p--;
            if(*p=='A')
            {
                p=p+2;
                while(*p)
                {
                    if(*p=='X')break;
                    p++;
                }p--;
                if(*p=='A')
                {
                    AX=AX+AX;
                }
                else if(*p=='B')
                {
                    AX=AX+BX;
                }
                else if(*p=='C')
                {
                    AX=AX+CX;
                }
                else
                {
                    AX=AX+DX;
                }
            }
            else if(*p=='B')
            {
                p=p+2;
                while(*p)
                {
                    if(*p=='X')break;
                    p++;
                }p--;
                if(*p=='A')
                {
                    BX=BX+AX;
                }
                else if(*p=='B')
                {
                    BX=BX+BX;
                }
                else if(*p=='C')
                {
                    BX=BX+CX;
                }
                else
                {
                    BX=BX+DX;
                }
            }
            else if(*p=='C')
            {
                p=p+2;
                while(*p)
                {
                    if(*p=='X')break;
                    p++;
                }p--;
                if(*p=='A')
                {
                    CX=CX+AX;
                }
                else if(*p=='B')
                {
                    CX=CX+BX;
                }
                else if(*p=='C')
                {
                    CX=CX+CX;
                }
                else
                {
                    CX=CX+DX;
                }
            }
            else if(*p=='D')
            {
                p=p+2;
                while(*p)
                {
                    if(*p=='X')break;
                    p++;
                }p--;
                if(*p=='A')
                {
                    DX=DX+AX;
                }
                else if(*p=='B')
                {
                    DX=DX+BX;
                }
                else if(*p=='C')
                {
                    DX=DX+CX;
                }
                else
                {
                    DX=DX+DX;
                }
            }
        }
        else if(s[0]=='S')
        {
            while(*p)
            {
                if(*p=='X')break;
                p++;
            }p--;
            if(*p=='A')
            {
                p=p+2;
                while(*p)
                {
                    if(*p=='X')break;
                    p++;
                }p--;
                if(*p=='A')
                {
                    AX=AX-AX;
                }
                else if(*p=='B')
                {
                    AX=AX-BX;
                }
                else if(*p=='C')
                {
                    AX=AX-CX;
                }
                else
                {
                    AX=AX-DX;
                }
            }
            else if(*p=='B')
            {
                p=p+2;
                while(*p)
                {
                    if(*p=='X')break;
                    p++;
                }p--;
                if(*p=='A')
                {
                    BX=BX-AX;
                }
                else if(*p=='B')
                {
                    BX=BX-BX;
                }
                else if(*p=='C')
                {
                    BX=BX-CX;
                }
                else
                {
                    BX=BX-DX;
                }
            }
            else if(*p=='C')
            {
                p=p+2;
                while(*p)
                {
                    if(*p=='X')break;
                    p++;
                }p--;
                if(*p=='A')
                {
                    CX=CX-AX;
                }
                else if(*p=='B')
                {
                    CX=CX-BX;
                }
                else if(*p=='C')
                {
                    CX=CX-CX;
                }
                else
                {
                    CX=CX-DX;
                }
            }
            else if(*p=='D')
            {
                p=p+2;
                while(*p)
                {
                    if(*p=='X')break;
                    p++;
                }p--;
                if(*p=='A')
                {
                    DX=DX-AX;
                }
                else if(*p=='B')
                {
                    DX=DX-BX;
                }
                else if(*p=='C')
                {
                    DX=DX-CX;
                }
                else
                {
                    DX=DX-DX;
                }
            }

        }
        else if(s[0]=='D')
        {
            while(*p)
            {
                if(*p=='X')break;
                p++;
            }p--;
            if(*p=='A')
            {
                p=p+2;
                while(*p)
                {
                    if(*p=='X')break;
                    p++;
                }p--;
                if(*p=='A')
                {
                    AX=AX/AX;
                }
                else if(*p=='B')
                {
                    AX=AX/BX;
                }
                else if(*p=='C')
                {
                    AX=AX/CX;
                }
                else
                {
                    AX=AX/DX;
                }
            }
            else if(*p=='B')
            {
                p=p+2;
                while(*p)
                {
                    if(*p=='X')break;
                    p++;
                }p--;
                if(*p=='A')
                {
                    BX=BX/AX;
                }
                else if(*p=='B')
                {
                    BX=BX/BX;
                }
                else if(*p=='C')
                {
                    BX=BX/CX;
                }
                else
                {
                    BX=BX/DX;
                }
            }
            else if(*p=='C')
            {
                p=p+2;
                while(*p)
                {
                    if(*p=='X')break;
                    p++;
                }p--;
                if(*p=='A')
                {
                    CX=CX/AX;
                }
                else if(*p=='B')
                {
                    CX=CX/BX;
                }
                else if(*p=='C')
                {
                    CX=CX/CX;
                }
                else
                {
                    CX=CX/DX;
                }
            }
            else if(*p=='D')
            {
                p=p+2;
                while(*p)
                {
                    if(*p=='X')break;
                    p++;
                }p--;
                if(*p=='A')
                {
                    DX=DX/AX;
                }
                else if(*p=='B')
                {
                    DX=DX/BX;
                }
                else if(*p=='C')
                {
                    DX=DX/CX;
                }
                else
                {
                    DX=DX/DX;
                }
            }
        }
        else
        {
            while(*p)
            {
                if(*p=='X')
                    break;
                p++;
            }
            p--;
            if(*p=='A')
            {
                printf("%d",AX);
            }
            if(*p=='B')
            {
                printf("%d",BX);
            }
            if(*p=='C')
            {
                printf("%d",CX);
            }
            if(*p=='D')
            {
                printf("%d",DX);
            }
        }
    }
}