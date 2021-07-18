#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
/* GLOBAL VARIABLES */
#define PATIENT_NAME_MAX 29

/* PATIENTS_CONFIG.h */
typedef struct
{
    int ID;
    char patientName[PATIENT_NAME_MAX];
    float weight;
    struct patientStruct *pointer; //ADDED A POINTER TO NEXT NODE

} patientStruct;

patientStruct *patientPtrStruct = NULL; // A POINTER POINTING TO THE ARRAY OF PATIENTS [HEAD NODE IN CASE OF LINKED LISTED]

//int pSize; //PATIENTS SIZE [ARRAY SIZE]
// NOT USED IN LINKED LIST ^^

/* FUNCTION DECLARATIONS */

patientStruct *Get_Patient_Index(patientStruct *ptr, unsigned int SearchID);

void Print_Patient_Data(patientStruct *patient);

void Print_All_Patient_Data();

void user_Interface();

void Modify_Patient_Data(patientStruct *patient, int ID, char *patientName, float weight);

void Add_Patient();

patientStruct *Get_Patient_Index(patientStruct *ptr, unsigned int SearchID);

void Remove_Patient_Data(patientStruct *patientPrev, patientStruct *patient);

patientStruct *Get_Patient_Prev_Index(patientStruct *ptr, unsigned int SearchID);

/* MAIN CODE */

int main(void)
{
    int pSize;
    printf("[SYS] Enter the number of Patients: "); // ASK FOR PATIENT SIZE
    scanf("%d", &pSize);                            // SCANNING ARRAY SIZE
    for (int i = 0; i < pSize; i++)
    {
        Add_Patient();
    }
    user_Interface();
    free(patientPtrStruct);
}

//GET PATIENT INDEX IS MODIFIED TO GET THE ADDRESS OF THE NODE TO GET USED IN OTHER FUNCTIONS
//HINT: YOU HAVE TO PASS A HEAD NODE OR A NODE ADDRESS THAT'S POINTING TO A NODE
//RETURNS NULL IF THERE WAS NO MATCH
/*          FUNCTIONS           */
//FUNCTION WAS MODIFIED TO TAKE THE ADDRESS OF THE NODE CARRYING THE PATIENT DATA

void Add_Patient()
{
    patientStruct *temp = (patientStruct *)malloc(sizeof(patientStruct)); //CREATING THE DATA FOR THE PATIENT
    printf("[SYS] Enter the name of the patient: ");
    scanf("%s", temp->patientName); //INSERT THE PATIENT NAME
    printf("[SYS] Enter the ID of this patient: ");
    scanf("%d", &(temp->ID)); //INSERT THE PATIENT ID
    printf("[SYS] Enter the patient weight: ");
    scanf("%f", &(temp->weight)); // INSERT THE WEIGHT*/
    temp->pointer = NULL;         // ASSIGN THE NODE POINTER TO NOT POINT AT ANYTHING
    //CREATING THE DATA FOR THE PATIENT
    patientStruct *tempo = patientPtrStruct; //CREATING A TEMP POINTER THAT POINTS TO HEAD NODE
    if (tempo == NULL)
    {                            // CHECK FOR THE FIRST ENTRY
        patientPtrStruct = temp; //ASSIGN HEAD NODE TO FIRST NODE
        return;                  //END THE LOOP
    }
    while (tempo->pointer != NULL) //CHECKING IF HEAD NODE IS POINTING AT ANYTHING, IF YES, GO TO THE NEXT NODE
        tempo = tempo->pointer;    //ASSIGN OLD TEMPORARY POINTER TO THE NEW TEMPORARY POINTER
    tempo->pointer = temp;         // ASSIGN THE TEMP POINTER TO THE ADDRESS OF THE NEW TEMPORARY STRUCTURE
}

patientStruct *Get_Patient_Prev_Index(patientStruct *ptr, unsigned int SearchID)
{
    ptr = patientPtrStruct;
    patientStruct *ptrPrev = NULL;
    while (ptr != NULL)
    {
        if (ptr->ID == SearchID)
        {
            ptrPrev = ptr;
            ptr = ptr->pointer;
        }
    }
    return ptrPrev;
}

patientStruct *Get_Patient_Index(patientStruct *ptr, unsigned int SearchID)
{
    if (ptr == NULL)
        printf("[SYSERROR] DB: A WRONG DATA WAS INSERTED!");
    while (ptr != NULL)
    {
        if (ptr->ID == SearchID)
            return ptr;
        ptr = ptr->pointer;
    }
    return NULL;
}
//IMPORTANT
//YOU HAVE TO PASS THE PREVIOUS POINTER TO STRUCT TO THIS FUNCTION TO WORK
//OR ELSE YOU WON'T BE ABLE TO GET IT TO WORK
void Remove_Patient_Data(patientStruct *patientPrev, patientStruct *patient)
{
    patientPrev->pointer = patient->pointer;
}

