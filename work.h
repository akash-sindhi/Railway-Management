#include<iostream>
#include<fstream>
#include<string.h>
#include<windows.h>
using namespace std;
struct Operations{
	string route;
	string timing;
	string rent;
	};
class Auth{
	private:
	string username,password,admin;
	ifstream fin;
	ofstream fout;
	public:
	bool signup(){
		fout.open("Authentication.txt",ios::in|ios::app);
		fin.open("Authentication.txt",ios::out);
		cout<<"\n\n\t\t\tEnter name of admin: ";
		cin>>admin;
		label:
		cout<<"\n\n\t\t\tEnter username: ";
		cin>>username;
		string x;
		while(fin>>x){
			if(x==username){
				cout<<"\n\n\t\t\tThis username already exists please enter unique"<<endl;
				goto label;
			}
		}
		cout<<"\n\n\t\t\tEnter password: ";
		cin>>password;
		fout<<"Admin name: "<<admin<<endl;
		fout<<"Username: "<<username;
		fout<<"  Password: "<<password<<endl;
		fout.close();
		return true;
		
		
	}
	bool login(){
		fin.open("Authentication.txt",ios::out);
		cout<<"\n\n\t\t\tEnter username: ";
		cin>>username;
		cout<<"\n\n\t\t\tEnter password: ";
		cin>>password;
		string x;
		while(getline(fin,x)){
			if(x=="Username: "+username+"  Password: "+password){
				fin.close();
				return true;
			}
		}
		fin.close();
		return false;
	}
};
class TrainOperations{
	private: 
		string trainNumber,numberOfSeats;
		Operations operation;
		ofstream input;
		ifstream output;
	void storeIninput(){
		input.open("TrainFile.txt",ios::in|ios::app);
		input<<"Train number: "<<trainNumber<<endl;
		input<<"Number of seats: "<<numberOfSeats<<endl;
		input<<"Route: "<<operation.route<<endl;
		input<<"Timing: "<<operation.timing<<endl;
		input<<"Rent: "<<operation.rent<<endl;
		input<<"_______________"<<endl;
		input.close();
	}
	public:
		void addNewTrain(){
			cout<<"\t\t\tEnter route: ";
			cin>>operation.route;
			cout<<"\t\t\tEnter train number: ";
			cin>>trainNumber;
			cout<<"\t\t\tEnter number of seats: ";
			cin>>numberOfSeats;
			cout<<"\t\t\tEnter timings: ";
			cin>>operation.timing;
			cout<<"\t\t\tEnter rent: ";
			cin>>operation.rent;
			storeIninput();
		}
		void viewTrains(){
			output.open("TrainFile.txt",ios::out);
			string x;
			while(getline(output,x)){
				cout<<"\t\t\t"<<x<<endl;
			}
			output.close();
		}
		void searchTrain(){
			output.open("TrainFile.txt",ios::out);
			string search;
			cout<<"\t\t\tEnter train number: ";
			cin>>search;
			string y;
			while(getline(output,y)){
				if(y==("Train number: "+search)){
					while(getline(output,y)){
						cout<<y<<endl;
						if(y=="_______________"){
							break;
						}
					}
				}
			}
			output.close();
		}		
};
class TicketBooking{
	private:
		string bookingId,nameOfPassenger,numberOfTickes,seatNumbers;
		Operations ticketOperation;
		ifstream fin;
		ofstream fout;
		void storeInFile(){
			fout.open("Tickets.txt",ios::in|ios::app);
			fin.open("TrainFile.txt",ios::out);
			fout<<"Booking id: "<<bookingId<<endl;
			fout<<"Passenger name: "<<nameOfPassenger<<endl;
			fout<<"Number of tickets: "<<numberOfTickes<<endl;
			fout<<"Route: "<<ticketOperation.route<<endl;
			string x;
			while(getline(fin,x)){
				if(x=="Route: "+ticketOperation.route){
					while(getline(fin,x)){
						if(x=="_______________"){
							break;
						}
						fout<<x<<endl;
						cout<<"\t\t\t"<<x<<endl;
					}
				}
			}
			fout<<"_______________"<<endl;
			fout.close();
			fin.close();
		}
	public:
		void bookTicket(){
			fin.open("TrainFile.txt",ios::out);
			cout<<"\t\t\tEnter booking id: ";
			cin>>bookingId;
			cout<<"\t\t\tEnter name of passenger: ";
			cin>>nameOfPassenger;
			cout<<"\t\t\tEnter number of tickets: ";
			cin>>numberOfTickes;
			label:
			cout<<"\t\t\tEnter route: ";
			cin>>ticketOperation.route;
			string x;
			bool flag = false;
			while(getline(fin,x)){
				if(x=="Route: "+ticketOperation.route){
				flag = true;
				}
			}
			if(flag==false){
				fin.close();
				cout<<"\t\t\tNo such route found...";
				Sleep(2000);
				cout<<endl;
				fin.open("TrainFile.txt",ios::out);
				goto label;
			}
			fin.close();
			storeInFile();
		}
		void viewBookings(){
			fin.open("Tickets.txt",ios::out);
			string x;
			while(getline(fin,x)){
				cout<<"\t\t\t"<<x<<endl;
			}
			fin.close();
		}
			void searchBooking(){
			fin.open("Tickets.txt",ios::out);
			string search;
			cout<<"\t\t\tEnter booking id for search: ";
			cin>>search;
			string y;
			while(getline(fin,y)){
				if(y==("Booking id: "+search)){
					while(getline(fin,y)){
						cout<<"\t\t\t"<<y<<endl;
						if(y=="_______________"){
							break;
						}
					}
				}
			}
			fin.close();
		}
};









