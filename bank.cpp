#include <iostream>
#include<string>
#include<random>
#include <ctime>  
#include<CCTYPE>
#include <cstdlib>
#include<iomanip>
#include<vector>
#include <fstream>
using namespace std;


const string fileName = "Clients.txt";

//struct client {
//	string accountNumber="";
//	string pinCode="";
//	string name="";
//	string phone="";
//	double balance=0.0;
//	bool mark = false;
//};
//vector<string> splitString(string str,string delim) {
//	vector<string>strings;
//	short pos = 0;
//	string element = "";
//	while ((pos = str.find(delim)) != std::string::npos) {
//		element = str.substr(0, pos);
//		if (element != "")
//			strings.push_back(element);
//		str.erase(0, pos + delim.length());
//	}
//	if (str!="") {
//		strings.push_back(str);
//	}
//
//	return strings;
//}
//client fillClientInfoFromVector(string str, string delim) {
//	vector<string>strings;
//	strings = splitString(str, delim);
//	client cln;
//
//	cln.accountNumber = strings[0];
//	cln.pinCode = strings[1];
//	cln.name = strings[2];
//	cln.phone = strings[3];
//	cln.balance = stod(strings[4]);
//
//	return cln;
//
//}
//vector <client>moveFileDataToClientsVector(string filename) {
//	vector <client>clients;
//	client cln;
//	fstream file;
//	file.open(filename, ios::in);
//	if (file.is_open()) {
//		string dataline;
//		while (getline(file, dataline)) {
//			cln=fillClientInfoFromVector( dataline, "#//#");
//			clients.push_back(cln);
//		}
//		file.close();
//	}
//	return clients;
//}
//void printStructAsLine(client excln) {
//	cout << "| " << left << setw(15) << excln.accountNumber;
//	cout << "| " << left << setw(10) << excln.pinCode;
//	cout << "| " << left << setw(15) << excln.name;
//	cout << "| " << left << setw(12) << excln.phone;
//	cout << "| " << left << setw(12) << excln.balance;
//	cout << endl;
//
//}
//client askForClientInfo(string accountNumber) {
//	client tempClient;
//	tempClient.accountNumber = accountNumber;
//
//	cout << "please enter pin code:"<<endl;
//	getline(cin>>ws, tempClient.pinCode);
//
//	cout << "please enter name:"<<endl;
//	getline(cin, tempClient.name);
//
//	cout << "please enter phone:" << endl;
//	getline(cin, tempClient.phone);
//
//	cout << "please enter balance:"<<endl;
//	 cin>> tempClient.balance;
//
//	 return tempClient;
//}
//bool ClientByThisNumberIsFound(string filename,string accountNumber) {
//	vector <client> clients = moveFileDataToClientsVector(filename);
//	for (client cln : clients) {
//		if (cln.accountNumber == accountNumber)
//			return true;
//	}
//	return false;
//}
//string convertStructInfoToLine(client cln1 , string delim) {
//	string line;
//
//	line += cln1.accountNumber + delim;
//	line += cln1.pinCode + delim;
//	line += cln1.name + delim;
//	line += cln1.phone + delim;
//	line += to_string(cln1.balance);
//
//	return line;
//}
//string askForAccountNumber() {
//	string accountNumber;
//
//	cout << "please enter the account number:";
//	cin.ignore();
//	getline(cin, accountNumber) ;
//
//	return accountNumber;
//
//}
//void printClientAsInfo(client cln) {
//	cout << "the following are the client detail:" << endl;
//	cout << "------------------------------------------------------" << endl;
//	cout << "acount number:" << cln.accountNumber << endl;
//	cout << "Pin Code:" << cln.pinCode << endl;
//	cout << "Name:" << cln.name << endl;
//	cout << "Phone:" << cln.phone << endl;
//	cout << "Account Balance:" << cln.balance << endl;
//	cout << "------------------------------------------------------" << endl;
//
//
//}
//bool addNewVectorToFile(vector <client>& clients, string filename) {
//	fstream file;
//	file.open(filename, ios::out);
//	if (file.is_open()) {
//		for (client& cln : clients) {
//			string data;
//			data = convertStructInfoToLine(cln, "#//#");
//			file << data << endl;
//		}
//		file.close();
//		return true;
//
//	}
//	return false;
//}
//void markElementWillBeRemoved(vector <client>& clients, string accNum) {
//	for (client& cln : clients) {
//		if (cln.accountNumber == accNum) {
//			cln.mark = true;
//		}
//	}
//}
//bool rewriteOnlyNonMarkedClientsToFile(vector <client>& clients, string filename) {
//	fstream file;
//	file.open(filename, ios::out);
//	if (file.is_open()) {
//		for (client& cln : clients) {
//			string data;
//			if (cln.mark == false) {
//				data = convertStructInfoToLine(cln, "#//#");
//				file << data << endl;
//			}
//		}
//		file.close();
//		return true;
//
//	}
//	return false;
//}
//void showClientsScreen(string filename) {
//	vector <client>clients = moveFileDataToClientsVector(filename);
//
//	cout << "\t\t\t\t Client List (" << clients.size() << ") Client(s)\n\n";
//	cout << "---------------------------------------------------------------------------" << endl;
//	cout << "| " << left << setw(15) << "Account Number";
//	cout << "| " << left << setw(10) << "Pin Code";
//	cout << "| " << left << setw(15) << "Client Name";
//	cout << "| " << left << setw(12) << "Phone";
//	cout << "| " << left << setw(12) << "Balance";
//	cout << "\n--------------------------------------------------------------------------" << endl;
//
//	for (client cln : clients) {
//		printStructAsLine(cln);
//	}
//	cout << "\n--------------------------------------------------------------------------" << endl;
//
//}
//void addClientScreen(string filename) {
//	char more = 'Y';
//
//	do {
//		string accnumber = askForAccountNumber();
//
//		vector <client> clients = moveFileDataToClientsVector(filename);
//		if (ClientByThisNumberIsFound(filename, accnumber)) {
//			cout << "this client is already exists !";
//			return;
//		}
//		else {
//			client newclient = askForClientInfo(accnumber);
//			clients.push_back(newclient);
//			if (addNewVectorToFile(clients, filename)) {
//				cout << "\nAdded sucssesfuully ! do you want to add more?";
//				cin >> more;
//			}
//			else {
//				cout << "error !";
//			}
//		}
//	} while (toupper(more) == 'Y');
//
//}
//void deleteClientSecreen(string filename) {
//
//	string accnumber = askForAccountNumber();
//	char sure = 'Y';
//	vector <client> clients = moveFileDataToClientsVector(filename);
//	if (!(ClientByThisNumberIsFound(filename, accnumber))) {
//		cout << "this client does not exist !";
//		return;
//	}
//	else {
//		markElementWillBeRemoved(clients, accnumber);
//		cout << "Are sure that you want to remove this client?";
//		cin >> sure;
//
//		if (toupper(sure) == 'Y') {
//			rewriteOnlyNonMarkedClientsToFile(clients, filename);
//		}
//		else {
//			cout << "deletion canceled !";
//		}
//	}
//}
//bool updateClientSecreen(string filename) {
//	char update = 'Y';
//	string accnum = askForAccountNumber();
//	vector<client> clients = moveFileDataToClientsVector(filename);
//	for (client& cln : clients) {
//		if (cln.accountNumber == accnum) {
//			printClientAsInfo(cln);
//			cout << "are you sure that you want to update?";
//			cin >>update;
//			if (toupper(update) == 'Y') {
//				cln = askForClientInfo(accnum);
//				addNewVectorToFile(clients, fileName);
//				cout << "updated sucsesfully !";
//				return true;
//			}
//		}
//
//	}
//	cout << "this client does not exist";
//	return false;
//}
//bool searchClientScreen(string filename) {
//	string accnum= askForAccountNumber();
//	vector<client>clientsInFile = moveFileDataToClientsVector(filename);
//	for (client &cln : clientsInFile) {
//		if (cln.accountNumber == accnum) {
//			printClientAsInfo(cln);
//			return true;
//		}
//	}
//	cout << "the client does not exist error !" << endl;
//	return false;
//}
//
//void menue() {
//	cout << "===================================================" << endl;
//	cout << "                    Main menue secreen" << endl;
//	cout << "===================================================" << endl;
//	cout << "for show all clients in the file please press 1" << endl;
//	cout << "to add new client to file please press 2" << endl;
//	cout << "to delete client from the file please press 3" << endl;
//	cout << "to update client please press 4" << endl;
//	cout << "to search by account number press 5" << endl;
//	cout << "press 6 to exit program" << endl;
//
//}
//void startProgram() {
//
//	do {
//		system("cls");
//		short userChoose;
//		menue();
//		cout << "your choice:";
//		cin >> userChoose;
//		switch (userChoose) {
//		case 1:
//            showClientsScreen(fileName);
//			break;
//		case 2:
//            addClientScreen(fileName);
//			break;
//		case 3:
//            deleteClientSecreen(fileName);
//			break;
//		case 4:
//            updateClientSecreen(fileName);
//			break;
//		case 5:
//            searchClientScreen(fileName);
//			break;
//		case 6:
//			return;
//		}
//		cout << "press any key to return to menue..";
//	} while (!(system("pause>0")));
//
//
//}
//int main() {
//	startProgram();
//}

