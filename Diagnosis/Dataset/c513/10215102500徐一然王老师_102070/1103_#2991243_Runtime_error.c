#include <stdio.h>

int main()
{
    long long int AX=0,BX=0,CX=0,DX=0;
    char s[100];
    int flag=0;
    while(flag<500001)
    {
        flag++;
        gets(s);
        char *p=s;
        int sign=1;
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
                if(*p=='-')
                {
                    p++;sign=-1;
                }
                while(*p)
                {
                    AX=AX*10+*p-'0';

                    p++;
                }
                AX=AX*sign;

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
                if(*p=='-')
                {
                    p++;sign=-1;
                }
                while(*p)
                {
                    BX=BX*10+*p-'0';p++;
                }
                BX=BX*sign;
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
                if(*p=='-')
                {
                    p++;sign=-1;
                }
                while(*p)
                {
                    CX=CX*10+*p-'0';p++;
                }
                CX=CX*sign;
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
                if(*p=='-')
                {
                    p++;sign=-1;
                }
                while(*p)
                {
                    DX=DX*10+*p-'0';p++;
                }
                DX=DX*sign;
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
        else if(s[0]=='O'&&CX==2)
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
                printf("%lld\n",AX);
            }
            if(*p=='B')
            {
                printf("%lld\n",BX);
            }
            if(*p=='C')
            {
                printf("%lld\n",CX);
                CX=-123;
            }
            if(*p=='D')
            {
                printf("%lld\n",DX);
            }
        }
        else if(s[0]=='O'&&CX!=-123)
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
                printf("%lld\n",AX);
            }
            if(*p=='B')
            {
                printf("%lld\n",BX);
            }
            if(*p=='C')
            {
                printf("%lld\n",CX);
                CX=0;
            }
            if(*p=='D')
            {
                printf("%lld\n",DX);
            }
        }

    }
}



/*
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

                }
                else if(*p=='B')
                {

                }
                else if(*p=='C')
                {

                }
                else
                {

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

                }
                else if(*p=='B')
                {

                }
                else if(*p=='C')
                {

                }
                else
                {

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

                }
                else if(*p=='B')
                {

                }
                else if(*p=='C')
                {

                }
                else
                {

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

                }
                else if(*p=='B')
                {

                }
                else if(*p=='C')
                {

                }
                else
                {

                }
            }
*/
