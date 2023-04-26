#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char s[120];
    int shu[120];
    int len;
}lie;


lie fuzhi(lie a)
{
    int i;
    for(i=0;i<a.len;i++)
    {
        switch(a.s[i])
        {
            case 'R': a.shu[i]=1;break;
            case 'B': a.shu[i]=3;break;
            case 'Y': a.shu[i]=5;break;
            case 'G': a.shu[i]=7;break;
            case '!': a.shu[i]=0;break;
            default: break;
        }
    }
    return a;
}

int find0(lie a)
{
    int i;
    for(i=0;i<a.len;i++)
    {
        if(a.shu[i]==0) return 1;
    }
    return 0;
}


int main()
{
    int i,t;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        lie a;
        int j;
        memset(a.shu,0,sizeof(int)*120);
        int r=0,b=0,y=0,g=0;
        scanf("%s",a.s);
        a.len=strlen(a.s);
        a=fuzhi(a);
        while(find0(a))
        {
            for(j=0;j<a.len-3;j++)
            {
                int sum;
                sum=a.shu[j]+a.shu[j+1]+a.shu[j+2]+a.shu[j+3];
                //printf("test:sum=%d,[%d]=%d,[%d]=%d,[%d]=%d,[%d]=%d\n",sum,j,a.shu[j],j+1,a.shu[j+1],j+2,a.shu[j+2],j+3,a.shu[j+3]);
                if((sum>=9)&&(sum%2)&&(sum<16))
                {
                    if(a.shu[j]==0) a.shu[j]=16-sum;
                    else if(a.shu[j+1]==0) a.shu[j+1]=16-sum;
                    else if(a.shu[j+2]==0) a.shu[j+2]=16-sum;
                    else if(a.shu[j+3]==0) a.shu[j+3]=16-sum;

                    if(sum==15) r++;
                    else if(sum==13) b++;
                    else if(sum==11) y++;
                    else if(sum==9) g++;
                }

            }
        }
        printf("case #%d:\n",i);
        printf("%d %d %d %d\n",r,b,y,g);

    }
    return 0;
}