//Corrections of code  

struct client {
	string accountNumber="";
	string pinCode="";
	string name="";
	string phone="";
	double balance=0.0;
	bool mark = false;
};
void menue();
vector<string> splitString(string str,string delim) {
	vector<string>strings;
	short pos = 0;
	string element = "";
	while ((pos = str.find(delim)) != std::string::npos) {
		element = str.substr(0, pos);
		if (element != "")
			strings.push_back(element);
		str.erase(0, pos + delim.length());
	}
	if (str!="") {
		strings.push_back(str);
	}

	return strings;
}
client fillClientInfoFromVector(string str, string delim) {
	vector<string>strings;
	strings = splitString(str, delim);
	client cln;

	cln.accountNumber = strings[0];
	cln.pinCode = strings[1];
	cln.name = strings[2];
	cln.phone = strings[3];
	cln.balance = stod(strings[4]);

	return cln;

}
vector <client>moveFileDataToClientsVector(string filename) {
	vector <client>clients;
	client cln;
	fstream file;
	file.open(filename, ios::in);
	if (file.is_open()) {
		string dataline;
		while (getline(file, dataline)) {
			cln=fillClientInfoFromVector( dataline, "#//#");
			clients.push_back(cln);
		}
		file.close();
	}
	return clients;
}
void printStructAsLine(client excln) {
	cout << "| " << left << setw(15) << excln.accountNumber;
	cout << "| " << left << setw(10) << excln.pinCode;
	cout << "| " << left << setw(15) << excln.name;
	cout << "| " << left << setw(12) << excln.phone;
	cout << "| " << left << setw(12) << excln.balance;
	cout << endl;

}
bool ClientByThisNumberIsFound(vector <client> Clients, string accountNumber,client &clnt) {
	for (client cln : Clients) {
		if (cln.accountNumber == accountNumber)
			clnt = cln;
			return true;
	}
	return false;
}
bool isExistByAccountNumber(string filename, string accountNumber) {
	client cln;
	fstream file;
	file.open(filename, ios::in);
	if (file.is_open()) {
		string line;
		while (getline(file,line)) {
			cln = fillClientInfoFromVector(line, "#//#");
			if (cln.accountNumber == accountNumber) {
				file.close();
				return true;
			}
		}
		file.close();
		return false;
	}

}
client askForClientInfo() {
	client tempClient;
	cout << "Enter Account Number? ";
	getline(cin >> ws, tempClient.accountNumber);

	while (isExistByAccountNumber(fileName, tempClient.accountNumber)) {
		cout << "\nClient with [" << tempClient.accountNumber << "] already exists, Enter another Account Number? ";
		getline(cin >> ws, tempClient.accountNumber);
	}

	cout << "please enter pin code:" << endl;
	getline(cin >> ws, tempClient.pinCode);

	cout << "please enter name:" << endl;
	getline(cin, tempClient.name);

	cout << "please enter phone:" << endl;
	getline(cin, tempClient.phone);

	cout << "please enter balance:" << endl;
	cin >> tempClient.balance;

	return tempClient;
}
string convertStructInfoToLine(client cln1 , string delim) {
	string line;

	line += cln1.accountNumber + delim;
	line += cln1.pinCode + delim;
	line += cln1.name + delim;
	line += cln1.phone + delim;
	line += to_string(cln1.balance);

	return line;
}
client ChangeClientRecord(string AccountNumber)
{
	client Client;

	Client.accountNumber = AccountNumber;

	cout << "\n\nEnter PinCode? ";
	getline(cin >> ws, Client.pinCode);

	cout << "Enter Name? ";
	getline(cin, Client.name);

	cout << "Enter Phone? ";
	getline(cin, Client.phone);

	cout << "Enter AccountBalance? ";
	cin >> Client.balance;
	return Client;
}
string askForAccountNumber() {
	string accountNumber;

	cout << "please enter the account number:";
	cin.ignore();
	getline(cin, accountNumber) ;

	return accountNumber;

}
void printClientAsInfo(client cln) {
	cout << "the following are the client detail:" << endl;
	cout << "------------------------------------------------------" << endl;
	cout << "acount number:" << cln.accountNumber << endl;
	cout << "Pin Code:" << cln.pinCode << endl;
	cout << "Name:" << cln.name << endl;
	cout << "Phone:" << cln.phone << endl;
	cout << "Account Balance:" << cln.balance << endl;
	cout << "------------------------------------------------------" << endl;


}
void addDataLineToFile(string dataLine, string filename) {
	fstream file;
	file.open(filename, ios::out|ios::app );
	if (file.is_open()) {
		file <<dataLine << endl;
		file.close();
	}
}

