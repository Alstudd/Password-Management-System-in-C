#include<stdio.h>
#include<stdbool.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>

struct user {
	char username[50];
	char email[50];
	char password[50];	
};

void maskPassword(char password[]) {
	char ch;
	int i = 0;
	while (1) 
	{	
		ch = getch();
		if (ch != 13) // 13 is ASCII value of \r also called carriage return = enter key
		{
			password[i] = ch;
			i++;
			printf("*");
		}
		else
			break;
	}
	password[i] = '\0';	
}

void passwordStrength(char password[]) {
	int len = strlen(password);
    bool hasLower = false, hasUpper = false;
	bool hasDigit = false, specialChar = false;
    char normalChars[100] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890 ";
 	int i;
    for (i = 0; i < len; i++) {
        if (islower(password[i]))
            hasLower = true;
        if (isupper(password[i]))
            hasUpper = true;
        if (isdigit(password[i]))
            hasDigit = true;
 		if (password[i] != normalChars[i])
 			specialChar = true;
    } 
    // Strength of password
    printf("\nStrength of password: ");
    if (hasLower && hasUpper && hasDigit &&
        specialChar && (len >= 8))
        printf("Strong\n");
    else if ((hasLower || hasUpper) &&
             specialChar && (len >= 6))
        printf("Moderate\n");
    else
        printf("Weak\n");
}

int main() {
	int opt = 0;
	char temp_password[50], temp_email[50];
	struct user signupUser;
	struct user loginUser;
	printf("\n\t\t\t\t-----Welcome to Password Management System-----\n\n");
	while (opt != 5) 
	{
		printf("\n|1. Signup         |");
		printf("\n|2. Login          |");
		printf("\n|3. Forgot Password|");
		printf("\n|4. Change Password|");
		printf("\n|5. Exit           |");
		printf("\n\nYour choice: ");
		scanf("%d", &opt);
		
		switch(opt) {
			case 1:
				printf("\n\t\t\t\t\t-----SignUp Section-----\n\n");
				printf("\nEnter your username: ");
				scanf(" %s", signupUser.username);
				printf("Enter your email: ");
				scanf(" %s", signupUser.email);
				printf("Enter Your Password: ");
				maskPassword(signupUser.password);
				
				printf("\nConfirm your password: ");
				maskPassword(temp_password);
				if (strcmp(signupUser.password, temp_password) == 0) {
					printf("\n\nRegistration Successful !!!\n");
					passwordStrength(signupUser.password);
				}
				else
					printf("\n\nPasswords don't match!\n");
				break;
			case 2:
				printf("\n\t\t\t\t\t-----Login Section-----\n\n");
				printf("\nEnter your email: ");
				scanf(" %s", loginUser.email);
				printf("Enter Your Password: ");
				maskPassword(loginUser.password);
				if ((strcmp(loginUser.password, signupUser.password) == 0) || (strcmp(loginUser.password, signupUser.password) == 0))  {
					printf("\n\nLogin Successful !!!\n\n");
					printf("User Details:\n");
					printf("Username: %s\n", signupUser.username);
					printf("Email: %s\n", loginUser.email);
				}
				else {
					printf("\n\nUser not found!\n");
				}
				break;
			case 3:
				printf("\n\t\t\t\t\t-----Forgot Password-----\n\n");
				printf("Enter your email: ");
				scanf(" %s", &temp_email);
				if (strcmp(temp_email, signupUser.email) == 0) {
					printf("\nYour Account was found!\n");
					printf("Your Password is: %s\n", signupUser.password);
				}
				else
					printf("Your Account was not found!\n");
				break;
			case 4:
				printf("\n\t\t\t\t\t-----Change Password-----\n\n");
				printf("Enter your email: ");
				scanf(" %s", &temp_email);
				if (strcmp(temp_email, signupUser.email) == 0) {
					printf("\nYour Password is: %s\n", signupUser.password);
					printf("\nEnter your new password: ");
					maskPassword(loginUser.password);
					strcpy(signupUser.password, loginUser.password);
					printf("\nConfirm your password: ");
					maskPassword(temp_password);
					if (strcmp(loginUser.password, temp_password) == 0) {
						printf("\n\nPassword Changed !!!\n");
						passwordStrength(signupUser.password);
					}
					else
						printf("\n\nPasswords don't match!\n");
				}
				else
					printf("Your Account was not found!\n");
				break;
			case 5:
				printf("\n\t\t\t\t\t-----Thank You !!!-----\n\n");
				break;
			default:
				printf("\n\nInvalid Option!\n");
		}
	}
	return 0;
}
