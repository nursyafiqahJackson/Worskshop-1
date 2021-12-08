#pragma warning(disable : 4996)
#include<iostream>
#include<cstdio>
#include<fstream>
#include<sstream>
#include<cstdlib>
#include<windows.h>
#include<time.h>
#include<ctime>
#include <iomanip>
#include<string>
#include<conio.h>
#include<mysql.h>

#include"Appoinment.h"
#include"AppoinmentManager.h"
#include"DermaManager.h"
#include"Dermatologist.h"
#include"DermatologistManager.h"
#include"Patient.h"
#include"PatientManager.h"
#include"Payment.h"
#include"PaymentManager.h"
#include"Treatment.h"
#include"TreatmentManager.h"

using namespace std; 


void loginMenu();
void registration();
void MainMenu();
void Login();
void Appoinment();
void Payment();
void Report();
void exit();

int option; 

void loginMenu()
{
    int chooseOneFromMenu = 0;
    cout << "\n\t\t\t\t================================================================" << endl;
    cout << "\n\t\t\t\t\tHELLO! WELCOME TO AESTHETIC CLINIC MANAGEMENT SYSTEM" << endl;
    cout << "\n\t\t\t\t================================================================" << endl;

    cout << "\t\t\t\t\t================================================================" << endl << endl;
    cout << "\n\t\t\t\t\t\t\t   1. LOGIN" << endl;
    cout << "\n\t\t\t\t\t\t\t   2. NEW REGISTRATION" << endl;
    cout << "\n\t\t\t\t\t\t\t   3. EXIT" << endl;
    cout << "\t\t\t\t\t================================================================" << endl << endl;
    cout << "\n\t\t\t\t\t\t\    Please Choose Your Option: ";
    cin >> chooseOneFromMenu;

    switch (chooseOneFromMenu)
    {
    case 1:
        Login();
        break;
    case 2:
        registration();
        break;
    case 3:
        cout << "Loading..." << endl;
        exit(0);
    default:
        cout << "Please choose between 1 - 3. Press Enter To Continue...";
        
        system("pause");
        system("cls");

        loginMenu();
        break;
    }
}

void Login()
{
    system("pause");
    system("cls");
    string password;
    
    cout << "\n\t\t\t\t--- This Is Aesthetic Clinic's Login Menu ---" << endl << endl;

    cout << "\n\tName : ";
    cin >> name;
    cout << "\n\tPassword : ";
    getline(cin, password);

    char ch;
    while ((ch = _getch()) != 13)
    {
        password += ch;
        cout << '*';
    }



}

void Appoinment() 
{
    system("pause");
    system("cls");
    
    AppoinmentManager appoinmentManager;
    TreatmentManager treatmentManager;

    Appoinment* appoinment = new Appoinment();
    Treatment* treatment = new Treatment();

    Appoinment->PatientID = ID;

    cout << "\t\t ========================================================" << endl;
    cout << "\n\t\t\t\t--- THIS IS AESTHETIC CLINIC'S APPOINTMENT  ---" << endl << endl;
    cout << "\t\t ========================================================" << endl;

    cout << "\t\t\tThe table below shows available appoinment within this month." << endl;
    cout << "\t\t--------------------------------------------------------------------------" << endl;
    cout << "\t\t        AppoinmentID        Date       Treatment Name                            " << endl;
    cout << "\t\t--------------------------------------------------------------------------" << endl;

    for (int i = 1; i <= AppoinmentManager::AppoinmentManager.selectMax(); i++)
    {
        appoinment = AppoinmentManager.selectClass(i);
        if (appoinment != 0) {
    cout << "\t\t       " << i << "\t\t" << appoinment->AppoinmentID << "\t\t" << appoinment->AppoinmentDate << "\t\t" << treatment->TreatmentName << endl;
}
    }
    cout << "\n\n\t\t\tPlease enter 1 to book a class, enter 2 to return : ";
    cin >> option;
    if (option == 1) {
        cout << "\n\t\t\tEnter class no : ";
        cin >> appoinment->AppoinmentID;

        if (appoinment->AppoinmentID < 1 || appoinment->AppoinmentID > appoinmentManager.selectMax()) {
            cout << "\n\t\t\tNumber entered not in range! Please choose again. " << endl << endl;
            appoinment();
        }
        else {
            if (appoinmentManager.checkTableBookClass(appoinment)) {
                cout << "\n\n\t\t\tAre you sure you want to book this class? (Y/N) : ";
                cin >> ans;

                if (ans == 'Y' || ans == 'y') {
                    int status = appoinmentManager.bookClass(appoinment, ID);
                    if (status != 0) {
                        cout << "\n\n\t\t\tSuccessfully booked a class." << endl;
                        classMenu();
                    }
                    else {
                        cout << "\n\n\t\t\tUnable to book a class." << endl;
                        classMenu();
                    }
                }
                else if (ans == 'N' || ans == 'n') {
                    cout << "\n\t\t\tBooking cancelled." << endl;
                    cout << "\n\n\t\t\tDo you want to book again? (Y/N) : ";
                    cin >> ans;
                    if (ans == 'Y' || ans == 'y') {
                        appoinment();
                    }
                    else {
                        classMenu();
                    }
                }
                else {
                    cout << "\n\t\t\tInvalid request. Please enter again" << endl << endl;
                    appoinment();
                }
            }
            else {
                appoinment();
            }
        }
    }
    else if (option == 2) {
        classMenu();
    }
    else {
        cout << "\n\t\t\tInvalid option! Please choose again. " << endl << endl;
        appoinment();
    }
}
void registration()
{

}

void MainMenu()
{

}

void Payment()
{

}

void Report()
{
    system("pause");
    system("cls");
    AppoinmentManager appoinmentManager;
    Appoinment* appoinment = new Appoinment();

    cout << "\n\t\t\t\t--- THIS IS DENTAL CLINIC'S PATIENT REPORT ---" << endl << endl;
    string date;
    cout << "\n\tWhich date do you want to see? : ";
    cin >> date;
    
}

void exit()
{
    system("pause");
    system("cls");

    cout << "\n\n\n\n\n\t\t\t\t==================================================================================================================" << endl;
    cout << "                                                                                                                                    " << endl;
    cout << "\t\t\t\t   Thank you for using this system.For your safety purpose, do not share any information to others." << endl;
    cout << "                                                                                                                                    " << endl;
    cout << "\t\t\t\t==================================================================================================================\n\n\n\n" << endl;

    exit(1);
}