#include <stdio.h>
#include <stdlib.h>



int main()
{
    int n;
    scanf("%d",&n);
    for(int i = 0;i<n;i++)
    {

        char p[200];
        scanf("%s",p);
        int po =0;
        while(p[po]== '!')
        {
            po++;
        }
        char z[4]={0};
        z[0] = p[po];
        int pr = po;
        while(po<strlen(p))
        {
            if(p[po]!='!')z[(po-pr)%4]= p[po];
            po++;
        }
        int res[200]={0};
        for(int i =pr;i<strlen(p);i++)
        {
            if(p[i]=='!')res[z[(i-pr)%4]]++;
        }
        for(int k = pr-1;k>=0;k--)
        {
            int k_ = (pr-k)%4;
            if(k_!=0)k_=4-k_;
            res[z[k_]]++;
        }
        printf("case #%d:\n",i);
        printf("%d ",res['R']);
        printf("%d ",res['B']);
        printf("%d ",res['Y']);
        printf("%d\n",res['G']);
    }
    return 0;
}
