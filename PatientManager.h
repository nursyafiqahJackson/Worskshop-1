#ifndef PATIENTMANAGER_H
#define PATIENTMANAGER_H

class PatientManager
{
public:

	int addPatient(Patient* patient);
	int updatePatient(Patient* patient);
	void searchPatient(string PatientID);
};

#endif
