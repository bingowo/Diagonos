#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int mayadatecmp(void *a,void *b)
{
    char table[20][7]={"pop","no","zip","zotz","tzec","xul","yoxkin",
    "mol","chen","yax","zac","ceh","mac","kankin","mua","pax","koyab","cumhu","uayet"},montha[7],monthb[7];
    short lena=0,lenb=0,yeara=0,yearb=0,base=1,ma=0,mb=0,daya=0,dayb=0;
    lena=strlen((char*)a);
    lenb=strlen((char*)b);
    for(;;lena--)
    {
        if(*((char*)a+lena-1)==' ') break;
        yeara+=(*((char*)a+lena-1)-48)*base;
        base*=10;
    }
    base=1;
    for(;;lenb--)
    {
        if(*((char*)b+lenb-1)==' ') break;
        yearb+=(*((char*)b+lenb-1)-48)*base;
        base*=10;
    }
    if(yeara!=yearb) return yeara-yearb;
    for(;;lena--)
    {
        short i=0;
        if(*((char*)a+lena-1)==' ') break;
        montha[i++]=*((char*)a+lena-1);
    }
    for(short i=0;i<19;i++)
    {
        short j=0,c=0;
        short lenma=strlen(montha);
        while(1)
        {
            if(table[i][j++]!=montha[lenma-j-1]) break;
            if(!(lenma-j-1))
            {
                c=1;
                break;
            }
        }
        if(c)
            ma=i;
    }
    for(;;lenb--)
    {
        short i=0;
        if(*((char*)b+lenb-1)==' ') break;
        monthb[i++]=*((char*)b+lenb-1);
    }
    for(short i=0;i<19;i++)
    {
        short j=0,c=0;
        short lenmb=strlen(monthb);
        while(1)
        {
            if(table[i][j++]!=monthb[lenmb-j-1]) break;
            if(!(lenmb-j-1))
            {
                c=1;
                break;
            }
        }
        if(c)
            mb=i;
    }
    if(ma!=mb) return ma-mb;
    base=1;
    for(;;lena--)
    {
        if(*((char*)a+lena-1)<='9'&&*((char*)a+lena-1)>='0')
        {
            while(lena)
            {
                base*=10;
                daya+=(*((char*)a+lena-1)-48)*base;
                lena--;
            }
            break;
        }
    }
    base=1;
    for(;;lenb--)
    {
        if(*((char*)b+lenb-1)<='9'&&*((char*)b+lenb-1)>='0')
        {
            while(lenb)
            {
                base*=10;
                dayb+=(*((char*)b+lenb-1)-48)*base;
                lenb--;
            }
        }
    }
    return daya-dayb;
}

int main()
{
    short T=0,N=0,i=0;
    scanf("%hd",&T);
    for(i=0;i<T;i++)
        {
            short j=0;
            char date[10000][20];
            scanf("%hd",&N);
            for(i=0;j<N;j++)
                scanf("%s",date[i]);
            qsort(date,N,20,mayadatecmp);
            printf("case #%hd:\n",i);
            for(i=0;j<N;j++)
                printf("%s\n",date[i]);
        }
}
