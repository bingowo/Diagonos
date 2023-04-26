#include<stdio.h>
#include<stdlib.h>

int cmp(const void*a,const void*b)
{
    char c = *(char*)a;
    char d = *(char*)b;
    if(c<d)return -1;
    else return 1;
}

int main()
{
    char gene[3][3];
    scanf("%s%s%s",gene[0],gene[1],gene[2]);

    //以下为孩子未知；
    if(gene[2][0] == '?')
    {
       if(gene[0][0] == 'O'&&gene[1][0] == 'O') {gene[2][0] = 'O';printf("%s %s {O}",gene[0],gene[1]);}//父母均为O型；

       //以下为以父亲分大类；
       else if(gene[0][0] == 'A'&&gene[0][1] == 'B')//父亲为AB;
       {
           if(gene[1][0] == 'O'&&gene[1][1] == '\0'){printf("%s %s {A,B}",gene[0],gene[1]);}//母亲为O;
           else if(gene[1][0] == 'A'&&gene[1][1] == 'B'){printf("%s %s {A,AB,B}",gene[0],gene[1]);}//母亲为AB;
           else if(gene[1][0] == 'B'&&gene[1][1] == '\0'){printf("%s %s {A,AB,B}",gene[0],gene[1]);}//母亲为B;
           else if(gene[1][0] == 'A'&&gene[1][1] == '\0'){printf("%s %s {A,AB,B}",gene[0],gene[1]);}//母亲为A;
       }
       else if(gene[0][0] == 'A'&&gene[0][1] == '\0')//父亲为A；
       {
           if(gene[1][0] == 'A'&&gene[1][1] == '\0'){printf("%s %s {A,O}",gene[0],gene[1]);}//母亲为A;
           else if(gene[1][0] == 'B'&&gene[1][1] == '\0'){printf("%s %s {A,AB,B,O}",gene[0],gene[1]);}//母亲为B;
           else if(gene[1][0] == 'O'&&gene[1][1] == '\0'){printf("%s %s {A,O}",gene[0],gene[1]);}//母亲为O;
           else if(gene[1][0] == 'A'&&gene[1][1] == 'B'){printf("%s %s {A,AB,B}",gene[0],gene[1]);}//母亲为AB;
       }
       else if(gene[0][0] == 'B'&&gene[0][1] == '\0')//父亲为B；
       {
           if(gene[1][0] == 'O'&&gene[1][1] == '\0'){printf("%s %s {B,O}",gene[0],gene[1]);}//母亲为O;
           else if(gene[1][0] == 'B'&&gene[1][1] == '\0'){printf("%s %s {B,O}",gene[0],gene[1]);}//母亲为B;
           else if(gene[1][0] == 'A'&&gene[1][1] == '\0'){printf("%s %s {A,AB,B,O}",gene[0],gene[1]);}//母亲为A;
           else if(gene[1][0] == 'A'&&gene[1][1] == 'B'){printf("%s %s {A,AB,B}",gene[0],gene[1]);}//母亲为A;
       }


       //以下为以母亲分大类；
       else if(gene[1][0] == 'A'&&gene[1][1] == 'B')//母亲为AB;
       {
           if(gene[0][0] == 'O'&&gene[0][1] == '\0'){printf("%s %s {A,B}",gene[0],gene[1]);}//父亲为O;
           else if(gene[0][0] == 'B'&&gene[0][1] == '\0'){printf("%s %s {A,AB,B}",gene[0],gene[1]);}//父亲为B;
           else if(gene[0][0] == 'A'&&gene[0][1] == '\0'){printf("%s %s {A,AB,B}",gene[0],gene[1]);}//父亲为A;
       }
       else if(gene[1][0] == 'A'&&gene[1][1] == '\0')//母亲为A；
       {
           if(gene[0][0] == 'B'&&gene[0][1] == '\0'){printf("%s %s {A,AB,B,O}",gene[0],gene[1]);}//父亲为B;
           else if(gene[0][0] == 'O'&&gene[0][1] == '\0'){printf("%s %s {A,O}",gene[0],gene[1]);}//父亲为O;
       }
       else if(gene[1][0] == 'B'&&gene[1][1] == '\0')//母亲为B；
       {
           if(gene[0][0] == 'O'&&gene[0][1] == '\0'){printf("%s %s {B,O}",gene[0],gene[1]);}//父亲为O;
       }
    }

    //以下为父亲未知；
    else if(gene[0][0] == '?')
    {
        if(gene[1][0] == 'A'&&gene[1][1] == '\0')//母亲为A;
        {
             if(gene[2][0] == 'A'&&gene[2][1] == '\0'){printf("{A,AB,B,O} %s %s",gene[1],gene[2]);}//孩子为A;
            else if(gene[2][0] == 'B'&&gene[2][1] == '\0'){printf("{AB,B} %s %s",gene[1],gene[2]);}//孩子为B;
            else if(gene[2][0] == 'A'&&gene[2][1] == 'B'){printf("{AB,B} %s %s",gene[1],gene[2]);}//孩子为AB;
            else if(gene[2][0] == 'O'&&gene[2][1] == '\0'){printf("{A,B,O} %s %s",gene[1],gene[2]);}//孩子为O;
        }
         else if(gene[1][0] == 'B'&&gene[1][1] == '\0')//母亲为B;
        {
             if(gene[2][0] == 'A'&&gene[2][1] == '\0'){printf("{A,AB} %s %s",gene[1],gene[2]);}//孩子为A;
            else if(gene[2][0] == 'B'&&gene[2][1] == '\0'){printf("{A,AB,B,O} %s %s",gene[1],gene[2]);}//孩子为B;
            else if(gene[2][0] == 'A'&&gene[2][1] == 'B'){printf("{A,AB} %s %s",gene[1],gene[2]);}//孩子为AB;
            else if(gene[2][0] == 'O'&&gene[2][1] == '\0'){printf("{A,B,O} %s %s",gene[1],gene[2]);}//孩子为O;
        }
        else if(gene[1][0] == 'A'&&gene[1][1] == 'B')//母亲为AB;
        {
             if(gene[2][0] == 'A'&&gene[2][1] == '\0'){printf("{A,AB,B,O} %s %s",gene[1],gene[2]);}//孩子为A;
            else if(gene[2][0] == 'B'&&gene[2][1] == '\0'){printf("{A,AB,B,O} %s %s",gene[1],gene[2]);}//孩子为B;
            else if(gene[2][0] == 'A'&&gene[2][1] == 'B'){printf("{A,AB,B} %s %s",gene[1],gene[2]);}//孩子为AB;
            else if(gene[2][0] == 'O'&&gene[2][1] == '\0'){printf("impossible %s %s",gene[1],gene[2]);}//孩子为O;
        }
        else if(gene[1][0] == 'O'&&gene[1][1] == '\0')//母亲为O;
        {
             if(gene[2][0] == 'A'&&gene[2][1] == '\0'){printf("{A,AB} %s %s",gene[1],gene[2]);}//孩子为A;
            else if(gene[2][0] == 'B'&&gene[2][1] == '\0'){printf("{AB,B} %s %s",gene[1],gene[2]);}//孩子为B;
            else if(gene[2][0] == 'A'&&gene[2][1] == 'B'){printf("impossible %s %s",gene[1],gene[2]);}//孩子为AB;
            else if(gene[2][0] == 'O'&&gene[2][1] == '\0'){printf("{A,B,O} %s %s",gene[1],gene[2]);}//孩子为O;
        }
    }

    //以下为母亲未知；
    else if(gene[1][0] == '?')
    {
        if(gene[0][0] == 'A'&&gene[0][1] == '\0')//父亲为A;
        {
             if(gene[2][0] == 'A'&&gene[2][1] == '\0'){printf("%s {A,AB,B,O} %s",gene[0],gene[2]);}//孩子为A;
            else if(gene[2][0] == 'B'&&gene[2][1] == '\0'){printf("%s {AB,B} %s",gene[0],gene[2]);}//孩子为B;
            else if(gene[2][0] == 'A'&&gene[2][1] == 'B'){printf("%s {AB,B} %s",gene[0],gene[2]);}//孩子为AB;
            else if(gene[2][0] == 'O'&&gene[2][1] == '\0'){printf("%s {A,B,O} %s",gene[0],gene[2]);}//孩子为O;
        }
         else if(gene[0][0] == 'B'&&gene[0][1] == '\0')//父亲为B;
        {
             if(gene[2][0] == 'A'&&gene[2][1] == '\0'){printf("%s {A,AB} %s",gene[0],gene[2]);}//孩子为A;
            else if(gene[2][0] == 'B'&&gene[2][1] == '\0'){printf("%s {A,AB,B,O} %s",gene[0],gene[2]);}//孩子为B;
            else if(gene[2][0] == 'A'&&gene[2][1] == 'B'){printf("%s {A,AB} %s",gene[0],gene[2]);}//孩子为AB;
            else if(gene[2][0] == 'O'&&gene[2][1] == '\0'){printf("%s {A,B,O} %s",gene[0],gene[2]);}//孩子为O;
        }
        else if(gene[0][0] == 'A'&&gene[0][1] == 'B')//父亲为AB;
        {
             if(gene[2][0] == 'A'&&gene[2][1] == '\0'){printf("%s {A,AB,B,O} %s",gene[0],gene[2]);}//孩子为A;
            else if(gene[2][0] == 'B'&&gene[2][1] == '\0'){printf("%s {A,AB,B,O} %s",gene[0],gene[2]);}//孩子为B;
            else if(gene[2][0] == 'A'&&gene[2][1] == 'B'){printf("%s {A,AB,B} %s",gene[0],gene[2]);}//孩子为AB;
            else if(gene[2][0] == 'O'&&gene[2][1] == '\0'){printf("%s impossible %s",gene[0],gene[2]);}//孩子为O;
        }
        else if(gene[0][0] == 'O'&&gene[0][1] == '\0')//父亲为O;
        {
             if(gene[2][0] == 'A'&&gene[2][1] == '\0'){printf("%s {A,AB} %s",gene[0],gene[2]);}//孩子为A;
            else if(gene[2][0] == 'B'&&gene[2][1] == '\0'){printf("%s {AB,B} %s",gene[0],gene[2]);}//孩子为B;
            else if(gene[2][0] == 'A'&&gene[2][1] == 'B'){printf("%s impossible %s",gene[0],gene[2]);}//孩子为AB;
            else if(gene[2][0] == 'O'&&gene[2][1] == '\0'){printf("%s {A,B,O} %s",gene[0],gene[2]);}//孩子为O;
        }
    }

    return 0;
}
