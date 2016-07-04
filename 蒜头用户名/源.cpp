#include <iostream>
#include <string>
#include<algorithm>
#include<cctype>
using namespace std;
class HashTable {
private:
	string *elem;
	int size;
public:
	HashTable() {
		size = 2000;
		elem = new string[size];
		for (int i = 0; i < size; i++) {
			elem[i] = "#";
		}
	}
	~HashTable() {
		delete[] elem;
	}
	int hash(string& index) {
		int code = 0;
		for (size_t i = 0; i < index.length(); i++) {
			code = (code * 256 + index[i] + 128) % size;
		}
		return code;
	}
	bool search(string& index, int& pos, int& times) {
		pos = hash(index);
		times = 0;
		while (elem[pos] != "#" && elem[pos] != index) {
			times++;
			if (times < size) {
				pos = (pos + 1) % size;
			}
			else {
				return false;
			}
		}
		if (elem[pos] == index) {
			return true;
		}
		else {
			return false;
		}
	}
	int insert(string& index) {
		int pos, times;
		if (search(index, pos, times)) {
			return 2;
		}
		else if (times < size / 2) {
			elem[pos] = index;

			return 1;
		}
		else {
			recreate();
			search(index, pos, times);
			elem[pos] = index;
			return 1;
		}
	}
	void recreate()
	{
		string * temp_elem;
		temp_elem = new string[size];
		for (int i = 0; i < size; i++)
		{
			temp_elem[i] = elem[i];
		}
		int copy_size = size;
		size *= 2;
		delete[] elem;
		elem = new string[size];
		for (int i = 0; i < size; i++) {
			elem[i] = "#";
		}
		for (int i = 0; i < copy_size; i++)
		{
			if (temp_elem[i] != "#")
			{
				insert(temp_elem[i]);
			}

		}
		delete[] temp_elem;
	}

};
void lower(char & cc)
{
	cc = tolower(cc);
}
int main() {
	HashTable hashtable;
	string buffer;
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> buffer;
		for_each(buffer.begin(), buffer.end(), lower);
		int ans = hashtable.insert(buffer);
		if (ans == 1) {
			cout << "No" << endl;
		}
		else if (ans == 2) {
			cout << "Yes" << endl;
		}
	}
	return 0;
}
