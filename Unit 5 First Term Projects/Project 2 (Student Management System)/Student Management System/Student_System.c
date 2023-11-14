/*
 ==========================================================================
 Name        : Student_System.c
 Author      : Mohammed Hassan
 Created on	 : Oct 30, 2023
 Description : First Term Project 2
 ==========================================================================
 */
#include "Student_System.h"

// ==============>> Initialize FIFO Buffer <<==============
FIFO_Buf_Status FIFO_init(FIOF_Buf_t *Student_Queue, SStudent_Node *Buf, uint32_t length)
{
	if (Buf == NULL)
	{
		return FIFO_Null;
	}
	// Initialize Students Data Base
	Student_Queue->base = Buf;
	Student_Queue->head = Buf;
	Student_Queue->tail = Buf;
	Student_Queue->length = length;
	Student_Queue->count = 0;
	return FIFO_no_error;
}

// ==============>> Add Student Manually <<==============
void Add_Student_manually(FIOF_Buf_t *Student_Queue)
{
	SStudent_Node New_Student;
	int i;

	// *Check if Student Data Base is valid
	if (!Student_Queue->base || !Student_Queue->head || !Student_Queue->tail)
	{
		print("\n******************************************************\n");
		print("* [ERROR] Student Data Base Initialization ==>> Failed\n");
		print("*******************************************************\n");
		return;
	}

	// *Check if Student Data Base is Full
	if (Student_Queue->count == Student_Queue->length)
	{
		print("***********************************************\n");
		print("* [ERROR] Student Data Base is ==>> Full\n");
		print("***********************************************\n");
		return;
	}

	// * ADD STUDENT INFORMATION
	print("\t\t\t==================================================\n");
	print("\t\t\t==>>            Enter Student Data            <<==\n");
	print("\t\t\t==================================================\n\n");

	print(" Enter Student id : ");
	scanf("%d", &New_Student.roll);

	if (Check_Student_id(Student_Queue, New_Student.roll))
	{
		print("\n*********************************************************\n");
		print("* [ERROR] Roll Number %d is Already Taken Before\n", New_Student.roll);
		print("* [ERROR] Adding Student Manually Failed\n");
		print("*********************************************************\n");
		return ;
	}
	else
	{
		print(" Enter Student First Name : ");
		scanf("%s", New_Student.first_name);

		print(" Enter Student Last Name : ");
		scanf("%s", New_Student.last_name);

		print(" Enter Student GPA : ");
		scanf("%f", &New_Student.GPA);

		for (i = 0; i < Number_Courses; i++)
		{
			print(" Enter Course id Number %d : ", i + 1);
			scanf("%d", &New_Student.Course_id[i]);
		}
		if (FIFO_enqueue(Student_Queue, New_Student) == FIFO_no_error)
		{
			print("\n***********************************************\n");
			print("* [INFO] Student Details is Added Successfully");
		}
		else
		{
			print("***********************************************\n");
			print("* [ERROR] Adding Student Manually Failed\n");
			print("***********************************************\n");
			return;
		}
	}
	Print_Student_Count(Student_Queue);
}

// ==============>> Add Student From File <<==============
void Add_Student_From_File(FIOF_Buf_t *Student_Queue)
{
	FILE *Student_file;
	SStudent_Node New_Student;
	int i;

	//* Open Text file
	Student_file = fopen("Student_Data.txt", "r");

	//* check if this file is exist or not
	if (Student_file == NULL)
	{
		print("***********************************************\n");
		print("* [ERROR] this File not fount\n");
		print("* [ERROR] Add Student From File Failed\n");
		print("***********************************************\n");
		return;
	}
	//* reading file information until end of file
	while (!feof(Student_file))
	{
		//* Reading Student id from file
		fscanf(Student_file, "%d", &New_Student.roll);
		if (Check_Student_id(Student_Queue, New_Student.roll))
		{
			print("***********************************************\n");
			print("* [ERROR] Roll Number %d is Already Taken Before\n", New_Student.roll);
			print("***********************************************\n\n");
			fscanf(Student_file, "%*[^\n]");
			continue ;
		}

		fscanf(Student_file, "%s", New_Student.first_name);
		fscanf(Student_file, "%s", New_Student.last_name);
		fscanf(Student_file, "%f", &New_Student.GPA);

		for(i = 0 ; i < Number_Courses ; i++)
		{
			fscanf(Student_file, "%d", &New_Student.Course_id[i]);
		}

		if(FIFO_enqueue(Student_Queue, New_Student) == FIFO_no_error)
		{
			print("* [INFO] Roll Number %d is Saved Successfully\n", New_Student.roll);
		}
		else
		{
			print("***********************************************\n");
			print("* [ERROR] Adding Student From File Failed\n");
			print("***********************************************\n");
			return ;
		}
	}
	print("* [Info] Student Details Are Saved Successfully ");
	Print_Student_Count(Student_Queue);

	//* Close text file
	fclose(Student_file);
}

