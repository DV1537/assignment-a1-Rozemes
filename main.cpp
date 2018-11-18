#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

int main(int argc, char* argv[]) {

	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	// Checks if a second argument(the filename) is given
	bool fileGiven = false;
	if (argc > 1)
		fileGiven = true;
	else
		cout << "no file entered!" << endl;


	if (fileGiven) {

		ifstream myReadFile;
		myReadFile.open(argv[1]);

		// If the file was found then proceed
		if (!myReadFile.fail()) {

			string word;
			int size = 0;
			bool validInput = true;
			float *arr = nullptr;
			float average = 0;

			// Read all the words in the textfile and store them as ints in an allocated array which increases in size for each word
			while (!myReadFile.eof() && validInput) {
				myReadFile >> word;
				size++;

				float *temp = new float[size];

				for (int i = 0; i < size - 1; i++)
					temp[i] = arr[i];

				// If you cant convert the "word" variable into a float number, then it must contain characters. 
				// In that case the file is invalid
				try {
					temp[size - 1] = stof(word);
					average += stof(word);
				}
				catch (const std::exception&) {
					cout << "File contains invalid data" << endl;
					validInput = false;
				}

				delete[] arr;
				arr = temp;
				temp = nullptr;
			}

			if (validInput) {
				average /= size;

				// Printing out all the values in the array that are above average and formatting the numbers with a maximum of three deciamals
				for (int i = 0; i < size; i++) {
					if (arr[i] > average) {
						arr[i] *= 1000;
						arr[i] = floor(arr[i]);
						arr[i] /= 1000;
						cout << arr[i] << " ";
					}
				}
				cout << endl;
			}
			myReadFile.close();

			delete[] arr;
		}
		else
			cout << "File Not Found" << endl;

	}

	system("pause");
	return 0;
}