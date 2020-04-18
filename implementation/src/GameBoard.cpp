#include <iostream>
#include <vector>
#include "../include/GameBoard.h"
#include "../include/CardStack.h"
#include "../include/CardTypes.h"
#include <stdexcept>


using namespace std;


BoardT::BoardT(vector<CardT> deck){
	int count=0;
	vector<CardT> null {};
	for(unsigned int i =0 ; i < deck.size(); i++){
		for(unsigned int j=0; j < deck.size(); j++){
			if((i != j ) && (deck[i].r == deck[j].r) && (deck[i].s == deck[j].s)){
				count = count + 1;
				
			}
		}
	}

	if (count == 104){
		for (int i =0; i < 10; i++){
			CardStackT new_stack;
			for (int j=0; j<4; j++){

				new_stack = new_stack.push(deck[(4*i) + j]);

				
				
			}

			this->Tableau.push_back(new_stack);
			
		}

		for (int i = 0; i < 8; i++){
			CardStackT new_stack;
			this->Foundation.push_back(new_stack);
		}

	

		this->deck = CardStackT(null);

		for (int i =40; i < 104; i++){
			this->deck = this->deck.push(deck[i]);
		}

		this->waste = CardStackT(null);

	}

	else{
		throw std::invalid_argument("No two decks");
	}
	

	
};

CardStackT BoardT::get_tab(int index){
	if (0 <= index && index <10){
		std::vector<CardStackT> seq;
		seq = this->Tableau;
		return seq[index];
	}
	else {
		throw std::out_of_range("Tableau out of range");
	}
}


CardStackT BoardT::get_foundation(int index){
	if (0 <= index && index <8){
		return this->Foundation[index];
	}
	else {
		throw std::out_of_range("Foundation out of range");
	}
}


CardStackT BoardT::get_deck(){
	return this->deck;
}

CardStackT BoardT::get_waste(){
	return this->waste;
}



bool BoardT::is_valid_tab_mv(CategoryT c, int n_0 , int n_1){
	
	if (c == 0){
		if (is_valid_pos(static_cast<CategoryT>(0),n_0) && is_valid_pos(static_cast<CategoryT>(0),n_1)){
			
			return valid_tab_tab(n_0,n_1);
		}
		else{

			throw std::out_of_range("Tableau out of range");
		}
	}

	else if ( c == 1){

		if (is_valid_pos(static_cast<CategoryT>(0),n_0) && is_valid_pos(static_cast<CategoryT>(1),n_1)){
			return valid_tab_foundation(n_0,n_1);
		}

		else{
			throw std::out_of_range("Tableau or Foundation out of range");
		}
	}

	else{
		return false;
	}
}

bool BoardT::valid_tab_tab(int n_0 , int n_1){
	
	if (this->Tableau[n_0].size() > 0){
		if (this->Tableau[n_1].size() > 0){
			return tab_placeable(this->Tableau[n_0].top() , this->Tableau[n_1].top());

		}

		else{
			return true;
		}
	}

	else{
		return false;
	}

}



bool BoardT::valid_tab_foundation(int n_0, int n_1){
	if( this->Tableau[n_0].size() > 0){

		if ( this->Foundation[n_1].size() > 0){
			return foundation_placeable(this->Tableau[n_0].top() , this->Foundation[n_1].top());
		}
		else{

			if (this->Tableau[n_0].top().r == ACE ){
				return true;
			}
			else{
				return false;
			}
		}
	}
	else{
		return false;
	}
}

bool BoardT::tab_placeable(CardT card1 , CardT card2){
		

	if ((card1.s == card2.s) && (card1.r == card2.r - 1) ){
		return true;
	}

	else{

		return false;
		
	}
}

bool BoardT::foundation_placeable(CardT card1 , CardT card2){
		

	if ((card1.s == card2.s) && (card1.r == card2.r + 1) ){
		return true;
	}

	else{

		return false;
		
	}
}

