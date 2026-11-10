# 🏦 Bank Account Management System

A console-based Bank Account Management System built using **C++**. This project allows users to create bank accounts, deposit money, withdraw money, and check account balances through a simple menu-driven interface.

## 📌 Features

- **Create Account** – Create a new account with a unique account number and an initial balance.
- **Deposit Money** – Add money to an existing account.
- **Withdraw Money** – Withdraw money while checking for sufficient balance.
- **Check Balance** – View the account number and current balance.
- **Input Validation** – Handles invalid inputs and allows users to re-enter incorrect values.
- **Duplicate Account Prevention** – Prevents multiple accounts from having the same account number.
- **Account Storage Limit** – Supports up to 100 accounts.

## 🛠️ Technologies Used

- **Language:** C++
- **Libraries:** `iostream`, `limits`
- **Concepts:** Functions, Arrays, Loops, Conditional Statements, References, Input Validation.

## ⚙️ How It Works

The program uses two parallel arrays to store account information:

| Array | Purpose |
|---|---|
| `AccountNumber[]` | Stores account numbers |
| `Balance[]` | Stores account balances |

An `AccountCount` variable keeps track of the number of accounts currently created.

Each account's information is stored at the same array index, connecting its account number with its balance.

## 🚀 Getting Started

### 1. Clone the Repository

```bash
git clone https://github.com/Zrayoid/Bank-Account-Management-System.git
```

### 2. Navigate to the Project Folder

```bash
cd Bank-Account-Management-System
```

### 3. Compile the Program

Using g++:

```bash
g++ main.cpp -o bank
```

### 4. Run the Program

**Windows:**
```bash
bank.exe
```

**Linux:**
```bash
./bank
```

## 🖥️ Menu Interface

```text
<------------Menu-------------->

Press 1 to create Account
Press 2 to Deposit Money
Press 3 to Withdraw Money
Press 4 to Check Account Balance
Press 5 to Exit.

Enter your choice:
```

## 📚 Learning Objectives

This project was developed to strengthen my understanding of:

- Working with arrays and parallel arrays.
- Breaking a program into reusable functions.
- Passing arrays and variables through function parameters.
- Using references to modify variables.
- Implementing loops for repeated input.
- Validating user input using `cin.fail()`, `cin.clear()`, and `cin.ignore()`.
- Applying conditions to handle different operations.

## 🔮 Future Improvements

- Implement account deletion.
- Add transaction history.
- Introduce file handling to save account data permanently.
- Explore Object-Oriented Programming to manage account information.

## ⚠️ Limitations

- Account information is stored in memory and is lost when the program closes.
- The system supports a maximum of 100 accounts.
- This is an educational console project, not a real banking application.

---

**Project Type:** Beginner C++ Project  
**Status:** Completed  
**Author:** [Zrayoid](https://github.com/Zrayoid)
