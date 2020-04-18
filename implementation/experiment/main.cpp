/*
 * Use this file for experimenting with your code,
 * testing things that don't work, debugging, etc.
 *
 * You can compile and run this via 'make experiment'
 *
 * This file will not be graded
 */
#include <algorithm>
#include <iostream>
#include <vector>

#include "../include/CardStack.h"
#include "../include/CardTypes.h"
#include "../include/GameBoard.h"
using namespace std;



int main() {
  std::cout << "'make experiment' will run this main" << std::endl;

  // When you are finished your implementation, uncomment the code
  // below and make sure 'make experiment' compiles and runs.
  // This will ensure that your interface has the correct syntax and will be
  // compatible with our unit tests that we will run for grading.

 
  // Produce a new deck (consisting of two standard decks) and shuffle its
  // cards.
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
  try {
    std::cout << "Valid tab move? " << board.is_valid_tab_mv(Foundation, 0, 0) << std::endl;
  } catch (std::out_of_range &e) {}

  board.deck_mv();
  board.deck_mv();
  
  CardStackT waste1 = board.get_waste();
  std::cout << "Card(Rank,Suit)  :" <<  waste1.top().r << " " << waste1.top().s << std::endl;
    


  try {
    std::cout << "Valid waste move? " << board.is_valid_waste_mv(Foundation, 0) << std::endl;
  } catch (std::invalid_argument &e) {}
  std::cout << "Valid deck move? "   << board.is_valid_deck_mv() << std::endl;
  std::cout << "Is win state? "      << board.is_win_state() << std::endl;
  std::cout << "Valid move exists? " << board.valid_mv_exists() << std::endl;
  try {
    board.tab_mv(Tableau, 0, 1);
  } catch (std::invalid_argument &e) {}
  
  try {
    board.waste_mv(Tableau, 0);
  } catch (std::invalid_argument &e) {}
  CardStackT tableau = board.get_tab(0);
  CardStackT foundation = board.get_foundation(0);
  CardStackT deck = board.get_deck();
  CardStackT waste = board.get_waste();

  std::vector<CardT> vec = deck.toSeq();
  std::cout << "Sequence length: " << vec.size() << std::endl;
  std::cout << "Deck size: " << deck.size() << std::endl;
  std::cout << "Deck top: " << deck.top().s << " " << deck.top().r << std::endl;

  CardStackT foo(vec);
  foo = foo.push(d[0]);
  CardT bar = foo.top();
  std::cout << "Card: " << bar.s << " " << bar.r << std::endl;
  foo = foo.pop();


  std::cout << "Waste top: " << waste.top().s << " " << waste.top().r << std::endl;
  std::cout << "Waste size: " << waste.size() << " " << std::endl;
  cout << "Tab card top" << endl;
  for(int i = 0; i <10; i++){
    std::cout << "Card(Rank,Suit)  :" <<  board.get_tab(i).top().r << " " << board.get_tab(i).top().s << std::endl;
  }
    

  
  

  return 0;
}
