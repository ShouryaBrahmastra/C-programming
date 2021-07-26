/*The program to find the correct ID password using switch*/
#include <stdio.h>
int main() {
        int ID = 500;
        int password = 000;
        printf("Plese Enter Your ID:\n ");
        scanf("%d", & ID);
        switch (ID) {
            case 500:
                printf("Enter your password:\n ");
                scanf("%d", & password);
                switch (password) {
                    case 000:
                        printf("Password is match\n");
                        break;
                    default:
                        printf("incorrect password");

                }
                break;
            default:
                printf("incorrect ID");
                break;
        }
}
