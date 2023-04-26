#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char dad[11],mom[11],kid[11];
    scanf("%s %s %s",dad,mom,kid);
    int dad_len=strlen(dad),mom_len=strlen(mom),kid_len=strlen(kid);
    if(kid[0]=='?')
    {
        if(dad_len==2&&mom_len==2)
        {
            kid[0]='{';kid[1]='A';kid[2]=',';kid[3]='A';
            kid[4]='B';kid[5]=',';kid[6]='B';kid[7]='}';
            kid[8]='\0';
        }
        else if((dad_len==2&&mom[0]=='A')||(dad[0]=='A'&&mom_len==2))
        {
            kid[0]='{';kid[1]='A';kid[2]=',';kid[3]='A';
            kid[4]='B';kid[5]='}';kid[6]='\0';
        }
        else if((dad_len==2&&mom[0]=='B')||(dad[0]=='B'&&mom_len==2))
        {
            kid[0]='{';kid[1]='A';kid[2]=',';kid[3]='A';
            kid[4]='B';kid[5]='}';kid[6]='\0';
        }
        else if((dad_len==2&&mom[0]=='O')||(dad[0]=='O'&&mom_len==2))
        {
            kid[0]='{';kid[1]='A';kid[2]=',';kid[3]='B';
            kid[4]='}';kid[5]='\0';
        }
        else if(dad_len==1&&mom_len==1)
        {
            if(dad[0]=='O'&&mom[0]=='O')
            {
                kid[0]='{';kid[1]='O';kid[2]='}';kid[3]='\0';
            }
            if((dad[0]=='A'&&mom[0]=='A')||(dad[0]=='A'&&mom[0]=='O')||(dad[0]=='O'&&mom[0]=='A'))
            {
                kid[0]='{';kid[1]='A';kid[2]=',';kid[3]='O';
                kid[4]='}';kid[5]='\0';
            }
            if((dad[0]=='B'&&mom[0]=='B')||(dad[0]=='B'&&mom[0]=='O')||(dad[0]=='O'&&mom[0]=='B'))
            {
                kid[0]='{';kid[1]='B';kid[2]=',';kid[3]='O';
                kid[4]='}';kid[5]='\0';
            }
            if((dad[0]=='A'&&mom[0]=='B')||(dad[0]=='B'&&mom[0]=='A'))
            {
                kid[0]='{';kid[1]='A';kid[2]=',';kid[3]='A';
                kid[4]='B';kid[5]=',';kid[6]='B';kid[7]=',';
                kid[8]='O';kid[9]='}';kid[10]='\0';
            }
        }
    }
    else
    {
        if(kid_len==2)
        {
            if(dad_len==2)
            {
                mom[0]='{';mom[1]='A';mom[2]=',';mom[3]='A';
                mom[4]='B';mom[5]=',';mom[6]='B';mom[7]='}';
                mom[8]='\0';
            }
            if(mom_len==2)
            {
                dad[0]='{';dad[1]='A';dad[2]=',';dad[3]='A';
                dad[4]='B';dad[5]=',';dad[6]='B';dad[7]='}';
                dad[8]='\0';
            }
            if(dad_len==1&&mom_len==1)
            {
                if(dad[0]=='A')
                {
                    mom[0]='{';mom[1]='A';mom[2]='B';mom[3]=',';
                    mom[4]='B';mom[5]='}';mom[6]='\0';
                }
                if(mom[0]=='A')
                {
                    dad[0]='{';dad[1]='A';dad[2]='B';dad[3]=',';
                    dad[4]='B';dad[5]='}';dad[6]='\0';
                }
                if(dad[0]=='B')
                {
                    mom[0]='{';mom[1]='A';mom[2]=',';mom[3]='A';
                    mom[4]='B';mom[5]='}';mom[6]='\0';
                }
                if(mom[0]=='B')
                {
                    dad[0]='{';dad[1]='A';dad[2]=',';dad[3]='A';
                    dad[4]='B';dad[5]='}';dad[6]='\0';
                }
                if(dad[0]=='O') strcpy(mom,"impossible");
                if(mom[0]=='O') strcpy(dad,"impossible");
            }
        }
        else if(kid_len==1)
        {

            if(kid[0]=='O')
            {
                if(dad_len==2) strcpy(mom,"impossible");
                if(mom_len==2) strcpy(dad,"impossible");
                if(dad_len==1&&mom_len==1)
                {
                    if(dad[0]=='?')
                    {
                        dad[0]='{';dad[1]='A';dad[2]=',';dad[3]='B';
                        dad[4]=',';dad[5]='O';dad[6]='}';dad[7]='\0';
                    }
                    if(mom[0]=='?')
                    {
                        mom[0]='{';mom[1]='A';mom[2]=',';mom[3]='B';
                        mom[4]=',';mom[5]='O';mom[6]='}';mom[7]='\0';
                    }
                }
            }
            if(kid[0]=='A')
            {
                if(dad_len==2||(dad_len==1&&dad[0]=='A'))
                {
                    mom[0]='{';mom[1]='A';mom[2]=',';mom[3]='A';
                    mom[4]='B';mom[5]=',';mom[6]='B';mom[7]=',';
                    mom[8]='O';mom[9]='}';mom[10]='\0';
                }
                if(mom_len==2||(mom_len==1&&mom[0]=='A'))
                {
                    dad[0]='{';dad[1]='A';dad[2]=',';dad[3]='A';
                    dad[4]='B';dad[5]=',';dad[6]='B';dad[7]=',';
                    dad[8]='O';dad[9]='}';dad[10]='\0';
                }
                if((dad_len==1&&dad[0]=='O')||(dad_len==1&&dad[0]=='B'))
                {
                    mom[0]='{';mom[1]='A';mom[2]=',';mom[3]='A';
                    mom[4]='B';mom[5]='}';mom[6]='\0';
                }
                if((mom_len==1&&mom[0]=='O')||(mom_len==1&&mom[0]=='B'))
                {
                    dad[0]='{';dad[1]='A';dad[2]=',';dad[3]='A';
                    dad[4]='B';dad[5]='}';dad[6]='\0';
                }
            }
            if(kid[0]=='B')
            {
                if(dad_len==2||(dad_len==1&&dad[0]=='B'))
                {
                    mom[0]='{';mom[1]='A';mom[2]=',';mom[3]='A';
                    mom[4]='B';mom[5]=',';mom[6]='B';mom[7]=',';
                    mom[8]='O';mom[9]='}';mom[10]='\0';
                }
                if(mom_len==2||(mom_len==1&&mom[0]=='B'))
                {
                    dad[0]='{';dad[1]='A';dad[2]=',';dad[3]='A';
                    dad[4]='B';dad[5]=',';dad[6]='B';dad[7]=',';
                    dad[8]='O';dad[9]='}';dad[10]='\0';
                }
                if((dad_len==1&&dad[0]=='O')||(dad_len==1&&dad[0]=='A'))
                {
                    mom[0]='{';mom[1]='A';mom[2]='B';mom[3]=',';
                    mom[4]='B';mom[5]='}';mom[6]='\0';
                }
                if((mom_len==1&&mom[0]=='O')||(mom_len==1&&mom[0]=='A'))
                {
                    dad[0]='{';dad[1]='A';dad[2]='B';dad[3]=',';
                    dad[4]='B';dad[5]='}';dad[6]='\0';
                }
            }
        }
    }
    printf("%s %s %s\n",dad,mom,kid);
    return 0;
}
