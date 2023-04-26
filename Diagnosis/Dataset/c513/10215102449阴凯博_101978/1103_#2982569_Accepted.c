#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int main()
{
    int arr[150]={0};
    char s1[5]={0},s2[50]={0};
    while (scanf("%s",s1)!=EOF)
    {
        scanf("%s",s2);
        switch (s1[0])
        {
        case 'I':
            {
                int a=0;
                char c=0;
                sscanf(s2,"%cX,%d",&c,&a);
                arr[s2[0]]=a;
                break;
            }
        case 'M':
            {
                if (s1[1]=='O')
                {
                    arr[s2[0]]=arr[s2[3]];
                }
                if (s1[1]=='U')
                {
                    arr[s2[0]]*=arr[s2[3]];
                }
                break;
            }
        case 'A':
            {
                arr[s2[0]]+=arr[s2[3]];
                break;
            }
        case 'S':
            {
                arr[s2[0]]-=arr[s2[3]];
                break;
            }
        case 'D':
            {
                arr[s2[0]]/=arr[s2[3]];
                break;
            }
        case 'O':
            {
                printf("%d\n",arr[s2[0]]);
                break;
            }
        }
    }
    return 0;
}
