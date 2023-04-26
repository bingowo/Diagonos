#include <iostream>
#include <limits>
#include <typeinfo>
using namespace std;

int main()
{

    cout << "Minimun value for char: " << (int)numeric_limits<char>::min() <<'\n';
    cout << "Maximun value for char: " << (int)numeric_limits<char>::max() <<'\n';
    cout << "Minimun value for wchar_t: " << numeric_limits<wchar_t>::min() <<'\n';
    cout << "Maximun value for wchar_t: " << numeric_limits<wchar_t>::max() <<'\n';
    cout << "Minimun value for short: " << numeric_limits<short>::min() <<'\n';
    cout << "Maximun value for short: " << numeric_limits<short>::max() <<'\n';
    cout << "Minimun value for int: " << numeric_limits<int>::min() <<'\n';
    cout << "Maximun value for int: " << numeric_limits<int>::max() <<'\n';
    cout << "Minimun value for long: " << numeric_limits<long>::min() <<'\n';
    cout << "Maximun value for long: " << numeric_limits<long>::max() <<'\n';
    cout << "Minimun value for float: " << numeric_limits<float>::min() <<'\n';
    cout << "Maximun value for float: " << numeric_limits<float>::max() <<'\n';
    cout << "Minimun value for double: " << numeric_limits<double>::min() <<'\n';
    cout << "Maximun value for double: " << numeric_limits<double>::max() <<'\n';
    cout << "Minimun value for unsigned: " << numeric_limits<unsigned>::min() <<'\n';
    cout << "Maximun value for unsigned: " << numeric_limits<unsigned>::max() <<'\n';
    cout << "Minimun value for long long: " << numeric_limits<long long>::min() <<'\n';
    cout << "Maximun value for long long: " << numeric_limits<long long>::max() <<'\n';
    return 0;
}
