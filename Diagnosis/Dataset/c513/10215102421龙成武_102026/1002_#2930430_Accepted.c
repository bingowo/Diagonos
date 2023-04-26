#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
int main()
{
    int T,i,j,x,R,len,tim;
    tim=0;
    //tim记录最后打印的次数
    long long int result=0;
    scanf("%d",&T);
    char *a[10];
    int b[123];

    for(x=0;x<123;x++)
        b[x]=-1;
    x=0;

    len=60;     //输入的字符长度
    for(i=0;i<T;i++)
    {
        a[i]=(char*)malloc(len*sizeof(char));
        scanf("%s",a[i]);
    }

    for(i=0;i<T;i++)
    {
        for(j=0;j<strlen(a[i]);j++)
        {
            if(b[(int)a[i][j]]==-1)
            {
                if(x==0)
                    b[(int)a[i][j]]=1;
                else if(x==1)
                    b[(int)a[i][j]]=0;
                else
                    b[(int)a[i][j]]=x;
                x++;
            }
        }
        //进制数为strlen(b);,但不为1进制
        if(x==1)
            R=2;
        else
            R=x;
        for(j=0;j<strlen(a[i]);j++)
        {
            result=result*R+b[(int)a[i][j]];
        }

        printf("case #");
        printf("%d:\n",tim);
        printf("%lld\n",result);

        for(x=0;x<123;x++)
            b[x]=-1;
        x=0;
        result=0;

        tim++;
    }

    for(i=0;i<T;i++)    free(a[i]);
    return 0;
}