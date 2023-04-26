#include<stdio.h>
#include<string.h>

int main()
{
    int t;scanf("%d",&t);getchar();
    for(int i=0;i<t;i++)
    {
        char line[121];gets(line);
        int l=strlen(line),fz=0,fm=0,gcd,tmp;
        for(int p=0;p<l;p++)
        {
            int time=0;
            while (time!=8)
            {
                fz+=line[p]&1;
                line[p]>>=1;
                time++;
            }            
        }
        fm=8*l,gcd=8*l,tmp=fz;
        while(tmp!=0)
        {
            int c=gcd%tmp;
            gcd=tmp;tmp=c;
        }
        printf("%d/%d\n",fz/gcd,fm/gcd);
    }

    return 0;
}