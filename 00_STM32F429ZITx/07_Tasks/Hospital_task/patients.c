#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int ID;
    char name[30];
    float weight;
}patient;

unsigned int nb_patients;
patient* ptn;

void Search_data_from_ID(int id);
void Get_Patients_data(patient *ptn);
void Display_Patients();
void info(int i);

int main(void)
{
    int id;
    int choice;

    printf("Enter the number of patients : ");
    scanf("%d", &nb_patients);
    ptn = malloc(nb_patients * sizeof(patient));

    Get_Patients_data(ptn);
    
    printf("1 : Display all patients\n2: Choose one patient\nAny key to quit\n--> ");
    scanf("%d", &choice);

    if (choice == 1)
    {
        Display_Patients();
    }
    else if (choice == 2)
    {
        printf("Enter the ID of the patient : ");
        scanf("%d", &id);
        Search_data_from_ID(id);
    }

    free(ptn);
}

void Get_Patients_data(patient *ptn)
{
    for(int i = 0; i < nb_patients; i++)
    {
        printf("ID of Patient : ");
        scanf("%d", &((ptn + i)->ID));
        fflush(stdin);
        printf("Name of Patient : ");
        scanf("%s", &((ptn + i)->name));
        fflush(stdin);
        printf("Weight of Patient : ");
        scanf("%f", &((ptn + i)->weight));
        printf("\n");
        fflush(stdin);
    }
}

void Search_data_from_ID(int id)
{
    for (int i = 0; i < nb_patients;i++)
    {
        if((ptn+i)->ID == id)
        {
            info(i);
        }
    }
}

void info(int i)
{
    printf("\nPatient number %d : ", i + 1);
    printf("\nName : %s", (ptn + i)->name);
    printf("\nWeight : %.2f", (ptn + i)->weight);
}

void Display_Patients()
{
    for (int i = 0; i < nb_patients; i++)
    {
        info(i);
    }
}