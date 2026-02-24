#ifndef PROJECT_HEADER_H
#define PROJECT_HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../features/structures.h"    /* bring in struct and enum definitions */

/* ================== CONSTANTS ================== */

#define ROOM_CHARGE 1500
#define DOCTOR_FEE 800
#define MEDICINE_COST 1200

#define ADMIN_USER "admin"
#define ADMIN_PASS "admin123"
#define DOC_USER "doctor"
#define DOC_PASS "doc123"
#define PHARM_USER "PHARM"
#define PHARM_PASS "PHARM123"

/* ================== FUNCTION DECLARATIONS ================== */

int login();
void adminMenu();
void userMenu();
void doctorMenu();
void pharmacistMenu();

/* Patient */
void addPatient();
void viewPatients();
void searchPatient();
void updatePatient();
void deletePatient();
float calculateBill(int days);

/* Other modules (Part 2 & 3) */
void addDoctor();
void viewDoctors();
void searchDoctor();

void addMedicationByDoctor();
void viewMedication();
void searchTreatments();
void addPriceByPharmacist();
void addWard();
void checkVacancy();

void addVisitor();
void viewVisitors();
void searchVisitorByPatientID();

void addRound();
void findDoctorByWard();
void findPatientsByDoctor();

int game();

#endif /* PROJECT_HEADER_H */
