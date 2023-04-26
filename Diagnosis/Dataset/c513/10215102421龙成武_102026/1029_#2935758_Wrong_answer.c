#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
typedef struct
{
    double x,y,p,o;
}POINT;
int compar(const void *p1,const void *p2);
void myPrint(POINT* point,int N);
int main()
{
    int T,i,j;
    char temp[201],alpha[201],res[201];
    scanf("%d",&T);
    while(T--)
    {
        j=0;
        scanf("%s",temp);
        for(i=0;i<strlen(temp);i++)
        {
            if(temp[i]>='A'&&temp[i]<='Z')
                alpha[j++]=temp[i];
        }
        alpha[j]=0;
        qsort(alpha,strlen(alpha),sizeof(char),compar);
        j=0;
        for(i=0;i<strlen(temp);i++)
        {
            if(temp[i]>='A'&&temp[i]<='Z')
            {
                res[i]=alpha[j++];
            }
            else
            {
                res[i]=temp[i];
            }
        }
        puts(res);
    }
    return 0;
}

int compar(const void *p1,const void *p2)
{
    int flag=0;
    char *a=(char*)p1,*b=(char*)p2;
    if(*a<*b)
        flag=-1;
    else
        flag=1;
    return flag;
}
void myPrint(POINT* point,int N)
{
    static int tim=0;
    int i;
    printf("case #%d:\n",tim++);
    for(i=0;i<N;i++)
    {
        printf("(%.4lf,%.4lf)\n",point[i].p,point[i].o);
    }
}
