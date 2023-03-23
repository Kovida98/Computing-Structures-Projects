// DSA 5005 - Computing Structures
// Fall 2022
// Project 3

#include <iostream>
#include <string>  // for the string fields
#include <vector>  // to store data
#include <fstream> // to read the csv file

using namespace std;

// class to store one row's information
class DFrow
{
protected:
	// all the fields to store information of a row
	string name;
	char sex;
	int age;
	int height;
	int weight;
	string city;

public:
	DFrow(); // default constructor
	DFrow(string n, char c, int one, int two, int three, string ci); // non-default constructor

	// TODO: write getters for each of the fields
	string getName();
	char getSex();
	int getAge();
	int getHeight();
	int getWeight();
	string getCity();

	// TODO: write setters for each of the fields
	void setName(string newName);
	void setSex(char newsex);
	void setAge(int newage);
	void setHeight(int newHeight);
	void setWeight(int newWeight);
	void setCity(string newCity);
	void display();
	~DFrow();
	// TODO: write display method to display all the fields in the same order
	// 			refer to output sample for exact format

	// TODO: write destructor
};
DFrow::DFrow() {
	name = "";
	sex = ' ';
	age = 0;
	height = 0;
	weight = 0;
	city = "";
}
DFrow::~DFrow() {
	name = "";
	sex = ' ';
	age = 0;
	height = 0;
	weight = 0;
	city = "";
}
DFrow::DFrow(string n, char c, int one, int two, int three, string ci) {
	name = n;
	sex = c;
	age = one;
	height = two;
	weight = three;
	city = ci;
}
string DFrow::getName() {

	return name;
}
char DFrow::getSex() {
	return sex;
}
int DFrow::getAge() {
	return age;
}
int DFrow::getHeight() {
	return height;
}
int DFrow::getWeight() {
	return weight;
}
string DFrow::getCity() {
	return city;
}
void DFrow::setName(string newName) {
	name = newName;
}
void DFrow::setSex(char newsex) {
	sex = newsex;
}
void DFrow::setAge(int newage) {
	age = newage;
}
void DFrow::setHeight(int newHeight) {
	height = newHeight;
}
void DFrow::setWeight(int newWeight) {
	weight = newWeight;
}
void DFrow::setCity(string newCity) {
	city = newCity;
}
class myNonExistingNameException {

};

// class to store the entire dataframe
class DataFrame
{
protected:
	vector<DFrow> data; // field storeing all the data
	vector<string> headers; // field to only the headers
	int nRows, nCols; // store the number of rows and cols

public:
	// Constructors
	DataFrame();
	DataFrame(int rows, int cols);

	// Overload the [] operator to access data in DF
	DFrow operator[](int i) {
		if (i < sizeof(data)) {
			return data[i];
		}
	}


	// File reading Method
	void readCSV(string filename, string headerPresence);

	// Output Method
	void display();

	// Search Record
	DFrow searchRecord(string name);

	// Setters
	void setColName(int col, char* name); // change the name of a header/column

	// Getters
	int getNumberRows();                                              // returns the number of rows
	int getNumberCols();                                              // returns the number of columns
	int getHeaderIndex(string name);
	//DataFrame* getColumns(int* columns, int cLen);                    // returns a dataframe with a set of cLen number of columns
	DataFrame* getRows(int* rows, int rLen);                          // returns a data frame with a set of rLen number of rows
	//DataFrame* getRowsCols(int* rows, int rLen, int* cols, int cLen); // returns a data frame given a set of row numbers and column numbers
	string getHeader(int i);                                          // returns the header name given a index position
	
	// Find info of a given column

	double findAverage(int colNumber); // returns the average of the given column
	double findMax(int colNumber);     // returns the max of the given column
	double findMin(int colNumber);     // returns the min of the given column
	double frequency(int colNumber);   // displays the frequency of the unique values


	// Destructor
	~DataFrame();
};

