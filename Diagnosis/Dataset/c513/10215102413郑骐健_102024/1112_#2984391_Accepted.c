#include <stdio.h>
#include <stdlib.h>

//int con=0;
//int f(int a,int b,int c ,int d,int m)
//{
//    int cnt =0;
//    switch(m)
//    {
//        case 1:
//            {
//                cnt=1;
//                break;
//            }
//        case 2:
//            {
//            cnt=c+1;
//            break;
//            }
//        case 3:
//            {
//                if(b>0)
//                    {
//                        if(d>0)
//                        {
//                            cnt+=f(a,b,c,d,2)+f(a,b-1,c+2,d-1,3);
//                        }
//                        else
//                        {
//                            cnt+=f(a,b,c,d,2)+f(a,b-1,c+1,d+1,3);
//                        }
//                    }
//                else cnt+=f(a,b,c,d,2);
//                break;
//            }
//        case 4:
//            {
//                if(a>0)cnt+=f(a,b,c,d,3)+f(a-1,b+1,c,d+1,4);
//                else cnt+=f(a,b,c,d,3);
//            }
//            }
//   return cnt;
//
//}



int main()
{
//    int p[4];
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
    int n,res;
    scanf("%d",&n);
   int a,b,c,d;
//    a = n/4;
//    b = (n%4)/3;
//    c = ((n%4)-b*3)/2;
//    d= n/4 -b*3-c*2;
//    res= f(a,b,c,d,4);
    res=0;
        for(a=0;a<=n/4;a++)
        {
            for(b=0;b<=(n-a*4)/3;b++)
            {
                res+=(n-a*4-b*3)/2+1;
            }
        }
    printf("%d\n",res);
    }
    return 0;
}
