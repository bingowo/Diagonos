#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<string.h>
#include<math.h>


int main()
{
    int r[3] ={0};
    char mid[50];
    scanf("%s",mid);
    int po =0;
    while(mid[po]!=0)
    {
        int n = 0;
        int sym = 1;
        int k =0;
        if(mid[po]=='-')
        {
            sym=-1;
            po++;
        }
        else if(mid[po]=='+')po++;
        while(isdigit(mid[po]))
        {
            n = n*10+mid[po]-'0';
            po++;
        }
        if(mid[po]=='x')
        {
            k=1;
            if(n==0)n=1;
            po++;
            if(mid[po]=='^')
            {
                po++;
                k = 2;
                po++;
            }
        }
        r[k]=n*sym;
    }
    int a1,a2,c1,c2;
    int flag = 0;
    for(int i=1;i<=(int)(pow(r[2],1/2));i++)
    {
        if(r[2]%i==0)
        {
         a1 = i;a2=r[2]/i;
        if(r[0]==0)
        {
            if(r[1]%a1==0)
            {
                c2=r[1]/a1;
                c1 = 0;
                if(c1<=c2)
                {
                    if(a1==a2&&c1==c2);
                    else flag =1;
                }
            }
            else if(r[1]%a2==0)
            {
                c1=r[1]%a1;
                c2 = 0;
                if(c1<=c2)
                {
                    if(a1==a2&&c1==c2);
                    else flag =1;
                }
            }
        }
        else
            {
                for(int g = (-1)*(abs(r[0]));g<=r[0];g++)
                {
                    if(g!=0&&r[0]%g==0)
                    {
                        c1 = g;
                        c2 = r[0]/g;
                        if(c1<=c2)
                            {
                                if(a1==a2&&c1==c2);
                                else{
                                if(a1*c2+c1*a2==r[1])
                                {
                                    flag =1;
                                    break;
                                }
                            }
                         }
                    }
                }
            }
        }
        if(flag)break;
        }
        if(flag)printf("%d %d %d %d",a1,c1,a2,c2);
        else printf("No Answer!");

    return 0;
}
