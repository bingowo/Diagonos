#include <stdio.h>
#include <stdlib.h>

int f(int x)
{
    int t=0;
    int lastt=0;
    int l=1;
    int maxl=0;
    int i=0;
    for(lastt=x%2;x;x/=2){
        t=x%2;
        if(t!=lastt){l++;
            if(l>maxl)
                maxl=l;
        }
        else l=1;
        lastt=t;
    }
    return maxl;


}
int main()
{
    int n;
    scanf("%d",&n);
    int x;
    for (int i=0;i<n;i++)
    {
        scanf("%d",&x);
        printf("%d",f(x));

    }
    return 0;
}
