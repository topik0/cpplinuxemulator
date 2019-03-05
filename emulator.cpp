// UnixEmulator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

// #include "pch.h"
#include <iostream>
#include <string>
using namespace std;

string hostname;
string username;
string input;
string sudopassword;
string userhost;
int sudoPasswordCount = 0;

void loginStart();
bool sudoPasswordCheck();
int main();

int prompt()
{
	cout << userhost;
	getline(cin, input);	
	if (input == "help") {
		cout << "Help:" << endl;
		cout << "help  -  Displays the help command" << endl;
		cout << "logout  -  Ends the user session" << endl;
		cout << "login  -  Creates a new user session" << endl;
		cout << "sudo -s  -  Activates a root shell session" << endl;
		cout << "shutdown  -  Ends the user session" << endl;
		cout << "reboot  -  Reboots the system" << endl;
		prompt();
	}
	else if (input == "shutdown") {
		system("exit");
	}
	else if (input == "reboot" || input == "restart"){
	    cout << "Rebooting..." << endl;
	    main();
	}
	else if (input == "logout") {
		cout << "Logging out..." << endl;
		cout << "You have been logged out.  Type 'login' to login" << endl << userhost;
		loginStart();
	}
	else if (input == "sudo -s") {
		cout << "[sudo] password for " << username << ": ";
		getline(cin, input);
		while(sudoPasswordCheck() == false && sudoPasswordCount < 2) {
			sudoPasswordCount++;
			cout << "Sorry, try again." << endl;
			cout << "[sudo] password for " << username << ": ";
			getline(cin, input);
		}
		if (sudoPasswordCheck() == true) {
			username = "root";
			userhost = username + "@" + hostname + ":~$ ";
			prompt();
		}
		cout << "sudo: 3 incorrect password attempts" << endl;
		prompt();
	}
	//else if(input == "sudo passwd"){
	//    cout << 
	//}
	else {
		cout << "-bash: " << input << ": " << "command not found" << endl;
		prompt();
	}
}

bool sudoPasswordCheck() {
	if (sudopassword == input) {
		return true;
	}
	else {
		return false;
	}
}

void login() {
	cout << "Please choose a host name" << endl << "~$ ";
	getline(cin, hostname);
	cout << "Please choose a username" << endl << "~$ ";
	getline(cin, username);
	cout << "Please choose a sudo password" << endl << "~$ ";
	getline(cin, sudopassword);
	userhost = username + "@" + hostname + ":~$ ";
	prompt();
}

void nonExistentCommandLogin() {
	cout << "-bash: " << input << ": " << "command not found" << endl;
	loginStart();
}

void loginStart() {
	getline(cin, input);
	if (input == "login") {
		login();
	}
	else {
		nonExistentCommandLogin();
	}
}

int main()
{
	cout << "Welcome to the Linux terminal emulator made by Topik!" << "  " << "Please choose a host name" << endl << "> ";
	getline(cin, hostname);
	cout << "Please choose a username" << endl << "> ";
	getline(cin, username);
	cout << "Please choose a sudo password" << endl << "> ";
	getline(cin, sudopassword);
	userhost = username + "@" +  hostname + ":~$ ";
	prompt();
}
