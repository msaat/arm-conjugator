#include <stdio.h>
#include <string.h>

// returns inputted string without last two laters
char* chunk_without_two(char* verb)
{
  verb[strlen(verb)-2] = 0;
	return verb;
}

// prints present positve conjugation if verb starts
//   with a vowel
int pres_conj_vow(char* verb, char letter)
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

// prints present positve conjugation if verb starts
//   with a consonant
int pres_conj_cons(char* verb, char letter)
{
  // singular
  printf("yes ge %s%cm\n", verb, letter);
  printf("toun ge %s%cs\n", verb, letter);
  printf("an ge %s%c\n", verb, letter);

  // plural
  printf("menk ge %s%cnk\n", verb, letter);
  printf("touk ge %s%ck\n", verb, letter);
  printf("anonk ge %s%cn\n", verb, letter);
  return 0;
}

int pres_conj_east(char* verb)
{
  // singular
  printf("yes %soum em\n", verb);
  printf("dou %soum es\n", verb);
  printf("na %soum e\n", verb);

  // plural
  printf("menk %soum enk\n", verb);
  printf("douk %soum ek\n", verb);
  printf("nrank %soum en\n", verb);
  return 0;
}


int main(void) {



while(1){
  // taking in input verb 

  char in_verb[25]; 
  char ex_key[25] = "exit";
  printf("\nEnter a verb or enter 'exit' to quit: ");
  scanf("%s", in_verb);
  // printf("Your verb is %s.\n", in_verb);

  if(strcmp(in_verb, ex_key) == 0) {
    break;
  }

  // second last and last letters
  char second_last = in_verb[(strlen(in_verb)-2)];
  char let_last = in_verb[(strlen(in_verb)-1)];

  // getting input for dialect

  char in_dialect[25]; 
  char eastern_dia[25] = "eastern";
  char western_dia[25] = "western";
  printf("Choose a dialect:\neastern, western\n");
  scanf("%s", in_dialect);

  // getting input for tense
  
  char in_tense[25]; 
  printf("Enter a tense from the list:\npresent\n");
  scanf("%s", in_tense);

  // root of verb (without -xl ending)
  char* root = chunk_without_two(in_verb);
  char present[25] = "present";

if ((strcmp(in_dialect, western_dia) == 0)) {
  if ((strcmp(in_tense, present) == 0) && ((in_verb[0] == 'a') || (in_verb[0] == 'e') || (in_verb[0] == 'i') || (in_verb[0] == 'o') || (in_verb[0] == 'u'))){
    // calling present conugation function on input 
    //   for verb starting with vowel
    pres_conj_vow(root,second_last);
  }
  else if ((strcmp(in_tense, present) == 0)){
    // calling present conugation function on input
    //  for verb starting with consonant
    pres_conj_cons(root,second_last);
  }
} 
else if ((strcmp(in_dialect, eastern_dia) == 0)){
  if ((strcmp(in_tense, present) == 0)){
    pres_conj_east(root);
  }
}

  //printf("\nenter 'exit' to exit the program or anything else to continue:\n");
  //scanf("%c", &check);

  
}



  return 0;
}