void Modify_Patient_Data(patientStruct *patient, int ID, char patientName[29], float weight)
{
    patient->ID = ID;
    strcpy(patient->patientName, patientName);
    patient->weight = weight;
}
void Print_Patient_Data(patientStruct *patient)
{
    printf("[DATA] Patient Name: %s\n", patient->patientName);
    printf("[DATA] Patient Weight: %0.1f\n", patient->weight);
    printf("[DATA] Patient ID: %d\n", patient->ID);
    printf("[DATA] Address in MEMORY: %p\n", (void *)patient);
}

void Print_All_Patient_Data()
{
    if (patientPtrStruct == NULL)
        printf("[SYSERROR] INTERFACE: YOU HAVE ENTERD NO DATA");
    patientStruct *patient = patientPtrStruct;
    while (patient != NULL)
    {
        printf("[DATA] Patient Name: %s\n", patient->patientName);
        printf("[DATA] Patient Weight: %0.1f\n", patient->weight);
        printf("[DATA] Patient ID: %d\n", patient->ID);
        printf("[DATA] Address in MEMORY: %p\n", (void *)patient);
        patient = patient->pointer;
    }
}

void user_Interface()
{
    user_Interface_Text();
    while (1)
    { // LOOP TO KEEP PROGRAM GOING
        char c;
        if (kbhit())
        {                //Checks if a key on the keyboard was pressed
            c = getch(); // Stores that key into C without showing it on the Command Prompt
            switch (c)
            {
                patientStruct *temp; //Temporary Struct Pointer used in most cases
                int searchID;        //Search ID used in Most cases
            case '1':                //GO BACK TO USER INTERFACE FUNCTION TO SEE CASE OF 1
                Print_All_Patient_Data();
                user_Interface_Text();
                break;
            case '2': // GO BACK TO USER INTERFACE FUNCTION TO SEE CASE OF 1
                printf("Please insert the ID of the Patient: ");
                int x = 0; // temp integer to store the ID for comparison
                scanf("%d", &x);
                temp = Get_Patient_Index(patientPtrStruct, x);
                if (temp == NULL)
                {
                    printf("[SYS] You have entered an invalid ID\n");
                    user_Interface_Text();
                    break;
                }
                else
                    Print_Patient_Data(temp);
                user_Interface_Text();
                break;
            case '3':
                printf("[SYS] Enter the ID of the patient details you want to modify\n");
                scanf("%d", &searchID);
                temp = Get_Patient_Index(patientPtrStruct, searchID);
                printf("[SYS] Enter the name of the patient: ");
                scanf("%s", temp->patientName); //INSERT THE PATIENT NAME
                printf("[SYS] Enter the ID of this patient: ");
                scanf("%d", &(temp->ID)); //INSERT THE PATIENT ID
                printf("[SYS] Enter the patient weight: ");
                scanf("%f", &(temp->weight));
                printf("[SYS] PATIENT DETAILS HAVE BEEN UPDATED!\n");
                user_Interface_Text();
                break;
            case '4':
                Add_Patient();
                user_Interface_Text();
                break;
            case '5':
                printf("[SYS] Enter the ID of the patient details you want to delete\n");
                scanf("%d", &searchID);
                patientStruct *prevIndex = Get_Patient_Prev_Index(patientPtrStruct, searchID);
                temp = Get_Patient_Index(patientPtrStruct, searchID);
                Remove_Patient_Data(prevIndex, temp);
                user_Interface_Text();
                break;
            case '6':
                return;
            }
        }
    }
}
void user_Interface_Text()
{
    printf("[SYS] Press 1 to Print All Data of Patients\n");
    printf("[SYS] Press 2 to Print data of a Single Patient\n");
    printf("[SYS] Press 3 to Modify the List of Patients\n"); //WILL BE IMPLEMENTED USING LINKED LISTS
    printf("[SYS] Press 4 to Add a patient to the List\n");
    printf("[SYS] Press 5 to Remove a patient from the List\n");
    printf("[SYS] Press 6 to end the Program\n");
}
//TEST_PURPOSE
//printf("\n%s %d %0.1f", patientPtrStruct->patientName, patientPtrStruct->ID, patientPtrStruct->weight);