void addNewClient() {
	client cln = askForClientInfo();
	addDataLineToFile(convertStructInfoToLine(cln,"#//#"), fileName);

}
void AddNewClients()
{
	char AddMore = 'Y';
	do
	{
		//system("cls");
		cout << "Adding New Client:\n\n";

		addNewClient();
		cout << "\nClient Added Successfully, do you want to add more clients? Y/N? ";
		cin >> AddMore;

	} while (toupper(AddMore) == 'Y');

}
void markElementWillBeRemoved(vector <client>& clients, string accNum) {
	for (client& cln : clients) {
		if (cln.accountNumber == accNum) {
			cln.mark = true;
		}
	}
}
bool rewriteOnlyNonMarkedClientsToFile(vector <client>& clients, string filename) {
	fstream file;
	file.open(filename, ios::out);
	if (file.is_open()) {
		for (client& cln : clients) {
			string data;
			if (cln.mark = false) {
				data = convertStructInfoToLine(cln, "#//#");
				file << data << endl;
			}
		}
		file.close();
		return true;

	}
	return false;
}

void showClients(string filename) {
	vector <client>clients = moveFileDataToClientsVector(filename);

	cout << "\t\t\t\t Client List (" << clients.size() << ") Client(s)\n\n";
	cout << "---------------------------------------------------------------------------" << endl;
	cout << "| " << left << setw(15) << "Account Number";
	cout << "| " << left << setw(10) << "Pin Code";
	cout << "| " << left << setw(15) << "Client Name";
	cout << "| " << left << setw(12) << "Phone";
	cout << "| " << left << setw(12) << "Balance";
	cout << "\n--------------------------------------------------------------------------" << endl;
	if (clients.size() == 0)
		cout << "No Clients  Avaliable" << endl;
	else
		for (client cln : clients) {
			printStructAsLine(cln);
		}
	cout << "\n--------------------------------------------------------------------------" << endl;

}
bool DeleteClientByAccountNumber(string AccountNumber, vector <client>& vClients)
{
	client Client;
	char Answer = 'n';

	if (ClientByThisNumberIsFound(vClients,AccountNumber, Client))
	{

		printClientAsInfo(Client);

		cout << "\n\nAre you sure you want delete this client? y/n ? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			markElementWillBeRemoved(vClients,AccountNumber);
			rewriteOnlyNonMarkedClientsToFile(vClients,fileName);

			//Refresh Clients 
			vClients = moveFileDataToClientsVector(fileName);

			cout << "\n\nClient Deleted Successfully.";
			return true;
		}

	}
	else
	{
		cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!";
		return false;
	}
}
bool UpdateClientByAccountNumber(string accountNumber, vector<client> &clients)	 {
	client cln;
	char update = 'Y';
	//string accnum = askForAccountNumber();
	if (ClientByThisNumberIsFound(clients, accountNumber,cln))
	{
		printClientAsInfo(cln);
		cout << "are you sure that you want to update?";
		cin >> update;
		if (toupper(update) == 'Y') {

			for (client& cln : clients) {
				if (cln.accountNumber == accountNumber) {
					cln = ChangeClientRecord(accountNumber);
					break;
				}
			}
			rewriteOnlyNonMarkedClientsToFile(clients, fileName);
			cout << "updated sucsesfully !";
			return true;
		}
	}
	else {
		cout << "The client with account number ("<<accountNumber<<") is not found";
		return false;
	}

}

