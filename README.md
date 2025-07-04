# CryptoAlgo# 🔐 DynamicShiftCaesar

A dynamic Caesar cipher algorithm developed as part of the **CSE 361: Mathematical Analysis for Computer Science** course at **Hajee Mohammad Danesh Science and Technology University (HSTU)**.

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

## 🔎 Algorithm Overview

**DynamicShiftCaesar** is a variation of the Caesar cipher that uses a **dynamic shift** value calculated from the **maximum frequency of characters** in the plaintext.

### 🔐 Encryption Formula:

\[
F(p) = (p + (m \mod k)) \mod 26
\]

### 🔓 Decryption Formula:

\[
F'(p) = (p - (m \mod k)) \mod 26
\]

Where:  
- `p` = position of character in alphabet (A=0, ..., Z=25)  
- `m` = maximum frequency of any character in the text  
- `k` = secret key (integer)

---

## 📂 Repository Contents

```
📁 DynamicShiftCaesar/
├── DynamicShiftCaesar.md       ← Full algorithm report
├── dynamicshiftcaesar.py       ← Python implementation
├── test_case.txt               ← Test input and output
├── hstu_logo_.png              ← HSTU Logo
└── README.md                   ← This file
```

---

## 🧪 Sample Input/Output

- **Input:** `HELLO WORLD`  
- **Key (k):** 5  
- **Output (cipher):** `KHOOR ZRUOG`  
- **Recovered (decryption):** `HELLO WORLD`

---

## 🚀 Run the Code

Make sure you have Python 3 installed.

```bash
python dynamicshiftcaesar.py
```

Modify the script to test with custom inputs.

---

## 📝 License

This project is for educational purposes only. All rights reserved © 2025 G.M. Nazmul Hassan.

---
