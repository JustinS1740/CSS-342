// Justin Singsanavong
#include <iostream>
using namespace std;

int CalculateCatalan(int n);

int main(int argc, char* argv[])
{
    int n = atoi(argv[1]);

    if (CalculateCatalan(n) != -1) {
        cout << "The Catalan of " << n << " is " << CalculateCatalan(n) << endl;
    }
}

int CalculateCatalan(int n) {
    // base cases
    if (n == 0) {
        return 1;
    }

    // checks for negatives
    else if (n < 0) {
        cout << "Negative n not allowed." << endl;
        return -1;
    }

    // check for integer overflow
    else if (n >= 20) {
        cout << "Error: Integer overflow at n = " << n << endl;
        return -1;
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += CalculateCatalan(i) * CalculateCatalan(n - i - 1);
    }
    return ans;
}
