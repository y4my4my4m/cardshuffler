#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

#define NUM_CARDS 52

typedef struct {
  char value;
  wchar_t suit;
} Card;

int main(void) {
  char cards[13] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};
  // ♧, ♦, ♥, ♤
  wchar_t suits[4] = {9824, 9826, 9825, 9827};  // ASCII codes for the suits
  int i, j;

  Card deck[NUM_CARDS];  // Array of Card structs to represent the deck

  // Initialize the deck
  for (i = 0; i < 4; i++) {
    for (j = 0; j < 13; j++) {
      deck[i * 13 + j].value = cards[j];  // Set the card
      deck[i * 13 + j].suit = suits[i];  // Set the suit
    }
  }

  srand(time(0));  // Seed the random number generator with the current time

  // Shuffle the deck
  for (i = 0; i < NUM_CARDS; i++) {
    int j = rand() % NUM_CARDS;  // Generate a random index
    Card temp;                   // Swap the cards at indices i and j
    temp = deck[i];
    deck[i] = deck[j];
    deck[j] = temp;
  }

  setlocale(LC_ALL, "");  // Set the locale to a Unicode-enabled one

  // Print the shuffled deck
  for (i = 0; i < NUM_CARDS; i++) {
    printf("%c%lc ", deck[i].value, deck[i].suit);
  }

  return 0;
}

