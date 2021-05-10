#include <stdio.h>
#include <string.h>

// returns inputted string without last two laters
char* chunk_without_two(char* verb)
{
  verb[strlen(verb)-2] = 0;
	return verb;
}

// prints present positve conjugation
int pres_conj(char* verb, char letter)
{
  // singular
  printf("yes g'%s%cm\n", verb, letter);
  printf("toun g'%s%cs\n", verb, letter);
  printf("an g'%s%c\n", verb, letter);

  // plural
  printf("menk g'%s%cnk\n", verb, letter);
  printf("touk g'%s%ck\n", verb, letter);
  printf("anonk g'%s%cn\n", verb, letter);
  return 0;
}


int main(void) {



  // taking in input verb 

  char in_verb[25]; 
  printf("Enter a verb: ");
  scanf("%s", in_verb);
  //printf("Your verb is %s.\n", in_verb);

  // second last and last letters
  char second_last = in_verb[(strlen(in_verb)-2)];
  char let_last = in_verb[(strlen(in_verb)-1)];

  //getting input for tense
  
  char in_tense[25]; 
  printf("Enter a tense from the list:\npresent\n");
  scanf("%s", in_tense);

  // root of verb (without -xl ending)
  char* root = chunk_without_two(in_verb);
  char present[25] = "present";

  if (strcmp(in_tense, present) == 0){
    // calling present conugation function on input
    pres_conj(root,second_last);
  }

  //printf("\nenter 'exit' to exit the program or anything else to continue:\n");
  //scanf("%c", &check);

  






  return 0;
}