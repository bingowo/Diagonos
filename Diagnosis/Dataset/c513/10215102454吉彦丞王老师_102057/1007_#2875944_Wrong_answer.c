#include<stdio.h>
int main()
{
    int number;
    scanf("%d",&number);
    long long int a[number];
    int s[number][32];
    int result[number];
    for(int i=0;i<number;i++)
    {
        scanf("%lld",&a[i]);
        int length=0;
        while(a[i]>0)
        {
            s[i][length]=a[i]%2;
            a[i]=a[i]/2;
            length++;
        }
    }
    
        
}