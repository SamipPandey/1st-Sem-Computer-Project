#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void addPatient() {
    clearScreen();
    FILE *fp = fopen("patients.dat", "ab");
    struct Patient p;
 p.med.price = 0.0;
    int days;

    if (!fp) {
        printf("File error!\n");
        return;
    }

    printf("Enter Patient ID: ");
    scanf("%d", &p.id);

    printf("Enter Name: ");
    scanf(" %[^\n]", p.name);

    printf("Enter Age: ");
    scanf("%d", &p.age);

    printf("Enter Disease: ");
    scanf(" %[^\n]", p.disease);

    printf("Enter Admission Date (dd-mm-yyyy): ");
    scanf("%d-%d-%d", &p.Date.day, &p.Date.month, &p.Date.year);

    printf("Enter Ward: ");
    scanf(" %[^\n]", p.ward);

    printf("Enter Status (0=Admitted, 1=Discharged): ");
    scanf("%d", (int*)&p.status);

    printf("Enter Number of Days Admitted: ");
    scanf("%d", &p.days);

   

    fwrite(&p, sizeof(p), 1, fp);
    fclose(fp);

    printf("Patient added successfully!\n");
}

float calculateBill(struct Patient p) {
	
	
    
    printf(" Patient ID: ");
    printf("%d", &p.id);

    printf(" Name: ");
    printf(" %[^\n]", p.name);

    return (p.days * ROOM_CHARGE) + DOCTOR_FEE + p.med.price;
    
return(0);
}

void viewPatients() {
	clearScreen();
    FILE *fp = fopen("patients.dat", "rb");
    struct Patient p;

    if (!fp) {
        printf("No patient records found.\n");
        return;
    }

    while (fread(&p, sizeof(p), 1, fp)) {
        printf("\nID: %d\nName: %s\nAge: %d\nDisease: %s\nDate: %02d-%02d-%04d\nWard: %s\nBill: %.2f",
               p.id, p.name, p.age, p.disease,
               p.Date.day, p.Date.month, p.Date.year,
               p.ward, p.bill);
               printf("\nMedicine   : %s", p.med.name);
        printf("\nDosage     : %s", p.med.dosage);
        printf("\nDuration   : %d days", p.med.days);
        printf("\nPrice      : Rs %.2f\n", p.med.price);
    }

    fclose(fp);
}

