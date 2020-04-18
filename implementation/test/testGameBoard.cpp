/**
* \file testGameboard.cpp
* author Muneeb Arshad
*/

#include <iostream>
#include "../catch/catch.h"
#include "../include/GameBoard.h"
#include "../include/CardTypes.h"

#include <algorithm>
#include <vector>
using namespace std;

TEST_CASE("Test for Gmaeboard.cpp 1" , "[BoardT]" ){


	std::vector<CardT> d;
	for (RankT rank = ACE; rank <= KING; rank++) {
		for (unsigned int suit = 0; suit < 4; suit++) {
	 		CardT n = { static_cast<SuitT>(suit), rank };

	  		d.push_back(n);
	  		d.push_back(n);
	  	}
	}


	std::random_shuffle(d.begin(), d.end());

	BoardT board(d);
	//The game just started so it can not win.
	SECTION("Tests if the user has won the game" , "Win_state()"){
		REQUIRE_FALSE(board.is_win_state());
	}

	SECTION("Tests if there is a Valid move"){
		board.deck_mv();
		REQUIRE(board.valid_mv_exists());
	}

	SECTION("Tests if the card from deck can moved to waste" , "deck_mv()"){
		CardT c = board.get_deck().top();
		board.deck_mv();
		bool same = ((board.get_waste().top().r == c.r) && (board.get_waste().top().s == c.s) );
		REQUIRE(same);
	}

	SECTION("Tests if the card from deck can moved to waste(part2)" , "deck_mv()"){
		board.deck_mv();
		board.deck_mv();
		CardT c = board.get_deck().top();
		
		board.deck_mv();
		bool same = ((board.get_waste().top().r == c.r) && (board.get_waste().top().s == c.s) );
		REQUIRE(same);
	}


	SECTION("Gameboard constructor"){
		std::vector<CardT> d;
		for (RankT rank = ACE; rank <= KING; rank++) {
			for (unsigned int suit = 0; suit < 4; suit++) {
		 		CardT n = { static_cast<SuitT>(suit), rank };
		  		d.push_back(n);
		  		d.push_back(n);
		  	}
		}
		BoardT board(d);
		for(int i=0; i < 10 ; i++){
			REQUIRE(board.get_tab(i).size() == 4);
		}

		for(int i=0; i < 8 ; i++){
			REQUIRE(board.get_foundation(i).size() == 0);
		}

		REQUIRE(board.get_deck().size() == 64);
		REQUIRE(board.get_waste().size() == 0);
	}


	SECTION("Tab move"){
		std::vector<CardT> d;
		for (RankT rank = ACE; rank <= KING; rank++) {
			for (unsigned int suit = 0; suit < 4; suit++) {
		 		CardT n = { static_cast<SuitT>(suit), rank };
		  		d.push_back(n);
		  		d.push_back(n);
		  	}
		}
		BoardT board(d);
		REQUIRE(board.is_valid_tab_mv(Foundation,0,0));
		REQUIRE(board.is_valid_tab_mv(Foundation,1,1));
		board.tab_mv(Foundation,0,0);
		REQUIRE_THROWS_AS(board.tab_mv(Foundation,1,0),invalid_argument);
		board.tab_mv(Foundation,1,1);
		board.deck_mv();
		REQUIRE_FALSE(board.is_valid_waste_mv(Foundation,3));
	}

	

}

TEST_CASE("Test for Gmaeboard.cpp 2" , "[BoardT]"){
	std::vector<CardT> d;
	for (RankT rank = ACE; rank <= KING; rank++) {
		for (unsigned int suit = 0; suit < 4; suit++) {
	 		CardT n = { static_cast<SuitT>(suit), rank };

	  		d.push_back(n);
	  		d.push_back(n);
	  	}
	}


	
	BoardT board(d);
	
	

	SECTION("Test if the move from tab to foundation is valid and test if the card can be moved to the foundation"){
		REQUIRE(board.is_valid_tab_mv(Foundation,1,0));
		int rank = board.get_tab(1).top().r;
		board.tab_mv(Foundation,1,0);
		REQUIRE(board.get_foundation(0).top().r == rank);
	}

	
	SECTION("Test if the move from tab to tab is valid and test if the card can be moved to the tab"){
		REQUIRE(board.is_valid_tab_mv(Tableau,1,3));
		int rank = board.get_tab(1).top().r;
		board.tab_mv(Tableau,1,3);
		REQUIRE(board.get_tab(3).top().r == rank);	
	}

	SECTION("Test for exptions"){
		std::vector<CardT> d;
		for (RankT rank = ACE; rank <= KING; rank++) {
			for (unsigned int suit = 0; suit < 4; suit++) {
		 		CardT n = { static_cast<SuitT>(suit), rank };

		  		d.push_back(n);
		  		d.push_back(n);
		  	}
		}
		BoardT board(d);
		REQUIRE_THROWS_AS(board.is_valid_tab_mv(Tableau,0,32), out_of_range);
		REQUIRE_THROWS_AS(board.is_valid_tab_mv(Foundation,0,10), out_of_range);
		REQUIRE_THROWS_AS(board.is_valid_waste_mv(Foundation,0), invalid_argument);
		REQUIRE_THROWS_AS(board.is_valid_waste_mv(Tableau,4), invalid_argument);
	}


	SECTION("Test for deck_mv() and is_valid_deck()"){
		std::vector<CardT> d;
		for (RankT rank = ACE; rank <= KING; rank++) {
			for (unsigned int suit = 0; suit < 4; suit++) {
		 		CardT n = { static_cast<SuitT>(suit), rank };
		  		d.push_back(n);
		  		d.push_back(n);
		  	}
		}
		BoardT board(d);
		for(int i=0; i<64; i++){
			CardT card = board.get_deck().top();
			board.deck_mv();
			REQUIRE(board.get_waste().top().r == card.r);
		}
		REQUIRE_FALSE(board.is_valid_deck_mv());

	}

	

}




