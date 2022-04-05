#include<stdio.h>			//including header files
#include<stdlib.h>
#include<string.h>

int Exit,i,j;		//defining global variables


void catalog();		//declaring functions
void new_comer();
void edit();
void checklist();
void del();
void view();
void sorter();
void closer();

struct Date{		//defining structures
    int month,day,year;
};
struct {

    char Name[30];
    int Age;
    char City[10];
    char Mail_Id[15];
    char Hall_No[8];
    char Father_Name[30];
    int Father_Mob_No;
    int Mob_No;
    char Rooming_House_Name[6];
    char Enroll_No[10];
    struct Date DOB;
    }add,update,check,rem,sort;

//*********************************************************************************************************************
int main()		//main function

{
	pass();
  catalog();
  return 0;
}


// catalog function
void catalog()
{
system("CLS");
    int choice;
    printf("\n\n\t\t\tROOMING HOUSE MANAGEMENT SYSTEM");
    printf("\n\n\n\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME TO THE MAIN catalog \xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\n\t\t1] Enter new Customer’s data\n\t\t2] Update information of existing account\n\t\t3] Check the details of existing account\n\t\t4] View all Customer of a particlar Rooming_House\n\t\t5] Removing existing account\n\t\t6] View all Customer list\n\t\t7] Exit\n\n\n\n\n\t\t Enter your choice:");
    scanf("%d",&choice);

    switch(choice)
    {

        case 1:new_comer();
        break;
        case 2:edit();
        break;
        case 3:view();
        break;
        case 4:sorter();
        break;
        case 5:del();
        break;
        case 6:checklist();
        break;
        case 7:closer();
        break;
        default: catalog();
    }
}

//*******************************************************************************************************************
//function to display all Customer of a Rooming_House
void sorter()
{
	system("CLS");
    int choice,test=0;

    printf("Enter your choice:\n\n\t\t1. BH-1 \n\t\t2. BH-2 \n\t\t3. BH-3 \n\t\t4. GH-1 \n\n");
    scanf("%d",&choice);

    FILE *fp, *Rooming_House;
    switch(choice)
    {
    	case 1: Rooming_House=fopen("BH-1.dat","a+");break;
    	case 2: Rooming_House=fopen("BH-2.dat","a+");break;
    	case 3: Rooming_House=fopen("BH-3.dat","a+");break;
    	case 4: Rooming_House=fopen("GH-1.dat","a+");break;
    	default: sorter();
    }
    while(fscanf(Rooming_House,"%s\n",check.Enroll_No)!=EOF)
    {
   	    fp=fopen("record.dat","r");
    	while(fscanf(fp,"%s %s %d/%d/%d %d %s %d %s %s %d %s %s\n",sort.Enroll_No, sort.Name, &sort.DOB.month, &sort.DOB.day, &sort.DOB.year, &sort.Age, sort.City, &sort.Mob_No, sort.Mail_Id, sort.Father_Name, &sort.Father_Mob_No, sort.Mail_Id, sort.Rooming_House_Name)!=EOF)
    	{
    		if(strcmp(check.Enroll_No,sort.Enroll_No)==0)
    		{
    			if(test==0)
    			{
    				printf("\t\tFollowing is the list of requested Customer:");
		            printf("\n\tROLL NO.\tNAME\tROOM NO.\n");
    			}
    			printf("\n\t%8s\t %8s\t %s", sort.Enroll_No, sort.Mail_Id, sort.Name);
           		test++;
    		}
    	}
    }

    fclose(fp);
    if (test==0)
        printf("\nNO RECORDS!!\n");

    sort_list_invalid:
    printf("\n\nEnter 1 to go to the main catalog and 0 to exit:");
    scanf("%d",&Exit);

    if (Exit==1)
        catalog ();
    else if(Exit==0)
        closer();
    else
    {
        printf("\nInvalid!\a");
        goto sort_list_invalid;
    }

}

