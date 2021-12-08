#include <string>
#include <ctime>
using namespace std;

#ifndef DERMATOLOGIST_H
#define DERMATOLOGIST_H

class Dermatologist
{
public:
	int DermaID;
	string DermaName, DermaPassword, DermaAddress, DermaPhoneNumber;
	time_t DermaDOB;

};
#endif 