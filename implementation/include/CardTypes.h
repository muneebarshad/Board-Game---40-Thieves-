/**
 * \file CardTypes.h
 * \author Muneeb Arshad
 * \brief Creates enum type of cards
 */

#ifndef A3_CARD_TYPES_H_
#define A3_CARD_TYPES_H_



/**
 * \brief Describes the rank of a card.
 */
typedef unsigned short int RankT;



/**
 * \brief RankT for an Ace.
 */
#define ACE  1

/**
 * \brief RankT for an Jack.
 */
#define JACK   11

/**
 * \brief RankT for a Queen.
 */
#define QUEEN  12

#define TOTAL_CARDS 104
/**
 * \brief RankT for a King.
 */
#define KING   13

/**
 * \brief Enums for SuitT defined
 */
enum SuitT{Heart,Diamond,Club,Spade};


/**
 * \brief Enums for CategoryT defined
 */
enum CategoryT{Tableau,Foundation,Deck,Waste};


/**
 * \brief Tuple of SuitT and RankT.
 */
struct CardT{
	SuitT s;
	RankT r;

};



#endif
