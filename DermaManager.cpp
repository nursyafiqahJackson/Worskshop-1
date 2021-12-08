#include <iostream>
#include <string>
using namespace std;

#include <mysql/jdbc.h>
using namespace sql;

#include "DatabaseConnection.h"
#include "Dermatologist.h"
#include "DermaManager.h"

bool DermaManager::checkTableDerma(Dermatologist* derma)
{
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.preparedStatement("SELECT* FROM derma WHERE d_ID = ?");

	ps->setInt(1, derma->DermaID);
	ResultSet* rs = ps->executeQuery();

	if ((rs->next()))
	{
		cout << "\n\n\t\t\t User ID registered before !" << endl;
		return false;
	}
	else
	{
		delete rs;
		delete ps;

		return true;
	}
}

int DermaManager::addDerma(Dermatologist* derma)
{
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.preparedStatement("INSERT INTO derma VALUES (?, ?, ?, ?, ?, ?)");

	ps->setInt(1, derma->DermaID);
	ps->setString(2, derma->DermaName);
	ps->setInt(3, derma->DermaDOB);
	ps->setString(4, derma->DermaPhoneNumber);
	ps->setString(5, derma->DermaAddress);
	ps->setString(6, derma->DermaPassword);

	int status = ps->executeUpdate();

	delete ps;

	return status;
}

Dermatologist* DermaManager::searchDerma(int DermaID)
{
	Dermatologist* derma = NULL;
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.preparedStatement("SEARCH* FROM derma WHERE d_ID = ?");

	ps->setInt(1, DermaID);
	ResultSet* rs = ps->executeQuery();

	if (rs->next())
	{
		derma = new Dermatologist();

		derma->DermaID = rs->getInt(1);
		derma->DermaName = rs->getString(2);
		derma->DermaDOB = rs->getInt(3);
		derma->DermaAddress = rs->getString(4);
		derma->DermaPhoneNumber = rs->getString(5);
		derma->DermaPassword = rs->getString(6);

	}
	delete rs;
	delete ps;

	return derma;
}

bool DermaManager::loginDerma(Dermatologist* derma)
{
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.preparedStatement("SELECT* FROM derma WHERE d_ID = ?");

	ps->setInt(1, derma->DermaID);
	ResultSet* rs = ps->executeQuery();

	if ((rs->next()))
	{
		cout << "\n\t\t Invalid ID" << endl << endl;
		return false;
	}
	else
	{
		delete rs;
		delete ps;

		ps = dbConn.preparedStatement("SELECT* FROM derma WHERE d_ID = ? AND d_password = ?");

		ps->setInt(1, derma->DermaID);
		ps->setString(2, derma->DermaPassword);

		rs = ps->executeQuery();

		if (!(rs->next()))
		{
			cout << "\n\t\t\tInvalid password authentication ! " << endl << endl;
			return false;
		}

		delete rs;
		delete ps;
	}

	return true;
}

int DermaManager::updateDermaName(Dermatologist* derma)
{
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.preparedStatement("UPDATE derma SET WHERE d_name= ? AND d_ID = ?");

	
	ps->setString(1, derma->DermaName);
	ps->setInt(2, derma->DermaID);

	int status = ps->executeUpdate();

	delete ps;

	return status;
}

int DermaManager::updateDermaDOB(Dermatologist* derma)
{
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.preparedStatement("UPDATE derma SET WHERE d_DOB= ? AND d_ID = ?");


	ps->setInt(1, derma->DermaDOB);
	ps->setInt(2, derma->DermaID);

	int status = ps->executeUpdate();

	delete ps;

	return status;
}

int DermaManager::updateDermaPhoneNumber(Dermatologist* derma)
{
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.preparedStatement("UPDATE derma SET WHERE d_PhoneNumber= ? AND d_ID = ?");


	ps->setString(1, derma->DermaPhoneNumber);
	ps->setInt(2, derma->DermaID);

	int status = ps->executeUpdate();

	delete ps;

	return status;
}

int DermaManager::updateDermaAddress(Dermatologist* derma)
{
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.preparedStatement("UPDATE derma SET WHERE d_Address= ? AND d_ID = ?");


	ps->setString(5, derma->DermaAddress);
	ps->setInt(2, derma->DermaID);

	int status = ps->executeUpdate();

	delete ps;

	return status;
}
