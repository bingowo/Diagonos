#include <stdio.h>
#include <string.h>


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
    int i,j,T,res;
    char a[21];
    scanf("%d",&T);


    for(i=0;i<T;i++)
    {
        res=0;
        scanf("%s",a);
        //len=strlen(a)-1;
        for(j=0;j<strlen(a);j++)
        {
            if(a[j]=='-')
                res=res*3+(-1);
            else if(a[j]=='0')
                res=res*3+0;
            else if(a[j]=='1')
                res=res*3+1;
        }
        myPrint(res);
    }
    return 0;
}
