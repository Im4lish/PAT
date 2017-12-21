#include <iostream>
#include <cctype>
using namespace std;
int main() {
    string a, b;
    cin >> a >> b;
    char c[100];
    int i = 0, j = 0, t = 0;
    while (j <= b.length() - 1) {
        if (b[j] != a[i]) {
            c[t++] = a[i];
        } else {
            j++;
        }
        i++;
    }
    for (int k = i; k < a.length(); k++)
        c[t++] = a[k];
    for (int k = 0; k < t; k++)
        c[k] = toupper(c[k]);
    for (int k = 0; k < t; k++) {
        for (int m = 0; m < k; m++) {
            if (c[m] == c[k]) c[k] = '#';
        }
    }
    for (int k = 0; k < t; k++) {
        if (c[k] != '#') cout << c[k];
    }
    return 0;
}
