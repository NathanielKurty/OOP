# OOP
object oriented programming spring 2019

  The main abstraction for this project would be the deck of cards.  Since the game of war does not depend on the suits,
an array of numbers equal to the rank of cards are added. this array is then "shuffled" in order to provide a new deck 
everytime. A "card" is pulled from the top and bottom of the array to immitate the idea of two seperate decks between 
two seperate players. Cards are compared in order to find a winner or declare war.  War between two players deals with
two "face down" and two "face up" cards.  The face up cards are announced and compared.  Should the face up cards be 
the same, the face down cards are announced and compared.  In the rare chance the face down cards are also the same, 
the war ends in a draw. 
  The implementation of war varies based on the amount of cards in the deck. should there be only 1 card left in the deck,
war is waged with only those two cards.  Should there be no cards left in the deck, that round is simply decided as a draw.
The entirety of the game has dialogue announcing the rounds, winners, whether war is waged, and if a special case of war happens.
 
