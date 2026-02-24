#include "header.h"

/* ================== MAIN ================== */

int main(int a) {
    FILE *fp = fopen("patients.dat", "ab");
    if (fp) fclose(fp);

    int role = 5;
    if (a == 1) {
        role = login();

        if (role == 1)
            adminMenu();
        else if (role == 2)
            userMenu();
        else if (role == 3)
            doctorMenu();
        else if (role == 4)
            pharmacistMenu();
        else
            printf("Exiting system.\n");
    }
    return 0;
}
