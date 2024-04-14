#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

int squirtlehp = 50, charizardhp = 54, bulbasaurhp = 46;
int chardmg = 52, bulbadmg = 49, squirtdmg = 48;
int chardef = 43, bulbadef = 49, squirtdef = 65;
int charspd = 65, bulbaspd = 45, squirtspd = 43;
int charspatk = 60, bulbaspatk = 65, squirtspatk = 50;
int scratch = 40, tackle = 40, ember = 40, vinewhip = 45, watergun = 40;
float growl = 0.5, tailwhip = 0.5;
char charmandermoves[10][10] = {"Scratch","Growl","Ember"};
char squirtlemoves[10][10] = {"Tackle","Tail Whip","Water Gun"};
char bulbasaurmoves[10][10] = {"Tackle","Tail Whip","Vine Whip"};
int main(void){
	
	loadingscreen();
	sleep(1);
	newintro();
	sleep(1);
    housetolab();
    pickyourpokemon();
    system("cls");
    ending();
	return 0;
}

void pickyourpokemon(){
    bool hp = true;
    int crit, critelement;
    int lower = 1, upper = 7, lowerelement = 1, upperelement = 7;
    int lowerrival = 1, upperrival = 3;
    int pokechoice, move, damage, enemyattack;
    char yourpokemon[15] = "none";
    char rivalpokemon[15] = "none";
    speak("\n\t\tPick you desired pokemon: \n\t\t[1]charmander [2]bulbasaur [3]squirtle\n\t\t>");
    scanf("%d",&pokechoice);
    if(pokechoice == 1){
        strcpy(yourpokemon, " Charmander");
        charmander();
        strcpy(rivalpokemon, " Squirtle");
    }
    else if(pokechoice == 2){
        strcpy(yourpokemon, " Bulbasaur");
        bulbasaur();
        strcpy(rivalpokemon, " Charmander");
    }
    else if(pokechoice == 3){
        strcpy(yourpokemon, " Squirtle");
        squirtle();
        strcpy(rivalpokemon, " Bulbasaur");
    }
    speak("\t\tYou picked "); speak(yourpokemon);
    sleep(1);
    speak("\n\t\tYour rival: I see you've picked "); speak(yourpokemon);
    speak("\n\t\tYour rival: Then I will choose"); speak(rivalpokemon);
    sleep(1);
    speak("\n\t\tYour rival wanted to battle with you!\n");
    sleep(1);
    speak("\t\tYou are now battling you rival\n");
    sleep(1);
    system("cls");
    printf("\t\t\t     o                       o\n\
\t\t\t    <O--      O   O        --0>\n\
\t\t\t    / >                     </\n");
    speak("\t\tYou sent out "); speak(yourpokemon); printf("\n");
    sleep(1);
    speak("\t\tYour rival sent "); speak(rivalpokemon);printf("\n");
    sleep(1);
    system("cls");

    //--- CHARIZARD VS SQUIRTLE (CHARIZARD/YOU FIRST MOVE) ---

    if(pokechoice == 1){

        while(hp == true){
        printf("\n");
        printf("=============================\n");
        printf("||Your pokemon hp: %d      ||\n", charizardhp);
        printf("=============================\n");
        printf("||Your enemy pokemon hp: %d||\n", squirtlehp);
        printf("=============================\n||\t\t\t   ||\n");
        printf("|| [1] %s   ",charmandermoves[0]);
        printf("[2] %s ||\n||\t\t\t   ||\n", charmandermoves[1]);
        printf("|| [3] %s   ", charmandermoves[2]);
        printf("  [4] - \t   ||\n||\t\t\t   ||\n");
        printf("=============================\n");
        scanf("%d", &move);

            switch(move){

                //SCRATCH MOVE

                case 1:

                speak("You picked "); speak(charmandermoves[0]); printf("\n");

                //CRIT SYSTEM

                srand(time(0));

                int crit = (rand() % (upper - lower + 1)) + lower;

                //SCRATCH MOVE (NORMAL)

                if(crit > 1 && crit < 7){
                squirtlehp = squirtlehp - (chardmg/6);
                damage = chardmg / 6;
                speak(rivalpokemon); printf(" took %d damage!\n", damage);

                //SCRATCH MOVE (MISS)

                }else if(crit == 1){

                printf("Your attack missed\n");

                //SCRATCH MOVE (CRITICAL)

                }else if(crit == 7){

                printf(" A critical hit!");
                squirtlehp = squirtlehp - (chardmg/3);
                damage = chardmg/3;
                speak(rivalpokemon); printf(" took %d damage!\n", damage);
                }

                break;

                //GROWL MOVE

                case 2:

                speak("You picked "); speak(charmandermoves[1]); printf("\n");
                squirtdmg = squirtdmg * 0.8;
                speak(rivalpokemon); printf(" attack fell!\n");

                break;

                //ELEMENT ATTACK

                case 3:

                speak("You picked "); speak(charmandermoves[2]); printf("\n");

                //CRIT SYSTEM

                srand(time(0));

                int critelement = (rand() % (upperelement - lowerelement + 1)) + lowerelement;

                //ELEMENT ATTACK (NORMAL)

                if(critelement > 1 && critelement < 7){
                squirtlehp = squirtlehp - (chardmg/7);
                damage = chardmg / 7;
                speak(rivalpokemon); printf(" took %d damage!\n", damage);
                speak(charmandermoves[2]); speak(" is not very effective!\n");

                //ELEMENT ATTACK (MISS)

                }else if(critelement == 1){

                printf("Your attack missed\n");

                //ELEMENT ATTACK (CRITICAL)

                }else if(critelement == 7){

                printf("A critical hit!");
                squirtlehp = squirtlehp - (chardmg/5);
                damage = chardmg/5;
                speak(rivalpokemon); printf(" took %d damage!\n", damage);
                speak(charmandermoves[2]); speak(" is not very effective!\n");
                }


                break;

                }

                //HEALTH CHECK FOR RIVAL POKEMON

                if(squirtlehp <= 0){
                speak("\nSquirtle fainted\n");
                speak("You Won!\n");
                break;
                }

                //RIVAL TURN

                printf("\n");

                //MOVE RANDOMIZER

                srand(time(0));

                int enemyattack = (rand() % (upperrival - lowerrival + 1)) + lowerrival;

                switch(enemyattack){

                //TACKLE MOVE

                case 1:

                speak("Squirtle used "); speak(squirtlemoves[0]); printf("\n");

                //CRIT SYSTEM

                srand(time(0));

                int crit = (rand() % (upper - lower + 1)) + lower;

                //TACKLE MOVE (NORMAL)

                if(crit > 1 && crit < 7){

                charizardhp = charizardhp - (squirtdmg/6);
                damage = squirtdmg / 6;
                speak(yourpokemon); printf(" took %d damage!\n", damage);

                //TACKLE MOVE (MISS)

                }else if(crit == 1){

                speak(rivalpokemon); printf(" attack missed\n");

                //TACKLE MOVE (CRITICAL)

                }else if(crit == 7){

                printf("A critical hit!");
                charizardhp = charizardhp - (squirtdmg/3);
                damage = squirtdmg / 3;
                speak(yourpokemon); printf(" took %d damage!\n", damage);
                }

                break;

                //TAIL WHIP MOVE

                case 2:

                speak("Squirtle used "); speak(squirtlemoves[1]); printf("\n");
                squirtdmg = squirtdmg * 1.22;
                speak("Charmander's"); printf(" defence fell!\n");

                break;

                //ELEMENT ATTACK

                case 3:

                speak("Squirtle used "); speak(squirtlemoves[2]); printf("\n");

                //CRIT SYSTEM

                srand(time(0));

                int critelement = (rand() % (upperelement - lowerelement + 1)) + lowerelement;

                //ELEMENT ATTACK (NORMAL)

                if(critelement > 1 && critelement < 7){
                charizardhp = charizardhp - (squirtdmg/5);
                damage = squirtdmg / 5;
                speak(yourpokemon); printf(" took %d damage!\n", damage);
                speak(squirtlemoves[2]); speak(" is very effective!\n");

                //ELEMENT ATTACK (MISS)

                }else if(critelement == 1){

                speak(rivalpokemon); printf(" attack missed\n");

                //ELEMENT ATTACK (CRITICAL)

                }else if(critelement == 7){

                printf("A critical hit!");
                charizardhp = charizardhp - (squirtdmg/2.5);
                damage = squirtdmg/2.5;
                speak(yourpokemon); printf(" took %d damage!\n", damage);
                speak(squirtlemoves[2]); speak(" is very effective!\n");
                }

                break;

                }

                //HEALTH CHECK FOR YOUR POKEMON

                if(charizardhp <= 0){
                speak("\nCharmander fainted\n");
                speak("Your team got wiped out!\n");
                speak("You lost!\n");
                hp = false;
                } else if (charizardhp > 0){
                hp = true;
                }

                sleep(2);

                } //WHILE LOOP CLOSE

                } //CHARIZARD VS SQUIRTLE (CHARIZARDA/YOU FIRST MOVE) (CLOSING OF IF STATEMENT)

                //--- BULBASAUR VS CHARIZARD (CHARIZARD/RIVAL FIRST MOVE) ---

                else if(pokechoice == 2){

                while(hp == true){

                //MOVE RANDOMIZER

                srand(time(0));

                int enemyattack = (rand() % (upperrival - lowerrival + 1)) + lowerrival;

                switch(enemyattack){

                //SCRATCH MOVE


                case 1:

                speak("Charmander used "); speak(charmandermoves[0]); printf("\n");

                //CRIT SYSTEM

                srand(time(0));

                int crit = (rand() % (upper - lower + 1)) + lower;

                //SCRATCH MOVE (NORMAL)

                if(crit > 1 && crit < 7){
                bulbasaurhp = bulbasaurhp - (chardmg/6);
                damage = chardmg / 6;
                speak(yourpokemon); printf(" took %d damage!\n", damage);

                //SCRATCH MOVE (MISS)

                }else if(crit == 1){

                speak(rivalpokemon); printf(" attack missed\n");

                //SCRATCH MOVE (CRIT)

                }else if(crit == 7){

                printf("A critical hit!");
                bulbasaurhp = bulbasaurhp - (chardmg/3);
                damage = chardmg / 3;
                speak(yourpokemon); printf(" took %d damage!\n", damage);
                }

                break;

                //GROWL MOVE

                case 2:

                speak("Charmander used "); speak(charmandermoves[1]); printf("\n");
                bulbadmg = bulbadmg * 0.8;
                speak(yourpokemon); printf(" attack fell!\n");

                break;

                //ELEMENT ATTACK

                case 3:

                speak("Charmander used "); speak(charmandermoves[2]); printf("\n");

                //CRIT SYSTEM

                srand(time(0));

                int critelement = (rand() % (upperelement - lowerelement + 1)) + lowerelement;

                //ELEMENT ATTACK (NORMAL)

                if(critelement > 1 && critelement < 7){
                bulbasaurhp = bulbasaurhp - (chardmg/5);
                damage = chardmg / 5;
                speak(yourpokemon); printf(" took %d damage!\n", damage);
                speak(charmandermoves[2]); speak(" is very effective!\n");

                //ELEMENT ATTACK (MISS)

                }else if(critelement == 1){

                speak(rivalpokemon); printf(" attack missed\n");

                //ELEMENT ATTACK (CRITICAL)

                }else if(critelement == 7){

                printf("A critical hit!");
                bulbasaurhp = bulbasaurhp - (chardmg/2.5);
                damage = chardmg/2.5;
                speak(yourpokemon); printf(" took %d damage!\n", damage);
                speak(charmandermoves[2]); speak(" is very effective!\n");
                }

                break;

                }

                //HEALTH CHECK FOR YOUR POKEMON

                if(bulbasaurhp <= 0){
                speak("\nBulbasaur fainted\n");
                speak("Your team got wiped out!\n");
                speak("You lost!\n");
                break;
                }

                sleep(2);

                //YOUR TURN


                printf("\n");
                
                printf("\n");
                printf("=============================\n");
                printf("||Your pokemon hp: %2d      ||\n", bulbasaurhp);
                printf("=============================\n");
                printf("||Your enemy pokemon hp: %2d||\n", charizardhp);
                printf("||=========================||\n");
                printf("|| [1] - %s            ||\n",bulbasaurmoves[0]);
                printf("|| [2] - %s         ||\n", bulbasaurmoves[1]);
                printf("|| [3] - %s         ||\n", bulbasaurmoves[2]);
                printf("|| [4] -                   ||\n");
                printf("||=========================||\n");
                printf("=============================\n");

                scanf("%d", &move);

                switch(move){

                //TACKLE MOVE

                case 1:

                speak("You picked "); speak(bulbasaurmoves[0]); printf("\n");

                //CRIT SYSTEM

                srand(time(0));

                int crit = (rand() % (upper - lower + 1)) + lower;

                //TACKLE MOVE (NORMAL)

                if(crit > 1 && crit < 7){
                charizardhp = charizardhp - (bulbadmg/6);
                damage = bulbadmg / 6;
                speak(rivalpokemon); printf(" took %d damage!\n", damage);

                //TACKLE MOVE (MISS)

                }else if(crit == 1){

                printf("Your attack missed\n");

                //TACKLE MOVE (CRITICAL)

                }else if(crit == 7){

                printf(" A critical hit!");
                charizardhp = charizardhp - (bulbadmg/3);
                damage = bulbadmg/3;
                speak(rivalpokemon); printf(" took %d damage!\n", damage);
                }

                break;

                //TAIL WHIP MOVE

                case 2:

                speak("You picked "); speak(bulbasaurmoves[1]); printf("\n");
                bulbadmg = bulbadmg * 1.22;
                speak(rivalpokemon); printf(" defence fell!\n");

                break;

                //ELEMENT ATTACK

                case 3:

                speak("You picked "); speak(bulbasaurmoves[2]); printf("\n");

                //CRIT SYSTEM

                srand(time(0));

                int critelement = (rand() % (upperelement - lowerelement + 1)) + lowerelement;

                //ELEMENT ATTACK (NORMAL)

                if(critelement > 1 && critelement < 7){
                charizardhp = charizardhp - (bulbadmg/7);
                damage = bulbadmg / 7;
                speak(rivalpokemon); printf(" took %d damage!\n", damage);
                speak(bulbasaurmoves[2]); speak(" is not very effective!\n");

                //ELEMENT ATTACK (MISS)

                }else if(critelement == 1){

                printf("Your attack missed\n");

                //ELEMENT ATTACK (CRITICAL)

                }else if(critelement == 7){

                printf("A critical hit!");
                charizardhp = charizardhp - (bulbadmg/5);
                damage = bulbadmg/5;
                speak(rivalpokemon); printf(" took %d damage!\n", damage);
                speak(bulbasaurmoves[2]); speak(" is not very effective!\n");
                }


                break;

                }

                //HEALTH CHECK FOR RIVAL POKEMON

                if(charizardhp <= 0){
                speak("\nCharmander fainted\n");
                speak("You won!!\n");
                hp = false;
                } else if (charizardhp > 0){
                hp = true;
                }

                sleep(2);

                } //WHILE LOOP CLOSE

                } //BULBASAUR VS CHARIZARD (CHARIZARD/RIVAL FIRST MOVE) (CLOSING OF IF STATEMENT)


                //--- SQUIRTLE VS BULBASAUR (BULBASAUR/RIVAL FIRST MOVE) ---

                else if(pokechoice == 3){

                //MOVE RANDOMIZER

                while(hp == true){

                srand(time(0));

                int enemyattack = (rand() % (upperrival - lowerrival + 1)) + lowerrival;

                switch(enemyattack){

                //TACKLE MOVE

                case 1:

                speak("Bulbasaur used "); speak(bulbasaurmoves[0]); printf("\n");

                //CRIT SYSTEM

                srand(time(0));

                int crit = (rand() % (upper - lower + 1)) + lower;

                //TACKLE MOVE (NORMAL)

                if(crit > 1 && crit < 7){
                squirtlehp = squirtlehp - (bulbadmg/6);
                damage = bulbadmg / 6;
                speak(yourpokemon); printf(" took %d damage!\n", damage);

                //TACKLE MOVE (MISS)

                }else if(crit == 1){

                speak(rivalpokemon); printf(" attack missed\n");

                //TACKLE MOVE (CRITICAL)

                }else if(crit == 7){

                printf("A critical hit!");
                squirtlehp = squirtlehp - (bulbadmg/3);
                damage = bulbadmg / 3;
                speak(yourpokemon); printf(" took %d damage!\n", damage);
                }

                break;

                //TAIL WHIP MOVE

                case 2:

                speak("Bulbasaur used "); speak(bulbasaurmoves[1]); printf("\n");
                bulbadmg = bulbadmg * 1.22;
                speak(yourpokemon); printf(" defence fell!\n");

                break;

                //ELEMENT ATTACK

                case 3:

                speak("Bulbasaur used "); speak(bulbasaurmoves[2]); printf("\n");

                //CRIT SYSTEM

                srand(time(0));

                int critelement = (rand() % (upperelement - lowerelement + 1)) + lowerelement;

                //ELEMENT ATTACK (NORMAL)

                if(critelement > 1 && critelement < 7){
                squirtlehp = squirtlehp - (bulbadmg/5);
                damage = bulbadmg / 5;
                speak(yourpokemon); printf(" took %d damage!\n", damage);
                speak(bulbasaurmoves[2]); speak(" is very effective!\n");

                //ELEMENT ATTACK (MISS)

                }else if(critelement == 1){

                speak(rivalpokemon); printf(" attack missed\n");

                //ELEMENT ATTACK (CRITICAL)

                }else if(critelement == 7){

                printf("A critical hit!");
                squirtlehp = squirtlehp - (bulbadmg/2.5);
                damage = bulbadmg/2.5;
                speak(yourpokemon); printf(" took %d damage!\n", damage);
                speak(bulbasaurmoves[2]); speak(" is very effective!\n");
                }

                break;

                }

                //HEALTH CHECK FOR YOUR POKEMON

                if(squirtlehp <= 0){
                speak("\nSquirtle fainted\n");
                speak("Your team got wiped out!\n");
                speak("You lost!\n");
                break;
                }

                sleep(2);
                printf("\n");

                printf("\n");
                printf("=============================\n");
                printf("||Your pokemon hp: %2d      ||\n", squirtlehp);
                printf("=============================\n");
                printf("||Your enemy pokemon hp: %2d||\n", bulbasaurhp);
                printf("=============================\n");
                printf("||=========================||\n");
                printf("|| [1] %s              ||\n",squirtlemoves[0]);
                printf("|| [2] %s           ||\n", squirtlemoves[1]);
                printf("|| [3] %s           ||\n", squirtlemoves[2]);
                printf("|| [4] -                   ||\n");
				printf("||=========================||\n");
                printf("=============================\n");

                scanf("%d", &move);

                switch(move){

                //TACKLE MOVE

                case 1:

                speak("You picked "); speak(squirtlemoves[0]); printf("\n");

                //CRIT SYSTEM

                srand(time(0));

                int crit = (rand() % (upper - lower + 1)) + lower;

                //TACKLE MOVE (NORMAL)

                if(crit > 1 && crit < 7){
                bulbasaurhp = bulbasaurhp - (squirtdmg/6);
                damage = squirtdmg / 6;
                speak(rivalpokemon); printf(" took %d damage!\n", damage);

                //TACKLE MOVE (MISS)

                }else if(crit == 1){

                printf("Your attack missed\n");

                //TACKLE MOVE (CRITICAL)

                }else if(crit == 7){

                printf(" A critical hit!");
                bulbasaurhp = bulbasaurhp - (squirtdmg/3);
                damage = squirtdmg/3;
                speak(rivalpokemon); printf(" took %d damage!\n", damage);
                }

                break;

                //TAIL WHIP MOVE

                case 2:

                speak("You picked "); speak(squirtlemoves[1]); printf("\n");
                squirtdmg = squirtdmg * 1.22;
                speak(rivalpokemon); printf(" defence fell!\n");

                break;

                //ELEMENT ATTACK

                case 3:

                speak("You picked "); speak(squirtlemoves[2]); printf("\n");

                //CRIT SYSTEM

                srand(time(0));

                int critelement = (rand() % (upperelement - lowerelement + 1)) + lowerelement;

                //ELEMENT ATTACK (NORMAL)

                if(critelement > 1 && critelement < 7){
                bulbasaurhp = bulbasaurhp - (squirtdmg/7);
                damage = squirtdmg / 7;
                speak(rivalpokemon); printf(" took %d damage!\n", damage);
                speak(squirtlemoves[2]); speak(" is not very effective!\n");

                //ELEMENT ATTACK (MISS)

                }else if(critelement == 1){

                printf("Your attack missed\n");

                //ELEMENT ATTACK (CRITICAL)

                }else if(critelement == 7){

                printf("A critical hit!");
                bulbasaurhp = bulbasaurhp - (squirtdmg/5);
                damage = squirtdmg/5;
                speak(rivalpokemon); printf(" took %d damage!\n", damage);
                speak(squirtlemoves[2]); speak(" is not very effective!\n");
                }


                break;

                }

                //HEALTH CHECK FOR RIVAL POKEMON

                if(bulbasaurhp <= 0){
                speak("\nBulbasaur fainted\n");
                speak("You won!!\n");
                hp = false;
                } else if (bulbasaurhp > 0){
                hp = true;
                }

                sleep(2);

                } //WHILE LOOP CLOSE

                } //SQUIRTLE VS BULBASAUR (BULBASAUR/RIVAL FIRST MOVE) (CLOSING OF IF STATEMENT)
                battleframe();

}
void housetolab(){
    int tolab;
    speak("\n\n\t\tThe professor wanted you to go to the lab\n");
    speak("\t\tPress [1] to go to the laboratory\n\t\t>");
    scanf("%i", &tolab);
    walkingman();
    system("cls");
    printf("\n\n\t\t\t     o                       o\n\
\t\t\t    <O--      O O O        --0>\n\
\t\t\t    / >                     </");
    speak("\n\n\n\t\tYou have arrived at the professor's laboratory\n");

}
void walkingman(){
    char man1[] =
    "\n\n\t\t\t     o   \n\
\t\t\t    <O-- \n\
\t\t\t    / > ";
    char man2[] =
        "\n\n\t\t\t     o   \n\
\t\t\t    /O> \n\
\t\t\t    > \\ ";
int i;
    for(i = 0; i<10; i++){
        system("cls");
        printf("%s",man1);
        usleep(100000);
        system("cls");
        printf("%s",man2);
        usleep(100000);
    }
}
void speak(char sentence[]){
	int i;
	int length = strlen(sentence);
	for(i=0;i<length;i++){
		printf("%c",sentence[i]);
		char letter = sentence[i];
		if(letter=='\n'){
			sleep(1);
		}
		usleep(30000);
	}
}
void speakfast(char sentence[], int delay){
	int i;
	int length = strlen(sentence);
	for(i=0;i<length;i++){
		printf("%c",sentence[i]);
		char letter = sentence[i];
		usleep(delay);
	}
}
void battleframe(){
    printf("\t     o                       o\n\
\t    <O--      O   O        --0>\n\
\t    / >                     </\n");
}
void newintro(){
	char prompts[7][200] = {
"\n\n\t\tHi there!\n\t\tMy name is Professor Juniper.\n\
\t\tEveryone calls me the Pokemon Professor\n",

"\n\n\t\tThat's right! This world is widely\n\
\t\tinhabited by mysterious creatures called pokemon\n",

"\n\n\t\tPokemon have mysterious powers. They come in \n\
\t\tmany shapes and live in many different places.\n",

"\n\n\t\tWe humans live happily with Pokemon!\n\
\t\tLiving and working together,\n",

"\n\n\tWe complement each other and help accomplish various tasks.\n\
\tHaving Pokemon battle one another is particularly popular\n",

"\n\n\t\tAnd that is why I research pokemon\n\
\t\tWell that's enough for me...\n\
\t\tCould you tell me about yourself?\n"
};
	int gender,i,resp = 2;
	char yourname[12], rivalname[12];
	speak("PLEASE MAXIMIZE THE TERMINAL WINDOW AT THE RIGHT OR LEFT SIDE OF THE SCREEN FOR BETTER EXPERIENCE :P\n");
	for(i = 0; i<10; i++){
		speak(" . . ."); usleep(400000);
	}
	for(i = 0; i<7; i++){
		system("cls");
		professor();
		speak(prompts[i]);
		sleep(1);
		system("cls");
	}
	while(1){
		professor();
		speak("\n\n\t\t\tAre you a boy? or a girl?\n\t\t\t[1]BOY [2]GIRL\n\t\t\t>");
		scanf("%d",&gender);
		system("cls");
		switch(gender){
			case 1:
				system("cls");
				boy();
				speak("\n\t\t\tSo, You are a Boy?\n");
				break;
			case 2:
				system("cls");
				girl();
				speak("\n\t\t\tSo, You are a Girl?\n");
				break;
		}
		speak("\t\t\t[1]Yes [2]No\n\t\t\t>");
		scanf("%d", &resp);
		if(resp == 1){
			system("cls");
			break;
		}
	system("cls");
	}
	professor();
	speak("\n\n\t\tI'd like to know your name. Please tell me.\n\t\t>");
	scanf("%s",&yourname);
	system("cls");
	professor();
	speak("\n\n\t\t\tSo your name is "); speak(yourname);
	speak("\n\t\t\tWhat a wonderful name!");
	sleep(1);
	system("cls");
	professor();
	speak("\n\n\tCould you also tell me the name of your cousin right there?\n\t>");
	scanf("%s",&rivalname);
	system("cls");
	professor();
	speak("\n\n\t\tOK! ");speak(yourname);speak(" and "); speak(rivalname);
	speak("\n\t\tYour journey as a pokemon trainer will now begin.");
	sleep(1);
	system("cls");
	speakfast("\n\
\t\t               ZZZ__Z____$ \n\
\t\t              Z____ZZ___$$$ \n\
\t\t            ZZ____ZZ___$$$$$ \n\
\t\t            Z___ZZ____$$   $$ \n\
\t\t            $$$$_____$$     $$ \n\
\t\t            $__$____$$       $$ \n\
\t\t            $__$___$$    #    $$ \n\
\t\t          $$$$$$$$$$    ###    $$ \n\
\t\t         $ZZZZZZZ$$      #      $$ \n\
\t\t        $ZZZZZZZ$$               $$ \n\
\t\t       $ZZZZZZZ$$                 $$ \n\
\t\t      $ZZZZZZZ$$  $$$$$$$_$$$$$$$  $$ \n\
\t\t      $$_$|$_$$    $_$$$_$_$_$$$_$  $$ \n\
\t\t      $$_$|$_$$   $$$$$$$_$$$$$$$   $$ \n\
\t\t    $$$$$$$$$$$_____________________$$ \n\
\t\t   $ZZZZZZZZZZ$$$$$$$$$$$$$$$$$$$$$$$$ \n\
\t\t  $ZZZZZZZZZZZ$ZZZZZZZZZZZZZZZZZZZZZZ$ \n\
\t\t$ZZZZZZZZZZZ$ZZZZZZZZZZZZZZZZZZZZZZZZ$ \n\
\t\t$ZZZZZZZZZZZ$ZZZZZZZZZZZZZZZZZZZZZZZZZZ$ \n\
\t\t$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ \n\
\t\t  $$_$__$__$___$$__$ZZZZ$___$$_$__$__$_$$ \n\
\t\t  $$_$__$__$___$$__$_ZZ_$___$$_$__$__$_$$ \n\
\t\t  $$ZZZZZZZZZZZ$$__$___#$___$$ZZZZZZZZZ$$ \n\
\t\t  $$_#_#_#_#_#$$_ $_ZZ_$___$$#_#_#_#_$$ \n\
\t\t  $$#_#_#_#_#_$$__$$$$$$___$$_#_#_#_#$$ \n\
\t\t$$$$$$$$$$$$$$$$##########$$$$$$$$$$$$$$$\n",1000);
sleep(2);

}
void professor(){
	printf("\n\
\t                       :+    :-++++--.       \n\
\t .:                   =**+=+*+++++++++*=.     \n\
\t .:                   :*+++**++++++++***-    \n\
\t .:                    -*++++++++++++**-      \n\
\t ..                  .=++++++++++++++++++.       \n\
\t                     *++*+*+++++++***++++*        \n\
\t                     *+#+*++++++++::=+++++*         \n\
\t                     .**#++++*+:..:=-=*****          \n\
\t                      .+#**+=+=..::+=:#+**.          \n\
\t                       .=*-=::.....:.-=++.           \n\
\t                     ...=*%=-:::::--=**=.::-        \n\
\t                     =-::-=--*+=--+====:..=          \n\
\t             :::       :==:..-=-+==-::..-:           \n\
\t          .=**+#*-     -::-=.:===-=*-.:++.            \n\
\t         :-#+=-=+*    ::..:.-.+----: .=+*.            \n\
\t         +-+-===+=:  :.....:..-+      .-=.            \n\
\t          :=++===+=*::....=-:::#::::::-=+.           \n\
\t             .**+++*:...:--#--*-:--::-+**.           \n\
\t              .+=+=...::--:=-=:      ==#+*.            \n\
\t                :-+----: .+:-         -=+-+-             \n\
\t                        --.:.          --*-+-               \n\
\t                      :-..:=:      :::==*=*=+.               \n\
\t                     ::..:**+++++++++++++++*#=.              \n\
\t                    -....+*+++++++++++++++*+*=+.             \n\
\t                   -....+#+++++++++++++++++*+***.    		\n\
\t                  :....+**++++++*+++++++++*#==+#-            \n\
\t              .::-....+#*++++++++++*++++++**-:-=*:          \n\
\t            .:....::.+##*+++++++++*+++++++#+-::-=*:         \n\
\t           .:.....-.+++#*+++++++++++++++++#++-::-++.       	\n\
\t          .-.....-.++++#++++++++++++++***#+=+=---=*=      	\n\
\t          -....::.+++++*=+****+***+==--:-++++++++++#:       \n\
\t         ::...-..-*=++++...:---+++--::..-++++++++++*:    \n\
\t         =..::...#+++++-......=+++:.....-+=+++++++++#     \n\
\t        -=-:....*+=+=++:.....:++=+:.....=+=+++++++=+#      \n\
\t        +:.....=*+++=++:.....+++++:....:++++++++++++#   \n\
\t       -=......+++++++=.....-#++=++....-*+==+++++++*-    \n\
\t       -=.....-*+++++=..:..:=*++*++---.-*==*+++++++*.  	   \n\
\t       -=.....==::-++.....::+::::=-----+.   .::-++#-     \n\
\t       :=....:*     =......*.   -+----=*         ...        \n\
\t........:=-..:*......=.....*....-+----=*....................\n\
\t::::::::::-===+::::::-:...=-:::::+=---=*::::::::::::::::::::\n\
\t:::::::::::::::::::::==...+=:::::-*---#--:::::::::::::::::::\n\
\t---------------------++..-+-------++--#---------------------\n\
\t=====================++..=*========#--#=====================\n\
\t++++++++++++++++++++++=..=*++++++++#--*+++++++++++++++++++++\n\
\t++++++++++++++++++++++:.:=*+++++++*=--=#*+++++++++++++++++++\n\
\t*********************+----*#******=-==+*####****************\n\
\t#####################*+++++*#####+:=*+=::. :=###############\n\
");
}
void boy(){
	printf("\n\
\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n\
\t                                                            \n\
\t                              .-:                           \n\
\t                         .:=+*###@+.                        \n\
\t                      :=***+=+++++***+=                     \n\
\t      .             =#*+++**####*******#*:                  \n\
\t      ..           =#*++**########******=++                 \n\
\t      ..           +#***##########******-.#-                \n\
\t                   +#*****######********--@-                \n\
\t::--:::::::-:::----##*****###########***=+#-::::::::::::::::\n\
\t==============+#----+#*###########@##@##*@*=================\n\
\t==----====---=#=--:=@@#**+@#++++**#*=#####@#*#@+===----====-\n\
\t--====----==+#-::::+@@#:-#@=---==##-:########*+----====----=\n\
\t=-----====-=#::---+#@@#=.-=::....--:+####@@#+--====----====-\n\
\t-=====----=**..:++**#@@#:...:......=#@@@@@#====----====----=\n\
\t=-----=====#-..:+*#@@@@@*-:.:.::.:+#@@@@@@@+---====----====-\n\
\t-====----+@#:.-*@====**+*@@*+--=+@@@@@@@#======---=====----=\n\
\t-=====--=#*#**#@*-====-=*@@@@****@@###@*+=-====----====----=\n\
\t=-----==@@****#@+=--**#@@#*#**+******###@#=----====----====-\n\
\t-======#++***#+@*-+#@@@@@@#*##********######+==----====----=\n\
\t==---=**:::---+#+##*#@@@@##*+*******##****=-#=-====----====-\n\
\t=====*#-:-----###***##@####*:+**####*****=:-+#==============\n\
\t====+#=------=**++++#######*+####******+=::--#*=============\n\
\t+===#+--::----=++++**=*####**#*******=---:::-=@++++====++++=\n\
\t+++*@-:::::::-=++*##*--+******#**+=-::-----:::+#++++++++++++\n\
\t++++#+-::::::-*###+**:::-+******-:::--=+-:--::-*#+++++++++++\n\
\t++***##=----+@#*++*#=:::::+******=:::--=+---:::-#*+****++++*\n\
\t*******######******#------=-#*####+=---+@=::::::+@**********\n\
\t******************#@==----=:+*#####*+--#@#-:::::-##*********\n\
\t####################------=:=-+######+*#***------=@#########\n\
\t..................*+=----==-=--+*###*##*-***+++==-=##.......\n\
\t                 :#=-----=+*----=+######*=+#+=------#       \n\
\t                 ++=----=-@@:=----+#######**--------#       \n\
\t                :*=-----==@@=------=*#####+---::::-*#-      \n\
\t................#==----=:#@@#:=------*##@+--::::-=*#*@+.....\n\
\t:::::::::::::::++------=-####-------++*#@###*+-=+#####@=::::\n\
\t--------------=#------=:=-:::-:=--:--++*##@@###*@@#####=----\n\
\t==============*@+++==-=:+====+=----=+##*###@@@@@@@@@@+======\n\
\t++++++++++++++#@###########@###########*=+@@@@@@@@#*++++++++\n\
\t**************@###########################@#####**+*********\n\
\t************#@@###########################@##***************\n\
\t@@@@@@@@@@@@@@############@################@@@@@@@@@@@@@@@@@\n\
\t@@@@@@@@@@@@@@############@@@##############@@@@@@@@@@@@@@@@@\n\
\t@@@@@@@@@@@@@@############@@@@#############@@@@@@@@@@@@@@@@@\n");
}
void girl(){
	printf("\n\
\t                 .:===-.      .-====:.                      \n\
\t               :*#****###*: .+##**#####                     \n\
\t              =**=-=*@@####*@**#@+:   .                     \n\
\t         :       :*#***#**#####*###*.                       \n\
\t         :      +#*****####**######@@-                      \n\
\t         .     =@#########*=--==+#####                      \n\
\t.......     ...+######@*:    .:::.:=#@......................\n\
\t***###**+++*##*@#####*-    .=+++**=..+#*####****####****###*\n\
\t*******+*+******@####:.    :+++****-.:#+*****+*+************\n\
\t***++++***++++*#@@##* .     .-+**+-::-@@*+++****++++****+++*\n\
\t+++****++++**#@######...:--====++***+*@@@#**++++****++++***+\n\
\t***++++*****@########==*#*+**+++**##*##@@+++****++++****+++*\n\
\t+++****++++*@@#######-+#*-*+:::-+**=+@###***++++****++++***+\n\
\t***++++****++#@@####@**##:-:...:.-::*@@*++++****++++****+++*\n\
\t+++****+++**#@@@@###@@@##:.....:...=#@@+****++++****++++***+\n\
\t***++++****++#@@@#@@@#*#@*=::..::-+@@#@@*+++****++++****+++*\n\
\t+++****+++****#@@@@@#####@@#+==*@@@@@###@#**++++****++++***+\n\
\t****************#@@**#####@#+++@@@@####**@#*****************\n\
\t*****************#@@#####@@**=--#@@######@#*****************\n\
\t*****************##+=*##@@@#*+-:-#@@###@@#******************\n\
\t###****###****#*=:...-*###@#@*+: -#@##*++#######****###*****\n\
\t***####***##+-.....:=####@###*-+:.##@##++=++*##*####****####\n\
\t###***#@@*-.....-+###@@@@#@@@*:=++#@@@@#*+=-:.-+*#######***#\n\
\t######@+.....=*#########@@@@@*::-+#@@@###@#*-:...:=#########\n\
\t@@####@*....:*@##@####@@@@#@@* ..:**@@@@####@@+....+@#@#####\n\
\t#########=....-#@#######@@@@@*    =#*@@@####@@-::-+@########\n\
\t         =#:....-+-.   #@##@@+    :@#*##.   #===+*+         \n\
\t           :#=....+@*==@**##@+    .*@*##*-=@#*++#-          \n\
\t             :=*=+###@#*::-*#+     +#@@*####@@#+:           \n\
\t              .:=*@@@##+====#=     -####+++*@@#             \n\
\t...................-+#+====+-       ::..=++**#*:............\n\
\t:::::::::::::::::::::-*-==-:.           .+*+***@=:::::::::::\n\
\t=====================#*++++++++=+=-------+#+****@+==========\n\
\t++++++++++++++++++++*@++++*******+=**++***#*****#@++++++++++\n\
\t********************@+=-===+++++*++*+++++++******#@*********\n\
\t####################**+=-==+++++****+++*+--=#**##@@#########\n\
\t@@@@@@@@@@@@@@@@#=: ..-=-=*+++++#**++++*++*+::*@@@@@@@@@@@@@\n\
\t@@@@@@@@@@@@@@@@#*.      ::..:-*@@=--::-..:   .+@@@@@@@@@@@@\n\
\t@@@@@@@@@@@@@@@@@-   .:.-:....=@@@-.....: ..  :@@@@@@@@@@@@@\n");
}
void charmander(){
    speakfast("\n\t                         :::----:\n\
\t                      :-==+++++++*+-.\n\
\t                    :+++++++**++++++*=\n\
\t              :==+**+++++++*=-==+++++++\n\
\t            :**+++++++++++#=#=@=*++++++=\n\
\t            *=###**++++++##=@=#**+++++++\n\
\t            :=#######*+++***#*#*+++++++=\n\
\t             .+==#####=*++++++++++++++*.             .:\n\
\t                -*=#=*+*#***+++++++++++           .----.\n\
\t          =-     +=#+===*#*++++++++++*:           -----:.\n\
\t        =*++*+-=#====*+**++++++++++++*  ..::::  .:---+*==.\n\
\t       .*++++++*###***+++**+++++++**++=+++++++  ----=****-\n\
\t         -*+++++******#****++++**+===++++++++*:.----=****:\n\
\t          :*++++++++#*++**++++++++++++++++++*=  :=*******.\n\
\t           .=*+++++*:::::-*++++++++++++++*=:     ..=***=.\n\
\t             .+*+**::::::::*+++++++++**=:           *+=\n\
\t               .-*::::::::::#+++++*****             *+=\n\
\t                -:::::::::::=*++++++++*:           :***\n\
\t                =::::::::::::*++++++++++          .*+*+\n\
\t               -:::::::::::::*+++++++++*         -*+*+=\n\
\t           .:::+:::::::::::::*+++++++++*.     .-*++*+=\n\
\t         -==+++*=:::::::::::=**++++++++*=:--=*++++*+=.\n\
\t        --=+++++#::::::::::=**+++++++++**+++++++**==.\n\
\t.::...  =++++*****:::::::-**+++++++++++#**+++**+==-\n\
\t.--:***+*++********+::::-*++++++++++++##****+=-=-.\n\
\t   :+*+++++*********#+=-***+++++++++**#==---=-:\n\
\t     .=*********+=:.   :-****++++******=--:.\n\
\t        -+*****.         :**********+.\n\
\t          :=++:            +*******#\n\
\t                          .********#\n\
\t                          :*-*#-*#-#\n\
\t                            -..-::- \n", 1000);
}
void squirtle(){
    speakfast("\t                    ......:...\n\
\t                 .::...:::::::-:.\n\
\t               :-:...:::::-:::::--.\n\
\t               =::::::::::+. =-----:\n\
\t              ++:::::::::+@#*==------\n\
\t             .*-:::::::::#@@#+------+\n\
\t             --::::::::::====-=-----=.\n\
\t            :=-::--------::::--=----+\n\
\t             :====-------======----=.\n\
\t               ------------------==-.\n\
\t               .-===-----------=+=:++=.\n\
\t          .::-:::---==========-:--=+*+=:\n\
\t       .:::.:::--...:------=-..:::--++*+:\n\
\t    :---::::::-:.:::::::::=-:.::::---*+++.\n\
\t    .=-=-:::::-......:=::-=:-::::---+=+===\n\
\t   .----===--+-.....:::::=:--=::---=--+=-=\n\
\t             --:..:::-::==------==+:.=+==+\n\
\t             :.=:--::-::::---===--=: *+++*      ....\n\
\t             :-:::::-=:----:------=:.+++*=  .::-::::--:\n\
\t            :-=.:::::-:::::::-==--=--=*+*. -::::::------\n\
\t           -:.:-:::::=.::::--=-::::::=*+-:=----=====---=:\n\
\t          :...::==---=------=:::::::::+==-----==-------=.\n\
\t          -..:::-===---====+::::::::::==------+--------=\n\
\t          -::------=-:::--==+::..:::::-=------===----=-\n\
\t         -=:----=-=.        .-::::::---=---==---=+=-:.\n\
\t         .-:===-:.            =-------=:     ....\n\
\t            .                 --==--==-:\n\
\t                               .  :-: ..\n", 1000);
}
void bulbasaur(){
    speakfast("\t                                              .=- .:-\n\
\t                                            :-=-++-==..\n\
\t                            .::----------===---==--*++-\n\
\t                        :-=-::::-----===----------=+==\n\
\t                      :+----------===-------------+++=\n\
\t       .:::::.       -+==------=++=---------------+++*.\n\
\t      :-:::-------------=-==---::::+-------------==+==+\n\
\t     :--::..:::.::--===::::::::::::-+----------====++==+.\n\
\t     +=::...:-==++++++-:::::::::::--+-----======++++++==+:\n\
\t    --::::::-++++++=-:::::::::::::--=*=======+++++===*===+.\n\
\t   -:-:::-=-::===-::::::::::::::::---*+===++++=++++++++===+\n\
\t  --:+==:=+-::::::::::-::--*#*=::---=+=++++=++++++====*====-\n\
\t -= =+=-::::::=+*-:::=::-.-++=#+:-==-=+-=++++++=======+====+\n\
\t =..*:-::::::=++*::::::=  ++- =#+==---+=++***+======++=====*\n\
\t-- .*:-:::::::-==:::::-.  #*= +**-----===*+++***+++++=====++\n\
\t+:::#+=:::::::::::::::=   +**++**-========*+++++**++======*.\n\
\t+=-::-::::::::::::::::=-:.-+===============**+++*+=++===+*-\n\
\t -++==-:-::::-:::::::::::::--===+====================*++-\n\
\t   :==+**++=======++++++++*++======+=--------====---==*\n\
\t      :===+++===-======+++===--=+=--::::::-+-==-:---====\n\
\t       --====++=+==+=========+++-:::-:::::-+==-=++*-====.\n\
\t       -:::-=====+++++++++====*-::=++-:::--*==++++*======\n\
\t       .==+==+---=+==========+===+--=-::---+::+++**+=====\n\
\t        ====+*------=+-=++++=*===+:::::---#----=+++======\n\
\t         +===-------=   .=++#++++=::::--=**============+\n\
\t          +-------==      =-*+++=:::---=:  -===========:\n\
\t          -+-++==-.        .=:--:----=-     -=++=+==+=.\n\
\t                           ..:-:----:          .. ..\n", 1000);
}
void ending(){
	int i;
	for(i=0;i<100;i++){
		printf("\n");
	}
	speak("\t\t\tTHANK YOU FOR PLAYING OUR GAME!\n\n\n");
	speak("\t\t\tMADE BY:\n\n\n");
	speak("\t\t\tKENT ALBORES\n\n\n");
	speak("\t\t\tHARROLD RESMA\n\n\n");
	speak("\t\t\tMARC SHANE ANCAJAS\n\n\n");
	for(i=0;i<100;i++){
		printf("\n");
		usleep(700000);
	}
}
void loadingscreen(){
	int i,j,k=0;
	for(i=0;i<260;i++){
		printf("\n\n\n\n\n\n\n\t");
		for(j=0;j<i;j++){
			printf(" ");
		}
		if(i>=50){
			i=0;
			k++;
		}
		printf("LOADING GAME");
		usleep(10000);
		system("cls");
		
		if(k>=5){
			break;
		}
	}
}