//*******************************************************************************************************************
//new entry function
void new_comer()
{
	system("CLS");
    int choice;
    FILE *ptr,*Rooming_House;

    ptr=fopen("record.dat","a+");
    Enroll_No:

    printf("\t\t\t\xB2\xB2\xB2 ADD CUSTOMER DATA  \xB2\xB2\xB2\xB2");
    printf("\nEnter your roll number:");
    scanf("%s",check.Enroll_No);
    while(fscanf(ptr,"%s %s %d/%d/%d %d %s %d %s %s %d %s %s\n",add.Enroll_No, add.Name, &add.DOB.month, &add.DOB.day, &add.DOB.year, &add.Age, add.City, &add.Mob_No, add.Mail_Id, add.Father_Name, &add.Father_Mob_No, add.Mail_Id, add.Rooming_House_Name)!=EOF)
    {
        if (strcmp(check.Enroll_No,add.Enroll_No)==0)
            {printf("Customer roll no. already in use!");
             goto Enroll_No;
        }
    }

    strcpy(add.Enroll_No,check.Enroll_No);
    printf("\nEnter the Name:");
    scanf("%s",add.Name);
    printf("\nEnter the Date of birth(mm/dd/yyyy):");
    scanf("%d/%d/%d",&add.DOB.month,&add.DOB.day,&add.DOB.year);
    printf("\nEnter the Age:");
    scanf("%d",&add.Age);
    printf("\nEnter the City:");
    scanf("%s",add.City);
    printf("\nEnter the Mob_No number: ");
    scanf("%d",&add.Mob_No);
    printf("\n Enter your email id :");
    scanf("%s",add.Mail_Id);
    printf("\n Enter your Father's Name:");
    scanf("%s",add.Father_Name);
    printf("\n Enter your Father's Mob_No no.:");
    scanf("%d",&add.Father_Mob_No);
    printf("\n Enter your room no.:");
    scanf("%s",add.Mail_Id);
    printf("\n Enter your Rooming_House Name from BH-1, BH-2, BH-3, GH-1 :");
    scanf("%s",add.Rooming_House_Name);
        fprintf(ptr,"%s %s %d/%d/%d %d %s %d %s %s %d %s %s\n",add.Enroll_No, add.Name, add.DOB.month, add.DOB.day, add.DOB.year, add.Age, add.City, add.Mob_No, add.Mail_Id, add.Father_Name, add.Father_Mob_No, add.Mail_Id, add.Rooming_House_Name);

		//adding student roll no. to Rooming_Houses' list
	if(strcmp(add.Rooming_House_Name,"BH-1")==0)
	{
		Rooming_House=fopen("BH-1.dat","a+");
		fprintf(Rooming_House, "%s\n", add.Enroll_No);
		fclose(Rooming_House);
	}
	else if(strcmp(add.Rooming_House_Name,"BH-2")==0)
	{
		Rooming_House=fopen("BH-2.dat","a+");
		fprintf(Rooming_House, "%s\n", add.Enroll_No);
		fclose(Rooming_House);
	}
	else if(strcmp(add.Rooming_House_Name,"BH-3")==0)
	{
		Rooming_House=fopen("BH-3.dat","a+");
		fprintf(Rooming_House, "%s\n", add.Enroll_No);
		fclose(Rooming_House);
	}
	else if(strcmp(add.Rooming_House_Name,"GH-1")==0)
	{
		Rooming_House=fopen("GH-1.dat","a+");
		fprintf(Rooming_House, "%s\n", add.Enroll_No);
		fclose(Rooming_House);
	}
		//----------------------------------------

    fclose(ptr);
    printf("\nStudent added successfully!");
    add_invalid:
    printf("\n\n\n\t\tEnter 1 to go to the main catalog and 0 to exit:");
    scanf("%d",&Exit);

    if (Exit==1)

        catalog ();
    else if(Exit==0)
            closer();
    else
        {
            printf("\nInvalid!\a");
            goto add_invalid;
        }
}

//*******************************************************************************************************************
//nsbfunction to view all Customer
void checklist()
{
	system("CLS");
    FILE *view;
    view=fopen("record.dat","r");
    int test=0;

    printf("\nROLL NO.\tNAME\t\t\tCity\t\t\tMOB_NO\n");

    while(fscanf(view,"%s %s %d/%d/%d %d %s %d %s %s %d %s %s\n",add.Enroll_No, add.Name, &add.DOB.month, &add.DOB.day, &add.DOB.year, &add.Age, add.City, &add.Mob_No, add.Mail_Id, add.Father_Name, &add.Father_Mob_No, add.Mail_Id, add.Rooming_House_Name)!=EOF)
       {
           printf("\n%8s\t %10s\t\t\t %10s\t\t %d",add.Enroll_No,add.Name,add.City,add.Mob_No);
           test++;
       }
    fclose(view);

    if (test==0)
        {
            printf("\nNO RECORDS!!\n");}

    checklist_invalid:
     printf("\n\nEnter 1 to go to the main catalog and 0 to exit:");
        scanf("%d",&Exit);

        if (Exit==1)
            catalog ();
        else if(Exit==0)
            closer();
        else
        {
            printf("\nInvalid!\a");
            goto checklist_invalid;
        }
}

