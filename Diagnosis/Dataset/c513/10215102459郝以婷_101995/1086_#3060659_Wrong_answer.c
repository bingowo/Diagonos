#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int i,j,N,lena,lenb,marka,markb,k=0,carry=0,temp,if0=0,mark,if1=0;
    char a[501],b[501],ret[501],a1[501];
    scanf("%s",a);
    scanf("%s",b);
    scanf("%d",&N);
    lena=strlen(a);
    lenb=strlen(b);
    for(marka=0;a[marka]!='.'&&marka<lena;marka++);
    for(markb=0;b[markb]!='.'&&markb<lenb;markb++);
    if(marka==lena)
    {
        a[lena]='.';
        lena++;
        marka=lena-1;
    }
    if(markb==lenb)
    {
        b[lenb]='.';
        lenb++;
        markb=lenb-1;
    }
    if(marka<markb)
    {
        strcpy(a1,a);
        strcpy(a,b);
        strcpy(b,a1);
        if0=1;
        temp=lena;
        lena=lenb;
        lenb=temp;
        temp=marka;
        marka=markb;
        markb=temp;
    }
    if(lena-marka<lenb-markb)
    {
        for(i=0;i<lenb-markb-lena+marka;i++)
        {
            a[lena+i]=48;
        }
        lena=lena+i;
    }
    else if(lena-marka>lenb-markb)
    {
        for(i=0;i<lena-marka-lenb+markb;i++)
        {
            b[lenb+i]=48;
        }
        lenb=lenb+i;
    }
    //printf("%s %s",a,b);
    for(i=lena-1,j=lenb-1;i>=0;i--,j--)
    {
        if(i==marka)
        {
            ret[k++]='.';
            mark=k-1;
            continue;
        }
        if(j<0)
            temp=48;
        else
            temp=b[j];
        if(a[i]-temp-carry>=0)
        {
            ret[k++]=a[i]-temp-carry+48;
            carry=0;
        }
        else
        {
            if(a[i]=='0'&&carry>0)
            {
                a[i]='9';
                ret[k++]=a[i]-temp+48;
            }
            else
                ret[k++]=10+a[i]-temp+48-carry;
            carry=1;
        }//printf("%c %c %c %d\n",ret[k-1],a[i],temp,j);
    }
    if(mark==k-1)
        ret[k++]='0';
    if(mark<N)
        if1=1;
    else if(mark>N)
    {
        for(i=mark-N-1;i<k;i++)
        {
            if(i==mark)
                continue;
            if(i==mark-N-1&&ret[i]<=4+48)
                break;
            else if(i==mark-N-1&&ret[i]>=5+48)
            {
                carry=1;
            }
            else
            {
                if(carry+ret[i]<=9+48)
                {
                    ret[i]=ret[i]+carry;
                    break;
                }
                else
                {
                    ret[i]='0';
                    carry=1;
                }
            }
        }
    }
    if(if0)
        printf("-");
    while(ret[k-1]=='0'&&ret[k-2]!='.')
        k--;
    if(if1)
    {
        for(i=k-1;i>=0;i--)
            printf("%c",ret[i]);
        for(i=0;i<N-mark;i++)
            printf("0");
    }
    else
    {
        for(i=k-1;i>=mark-N;i--)
            printf("%c",ret[i]);
    }
    return 0;
}
