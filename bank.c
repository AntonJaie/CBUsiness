#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>

struct Transaction{
	int transNo;
	int transType; //1 = for deposit, 2 = withdraw, 3 = transfer
	int srofTransID; //sender or recipient of transaction
	char dateTrans[11];
	float amount;
}

struct User{ //struct for users with its attributes
	int accntNo;	
	char name[60];
	int age;
	char address[60];
	int accType; //1 = Savings/Current, 2 = Fixed
	float balance;
};

struct NodePointer{ //for the linked list of users
	struct User data;
	struct Transaction trans;
	struct NodePointer *next;
}

void loadTitle(){
	system("cls");
	printf("***************************\n");
	printf("**    Online Banking     **\n");
	printf("***************************\n\n\n");
}

int genRandomAccntNo(struct NodePointer* List){ //generate unique random number
	strct NodePointer* pCurr;

	srand(time(NULL));
	int r = 0, isSame = 1;
	do{	
		r = rand()%9999;
		pCurr = List;
		if(pCurr != NULL){
			while(pCurr != NULL){
				if(r == pCurr->data.accntNo){
					isSame = 1;
					breal
				}
			}
		}
	}while(isSame = 1);

	return r;
}

struct NodePointer* makeUser(int accntNo, char name[60], int age, char address[60],int accntType,float balance){
	struct User u;
	struct Transaction trans;
	struct NodePointer* pointer;

	u.accntNo = accntNo;
	strcpy(u.name,name);
	u.age = age;
	strcpy(u.address,address);
	u.acctType = acctType;
	u.balance = balance;

	trans = NULL;
	pointer = malloc(sizeof(struct NodePointer));
	if(pointer==NULL)
			return NULL;
	pointer->data = data;
	pointer->trans = NULL;
	pointer->next = NULL;

	return pointer;
}

struct NodePointer* createAccount(struct NodePointer* List){

	loadTitle();
	printf("--- Add Account ----\n\n");
	struct NodePointer* pNew;
	struct NodePointer* pCurrent;
	struct NodePointer* pTrail;
	struct NodePointer* pTemp;

	char name[60] = {'\0'}, address[60] = {'\0'};
	int age = 0, accntType = 0;
	float balance = -1.1; 
	int accntNo = genRandomAccntNo(List);

	printf("Account No: %d\n",accntNo);
	printf("Name: ");
	scanf("%s", name);
	fflush(stdin);
	printf("Address: ");
	scanf("%s", address);
	fflush(stdin);
	printf("Age: ");
	scanf("%d", &age);
	printf("Account Type (1 - S/C, 2 - Fixed): ");
	scanf("%d, accntType");
	printf("Starting Balance: ");
	scanf("%f", balance);

	pNew = makeUser(accntNo, name, age, address,accntType,balance);
	pTemp = List;
	if(List == NULL){
		List = pNew;
	}
	else{
		while(pTemp->next != NULL){
			pTemp-pTemp->next;
		}
		pTemp->next = pNew;
	}
	return List;
}
void printOneNode(struct NodePointer* node){
	printf("Account Number: %d\n", node->data.accntNo);
	printf("Name: %s\n", node->data.name);
	printf("Age: %d\n", node->data.age);
	printf("Address: %s\n", node->data.Address);
	if(node->data.accntType = 1)
		printf("Account Type: Savings/Current\n");
	else
		printf("Account Type: Fixed\n");

	printf("Balance: %.3f", node->data.balance);	
}

void viewList(struct NodePointer* List){
	loadTitle();
	printf("--- View Customer List ----\n\n")
	char choice = 'O';
	struct NodePointer* pCurr;
	pCurr = nodes;
	
	if(pCurr != NULL){
		while(pCurr!= NULL){
			printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
			printOneNode(pCurr);
			printf("\n\n");
			printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
			printf("\n");
			pCurr = pCurr->next;
		}
		while(choice != 'B'){
			fflush(stdin);
			printf("\n[B]ack to Main Menu\n");
			printf("Option: ");
			scanf("%c", &choice);
			if(choice == 'B')
				return;
		}
	}
	else
		printf("No data available.");
	getchar();
}
loadAdminHome(){
	loadTitle();//load title screen
	
	int input;
	struct NodePointer* pStart = NULL;
	printf("[1] Create an Account\n");
	printf("[2]	Update Info\n");
	printf("[3]	Check Info\n");
	printf("[4]	View and Manage Transactions\n");
	printf("[5]	Remove An Account\n");
	printf("[6]	View Customer's List\n");
	printf("[7]	Exit\n\n\n");

	while(input != 7){
		switch(input){
			case 1: //create accnt
				pStart = createAccount(pStart);
				break;
			case 2: //update info
				//pStart = updateInfo(pStart);
				break;
			case 3: //check info
				//checkInfo(pStart);
				break;
			case 4: //View and Manage Trans
				//pStart = viewAndManageTrans(pStart);
				break;
			case 5: //remove account
				//pStart = removeAccount(pStart);
				break;
			case 6: // View Customer List
				viewList(pStart);
				break;
			case 7:
				free(pStart);
				exit(1);
				break;
		}
	}
}



int main(){
	char pass[10],password[10]="hazelchung";
	int match = 0;
	loadTitle();

	while(match != 1)
	printf("Enter the password to login ('Q' to quit): ");
	scanf("%s",pass[10]);

	if(strcmp(pass,"Q")){
		goto exit_tag;
	}
	else if(strcmp(pass,password)){
		loadAdminHome();
	}
	else{
		printf("Access Denied! Wrong Password.\n")
	}

	exit_tag:
	getch();
	fflush(stdin);
	return 0;
}

