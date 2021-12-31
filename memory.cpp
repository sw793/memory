#include <iostream>
#include <ctime>
using namespace std;
int main(){
	int n = 10;	//кол-во карточек
	int a[n] = { 1, 2, 3, 4, 5, 1, 2, 3, 4, 5 }; // комбинация, которая будет перемешиваться
	int index[n];	
	int a2[n];
	int number1, number2, count = 0;
 	for (int i = 0; i < n; i++)
		cout << "[ " << i + 1 << " ]" << " ";
	srand ((unsigned) time (NULL));				// перемешивание чисел
	for (int i = 0; i < n; i++){
		index[i] = rand () % n;
		for (int j = 0; j < i; j++){
			if (index[j] == index[i]){
				i--;
			}
		}
	}
	for (int i = 0; i < n; i++)
		a2[i] = a[index[i]];
	do{
		cout << endl << "Напишите два номера карточек: ";
		cin >> number1 >> number2;
		if ((0 >= number1) && (0 < number2) && (number2 < 10) && (number1 < 10))
			cout << "Ваше число маленькое, оно должно быть больше нуля.";
		if ((0 >= number2) && (0 < number1) && (number1 < 10))
			cout << "Ваше число маленькое, оно должно быть больше нуля.";
		if ((0 > number1) && (0 > number2) && (number1 < 10) &&  (number2 < 10))
			cout << "Ваши числа маленькие, они должны быть больше нуля.";
			
		if ((number1 > 10) && (0 < number2) && (number2 < 10)) 
				cout << "Ваше число слишком большое, оно должно быть меньше десяти. ";
		if ((number2 > 10) && (0 < number1) && (number1 < 10)) 
				cout << "Ваше число слишком большое, оно должно быть меньше десяти. ";
		if ((number1 > 10) && (number2 > 10) && (number1 > 0) && (number2 > 0)) 
				cout << "Ваши числа слишком большие, они должно быть меньше десяти. ";   
		if(((number1 > 10) || (number2 > 10)) && ((number1 < 0) || (number2 < 0)))
				cout <<  "Одно ваше число маленькое, а другое большое, придумайте числа от одного до десяти. ";
		if((number1 == number2) && (0 < number1) && (number1 < 10) && (0 < number2) && (number2 < 10))
				cout << "Ваши числа равны, так не должно быть. ";   
		if (((a2[number1-1] == 0) || (a2[number2-1] == 0)) && ((a2[number1-1]!=0) || (a2[number2-1] != 0)) && (number1 != number2))
				cout << "Вы ввели выиграшное число, придумайте другое.";
		if ((a2[number1-1] == 0)  &&  (a2[number2-1] == 0) && (number1 != number2))
				cout << "Вы ввели выиграшные числа, придумайте другие.";
		if((0 < number1) && (number1 <= 10)  &&  (0 < number2)  &&  (number2 <= 10)  &&  (a2[number1-1] != 0)  &&  (a2[number2-1] != 0) && (number1 != number2)){
			for(int i = 0; i < n; i++){
				if (i + 1 == number1){
					if (a2[number1 - 1] == 1)
						cout << "[ ! ] ";
					if (a2[number1 - 1] == 2)
						cout << "[ @ ] ";
					if (a2[number1 - 1] == 3)
						cout << "[ # ] ";
					if (a2[number1 - 1] == 4)
						cout << "[ $ ] ";
					if (a2[number1 - 1] == 5)
						cout << "[ % ] ";
				} 
				if (i + 1 == number2){
					if (a2[number2-1] == 1) 
						cout << "[ ! ] ";
					if (a2[number2-1] == 2)
						cout << "[ @ ] ";
					if (a2[number2 - 1] == 3)
						cout << "[ # ] ";
					if (a2[number2 - 1] == 4)
						cout << "[ $ ] ";
					if (a2[number2 - 1] == 5)
						cout << "[ % ] ";
				} 
				if ((i + 1 != number1)  &&  (i + 1 != number2)){  
					if(a2[i] != 0)
						cout << "[ " << i + 1 << " ] ";
					else
						cout << "[ " << " " << " ] ";
				}
			}
			if ((a2[number1-1] == a2[number2-1])  ||  (a2[number2-1] == a2[number1-1])){
				cout << endl << "Есть пробитие";
				a2[number1-1] = 0;
				a2[number2-1] = 0;
				count+=2;
			}
		}
		system("clear");
	}
	while (count < 10);
	if (count == 10)
			cout << endl << "Юху, вы победили";
	return 0;
}
