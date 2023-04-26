#include <stdio.h>
#include <ctype.h>

void ReadPoly(int n[], char s[] )
{
    char *p = s;
    int sgn,coe,exp;
    int isConst,isMonomial;
    while(*p)
    {
        sgn=1,coe=0,exp=0;
        isConst=1,isMonomial=1;
        if(*p=='+' || *p=='-')
        {
            if(*p=='-') sgn=-1;
            p++;
        } 
        if(isdigit(*p))
        {
            while(isdigit(*p))
            {
                coe=coe*10 + *p - '0';
                p++;
            }
            coe*=sgn;
        }
        if(*p == 'x')
        {
            if(coe == 0) coe=1*sgn;
            isConst = 0;
            p++;
        }
        if(*p == '^')
        {
            isMonomial = 0;
            p++;
        }
        if(isdigit(*p))
        {
        while(isdigit(*p))
            {
                exp=exp*10 + *p - '0';
                p++;
            }
        }
        if(isConst)  n[0]=coe;
        else if(isMonomial) n[1]=coe;
        else n[exp]=coe;
    }
    return ;
}
int main()
{
    char s1[101] , s2[101];
    while(scanf("%s %s",s1,s2)!= EOF)
    {
        int poly1[50]={0}, poly2[50]={0}, poly[99]={0};
        ReadPoly(poly1, s1);
        ReadPoly(poly2, s2);
        for(int i=49; i>=0; i--)
        {
            //if (poly1[i]==0) continue;
            for(int j=49; j>=0; j--)
            {
                poly[i+j]+= poly1[i] * poly2[j];
            }
        }
        for(int i=98; i>=0; i--)
        {
            if(poly[i]==0) continue;
            else printf("%d ",poly[i]);
        }
        printf("\n");
    }
    return 0;
}