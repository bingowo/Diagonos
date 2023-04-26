#include <stdio.h>
#include <stdlib.h>

int f(int x,int y);
void tobinary(int a[],int x);

int main()
{
    int T,i;
    scanf("%d",&T);
    for(i = 0;i < T;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        printf("%d\n",f(x,y));
    }
    return 0;
}

int f(int x,int y)
{
    int a[32],b[32];
    tobinary(a,x);
    tobinary(b,y);
    int j = 32,num = 0;
        while(a[j] != -1 || b[j] != -1){
            if(a[j] != b[j])num++;
            j--;
        }
        return num;
}

void tobinary(int a[],int x)
{
    for(int i = 0;i < 32;i++){
        a[i] = -1;
    }
    int j = 32;
    if(x == 0)a[32] = 0;
    while(x){
        a[j] = x%2;
        printf("a[%d] = %d\n",j,a[j]);
        x /= 2;
        j--;
    }

}