void ShowDeleteClientScreen()
{
	cout << "\n-----------------------------------\n";
	cout << "\tDelete Client Screen";
	cout << "\n-----------------------------------\n";

	vector <client> vClients =
		moveFileDataToClientsVector(fileName);
	string AccountNumber = askForAccountNumber();
	DeleteClientByAccountNumber(AccountNumber, vClients);
}
void ShowUpdateClientScreen()
{
	cout << "\n-----------------------------------\n";
	cout << "\tUpdate Client Info Screen";
	cout << "\n-----------------------------------\n";

	vector <client> vClients =
		moveFileDataToClientsVector(fileName);
	string AccountNumber = askForAccountNumber();
	UpdateClientByAccountNumber(AccountNumber, vClients);
}
void ShowAddNewClientsScreen()
{
	cout << "\n-----------------------------------\n";
	cout << "\tAdd New Clients Screen";
	cout << "\n-----------------------------------\n";
	AddNewClients();
}
void ShowFindClientScreen() {
	cout << "\n-----------------------------------\n";
	cout << "\tFind Client Screen";
	cout << "\n-----------------------------------\n";

	string accnum = askForAccountNumber();
	vector<client>clientsInFile = moveFileDataToClientsVector(fileName);
	client clnt;
	if (ClientByThisNumberIsFound(clientsInFile, accnum, clnt)) {
		printClientAsInfo(clnt);
	}
	else {
		cout << "the client does not exist error !" << endl;
	}

}

