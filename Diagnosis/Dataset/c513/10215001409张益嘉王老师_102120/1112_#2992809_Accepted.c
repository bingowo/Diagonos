#include <stdio.h>
#include <stdlib.h>

int yuan2(int n)
{
    int re=0,y,z=0;
    while(z<=n)
    {
        y=(n-z)%2;
        if(y==0) re++;
        z++;
    }
    //printf("in yuan2 re=%d\n",re);
    return re;
}

int yuan3(int n)
{
    int x=0,re=0;
    while(x*3<=n)
    {
        //printf("x=%d\n",x);
        re+=yuan2(n-(x*3));
        x++;
    }
    return re;
}

int numofjie(int n)
{
    int w=0,re=0;
    while(w*4<=n)
    {
        //printf("w=%d\n",w);
        re+=yuan3(n-(4*w));
        w++;
    }
    return re;
}



int main()
{
    int t,i;
    scanf("%d",&t);

    for(i=0;i<t;i++)
    {
        int n,re;
        scanf("%d",&n);
        re=numofjie(n);
        printf("%d\n",re);
    }
}
