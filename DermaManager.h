#ifndef DERMAMANAGER_H
#define DERMAMANAGER_H

class DermaManager
{
public:

	bool checkTableDerma(Dermatologist* derma);
	int addDerma(Dermatologist* derma);
	int updateDermaName(Dermatologist* derma);
	int updateDermaDOB(Dermatologist* derma);
	int updateDermaPhoneNumber(Dermatologist* derma);
	int updateDermaAddress(Dermatologist* derma);
	Dermatologist* searchDerma(int DermaID);
	bool loginDerma(Dermatologist* derma);
}; 

#endif