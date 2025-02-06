#include <iostream>

using namespace std;

int gcd(int x, int y) {
    if (y == 0) return x;
    return gcd(y, x % y);
}

int main(){
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int x, y, z;
    x = a * d;
    y = c * b;
    z = b * d;

    cout << (x + y) / gcd(x + y, z) << ' ' << z / gcd(x + y, z) ;
}