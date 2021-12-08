#include <string>
#include <iostream>
using namespace std;

#include <mysql/jdbc.h>
using namespace sql;

#include "DatabaseConnection.h"
#include "Patient.h"
#include "PatientManager.h"

int PatientManager::addPatient(Patient* patient)
{
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn->prepareStatement("Insert into Patient values(?,?,?,?,?,?)");

	ps->setInt(1, patient->PatientID);
	ps->setString(2, patient->PatientName);
	ps->setString(3, patient->PatientPhoneNumber);
	ps->setString(4, patient->PatientAddress);
	ps->setString(5, patient->PatientPassword);
	ps->setInt(6, patient->PatientDOB);

	int status = ps->executeUpdate();

	delete ps;
	return status;

}

int PatientManager::updatePatient(Patient* patient)
{
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.preparedStatement("UPDATE Patient values(?,?,?,?,?,?)");
}

void PatientManager::searchPatient(string PatientID)
{

}