// ==============>> Find Student by id <<==============
void Find_Student_By_id(FIOF_Buf_t* Student_Queue)
{
	int Student_id;
	SStudent_Node* Student ;
	// *Check if Student Data Base is Empty
	if (Student_Queue->count == 0)
	{
		print("***********************************************\n");
		print("* [ERROR] Student Data Base is Empty\n");
		print("***********************************************\n");
		return;
	}
	print("***********************************************\n");
	print("Enter Student id number you want to find :")
	scanf("%d", &Student_id);


	Student = Check_Student_id(Student_Queue, Student_id);
	if(Student == NULL)
	{
		print("***********************************************\n");
		print("* [ERROR] Student id number %d not found \n", Student_id);
		print("***********************************************\n");
		return ;
	}
	else
	{
		print("Student id : %d is Found Successfully\n", Student_id);
		print_Student_info(Student);
	}
}
// ==============>> Find Student by First Name  <<==============
void Find_Student_By_FirstName(FIOF_Buf_t *Student_Queue)
{
	SStudent_Node* Student = Student_Queue->tail ;
	char First_Name[Name_Length] ;
	int i, flag = 0 ;

	// *Check if Student Data Base is Empty
	if (Student_Queue->count == 0)
	{
		print("***********************************************\n");
		print("* [ERROR] Student Data Base is Empty\n");
		print("***********************************************\n");
		return;
	}
	print("Enter Student First Name :")
	scanf("%s",First_Name);

	for(i = 0 ; i < Student_Queue->count ; i++)
	{
		if(strcmp(First_Name, Student->first_name) == 0)   // not identical
		{
			print("\n***********************************************\n");
			print("Student : %s is found Successfully\n",First_Name);
			print_Student_info(Student);
			flag = 1 ;
			return ;
		}
		// Check if we reach the last item in the queue
		if((Student + 1) == (Student_Queue->base + Student_Queue->length))
		{
			Student = Student_Queue->base;
		}
		else
		{
			Student++;
		}
	}
	if(!flag)
	{
		print("***********************************************\n");
		print("* [ERROR] Student %s Not found \n", First_Name );
		print("***********************************************\n");
		return ;
	}

}
// ==============>> Find Student by course id <<==============
void Find_Student_By_Course_id(FIOF_Buf_t *Student_Queue)
{
	SStudent_Node* Student = Student_Queue->tail ;
	int i, j,counter = 0, Course_id;

	if (Student_Queue->count == 0)
	{
		print("***********************************************\n");
		print("* [ERROR] Student Data Base is Empty\n");
		print("***********************************************\n");
		return;
	}

	print("Enter course id: ");
	scanf("%d", &Course_id);

	for(i = 0 ; i < Student_Queue->count ; i++)
	{
		for(j = 0 ; j < Number_Courses ; j++)
		{
			if(Student->Course_id[j] == Course_id)
			{
				print_Student_info(Student);
				counter++ ;
			}
		}
		Student++;
	}
	if(counter == 0)
	{
		print("***********************************************\n");
		print("* [ERROR] Course ID %d Not found on the System\n", Course_id);
		print("***********************************************\n");
		return;
	}
	else
	{
		print("***********************************************************\n");
		print("[INFO] Number of Students enrolled in this course is : %d\n", counter);
		print("***********************************************************\n");
	}
}
// ==============>> Delete Student By id <<==============
void Delete_Student_By_id(FIOF_Buf_t *Student_Queue)
{
	int Student_id, i, flag = 0 ;
	SStudent_Node* Student = Student_Queue->base ;

	if (Student_Queue->count == 0)
	{
		print("***********************************************\n");
		print("* [ERROR] Student Data Base is Empty\n");
		print("***********************************************\n");
		return;
	}

	print("Enter Student id to Delete it from the system: ");
	scanf("%d", &Student_id);

	for(i = 0 ; i < Student_Queue->count ; i++)
	{
		if(Student->roll == Student_id)
		{
			*Student = *(Student_Queue->tail);
			Student_Queue->count-- ;

			if( (Student_Queue->tail+1) == (Student_Queue->base + Student_Queue->length) )
			{
				Student_Queue->tail = Student_Queue->base ;
			}
			else
			{
				Student_Queue->tail++;
			}
			flag = 1 ;
			break ;
		}

		else
		{
			flag = 0 ;
		}
		Student++ ;
	}

	if(flag == 1)
	{
		print("***************************************************\n");
		print("* [INFO] Student ID Number %d Removed Successfully\n", Student_id);
		print("***************************************************\n");
	}
	else
	{
		print("***********************************************\n");
		print("* [ERROR] Student ID Number %d Not found\n",Student_id );
		print("***********************************************\n");
	}
}
// ==============>> Update Student Data <<==============
void Update_Student_By_id(FIOF_Buf_t *Student_Queue)
{
	SStudent_Node* Student = Student_Queue->tail;
	SStudent_Node *Student_Data_mod ;
	int option_number, Student_id, New_Student_id, i, flag = 0;

	if (Student_Queue->count == 0)
	{
		print("***********************************************\n");
		print("* [ERROR] Student Data Base is Empty\n");
		print("***********************************************\n");
		return;
	}
	print(" Enter Student id to update data: ");
	scanf("%d", &Student_id);

	Student_Data_mod = Check_Student_id(Student_Queue, Student_id);
	if(Student_Data_mod != NULL)
	{
		print("\n\t\t****************\n");
		print("\t\t* Student Data *\n");
		print("\t\t****************\n");
		print_Student_info(Student_Data_mod);
		print("\n***********************************************\n");
	}
	else
	{
		print("***********************************************\n");
		print("* [ERROR] Student ID number %d Not found\n", Student_id);
		print("***********************************************\n");
		return ;
	}

	print(" What do you want to change\n");
	print(" 1: Student ID Number\n");
	print(" 2: Student First Name\n");
	print(" 3: Student Last Name\n");
	print(" 4: Student GPA\n");
	print(" 5: Student Course ID\n\n");
	print("Enter the Number: ");
	scanf("%d", &option_number);

	switch(option_number)
	{
	case 1:
		print(" \nEnter the New Student ID: ");
		scanf("%d", &New_Student_id);

		for(i = 0 ; i < Student_Queue->count ; i++)
		{
			while(Student->roll == New_Student_id)
			{
				print("***********************************************\n");
				print("* [ERROR] Roll Number %d is Exist\n", New_Student_id);
				print("***********************************************\n");
				flag = 1 ;
				break ;
			}
			if((Student + 1) == (Student_Queue->base + Student_Queue->length))
			{
				Student = Student_Queue->base;
			}
			else
			{
				Student++;
			}
		}
		if(flag == 0)
		{
			Student_Data_mod->roll = New_Student_id ;

			print("\n* [INFO] Student ID Number %d Updated Successfully\n\n",New_Student_id);

			print("***********************************************\n");
			print("************ Student Data After update ************\n");
			print_Student_info(Student_Data_mod);
		}
		break;
	case 2:
		print(" Enter The New Student First Name: ");
		scanf("%s",Student_Data_mod->first_name);

		print("* [INFO] Student %s Updated Successfully\n\n",Student_Data_mod->first_name);

		print("***********************************************\n");
		print("********** Student Data After update **********\n");
		print_Student_info(Student_Data_mod);
		break ;
	case 3:
		print(" Enter The New Student Last Name: ");
		scanf("%s",Student_Data_mod->last_name);

		print("* [INFO] Student Last Name %s Updated Successfully\n\n",Student_Data_mod->last_name);

		print("***********************************************\n");
		print("********** Student Data After update **********\n");
		print_Student_info(Student_Data_mod);
		break ;
	case 4:
		print(" Enter The New Student GPA: ");
		scanf("%f",&Student_Data_mod->GPA);

		print("* [INFO] Student GPA %.2f Updated Successfully\n\n",Student_Data_mod->GPA);

		print("***********************************************\n");
		print("********** Student Data After update **********\n");
		print_Student_info(Student_Data_mod);
		break;
	case 5:
		print(" Enter Course Number From 1 to %d to update: ", Number_Courses);
		scanf("%d", &option_number);
		print(" Enter New Course ID: ");
		scanf("%d", &Student_Data_mod->Course_id[option_number - 1]);

		print("* [INFO] Student Course ID Number %d Updated Successfully\n\n",Student_Data_mod->Course_id[option_number - 1]);

		print("***********************************************\n");
		print("********** Student Data After update **********\n");
		print_Student_info(Student_Data_mod);
		break;
	default:
		print("======================\n");
		print("* [ERROR]Wrong Option\n");
		print("======================\n");
		break;
	}
}

