#include <stdio.h>
#include <stdlib.h>

int main()
{
    char command[4];
    char conduct[10];
    int Ax,Bx,Cx,Dx;
    char register1[3],register2[3];
    while(scanf("%s",command) == 1)
    {
        if(strcmp(command,"IN") == 0)
        {
            scanf("%s",conduct);
            sscanf(conduct,"%d",Ax);
        }
        else if(strcmp(command,"MOV") == 0)
        {
            scanf("%s,%s",register1,register2);
            if(strcmp(register1,"Ax") == 0)
            {
                if(strcmp(register2,"Ax") == 0)
                    Ax = Ax;
                else if(strcmp(register2,"Bx") == 0)
                    Ax = Bx;
                else if(strcmp(register2,"Cx") == 0)
                    Ax = Cx;
                else if(strcmp(register2,"Dx") == 0)
                    Ax = Dx;
            }
            else if(strcmp(register1,"Bx") == 0)
            {
                if(strcmp(register2,"Ax") == 0)
                    Bx = Ax;
                else if(strcmp(register2,"Bx") == 0)
                    Bx = Bx;
                else if(strcmp(register2,"Cx") == 0)
                    Bx = Cx;
                else if(strcmp(register2,"Dx") == 0)
                    Bx = Dx;
            }
            else if(strcmp(register1,"Cx") == 0)
            {
                if(strcmp(register2,"Ax") == 0)
                    Cx = Ax;
                else if(strcmp(register2,"Bx") == 0)
                    Cx = Bx;
                else if(strcmp(register2,"Cx") == 0)
                    Cx = Cx;
                else if(strcmp(register2,"Dx") == 0)
                    Cx = Dx;
            }
            else if(strcmp(register1,"Dx") == 0)
            {
                if(strcmp(register2,"Ax") == 0)
                    Dx = Ax;
                else if(strcmp(register2,"Bx") == 0)
                    Dx = Bx;
                else if(strcmp(register2,"Cx") == 0)
                    Dx = Cx;
                else if(strcmp(register2,"Dx") == 0)
                    Dx = Dx;
            }
        }
        else if(strcmp(command,"ADD") == 0)
        {
            scanf("%s,%s",register1,register2);
            if(strcmp(register1,"Ax") == 0)
            {
                if(strcmp(register2,"Ax") == 0)
                    Ax += Ax;
                else if(strcmp(register2,"Bx") == 0)
                    Ax += Bx;
                else if(strcmp(register2,"Cx") == 0)
                    Ax += Cx;
                else if(strcmp(register2,"Dx") == 0)
                    Ax += Dx;
            }
            else if(strcmp(register1,"Bx") == 0)
            {
                if(strcmp(register2,"Ax") == 0)
                    Bx += Ax;
                else if(strcmp(register2,"Bx") == 0)
                    Bx += Bx;
                else if(strcmp(register2,"Cx") == 0)
                    Bx += Cx;
                else if(strcmp(register2,"Dx") == 0)
                    Bx += Dx;
            }
            else if(strcmp(register1,"Cx") == 0)
            {
                if(strcmp(register2,"Ax") == 0)
                    Cx += Ax;
                else if(strcmp(register2,"Bx") == 0)
                    Cx += Bx;
                else if(strcmp(register2,"Cx") == 0)
                    Cx += Cx;
                else if(strcmp(register2,"Dx") == 0)
                    Cx += Dx;
            }
            else if(strcmp(register1,"Dx") == 0)
            {
                if(strcmp(register2,"Ax") == 0)
                    Dx += Ax;
                else if(strcmp(register2,"Bx") == 0)
                    Dx += Bx;
                else if(strcmp(register2,"Cx") == 0)
                    Dx += Cx;
                else if(strcmp(register2,"Dx") == 0)
                    Dx += Dx;
            }
        }
        else if(strcmp(command,"SUB") == 0)
        {
            scanf("%s,%s",register1,register2);
            if(strcmp(register1,"Ax") == 0)
            {
                if(strcmp(register2,"Ax") == 0)
                    Ax -= Ax;
                else if(strcmp(register2,"Bx") == 0)
                    Ax -= Bx;
                else if(strcmp(register2,"Cx") == 0)
                    Ax -= Cx;
                else if(strcmp(register2,"Dx") == 0)
                    Ax -= Dx;
            }
            else if(strcmp(register1,"Bx") == 0)
            {
                if(strcmp(register2,"Ax") == 0)
                    Bx -= Ax;
                else if(strcmp(register2,"Bx") == 0)
                    Bx -= Bx;
                else if(strcmp(register2,"Cx") == 0)
                    Bx -= Cx;
                else if(strcmp(register2,"Dx") == 0)
                    Bx -= Dx;
            }
            else if(strcmp(register1,"Cx") == 0)
            {
                if(strcmp(register2,"Ax") == 0)
                    Cx -= Ax;
                else if(strcmp(register2,"Bx") == 0)
                    Cx -= Bx;
                else if(strcmp(register2,"Cx") == 0)
                    Cx -= Cx;
                else if(strcmp(register2,"Dx") == 0)
                    Cx -= Dx;
            }
            else if(strcmp(register1,"Dx") == 0)
            {
                if(strcmp(register2,"Ax") == 0)
                    Dx -= Ax;
                else if(strcmp(register2,"Bx") == 0)
                    Dx -= Bx;
                else if(strcmp(register2,"Cx") == 0)
                    Dx -= Cx;
                else if(strcmp(register2,"Dx") == 0)
                    Dx -= Dx;
            }
        }
        else if(strcmp(command,"MUL") == 0)
        {
            scanf("%s,%s",register1,register2);
            if(strcmp(register1,"Ax") == 0)
            {
                if(strcmp(register2,"Ax") == 0)
                    Ax *= Ax;
                else if(strcmp(register2,"Bx") == 0)
                    Ax *= Bx;
                else if(strcmp(register2,"Cx") == 0)
                    Ax *= Cx;
                else if(strcmp(register2,"Dx") == 0)
                    Ax *= Dx;
            }
            else if(strcmp(register1,"Bx") == 0)
            {
                if(strcmp(register2,"Ax") == 0)
                    Bx *= Ax;
                else if(strcmp(register2,"Bx") == 0)
                    Bx *= Bx;
                else if(strcmp(register2,"Cx") == 0)
                    Bx *= Cx;
                else if(strcmp(register2,"Dx") == 0)
                    Bx *= Dx;
            }
            else if(strcmp(register1,"Cx") == 0)
            {
                if(strcmp(register2,"Ax") == 0)
                    Cx *= Ax;
                else if(strcmp(register2,"Bx") == 0)
                    Cx *= Bx;
                else if(strcmp(register2,"Cx") == 0)
                    Cx *= Cx;
                else if(strcmp(register2,"Dx") == 0)
                    Cx *= Dx;
            }
            else if(strcmp(register1,"Dx") == 0)
            {
                if(strcmp(register2,"Ax") == 0)
                    Dx *= Ax;
                else if(strcmp(register2,"Bx") == 0)
                    Dx *= Bx;
                else if(strcmp(register2,"Cx") == 0)
                    Dx *= Cx;
                else if(strcmp(register2,"Dx") == 0)
                    Dx *= Dx;
            }
        }
        else if(strcmp(command,"DIV") == 0)
        {
            scanf("%s,%s",register1,register2);
            if(strcmp(register1,"Ax") == 0)
            {
                if(strcmp(register2,"Ax") == 0)
                    Ax /= Ax;
                else if(strcmp(register2,"Bx") == 0)
                    Ax /= Bx;
                else if(strcmp(register2,"Cx") == 0)
                    Ax /= Cx;
                else if(strcmp(register2,"Dx") == 0)
                    Ax /= Dx;
            }
            else if(strcmp(register1,"Bx") == 0)
            {
                if(strcmp(register2,"Ax") == 0)
                    Bx /= Ax;
                else if(strcmp(register2,"Bx") == 0)
                    Bx /= Bx;
                else if(strcmp(register2,"Cx") == 0)
                    Bx /= Cx;
                else if(strcmp(register2,"Dx") == 0)
                    Bx /= Dx;
            }
            else if(strcmp(register1,"Cx") == 0)
            {
                if(strcmp(register2,"Ax") == 0)
                    Cx /= Ax;
                else if(strcmp(register2,"Bx") == 0)
                    Cx /= Bx;
                else if(strcmp(register2,"Cx") == 0)
                    Cx /= Cx;
                else if(strcmp(register2,"Dx") == 0)
                    Cx /= Dx;
            }
            else if(strcmp(register1,"Dx") == 0)
            {
                if(strcmp(register2,"Ax") == 0)
                    Dx /= Ax;
                else if(strcmp(register2,"Bx") == 0)
                    Dx /= Bx;
                else if(strcmp(register2,"Cx") == 0)
                    Dx /= Cx;
                else if(strcmp(register2,"Dx") == 0)
                    Dx /= Dx;
            }
        }
        else if(strcmp(command,"OUT") == 0)
        {
            scanf("%s",register1);
            if(strcmp(register1,"Ax") == 0)
                printf("%d",Ax);
            else if(strcmp(register1,"Bx") == 0)
                printf("%d",Bx);
            else if(strcmp(register1,"Cx") == 0)
                printf("%d",Cx);
            else if(strcmp(register1,"Dx") == 0)
                printf("%d",Dx);
        }
    }
    return 0;
}