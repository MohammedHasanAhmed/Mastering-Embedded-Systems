/*
 ==========================================================================
 Name        : Student_Data_Base.c
 Author      : Mohammed Hasan
 Created on	 : Sep 28, 2023
 Description : 
 ==========================================================================
 */


#include "Student_Data_Base.h"

struct SStudent *gpFirst_Student = NULL;

void Fill_the_record(struct SStudent *New_Student)
{
	char temp_text[40];

	DPRINTF("\n Enter the ID : ");
	fgets(temp_text , 40 ,stdin);
	New_Student->Student.ID = atoi(temp_text);

	DPRINTF("Enter Student Full Name : ");
	fgets(New_Student->Student.name , 40 , stdin);

	DPRINTF("Enter height : ");
	fgets(temp_text , 40 ,stdin);
	New_Student->Student.height = atof(temp_text);
}

void Add_Student()
{
	struct SStudent *pNew_Student;
	struct SStudent *pLast_Student;

	if (gpFirst_Student == NULL) // List is empty
	{
		// Create new Record
		pNew_Student = (struct SStudent *)malloc(sizeof(struct SStudent));

		// assign to gpFirst_Student
		gpFirst_Student = pNew_Student;
	}
	else // List contains records
	{
		// navigate until reach to the last record
		pLast_Student = gpFirst_Student;
		while (pLast_Student->pNext_Student)
			pLast_Student = pLast_Student->pNext_Student;

		// Create new Record
		pNew_Student = (struct SStudent *)malloc(sizeof(struct SStudent));
		pLast_Student->pNext_Student = pNew_Student;
	}
	Fill_the_record(pNew_Student) ;
	// set the new Last node->Next = Null
	pNew_Student->pNext_Student = NULL;
}

int Delete_Student()
{
	// get the selected ID
	char temp_text[40];
	unsigned int Selected_ID;

	DPRINTF("\n Enter the student ID to be Deleted :");
	fgets(temp_text , 40 ,stdin);
	Selected_ID = atoi(temp_text);

	if (gpFirst_Student) // gpFirst_Student != NULL
	{
		struct SStudent *pSelected_Student = gpFirst_Student;
		struct SStudent *pPrevious_Student = NULL;

		// Loop on all record
		while (pSelected_Student)
		{
			// compare each Node with selected ID
			if (pSelected_Student->Student.ID == Selected_ID)
			{
				if (pPrevious_Student) // pPrevious_Student is exist ==>> the first is not selected one
				{
					pPrevious_Student->pNext_Student = pSelected_Student->pNext_Student;
				}
				else // pPrevious_Student == NULL ==>> first student ==> Selected_ID
				{
					gpFirst_Student = pSelected_Student->pNext_Student;
				}
				free(pSelected_Student);
				return 1;
			}
			pPrevious_Student = pSelected_Student;
			pSelected_Student = pSelected_Student->pNext_Student;
		}
	}
	DPRINTF("\n Can't Find This Student_ID, please try Again.");
	return 0;
}

void View_Students()
{
	struct SStudent *pCurrent_Student = gpFirst_Student;
	int count = 0;
	if (gpFirst_Student == NULL)
	{
		DPRINTF("\n Empty List");
	}
	else
	{
		while (pCurrent_Student)
		{
			DPRINTF("\n Record number %d", count + 1);
			DPRINTF("\n \t ID : %d", pCurrent_Student->Student.ID);
			DPRINTF("\n \t Name : %s", pCurrent_Student->Student.name);
			DPRINTF("\n \t Height : %f", pCurrent_Student->Student.height);
			pCurrent_Student = pCurrent_Student->pNext_Student;
			count++;
		}
	}
}

void Delete_All()
{
	struct SStudent *pCurrent_Student = gpFirst_Student;

	if (gpFirst_Student == NULL)
	{
		DPRINTF("\n Empty List");
	}
	else
	{
		while (pCurrent_Student)
		{
			struct SStudent *pTemp_Student = pCurrent_Student;
			pCurrent_Student = pCurrent_Student->pNext_Student;
			free(pTemp_Student);
		}
		gpFirst_Student = NULL;
	}
    DPRINTF("\n========= Done =========");
}

