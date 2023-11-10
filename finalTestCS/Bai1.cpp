#include <iostream>
#include <cmath>

using namespace std;

int sum_of_divisors(int n) {
   int result = 1;

    for (int i = 2; i <= sqrt(n); ++i) {
        if (n % i == 0) {
            result += i;

            if (i != n / i) {
                result += n / i;
            }
        }
    }

    return result;
}

int main() {
    int T;
    cin >> T;

    int huan[T];
    for (int i = 0; i < T; ++i) {
        cin >> huan[i];
    }
    for (int i = 0; i < T; ++i) {
        int result = sum_of_divisors(huan[i]);

        cout << result << endl;
    }

    return 0;
}