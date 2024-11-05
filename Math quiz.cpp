#include <iostream>
#include <conio.h> 
using namespace std;

enum diffiiculty {Easy=1,Normal,Hard,Mix};

int RandomNumber(int From, int To){

 int randNum = rand() % (To - From + 1) + From; return randNum;

}

int quizlvl(short lvl,short &quizNumbers) {

	switch(lvl) {
	case diffiiculty::Easy:return quizNumbers = RandomNumber(1,10);
		break;
	case diffiiculty::Normal:return quizNumbers = RandomNumber(11,50);
		break;
	case diffiiculty::Hard: return quizNumbers = RandomNumber(51,100); 
		break;
	case diffiiculty::Mix: return quizNumbers = RandomNumber(1,100);
		break;

	}

}

void results(short Qnumber,short lvl,short opType,short winningCounter,short losingCounter) {

	string operationsForResults[5] = { "Addition","Subtraction","Multiplication","Division","Mix"};

	string lvlForResults[4] = { "Easy","Normal","Hard","Mix" };

	cout << "-------------------------------------------------------\n";

	if (winningCounter > losingCounter) {
		cout << "\t  Final Result : YAY YOU PASSED !!"; system("Color A0");
	}
	else { cout << "  Final Result : AWWWW! It Looks Like You Didn't Pass"; system("Color C0"); } cout << endl;

	cout << "-------------------------------------------------------\n\n";
	cout << "Number Of Questions  \t:\t" << Qnumber << endl;
	cout << "Questions Level \t:\t"<<lvlForResults[lvl-1]<<"\n";
	cout << "Operation Type \t\t:\t"<<operationsForResults[opType-1]<<"\n";
	cout << "Number Of Right Answer  :\t"<<winningCounter<<"\n";
	cout << "Number Of Wrong Answers :\t"<<losingCounter<<"\n";
}

void Quiz() {

	short Qnumber = 1;
	short num1 = 1;
	short num2 = 1;
	short lvl = 1;
	short opType = 1;
	short answer = 1;
	short winningCounter = 0;
	short losingCounter = 0;
	char again = 0;

	cout << "How Many Questions Do You Want To Answer : "; cin >> Qnumber; cout << endl;

	cout << "[1] : Easy\n[2] : Normal\n[3] : Hard\n[4] : Mix\n\nEnter Level Of Questions : "; cin >> lvl; cout << endl;

	cout << "[1] : Addition\n[2] : Subtraction\n[3] : Multiplication\n[4] : Division\n[5] : Mix\n\nEnter Operation Type : "; cin >> opType; cout << endl;

	for (int i = 1; i <= Qnumber; i++) {


		quizlvl(lvl, num1);
		quizlvl(lvl, num2);

		short randomOperation = RandomNumber(0, 3);

		string operations = "+-*/";
		short operationResult[4] = { num1 + num2, num1 - num2, num1 * num2 , num1 / num2 };

		cout << "Question [" << i << "/" << Qnumber << "]\n\n";

		if (opType == 5) {

			cout << num1 << " " << operations[randomOperation] << " " << num2 << " = "; cin >> answer;

			if (answer == operationResult[randomOperation]) { cout << "\nGood Job ! Your Answer Is Right :-) \n\n"; system("Color A0"); winningCounter++; }
			else {
				cout << "\nOh No ! Your Answer Is Wrong :-(\n\n" << "The Right Answer Is : " << operationResult[randomOperation] << "\n\n"; system("Color C0"); losingCounter++;
			}

		}
		else {
			cout << num1 << " " << operations[opType - 1] << " " << num2 << " = "; cin >> answer;

			if (answer == operationResult[opType - 1]) { cout << "\nGood Job ! Your Answer Is Right :-) \n\n"; system("Color A0"); winningCounter++; }

			else { cout << "\nOh No ! Your Answer Is Wrong :-(\n\n" << "The Right Answer Is : " << operationResult[opType - 1] << "\n\n"; system("Color C0"); losingCounter++; }
		}



	}

	results(Qnumber, lvl, opType, winningCounter, losingCounter);

	cout << "\nDo You Want To Play Again (Y/N) ? : "; cin >> again; cout << endl;

	if (again == 'Y' || again == 'y') {
		system("cls");
		system("Color 0F");
		Quiz();
	}

}

int main()
{

	srand((unsigned)time(NULL));

	Quiz();

	return 0;
}


