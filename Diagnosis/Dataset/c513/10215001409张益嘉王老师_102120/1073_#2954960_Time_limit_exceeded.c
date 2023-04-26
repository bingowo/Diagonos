#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int baohan(unsigned long long x)
{
    int i=0,mid=0;
    while(x>0)
    {
        if((x%10)==9) return i*10-mid-1;
        mid=x%10;
        x/=10;
        i++;
    }
    return 1;
}

int jud(unsigned long long x)
{
    if((x%9)==0) return -1;
    else return 1;

}

/*unsigned long long qujian(unsigned long long x)
{
    //printf("x=%llu\n",x);
    if((x==89)||(x==189)||(x==289)||(x==389)||(x==489)||(x==589)||(x==689)||(x==789)||(x==889)) return 10;
    else if((x==900)||(x==1900)||(x==2900)||(x==3900)||(x==4900)||(x==5900)||(x==6900)||(x==7900)||(x==8900)) return 99;
    else if((x==9000)||(x==19000)||(x==29000)||(x==39000)||(x==49000)||(x==59000)||(x==69000)||(x==79000)||(x==89000)) return 999;
    else if((x==90000)||(x==190000)||(x==290000)||(x==390000)||(x==490000)||(x==590000)||(x==690000)||(x==790000)||(x==890000)) return 9999;
    else if((x==900000)||(x==1900000)||(x==2900000)||(x==3900000)||(x==4900000)||(x==5900000)||(x==6900000)||(x==7900000)||(x==8900000)) return 99999;
    else return 1;

}
*/
int main()
{
    unsigned long long a,b,i,co=0;
    unsigned long long pan;
    scanf("%llu%llu",&a,&b);
    //printf("test: a=%llu  b=%llu\n",a,b);
    for(i=a;i<=b;i++)
    {
        //pan=qujian(i);
        //printf("pan=%llu\n",pan);
        //if(pan!=1) {i+=pan;continue;}
        if(jud(i)==1)
        {
            pan=baohan(i);
            //printf("pan=%d i=%d\n",pan,i);
             if(pan==1) co++;
             else if(pan==-1);
             else i+=pan;
        }
        //printf("i=%llu\n",i);
    }
    printf("%llu\n",co);
    return 0;
}
