#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int main() {
	int chet[8];
	int nechet[8];
	int a = 0;
	int sum = 0;
	int p = 0;
	int l = 0;
	string word;
	string new_word = "";
	cout << "Write your number: ";
	getline(cin, word); //присваиваем word значение, которое мы вводим
   
	for (int i = 0; i < word.size(); i++) { //удаление пробелов из word
		if (!isspace(word[i])) {
			new_word += word[i];
        }
    }
   
	int num[new_word.length()]; // создаем массив символов длиной равной длине введенного слова

	for (int i = 0; i < new_word.length(); i++) {
		num[i] = stoi(string(1, new_word[i]));
	}
	
	if (new_word.length() == 16){
		for (int i = 0; i < new_word.length(); i++){
			if ((i + 1) % 2 == 0){
				chet[p] = num[i];
				p++;
			}
		}
		
		p = 0;
		
		for (int i = 0; i < new_word.length(); i++) {
			if ((i + 1) % 2 != 0){ //умножение каждого числа, которое четное по счету на 2
				nechet[p] = num[i] * 2;
				if (nechet[p] > 9){
					a = nechet[p] - 10;
					a += 1;
					nechet[p] = a;
				}
				p++;
			}
			/*else{
				chet[p] = num[i];
				p++;
			}*/
		}
	}
	else{
		cout << "You wrote wrong number of your card!";
	}
	
	cout << "Sum: ";
	for (p = 0; p < 8; p++){
		sum += nechet[p] + chet[p];
	}
	
	cout << sum;
	
	if (sum % 10 == 0){
		cout << endl << "Your card is valid";
	}
	else{
		cout << endl << "Your card is invalid";
	}
	
	return 0;
}