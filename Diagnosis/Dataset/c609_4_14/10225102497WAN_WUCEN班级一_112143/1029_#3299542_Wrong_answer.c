#include <stdio.h>
#include <stdlib.h>

short nappear(const short* ascend, const short a, const short n);

int cmp(const void* a, const void* b);

int main()
{
    short nA = 0, nB = 0, * A, * B, BNotInA[500] = { 0 }, * ascendB, * ascendA, ib = 0, nBNotInA = 0;
    scanf("%hd", &nA);
    A = (short*)malloc(nA * sizeof(short));
    ascendA = (short*)malloc(nA * sizeof(short));
    for (short ia = 0;ia < nA;ia++)
    {
        scanf("%hd", A + ia);
        *(ascendA + ia) = *(A + ia);
    }
    scanf("%hd", &nB);
    B = (short*)malloc(nB * sizeof(short));
    ascendB = (short*)malloc(nB * sizeof(short));
    for (ib = 0;ib < nB;ib++)
    {
        scanf("%hd", B + ib);
        *(ascendB + ib) = *(B + ib);
    }
    qsort(ascendA, nA, sizeof(short), cmp);
    qsort(ascendB, nB, sizeof(short), cmp);
    for (ib = 0;ib < nB;ib++)
    {
        short napp = 0;
        if (!(napp = nappear(ascendA, *(B + ib), nA)))
                BNotInA[nBNotInA++] = *(B + ib);
    }
    ib = 0;
    for (short ia = 0;ia < nA;ia++)
    {
        short napp = 0;
        if (napp = nappear(ascendB, *(A + ia), nB))
            while (napp--)
                *(B + ib++) = *(A + ia);
    }
    qsort(BNotInA, nBNotInA, sizeof(short), cmp);
    for (int i = 0;i < nBNotInA;i++)
        *(B + ib + i) = BNotInA[i];
    for (ib = 0;ib < nB;ib++)
        printf("%hd ", *(B + ib));
    return 0;
}

int cmp(const void* a, const void* b)
{
    return *(short*)a - *(short*)b;
}

short nappear(const short* ascend, const short a, const short n)
{
    short left = 0, right = n - 1,mid=0,Nappear=0,radius=0;
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (a == *(ascend + mid))
        {
            Nappear++;
            radius = mid+1;
            break;
        }
        else if (a < *(ascend + mid))
            right = mid - 1;
        else
            left = mid + 1;
    }
    while (*(ascend + radius++) == a)
        Nappear++;
    radius = mid - 1;
    while (*(ascend + radius--) == a&&radius>=0)
        Nappear++;
    return Nappear;
}