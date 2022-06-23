#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdio>
#include <iomanip>
using namespace std;

//Yavuz U�arku� 152120171006

vector<float> PullAvgNum(ifstream& file) {

	char ch[512];
	vector<float> avgNotes;
	float sum = 0;
	float i = 0;
	float c = 1;


	while (file >> ch) {
		if (atof(ch) == -999) {
			avgNotes.push_back((sum) / (i - c));
			sum = 999;
			i = 0;
			c = 2;
		}
		sum += atof((ch));

		i++;
	}
	//for (int i = 0; i < avgNotes.size(); i++) {
	//	cout << avgNotes[i] << " ";
	//}
	return avgNotes;
}

vector<string> getLessonsID(ifstream& file) {

	vector<string> lesson;
	string t;
	string k;
	file >> k;
	lesson.push_back(k);
	while (getline(file, t)) {
		file >> k;
		lesson.push_back(k);
	}
	return lesson;
}

int main() {




	ofstream result("student.txt");


	cout << "\t\t     Bar  Graph" << endl;
	result << "\t\t     Bar  Graph" << endl;
	cout << "  Course   Course ";
	result << "  Course   Course ";

	for (int i = 0; i <= 10; i++) {

		cout << "   " << i * 10;
		result << "   " << i * 10;

	}
	cout << endl << "  ID       Average   ";
	result << endl << "  ID       Average   ";

	for (int i = 0; i <= 50; i++) {
		if (i % 5 == 0) {
			cout << "|";
			result << "|";

		}
		else {
			cout << ".";
			result << ".";
		}

	}
	cout << endl << "  ";
	result << endl << "  ";


	ifstream Ids("group1.TXT");
	ifstream group1("group1.TXT");
	ifstream group2("group2.TXT");
	ifstream test("test.txt");
	int sum = 0;

	vector<string> Id = getLessonsID(Ids);
	vector<float> group1Avg = PullAvgNum(group1);
	vector<float> group2Avg = PullAvgNum(group2);



	cout.precision(3);
	for (int i = 0; i < Id.size() - 1; i++) {
		cout << Id[i] << "      ";
		result << Id[i] << "      ";

		cout << fixed << setprecision(2) << group1Avg[i];
		result << fixed << setprecision(2) << group1Avg[i];
		cout << "     ";
		result << "     ";

		for (int x = 0; x < group1Avg[i] / 2; x++) {
			cout << "*";
			result << "*";
		}
		cout << endl << "           ";
		result << endl << "           ";

		cout << fixed << setprecision(2) << group2Avg[i];
		result << fixed << setprecision(2) << group2Avg[i];
		cout << "     ";
		result << "     ";
		for (int x = 0; x < group2Avg[i] / 2; x++) {
			cout << "#";
			result << "#";
		}
		cout << endl << endl << "  ";
		result << endl << endl << "  ";
	}

	cout << endl << "Group 1 -- ****" << endl << "Group 2 -- ####" << endl;
	result << endl << "Group 1 -- ****" << endl << "Group 2 -- ####" << endl;
	float sumOfAllg1 = 0;
	float sumOfAllg2 = 0;
	for (int i = 0; i < group1Avg.size(); i++) {
		sumOfAllg1 += group1Avg[i];
		sumOfAllg2 += group2Avg[i];
	}
	float avg1 = sumOfAllg1 / group1Avg.size();
	float avg2 = sumOfAllg2 / group1Avg.size();

	cout << "Avg for group 1: " << fixed << setprecision(2) << avg1 << endl;
	result << "Avg for group 1: " << fixed << setprecision(2) << avg1 << endl;
	cout << "Avg for group 2: " << fixed << setprecision(2) << avg2 << endl;
	result << "Avg for group 2: " << fixed << setprecision(2) << avg2 << endl;

}
