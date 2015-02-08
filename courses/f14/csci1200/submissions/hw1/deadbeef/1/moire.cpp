#include <iostream>
#include <string>
#include <fstream>

using namespace std;

string square(string text, int height, string file) {
	
	string output;
	
	for(int w = 0; w < height + 2; w++) output += "*";
	output += "\n";
	
	int characterNumber = 0;
	for(int h = 0; h < height; h++) {
		output += "*";
		for(int c = 0; c < height; c++) {
			if (characterNumber >= text.length()) {
				characterNumber = 0;
			}
			output += text[characterNumber];
			characterNumber++;
		}
		output += "*\n";
	}
	
	for(int w = 0; w < height + 2; w++) output += "*";
	output += "\n";
	
	cout << output;
	return output;
}

string rightTriangle(string text, int height, string file) {
	
	string output;
	
	output += "*\n";
	
	int characterNumber = 0;
	int lineLengthener = 0;
	for(int h = 0; h < height; h++) {
		output += "*";
		for(int c = 0; c < lineLengthener; c++) {
			if (characterNumber >= text.length()) {
				characterNumber = 0;
			}
			output += text[characterNumber];
			characterNumber++;
		}
		output += "*\n";
		lineLengthener++;
	}
	
	for(int w = 0; w < height + 2; w++) output += "*";
	output += "\n";
	
	cout << output;
	return output;
}

string isoscelesTriangle(string text, int height, string file) {
	
	string output;
	
	for(int s=0; s < height + 1; s++) output += " ";
	output += "*\n";
	
	int characterNumber = 0;
	int lineLengthener = 0;
	int characterLength = 1;
	for(int h = 0; h < height; h++) {
		
		for(int c = 0; c < (height - lineLengthener); c++) output += " ";
		
		output += "*";
		for(int c = 0; c < characterLength; c++) {
			if (characterNumber >= text.length()) {
				characterNumber = 0;
			}
			output += text[characterNumber];
			characterNumber++;
		}
		output += "*\n";
		lineLengthener++;
		characterLength+=2;
	}
	
	for(int w = 0; w < (height * 2 + 3); w++) output += "*";
	output += "\n";
	
	cout << output;
	return output;
}


void fileOutput(string file, string shape) {
	ofstream outfile(file);
	if (!outfile.good()) {
		std::cerr << "Can't open " << file << " to write.\n";
		exit(1);
	}
	outfile << shape;
}




int main(int argc, char * argv[]) {
	
	// Stores command line arguements for use by the program.
	string text = argv[1];
	int height = atoi(argv[2]);
	string shape = argv[3];
	string file = argv[4];
	
	if (shape == "square") {
		fileOutput(file, square(text, height, file));
	}
	else if (shape == "right_triangle") {
		fileOutput(file, rightTriangle(text, height, file));
	}
	else if (shape == "isosceles_triangle") {
		fileOutput(file, isoscelesTriangle(text, height, file));
	}
	
	/*
	square(text, height, file);
	cout << "\n";
	rightTriangle(text, height, file);
	cout << "\n";
	isoscelesTriangle(text, height, file);
	*/

	
	return 0;
}