#include <string>
using namespace std; 

#include <mysql/jdbc.h>
using namespace sql;

#include "DatabaseConnection.h"

class DatabaseConnection
{
	DatabaseConnection()
	{
		mysql::MySQL_Driver* driver = mysql::get_mysql_driver_instance();
		connection = driver->connect("tcp://127.0.0.1:3306", "root", "");
		
		connection->setSchema("dbaestheticclinic");
	}

	~DatabaseConnection::~DatabaseConnection()
	{
		connection->close();
		delete connection;
	}

	PreparedStatement* DatabaseConnection::preparedStatement(string query)
	{
		return connection->prepareStatement(query);
	}
};