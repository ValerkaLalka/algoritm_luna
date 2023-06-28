#include <stdio.h>
enum CardType
{
  type_master_card,
  type_visa,
  type_american_express,
  type_other
};
 
static char* EmitentNames[] = {"Master Card", "VISA", "American Express", "Other"};
 
int GetFirstTwoDigits(const int* const cardNumber)
{
  return (cardNumber[0] * 10 + cardNumber[1]);
}
 
enum CardType GetCardType(const int* const cardNumber)
{
  enum CardType type;
 
  int firstTwoDigits = GetFirstTwoDigits(cardNumber);
 
  if ((firstTwoDigits >= 51) && (firstTwoDigits <= 55))       type = type_master_card;
  else if (firstTwoDigits / 10 == 4)                          type = type_visa;
  else if ((firstTwoDigits == 34) || (firstTwoDigits == 37))  type = type_american_express;
  else                                                        type = type_other;
  return type;
}
 
int Luhn(const int* const cardNumber, const int cardNumberLength)
{
  int validationFlag = 0;
  int p = 0;
  int sum = 0;
  int i = 0;
 
  for (i = cardNumberLength - 1; i > -1; i--)
  {
    p = cardNumber[i];
 
    if ((i + 1) % 2 == 0) p = p * 2;
 
    if (p > 9) p = p - 9;
 
    sum = sum + p;
  }
 
  if (sum % 10 == 0) validationFlag = 1;
 
  return validationFlag;
}
 
void VerifyCard(const int* const cardNumber, const int cardNumberLength)
{
  if (Luhn(cardNumber, cardNumberLength))
    printf("This is a VALID credit card. Emitent: %s\n", EmitentNames[GetCardType(cardNumber)]);
  else
    printf("This card is INVALID!\n");
}
 
int main(void)
{
  int card[] = {3, 7, 8, 7, 3, 4, 4, 9, 3, 6, 7, 1, 0, 0, 0};
 
  VerifyCard(card, sizeof(card)/ sizeof(*card));
 
  return 0;
}