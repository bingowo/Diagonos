#include <stdio.h>
#include <string.h>

void changebin(char *a,int num)
{
    int i=0;
    while(num>=2)
    {
        a[i]=num%2+'0';
        num=num/2;
        i++;
    }
    a[i]=num+'0';
}
int findit(char *a)
{
    int temp,maxlen,p,q;
    temp=maxlen=1;
    q=1;
    while(q<strlen(a))
    {
        if(a[q-1]!=a[q])
        {
            temp++;
        }

        if(a[q-1]==a[q])
        {
            if(maxlen<temp)
                maxlen=temp;
            temp=1;
        }
        else if(q==strlen(a)-1)
        {
            if(maxlen<temp)
                maxlen=temp;
            temp=1;
        }
        q++;
    }
    return maxlen;
}
void myPrint(int res)
{
    static int tim=0;
    printf("case #%d:\n", tim);
    //printf("0.");
    printf("%d\n",res);
    tim++;
}
int main()
{
    int i,T,num,maxlen;
    char a[33];
    scanf("%d",&T);

    for(i=0;i<T;i++)
    {
        scanf("%d",&num);
        changebin(a,num);
        maxlen=findit(a);
        myPrint(maxlen);
    }
    return 0;
}