DataFrame::DataFrame() {
	nRows = 0;
	nCols = 0;
	//vector<DFrow> data(nRows);
	//vector<DFrow> headers(nCols);
}
DataFrame::DataFrame(int rows, int cols) {
	nRows = rows;
	nCols = cols;
	//vector<DFrow> data(nRows);
	//vector<DFrow> headers(nCols);
}
DataFrame::~DataFrame() {
	nRows = 0;
	nCols = 0;
	//vector<DFrow> data(0);
	//vector<DFrow> headers(0);
}
void DataFrame::readCSV(string filename, string headerPresence) {
	/*
	//ifstream mycsv(filename);
	string l;
	string x;
	vector<string> tempvector;
	ifstream mycsv;
	mycsv.open(filename);
	while (!mycsv.eof()) {
		mycsv >> l;
		cout << l << " " << endl;
		for (auto i : l+",") {
			if (i == ',') {
				cout << x << endl;
				tempvector.push_back(x);
				if (sizeof(tempvector) == 6) {
					DFrow temp;
					temp.setName(tempvector[0]);
					temp.setSex(tempvector[1][0]);
					temp.setAge(stoi(tempvector[2]));
					temp.setHeight(stoi(tempvector[3]));
					temp.setWeight(stoi(tempvector[4]));
					temp.setCity(tempvector[5]);
					data.push_back(temp);
					vector<string> tempvector(0);

				}
				x = "";
			}
			else {
				x = x + i;
				//cout << x << endl;
			}
		}
		//cout << x << endl;
		//data.push_back(l);
	}
	*/
	ifstream mycsv;
	mycsv.open(filename);
	int count = 0;
	string line,x,b;
	vector<string> tempvector;
	while ((getline(mycsv, line)) && count < nRows+1) {
		//cout << "\n " << y;
		tempvector.push_back(line+",");
		count++;
	}
	/*
	for (int i = 0; i < nRows+1; i++) {
		cout << tempvector[i] << endl;
	}
	*/
	int size_of_row = tempvector[0].size();
	//cout << size_of_row << endl;
	if (headerPresence == "true") {
		for (int i = 0; i < size_of_row; i++) {
			if (tempvector[0][i] == ',') {
				//cout << x << endl;
				headers.push_back(x);
				x = "";
			}
			else {
				x = x + tempvector[0][i];
			}

		}
		tempvector.erase(tempvector.begin());

	}
	vector<string> tempvector1;
	int size_of_vector = tempvector.size();
	for (int i = 0; i < size_of_vector; i++) {
		int s = tempvector[i].size();
		for (int j = 0; j < s; j++) {
			if (tempvector[i][j] == ',') {
				//cout << b << endl;
				tempvector1.push_back(b);
				//cout << " before if tempvector1 size " << tempvector1.size() << endl;
				if (tempvector1.size() == nCols) {
					//cout << "after if " << tempvector1.size() << endl;
					DFrow temp;
					temp.setName(tempvector1[0]);
					temp.setSex(tempvector1[1][0]);
					temp.setAge(stoi(tempvector1[2]));
					temp.setHeight(stoi(tempvector1[3]));
					temp.setWeight(stoi(tempvector1[4]));
					temp.setCity(tempvector1[5]);
					data.push_back(temp);
					tempvector1.clear();
					//cout << "after setting " << tempvector1.size() << endl;
				}
				b = "";
			}
			else {
				b = b + tempvector[i][j];
			}
		}
	}

}

