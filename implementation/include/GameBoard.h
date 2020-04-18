/**
 * \file CardBoard.h
 * \author Muneeb Arshad
 * \Working parteners : Harshil Modi and Mariana Marilies 
 * \brief GameBoard.cpp is a module represtation module of a 40 Theives game that creates a boeard with 10 Tableau, 8 foundation , 1 deck and 1 waste stack. This cpp file consists of various methods that provides function of the game.
 */

#ifndef A3_GAME_BOARD_H_
#define A3_GAME_BOARD_H_
#include "CardStack.h"
#include "CardTypes.h"





class BoardT{
	private:
		/**
		* \brief Creates a vector Tableau of type CardStackT
		*/
		std::vector<CardStackT> Tableau;
		/**
		* \brief Creates a vector Foundation of type CardStackT
		*/
		std::vector<CardStackT> Foundation;

		/**
		* \brief Creates a stack of deck
		*/
		CardStackT deck;

		/**
		* \brief Creates a stack of waste
		*/
		CardStackT waste;





	public:
		/**
		* \param The constructor takes in a deck of cards
		* \brief The constructor creates 10 tablaue stacks, 8 foundations stacks, 1 stack for deck and 1 for waste on a gameboard.
		* \details The constructor checks if there are two decks on the game board. It adds 10 stacks each with  4 cards to the table and rest cards in the deck stack. 
		* \return It returns a game board. If the card deck is not two decks combines then it raises an error.
		*/
		BoardT(std::vector<CardT> deck);

		/**
		* \param Integer number of the potition of the stack in the vector.
		* \brief This function returns the stack in the tableau at the index position
		*/
		CardStackT get_tab(int index);

		/**
		* \param Integer number of the potition of the stack in the vector.
		* \brief This function returns the stack in the foundation at the index position
		*/
		CardStackT get_foundation(int index);

		/**
		* \brief returns the deck from the Gameboard
		*/
		CardStackT get_deck();

		/**
		* \brief returns the waste from the Gameboard
		*/
		CardStackT get_waste();

		/**
		* \param The CategoryT such as Tableau or Foundation in which the the card is moved. n_0 is the position in tableau from where the card is being removed. n_1 is the position in the foundation or tableau where the card is moved to.
		* \brief Checks if the card move is valid from Tableau
		* \return Returns a bool value
		*/
		bool is_valid_tab_mv(CategoryT c, int n_0 , int n_1);


		/**
		* \param n_0 is the position in tableau from where the card is being removed. n_1 is the position in the tableau where the card is moved to.
		* \brief Local function to check if the card being moved from tableau to tableau is valid
		*/
		bool valid_tab_tab(int n_0 , int n_1);


		/**
		* \param n_0 is the position in foundation from where the card is being removed. n_1 is the position in the foundation where the card is moved to.
		* \brief Local function to check if the card being moved from foundation to foundation is valid
		*/
		bool valid_tab_foundation(int n_0, int n_1);


		/**
		* \brief Local function to check if the card1 from n_0 tableau at n_0 is placeable in the tableau at n_1 over the card2
		*/
		bool tab_placeable(CardT card1 , CardT card2);


		/**
		* \brief Local function to check if the card1 from tableuau at n_0 is placeable in the foundation at n_1 over the card2.
		*/
		bool foundation_placeable(CardT card1 , CardT card2);


		/**
		* \param Inputs the category table or foundation and the int n which is the postion in the Catogory the card has to be add from the waste.
		* \brief Checks if the card from waste is valid in Tableau or Foundation.
		* \return Returns a bool value if the card is valid.
		*/
		bool is_valid_waste_mv(CategoryT c , int n);


		/**
		* \brief Local function to implement is_valid_waste_mv. If the input category is Tableau then this function is called with int n which is the nth stack in the tableau where its checksed if the card can be added.
		*/
		bool valid_waste_tab(int n);


		/**
		* \brief Local function to implement is_valid_waste_mv. If the input category is Foundation then this function is called with int n which is the nth stack in the tableau where its checksed if the card can be added.
		*/
		bool valid_waste_foundation(int n);


		/**
		* \brief Returns true if the card from the decks can be moved to the waste stack. Returns false only if the deck stack is not empty.
		*/
		bool is_valid_deck_mv();


		/**
		* \param The method takes CategoryT c which is the category Tableau or Foundation in which the card is added. The int n_0 is the position of the stack in the tableau from which the card is popped and int n_1 is the poition of the stack in the Tableau or foundation in which the card is added.
		* \brief Adds the card from the Tableau to the Category c
		*/
		void tab_mv(CategoryT c , int n_0, int n_1);


		/**
		* \param The method takes CategoryT c which is the category Tableau or Foundation in which the card is added. The int n is the poition of the stack in the Tableau or foundation in which the card is added.
		* \brief Adds the card from the Waste stack to the Category c
		*/
		void waste_mv(CategoryT c , int n);


		/**
		* \brief Pops the card from the deck stack and add it to the waste.
		*/
		void deck_mv();


		/**
		*  \brief Returns a True if there is a move exists in the game.
		* \return Returns a bool value
		*/
		bool valid_mv_exists();


		/**
		* \brief Checks if the top card on top of all stacks of Foundation are the of RankT 13 and all Foundation stacks are not empty. This is a win case for the game. If this is True then the user has completed the game.
		* \return Returns true if the user wins the game.
		*/
		bool is_win_state();


		/**
		*\param Category T c is either Tableau or Foundation. n is the nth stack in the categoryT c.
		* \brief Loacl function returns true if the nth position exists in the c.
		*/
		bool is_valid_pos(CategoryT c , int n);

		




};
	
#endif
