#include <string>
#include <ctime>

using namespace std;

#ifndef PATIENT_H
#define PATIENT_H

class Patient
{
public:
	int PatientID;
	string PatientName, PatientPassword, PatientAddress, PatientPhoneNumber;
	time_t PatientDOB;

};
#endif
