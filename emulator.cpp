// UnixEmulator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
using namespace std;

string hostname;
string username;
string input;
string sudopassword;

void loginStart();

int prompt()
{
	cout << username << "@" << hostname << ":~$ ";
	cin >> input;
	if (input == "help") {
		cout << "Help:" << endl;
		cout << "help  -  Displays the help command" << endl;
		cout << "logout  -  Ends the user session" << endl;
		cout << "login  -  Creates a new user session" << endl;
		prompt();
	}
	else if (input == "shutdown") {
		return 0;
	}
	else if (input == "logout") {
		cout << "Logging out..." << endl;
		cout << "You have been logged out.  Type 'login' to login" << endl << username << "@" << hostname << ":~$ ";
		loginStart();
	}
	else if (input == "sudo -s") {
		cout << "[sudo] password for " << username << " ";
		cin >> sudopassword;
	}
	else {
		cout << "-bash: " << input << ": " << "command not found" << endl;
		prompt();
	}
}

void login() {
	cout << "Please choose a host name" << endl << "~$ ";
	cin >> hostname;
	cout << "Please choose a username" << endl << "~$ ";
	cin >> username;
	prompt();
}

void nonExistentCommandLogin() {
	cout << "-bash: " << input << ": " << "command not found" << endl;
	loginStart();
}

void loginStart() {
	cin >> input;
	if (input == "login") {
		login();
	}
	else {
		nonExistentCommandLogin();
	}
}

int main()
{
	cout << "Welcome to the Unix terminal emulator made by Topik!" << "  " << "Please choose a host name" << endl << "~$ ";
	cin >> hostname;
	cout << "Please choose a username" << endl << "~$ ";
	cin >> username;
	prompt();
}
