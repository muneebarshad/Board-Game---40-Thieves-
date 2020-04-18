/**
* \file testStack.cpp
* author Muneeb Arshad
*/


#include <iostream>
#include "../catch/catch.h"
#include "../include/CardTypes.h"
#include "../include/CardStack.h"

#include <algorithm>
#include <vector>
using namespace std;


TEST_CASE("Test for Stack.cpp", "[CardT]"){
	CardStackT newStack;
	SECTION("Size of empty stack is 0"){
		REQUIRE(newStack.size() == 0);
	}

	SECTION("Push cards and check size"){
		CardT n = {static_cast<SuitT>(0), 1 };
		newStack = newStack.push(n);
		REQUIRE(newStack.size() == 1);
	}

	SECTION("Push and pop cards and check size"){
		CardT n = {static_cast<SuitT>(0), 1 };
		newStack = newStack.push(n);
		newStack = newStack.push(n);
		newStack = newStack.pop();
		REQUIRE(newStack.size() == 1);

	}

	SECTION("Check top card"){
		CardT n = {static_cast<SuitT>(0), 1 };
		CardT c = {static_cast<SuitT>(3), 3 };
		newStack = newStack.push(n);
		newStack = newStack.push(c);
		int topCardRank = newStack.top().r;
		int topCardSuit = newStack.top().s;

		REQUIRE(topCardSuit == 3);

	}

	SECTION("Test toSeq"){
		CardT n = {static_cast<SuitT>(0), 1 };
		CardT c = {static_cast<SuitT>(3), 3 };
		newStack = newStack.push(n);
		newStack = newStack.push(c);
		vector<CardT> newSeq = newStack.toSeq();

		REQUIRE(newSeq[1].r == 3);

	}

}