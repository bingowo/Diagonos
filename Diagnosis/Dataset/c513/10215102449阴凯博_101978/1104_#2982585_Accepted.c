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
                    if (s1[2]=='V')
                        arr[s2[0]]=arr[s2[3]];
                    if (s1[2]=='D')
                    {
                        if (strlen(s2)==5)
                            arr[s2[0]]%=arr[s2[3]];
                        if (strlen(s2)==8)
                            arr[s2[0]]=arr[s2[3]]%arr[s2[6]];
                    }
                }
                if (s1[1]=='U')
                {
                    if (strlen(s2)==5)
                        arr[s2[0]]*=arr[s2[3]];
                    if (strlen(s2)==8)
                        arr[s2[0]]=arr[s2[3]]*arr[s2[6]];
                }
                break;
            }
        case 'A':
            {
                if (strlen(s2)==5)
                {
                    if (s1[1]=='D')
                        arr[s2[0]]+=arr[s2[3]];
                    if (s1[1]=='N')
                        arr[s2[0]]&=arr[s2[3]];
                }
                if (strlen(s2)==8)
                {
                    if (s1[1]=='D')
                        arr[s2[0]]=arr[s2[3]]+arr[s2[6]];
                    if (s1[1]=='N')
                        arr[s2[0]]=arr[s2[3]]&arr[s2[6]];
                }
                break;
            }
        case 'S':
            {
                if (strlen(s2)==5)
                    arr[s2[0]]-=arr[s2[3]];
                if (strlen(s2)==8)
                    arr[s2[0]]=arr[s2[3]]-arr[s2[6]];
                break;
            }
        case 'D':
            {
                if (strlen(s2)==5)
                    arr[s2[0]]/=arr[s2[3]];
                if (strlen(s2)==8)
                    arr[s2[0]]=arr[s2[3]]/arr[s2[6]];
                break;
            }
        case 'O':
            {
                if (s1[1]=='U')
                    printf("%d\n",arr[s2[0]]);
                if (s1[1]=='R')
                {
                    if (strlen(s2)==5)
                        arr[s2[0]]|=arr[s2[3]];
                    if (strlen(s2)==8)
                        arr[s2[0]]=arr[s2[3]]|arr[s2[6]];
                }

                break;
            }
        case 'X':
            {
                if (s1[1]=='C')
                {
                    int a=0;
                    a=arr[s2[0]];
                    arr[s2[0]]=arr[s2[3]];
                    arr[s2[3]]=a;
                }
                if (s1[1]=='O')
                {
                    if (strlen(s2)==5)
                        arr[s2[0]]^=arr[s2[3]];
                    if (strlen(s2)==8)
                        arr[s2[0]]=arr[s2[3]]^arr[s2[6]];
                }

            }

        }
    }
    return 0;
}
