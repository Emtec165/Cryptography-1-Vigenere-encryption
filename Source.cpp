//
//KRYPTOGRAFIA PIERWSZY PROJEKT
//KRZYSZTOF PIKÓRA 150227
//
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(void){
	string line;
	ifstream myfile("lab1.txt");
	if (myfile.is_open()){
		while (getline(myfile, line)){
			cout << line << '\n';
		}
		myfile.close();
	}
	else cout << "Unable to open file";

	//line = "bardzosiecieszezewreszciezaczalsierokakademicki";//Do testowania programu
	//cout << line << endl;

	int dlugosctekstu, dlugoscklucza, y=1;
	string klucz;
	char kluczyk, wiadomosc;
	dlugosctekstu = line.length();
	cout << "\n\n\nTekst do zaszyfrowania ma " << dlugosctekstu << " znakow" << endl;
	cout << "Podaj klucz wg ktorego tekst bedzie szyfrowany\n";
	cin >> klucz;
	cout << "\n\n";
	dlugoscklucza = klucz.length();

	int sum;
	string szyfr;

	for (int x = 1; x < dlugosctekstu + 1; x++){
		sum = ((klucz[y-1]+line[x-1])-'a'-'a')%26;
		szyfr.push_back(char(sum + 'a'));
		//cout << sum << endl;
		//cout << char(sum + 'a') << endl;
		//cout << "\n\n" << endl;
		y++;

		if (y == dlugoscklucza + 1) { y = 1; }
		
	}

	cout << szyfr << endl;

	ofstream mojpliczek;
	mojpliczek.open("szyfr.txt");
	mojpliczek << szyfr;
	mojpliczek.close();

	system("pause");
	return 0;
}