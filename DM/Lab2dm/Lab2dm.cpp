#include <iostream>
#include<algorithm>
#include<clocale>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Ukrainian");//додаємо українську мову

	int N, M;									//ініціалзуємо к-ксть членів множин A i B

	cout << "Введiть кiлькiсть елементiв множини А: ";	//Вводимо змінну
	cin >> N;											//N
	cout << "Введiть кiлькiсть елементiв множини B: ";	//і
	cin >> M;											//M з клавіатури

	char *arr1=new char[N], *arr2=new char[M];   //створюємо масиви множин A i B

	cout << "Введiть множину A: ";
	for (int i = 0; i < N; i++) {       //
		cin >> arr1[i];					//вводимо множину A з клавіатури
	}		                            //

	cout << "Введiть множину B: ";
	for (int i = 0; i < M; i++) {       //
		cin >> arr2[i];					//вводимо множину B з клавіатури
	}									//

	sort(&arr1[0], &arr1[N]);    //сортуємо масив arr1
	sort(&arr2[0], &arr2[M]);    //сортуємо масив arr2

	cout << "A перетин з B: ";

	int F = 0;
	char *arr3=new char[F];                 //створюємо множину A^B
	for (int i = 0; i < N; i++) {			//запускаєм цикл з 0 по N
		for (int j = 0; j < M; j++) {		//запускаєм ще один цикл з 0 по M 
			if (arr1[i] == arr2[j]) {		//перевіряємо чи arr1[i] дорівнює arr2[j] 
				arr3[F] = arr1[i];			//якщо в цих двох масивах є однакові елементи ми присвоюємо
				F++;						//arr3 значення arr1[i] і збільшуємо F на 1
			}
		}
	}
	sort(&arr3[0], &arr3[F]);			//сортуємо масив arr3

	for (int i = 0; i < F; i++) {		//
		cout << arr3[i] << " ";			//виводимо множину A^B
	}									//
	if (F == 0) {
		cout << "Перетину немає";
	}
	cout << endl << "Потужнiсть множини перетину множин A i B: "<<F;
	
	int U = N;							//створюємо множину універсуму
	char *arr4=new char[U];				//яка має таку ж к-ксть членів як множина A
	for (int i = 0; i < U; i++) {		//
		arr4[i] = arr1[i];				//спершу у множину універсуму вводимо всі члени множини A     
	}								    //
	int check = 0;						//створюємо змінну check яку ми використаємо для перевірки
	for (int j = 0; j < M; j++) {       //створюємо цикл перевірки 
		for (int f = 0; f < F; f++) {   //створюємо цикл перебору 
			if (arr2[j] != arr3[f]) {   //якщо arr2[j] не дорівнює arr3[f]
				check++;				//змінна check збільшується на 1
			}							//
		}								//
		if (check == F) {               //якщо check дорівнює F це означає що член масиву arr2 не дорівнював 
			arr4[U] = arr2[j];			//жодному члену масиву arr3 отже його можна записати до універсуму
			U++;						//
		}								//
		check = 0;						//
	}									//
	sort(&arr4[0], &arr4[U]);			//сортуємо універсум
	
	//cout << endl << "Універсум: ";

	/*for (int i = 0; i < U; i++) {
		cout << arr4[i] << " ";
	}*/

	cout <<endl<< "Симетрична рiзниця A i B: ";

	int T = 0,check1=0;
	char *arr5 = new char[U-F];

	for (int i = 0; i <U ; i++) {
		for (int j = 0; j < F; j++) {
			if (arr4[i] != arr3[j]) {   //
				check1++;				//
			}							//
		}								//
		if (check1 == F) {              // 
			arr5[T] = arr4[i];			//
			T++;						//
		}								//
		check1 = 0;						//
	}
	if (T == 0) {
		cout << "Множини однаковi";
	}
	for (int i = 0; i <T; i++) {
		cout << arr5[i] << " ";
	}
	cout << endl << "Потужнiсть множини симетричної рiзницi множин A i B: " << T<<endl<<endl<<endl;





	return 0;
}