// ==============>> Check FIFO Status <<==============
FIFO_Buf_Status FIFO_is_Full(FIOF_Buf_t *Student_Queue)
{
	// Check FIFO Valid
	if (!Student_Queue->base || !Student_Queue->head || !Student_Queue->tail)
	{
		print("***********************************************\n");
		print("* [ERROR] FIFO Enqueue Failed ==>> FIFO is Null\n");
		print("***********************************************\n");
		return FIFO_Null;
	}

	if (Student_Queue->count == Student_Queue->length)
	{
		print("***********************************************\n");
		print("* [ERROR] FIFO Enqueue Failed ==>> FIFO is Full\n");
		print("***********************************************\n");
		return FIFO_full;
	}

	return FIFO_no_error;
}

// ==============>> FIFO Equeue <<==============
FIFO_Buf_Status FIFO_enqueue(FIOF_Buf_t *Student_Queue, SStudent_Node Student)
{
	// Check FIFO Valid
	if (!Student_Queue->base || !Student_Queue->head || !Student_Queue->tail)
	{
		return FIFO_Null;
	}

	// FIFO is Full
	if (FIFO_is_Full(Student_Queue) == FIFO_full)
	{
		return FIFO_full;
	}

	*(Student_Queue->head) = Student;
	Student_Queue->count++;
	// Check if The head at the last element in the array.

	if (Student_Queue->head == (Student_Queue->base + (Student_Queue->length * sizeof(SStudent_Node))))
	{
		Student_Queue->head = Student_Queue->base;
	}
	else
	{
		Student_Queue->head++;
	}

	return FIFO_no_error;
}