//*******************************************************************************************************************
//function to view all data of 1 student
void view()
{
	system("CLS");
    FILE *ptr;
    int test=0;
    int choice;
    ptr=fopen("record.dat","r");
    printf("Do you want to check by\n1.Roll no\n2.Name\nEnter your choice:");
    scanf("%d",&choice);
    if (choice==1)
    {   printf("\n\nEnter the roll number:");
        scanf("%s",check.Enroll_No);

        while (fscanf(ptr,"%s %s %d/%d/%d %d %s %d %s %s %d %s %s\n",add.Enroll_No, add.Name, &add.DOB.month, &add.DOB.day, &add.DOB.year, &add.Age, add.City, &add.Mob_No, add.Mail_Id, add.Father_Name, &add.Father_Mob_No, add.Mail_Id, add.Rooming_House_Name)!=EOF)
        {
            if(strcmp(add.Enroll_No,check.Enroll_No)==0)
            {
                test=1;

                printf("\nROLL NO.:%s\nName:%s \nDOB:%d/%d/%d \nAge:%d \nCity:%s \nMob_No number:%d \nE-Mail id:%s \nFather's Name:%s \n Father's Mob_No No.:%d \nRoom No:%s \nRooming_House:%s \n",add.Enroll_No, add.Name, add.DOB.month, add.DOB.day, add.DOB.year, add.Age, add.City, add.Mob_No, add.Mail_Id, add.Father_Name, add.Father_Mob_No, add.Mail_Id, add.Rooming_House_Name);
            }
        }
    }
    else if (choice==2)
    {   printf("\n\nEnter the Name:");
        scanf("%s",check.Name);
        while (fscanf(ptr,"%s %s %d/%d/%d %d %s %d %s %s %d %s %s\n",add.Enroll_No, add.Name, &add.DOB.month, &add.DOB.day, &add.DOB.year, &add.Age, add.City, &add.Mob_No, add.Mail_Id, add.Father_Name, &add.Father_Mob_No, add.Mail_Id, add.Rooming_House_Name)!=EOF)
        {
            if(strcmp(add.Name,check.Name)==0)
            {
                test=1;
                printf("\nROLL NO.:%s\nName:%s \nDOB:%d/%d/%d \nAge:%d \nCity:%s \nMob_No number:%d \nE-Mail id:%s \nFather's Name:%s \n Father's Mob_No No.:%d \nRoom No:%s \nRooming_House:%s \n",add.Enroll_No, add.Name, add.DOB.month, add.DOB.day, add.DOB.year, add.Age, add.City, add.Mob_No, add.Mail_Id, add.Father_Name, add.Father_Mob_No, add.Mail_Id, add.Rooming_House_Name);
            }
        }
    }

    fclose(ptr);
     if(test!=1)
     	printf("\nRecord not found!!\a\a\a");
    view_invalid:
        printf("\nEnter 0 to try again,1 to return to main catalog and 2 to exit:");
        scanf("%d",&Exit);
        if (Exit==1)
            catalog ();
        else if (Exit==2)
            closer();
        else if(Exit==0)
            del();
        else
        {
        	printf("\nInvalid!\a");
            goto view_invalid;
		}
}

//*******************************************************************************************************************
//function to updateate student info
void edit()
{
	system("CLS");
    int choice,test=0;
    FILE *old,*newrec;
    old=fopen("record.dat","r");
    newrec=fopen("new.dat","w");

    printf("\nEnter the roll no. of the student whose info you want to change:");
    scanf("%s",update.Enroll_No);
    while(fscanf(old,"%s %s %d/%d/%d %d %s %d %s %s %d %s %s\n",add.Enroll_No, add.Name, &add.DOB.month, &add.DOB.day, &add.DOB.year, &add.Age, add.City, &add.Mob_No, add.Mail_Id, add.Father_Name, &add.Father_Mob_No, add.Mail_Id, add.Rooming_House_Name)!=EOF)

    {
        if (strcmp(add.Enroll_No,update.Enroll_No)==0)
        {   test=1;
            printf("\nWhich information do you want to change?\n1.Room no.\n2.Mob_No\n\nEnter your choice(1 for room no. and 2 for Mob_No ):");
            scanf("%d",&choice);

            if(choice==1)
                {printf("Enter the new room no.:");
                scanf("%s",update.Mail_Id);
                fprintf(newrec,"%s %s %d/%d/%d %d %s %d %s %s %d %s %s\n",add.Enroll_No, add.Name, add.DOB.month, add.DOB.day, add.DOB.year, add.Age, add.City, add.Mob_No, add.Mail_Id, add.Father_Name, add.Father_Mob_No, update.Mail_Id, add.Rooming_House_Name);
                printf("Changes saved!");
                }
            else if(choice==2)
                {
                    printf("Enter the new Mob_No number:");
                scanf("%d",&update.Mob_No);
                fprintf(newrec,"%s %s %d/%d/%d %d %s %d %s %s %d %s %s\n",add.Enroll_No, add.Name, add.DOB.month, add.DOB.day, add.DOB.year, add.Age, add.City, update.Mob_No, add.Mail_Id, add.Father_Name, add.Father_Mob_No, add.Mail_Id, add.Rooming_House_Name);
                printf("Changes saved!");
                }

        }
        else
            fprintf(newrec,"%s %s %d/%d/%d %d %s %d %s %s %d %s %s\n",add.Enroll_No, add.Name, add.DOB.month, add.DOB.day, add.DOB.year, add.Age, add.City, add.Mob_No, add.Mail_Id, add.Father_Name, add.Father_Mob_No, add.Mail_Id, add.Rooming_House_Name);
    }
    fclose(old);
    fclose(newrec);
    remove("record.dat");
    rename("new.dat","record.dat");

	if(test!=1)
        printf("\nRecord not found!!\a\a\a");

    edit_invalid:
		printf("\nEnter 0 to try again,1 to return to main catalog and 2 to exit:");
        scanf("%d",&Exit);
        if (Exit==1)
			catalog();
        else if (Exit==2)
            closer();
        else if(Exit==0)
            edit();
        else
        {
        	printf("\nInvalid!\a");
            goto edit_invalid;
        }

}

