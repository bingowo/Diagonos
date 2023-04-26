#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int jud(unsigned long long x)
{
    return x%9;

}

int jud2(unsigned long long x)
{
    char s[20];
    sprintf(s,"%llu",x);
    int len=strlen(s),i;
    //printf("s=%s\n",s);
    for(i=0;i<len;i++)
    {
        if(s[i]=='9') return 0;
    }
    return 1;
}

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
        if(jud(i))
        {
            //pan=baohan(i);
            //printf("pan=%d i=%d\n",pan,i);
             if(jud2(i)) co++;
             //else if(pan==-1);
             //else i+=pan;
        }
        //printf("i=%llu\n",i);
    }
    printf("%llu\n",co);
    return 0;
}
