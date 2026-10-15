#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student
{
    int rollno;
    char name[50];
    float marks;
    struct Student *next;
    
};

struct Student *head = NULL;
   
    int rollno=1;

void insert()
{
    struct Student *new, *temp;

    new = (struct Student *)malloc(sizeof(struct Student));

    new->rollno=rollno++;
    printf(" Roll Number: %d\n",new->rollno);

    printf("Enter Name: ");
    scanf(" %s", new->name);

    printf("Enter Marks: ");
    scanf("%f", &new->marks);

    new->next = NULL;

    if(head == NULL)
        head = new;
    else
    {
        temp = head;
        while(temp->next != NULL)
            temp = temp->next;

        temp->next = new;
    }

}

void display()
{
    struct Student *temp = head;

    if(head == NULL)
    {
        printf("No Records Found.\n");
        return;
    }
    while(temp != NULL)
    {
      printf(" %d  %s %f\n",temp->rollno,temp->name,temp->marks);

        temp = temp->next;
    }
}

void search()
{
    int rollno;
    struct Student *temp = head;

    printf("Enter roll number : ");
    scanf("%d", &rollno);

    while(temp != NULL)
    {
        if(temp->rollno == rollno)
        {
            printf("record Found\n");
	    printf("rollno : %d\n",temp->rollno);
            printf("Name : %s\n", temp->name);
            printf("Marks : %.2f\n", temp->marks);
            return;
        }
        temp = temp->next;
    }

    printf("record Not Found.\n");
}

void update()
{
    int rollno;
    struct Student *temp = head;

    printf("Enter roll number: ");
    scanf("%d", &rollno);

    while(temp != NULL)
    {
        if(temp->rollno == rollno)
        {
            printf("Enter New Name: ");
            scanf(" %s", temp->name);
	    
	    printf("Enter New Marks: ");
            scanf("%f", &temp->marks);

            printf("Record Updated \n");
            return;
        }

        temp = temp->next;
    }

    printf("Student Not Found.\n");
}

void delete()
{
    int rollno;

    struct Student *temp = head;
    struct Student *prev = NULL;

    printf("Enter rollno: ");
    scanf("%d", &rollno);

    while(temp != NULL)
    {
      if(temp->rollno == rollno)
      {
	if(prev == NULL)
	head=temp->next;

	else
           prev-> next = temp ->next;

     free(temp);

    printf("Record Deleted \n");
    return;
      }
      prev = temp;
      temp=temp->next;
    }
}

void deleteAll()
{
	struct Student *temp;

	while(head != NULL)
	{
		temp=head;
		head = head->next;
		free(temp);
	}

	printf(" all records deleted.\n");
}

void savedata()
{
	FILE *fp;
	struct Student *temp = head;
	fp=fopen("student.txt","w");

	if(fp==NULL)
	{
	 printf("file cannot open");
	 return;
	}
	while(temp!=NULL)
	{
	fprintf(fp,"%d %s %f\n",temp->rollno,temp->name,temp->marks);

	temp=temp->next;
	}
	fclose(fp);
	
	printf("data saved.\n");
}

void sort()
{
	struct Student *i,*j;
	int rollno;
	float marks;
	char name[20];

	if(head==NULL)
	{
	 printf("no records found.\n");
	 return;
	}

	for(i=head;i!=NULL;i=i->next)
	{
	 for(j=i->next;j!=NULL;j=j->next)
	 {
	  if(i->rollno > j->rollno)
	  {
            rollno=i->rollno;
	    i->rollno=j->rollno;
	    j->rollno=rollno;

	    strcpy(name,i->name);
	    strcpy(i->name,j->name);
	    strcpy(j->name,name);

	    marks=i->marks;
	    i->marks=j->marks;
	    j->marks=marks;
	  }
	 }
	}
	printf(" records sorted \n");
}




int main()
{
    int choice;

    while(1)
    {
        printf("1. Insert Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Update Student\n");
        printf("5. Delete Student\n");
	printf("6. Delete All\n");
	printf("7. save data in file\n");
	printf("8. sorting\n");
        printf("9. Exit\n");

        printf("Enter Choice: \n ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                insert();
                break;

            case 2:
                display();
                break;

            case 3:
                search();
                break;

            case 4:
                update();
                break;

            case 5:
                delete();
                break;

            case 6:
                deleteAll();
                break;

	    case 7:
	        savedata();
	        break;

	    case 8:
	         sort();
	         break;	 

	    case 9:
	        exit(0);
	    	

            default:
                printf("Invalid Choice entered \n");
        }
    }

    return 0;
}