void Get_Node(unsigned int index)
{
	int count = 0 ;
	struct SStudent* pTemp_Student = gpFirst_Student ;

	if(gpFirst_Student == NULL) // gpFirst_Student != null
	{
		DPRINTF("\n Empty List");
	}
	if(index < 0)
	{
		DPRINTF("\n Invalid Index");
	}
	while(pTemp_Student) // pTemp_Student != Null
	{
		if(count == index)
		{
			DPRINTF("\n Record index %d" , index);
			DPRINTF("\n \t ID : %d", pTemp_Student->Student.ID);
			DPRINTF("\n \t Name : %s", pTemp_Student->Student.name);
			DPRINTF("\n \t Height : %f", pTemp_Student->Student.height);
		}
		pTemp_Student = pTemp_Student->pNext_Student ;
		count++ ;
	}
}

int Get_Count_Iterative()
{
	int count = 1 ;
	struct SStudent* pTemp_Student = gpFirst_Student ;

	if(gpFirst_Student == NULL) // gpFirst_Student != null
	{
		DPRINTF("\n Empty List");
	}
	while(pTemp_Student)
	{
		if(pTemp_Student->pNext_Student == NULL) break;
		pTemp_Student = pTemp_Student->pNext_Student ;
		count++ ;
	}
	return count;
}

int Get_Count_Recursive(struct SStudent* pTemp_Student)
{
	// Check if the list is empty
	if(gpFirst_Student == NULL )
	{
		DPRINTF("\n Empty List");
		return 0;
	}

	if(pTemp_Student == NULL)
	{
		return 0;
	}
	else
	{
		return (1 + Get_Count_Recursive(pTemp_Student->pNext_Student));
	}
}

void Get_Node_From_End(unsigned int index)
{
	// Check if the list is empty
	if (gpFirst_Student == NULL)
	{
		DPRINTF("\n Empty list");
	}
	if (index < 0)
	{
		DPRINTF("\n Invalid Index");
	}
	struct SStudent *pMain = gpFirst_Student;
	struct SStudent *pRef = gpFirst_Student;

	while (index)
	{
		if (pRef == NULL)
		{
			DPRINTF("\n Invalid Index");
		}
		index--;
		pRef = pRef->pNext_Student;
	}
	if (pRef->pNext_Student != NULL)
	{
		pRef = pRef->pNext_Student;
		pMain = pMain->pNext_Student;
	}
	DPRINTF("\n Record Index from end to zero-based");
	DPRINTF("\n\t ID : %d", pMain->Student.ID);
	DPRINTF("\n\t Name : %s", pMain->Student.name);
	DPRINTF("\n\t Height : %f", pMain->Student.height);
}

void Get_Middle()
{
	unsigned int Number_OF_Student = 0;
	// Check if the list is empty
	if (gpFirst_Student == NULL)
	{
		DPRINTF("\n Empty list");
	}
	// Get Count of Nodes
	Number_OF_Student = Get_Count_Iterative();

	// Get the middle node
	Get_Node(Number_OF_Student / 2);
}

// Reverse the arrangement of the list
void Reverse_Students_List()
{
	// Initialize node for previous, current and next
	struct SStudent *pPrevious_Student = NULL;
	struct SStudent *pCurrentStudent = gpFirst_Student;
	struct SStudent *pNextStudent = NULL;

	// Check if the list is empty
	if(gpFirst_Student == NULL)
	{
		DPRINTF("\nThe List is Empty.\n");
	}

	// if pCurrentStudent get the last node in the list
	while(pCurrentStudent != NULL)
	{
		pNextStudent = pCurrentStudent->pNext_Student;
		pCurrentStudent->pNext_Student = pPrevious_Student;
		pPrevious_Student = pCurrentStudent;
		pCurrentStudent = pNextStudent;
	}

	// After reverse all node
	gpFirst_Student = pPrevious_Student;
	DPRINTF("\n======= Reverse is Done =======");
}
