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
	else {
		cout << "no file entered!" << endl;
		exit(EXIT_FAILURE);
	}


	if (fileGiven) {

		ifstream myReadFile;
		myReadFile.open(argv[1]);

		// If the file was found then proceed
		if (!myReadFile.fail()) {

			string word;
			int size = 0;
			float *arr = nullptr;
			float average = 0;

			// count nmbr of words in line
			while (myReadFile >> word)
				size++;

			arr = new float[size];

			myReadFile.clear();
			myReadFile.seekg(0);

			// fills the array with values
			for (int i = 0; myReadFile >> word; i++)
			{
				// Checks if you can convert the "word" variable into a float, if not then the program will exit
				try {
					arr[i] = stof(word);
					average += stof(word);
				}
				catch (const std::exception&) {
					cout << "File contains invalid data" << endl;
					delete[] arr;
					arr = nullptr;
					exit(EXIT_FAILURE);
				}
			}

			myReadFile.close();

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


			delete[] arr;
		}
		else {
			cout << "File Not Found" << endl;
			exit(EXIT_FAILURE);
		}
	}

	system("pause");
	return 0;
}