#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>

void itemdata(int n);
void display(int n);
void bidding(int n,int u_no);
void result(int n,int u_no);
void usersinfo(int n,int u_no);
void menuscrn(int n,int u_no);
void suggest (int n,int u_no);
void info(int n,int u_no);
void filer (int n, int u_no);

struct users{
	int user_id;
	float budget;	
	int bids;
	char user_name[20];
	
}user[1];

static int pin;

struct item{
	int item_no,winner_id;
	char name[20];
	char winner[20];
	float bid;
	float highest_bid;
	float reserve_price;
	bool status;
}auc1[1];

void filer(int n,int u_no){
	int i,j;
	FILE *fptr;
	fptr=fopen("auction.txt","w");
	fprintf(fptr,"=======================================================================================================================\n");
	fprintf(fptr,"\tname \t|\tuser id \t|\tno. of bids placed\t|\thighest bidson items no. \n");
    fprintf(fptr,"=======================================================================================================================\n");
	for(i=0;i<=u_no;i++){
		

	fprintf(fptr,"%12s %15d %26d\t",user[i].user_name,user[i].user_id,user[i].bids);	
	fprintf(fptr,"\t\t\t\t");
		for(j=0;j<=n;j++){
			if(auc1[j].winner_id==user[i].user_id){
				fprintf(fptr,"%d  ",auc1[j].item_no);
			}
		}
		fprintf(fptr,"\n");
	}
	fprintf(fptr,"=======================================================================================================================\n");
	fprintf(fptr,"\n\n\t\t\t\t\t RESULTS \n");
	fprintf(fptr,"=======================================================================================================================\n");
	fprintf(fptr,"\titem no \t|\titem name \t|\t winner \t|\t user id \t|\t sold at\n");
    fprintf(fptr,"=======================================================================================================================\n");

	for (i=1;i<=n;i++){
		
		if (auc1[i].status!=0){
			fprintf(fptr,"%12d%26s%25s%23d%24.2f\n",auc1[i].item_no,auc1[i].name,auc1[i].winner,auc1[i].winner_id,auc1[i].highest_bid);
		}
	
		else {
		fprintf(fptr,"%12d %23s\t\t\t\t *********NOT SOLD*********\n",auc1[i].item_no,auc1[i].name);
		}
		
	}	
		fprintf(fptr,"=======================================================================================================================\n");
	fclose(fptr);
	
	

}


