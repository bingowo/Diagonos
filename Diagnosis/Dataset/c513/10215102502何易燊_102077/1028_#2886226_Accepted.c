#include <stdio.h>

main()
{
    int bucket[1002] = {};
    char c = getchar();
    int n;
    while (scanf("%d",&n)!=EOF) bucket[n]++;
    if (c=='A')
        {for (int i=0;i<1002;i++) if (bucket[i]!=0) printf("%d ",i);}
    else
        {for (int j=1001;j>=0;j--) if (bucket[j]!=0) printf("%d ",j);}
    return 0;
}