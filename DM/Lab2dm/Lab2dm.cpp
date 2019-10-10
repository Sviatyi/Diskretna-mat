#include <iostream>
#include<algorithm>
#include<clocale>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Ukrainian");//������ ��������� ����

	int N, M;									//���������� �-���� ����� ������ A i B

	cout << "����i�� �i���i��� �������i� ������� �: ";	//������� �����
	cin >> N;											//N
	cout << "����i�� �i���i��� �������i� ������� B: ";	//�
	cin >> M;											//M � ���������

	char *arr1=new char[N], *arr2=new char[M];   //��������� ������ ������ A i B

	cout << "����i�� ������� A: ";
	for (int i = 0; i < N; i++) {       //
		cin >> arr1[i];					//������� ������� A � ���������
	}		                            //

	cout << "����i�� ������� B: ";
	for (int i = 0; i < M; i++) {       //
		cin >> arr2[i];					//������� ������� B � ���������
	}									//

	sort(&arr1[0], &arr1[N]);    //������� ����� arr1
	sort(&arr2[0], &arr2[M]);    //������� ����� arr2

	cout << "A ������� � B: ";

	int F = 0;
	char *arr3=new char[F];                 //��������� ������� A^B
	for (int i = 0; i < N; i++) {			//�������� ���� � 0 �� N
		for (int j = 0; j < M; j++) {		//�������� �� ���� ���� � 0 �� M 
			if (arr1[i] == arr2[j]) {		//���������� �� arr1[i] ������� arr2[j] 
				arr3[F] = arr1[i];			//���� � ��� ���� ������� � ������� �������� �� ����������
				F++;						//arr3 �������� arr1[i] � �������� F �� 1
			}
		}
	}
	sort(&arr3[0], &arr3[F]);			//������� ����� arr3

	for (int i = 0; i < F; i++) {		//
		cout << arr3[i] << " ";			//�������� ������� A^B
	}									//
	if (F == 0) {
		cout << "�������� ����";
	}
	cout << endl << "������i��� ������� �������� ������ A i B: "<<F;
	
	int U = N;							//��������� ������� ���������
	char *arr4=new char[U];				//��� �� ���� � �-���� ����� �� ������� A
	for (int i = 0; i < U; i++) {		//
		arr4[i] = arr1[i];				//������ � ������� ��������� ������� �� ����� ������� A     
	}								    //
	int check = 0;						//��������� ����� check ��� �� ����������� ��� ��������
	for (int j = 0; j < M; j++) {       //��������� ���� �������� 
		for (int f = 0; f < F; f++) {   //��������� ���� �������� 
			if (arr2[j] != arr3[f]) {   //���� arr2[j] �� ������� arr3[f]
				check++;				//����� check ���������� �� 1
			}							//
		}								//
		if (check == F) {               //���� check ������� F �� ������ �� ���� ������ arr2 �� ��������� 
			arr4[U] = arr2[j];			//������� ����� ������ arr3 ���� ���� ����� �������� �� ���������
			U++;						//
		}								//
		check = 0;						//
	}									//
	sort(&arr4[0], &arr4[U]);			//������� ��������
	
	//cout << endl << "��������: ";

	/*for (int i = 0; i < U; i++) {
		cout << arr4[i] << " ";
	}*/

	cout <<endl<< "���������� �i����� A i B: ";

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
		cout << "������� �������i";
	}
	for (int i = 0; i <T; i++) {
		cout << arr5[i] << " ";
	}
	cout << endl << "������i��� ������� ���������� �i����i ������ A i B: " << T<<endl<<endl<<endl;





	return 0;
}
