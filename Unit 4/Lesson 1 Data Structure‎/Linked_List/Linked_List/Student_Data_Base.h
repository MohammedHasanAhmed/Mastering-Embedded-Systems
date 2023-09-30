/*
 ==========================================================================
 Name        : Student_Data_Base.h
 Author      : Mohammed Hasan
 Created on	 : 9/30/2023
 Description : Linked List (Student Data Base)
 ==========================================================================
 */


#ifndef Student_Data_Base_H_
#define Student_Data_Base_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#define DPRINTF(...) { \
		fflush stdout; fflush stdin; \
		printf(__VA_ARGS__); \
		fflush stdout; fflush stdin; \
}

/*============= Type Definitions =============*/
struct SData
{
	int ID;
	char name[30];
	float height;
};

struct SStudent
{
	struct SData Student;
	struct SStudent *pNext_Student;
};

/*==================== APIs ====================*/
void Fill_the_record(struct SStudent *New_Student); 		// Fill Student Data.
void Add_Student();                                			// Add a Student to the list.
int Delete_Student();                               		// Delete a Student from list.
void View_Students();                               		// View Data of All Students.
void Delete_All();                                  		// Delete All the Students in the list.
void Get_Node(unsigned int index);							// Get a Student form the list.
int Get_Count_Iterative();									// Get Number of Student in list by Iterative.
int Get_Count_Recursive(struct SStudent* pTemp_Student);	// Get Number of Student in list by Recursive.
void Get_Node_From_End(unsigned int index);					// Get a Student from the end.
void Get_Middle();											// Get Middle Student in the list.
void Reverse_Students_List();								//Reverse the arrangements of the list.


#endif
