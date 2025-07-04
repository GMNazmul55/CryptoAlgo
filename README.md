<p align="center">
  <img src="hstu_logo_.png" alt="HSTU Logo" width="200"/>
</p>

# 🔐 DynamicShiftCaesar Cipher

A dynamic Caesar cipher cryptographic algorithm designed for:

> **CSE 361: Mathematical Analysis for Computer Science**  
> Hajee Mohammad Danesh Science and Technology University (HSTU)

---

## 📘 Course Information

- **Course Title:** Mathematical Analysis for Computer Science  
- **Course Code:** CSE 361  

---

## 🧑‍💻 Submitted By

- **Name:** G.M. Nazmul Hassan  
- **Student ID:** 2102055  
- **Level:** 3  
- **Semester:** II  
- **Department:** Computer Science and Engineering

---

## 👨‍🏫 Submitted To

- **Name:** Pankaj Bhowmik  
- **Designation:** Lecturer  
- **Department:** Computer Science and Engineering

---

# ✨ DynamicShiftCaesar Overview

**DynamicShiftCaesar** is an enhanced variant of the classical Caesar cipher. Unlike the classical cipher, which uses a fixed shift, this algorithm determines the shift **dynamically** based on the maximum frequency of characters in the plaintext.

This makes it significantly harder for attackers to guess the shift without analyzing the plaintext statistics.

---

## 🔑 Algorithm Details

### Encryption Formula

\[
F(p) = (p + (m \mod k)) \mod 26
\]

- **p** = position of letter in alphabet (A=0, B=1, ..., Z=25)
- **m** = highest frequency among all letters in plaintext
- **k** = secret key (integer)

If `(m mod k) = 0`, then:
- update `m = m - 1`
- recompute `(m mod k)`

---

### Decryption Formula

\[
F'(p) = (p - (m \mod k)) \mod 26
\]

---

## ✅ How It Works

1. Count the frequency of each letter in the text.
2. Find the maximum frequency `m`.
3. Compute shift `s = m mod k`.
4. If `s = 0`, decrement `m` by 1 and recompute `s`.
5. Shift letters forward (+s) for encryption or backward (–s) for decryption.
6. Non-alphabetic characters remain unchanged.

---

## 🧪 Example

Encrypt the plaintext:

```
Plaintext: HELLO WORLD
Key (k): 5
```

**Letter frequencies:**

- H → 1
- E → 1
- L → 3
- O → 2
- W → 1
- R → 1
- D → 1

Maximum frequency \( m = 3 \)

```
s = m % k = 3 % 5 = 3
```

### Encryption:

| Char | Pos (p) | (p + s) % 26 | Encrypted |
|------|---------|--------------|-----------|
| H    | 7       | 10           | K         |
| E    | 4       | 7            | H         |
| L    | 11      | 14           | O         |
| L    | 11      | 14           | O         |
| O    | 14      | 17           | R         |
| (space)| -     | -            | (space)   |
| W    | 22      | 25           | Z         |
| O    | 14      | 17           | R         |
| R    | 17      | 20           | U         |
| L    | 11      | 14           | O         |
| D    | 3       | 6            | G         |

→ **Ciphertext:** `KHOOR ZRUOG`

Decryption shifts back by `–3`, recovering the original plaintext.

---

## 📂 Repository Contents

```
📁 DynamicShiftCaesar/
├── DynamicShiftCaesar.md       ← Full report
├── dynamicshiftcaesar.py       ← Python implementation
├── dynamicshiftcaesar.cpp      ← C++ implementation
├── test_case.txt               ← Test input/output
├── hstu_logo_.png              ← University logo
└── README.md                   ← This file
```

---

## 🚀 Usage Instructions

### Run Python Version

```bash
python dynamicshiftcaesar.py
```

### Run C++ Version

Compile:

```bash
g++ dynamicshiftcaesar.cpp -o dynamicshift
```

Run:

```bash
./dynamicshift
```

---

## ✅ Flowcharts

### Encryption

```
[Start]
   ↓
[Count letter frequencies]
   ↓
[Find max frequency m]
   ↓
[Compute s = m mod k]
   ↓
[If s == 0 → m = m - 1, recompute s]
   ↓
[For each letter]
 ┌───────────────┐
 │ Is letter?    │
 └───────┬───────┘
      Yes        No
       ↓          ↓
[Convert p]   [Keep char]
       ↓
[(p + s) mod 26]
       ↓
[Convert back]
       ↓
[Append to output]
   ↓
[End]
```

### Decryption

Same as encryption, except subtract `s` instead of adding.

---

## ✅ Mermaid Encryption Flowchart

```mermaid
flowchart TD
    A[Start] --> B[Count letter frequencies]
    B --> C[Find max frequency m]
    C --> D[Compute s = m mod k]
    D --> E{Is s == 0?}
    E -- No --> F[Keep s]
    E -- Yes --> G[Set m = m - 1]
    G --> H[Recompute s = m mod k]
    F --> I[For each character]
    H --> I
    I --> J{Is letter?}
    J -- No --> K[Append unchanged]
    J -- Yes --> L[Convert char to p]
    L --> M[Compute (p + s) mod 26]
    M --> N[Convert back to char]
    N --> O[Append to output]
    K --> P{More letters?}
    O --> P
    P -- Yes --> I
    P -- No --> Q[End]
```

---

# 💻 C++ Implementation

Below is the **C++ code** for DynamicShiftCaesar encryption and decryption:

```cpp
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
```

---

## 📝 License

This project is for academic purposes only.  
All rights reserved © 2025 G.M. Nazmul Hassan.

---
