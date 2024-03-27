struct Phone
{
	char			phoneDescription[20]; // Can be: CELL/HOME/WORK/TBA
	char			phoneNumber[11];
};

struct Patient
{
	int				patientID;
	char			patientName[20];
	struct Phone	patientPhone;
};

struct ClinicData
{
	struct Patient* patientsList;
	int				howManySlots; //How many patients we have
};

// Q. How to get the patient's ID if we know
// the pointer to clinic data - addr
// and the slot number - i?
// A. addr->patientsList[i].patientID

// Q. How to get the patient's name if we know
// the pointer to clinic data - addr
// and the slot number - i?
// A. addr->patientsList[i].patientName

// Q. How to get the patient's phone decription
// if we know the pointer to clinic data - addr
// andthe slot number - i?
// A. addr->patientsList[i].patientPhone.phoneDescription

// Q. How to get the patient's phone number
// if we know the pointer to clinic data - addr
// andthe slot number - i?
// A. addr->patientsList[i].patientPhone.phoneNumber


// UI - 4 menus

void menuMain(struct ClinicData* addr); //Already provided
/*
	declare 2 char input buffers: for selection and for yes/no answer
	do
	{
		print 3 selections
		get the selection (fgets())
		if it is '1' call menuPatientManagement(addr)
		if it is '2' print "not avail."
		if it is '0' ask "are you sure?"
	} while(selection[0] != '0' && yesNo[0] != 'y');
	print "goodbye"
*/

void menuPatientManagement(struct ClinicData* addr); //Already provided
/*
	declare char input buffer for selection
	do
	{
		print 6 selections
		get an answer
		if it is '1' call viewPatientData(addr)
		if it is '2' call menuSearchOptions(addr)
		if it is '3' call addPatient(addr)
		if it is '4' call menuEditPatient(addr)
		if it is '5' call removePatient(addr)
	} while(selection[0] != '0');
*/

void menuSearchOptions(struct ClinicData* addr);
/*
	do
	{
		print 3 selections
		get an answer
		if it is '1' or '2' call searchPatients(addr, buffer[0])
		(search can be done by ID or by phone number)
	} while(buffer[0] != '0');
*/

void menuEditPatient(struct ClinicData* addr); //Already provided
/*
	get the ID
	slotByID() - get the slot #
	do 
	{
		print 3 selections
		get an answer
		if it is '1' or '2' call editPatient(addr, buffer[0])
	} while buffer[0] != '0'
*/

// Data processing - 5 functions
void viewPatientData(struct ClinicData* addr);
/*
	print the table header
	for loop from 0 to addr->howManySlots - 1
		print the info only my record id != 0
		reuse displayFormattedPhone() (it is in core module)
	print "<ENTER> to continue..." message
	fgets();
*/

void searchPatients(struct ClinicData* addr, char idOrPhone);
/*
	scenario #1 search by ID (primary key)
		Ask the for the id
		get it - fgets()
		convert string to int - atoi()
		call slotByID()
		if the search is succesfull
			print all 4 fields
		else
			"*** No records found ***"
	scenario #2 search by phone
		Ask for the phone number
		get it - fgets()
		remove EOL character
		print the table header
		int found = 0
		loop from 0 to addr->howManySlots - 1
			use strcmp() to compare phone in the buffer and the 
			phone in DB
			print the record, set up "found" to 1
		if "found" is still 0, "*** No records found ***"	
*/

void addPatient(struct ClinicData* addr);
/*
	slotNumber = -1
	scan all the slots and if there is an empty one remember
	the slot number
	if slotNumber is still -1 print "Patient listing is FULL!"
	else
		ask for 4 pieces of data and save them in DB
		(for strings assignment is done through strcpy())
*/

void editPatient(struct ClinicData* addr, int slot, char nameOrPhone);
/*
	Scenario #1 Name changing
		ask for the new name
		get it, remove EOL!
		strcpy(destination string, source string)
	Scenario #2 Phone changing
		An extra menu is needed for phones descriptions
		If the phone is not TBD, ask for the phone number
		and save it in DB
*/

void removePatient(struct ClinicData* addr);
/*
	Ask the ID
	call slotByID()
	if the result is -1, message "... record not found!"
	if it is not show all the data about the pet to be removed
	ask "Are you sure?"
	get an answer
	if it is "n", message "operation aborted."
	if it is "y", put 0 in ID field, message "... removed!"
*/

// convert logical ID to physical slot, if not found -1 returned
int slotByID(struct ClinicData* addr, int id);

