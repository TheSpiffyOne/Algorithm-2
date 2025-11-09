#include <iostream>
using namespace std;

double power(double x, int n) {
    if (n == 0) return 1;
    if (n < 0) return 1 / power(x, -n);
    return x * power(x, n - 1);
}

int main() {
    cout << "2^5 = " << power(2, 5) << endl;
    cout << "3^-2 = " << power(3, -2) << endl;
    return 0;
}