bool BoardT::is_valid_waste_mv(CategoryT c , int n){
	if(this->waste.size() == 0){
		throw std::invalid_argument("Waste empty");
	}

	if ( c ==0){
		if(is_valid_pos(static_cast<CategoryT>(0),n)){
			return valid_waste_tab(n);
		}
		
		else{
			throw std::out_of_range("Tableau out of range");

		}
	}

	else if (c == 1){
		if(is_valid_pos(static_cast<CategoryT>(1),n)){
			return valid_waste_foundation(n);
		}
		else{
			throw std::out_of_range("Tableau out of range");

		}
		
	}

	else{
		return false;
	}
}


bool BoardT::valid_waste_tab(int n){
	if (this->Tableau[n].size() > 0){
		return tab_placeable(this->waste.top(),this->Tableau[n].top());
	}

	else{
		return true;
	}
}

bool BoardT::valid_waste_foundation(int n){
	if (this->Foundation[n].size() > 0){
		return foundation_placeable(this->waste.top(),this->Foundation[n].top());
	}

	else{
		return (this->waste.top().r == ACE);
	}
}

bool BoardT::is_valid_deck_mv(){
	return this->deck.size() > 0;
}

void BoardT::tab_mv(CategoryT c , int n_0, int n_1){
	if (is_valid_tab_mv(c,n_0 , n_1)){
		if (c ==0){
			CardT mov = this->Tableau[n_0].top();
			this->Tableau[n_1] = this->Tableau[n_1].push(mov);
			this->Tableau[n_0] = this->Tableau[n_0].pop();
			//cout << "Card moved from Tab to a different Tab" << endl;

		}

		else{
			CardT mov = this->Tableau[n_0].top();
			this->Foundation[n_1] = this->Foundation[n_1].push(mov);
			this->Tableau[n_0] = this->Tableau[n_0].pop();
			//cout << "Card moved from Tab to foundation" << endl;
		}

	}
	else{
		throw std::invalid_argument("Tab move not valid");

	}
		
}

void BoardT::waste_mv(CategoryT c , int n){
	if (is_valid_waste_mv(c,n) == 1){
		if ( c == 0){
			CardT mov = this->waste.top();
			this->Tableau[n] = this->Tableau[n].push(mov);
			this->waste = this->waste.pop();
		}
		else{

			CardT mov = this->waste.top();
			this->Foundation[n] = this->Foundation[n].push(mov);
			this->waste = this->waste.pop();
	
		}

	}

	else{
		throw std::invalid_argument("Waste move not valid");
	}
	

}


void BoardT::deck_mv(){
	if (is_valid_deck_mv() == 1){
		CardT mov = deck.top();
		this->deck = this->deck.pop();
		this->waste = this->waste.push(mov);
		
	}

	else{
		throw std::invalid_argument("Move from Deck to Waste not valid");
	}

	
}

bool BoardT::valid_mv_exists(){
	if(is_valid_deck_mv()){
		return true;
	}

	int validMv = 0;
	CategoryT c;
	for (int i =0; i<2; i++){
		c = static_cast<CategoryT>(i);
		for(int n_0 = 0; n_0<10; n_0++){
			for (int n_1 =0; n_1 < 10; n_1++){
				if(!((i==0) && (n_0 == n_1))){
					if((is_valid_pos(static_cast<CategoryT>(0),n_0)) && (is_valid_pos(c,n_1))){
						validMv = validMv || is_valid_tab_mv(c,n_0,n_1) || is_valid_waste_mv(c,n_1);
					}


				}
			}
		}
	}

	return validMv;
}



bool BoardT::is_win_state(){
	bool win = 1;
	for (int i=0; i <8; i++){
		win = win && ((this->Foundation[i].size() > 0) && this->Foundation[i].top().r == 13);
	}

	return win;
}


bool BoardT::is_valid_pos(CategoryT c , int n){
	if (c ==0){
		return n < 10;
	}

	else if(c ==1){
		return n < 8;
	}
	else{
		return false;
	}
}

