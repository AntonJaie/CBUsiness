#include<stdio.h>
#include<conio.h>
#include<string.h>

struct date{ // struct of the date
	int month, day, year;
};

struct user{ //struct for users with its attributes
	int accntNo;	
	char name[60];
	int age;
	char address[60];
	int accType;
	float balance;
	struct data dob;
	struct date deposit;
	struct date withdraw;
};

struct NodePointer{ //for the linked list of users
	struct user data;
	struct NodePointer *pNext;
	struct NodePointer *pPrev;
}
struct NodePointer* makeNode(int accntNo, char name[60], int age, char address[60],int accntType,float balance, str)
void loadTitle(){
	system("cls");
	printf("***************************\n");
	printf("**    Online Banking     **\n");
	printf("***************************\n\n\n");
}

loadAdminHome(){
	loadTitle();//load title screen
	
	printf("[1] Create an Account\n");
	printf("[2]	Update Info\n");
	printf("[3]	Check Info\n");
	printf("[4]	View and Manage Transactions\n");
	printf("[5]	Remove An Account\n");
	printf("[6]	View Customer's List\n");
	printf("[7]	Exit\n\n\n");
}

void userLogin(){
	int accountNo = -99, password = -99;
	loadTitle(); //load the title screen

	printf("---User Login----\n\n");
	printf("Account No.: ");
	scanf("%d", &accountNo);
	printf("Password: ");
	scanf("%d", &password);	
}

void adminLogin(){
	int adminID = -99, password = -99, success = 0;

	loadTitle(); //load title screen

	printf("--- Admin Login---\n\n");
	while(success != 1){
		printf("Admin ID: ");
		scanf("%d", &adminID);
		printf("Password: ");
		scanf("%d", &password);
		
		if(adminID == 1111){
			if(password == 12345){
				loadAdminHome();
				success = 1;	
			}
		}
		else{
			printf("Error! Grant Access Denied.\n\n");
			success = 0;
		}
	}
}

main(){
	int input = 0,exitBool = 0;
	
	loadTitle(); // load the title screen

	printf("---Login---\n\n");
	printf("[1]	User\n");
	printf("[2]	Admin\n");
	printf("[3]	Quit\n");

	while(input != 1){
		printf("Option: ");
		scanf("%d", &input);
		switch(input){
			case 1:
				userLogin();
				break;
			case 2:
				adminLogin();
				break;
			case 3:
				exitBool = 1;
				break;
		}
	}	

}

