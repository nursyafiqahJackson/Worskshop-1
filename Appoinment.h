#include <string>
#include <ctime>

using namespace std;

#ifndef APPOINMENT_H
#define APPOINMENT_H

class Appoinment
{
public:
	int AppoinmentID, PatientID;
	string TreatmentName;
	time_t AppoinmentDate;

};
#endif
