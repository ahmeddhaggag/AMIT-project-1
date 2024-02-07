#include"std.h"
#ifndef _SDB_H_
#define _SDB_H_

typedef struct SimpleDb
{
 uint32 Student_ID;
 uint32 Student_year;
 uint32 Course1_ID;
 uint32 Course1_grade;
 uint32 Course2_ID;
 uint32 Course2_grade;
 uint32 Course3_ID;
 uint32 Course3_grade;
 
} student;
static uint8 entriesNumber = 0; //Records number of entries
student* entries[10];
bool SDB_AddEntry();
bool SDB_IsFull();
 uint8 SDB_GetUsedSize();
 void SDB_DeleteEntry(uint32 ID);
 bool SDB_ReadEntry(uint32 ID);
 bool SDB_DoesIdExist(uint32 ID);
 void SDB_GetList();
 void SDB_Action(uint8 choice);
 void SDB_App();

 #endif