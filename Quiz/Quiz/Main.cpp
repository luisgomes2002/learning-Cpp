#include<iostream>

int main() {
	std::string question[] = { "1. Question 1", "2. Question 2", "3. Question 3", "4. Question 4" };

	std::string options[][4] = {
		{"A. 1", "B. 2", "C. 3", "D. 4"},
		{"A. 1", "B. 2", "C. 3", "D. 4"},
		{"A. 1", "B. 2", "C. 3", "D. 4"},
		{"A. 1", "B. 2", "C. 3", "D. 4"},
	};
	
	char answerKey[] = { 'A', 'B', 'C', 'D'};

	int size = sizeof(question) / sizeof(question[0]);
	char guess;
	int score = 0;


	for (int i = 0; i < size; i++) {
		std::cout << "**************************\n";
		std::cout << question[i] << "\n";
		std::cout << "**************************\n";

		for (int j = 0; j < sizeof(options[i]) / sizeof(options[i][0]); j++) {
			std::cout << options[i][j] << "\n";
		}

		std::cin >> guess;
		guess = toupper(guess);

		if (guess == answerKey[i]) {
			std::cout << "Correct\n";
			score++;
		}
		else {
			std::cout << "Wrong\n";
		}
	}
	std::cout << "**************************\n";
	std::cout << "*         RESULTS        *\n";
	std::cout << "**************************\n";
	std::cout << "CORRECT GUESS: " << score <<"\n";
	std::cout << "# of Questions: " << size << "\n";
	std::cout << "Score: " << (score / (double)size) * 100 << "%\n";
	return 0;
}
	