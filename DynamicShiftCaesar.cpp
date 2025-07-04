#include <iostream>
#include <string>
#include <cctype>
#include <unordered_map>
using namespace std;

int compute_shift(const string& text, int k) {
    unordered_map<char, int> freq;
    for (char c : text) {
        if (isalpha(c)) {
            freq[toupper(c)]++;
        }
    }

    int m = 0;
    for (auto& p : freq) {
        if (p.second > m) {
            m = p.second;
        }
    }

    int s = m % k;
    if (s == 0 && m > 0) {
        m--;
        s = m % k;
    }
    return s;
}

string encrypt(const string& plaintext, int k) {
    int s = compute_shift(plaintext, k);
    string result;
    for (char c : plaintext) {
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            int p = toupper(c) - 'A';
            int shifted = (p + s) % 26;
            result += static_cast<char>(base + shifted);
        } else {
            result += c;
        }
    }
    return result;
}

string decrypt(const string& ciphertext, int k) {
    int s = compute_shift(ciphertext, k);
    string result;
    for (char c : ciphertext) {
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            int p = toupper(c) - 'A';
            int shifted = (p - s + 26) % 26;
            result += static_cast<char>(base + shifted);
        } else {
            result += c;
        }
    }
    return result;
}

int main() {
    string text;
    int k;

    cout << "Enter plaintext: ";
    getline(cin, text);
    cout << "Enter key k: ";
    cin >> k;

    string cipher = encrypt(text, k);
    cout << "Ciphertext: " << cipher << endl;

    string recovered = decrypt(cipher, k);
    cout << "Decrypted text: " << recovered << endl;

    return 0;
}