// ==============>> Check Student id is Exist or not <<==============
struct Studen_info_t *Check_Student_id(FIOF_Buf_t *Student_Queue, uint32_t id)
{
	int i;
	SStudent_Node *New_Student = Student_Queue->tail;

	for (i = 0; i < Student_Queue->count; i++)
	{
		if (New_Student->roll == id)
		{
			return New_Student;
		}
		else
		{
			New_Student++;
		}
	}
	New_Student = NULL;
	return New_Student;
}

// ==============>> Show All Student Information <<==============
void Show_Student_Information(FIOF_Buf_t *Student_Queue)
{
	int i;
	SStudent_Node *Student_info;

	// *Check if Student Data Base is Empty
	if (Student_Queue->count == 0)
	{
		print("***********************************************\n");
		print("* [ERROR] Student Data Base is Empty\n");
		print("***********************************************\n");
		return;
	}

	// *Check if Student Data Base is valid
	if (!Student_Queue->base || !Student_Queue->head || !Student_Queue->tail)
	{
		print("***********************************************\n");
		print("* [ERROR] Student Data Base Initialization ==>> Failed\n");
		print("***********************************************\n");
		return;
	}

	Student_info = Student_Queue->tail;

	for (i = 0; i < Student_Queue->count; i++)
	{
		print_Student_info(Student_info);
		Student_info++;
	}
	Print_Student_Count(Student_Queue);
}

// ==============>> Print Student Count Info <<==============
void Print_Student_Count(FIOF_Buf_t *Student_Queue)
{
	print("\n*********** Total Number Of Students **********\n")
    										print("* [INFO] The Total Number of Students is %d\n", Student_Queue->count);
	print("* [INFO] You Can Add up to %d Students\n", Max_Number_Students);
	print("* [INFO] You Can Add %d more Students\n", Max_Number_Students - Student_Queue->count);
	print("***********************************************\n");
}

// ==============>> print Student info<<==============
void print_Student_info(SStudent_Node *student)
{
	int i ;
	print("***********************************************\n");
	print("Student ID: %d \n", student->roll);
	print("Student First Name: %s \n", student->first_name);
	print("Student Last Name: %s \n", student->last_name);
	print("Student GPA Number: %.2f \n", student->GPA);

	for (i = 0; i < Number_Courses; i++)
	{
		print("Course id Number %d are: %d \n", i + 1, student->Course_id[i]);
	}
}
