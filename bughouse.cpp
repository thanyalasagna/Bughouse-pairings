/*Thanya Nguyen 2 Dec 2023
This program creates pairings for chess games
that are read in from a file. I hope the next 
execboard is able to use this! :D

***Make sure all the input in the file look like this***
   Ex: Thanya Nguyen is 700 -> Thanya-Nguyen 700
*/
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/*returns to sort in descending order */
bool compareByRating(pair<string, int>& a, pair<string, int>& b) {
	return a.second > b.second; 
}

int main(int argc, char **argv) {
   printf("Welcome to BugHouse.cpp!\n");
	vector<pair<string, int>> people; //(name, rating)
	ifstream fin;
	string line, firstName;
	int rating, start, end;

	if (argc != 2) {
		cerr << "Usage: " << argv[0] << " <filename>\n";
		return 1;
	}

	fin.open(argv[1]);
	if (!fin.is_open()) {
		cerr << "Error opening file.\n";
		return 1;
	}

	while (getline(fin, line)) {
		istringstream ss(line);
		ss >> firstName >> rating;
		people.push_back(make_pair(firstName, rating));
	}

	sort(people.begin(), people.end(), compareByRating);  //sorts using compareByRating()

   //"pointers" used to point at the start and end
	start = 0;
	end = people.size() - 1;

   /*loops thru rating and prints accordingly*/
	cout << "\nCreating Pairings, The highest player is paired with the lowest player.\n";
	while (start < end) {
		printf("%-15s (%-2d)    -%15s (%4d)\n", 
				people[start].first.c_str(), people[start].second, 
				people[end].first.c_str(), people[end].second);
		++start;
		--end;
	}

	if (start == end) { //odd case
		cout << people[start].first << " (" << people[start].second << ") is left over\n";
	}


	return 0;
}
