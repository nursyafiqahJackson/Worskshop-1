#include <iostream>
#include <string>
using namespace std;

#include <mysql/jdbc.h>
using namespace sql;

#include "DatabaseConnection.h"
#include "Appoinment.h"
#include "AppoinmentManager.h"

#include "DermaManager.h"
#include "PatientManager.h"

int AppoinmentManager::Appoinment(Appoinment* appoinment, int PatientID)
{
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.preparedStatement("INSERT INTO appoinment_class VALUES (?, ?)");

	ps->setInt(1, appoinment->AppoinmentID);
	ps->setInt(2, PatientID);

	int status = ps->executeUpdate();

	delete ps;

	return status;

}

bool AppoinmentManager::checkTableBookClass(Appoinment* appoinment)
{
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.preparedStatement("SELECT * FROM appoinment_class WHERE appoinment_id = ? AND patient_id = ?");

	ps->setInt(1, appoinment->AppoinmentID);
	ps->setInt(2, appoinment->PatientID);

	ResultSet* rs = ps->executeQuery();

	if ((rs->next()))
	{
		cout << "\n\t\t\tYou have choosen this date before. Please choose another different date for your apooinment !" << endl << endl;
		return false;
	}
	else
	{
		delete rs;
		delete ps;

		return true;
	}
}

int BookingManager::selectMax() {
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.preparedStatement("SELECT MAX(appoinment_ID) FROM appoinment_class");

	ResultSet* rs = ps->executeQuery();
	if (rs->next())
	{
		return rs->getInt(1);
	}
	else
		return 0;
}


Appoinment* AppoinmentManager::selectBooked(int PatientID)
{
	Appoinment* appoinment = NULL;
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.preparedStatement("SELECT b.AppoinmentID, a.AppoinmentDate, a.class_time FROM available_appoinment a, TreatmentName b WHERE b.AppoinmentID = a.AppoinmentID AND PatientID = ?");

	ps->setInt(1, PatientID);

	ResultSet* rs = ps->executeQuery();

	int i = 1;
	while (rs->next())
	{
		appoinment = new Appoinment();
		appoinment->AppoinmentID = rs->getInt(1);
		appoinment->TreatmentName = rs->getString(2);
		appoinment->AppoinmentDate = rs->getInt(3);
		appoinment->PatientID = rs->getInt(4);
		

		cout << "\t\t  " << appoinment->AppoinmentID << "\t\t" << appoinment-> AppoinmentDate << "\t\t" <<appoinment->TreatmentName  << "\t\t" << appoinment->PatientID << endl;
		i++;
	}

	delete rs;
	delete ps;

	return appoinment;
}

bool AppoinmentManager::checkToDelete(Appoinment* appoinment)
{
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.preparedStatement("SELECT * FROM AppoinmentID WHERE AppoinmentID = ? AND PatientID = ?");

	ps->setInt(1, appoinment->AppoinmentID);
	ps->setInt(2, appoinment->PatientID);

	ResultSet* rs = ps->executeQuery();

	if (!(rs->next()))
	{
		return false;
	}
	else
	{
		delete rs;
		delete ps;

		return true;
	}
}

int AppoinmentManager::deleteBooked(Appoinment* appoinment)
{
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.preparedStatement("DELETE FROM AppoinmentID WHERE AppoinmentID = ? AND PatientID = ?");

	ps->setInt(1, appoinment->AppoinmentID);
	ps->setInt(2, appoinment->PatientID);

	int status = ps->executeUpdate();

	delete ps;

	return status;
} 