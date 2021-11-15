
#include <iostream>

class Loader {
private : 
	std::string m_username{ " " };
	std::string m_password{ " " };

public :
	int menuChoice() { 
		int choice{};
		std::cout << "\n\n1. Register 2. Login 3. Exit\n";
		std::cin >> choice;
		return choice;
	}

	std::string setUsername() {
		std::string userName{ " " };
		std::cout << "\nEnter username : ";
		std::cin >> userName;
		return userName;
	}

	std::string setPassword() {
		std::string password{ " " };
		std::cout << "\nEnter password : ";
		std::cin >> password;
		return password;
	}

	void setUserData(std::string& username, std::string& password) {
		username = setUsername();
		password = setPassword();
	}

	void signup() {
		std::cout << "\nREGISTER";
		setUserData(m_username, m_password);
	}

	void login() {
		if (username && password != " "){
			std::string loginUsername{ "" };
			std::string loginPassword{ "" }; 

			std::cout << "\nLOGIN\n";
			setUserData(loginUsername, loginPassword);
		
			if (checkLogin(m_username, m_password, loginUsername, loginPassword)) {
				std::cout << "\nLogin Success! Welcome " << m_username;
			}
			else 	{
				std::cout << "\nLogin failiure! Returning to menu \n";
			}
		}
		else {
			std::cout << "\nNo Registered users!\n";
		}
	}

	bool checkLogin(const std::string& username, const std::string& password, std::string& loginUsername, std::string& loginPassword) { // Checks if login saved from signup is the same one user entered - You could possibly just put this in login function

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

};


int main(){

	Loader loader;
	bool repeat{ true };

	while (repeat) {

		switch (loader.menuChoice()) {

		case 1:
			loader.signup();
			break;
		case 2:
			loader.login(); 
			break;
		default:
			repeat = false;

		}
	}

}



