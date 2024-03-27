#include <stdio.h>

#define FMT_FORM 1
#define FMT_TABLE 2
#define MAX_PETS 7

// C Strings: array sizes
#define NAME_LEN 15
#define PHONE_DESC_LEN 4
#define PHONE_LEN 10

// Data type: Phone
// ToDo:
struct Phone
{
    char description[PHONE_DESC_LEN];
    char number[PHONE_LEN];

};

// Data type: Patient 
// ToDo:
struct Patient
{
    int patientNumber;
    char name[NAME_LEN];
    struct Phone phone;
};

struct ClinicData
{
    struct Patient* patients;
    int maxPatient;
};


//Prototypes
void displayPatientTableHeader(void);
void displayFormattedPhone(const char* CString);
void displayPatientData(const struct Patient* patient, int fmt);
void displayAllPatients(const struct Patient patient[], int max, int fmt);
void searchPatients(struct ClinicData* addr, char idOrPhone);

void displayPatientTableHeader(void)
{
    printf("Pat.# Name            Phone#\n"
           "----- --------------- --------------------\n");
}
//Function 06 displayFormattedPhone
void displayFormattedPhone(const char* CString)
{
    int sizeCString = 0; // size of the array
    int i = 0;

    if (CString == NULL) //Handles the NULL case
    {
        printf("(___)___-____");
        return;
    }
    //check the size of the array
    for (i = 0; CString[i] != '\0'; i++)
    {
        //This will validade the digits (0 - 9)
        if (CString[i] >= '0' && CString[i] <= '9')
        {
            sizeCString++; //It will count only validated digits
        }
    }
    if (sizeCString != 10) //If the size is not exactly 10
    {
        printf("(___)___-____");
        return;
    }
    else //this will run only when the inout is exactly size 10
    {
        printf("(%c%c%c)%c%c%c-%c%c%c%c", CString[0],CString[1],CString[2],CString[3],
        CString[4],CString[5],CString[6],CString[7],CString[8],CString[9]);
        return;
    }
}

void displayPatientData(const struct Patient* patient, int fmt)
{
    if (fmt == FMT_FORM)
    {
        printf("Name  : %s\n"
               "Number: %05d\n"
               "Phone : ", patient->name, patient->patientNumber);
        displayFormattedPhone(patient->phone.number);
        printf(" (%s)\n", patient->phone.description);
    }
    else
    {
        printf("%05d %-15s ", patient->patientNumber,
               patient->name);
        displayFormattedPhone(patient->phone.number);
        printf(" (%s)\n", patient->phone.description);
    }
}

void displayAllPatients(const struct Patient patient[], int max, int fmt)
{
    int i = 0;
    for (i = 0; i < max; i++)
    {
        if (patient[i].patientNumber != 0)
        {
            displayPatientData(&patient[i], fmt);
        }
    }
}

// Search for a patient record based on patient number or phone number
void searchPatientData(const struct Patient patient[], int max)
{
    int scenario;
    int patientID;
    switch (scenario)
    {
    case 1: //1) By patient number
        printf("Search by patient number: ");
        scanf("%d", &patientID);

        break;
    
    default:
        break;
    }
}


int main(void)
{   
    struct Patient pets[MAX_PETS] = { 
        {1024, "Shaggy Yanson", {"CELL","3048005191"} },
        {1032, "Puglsey Yanson", {"CELL","3048005191"} },
        {1040, "Beans Maulin", {"HOME","3649155831"} },
        {1048, "Banjo Codi", {"TBA",{'\0'}} },
        {1056, "Rover Davidov", {"WORK","7934346809"} },
        {0, "Renan Queiroz", {"WORK","6742826480"} }
    };
    struct ClinicData data = { pets, MAX_PETS};

    // Entry point to the application logic:
    displayAllPatients(pets, MAX_PETS, 2);

    return 0;
}
