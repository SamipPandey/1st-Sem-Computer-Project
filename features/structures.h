#ifndef STRUCTURES_H
#define STRUCTURES_H

/* structure and enum definitions extracted from structure.txt */

enum Status { ADMITTED, DISCHARGED };

struct date {
    int day;
    int month;
    int year;
};

struct Medication {
    char name[30];
    char dosage[20];
    int days;
    float price;
};

struct Patient {
    int id;
    char name[30];
    int age;
    char disease[40];
    float bill;
    struct date Date;
    struct Medication med;
    char ward[30];
    enum Status status;
    int days;
};

struct Doctor {
    int id;
    char name[30];
    int roomNo;
};

struct Ward {
    char wardName[30];
    int totalBeds;
    int occupiedBeds;
};

struct Visitor {
    int patientID;
    char visitorName[30];
    char relation[20];
};

struct Round {
    int doctorID;
    int patientID;
    char ward[30];
};

#endif /* STRUCTURES_H */
