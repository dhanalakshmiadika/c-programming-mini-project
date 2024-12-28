#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int account_number;
    char account_holder[100];
    float balance;
} Account;

Account accounts[100];
int account_count = 0;

void create_account() {
    if (account_count < 100) {
        printf("Enter account number: ");
        scanf("%d", &accounts[account_count].account_number);
        printf("Enter account holder's name: ");
        scanf("%s", accounts[account_count].account_holder);
        accounts[account_count].balance = 0;
        account_count++;
        printf("Account created successfully!\n");
    } else {
        printf("Maximum number of accounts reached!\n");
    }
}

void deposit() {
    int account_number;
    float amount;
    printf("Enter account number: ");
    scanf("%d", &account_number);
    for (int i = 0; i < account_count; i++) {
        if (accounts[i].account_number == account_number) {
            printf("Enter amount to deposit: ");
            scanf("%f", &amount);
            accounts[i].balance += amount;
            printf("Deposit successful!\n");
            return;
        }
    }
    printf("Account not found!\n");
}

void withdraw() {
    int account_number;
    float amount;
    printf("Enter account number: ");
    scanf("%d", &account_number);
    for (int i = 0; i < account_count; i++) {
        if (accounts[i].account_number == account_number) {
            printf("Enter amount to withdraw: ");
            scanf("%f", &amount);
            if (amount > accounts[i].balance) {
                printf("Insufficient funds!\n");
            } else {
                accounts[i].balance -= amount;
                printf("Withdrawal successful!\n");
            }
            return;
        }
    }
    printf("Account not found!\n");
}

void display_account_details() {
    int account_number;
    printf("Enter account number: ");
    scanf("%d", &account_number);
    for (int i = 0; i < account_count; i++) {
        if (accounts[i].account_number == account_number) {
            printf("Account Number: %d\n", accounts[i].account_number);
            printf("Account Holder: %s\n", accounts[i].account_holder);
            printf("Balance: %.2f\n", accounts[i].balance);
            return;
        }
    }
    printf("Account not found!\n");
}

void generate_mini_statement() {
    int account_number;
    printf("Enter account number: ");
    scanf("%d", &account_number);
    for (int i = 0; i < account_count; i++) {
        if (accounts[i].account_number == account_number) {
            printf("Mini Statement:\n");
            printf("Account Number: %d\n", accounts[i].account_number);
            printf("Balance: %.2f\n", accounts[i].balance);
            // Add transaction history here
            return;
        }
    }
    printf("Account not found!\n");
}

int main() {
    int choice;
    while (1) {
        printf("\nBank Account Management System\n");
        printf("1. Create Account\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Display Account Details\n");
        printf("5. Generate Mini Statement\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                create_account();
                break;
            case 2:
                deposit();
                break;
            case 3:
                withdraw();
                break;
            case 4:
                display_account_details();
                break;
            case 5:
                generate_mini_statement();
                break;
            case 6:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
