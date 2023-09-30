/*
 ==========================================================================
 Name        : main.c
 Author      : Mohammed Hassan
 Created on	 : 9/30/2023
 Description : Linked List (Student Data Base)
 ==========================================================================
 */

#include "Student_Data_Base.h"


int main()
{
	char temp_text[40];
	unsigned int index ;
	unsigned int count = 0 ;
	struct SStudent* pFirst_Student = NULL;
	while (1)
	{
		DPRINTF("\n==================================");
		DPRINTF("\n Choose on of the following Options \n");
		DPRINTF("\n 1: Add Student");
		DPRINTF("\n 2: Delete Student");
		DPRINTF("\n 3: View Students");
		DPRINTF("\n 4: Delete All Students");
		DPRINTF("\n 5: Get Student");
		DPRINTF("\n 6: Get Number of Students by Iteration");
		DPRINTF("\n 7: Get Number of Students by Recursion");
		DPRINTF("\n 8: Get Student From The End");
		DPRINTF("\n 9: Get the Middle Student");
		DPRINTF("\n 10: Reverse Student List");
		DPRINTF("\n 11: Exit ");
		DPRINTF("\n Enter Option Number: ");

		fgets(temp_text , 40 ,stdin);
		DPRINTF("\n==================================");
		switch (atoi(temp_text))
		{
		case 1:
			Add_Student();
			break;

		case 2:
			Delete_Student();
			break;

		case 3:
			View_Students();
			break;

		case 4:
			Delete_All();
			break;

		case 5:
			DPRINTF("\nEnter Record Index :");
			fgets(temp_text , 40 ,stdin);
			index = atoi(temp_text);
			Get_Node(index);
			break;

		case 6:
			count = Get_Count_Iterative();
			DPRINTF("\n Number of Students is : %d", count);
			break;

		case 7:
			count = Get_Count_Recursive(pFirst_Student);
			DPRINTF("\n Number of Students is : %d", count);
			break;

		case 8:
			DPRINTF("\nEnter Record Index :");
			fgets(temp_text , 40 ,stdin);
			index = atoi(temp_text);
			Get_Node_From_End(index);
			break;

		case 9:
			Get_Middle();
			break;

		case 10:
			Reverse_Students_List();
			break;

		case 11:
			return 0;

		default:
			DPRINTF("\n Wrong Option!!,Please Try Again");
			break;
		}
	}
	return 0;
}
