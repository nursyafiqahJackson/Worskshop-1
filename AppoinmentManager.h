#ifndef APPOINMENT_H
#define APPOINMENT_H

class AppoinmentManager
{
public:

	int appointment(Appoinment* appoinment, int PatientID);
	bool checkTableAppointment(Appoinment* appoinment);
	int selectMax();
	int AppoinmentManager(Appoinment* appoinment, int PatientID);
	int Appoinment(Appoinment* appoinment, int PatientID);
	Appoinment* selectBooked(int AppoinmentID);
	bool checkToDelete(Appoinment* appoinment);
	int deleteAppoinment(Appoinment* appoinment);
};

#endif
