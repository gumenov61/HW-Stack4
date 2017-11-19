//METHOD EMPTY
#include "stack.hpp"

void foo_empty() {
	try {
		cout << endl << "RUN EMPTY FILE..." << endl;
		Stack<char> CharArr;

		char slovo[] = "NOITAREDEF_NAISSUR";

		for(int i = 0; i < sizeof(slovo); i++) { CharArr.push(slovo[i]); }

		cout << "RESULT\t";
		while(CharArr.empty()) {
			CharArr.pop();
			cout << CharArr.top() << " ";
		}
		cout << endl << endl;

	} catch(const std::exception& e) {
		cout << e.what() << endl;
	}
}

int main() {
	foo_empty();
}
