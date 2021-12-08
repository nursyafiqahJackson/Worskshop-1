
#ifndef TREATMENTMANAGER_H
#define TREATMENTMANAGER_H


class TreatmentManager
{
public:

	bool checkTableTreatment(Treatment* treatment);
	int addTreatment(Treatment* treatment);
	int updateTreatmentName(Treatment* treatment);
	int updateTreatmentCost(Treatment* treatment);
	int updateTreatmentType(Treatment* treatment);
	
	Treatment* displayTest(string dermatID);
};

#endif