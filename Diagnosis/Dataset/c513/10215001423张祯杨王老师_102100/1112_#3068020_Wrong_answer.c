#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T;
    scanf("%d",&T);
    int a[11];
    for(int i=0;i<T;i++) scanf("%d",&a[i]);
    for(int i=0;i<T;i++)
    {   int count=1;
        int m=2;
        for(m;m<=a[i];m++)
        {
            int q1=m/2;
            int x=4;
            for(x;x<=q1;x+=2)
            {
                
                  if(x%12!=2) count+=x/12;
                  else count+=(x+12)/12;
            }
        }
        printf("%d",count);
    }
    return 0;
}
