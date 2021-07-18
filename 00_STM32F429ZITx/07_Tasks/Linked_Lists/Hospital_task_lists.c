#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct
{
    int ID;
    char name[30];
    float weight;
    struct patient* next;
}patient;

patient *ptn = NULL;
unsigned int nb_patients;


void Get_Patient_data();
void Display_Patients();
void Search_patient_from_ID(int id);
void Delete_Patient_data_from_id();
void Modify_patient_info(int id);
void menu();

int main(void)
{

    printf("Enter the number of patients : ");
    scanf("%d", &nb_patients);
    fflush(stdin);

    //add patient data every call 
    for (int i = 0; i < nb_patients; i++)
    {
     Get_Patient_data();
    }

    while(1)
    {
        menu();
    }
    free(ptn);
}

void Get_Patient_data()
{
    patient* temp = (patient*)malloc(sizeof(patient));

    printf("ID of Patient : ");
    scanf("%d", &(temp->ID));
    printf("Name of Patient : ");
    scanf("%s", &(temp->name));
    printf("Weight of Patient : ");
    scanf("%f", &(temp->weight));
    printf("\n");

    temp->next=NULL;
    patient* temp2 = ptn;

    if (temp2 == NULL)
    {
        ptn = temp;
    }
    else
    {
        while (temp2->next != NULL)
        {
            temp2 = temp2->next;
        }
        temp2->next = temp;
    }
}

void Display_Patients()
{
    int i = 0;
    patient *temp = ptn;

    if (temp == NULL)
    {
        printf("No data\n");
        return;
    }
    while (temp != NULL)
    {
        printf("\nPatient number %d : ", i + 1);
        printf("\nID : %d", temp->ID);
        printf("\nName : %s", temp->name);
        printf("\nWeight : %.2f", temp->weight);
        temp = temp->next;
        i++;
    }
}

void Search_patient_from_ID(int id)
{
    bool exists = false;
    patient* temp = ptn;

    while (temp != NULL)
    {
        if (temp->ID == id)
        {
            printf("\nName : %s", temp->name);
            printf("\nWeight : %.2f", temp->weight);
            exists = true;
        }
        temp = temp->next;
    }
    if(!exists)
    {
        printf("Patient of ID %d not exist\n\n",id);
        menu();
    }
    else
    {
        menu();
    }
}

void Delete_Patient_data_from_id(int id)
{
    bool exists = false;
    patient *temp = ptn;
    patient *previous = NULL;

    //to delete head
    if (temp->ID == id)
    {
        ptn = temp->next;
        free(temp);
        printf("\nDone, Thanks for choosing other option\n");
        exists = true;
    } //to delete middle or end
    else
    {
        while (temp != NULL && exists == false)
        {
            previous = temp;
            temp = temp->next;
            if (temp->ID == id)
            {
                previous->next = temp->next;
                printf("\nDone, Thanks for choosing other option\n");
                exists = true;
            }
        }
    }
    
    if (!exists)
    {
        printf("Patient of ID %d already not exist\n\n", id);
        menu();
    }
    else
    {
        menu();
    }
}

void Modify_patient_info(id){
    patient* new_patient = ptn;
    while(new_patient != NULL)
    {
        if(new_patient->ID == id)
        {
            printf("Enter the new name : ");
            scanf("%s", &(new_patient->name));
            fflush(stdin);
            printf("Enter the new weight : ");
            scanf("%f", &(new_patient->weight));
            fflush(stdin);
        }
        new_patient = new_patient->next;
    }
    printf("Done : choose other option : ");
    menu();
}

void menu()
{
    int choice, id;

    printf("\n\n1: Display all patients\n2: Choose one patient\n3: Add a patient\n4: Delete a patient\n5: Modify a patient\nAny key to quit\n--> ");
    scanf("%d", &choice);
    fflush(stdin);

    if (choice == 1)
    {
        Display_Patients();
    }
    else if (choice == 2)
    {
        printf("Enter the ID of the patient : ");
        scanf("%d", &id);
        fflush(stdin);
        Search_patient_from_ID(id);
    }
    else if (choice == 3)
    {
        Get_Patient_data();
    }
    else if (choice == 4)
    {
        printf("Enter the ID of the patient you want to delete : ");
        scanf("%d", &id);
        fflush(stdin);
        Delete_Patient_data_from_id(id);
    }
    else if (choice == 5)
    {
        printf("Inter The ID of the patient you want to modify his Info : ");
        scanf("%d",&id);
        fflush(stdin);
        Modify_patient_info(id);
    }
    else
    {
        exit(1);
    }
}