void searchPatient() {
	clearScreen();
    FILE *fp = fopen("patients.dat", "rb");
    struct Patient p;
    int id, found = 0;

    if (!fp) {
        printf("No records found.\n");
        return;
    }

    printf("Enter Patient ID: ");
    scanf("%d", &id);

    while (fread(&p, sizeof(p), 1, fp)) {
        if (p.id == id) {
            printf("\nPatient Found:\n");
            printf("Name: %s\nDisease: %s\nBill: %.2f\n",
                   p.name, p.disease, p.bill);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Patient not found.\n");

    fclose(fp);
}

void updatePatient() {
	clearScreen();
    FILE *fp = fopen("patients.dat", "rb+");
    struct Patient p;
    int id,choice, found = 0;

    if (!fp) {
        printf("No records found.\n");
        return;
    }

    printf("Enter Patient ID to update: ");
    scanf("%d", &id);

    while (fread(&p, sizeof(p), 1, fp)) {
        if (p.id == id) {
        	printf("what do you want to update \n ");

   				 printf("1.\tAge:\n");
   				 printf("2.\tDisease:\n ");
    			 printf("3.\tAdmission Date (dd-mm-yyyy):\n ");
   				 printf("4.\tWard:\n");
   				 printf("5.\tStatus (0=Admitted, 1=Discharged):\n ");
   				 printf("6.\tEnter Number of Days Admitted:\n");
   				 printf("Enter choice: ");
       			 scanf("%d", &choice);

        switch (choice) {
            case 1:  printf("Enter Age: ");
    				scanf("%d", &p.age);break;
            case 2:   printf("Enter Disease: ");
    				scanf(" %[^\n]", p.disease); break;
            case 3:  printf("Enter Admission Date (dd-mm-yyyy): ");
    				scanf("%d-%d-%d", &p.Date.day, &p.Date.month, &p.Date.year); break;
            case 4:  printf("Enter Ward: ");
    				scanf(" %[^\n]", p.ward); break;
            case 5:printf("Enter Status (0=Admitted, 1=Discharged): ");
   					scanf("%d", (int*)&p.status) ; break;
            case 6:printf("Enter Number of Days Admitted: ");
    				scanf("%d", &p.days) ; break;
            default: printf("Invalid choice!\n");
        }

            fseek(fp, -((long)sizeof(p)), SEEK_CUR); 
			fwrite(&p, sizeof(p), 1, fp);

            found = 1;
            break;
        }
    }

    fclose(fp);

    if (found)
        printf("Patient updated successfully.\n");
    else
        printf("Patient not found.\n");
}

void deletePatient() {
	clearScreen();
    FILE *fp = fopen("patients.dat", "rb");
    FILE *temp = fopen("temp.dat", "wb");
    struct Patient p;
    int id, found = 0;

    if (!fp || !temp) {
        printf("File error.\n");
        return;
    }

    printf("Enter Patient ID to delete: ");
    scanf("%d", &id);

    while (fread(&p, sizeof(p), 1, fp)) {
        if (p.id != id)
            fwrite(&p, sizeof(p), 1, temp);
        else
            found = 1;
    }

    fclose(fp);
    fclose(temp);

    remove("patients.dat");
    rename("temp.dat", "patients.dat");

    if (found)
        printf("Patient deleted successfully.\n");
    else
        printf("Patient not found.\n");
}
/* ================== DOCTOR MODULE ================== */

void addDoctor() {
	clearScreen();
    FILE *fp = fopen("doctors.dat", "ab");
    struct Doctor d;

    if (!fp) {
        printf("File error!\n");
        return;
    }

    printf("Enter Doctor ID: ");
    scanf("%d", &d.id);

    printf("Enter Doctor Name: ");
    scanf(" %[^\n]", d.name);

    printf("Enter Room Number: ");
    scanf("%d", &d.roomNo);

    fwrite(&d, sizeof(d), 1, fp);
    fclose(fp);

    printf("Doctor added successfully.\n");
}

void viewDoctors() {
	clearScreen();
    FILE *fp = fopen("doctors.dat", "rb");
    struct Doctor d;

    if (!fp) {
        printf("No doctor records found.\n");
        return;
    }

    while (fread(&d, sizeof(d), 1, fp)) {
        printf("\nDoctor ID: %d\nName: %s\nRoom: %d\n",
               d.id, d.name, d.roomNo);
    }

    fclose(fp);
}

void searchDoctor() {
	clearScreen();
    FILE *fp = fopen("doctors.dat", "rb");
    struct Doctor d;
    int id, found = 0;

    if (!fp) {
        printf("No records found.\n");
        return;
    }

    printf("Enter Doctor ID: ");
    scanf("%d", &id);

    while (fread(&d, sizeof(d), 1, fp)) {
        if (d.id == id) {
            printf("\nDoctor Found:\nName: %s\nRoom: %d\n",
                   d.name, d.roomNo);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Doctor not found.\n");

    fclose(fp);
}

/* ================== TREATMENT MODULE ================== */

void addMedicationByDoctor() {
    FILE *fp = fopen("patients.dat", "rb+");
    struct Patient p;
    int id, found = 0;
    printf("Patient ID: "); scanf("%d", &id);
    while (fread(&p, sizeof(p), 1, fp)) {
        if (p.id == id) {
            found = 1;
            printf("Medicine: "); scanf(" %[^\n]", p.med.name);
            printf("Dosage: "); scanf(" %[^\n]", p.med.dosage);
            printf("Days: "); scanf("%d", &p.med.days);
            fseek(fp, -((long)sizeof(p)), SEEK_CUR);
            fwrite(&p, sizeof(p), 1, fp);
            break;
        }
    }
    fclose(fp);
    if(found) printf("Medicine Prescribed.\n");
}


void viewMedication() {
	clearScreen();
    FILE *fp = fopen("patients.dat", "rb");
    struct Patient pm;

    if (!fp) {
        printf("No medication data.\n");
        return;
    }

    printf("\n--- Medication Records ---\n");
    while (fread(&pm, sizeof(pm), 1, fp)) {
        printf("\nPatient ID : %d", pm.id);
        printf("\nMedicine   : %s", pm.med.name);
        printf("\nDosage     : %s", pm.med.dosage);
        printf("\nDuration   : %d days", pm.med.days);
        printf("\nPrice      : Rs %.2f\n", pm.med.price);
    }

    fclose(fp);
}

void addPriceByPharmacist() {
    FILE *fp = fopen("patients.dat", "rb+");
    struct Patient p;
    char Name[50],medName[50];
    int id, found = 0;
    printf("Patient ID: "); 
	scanf("%d", &id);
    printf("Enter  PATIENT Name: ");
    scanf(" %[^\n]", Name);
    printf("Enter  medication Name: ");
    scanf(" %[^\n]", medName);

    while (fread(&p, sizeof(p), 1, fp)) {
        if (p.id == id) {
        		printf("\nPatient ID : %d", p.id);
        		printf("\nname 		 : %s", p.name);
        		printf("\nMedicine   : %s", p.med.name);
        		printf("\nDosage     : %s", p.med.dosage);
        		printf("\nDuration   : %d days", p.med.days);
            found = 1;
            printf("\nPrice for %s: ", p.med.name);
            scanf("%f", &p.med.price);
            p.bill = calculateBill(p);
            fseek(fp, -((long)sizeof(p)), SEEK_CUR);
            fwrite(&p, sizeof(p), 1, fp);
            break;
        }
    }
    fclose(fp);
    if(found) printf("Price Updated & Bill Calculated.\n");
}

/* ================== WARD MODULE ================== */

void addWard() {
    FILE *fp = fopen("wards.dat", "ab");
    struct Ward w;

    if (!fp) {
        printf("File error!\n");
        return;
    }

    printf("Enter Ward Name: ");
    scanf(" %[^\n]", w.wardName);

    printf("Enter Total Beds: ");
    scanf("%d", &w.totalBeds);

    printf("Enter Occupied Beds: ");
    scanf("%d", &w.occupiedBeds);

    if (w.occupiedBeds > w.totalBeds) {
        printf("Error: Occupied beds cannot exceed total beds.\n");
        fclose(fp);
        return;
    }

    fwrite(&w, sizeof(w), 1, fp);
    fclose(fp);

    printf("Ward added successfully.\n");
}

void checkVacancy() {
    FILE *fp = fopen("wards.dat", "rb");
    struct Ward w;
    int found = 0;

    if (!fp) {
        printf("No ward records found.\n");
        return;
    }

    printf("\n===== Ward Vacancy Status =====\n");

    while (fread(&w, sizeof(w), 1, fp)) {
        int vacant = w.totalBeds - w.occupiedBeds;

        printf("\nWard: %s\n", w.wardName);
        printf("Total Beds: %d\n", w.totalBeds);
        printf("Occupied Beds: %d\n", w.occupiedBeds);
        printf("Vacant Beds: %d\n", vacant);

        if (vacant > 0)
            printf("Status: Beds Available\n");
        else
            printf("Status: Full\n");

        found = 1;
    }

    if (!found)
        printf("No records found.\n");

    fclose(fp);
}

/* ================== VISITOR MODULE ================== */

void addVisitor() {
	clearScreen();
    FILE *fp = fopen("visitors.dat", "ab");
    struct Visitor v;

    if (!fp) {
        printf("File error!\n");
        return;
    }

    printf("Enter Patient ID: ");
    scanf("%d", &v.patientID);

    printf("Enter Visitor Name: ");
    scanf(" %[^\n]", v.visitorName);

    printf("Enter Relation: ");
    scanf(" %[^\n]", v.relation);

    fwrite(&v, sizeof(v), 1, fp);
    fclose(fp);

    printf("Visitor added successfully.\n");
}

void viewVisitors() {
	clearScreen();
    FILE *fp = fopen("visitors.dat", "rb");
    struct Visitor v;

    if (!fp) {
        printf("No visitor records found.\n");
        return;
    }

    while (fread(&v, sizeof(v), 1, fp)) {
        printf("\nPatient ID: %d\nVisitor: %s\nRelation: %s\n",
               v.patientID, v.visitorName, v.relation);
    }

    fclose(fp);
}

void searchVisitorByPatientID() {
	clearScreen();
    FILE *fp = fopen("visitors.dat", "rb");
    struct Visitor v;
    int id, found = 0;

    if (!fp) {
        printf("No records found.\n");
        return;
    }

    printf("Enter Patient ID: ");
    scanf("%d", &id);

    while (fread(&v, sizeof(v), 1, fp)) {
        if (v.patientID == id) {
            printf("\nVisitor: %s\nRelation: %s\n",
                   v.visitorName, v.relation);
            found = 1;
        }
    }

    if (!found)
        printf("No visitors found for this patient.\n");

    fclose(fp);
}

/* ================== DOCTOR ROUND MODULE ================== */

void addRound() {
	clearScreen();
    FILE *fp = fopen("rounds.dat", "ab");
    struct Round r;

    if (!fp) {
        printf("File error!\n");
        return;
    }

    printf("Enter Doctor ID: ");
    scanf("%d", &r.doctorID);

    printf("Enter Patient ID: ");
    scanf("%d", &r.patientID);

    printf("Enter Ward: ");
    scanf(" %[^\n]", r.ward);

    fwrite(&r, sizeof(r), 1, fp);
    fclose(fp);

    printf("Round record added successfully.\n");
}

void findDoctorByWard() {
	clearScreen();
    FILE *fp = fopen("rounds.dat", "rb");
    struct Round r;
    char ward[30];
    int found = 0;

    if (!fp) {
        printf("No round records found.\n");
        return;
    }

    printf("Enter Ward Name: ");
    scanf(" %[^\n]", ward);

    while (fread(&r, sizeof(r), 1, fp)) {
        if (strcmp(r.ward, ward) == 0) {
            printf("Doctor ID: %d attended Patient ID: %d\n",
                   r.doctorID, r.patientID);
            found = 1;
        }
    }

    if (!found)
        printf("No rounds found for this ward.\n");

    fclose(fp);
}

void findPatientsByDoctor() {
	clearScreen();
    FILE *fp = fopen("rounds.dat", "rb");
    struct Round r;
    int docID, found = 0;

    if (!fp) {
        printf("No round records found.\n");
        return;
    }

    printf("Enter Doctor ID: ");
    scanf("%d", &docID);

    while (fread(&r, sizeof(r), 1, fp)) {
        if (r.doctorID == docID) {
            printf("Patient ID: %d | Ward: %s\n",
                   r.patientID, r.ward);
            found = 1;
        }
    }

    if (!found)
        printf("No patients found for this doctor.\n");

    fclose(fp);
}