void ShowEndScreen()
{
	cout << "\n-----------------------------------\n";
	cout << "\tProgram Ends :-)";
	cout << "\n-----------------------------------\n";
}
enum enMainMenueOptions
{
	eListClients = 1, eAddNewClient = 2,
	eDeleteClient = 3, eUpdateClient = 4,
	eFindClient = 5, eExit = 6
};
void GoBackToMainMenue()
{
	cout << "\n\nPress any key to go back to Main Menue...";
	system("pause>0");
	system("cls");
	menue();
}
short ReadMainMenueOption()
{
	cout << "Choose what do you want to do? [1 to 6]? ";
	short Choice = 0;
	cin >> Choice;
	return Choice;
}
void PerfromMainMenueOption(enMainMenueOptions MainMenueOption)
{
	switch (MainMenueOption)
	{
	case enMainMenueOptions::eListClients:
		system("cls");
		showClients(fileName);
		GoBackToMainMenue();
		break;
	case enMainMenueOptions::eAddNewClient:
		system("cls");
		ShowAddNewClientsScreen();
		GoBackToMainMenue();
		break;
	case enMainMenueOptions::eDeleteClient:
		system("cls");
		ShowDeleteClientScreen();
		GoBackToMainMenue();
		break;
	case enMainMenueOptions::eUpdateClient:
		system("cls");
		ShowUpdateClientScreen();
		GoBackToMainMenue();
		break;
	case enMainMenueOptions::eFindClient:
		system("cls");
		ShowFindClientScreen();
		GoBackToMainMenue();
		break;
	case enMainMenueOptions::eExit:
		system("cls");
		ShowEndScreen();
		break;
	}
}
void menue() {
	cout << "===================================================" << endl;
	cout << "                    Main menue secreen" << endl;
	cout << "===================================================" << endl;
	cout << "for show all clients in the file please press 1" << endl;
	cout << "to add new client to file please press 2" << endl;
	cout << "to delete client from the file please press 3" << endl;
	cout << "to update client please press 4" << endl;
	cout << "to search by account number press 5" << endl;
	cout << "press 6 to exit program" << endl;

	PerfromMainMenueOption((enMainMenueOptions)ReadMainMenueOption());
}

int main() {
	menue();
	system("pause>0");
	return 0;
}