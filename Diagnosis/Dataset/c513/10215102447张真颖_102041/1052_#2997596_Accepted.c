#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int T=0;
    scanf("%d",&T);
    for(int cas=0;cas<T;cas++)
    {
        char s[21]={0};
        scanf("%s",s);
        int code[10]={0},num[127]={0};
        for(int i=0;i<strlen(s);i++)
            num[s[i]]+=1;

        //有z必为zero
        int t=num['Z'];
        num['Z']=0;
        num['E']-=t;
        num['R']-=t;
        num['O']-=t;
        code[0]=t;
        //有x必为six
        t=num['X'];
        num['X']=0;
        num['S']-=t;
        num['I']-=t;
        code[6]=t;
        //有s为seven
        t=num['S'];
        num['S']=0;
        num['E']-=2*t;
        num['V']-=t;
        num['N']-=t;
        code[7]=t;
        //有v必为five
        t=num['V'];
        num['V']=0;
        num['E']-=t;
        num['I']-=t;
        num['F']-=t;
        code[5]=t;
        //有f必为four
        t=num['F'];
        num['F']=0;
        num['O']-=t;
        num['U']-=t;
        num['R']-=t;
        code[4]=t;
        //有r必为three
        t=num['R'];
        num['R']=0;
        num['E']-=2*t;
        num['T']-=t;
        num['H']-=t;
        code[3]=t;
        //有h必为eight
        t=num['H'];
        num['H']=0;
        num['E']-=t;
        num['I']-=t;
        num['G']-=t;
        num['T']-=t;
        code[8]=t;
        //有i必为nine
        t=num['I'];
        num['I']=0;
        num['E']-=t;
        num['N']-=2*t;
        code[9]=t;
        //有n必为one
        t=num['N'];
        num['N']=0;
        num['E']-=t;
        num['O']-=t;
        code[1]=t;
        //有t必为two
        t=num['T'];
        num['T']=0;
        num['W']-=t;
        num['O']-=t;
        code[2]=t;

        printf("case #%d:\n",cas);
        for(int i=0;i<10;i++)
            for(int j=0;j<code[i];j++)
               printf("%d",i);
        printf("\n");
    }
    return 0;
}