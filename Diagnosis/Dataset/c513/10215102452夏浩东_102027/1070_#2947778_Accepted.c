#include <stdio.h>
int res=0;
void get(int len,int i,int j)
{
    if(len==0) {res++;return;}
    else 
    {
        if(i==0 && j==1){get(len-1,1,1);get(len-1,1,0);}
        else if(i==0 && j==0){get(len-1,0,1);get(len-1,0,0);}
        else if(i==1 && j==0){get(len-1,0,0);}
        else if(i==1 && j==1){get(len-1,1,1);get(len-1,1,0);} 
    }
}
int main()
{
    int len=0;
    while(1)
    {
        scanf("%d",&len);
        if(len==1) {printf("2\n");continue;}
        if(len==-1) break;
        get(len-2,1,0);
        get(len-2,1,1);
        get(len-2,0,1);
        get(len-2,0,0);
        printf("%d\n",res);
        res=0;
    }
    return 0;
}