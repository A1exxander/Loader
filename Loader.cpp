
#include <iostream>

int  menuChoice ();
void getUserData		(std::string& username, std::string& password);
void signup				(std::string& username, std::string& password);
void login				(const std::string& username, const std::string& password);
bool checkLogin			(const std::string& username, const std::string& password, const std::string& loginUsername, const std::string& loginPassword);

int main(){

	std::string username{ "" };
	std::string password{ "" };
	
	char repeat{ 'Y' };

	while (repeat == 'Y') {

		switch (menuChoice()) {

		case 1:
			signup(username, password);
			break;
		case 2:
			login(username, password); // If we wanted to do something while user was logged in, we could store the results of login success in a bool and if its true call things in main, or even in this case
			break;
		default:
			repeat = 'N';

		}
	}

}



int menuChoice() { // Unneeded since this is exclusive to the one loader menu, but it looks cleaner
		
		int choice{};
	
		std::cout << "\n\n1. Register 2. Login 3. Exit\n";

		std::cin  >> choice;

		return choice;

	}

void getUserData(std::string& username, std::string& password) {

	std::cout << "\nEnter username : ";

	std::cin >> username;

	std::cout << "\nEnter password : ";

	std::cin >> password;

}

void signup(std::string& username, std::string& password){

	std::cout << "\nREGISTER";

	getUserData(username, password);

}

void login (const std::string& username, const std::string& password) {

	std::string loginUsername{""};
	std::string loginPassword{""}; // We could put this in main, but these vars are exclusive to the login function and arent used anywhere else and cant be used anywhere else really, so its best to just leave them in here

	std::cout << "\nLOGIN\n";
	getUserData(loginUsername, loginPassword);

	if (checkLogin(username, password, loginUsername, loginPassword)) {
		std::cout << "\nLogin Success! Welcome " << username;
	}
	else {
		std::cout << "\nLogin failiure! Returning to menu \n";
	}

}

bool checkLogin(const std::string& username, const std::string& password, const std::string& loginUsername, const std::string& loginPassword) { // Checks if login saved from signup is the same one user entered - You could possibly just put this in login function

	short loginAttempts = 3;

	while ((loginUsername != username || loginPassword != password) && loginAttempts > 0) {


		if (loginAttempts == 3) {
			std::cout << "\nInvalid login. Please re-enter username and password\n";
			std::cin >> loginUsername >> loginPassword;
		}
		else if (loginAttempts > 1 && loginAttempts != 3) {
			std::cout << "\n" << loginAttempts << " remaining attemps \n";
			std::cin >> loginUsername >> loginPassword;
		}
		else {
			std::cout << "\nFinal Attempt\n";
			std::cin >> loginUsername >> loginPassword;
		}

		--loginAttempts;
	}

	if (loginUsername == username && loginPassword == password) {
		return true;
	}
	else {
		return false;
	}
}