void info(int n,int u_no){
	int i,j;
	printf("\n\n\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 User Information \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
	printf("=======================================================================================================================\n");
	printf("\tname \t|\tuser id \t|\tno. of bids placed\t|\thighest bidson items no. \n");
    printf("=======================================================================================================================\n");
	for(i=0;i<=u_no;i++){
		

	printf("%12s %15d %26d\t",user[i].user_name,user[i].user_id,user[i].bids);	
	printf("\t\t\t\t");
		for(j=0;j<=n;j++){
			if(auc1[j].winner_id==user[i].user_id){
				printf("%d  ",auc1[j].item_no);
			}
		}
		printf("\n");
	}
	printf("=======================================================================================================================\n");
	sleep(1);
	printf("press Enter to go back to menu screen");
	getchar();
	menuscrn(n,u_no);
}

void suggest(int n,int u_no){
	int u,i,b;
	char bud;
	bool ex=false;
	bool sug=false;
	system("cls");
	display(n);
	printf("\nenter you user id: ");
	scanf("%d",&u);
		do{
			
			for(i=0;i<=u_no;i++){
				if(u==user[i].user_id){
					b=i;
					ex=true;
					break;
				}
			}
			if(ex==false){
				printf("\n\n\t\tInvalid id plz reenter\n");
				printf("\nenter your user id :");
				scanf("%d",&u);
			}
		}while(ex!=true);
		getchar();
		if(user[b].budget!=-1){
		
		printf("\nuser name :%s\n\nYour budget is:%.2f\n",user[b].user_name,user[b].budget);
	for(i=1;i<=n;i++){
		if(auc1[i].reserve_price<user[b].budget && auc1[i].highest_bid<user[b].budget){
			printf("\nconsider item no. %d\n",i);
		}
	}
	
	
	
	printf("\npress enter to proceed to menu\n");
	getchar();
	menuscrn(n,u_no);
	}
	else {
		printf("\n\n\t\tYou didnt add budget while registration\n");
	do{
		printf("\npress B to add budget \npress M to switch to menu:");
		scanf(" %c",&bud);
		switch(bud){
			case 'B':
			case 'b':
				printf("\nrefer to the board for deciding the budget \nenter your budget:");
				scanf("%f",&user[b].budget);
				suggest(n,u_no);
			break;
			case 'm':
			case 'M':
				menuscrn(n,u_no);
			break;
			default:
				printf("\n\n\t\tinvalid input\n");
				sleep(1);
				//for the loop
				bud='x';
			break;
		}
	}while(bud=='x');
	}
	
}

void userinfo(int n,int u_no){

	int i,y;
	char x;
		printf("\n\n\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Create a User \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");

	printf("\n\n\nenter user name:");
	gets(user[u_no].user_name);
	user[u_no].user_id=u_no+1000;
	printf("\nYour user id is: %d\n",user[u_no].user_id);
	user[u_no].budget=-1;
	user[u_no].bids=0;
	printf("\n\t\t\t***REMEMBER YOUR ID FOR BIDDING***\n");
	user[u_no].bids=0;
	printf("\nif you want suggestions according to your budget enter B \nif you dont want to share your budget enter N\t");
	do{scanf(" %c",&x);
	
	
	switch (x){
		case 'B':
		case 'b':
			printf("\nrefer to the board for deciding the budget \nenter your budget:");
			scanf("%f",&user[u_no].budget);
			system("cls");
			menuscrn(n,u_no);
		break;
		case 'n':
		case 'N':
			system("cls");
			menuscrn(n,u_no);
		break;
		default:
				printf("\n\n\t\tinvalid input\n");
				sleep(1);
				printf("\nenter your choice again:");
		break;
		}
		
	}while(x!='q');
			
	
		
	
	}


void result(int n,int u_no){
	int i;
	printf("\n\n\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 AUCTION BOARD \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
	printf("=======================================================================================================================\n");
	
		printf("\n\n\n\t\t\t\t\tThe auction has ended");
				printf("\n\t\t\t\t\tcalculating results...\n");
					sleep(1);
				
					system("cls");	
		printf("\n\n\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 RESULTS \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
	printf("=======================================================================================================================\n");
	printf("\titem no \t|\titem name \t|\t winner \t|\t user id \t|\t sold at\n");
    printf("=======================================================================================================================\n");

	for (i=1;i<=n;i++){
		
		if (auc1[i].status!=0){
			printf("%12d%26s%25s%23d%24.2f\n",auc1[i].item_no,auc1[i].name,auc1[i].winner,auc1[i].winner_id,auc1[i].highest_bid);
		}
	
		else {
		printf("%12d %23s\t\t\t\t *********NOT SOLD*********\n",auc1[i].item_no,auc1[i].name);
		}
		
	}	
		printf("=======================================================================================================================\n");
		printf("\t\t\t\t\t  Thank you");
	sleep(1);
	getchar();
	filer(n,u_no);
	
	
}


void bidding(int n,int u_no){
	
	display(n);
	int buyer_number,bidon,y,i,b;
	char choice;
	float bid;
	bool ex=false;
	printf("\n\n\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Bidding \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
			printf("\nenter your user id :");
			scanf("%d",&buyer_number);
			do{
			
			for(i=0;i<=u_no;i++){
				if(buyer_number==user[i].user_id){
					b=i;
					ex=true;
					break;
				}
			}
			if(ex==false){
				printf("\n\n\t\tInvalid id plz reenter if you dont remember your id then enter '-1' and ask from management");
				printf("\nenter your user id :");
				scanf("%d",&buyer_number);
				if (buyer_number==-1){
					menuscrn(n,u_no);
				}
			}
		}while(ex!=true);
			
			printf("\nenter item no u want to bid on:");
			scanf("%d",&bidon);
			
		
				if(bidon>n){
					printf("\ninvalid input\n");
					printf("\nenter item no u want to bid on:");
					scanf("%d",&bidon);
				}
			
			printf("\nthe highest bid on item%d is:- %.2f  and the reserve price is:- %.2f\n",bidon,auc1[bidon].highest_bid,auc1[bidon].reserve_price);
			printf("\nif u dont want to bid the enter: -1 else enter your bid:");
			scanf("%f",&bid);
		
			if(bid!=-1){
		
				if(bid>auc1[bidon].highest_bid && bid>auc1[bidon].reserve_price){
					
					auc1[bidon].highest_bid=bid;
					auc1[bidon].winner_id=buyer_number;
					strcpy(auc1[bidon].winner,user[b].user_name);
					user[b].bids=user[b].bids+1;
					user[b].budget=user[b].budget-bid;
					auc1[bidon].status=true;
					printf("\n\n\t\t\t\t Thanks for bidding");
					sleep(1);
					
				}
					
				
				
			else {
				
				printf("your bid mst be higher than maximum bid and reserve price\n");
				sleep(2);

			}
		}
		
			
			system("cls");
			menuscrn(n,u_no);
	
				
	}
	
	
void display(int n){
	
	int i;
	
	printf("\n\n\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 AUCTION BOARD \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
	printf("=======================================================================================================================\n");
	printf("\titem no \t|\titem name\t|\treserve price\t|\thighest bid \n");
    printf("=======================================================================================================================\n");
	  
	
	for (i=1;i<=n;i++){
		
		printf("%12d %23s %28.2f  %20.2f\n",auc1[i].item_no,auc1[i].name,auc1[i].reserve_price,auc1[i].highest_bid);
		
	}
	printf("=======================================================================================================================\n");
	
}


void itemdata(int n){
	
	int i;
	
	for(i=1;i<=n;i++){
		
		auc1[i].item_no=i;
		printf("\nitem no.%d\n",auc1[i].item_no);
		printf("enter item name\n");
		gets (auc1[i].name);
		printf("\nenter reserve price for the item\n");
		scanf("%f",&auc1[i].reserve_price);
		getchar();
		auc1[i].highest_bid=0;
		auc1[i].status=false;
		
	}
	
	system("cls");
	display(n);
	
}

void menuscrn(int n,int u_no){
	
	system("cls");
	int x,c;
	
	do{
		printf("\n\n=======================================================================================================================");

		printf("\n\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 MENU OPTIONS \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
		printf("=======================================================================================================================\n");
		printf("=======================================================================================================================\n\n\n");

	printf("\t\t\t\t==========================================\n");
	printf("\t\t\t\tCreate new user     =================  '1'\n");
	printf("\t\t\t\t==========================================\n");
	printf("\t\t\t\tStart bidding       =================  '2'\n");
	printf("\t\t\t\t==========================================\n");
	printf("\t\t\t\tSuggestions         =================  '3'\n");
	printf("\t\t\t\t==========================================\n");
	printf("\t\t\t\tView Board          =================  '4'\n");
	printf("\t\t\t\t==========================================\n");
	printf("\t\t\t\tUser Info           =================  '5'\n");
	printf("\t\t\t\t==========================================\n");
	printf("\t\t\t\tSee results         =================  '6'\n");
	printf("\n=======================================================================================================================\n");
	printf("\nEnter your choice-->");
	
	scanf("%d",&x);
	getchar();
	system("cls");
	
	
	switch (x){
	
			case 1:
				system("cls");
				u_no=u_no+1;
				display(n);
				userinfo(n,u_no);
			break;
		
			case 2:
			
				bidding(n,u_no);
			break;
			case 3:
				
				suggest(n,u_no);
			break;
			case 4:
				system("cls");
				display(n);
				printf("press enter to go back");
				getchar();
				x=99;
				
			break;
			case 5:
				printf("\n\n\t\tenter pin\n");
				scanf("%d",&c);
				getchar();
				if(c==pin){
					system("cls");
					info(n,u_no);
					printf("press enter to go back");
					getchar();
					x=99;
				}
				else{
						printf("\n\tinvalid password\n");
						printf("if you have forgotten your password then check in pin.txt file");
						getchar();
						x=99;
					}
				
				
			break;
			case 6:
					printf("\n\n\t\tenter pin\n");
					scanf("%d",&c);
					if(c==pin){
						system("cls");
						result(n,u_no);
						exit(0);
					}
					else{
						printf("\n\tinvalid password\n");
						printf("if you have forgotten your password then check in pin.txt file");
						getchar();
						x=99;
					}
				
				break;
			default:
				printf("\n\n\t\tinvalid input");
				sleep(1);
				x=99;
			break;
		}
		system("cls");
	}while (x==99);
		
}
int main(){
	int n,y,u_no;
	char x;
	FILE *p;
	sleep(1);
	printf("\n\n\n\n\t\t\t\t\tC Program Interactive board\n");
	sleep(1);
	printf("\t\t\t==========================================================\n");
	sleep(1);
	printf("\t\t\t\t\t\t  WELCOME\n");
	sleep(1);
	printf("\t\t\t\t\t\t    to\n");
	sleep(1);
	printf("\t\t\t\t\t\tTHE AUCTION\n");
	sleep(1);
	printf("\t\t\t==========================================================\n");
	sleep(1);
	printf("\t\t\t==========================================================\n");
	sleep(1);
	printf("\t\t\t\t\t  press enter to start");
	sleep(1);
	getchar();
	system("cls");
	printf("set pin :");
	scanf("%d",&pin);
	p=fopen("pin.txt","w");
	fprintf(p,"%d",pin);
	fclose(p);
	system("cls");
	printf("\n\n\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Input Item Data \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
	printf("=======================================================================================================================\n");

	
	printf("\n\n\t\tEnter number of items: ");
	scanf("%d",&n);
	getchar();
	itemdata(n);
	printf("\n\n\t\t\t\t  press enter to start registration");
	getchar();
	userinfo(n,u_no);
	exit;
}
