#include<iostream>
#include<fstream>
#include<string>
#include<vector>
using namespace std;
class Patient {
private:
	string name, BloodType, mobile, id, age;
public:
	void set_name(string s) {
		name = s;
	}
	void set_BloodType(string s) {
		BloodType = s;
	}
	void set_mobile(string s) {
		mobile = s;
	}
	void set_id(string s) {
		id = s;
	}
	void set_age(string x) {
		age = x;
	}
	string get_name() {
		return name;
	}
	string get_BloodType() {
		return BloodType;
	}
	string get_mobile() {
		return mobile;
	}
	string get_id() {
		return id;
	}
	string get_age() {
		return age;
	}
	Patient() {
		name = "omar";
		BloodType = "o";
		mobile = "01100226115";
		id = "123456";
		age = "20";
	}
};
void Search_no(vector<Patient>obj1,int num, int i) {
	if (i > 0 && i <= num) {
		i--;
		cout << "***************\n";
		cout << "name: " << obj1[i].get_name() << endl;
		cout << "BloodType: " << obj1[i].get_BloodType() << endl;
		cout << "mobilee: " << obj1[i].get_mobile() << endl;
		cout << "id: " << obj1[i].get_id() << endl;
		cout << "age: " << obj1[i].get_age() << endl;
		cout << "***************\n";
	}
	else cout << "it is not found\n";
}
void refrish(int* p) {
	fstream file;
	file.open("data.txt", ios::in);
	if (file.is_open()) {
		string t;
		while (true) {
			getline(file, t);
			if (t.size()) (*p)++;
			else break;
		}
		file.close();
	}
}
void update(vector<Patient>&obj1, int num) {
	fstream file;
	file.open("data.txt", ios::in);
	if (file.is_open()) {
		string temp;
		for (int i = 0; i < num; i++) {
			getline(file, temp);
			obj1[i].set_name(temp.substr(0, temp.find(",")));
			obj1[i].set_BloodType(temp.substr(temp.find(",") + 1, temp.find(";") - temp.find(",") - 1));
			obj1[i].set_mobile(temp.substr(temp.find(";") + 1, temp.find("/") - temp.find(";") - 1));
			obj1[i].set_id(temp.substr(temp.find("/") + 1, temp.find(":") - temp.find("/") - 1));
			obj1[i].set_age(temp.substr(temp.find(":") + 1, temp.find(".") - temp.find(":") - 1));
		}
		file.close();
	}
}
void app_data(vector<Patient>& obj1,int num) {
	fstream file;
	num--;
	file.open("data.txt", ios::app);
	if (file.is_open()) {
		file << obj1[num].get_name() << ",";
		file << obj1[num].get_BloodType() << ";";
		file << obj1[num].get_mobile() << "/";
		file << obj1[num].get_id() << ":";
		file << obj1[num].get_age() << ".\n";
		file.close();
	}
}
void add_new(vector<Patient>& obj1, int* p) {
	string x1;
	cout << "name: ";
	cin >> x1;
	obj1[*p].set_name(x1);
	cout << "BloodType: ";
	cin >> x1;
	obj1[*p].set_BloodType(x1);
	cout << "mobile: ";
	cin >> x1;
	obj1[*p].set_mobile(x1);
	cout << "id: ";
	cin >> x1;
	obj1[*p].set_id(x1);
	cout << "age: ";
	cin >> x1;
	obj1[*p].set_age(x1);
	(*p)++;
}
int main(){
	vector<Patient>obj1(100);
	int num = 0;
	refrish(&num);
	update(obj1, num);
	cout <<"the number of patient in file: "<< num << endl;
	char test;
	while (true) {
		cout << "to add enter    <a>\n";
		cout << "to search enter <s>\n";
		cout << "to quit enter   <q>\n";
		cin >> test;
		if (test == 'a' || test == 'A') {
			add_new(obj1, &num);
			app_data(obj1, num);
		}
		if (test == 's' || test == 'S') {
			int i = 0;
			cout << "the no. of patiant : ";
			cin >> i;
			Search_no(obj1, num, i);
		}
		if (test == 'q' || test == 'Q')break;
	}

	return 0;
};
