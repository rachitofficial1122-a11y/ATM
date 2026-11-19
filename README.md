# ATM Simulation Application

A console-based ATM management system written in C.

## Features

- **PIN Authentication**: Secure login with a 3-attempt limit before card blocking.
- **Balance Inquiry**: Check current account balance.
- **Cash Withdrawal**: Validate withdrawal amounts (must be positive multiples of 100 and within balance limit).
- **Cash Deposit**: Deposit funds with positive amount validation.
- **Transaction Tracking**: Tracks transaction count with a per-session limit of 5 transactions.

## How to Run

1. Compile the program using GCC:
   ```bash
   gcc main.c -o atm
   ```
2. Run the executable:
   - On Windows:
     ```bash
     .\atm.exe
     ```
   - On Linux / macOS:
     ```bash
     ./atm
     ```

## Default Credentials
- **PIN**: `4821`
- **Initial Balance**: `₹ 12,500.00`
