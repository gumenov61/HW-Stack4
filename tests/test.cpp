#include "catch.hpp"
#include <stack.hpp>

SCENARIO("init") {
	Stack<int> IntArr;
	REQUIRE(IntArr.count() == 0);
}
	
SCENARIO("push") {
	Stack<int> IntArr;

	IntArr.push(3);
	IntArr.push(6);
	IntArr.push(9);

	IntArr.pop();

	REQUIRE(IntArr.count() == 2);
	REQUIRE(IntArr.top() == 9);
}

SCENARIO("pop") {
	Stack<int> IntArr;

	IntArr.push(5);
	IntArr.push(7);
	IntArr.push(9);

	IntArr.pop();
	IntArr.pop();

	REQUIRE(IntArr.count() == 1);
	REQUIRE(IntArr.top() == 7);
}

SCENARIO("empty") {
	Stack<int> IntArr;

	IntArr.push(5);
	IntArr.push(7);
	IntArr.push(9);

	IntArr.pop();
	IntArr.pop();
	IntArr.pop();
	
	REQUIRE(IntArr.empty() == false);
}
