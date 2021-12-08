#include <string>
using namespace std;

#include <mysql/jdbc.h>
using namespace sql;

#ifndef DATABASECONNECTION_H
#define DATABASECONNECTION_H

class DatabaseConnection
{
private:
		Connection* connection;

public:
	DatabaseConnection();
	~DatabaseConnection();

	PreparedStatement* preparedStatement(string sql);
};

#endif 