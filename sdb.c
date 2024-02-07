#include"sdb.h"
#include"std.h"
#include<stdio.h>
#include<stdlib.h>


void SDB_App(){  //Function to be called in main()
    printf("Add three entries\n");
    //Prompts the user to enter at least three entries
    for(int i =0; i<3; i++){
        SDB_AddEntry();
    }
    uint8 choice;  /* The function will then prompt the user to choose
                    an action which will be stored in this variable */
 
    while(1){  //Runs the program infinitely until th user chooses to exit
     printf("Choose action:\n"); //Prompts user in each iteration
     //Actions: 
     printf("To add entry, enter 1\n"
         "To get used size in database, enter 2\n"
         "To read student data, enter 3\n" 
         "To get the list of all student IDs, enter 4\n"
         "To check is ID is existed, enter 5\n"
         "To delete student data, enter 6\n"
         "To check is database is full, enter 7\n"
         "To exit enter 0\n"
        );
     
        scanf("%hhu", &choice); //scans user input
        if(choice == 0){
            break; //Ends the program if user chooses 0
        }
        SDB_Action(choice);   //Executes chosen action
    }
    

}

void SDB_Action(uint8 choice){ /* Prompts the user for a number which corresponds to an action
    (a function) the program will perform by calling a function */
    uint32 ID; // To store ID entered by the user if the user chooses an action related to it
    switch(choice){
        case 1:
            SDB_AddEntry(); 
            break;
        case 2:
            printf("%u\n", SDB_GetUsedSize());
            break;
        case 3: 
            
            printf("Enter  student ID\n");
            scanf("%u", &ID);
            SDB_ReadEntry(ID); 
            printf("\n");
            break;

        case 4:
            SDB_GetList();
            printf("\n");
            break;

        case 5:
            printf("Enter  student ID\n");
            scanf("%u", &ID);
            if(SDB_DoesIdExist(ID)){
                printf("ID %u exists\n", ID);
            } else{
                printf("ID %u does not exist\n", ID);
            }
            break;

        case 6:
             
            printf("Enter  student ID\n");
            scanf("%u", &ID);
            SDB_DeleteEntry(ID);
            printf("Entry deleted");
            break;
            
        case 7:
            if(SDB_IsFull()){
            printf("Database full\n");
            } else{
            printf("Database is not full\n");
            }
            break;

    }
     printf("Entries: %d\n", entriesNumber); //Displays number of entries in each iteration of the super loop
} 


bool SDB_AddEntry(){ 
    if(entriesNumber < 10){ //Adds entry to database
    student* sPtr = (student*)malloc(sizeof(student)); //Allocates memory for a student variable
    if(sPtr == NULL){ // Checks if allocation failed
        return false; 
    }
    //Scans student information:
    printf("Enter student ID\n");
    scanf("%u", &(sPtr->Student_ID));
    printf("Enter student year\n");
    scanf("%u", &(sPtr->Student_year));
    printf("Enter course1 ID\n");
    scanf("%u", &(sPtr->Course1_ID));
    printf("Enter course1 grade\n");
    scanf("%u", &(sPtr->Course1_grade));
    printf("Enter course2 ID\n");
    scanf("%u", &(sPtr->Course2_ID));
    printf("Enter course2 grade\n");
    scanf("%d", &(sPtr->Course2_grade));
    printf("Enter course3 ID\n");
    scanf("%u", &(sPtr->Course3_ID));
    printf("Enter course3 grade\n");
    scanf("%u", &(sPtr->Course3_grade));

    entries[entriesNumber++] =sPtr; // Adds entry pointer to the entry to entries array then increments entriesNumber
    return true; //Entry added successfully
    }
    return false; // Will not add entry because entries array is full

}

void SDB_DeleteEntry(uint32 ID){
    for(int i =0; i<entriesNumber; i++){ // Checks added entries
        if(entries[i]->Student_ID == ID){ //Entry found
            entries[i] = NULL;  //Deletes entry
            entriesNumber--; 
            break;
        }

    }
    
}
bool SDB_ReadEntry(uint32 ID){
    for(int i =0; i<entriesNumber; i++){
        if(entries[i]->Student_ID == ID){ //Entry found
            printf("%d %d %d %d %d %d %d %d", entries[i]->Student_ID, entries[i]->Student_year, entries[i]->Course1_ID, entries[i]->Course1_grade, entries[i]->Course2_ID,entries[i]->Course2_grade, entries[i]->Course3_ID, entries[i]->Course3_grade);
            // Prints entry information
            return true; //Success
        }  
    }
    return false; //Entry not found
}
bool SDB_DoesIdExist(uint32 ID){ //Checks whether the given student ID exists or not
    for(int i =0; i<entriesNumber; i++){ //Searches entries
        if((entries[i]->Student_ID) == ID){ // Entry found
            return true; //Found
        }
    }
        return false; //Not found
}
void SDB_GetList(){ //Prints list of entered student IDs
    printf("Student IDs: \n");
    for(int i = 0; i<entriesNumber; i++){ 
        printf("%u\n", entries[i]->Student_ID);
    }

}

bool SDB_IsFull(){ //Checks if the database is full
    if(entriesNumber == 10 ){ // Max: 10
        return true;
    } 
    return false;
}
uint8 SDB_GetUsedSize(){ // returns number of students in database
    return (uint8)entriesNumber;
 
}






