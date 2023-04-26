#include <stdio.h>
#include <math.h>
int main()
{
    int N,R,i = 0,m,j;
    char table[] = "0123456789ABCDEFGHIJK",a[100];
    scanf("%d %d",&N,&R);
    if(N==0) printf("0");
    else{while(N!=0)
    {
        m = N%R;
        if(m<0) m = abs(R) + m;
        a[i] = table[m];
        N = (N-m)/R;
        i++;
    }
    for(j=i-1;j>=0;j--)
    printf("%c",a[j]);}
    return 0;

}