//*******************************************************************************************************************
//cpfunction to delete records
void del()
{
	system("CLS");
    FILE *old,*newrec;
    int test=0;
    old=fopen("record.dat","r");
    newrec=fopen("new.dat","w");
    printf("Enter the roll np. of student whose data you want to delete:");
    scanf("%s",rem.Enroll_No);
    while (fscanf(old,"%s %s %d/%d/%d %d %s %d %s %s %d %s %s\n",add.Enroll_No, add.Name, &add.DOB.month, &add.DOB.day, &add.DOB.year, &add.Age, add.City, &add.Mob_No, add.Mail_Id, add.Father_Name, &add.Father_Mob_No, add.Mail_Id, add.Rooming_House_Name)!=EOF)
   {
        if(add.Enroll_No!=rem.Enroll_No)
            fprintf(newrec,"%s %s %d/%d/%d %d %s %d %s %s %d %s %s\n",add.Enroll_No, add.Name, add.DOB.month, add.DOB.day, add.DOB.year, add.Age, add.City, add.Mob_No, add.Mail_Id, add.Father_Name, add.Father_Mob_No, add.Mail_Id, add.Rooming_House_Name);

        else
            {test++;
            printf("\nRecord deleted successfully!\n");
            }
    }
    fclose(old);
    fclose(newrec);
    remove("record.dat");
    rename("new.dat","record.dat");
    if(test==0)
	    printf("\nRecord not found!!\a\a\a");
    del_invalid:
        printf("\nEnter 0 to try again,1 to return to main catalog and 2 to exit:");
        scanf("%d",&Exit);
        if (Exit==1)
            catalog();
        else if (Exit==2)
            closer();
        else if(Exit==0)
            del();
        else
        {
        	printf("\nInvalid!\a");
            goto del_invalid;
		}
}

//*******************************************************************************************************************
//function displaying developer credits 1353functioncalls
void closer()
{
	system("CLS");
    printf("\n\n\n\Abhishek Sabne\n\n\n");
}
int pass(void)
{
   int a=0,i=0;
    char uname[10],c=' ';
    char pword[10],code[10];
    char abhi[10]="abhi";
    char sabne[10]="sabne";
    do
{
	system("cls");

    printf("\n  **************************  LOGIN FORM  **************************  ");
    printf(" \n                       ENTER USERNAME:-");
	scanf("%s", &uname);
	printf(" \n                       ENTER PASSWORD:-");
	while(i<10)
	{
	    pword[i]=getch();
	    c=pword[i];
	    if(c==13) break;
	    else printf("*");
	    i++;
	}
	pword[i]='\0';

	i=0;

		if(strcmp(uname,abhi)==0 && strcmp(pword,sabne)==0)
	{
	printf("  \n\n\n       WELCOME !!!! LOGIN IS SUCCESSFUL\n");
	system("PAUSE");
	break;
	}
	else
	{
		printf("\n        SORRY !!!!  LOGIN IS UNSUCESSFUL\n");
		system("PAUSE");
		a++;

		getch();

	}
}
	while(a<=2);
	if (a>2)
	{
		printf("\nSorry you have entered the wrong username and password for four times!!!");

		getch();

		}
		system("cls");
}