DFrow DataFrame::searchRecord(string name) {

	//cout << "inside function" << endl;
	int track = 0;
	for (int i = 0; i < nRows; i++) {
		//cout << "inside for" << endl;
		if (data[i].getName() == name) {
			//cout << "inside if" << endl;
			cout << "found the person" << endl;
			cout << data[i].getName() << " , " << data[i].getSex() << " , " << data[i].getAge() << " , " << data[i].getHeight() << " , " << data[i].getWeight() << " , " << data[i].getCity() << endl;
			track++;
			//cout << endl;
			return data[i];
		}
	}
	try
	{
		if (track == 0) {
			throw myNonExistingNameException();
		}
	}
	catch (myNonExistingNameException myException)
	{
		cout << name << " is not present in the Dataframe" << endl;
	}
}
void DataFrame::setColName(int col, char* name) {
	//col = 2;
	headers.at(col) = name;
	/*
	for (int i = 0; i < nCols; i++) {
		cout << headers[i] << endl;
	}*/
}
int DataFrame::getNumberRows() {
	return data.size();
	//return nRows;
}
int DataFrame::getNumberCols() {
	return nCols;
}
string DataFrame::getHeader(int i) {
	return headers[i];
}
int DataFrame::getHeaderIndex(string name) {
	for (int i = 0; i < nCols; i++) {
		if (headers[i] == name) {
			return i;
		}
	}
}
/*
DataFrame* DataFrame::getRows(int* rows, int rLen) {
	vector<DFrow> DFvector;
	for (int i = *rows - 1; i <= rLen; i++) {
		DFvector.push_back(data[i]);
	}
	return DFvector;
}*/
/*
void DataFrame::display() {
	if (!headers.empty()) {
		cout << "Displaying all the records: " << endl;
		for (int i = 0; i < nCols; i++) {
			cout << headers[i] << " ";
		}
		cout << endl;
		for (int i = 0; i < nRows; i++) {
			cout << data[i].getName() << " " << data[i].getSex() << " " << data[i].getAge() << " " << data[i].getHeight() << " " << data[i].getWeight() << " " << data[i].getCity() << endl;
		}
	}
	else {
		cout << "Displaying all the records: " << endl;
		for (int i = 0; i < nRows; i++) {
			cout << data[i].getName() << " " << data[i].getSex() << " " << data[i].getAge() << " " << data[i].getHeight() << " " << data[i].getWeight() << " " << data[i].getCity() << endl;
		}

	}
}

double DataFrame::findAverage(int colNumber) {
	vector<int> avgtempvector_age;
	vector<int> avgtempvector_height;
	vector<int> avgtempvector_weight;
	double avg1=0;
	double sum=0;
	if (colNumber == 2) {
		for (int i = 0; i < nRows; i++) {
			avgtempvector_age.push_back(data[i].getAge());
			
		}
		//cout << "size: " << avgtempvector_age.size() << endl;
		for (int i = 0; i < nRows; i++) {
			sum = sum + data[i].getAge();
			//cout << "sum: " << sum << endl;
		}
		avg1 = sum / nRows;
		cout << "Average of the " << headers[colNumber] << " is " << avg1 << endl;
		sum = 0;
		
	}
	else if (colNumber == 3) {
		for (int i = 0; i < nRows; i++) {
			avgtempvector_height.push_back(data[i].getHeight());
			
		}
		for (int i = 0; i < nRows; i++) {
			sum = sum + data[i].getHeight();
		}
		avg1 = sum / nRows;
		cout << "Average of the " << headers[colNumber] << " is " << avg1 << endl;
		sum = 0;
	}
	else if (colNumber == 4) {
		for (int i = 0; i < nRows; i++) {
			avgtempvector_weight.push_back(data[i].getWeight());

		}
		for (int i = 0; i < nRows; i++) {
			sum = sum + data[i].getWeight();
		}
		avg1 = sum / nRows;
		cout << "Average of the " << headers[colNumber] << " is " << avg1 << endl;
		sum = 0;
	}
	else {
		cout << "Average of " << headers[colNumber] << " cannot be found " << endl;
	}
	return avg1;
}*/
/*
double DataFrame::findMax(int colNumber) {
	int location;
	double maximum;
	if (colNumber == 2) {
		maximum = data[0].getAge();
		for (int c = 1; c < nRows; c++) {
			if (data[c].getAge() > maximum) {
				maximum = data[c].getAge();
				location = c + 1;
			}
		}
	}
	else if (colNumber == 3) {
		maximum = data[0].getHeight();
		for (int c = 1; c < nRows; c++) {
			if (data[c].getHeight() > maximum) {
				maximum = data[c].getHeight();
				location = c + 1;
			}
		}
	}
	else if (colNumber == 4) {
		maximum = data[0].getWeight();
		for (int c = 1; c < nRows; c++) {
			if (data[c].getWeight() > maximum) {
				maximum = data[c].getWeight();
				location = c + 1;
			}
		}
	}
	//cout << endl;
	return maximum;


}
double DataFrame::findMin(int colNumber) {
	int location;
	double minimum;
	if (colNumber == 2) {
		minimum = data[0].getAge();
		for (int c = 1; c < nRows; c++) {
			if (data[c].getAge() < minimum) {
				minimum = data[c].getAge();
				location = c + 1;
			}
		}
	}
	else if (colNumber == 3) {
		minimum = data[0].getHeight();
		for (int c = 1; c < nRows; c++) {
			if (data[c].getHeight() < minimum) {
				minimum = data[c].getHeight();
				location = c + 1;
			}
		}
	}
	else if (colNumber == 4) {
		minimum = data[0].getWeight();
		for (int c = 1; c < nRows; c++) {
			if (data[c].getWeight() < minimum) {
				minimum = data[c].getWeight();
				location = c + 1;
			}
		}
	}
	//cout << endl;
	return minimum;

}*/
/*
double DataFrame::frequency(int colNumber) {
	vector<int> freq;
	int visited = -1;
	vector<char> tempvector_sex;
	if (colNumber == 1) {
		cout << "inside if " << endl;
		for (int i = 0; i < nRows; i++) {
			cout << data[i].getSex();
			tempvector_sex.push_back(data[i].getSex());
		}
		for (int i = 0; i < nRows; i++) {
			int count = 1;
			for (int j = i + 1; j < nRows; j++) {
				if (tempvector_sex[i] == tempvector_sex[j]) {
					count++;
					freq[j] = visited;
				}
			}
			if (freq[i] != visited) {
				freq[i] = count;
			}
		}
		for (int i = 0; i < nRows; i++) {
			if (freq[i] != visited) {
				cout << tempvector_sex[i] << " - " << freq[i] << endl;
			}
		}
	}
	return 0;
}*/

