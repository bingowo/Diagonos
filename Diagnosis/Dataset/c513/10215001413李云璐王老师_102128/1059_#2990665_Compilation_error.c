#include <iostream>
#include<bits/stdc++.h>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<cctype>
#include<stdlib.h>
#include<cstdio>

#define ll long long
using namespace std;



void gcd(int rain,int dif,int fina)
{
    int a = rain;
    int b = dif;
    if(!rain)
        return;
    else
    {
        int temp;
        while(b % a)
        {
            temp = b % a;
            b = a;
            a = temp;
        }
        rain /= a;
        dif /= a;
        cout << (fina?"+":"") << rain << "/" << dif;
    }

}


int main()
{
    int n,s;
    cin >> n >> s;
    ll a[1020];
    for(int i = 0; i < 1020;i++)a[i]=0;

    for(int i = 0; i < n; i++)
        cin >> a[i];
    long long low = 99999999999LL,high = 0;
    for(int i = 0; i < n; i++)
    {
        if(low > a[i]) low = a[i];
        if(high < a[i]) high = a[i];
    }

    int *al = new int[high+10];
    for(int i = 0; i < high + 10; i++)
        al[i] = 0;

    for(int i = 0; i < n; i++)
    {
        al[a[i]] += 1;
    }
    for(int i = 1; i <= high; i++ )
    {
        al[i] +=al[i-1];
    }
    //cout << al[high-1] << endl;

    int loc = 0;
    while(loc < high && al[loc] == 0)
        loc++;

    int dif = al[loc];
    int rain = s;
    int fina = low;
    while(rain >= dif)
    {
        rain -= dif;
        fina++;
        if(loc < high)loc++;
        dif = al[loc];
    }
    if(fina)
    cout << fina;
    //cout <<endl << rain << endl <<  dif << endl;
    gcd(rain,dif,fina);

    return 0;
}