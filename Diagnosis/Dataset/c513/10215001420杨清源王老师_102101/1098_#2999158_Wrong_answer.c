#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int check(char *str, char *str2)
{
    int ret=1;
    for(int i=0,n=strlen(str); i<n&&ret; i++)
    {
        if(str[i]=='!') continue;
        if(str[i]!=str2[i]) ret=0;
    }
    return ret;
}

int main()
{
    int cas;
    scanf("%d",&cas);
    for(int m=0; m<cas; m++)
    {
        //ABCDEFGH中A=H，B=E……
        char c[5]="RGBY";
        char head[24][5];
        int cnt=0;
        for(int i1=0; i1<4; i1++)
        {
            for(int i2=0; i2<4; i2++)
            {
                if(i1==i2)
                    continue;
                for(int i3=0; i3<4; i3++)
                {
                    if(i3==i2||i3==i1)
                        continue;
                    for(int i4=0; i4<4; i4++)
                    {
                        if(i4==i3||i4==i2||i4==i1)
                            continue;
                        head[cnt][0]=c[i1];
                        head[cnt][1]=c[i2];
                        head[cnt][2]=c[i3];
                        head[cnt][3]=c[i4];
                    }
                }
            }
        }

        char str[120],str2[120];
        scanf("%s",str);
        int kr=0,kg=0,kb=0,ky=0;
        int n=strlen(str);
        for(int h=0; h<24; h++)
        {
            for(int i=0; i<n; i++)
            {
                str2[i]=head[h][i%4];
                if(check(str,str2))
                {
                    for(int j=0; j<n; j++)
                    {
                        if(str[j]=='!')
                        {
                            if(str2[j]=='R')
                                kr++;
                            if(str2[j]=='G')
                                kg++;
                            if(str2[j]=='B')
                                kb++;
                            if(str2[j]=='Y')
                                ky++;
                        }
                    }
                }
            }
        }
        printf("case #%d:\n",m);
        printf("%d %d %d %d\n",kr,kg,kb,ky);
    }


}