// main function
int main()
{
	int numRows, numCols;
	string fileName;
	string headerBool;
	string name;
	char command;

	cin >> numRows >> numCols >> headerBool >> fileName;
	cout << numRows << numCols << headerBool << fileName << endl;

	DataFrame* d = new DataFrame(numRows, numCols);

	d->readCSV(fileName, headerBool); // use this method to read in the data from the csv file
	//d->setColName(2, );

	// TODO: read the commands from the input file (redirected input)
	cin >> command;
	while (!cin.eof()) {
		switch (command) {
		case 'F': {
			cin >> name;
			cout << name << endl;
			d->searchRecord(name);
			break;
		}
		case 'X': {
			cin >> name;
			//cout << name << endl;
			int ind =d->getHeaderIndex(name);
			//double maximum=d->findMax(ind);
			//cout << "maximum value of the " << name << " is " << maximum << endl;
			break;

		}
		case 'I': {
			cin >> name;
			int ind = d->getHeaderIndex(name);
			//double minimum = d->findMin(ind);
			//cout << "minimum value of the " << name << " is " << minimum << endl;
			//cout << "Datatype: " << typeid(int).name() << endl;
			break;
		}
		case 'A': {
			cin >> name;
			int ind = d->getHeaderIndex(name);
			//double average = d->findAverage(ind);
			//cout << "Average of the " << name << " is " << average << endl;
			break;
		}
		case 'D': {
			//d->display();
			break;
		}
		case 'Q': {
			cin >> name;
			cout << name << endl;
			int ind = d->getHeaderIndex(name);
			cout << ind << endl;
			//d->frequency(ind);
			break;
		}

		default: cout << "Holy Cow!!" << endl;
		}
		cin >> command;
	}

	return 0;
}
