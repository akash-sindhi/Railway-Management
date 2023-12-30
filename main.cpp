#include "work.h"
#include<conio.h>
void guidance(){
	cout<<"\n\n\t\t\t****User Guide****"<<endl;
	cout<<"\t\t\tPut '-' instead of spaces"<<endl;
	cout<<"\t\t\tEnter valid inputs"<<endl;
	cout<<"\t\t\tCheck data in files too"<<endl<<endl;
	cout<<"\t\t\tPress any key to continue....";
	getch();
	system("CLS");
}
void trainChoiceFun(){
	cout<<"\n\n\t\t\tPress 1 to enter new train"<<endl;
	cout<<"\t\t\tPress 2 to check existing trains"<<endl;
	cout<<"\t\t\tPress 3 to search specific train"<<endl;
	cout<<"\t\t\tPress 4 back to dashboard"<<endl;
	cout<<"\t\t\t";
}
void dashboard(){
	cout<<"\n\n\t\t\tPress 1 for train operations"<<endl;
	cout<<"\t\t\tPress 2 for booking options"<<endl;
	cout<<"\t\t\tPress 3 for logout"<<endl;
}
void bookingChoiceFun(){
	cout<<"\n\n\t\t\tPress 1 for booking tickets"<<endl;
	cout<<"\t\t\tPress 2 for view booking"<<endl;
	cout<<"\t\t\tPress 3 for search booking"<<endl;
	cout<<"\t\t\tPress 4 back to dashboard"<<endl;
	cout<<"\t\t\t";
}
int main(){
	guidance();
	char choice;
	Auth auth;
	back:
	cout<<"\t\t\t******TRAIN BOOKING SYSTEM******"<<endl<<endl;
	cout<<"\t\t\tPress 1 to create new account"<<endl;
	cout<<"\t\t\tPress 2 to login existing account"<<endl;
	cout<<"\t\t\t";
	choice = getch();
	system("CLS");
	switch(choice){
		case '1':
			cout<<"\n\n\t\t\tSIGNUP"<<endl;
			if(auth.signup()){
				cout<<"\n\n\t\t\tYour account has been created successfully"<<endl;
				cout<<"\n\n\t\t\tPress any key to continue.....";
				getch();
				goto label;
			}
			break;
		case '2':
			label:
			system("CLS");
			cout<<"\n\n\t\t\tLOGIN"<<endl;
			if(auth.login()){
				system("ClS");
			}else{
				cout<<"\n\n\t\t\t\aInvalid username and password"<<endl;
				cout<<"\n\n\t\t\tPlease try again....";
				Sleep(2000);
				goto label;
			}
			break;
		default:
			cout<<"\n\n\t\t\tInvalid input please try again...\a"<<endl;
			Sleep(2000);
			system("CLS");
			goto back;
			break;
	}
	TrainOperations operations;
	TicketBooking booking;
	while(true){
		dashboard:
		system("CLS");
		dashboard();
		cout<<"\t\t\t";
		choice = getch();
		system("CLS");
		switch(choice){
			case '1':
				trainChoiceFun();
				choice = getch();
				cout<<endl;
				if(choice=='1'){
					operations.addNewTrain();
					cout<<"\t\t\tNew train added...";
					Sleep(2000);
					goto dashboard;
				}else if(choice=='2'){
					operations.viewTrains();
				}else if(choice=='3'){
					operations.searchTrain();
				}else if(choice=='4'){
					goto dashboard;
				}
				else{
				cout<<"Invalid input please try again...\a"<<endl;
				Sleep(2000);
				goto dashboard;
				}
				cout<<"\t\t\tPress any key to continue...";
				getch();
				break;
			case '2':
				bookingChoiceFun();
				choice = getch();
				cout<<endl;
				if(choice=='1'){
					booking.bookTicket();
				}else if(choice=='2'){
					booking.viewBookings();
				}else if(choice=='3'){
					booking.searchBooking();
				}else if(choice=='4'){
					goto dashboard;
				}
				else{
				cout<<"Invalid input please try again...\a"<<endl;
				Sleep(2000);
				goto dashboard;
				}
				cout<<"\t\t\tPress any key to continue...";
				getch();
				break;
			case '3':
				goto label;
				break;
		}
		
	}
	return 0;
}

