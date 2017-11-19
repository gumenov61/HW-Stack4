//METHOD INIT
#include "stack.hpp"

void foo_init() {
	try {
		cout << endl << "INITIALIZING 3 INT-ARRAYS..." << endl << endl;
		Stack<int> IntArrA;
		Stack<int> IntArrB;
		Stack<int> IntArrC; //  Переносим сзданный объект по rvalue ссылке в IntArrC.
		Stack<int> IntArrD;

		cout << "FILLING IntArrA ARRAY..." << endl << endl;
		for (int i = 0; i < 10; i++) {
			IntArrA.push(i);
		}

		cout << "FILLING IntArrC ARRAY..." << endl << endl;
		for (int i = 0; i < 10; i++) {
			IntArrC.push(i);
		}

		cout << "COPY IntArrA INTO IntArrB..." << endl << endl;
		IntArrB = IntArrA; //  Копируем IntArrA в IntArrB.
		//Stack<int> IntArrB(std::move(IntArrA));
		cout << "MOVE IntArrC INTO IntArrD..." << endl << endl;
		IntArrD = std::move(IntArrC);

		cout << "CLEANING IntArrA ARRAY..." << endl << "RESULT\t";
		while(IntArrA.empty()) {
			IntArrA.pop();
			cout << IntArrA.top() << " ";
		}
		cout << endl << endl;

		cout << "CLEANING IntArrB ARRAY..." << endl << "RESULT\t";
		while(IntArrB.empty()) {
			IntArrB.pop();
			cout << IntArrB.top() << " ";
		}
		cout << endl << endl;

		cout << "CLEANING IntArrD ARRAY..." << endl << "RESULT\t";
		while(IntArrD.empty()) {
			IntArrD.pop();
			cout << IntArrD.top() << " ";
		}
		cout << endl << endl;

	} catch(const std::exception& e) {
		cout << e.what() << endl;
	}
}

int main() {
	foo_init();
}