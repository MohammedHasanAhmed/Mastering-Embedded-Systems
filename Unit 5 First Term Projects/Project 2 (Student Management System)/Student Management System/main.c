/*
 ==========================================================================
 Name        : main.c
 Author      : Mohammed Hassan
 Created on	 : Oct 30, 2023
 Description : First Term Project 2
 ==========================================================================
 */
#include "Student_System.h"
int main()
{
	int Select_Option;
	FIOF_Buf_t Student_Queue;
	struct Studen_info_t Student_Buffer[Max_Number_Students];

	FIFO_init(&Student_Queue,Student_Buffer,Max_Number_Students);
	while (1)
	{
		print("\n\t\t\t\t********************************************\n");
		print("\t\t\t\t* Choose the Task that you want to Perform *");
		print("\n\t\t\t\t********************************************\n\n");
		print(" 1- Add the Student Details Manually\n\n");
		print(" 2- Add the Student Details From Text File\n\n");
		print(" 3- Find the Student Details by Roll Number\n\n");
		print(" 4- Find the Student Details by First Name\n\n");
		print(" 5- Find the Student Details by Course id\n\n");
		print(" 6- Find the Total Number of Students\n\n");
		print(" 7- Delete the Students Details by Roll Number\n\n");
		print(" 8- Update the students Details by Roll Number\n\n");
		print(" 9- Show All Information\n\n");
		print(" 10- Exit\n\n");
		print(" Enter your Choice to Perform the task: ");

		scanf("%d", &Select_Option);
		print("\n=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*\n\n");
		switch (Select_Option)
		{
		case 1:
			Add_Student_manually(&Student_Queue);
			break;
		case 2:
			Add_Student_From_File(&Student_Queue);
			break;
		case 3:
			Find_Student_By_id(&Student_Queue);
			break;
		case 4:
			Find_Student_By_FirstName(&Student_Queue);
			break;
		case 5:
			Find_Student_By_Course_id(&Student_Queue);
			break;
		case 6:
			Print_Student_Count(&Student_Queue);
			break;
		case 7:
			Delete_Student_By_id(&Student_Queue);
			break;
		case 8:
			Update_Student_By_id(&Student_Queue);
			break;
		case 9:
			Show_Student_Information(&Student_Queue);
			break;
		case 10:
			print("\t\t\t\t ****************** Thank you ******************\n");
			return 0;
			break;
		default:
			print("\n Wrong Option Try Again\n");
			break;
		}
	}
	return 0;
}
