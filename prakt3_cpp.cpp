#include <iostream>

using namespace std;

struct Sotr {
	char familiya[128];
	bool obrazovanie; // true - высшее, false - среднее

	union {
		struct {
			int god_okonchaniya;
			char name_vuz[128];
		} vishka;
		int vozrast;
	};
};

void vivod(Sotr sotr) {
	cout << "Фамилия: " << sotr.familiya << ", ";

	if (sotr.obrazovanie) {
		cout << "Высшее образование: " << sotr.vishka.god_okonchaniya << ", " << sotr.vishka.name_vuz << endl;
	}
	else {
		cout << "Возраст: " << sotr.vozrast << endl;
	}
}

void sort(Sotr sotr[], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (!sotr[j].obrazovanie && !sotr[j + 1].obrazovanie) {
				if (sotr[j].vozrast > sotr[j + 1].vozrast) {
					swap(sotr[j], sotr[j + 1]); // обмен значениями
				}
			}
		}
	}
}

int main() {
	setlocale(LC_ALL, "Russian");

	const int n = 3;

	Sotr st[n];

	strcpy_s(st[0].familiya, "Иванов");
	st[0].obrazovanie = true;
	st[0].vishka.god_okonchaniya = 2010;
	strcpy_s(st[0].vishka.name_vuz, "МГУ");

	strcpy_s(st[1].familiya, "Петров");
	st[1].obrazovanie = false;
	st[1].vozrast = 21;

	strcpy_s(st[2].familiya, "Макаров");
	st[2].obrazovanie = false;
	st[2].vozrast = 20;

	sort(st, n);

	for (int i = 0; i < n; i++) {
		if (!st[i].obrazovanie) {
			vivod(st[i]);
		}
	}
}