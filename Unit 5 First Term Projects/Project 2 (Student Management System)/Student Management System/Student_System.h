/*
 ==========================================================================
 Name        : Student_System.h
 Author      : Mohammed Hassan
 Created on	 : Oct 30, 2023
 Description : First Term Project 2
 ==========================================================================
 */

#ifndef STUDENT_SYS_H_
#define STUDENT_SYS_H_

#include <stdio.h>
#include <stdint.h>
#include <string.h>
// ===========>> printf <<===========
#define print(...)		\
		fflush(stdin);fflush(stdout); \
		printf(__VA_ARGS__);          \
		fflush(stdin);fflush(stdout);


// ===========>> Macros <<===========
#define Name_Length     20
#define Number_Courses  5
#define Max_Number_Students  50

// ===========>> Student information <<===========
struct Studen_info_t
{
	char first_name[Name_Length];
	char last_name[Name_Length];
	int roll ;
	float GPA ;
	int Course_id[Number_Courses];
};
typedef struct Studen_info_t SStudent_Node ;

// ===========>> Type Definition <<===========
typedef struct
{
	SStudent_Node* base ;
	SStudent_Node* head ;
	SStudent_Node* tail ;
	uint32_t length ;
	uint32_t count ;
} FIOF_Buf_t;

// ===========>> Buf Status <<===========
typedef enum
{
	FIFO_no_error,
	FIFO_full,
	FIFO_empty,
	FIFO_Null
} FIFO_Buf_Status;

// ==============>> APIs <<==============

FIFO_Buf_Status FIFO_init(FIOF_Buf_t* Student_Queue, SStudent_Node* Buf, uint32_t length );	    // Student Queue Initialization
FIFO_Buf_Status FIFO_enqueue(FIOF_Buf_t* Student_Queue, SStudent_Node Student);
FIFO_Buf_Status FIFO_is_Full(FIOF_Buf_t* Student_Queue); 			                            // Check FIFO Full

void Add_Student_manually(FIOF_Buf_t* Student_Queue);

void Add_Student_From_File(FIOF_Buf_t* Student_Queue);

void Find_Student_By_id(FIOF_Buf_t* Student_Queue);

void Find_Student_By_FirstName(FIOF_Buf_t *Student_Queue);

void Find_Student_By_Course_id(FIOF_Buf_t *Student_Queue);

void Delete_Student_By_id(FIOF_Buf_t *Student_Queue);

void Update_Student_By_id(FIOF_Buf_t *Student_Queue);

void Print_Student_Count(FIOF_Buf_t *Student_Queue);											// print total Number of Students
void Show_Student_Information(FIOF_Buf_t *Student_Queue);										// View all Students information
void print_Student_info(SStudent_Node *student);                                                // print information of Student

struct Studen_info_t *Check_Student_id(FIOF_Buf_t *Student_Queue, uint32_t id);                 // Check if student is exist or not

#endif /* STUDENT_SYS_H_ */
