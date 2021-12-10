#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <sstream>
#include <filesystem>
using namespace std;

struct PIndex {
	int offset;
	char ID[13];
};
struct PIndexD {
	int offset;
	char ID[30];
};

struct SecIndex
{
	char depID[30];
	int pointer;
};
struct SecIndexD
{
	char name[50];
	int pointer;
};
struct node {
	char id[30];
	short next;
};

void swap(PIndex* a, PIndex* b)
{
	PIndex t = *a;
	*a = *b;
	*b = t;
}
void swap(PIndexD* a, PIndexD* b)
{
	//overload swap for department
	PIndexD t = *a;
	*a = *b;
	*b = t;
}
void swapS(SecIndex* a, SecIndex* b)
{
	//swap in employee second index
	SecIndex t = *a;
	*a = *b;
	*b = t;
}
void swapS_D(SecIndexD* a, SecIndexD* b)
{
	//swap in Department second index
	SecIndexD t = *a;
	*a = *b;
	*b = t;
}

int partition(PIndex arr[], int low, int high)
{
	int pivot = atoi(arr[high].ID);    // pivot
	int i = (low - 1);  // Index of smaller element

	for (int j = low; j <= high - 1; j++)
	{
		// If current element is smaller than or
		// equal to pivot
		if (atoi(arr[j].ID) <= pivot)
		{
			i++;    // increment index of smaller element
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}
int partition(PIndexD arr[], int low, int high)
{
	//overload partition for department
	int pivot = atoi(arr[high].ID);    // pivot
	int i = (low - 1);  // Index of smaller element

	for (int j = low; j <= high - 1; j++)
	{
		// If current element is smaller than or
		// equal to pivot
		if (atoi(arr[j].ID) <= pivot)
		{
			i++;    // increment index of smaller element
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}
int partitionS(SecIndex arr[], int low, int high)
{
	//partition in Employee second Index
	int pivot = atoi(arr[high].depID);
	int i = (low - 1);  // Index of smaller element

	for (int j = low; j <= high - 1; j++)
	{
		// If current element is smaller than or
		// equal to pivot
		if (atoi(arr[j].depID) <= pivot)
		{
			i++;    // increment index of smaller element
			swapS(&arr[i], &arr[j]);
		}
	}
	swapS(&arr[i + 1], &arr[high]);
	return (i + 1);
}
int partitionS_D(SecIndexD arr[], int low, int high)
{
	//partition in Department second Index
	char pivot[50];
	strcpy_s(pivot, arr[high].name);
	int i = (low - 1);  // Index of smaller element

	for (int j = low; j <= high - 1; j++)
	{
		// If current element is smaller than or
		// equal to pivot

		if (strcmp(arr[j].name, pivot) <= 0)
		{
			i++;    // increment index of smaller element
			swapS_D(&arr[i], &arr[j]);
		}
	}
	swapS_D(&arr[i + 1], &arr[high]);
	return (i + 1);
}

void quickSort(PIndex arr[], int low, int high)
{
	if (low < high)
	{
		/* pi is partitioning index, arr[p] is now
		at right place */
		int pi = partition(arr, low, high);

		// Separately sort elements before
		// partition and after partition
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}
void quickSort(PIndexD arr[], int low, int high)
{
	//overload quick sort for Department
	if (low < high)
	{
		/* pi is partitioning index, arr[p] is now
		at right place */
		int pi = partition(arr, low, high);

		// Separately sort elements before
		// partition and after partition
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}
void quickSortS(SecIndex arr[], int low, int high)
{
	//qick sort in employee second index
	if (low < high)
	{
		/* pi is partitioning index, arr[p] is now
		at right place */
		int pi = partitionS(arr, low, high);

		// Separately sort elements before
		// partition and after partition
		quickSortS(arr, low, pi - 1);
		quickSortS(arr, pi + 1, high);
	}
}
void quickSortS_D(SecIndexD arr[], int low, int high)
{
	//qick sort in department second index
	if (low < high)
	{
		/* pi is partitioning index, arr[p] is now
		at right place */
		int pi = partitionS_D(arr, low, high);

		// Separately sort elements before
		// partition and after partition
		quickSortS_D(arr, low, pi - 1);
		quickSortS_D(arr, pi + 1, high);
	}
}

int indexBinarySearch(PIndex arr[], int p, int r, char* num) {
	// binary search in Primary index 
	if (p <= r) {
		int mid = (p + r) / 2;
		if (atoi(arr[mid].ID) == atoi(num))
			return mid;
		if (atoi(arr[mid].ID) > atoi(num))
			return indexBinarySearch(arr, p, mid - 1, num);
		if (atoi(arr[mid].ID) < atoi(num))
			return indexBinarySearch(arr, mid + 1, r, num);
	}
	return -1;
}
int indexBinarySearch(PIndexD arr[], int p, int r, char* num) {
	//overload for department
	// binary search in Primary index
	if (p <= r) {
		int mid = (p + r) / 2;
		if (atoi(arr[mid].ID) == atoi(num))
			return mid;
		if (atoi(arr[mid].ID) > atoi(num))
			return indexBinarySearch(arr, p, mid - 1, num);
		if (atoi(arr[mid].ID) < atoi(num))
			return indexBinarySearch(arr, mid + 1, r, num);
	}
	return -1;
}
int indexBinarySearchS(SecIndex arr[], int p, int r, char* depID) {
	// binary search in secondry index in employee by dep_id
	if (p <= r) {
		int mid = (p + r) / 2;
		if (atoi(arr[mid].depID) == atoi(depID))
			return mid;
		if (atoi(arr[mid].depID) > atoi(depID))
			return indexBinarySearchS(arr, p, mid - 1, depID);
		if (atoi(arr[mid].depID) < atoi(depID))
			return indexBinarySearchS(arr, mid + 1, r, depID);
	}
	return -1;
}
int indexBinarySearchS_D(SecIndexD arr[], int p, int r, char* name) {
	//binary search in secondry index in department search by name
	if (p <= r) {
		int mid = (p + r) / 2;
		if (strcmp(arr[mid].name, name) == 0)
			return mid;
		if (strcmp(arr[mid].name, name) > 0)
			return indexBinarySearchS_D(arr, p, mid - 1, name);
		if (strcmp(arr[mid].name, name) < 0)
			return indexBinarySearchS_D(arr, mid + 1, r, name);
	}
	return -1;
}
class employee {
	const static int PIndexESize = 100;
	SecIndex SIndex[PIndexESize];
	node linkedList[PIndexESize];
	PIndex index[PIndexESize];
	int PIndexCounter = 0;
	int SIndexCounter = 0;
	int linkPtr = 0;
	char employeeID[13];
	char deptID[30];
	char employeeName[50];
	char employeePosition[50];
	string dataFilePath = "employees.txt";
	string pIndexFilePath = "empIndex.txt";
	string sIndexFilePath = "emp_sIndex.txt";
	string sIndexLinkFilePath = "empLinkedList.txt";
public:
	
	void writeEmployee() {
			//enter data of employee by user
			employee temp = enterData();
			ofstream outfile;
			outfile.open(dataFilePath, ios::app | ios::out | ios::binary);
			//******************************
			const int maxSize = 147;
			char buffer[maxSize];
			char id[13];
			char depID[30];
			strcpy_s(depID, temp.deptID);
			strcpy_s(id, temp.employeeID);
			//set deliameters
			temp = setDelemitars(temp);
			strcpy_s(buffer, temp.employeeID);
			strcat_s(buffer, temp.deptID);
			strcat_s(buffer, temp.employeeName);
			strcat_s(buffer, temp.employeePosition);
			//*****************************
			int len = strlen(buffer);
			outfile.seekp(0, ios::end);
			int address = outfile.tellp();
	
			//write new employee in employee file
			outfile.write((char*)&len, sizeof(len));
			outfile.write(buffer, len);
	
			writePIndex(id, address);//add new index to primary index
			writeSecIndex(depID, id);
			outfile.close();
	
		}
	employee enterData() {
		employee temp;
		cout << "Enter Employee ID: " << endl;
		cin.getline(temp.employeeID, 13);
		cout << "Enter Employee Department ID: " << endl;
		cin.getline(temp.deptID, 30);
		cout << "Enter Employee Name: " << endl;
		cin.getline(temp.employeeName, 50);
		cout << "Enter Employee Position: " << endl;
		cin.getline(temp.employeePosition, 50);
		return temp;
	}
	employee setDelemitars(employee &temp) {
		strcat_s(temp.employeeID, "|");
		strcat_s(temp.deptID, "|");
		strcat_s(temp.employeeName, "|");
		strcat_s(temp.employeePosition, "|");
		return temp;
	}
	void writeSecIndex(char *depID, char*id) {
		int found;
		if (SIndexCounter >= 1)
			found = indexBinarySearchS(SIndex, 0, SIndexCounter - 1, depID);
		else found = -1;
		if (found == -1) {
			//new index in linked list
			strcpy_s(linkedList[linkPtr].id, id);
			linkedList[linkPtr].next = -1;
		
			//new index in secIndex 
			strcpy_s(SIndex[SIndexCounter].depID, depID);
			SIndex[SIndexCounter].pointer = linkPtr;
			quickSortS(SIndex, 0, SIndexCounter);//sort SIndex
			linkPtr++;
			SIndexCounter++;
		}
		else {
			//edit pointer of element are found in secIndex
			linkedList[linkPtr].next = SIndex[found].pointer;
			SIndex[found].pointer = linkPtr;
			//new index in linked list
			strcpy_s(linkedList[linkPtr].id, id);
		
			linkPtr++;
		}
		
		
	}
	void writePIndex(char* id, int address) {
		strcpy_s(index[PIndexCounter].ID, id);
		index[PIndexCounter].offset = address;
		quickSort(index, 0, PIndexCounter);//sort primary index in ID
		PIndexCounter++;
	}
	void readEmployeeByID(char* id) {
		
		ifstream outfile;
		outfile.open(dataFilePath, ios::binary | ios::in);
		
		int address = indexBinarySearch(index, 0, PIndexCounter, id);
		if (address == -1)
		{
			cout << "\nthis Employee not exists";
			return;
		}
		int len;
		employee e;
		outfile.seekg(index[address].offset, ios::beg);
		outfile.read((char*)&len, sizeof(len));
		char *buffer = new char[len];
		outfile.read(buffer, len);
		
		istringstream stream(buffer);
		stream.getline(e.employeeID, 13, '|');
		stream.getline(e.deptID, 30, '|');
		stream.getline(e.employeeName, 50, '|');
		stream.getline(e.employeePosition, 50, '|');
		printEmployee(e);
		outfile.close();
		delete buffer;
	}
	void readEmployeeByDepID() {
		char depID[30];
		cout << "enter Department id :";
		cin >> depID;
		
		ifstream outfile;
		outfile.open(dataFilePath, ios::binary | ios::in);
		
		int address = indexBinarySearchS(SIndex, 0, SIndexCounter, depID);
		if (address == -1)
		{
			cout << "\nthis Employee not exists";
			return;
		}
		
		int pointer = SIndex[address].pointer;
		int next = linkedList[pointer].next;
		readEmployeeByID(linkedList[pointer].id);
		while (next != -1) {
		
			readEmployeeByID(linkedList[next].id);
			next = linkedList[next].next;
		}
	}
		
	void printEmployee(employee &e) {
		cout << "Employee ID : " << e.employeeID << endl;
		cout << "Employee DepID : " << e.deptID << endl;
		cout << "Employee Name : " << e.employeeName << endl;
		cout << "Employee Pos : " << e.employeePosition << endl;
	}
		
	void loadPIndex() {
		
		ifstream PIfile(pIndexFilePath);
		/*
		PIfile.open(indexFilePath, ios::binary | ios::in);
		PIfile.seekg(0, ios::beg);
		*/
		PIndexCounter = 0;
		while (true)
		{
		
			PIndex temp;
			PIfile.read((char*)&temp, sizeof(temp));
			if (PIfile.eof())
				break;
			index[PIndexCounter] = temp;
			PIndexCounter++;
		}
		cout << "n" << PIndexCounter;
		for (int i = 0; i < PIndexCounter - 1; i++) {
			cout << index[i].ID << "/" << index[i].offset << endl;
		}
		PIfile.close();
	}
	void savePIndex() {
		ofstream PIfile(pIndexFilePath, ios::trunc);
		for (int i = 0; i < PIndexCounter; i++)
		{
			PIndex temp = index[i];
			PIfile.write((char*)&temp, sizeof(temp)); //fixed len record, fixed len field
		}
		PIfile.close();
	}
		
	void loadSIndex() {
		
		ifstream SIfile(sIndexFilePath);
		SIndexCounter = 0;
		while (true)
		{
		
			SecIndex temp;
			SIfile.read((char*)&temp, sizeof(temp));
			if (SIfile.eof())
				break;
			SIndex[SIndexCounter] = temp;
			SIndexCounter++;
		}
		for (int i = 0; i < SIndexCounter; i++) {
			cout << "Sec index\n";
			cout << SIndex[i].depID << "/" << SIndex[i].pointer << endl;
		}
		SIfile.close();
	}
	void saveSIndex() {
		for (int i = 0; i < SIndexCounter - 1; i++) {
			cout << "Sec index\n";
			cout << SIndex[i].depID << "/" << SIndex[i].pointer << endl;
		}
		ofstream SIfile(sIndexFilePath, ios::trunc);
		for (int i = 0; i < SIndexCounter; i++)
		{
			SecIndex temp = SIndex[i];
			SIfile.write((char*)&temp, sizeof(temp)); //fixed len record, fixed len field
		}
		SIfile.close();
	}
		
	void loadSLIndex() {
		
		ifstream Lfile(sIndexLinkFilePath);
		linkPtr = 0;
		while (true)
		{
		
			node temp;
			Lfile.read((char*)&temp, sizeof(temp));
			if (Lfile.eof())
				break;
			linkedList[linkPtr] = temp;
			linkPtr++;
		}
		for (int i = 0; i < linkPtr; i++) {
			cout << "Sec link index\n";
			cout << linkedList[i].id << "/" << linkedList[i].next << endl;
		}
		
		Lfile.close();
	}
	void saveSLIndex() {
		for (int i = 0; i < linkPtr - 1; i++) {
			cout << "Sec link index\n";
			cout << linkedList[i].id << "/" << linkedList[i].next << endl;
		}
		ofstream Lfile(sIndexLinkFilePath, ios::trunc);
		for (int i = 0; i < linkPtr; i++)
		{
			node temp = linkedList[i];
			Lfile.write((char*)&temp, sizeof(temp)); //fixed len record, fixed len field
		}
		Lfile.close();
	}

};
class department {
	
	const static int PIndexESize = 100;
	SecIndexD SIndex[PIndexESize];
	node linkedList[PIndexESize];
	PIndexD index[PIndexESize];
	int PIndexCounter = 0;
	int SIndexCounter = 0;
	int linkPtr = 0;
	int next=0;
	char departID[30];
	char departName[50];
	char departManger[50];
	string dataFilePath = "departments.txt";
	string pIndexFilePath = "depIndex.txt";
	string sIndexFilePath = "dep_sIndex.txt";
	string sIndexLinkFilePath = "depLinkedList.txt";
public:

	void writeDepartment() {
		//enter data of employee by user
		department temp = enterData();
		ofstream outfile;
		outfile.open(dataFilePath, ios::app | ios::out | ios::binary);
		//******************************
		const int maxSize = 133;
		char buffer[maxSize];
		char id[30];
		char name[50];
		strcpy_s(id, temp.departID);
		strcpy_s(name, temp.departName);
		//set deliameters
		temp = setDelemitars(temp);
		strcpy_s(buffer, temp.departID);
		strcat_s(buffer, temp.departName);
		strcat_s(buffer, temp.departManger);
		//*****************************
		int len = strlen(buffer);
		outfile.seekp(0, ios::end);
		int address = outfile.tellp();

		//write new employee in employee file
		outfile.write((char*)&len, sizeof(len));
		outfile.write(buffer, len);

		writePIndex(id, address);//add new index to primary index
		writeSecIndex(name, id);
		outfile.close();

	}
	department enterData() {
		department temp;
		cout << "Enter Department ID: " << endl;
		cin.getline(temp.departID, 30);
		cout << "Enter Department Name: " << endl;
		cin.getline(temp.departName, 50);
		cout << "Enter Department Manger: " << endl;
		cin.getline(temp.departManger, 50);
		return temp;
	}
	department setDelemitars(department &temp) {
		strcat_s(temp.departID, "|");
		strcat_s(temp.departName, "|");
		strcat_s(temp.departManger, "|");
		return temp;
	}
	void writeSecIndex(char *name, char*id) {
		int found;
		if (SIndexCounter >= 1)
			found = indexBinarySearchS_D(SIndex, 0, SIndexCounter - 1, name);
		else found = -1;
		if (found == -1) {
			//new index in linked list
			strcpy_s(linkedList[linkPtr].id, id);
			linkedList[linkPtr].next = -1;

			//new index in secIndex 
			strcpy_s(SIndex[SIndexCounter].name, name);
			SIndex[SIndexCounter].pointer = linkPtr;
			quickSortS_D(SIndex, 0, SIndexCounter);//sort SIndex
			linkPtr++;
			SIndexCounter++;
		}
		else {
			//edit pointer of element are found in secIndex
			linkedList[linkPtr].next = SIndex[found].pointer;
			SIndex[found].pointer = linkPtr;
			//new index in linked list
			strcpy_s(linkedList[linkPtr].id, id);

			linkPtr++;
		}


	}
	void writePIndex(char* id, int address) {
		strcpy_s(index[PIndexCounter].ID, id);
		index[PIndexCounter].offset = address;
		quickSort(index, 0, PIndexCounter);//sort primary index in ID
		PIndexCounter++;
	}
	void readDepartmentByID(char* id) {

		ifstream outfile;
		outfile.open(dataFilePath, ios::binary | ios::in);

		int address = indexBinarySearch(index, 0, PIndexCounter, id);
		if (address == -1)
		{
			cout << "\nthis Employee not exists";
			return;
		}
		int len;
		department d;
		outfile.seekg(index[address].offset, ios::beg);
		outfile.read((char*)&len, sizeof(len));
		char *buffer = new char[len];
		outfile.read(buffer, len);

		istringstream stream(buffer);
		stream.getline(d.departID, 30, '|');
		stream.getline(d.departName, 50, '|');
		stream.getline(d.departManger, 50, '|');
		printDepartment(d);
		outfile.close();
		delete buffer;
	}
	void readDepartmentByName() {
		char name[50];
		cout << "enter Department Name :";
		cin >> name;

		ifstream outfile;
		outfile.open(dataFilePath, ios::binary | ios::in);

		int address = indexBinarySearchS_D(SIndex, 0, SIndexCounter, name);
		if (address == -1)
		{
			cout << "\nthis Employee not exists";
			return;
		}

		int pointer = SIndex[address].pointer;
		int next = linkedList[pointer].next;
		readDepartmentByID(linkedList[pointer].id);
		while (next != -1) {

			readDepartmentByID(linkedList[next].id);
			next = linkedList[next].next;
		}
	}

	void printDepartment(department &d) {
		cout << "Department ID : " << d.departID << endl;
		cout << "Department Name : " << d.departName << endl;
		cout << "Department Manger : " << d.departManger << endl;
	}

	void loadPIndex() {

		ifstream PIfile(pIndexFilePath);
		/*
		PIfile.open(indexFilePath, ios::binary | ios::in);
		PIfile.seekg(0, ios::beg);
		*/
		PIndexCounter = 0;
		while (true)
		{

			PIndexD temp;
			PIfile.read((char*)&temp, sizeof(temp));
			if (PIfile.eof())
				break;
			index[PIndexCounter] = temp;
			PIndexCounter++;
		}
		cout << "n" << PIndexCounter;
		for (int i = 0; i < PIndexCounter - 1; i++) {
			cout << index[i].ID << "/" << index[i].offset << endl;
		}
		PIfile.close();
	}
	void savePIndex() {
		ofstream PIfile(pIndexFilePath, ios::trunc);
		for (int i = 0; i < PIndexCounter; i++)
		{
			PIndexD temp = index[i];
			PIfile.write((char*)&temp, sizeof(temp)); //fixed len record, fixed len field
		}
		PIfile.close();
	}

	void loadSIndex() {

		ifstream SIfile(sIndexFilePath);
		SIndexCounter = 0;
		while (true)
		{

			SecIndexD temp;
			SIfile.read((char*)&temp, sizeof(temp));
			if (SIfile.eof())
				break;
			SIndex[SIndexCounter] = temp;
			SIndexCounter++;
		}
		for (int i = 0; i < SIndexCounter; i++) {
			cout << "Sec index\n";
			cout << SIndex[i].name << "/" << SIndex[i].pointer << endl;
		}
		SIfile.close();
	}
	void saveSIndex() {
		for (int i = 0; i < SIndexCounter - 1; i++) {
			cout << "Sec index\n";
			cout << SIndex[i].name << "/" << SIndex[i].pointer << endl;
		}
		ofstream SIfile(sIndexFilePath, ios::trunc);
		for (int i = 0; i < SIndexCounter; i++)
		{
			SecIndexD temp = SIndex[i];
			SIfile.write((char*)&temp, sizeof(temp)); //fixed len record, fixed len field
		}
		SIfile.close();
	}

	void loadSLIndex() {

		ifstream Lfile(sIndexLinkFilePath);
		linkPtr = 0;
		while (true)
		{

			node temp;
			Lfile.read((char*)&temp, sizeof(temp));
			if (Lfile.eof())
				break;
			linkedList[linkPtr] = temp;
			linkPtr++;
		}
		for (int i = 0; i < linkPtr; i++) {
			cout << "Sec link index\n";
			cout << linkedList[i].id << "/" << linkedList[i].next << endl;
		}

		Lfile.close();
	}
	void saveSLIndex() {
		for (int i = 0; i < linkPtr - 1; i++) {
			cout << "Sec link index\n";
			cout << linkedList[i].id << "/" << linkedList[i].next << endl;
		}
		ofstream Lfile(sIndexLinkFilePath, ios::trunc);
		for (int i = 0; i < linkPtr; i++)
		{
			node temp = linkedList[i];
			Lfile.write((char*)&temp, sizeof(temp)); //fixed len record, fixed len field
		}
		Lfile.close();
	}
};


void main() {

	
	department e;
	char id[50];

	/*for (int i = 0; i < 4; i++) {
		e.writeDepartment();
	}
	e.savePIndex();
	e.saveSIndex();
	e.saveSLIndex();*/
	e.loadPIndex();
	e.loadSIndex();
	e.loadSLIndex();
	for (int i = 0; i < 3; i++) {
		cout << endl << "Enter ID: ";
		cin >> id;
		e.readDepartmentByID(id);
	}
	for (int i = 0; i < 3; i++) {
		e.readDepartmentByName();
	}
	system("pause");
}