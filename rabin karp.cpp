#include <iostream>
using namespace std;

#define d 256

int main() {
    string txt = "ABCCDDAEFG";
    string pat = "CDD";

    int m = pat.length();
    int n = txt.length();
    int q = 101; // prime number

    int h = 1, p = 0, t = 0;

    // Calculate h = pow(d, m-1) % q
    for (int i = 0; i < m-1; i++)
        h = (h * d) % q;

    // Initial hash values
    for (int i = 0; i < m; i++) {
        p = (d * p + pat[i]) % q;
        t = (d * t + txt[i]) % q;
    }

    // Sliding window
    for (int i = 0; i <= n - m; i++) {

        if (p == t) {
            // Check characters one by one
            bool match = true;
            for (int j = 0; j < m; j++) {
                if (txt[i + j] != pat[j]) {
                    match = false;
                    break;
                }
            }
            if (match)
                cout << "Pattern found at index " << i << endl;
        }

        // Calculate next window hash
        if (i < n - m) {
            t = (d * (t - txt[i] * h) + txt[i + m]) % q;
            if (t < 0) t += q;
        }
    }

    return 0;
}