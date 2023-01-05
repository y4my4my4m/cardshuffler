#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

#define NUM_CARDS 52

int main(void) {
  char cards[13] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};
  // ♧, ♦, ♥, ♤
  wchar_t suits[4] = {9824, 9826, 9825, 9827};  // ASCII codes for the suits
  int i, j;

  wchar_t deck[NUM_CARDS][2];  // 2D array to store the cards and suits

  // Initialize the deck
  for (i = 0; i < 4; i++) {
    for (j = 0; j < 13; j++) {
      deck[i * 13 + j][0] = cards[j];  // Set the card
      deck[i * 13 + j][1] = suits[i];  // Set the suit
    }
  }

  srand(time(0));  // Seed the random number generator with the current time

  // Shuffle the deck
  for (i = 0; i < NUM_CARDS; i++) {
    int j = rand() % NUM_CARDS;  // Generate a random index
    wchar_t temp[2];               // Swap the cards at indices i and j
    temp[0] = deck[i][0];
    temp[1] = deck[i][1];
    deck[i][0] = deck[j][0];
    deck[i][1] = deck[j][1];
    deck[j][0] = temp[0];
    deck[j][1] = temp[1];
  }

  setlocale(LC_ALL, "");  // Set the locale to a Unicode-enabled one

  // Print the shuffled deck
  for (i = 0; i < NUM_CARDS; i++) {
    printf("%lc%lc ", deck[i][0], deck[i][1]);
  }

  return 0;
}

