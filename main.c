#include <stdio.h>

int main() {
    int correct_pin = 4821;
    float balance = 12500.00;
    int entered_pin;
    int attempts = 3;
    int logged_in = 0;
    
    // ==================== TASK 1: PIN Verification ====================
    while (attempts > 0) {
        printf("Enter PIN: ");
        scanf("%d", &entered_pin);
        
        if (entered_pin == correct_pin) {
            logged_in = 1;
            break; // Exit loop immediately on success
        } else {
            attempts--;
            if (attempts == 2) {
                printf("Incorrect PIN. 2 attempts remaining.\n\n");
            } else if (attempts == 1) {
                printf("Incorrect PIN. 1 attempt remaining.\n\n");
            } else {
                printf("Incorrect PIN. Your card has been blocked.\nPlease visit your nearest branch.\n");
            }
        }
    }
    
    // If login failed, exit program
    if (!logged_in) {
        return 0;
    }
    
    // ==================== TASK 2 & 3: Transaction Menu & Tracking ====================
    int choice;
    float amount;
    int txn_count = 0;
    
    while (1) {
        printf("\n===== Welcome =====\n");
        printf("Balance: ₹ %.2f\n", balance);
        printf("-------------------\n");
        printf("1. Check Balance\n");
        printf("2. Withdraw\n");
        printf("3. Deposit\n");
        printf("4. Exit\n");
        printf("===================\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Current Balance: ₹ %.2f\n", balance);
                break;
                
            case 2:
                printf("Enter amount to withdraw: ");
                scanf("%f", &amount);
                
                if (amount > balance) {
                    printf("Error: Insufficient balance.\n");
                } else if (amount <= 0 || (int)amount % 100 != 0) {
                    printf("Error: Amount must be a positive multiple of 100.\n");
                } else {
                    balance -= amount;
                    txn_count++;
                    
                    printf("\nTransaction: Withdrawal\n");
                    printf("Amount      : ₹ %.2f\n", amount);
                    printf("Balance     : ₹ %.2f\n", balance);
                    printf("Txn No.     : %d\n", txn_count);
                }
                break;
                
            case 3:
                printf("Enter amount to deposit: ");
                scanf("%f", &amount);
                
                if (amount <= 0) {
                    printf("Error: Deposit amount must be greater than zero.\n");
                } else {
                    balance += amount;
                    txn_count++;
                    
                    printf("\nTransaction: Deposit\n");
                    printf("Amount      : ₹ %.2f\n", amount);
                    printf("Balance     : ₹ %.2f\n", balance);
                    printf("Txn No.     : %d\n", txn_count);
                }
                break;
                
            case 4:
                printf("\nFinal Balance: ₹ %.2f\n", balance);
                printf("Thank you for using the ATM. Goodbye!\n");
                return 0;
                
            default:
                printf("Invalid choice. Please select between 1 and 4.\n");
        }
        
        // Check transaction limit after a successful transaction
        if (txn_count >= 5) {
            printf("\nTransaction limit reached. Please re-login.\n");
            break;
        }
    }

    return 0;
}