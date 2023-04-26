#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

double input()
    {
        char a[10];
        double f1,f2;
        scanf("%s",a);
        switch(a[0])
        {
            case '+':{f1=input();f2=input();return f1+f2;break;}
            case '-':{f1=input();f2=input();return f1-f2;break;}
            case '*':{f1=input();f2=input();return f1*f2;break;}
            case '/':{f1=input();f2=input();return f1/f2;break;}
            default:return atof(a);break;
        }
    }
        
int main()
{
    int n;
    scanf("%d\n",&n);
    for(int i=0;i<n;i++)
    {double l=input();
    printf("case #%d:\n",i);
    printf("%lf\n",l);}
    return 0;
    
    
}