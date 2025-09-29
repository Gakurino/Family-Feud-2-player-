/******************************************************************
		LIBRARIES Used
			stdio.h - Where inputs and outputs occur
			stdlib.h - Where rand() came from.
            unistd.h - so that i can acess the sleep() (delays) and system("cls")(clears the command console) commands.

*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define MAX_QUES 12

// Functions prototypes
void MainMenu();
void HowtoPlay();
char* numchoices(int Question, int *Answers);
int randomInRange(int min, int max);
int AnswerChecker(int Correct[], int PlayersAns);
void SinglePlayerMode();
void TwoPlayer();
int Gamemode();
int JackpotRound();
int RandomQuesGenerator();
void MainMenuswitch(char MainMenuInt);
int RandomNumGenerator(int RandomNum);


// this displays the Main Menu when you first run the code
void MainMenu() 
{
    printf("\n\n%60s", "FAMILY\n");
    printf("%60s", "FEUD\n\n");
    printf("%70s", "by: Chris Vergel Garvida\n\n");
    printf("%66s", "-- Main Menu --\n\n");
    printf("%66s","|H| How to play\n");
    printf("%59s", "|P| Play\n");
    printf("%60s", "|Q| Quit\n\n");
    printf("%72s", "Select an option: [ H, P, Q ]\n\n");
    printf("%59s", "Option: "); 
}
// this shows the instructions of the game  "Family Feud"
void HowtoPlay() 
{
     char a;
do
{
    printf("\n                                                 How to Play\n");
    printf("                   For single player:\n\n");
    printf("                               1. The game consists of 5 questions, which the user needs to answer.\n\n");
    printf("                               2. Each question has 3 possible answers, each with associated points.\n\n");
    printf("                               3. After answering each question you move to the jackpot round\n\n");
    printf("                                  where you will answer 5 random questions and must get 150 points\n");
    printf("                                  to win the grand prize.\n\n\n");
    printf("                   For 2 players:\n\n"); 
    printf("                               1. Players take turns answering each question.\n\n");
    printf("                               2. Each question has 3 possible answers, each answer has its\n");
    printf("                                  own points.\n\n");
    printf("                               3. Whoever scores the highest will move to the jackpot round.\n\n");
    printf("                                              Go back press [B]: ");
    scanf(" %s", &a);  //stores the users input 
    switch(a) // the answer provided by the user is stored in this switch statement
    {
    case 'b': // if b or B is pressed it will go back to the main menu
    case 'B': // if not pressed it keep on looping to the how to play 
        break;
    default: 
        system("cls"); // this clears the console
        printf("\n\n                                        Invalid input. Press [B] to go back\n"); // this will show if the user didnt input b or B 
       
    }
}
while (a != 'B' && a != 'b'); // this will loop the how to play function if b or B is not pressed
}

/*
Description: This function randomizes the question that is stored from the array it also randomizes the choices per question with each of it having a different range
Precondition: 
        @param = Question is not a negative integer
        @param = i and j is not a negative integer
        @param = RanAns is the generated positive integer base on the range of each questions
        @param = Unique is the one to know if it is a unique number, not repeating
        @param = Choices and Answers will store the generated random choices.
        @param = Answers will store the random generated number within each questions range

@return = nchoices is the group of strings that delivers the randomized choices
*/

char* numchoices(int Question, int *Answers)
{
int i, j;
int RanAns = 0;
int Unique = 0;
static char nchoices[100]; // this will hold the generated string

if (Question == 0 || Question == 7) // this is for the questions 0 and 7
{
    int Choices[4]; // 4 options is needed 

    for (i = 0; i < 4; i++) // loop where it generates 4 options
    {
        RanAns, Unique;

    do // This will generates the random option
    {
        RanAns = (rand() % 10) + 1; // generates an answer from 1 to 10
        Unique = 1;                 // 1 is the value of Unique
        

    for (j = 0; j < i; j++) 
    {
        if (Choices[j] == RanAns) // this line checks if the given answer is repeated
        {
            Unique = 0; // if it detects that the number is repeated it will not store the answer generated 
        }
    }
    }
    while (!Unique); // checks if the function written above is true, if true it ends, if not it will keep on looping
    Choices[i] = RanAns; 
    Answers[i] = RanAns; 
    }
    snprintf(nchoices, sizeof(nchoices), "      %d\n      %d\n      %d\n      %d\n", Choices[0], Choices[1], Choices[2], Choices[3]); // prints the 4 choices according to the range given
}
else if (Question == 2 || Question == 4 || Question == 5 || Question == 6)// this is for the questions 2, 4, 5, and 6
{
    int Choices[4]; // 4 options is needed 

    for (i = 0; i < 4; i++) // loop where it generates 4 options
    {
        RanAns, Unique;

    do
    {
        RanAns = (rand() % 5) + 1;// generates an answer from 1 to 5
        Unique = 1;               // 1 is the value of Unique

    for (j = 0; j < i; j++)
    {
        if (Choices[j] == RanAns) // this line checks if the given answer is repeated
        {
            Unique = 0; // if it detects that the number is repeated it will not store the answer generated
        }
    }
    }
    while (!Unique); // checks if the function written above is true, if true it ends, if not it will keep on looping
    Choices[i] = RanAns; 
    Answers[i] = RanAns; 
    }
    snprintf(nchoices, sizeof(nchoices), "      %d\n      %d\n      %d\n      %d\n", Choices[0], Choices[1], Choices[2], Choices[3]); // prints the 4 choices according to the range given
}
else if (Question == 3 || Question == 9 || Question == 11) // this is for the questions 3, 9, 5, and 11
{
    int Choices[4]; // 4 options is needed 

    for (i = 0; i < 4; i++) // loop where it generates 4 options
    {
        RanAns, Unique;
    
    do 
    {
        RanAns = (rand() % 21) + 10; // generates an answer from 10 to 30
        Unique = 1;                  // 1 is the value of Unique

    for (j = 0; j < i; j++)
    {
        if (Choices[j] == RanAns) // this line checks if the given answer is repeated
        {
            Unique = 0; // if it detects that the number is repeated it will not store the answer generated
        }
    }
    }
    while (!Unique); // checks if the function written above is true, if true it ends, if not it will keep on looping
    Choices[i] = RanAns; 
    Answers[i] = RanAns; 
    }
    snprintf(nchoices, sizeof(nchoices), "      %d\n      %d\n      %d\n      %d\n", Choices[0], Choices[1], Choices[2], Choices[3]); // prints the 4 choices according to the range given
}
else if (Question == 1 || Question == 10) // this is for the questions 1 and 10 
{
    int Choices[4]; // 4 options is needed 

    for (i = 0; i < 4; i++) // loop where it generates 4 options
    {
        RanAns, Unique;
    
    do 
    {
        RanAns = (rand() % 11) + 5; // generates an answer from 5 to 15
        Unique = 1;                 // 1 is the value of Unique

    for (j = 0; j < i; j++)
    {
        if (Choices[j] == RanAns) // this line checks if the given answer is repeated
        {
            Unique = 0; // if it detects that the number is repeated it will not store the answer generated
        }
    }
    }
    while (!Unique); // checks if the function written above is true, if true it ends, if not it will keep on looping
    Choices[i] = RanAns; 
    Answers[i] = RanAns; 
    }
    snprintf(nchoices, sizeof(nchoices), "      %d\n      %d\n      %d\n      %d\n", Choices[0], Choices[1], Choices[2], Choices[3]); // prints the 4 choices according to the range given
}  
else if (Question == 8) // this is for the questions 8
{
    int Choices[4]; // 4 options is needed 

    for (i = 0; i < 4; i++) // loop where it generates 4 options
    {
        RanAns, Unique;
    
    do 
    {
        RanAns = (rand() % 201) + 300; // generates an answer from 300 to 500
        Unique = 1;

    for (j = 0; j < i; j++)
    {
        if (Choices[j] == RanAns)
        {
            Unique = 0; // if it detects that the number is repeated it will not store the answer generated
        }
    }
    }
    while (!Unique); // checks if the function written above is true, if true it ends, if not it will keep on looping
    Choices[i] = RanAns; 
    Answers[i] = RanAns; 
    }
    snprintf(nchoices, sizeof(nchoices), "      %d\n      %d\n      %d\n      %d\n", Choices[0], Choices[1], Choices[2], Choices[3]); // prints the 4 choices according to the range given
  
}
return nchoices;
}



/*
Description: This function Generates the points of the given range when function is called
Precondition:

@return = A random number from what is the minimum given and the maximum (between that range)   ex: randomINRange(1 to 100) - prints a random number from 1 to 100

*/
int randomInRange(int min, int max) 
{
    return (rand() % (max - min + 1)) + min; // generates a random number from 1 to 100 then returns to the function where it is used
}

/*
Description: Checks if the player input is same with the choices given by the randomizer function
Precondition:
    @param  Correct - the array that stored the randomized answers, it is not negative
    @param PlayerAns - The players answer, it is not negative
@return = 0 if it matches the choices, 1 if not

*/
int AnswerChecker(int Correct[], int PlayersAns) 
{
    int i;
    for (i = 0; i < 4; i++) // loops through the correct array
    { 
        if (Correct[i] == PlayersAns) // checks if the answer given by the player is same with the choices given
        {
            return 0; // if it finds a match it will return 0
        }
    }
    return 1; // if found in the choices returns 1
}

/*
Description: This is the function which prints the randomly generated question along with its range of random answers
Precondition: Only accepts positive whole numbers within each questions range
*/
void SinglePlayerMode()
{
char *Questions[12] = //organizes the question with its own given number
{
"How many days can someone go without food?", // 1 to 10                                 0 check
"How many pairs of shoes does the average person own?", // 5 to 15                       1 check
"How many siblings does the average person have?", // 1 to 5                             2 check
"How many minutes does it take to get ready in the morning?", // 10 to 30                3 check
"How many pets does the average household have?", // 1 to 5                              4 check
"How many cups of coffee does the average person drink in a day?", // 1 to 5             5 check
"How many cars does the average household own?", // 1 to 5                               6 check
"How many eggs does the average person eat in a week?", // 1 to 10                       7 check
"How many pages are in the average novel?", // 300 to 500                                8  check
"How many hours a day does the average person spend on the internet?", // 10 to 30       9  check
"How many hours do people spend on their computers per day on average?", // 5 to 15      10 check
"How many hours of video games does the average teenager play per week?", // 10 to 30    11 check
};
int AskedQues[MAX_QUES] = {0};  // tracks which questions have been asked
    int Score = 0;                 // tracks the players score
    char Continue = 'Y';           // default to continue playing
    int QuesNum = 0;

   
    while (QuesNum < 5 && (Continue == 'Y' || Continue == 'y')) // loop to ask up to 5 questions or until the player decides to quit 
    {
        system("cls"); // clear screen
        printf("%38s", "-==================== SINGLE PLAYER ====================\n\n\n");

        
        int RandomQues;
        int MoreRandom;
        do {
            MoreRandom = RandomQuesGenerator(MAX_QUES); // Generate a unique random question
           RandomQues = RandomNumGenerator(MoreRandom); // Randomizes the Questions more
        } while (AskedQues[RandomQues]);

        AskedQues[RandomQues] = 1;  //mark question as asked
        QuesNum++;                  //increment the number of questions

        
        printf("Question:\n%s\n\n", Questions[RandomQues]);
        int Ans[4];
        printf("%s\n", numchoices(RandomQues, Ans));// display the question and choices

       
        int PlayerAns;
        int ValidAns = 0;
        do {
            printf("Enter an answer from the above choices: ");
            scanf("%d", &PlayerAns);// get the player's answer
            ValidAns = !AnswerChecker(Ans, PlayerAns); //checks if the answer given is part of the options
            if (!ValidAns) 
            {
                printf("\nInvalid Answer. Pick from the choices above.\n");
            }
        } while (!ValidAns);

        
        int points = randomInRange(0, 85);  // random points between 0 and 85
        Score += points;
        printf("\nYou earned %d points. Total score: %d\n", points, Score); // prints the points earned per question and total score
        sleep(2); // delays for 2 seconds

        
        printf("\nDo you want to continue the game? (Y/N): ");// ask the player if they want to continue
        scanf(" %c", &Continue);
    }

    
    system("cls");
    printf("\n==================== FINAL SCORES ====================\n");
    printf("\nFinal Score: %d\n", Score); // prints the final score of the player

    if (Continue == 'N' || Continue == 'n') // if N or n is inputted it will loop back to the main Menu
    {
        printf("Thank you for playing! Moving you back to the Main Menu\n");
        sleep(2); // delays for 2 seconds
        MainMenu();
        return;
    }

  
    if (Score >= 150) // if the players score is more than 150 he will proceed to the jackpot round
    {
        printf("Congratulations! You advance to the jackpot round.\n");
        sleep(3);
        JackpotRound();
    } else { // if not he will be then automatically go back to the main menu
        printf("Sorry, you needed %d more points to advance.\n", 150 - Score);
        printf("Thank you for playing!\n");
    }

    sleep(5);
    MainMenu();
}
/*
Description: This is the function which prints the randomly generated question along with its range of random answers but for 2 player
Precondition: Only accepts postive whole numbers that are within the range of each question
*/


void TwoPlayer()
{
char *Questions[12] = //organizes the question with its own given number
{
"How many days can someone go without food?", // 1 to 10                                 0 check
"How many pairs of shoes does the average person own?", // 5 to 15                       1 check
"How many siblings does the average person have?", // 1 to 5                             2 check
"How many minutes does it take to get ready in the morning?", // 10 to 30                3 check
"How many pets does the average household have?", // 1 to 5                              4 check
"How many cups of coffee does the average person drink in a day?", // 1 to 5             5 check
"How many cars does the average household own?", // 1 to 5                               6 check
"How many eggs does the average person eat in a week?", // 1 to 10                       7 check
"How many pages are in the average novel?", // 300 to 500                                8 check
"How many hours a day does the average person spend on the internet?", // 10 to 30       9  check
"How many hours do people spend on their computers per day on average?", // 5 to 15      10 check
"How many hours of video games does the average teenager play per week?", // 10 to 30    11 check
};
 int TQuestions = MAX_QUES; // total Questions
    int AskedQues[MAX_QUES] = {0}; // every question is not asked, which is why 0 is given
    int RanNum; 
    int QuesNum = 0; 
    int RandomQues;
    int OneScore = 0; 
    int TwoScore = 0;
    int Player1Ans;
    int Player2Ans;
    int Ans[4];
    int ValidAns = 1;
    char Continue; 

    for (QuesNum = 0; QuesNum < 5;) {
        RanNum = RandomQuesGenerator(TQuestions); // randomly picks the question that will be given
        RandomQues = RandomNumGenerator(RanNum); // randomizes the given question more

        if (AskedQues[RandomQues] == 0)  // checks if the question is asked
        {
            AskedQues[RandomQues] = 1; // if not asked it will store the random question
            QuesNum++; // increments if an unasked question is asked
            system("cls"); // clears the consle
            printf("%38s", "==================== TWO PLAYER ====================\n\n\n");
            printf("Question %d:\n", QuesNum);
            printf("%s\n\n", Questions[RandomQues]); // prints the random question that is marked unasked

            
            numchoices(RandomQues, Ans); // This produces 4 random options in the question with its assigned range
            printf("%s\n", numchoices(RandomQues, Ans)); // prints 4 random answers for the player to choose

            
            do {
                printf("Player 1, enter an answer from the above choices: ");
                scanf("%d", &Player1Ans); // stores the player 1s answer

                if (AnswerChecker(Ans, Player1Ans))  // checks if the answer of the player is the same with the given 4 options
                {
                    printf("\nInvalid Answer. Pick from the choices above.\n"); // if not part this line will print and ask the player again
                    ValidAns = 0; // if not met this line will loop and ask for the players answer the same with the options given
                } else {
                    printf("\n");
                    ValidAns = 1; // will end the loop if the answer of the player is part of the options given
                }
            } while (!ValidAns);// will loop when not 1

            
            do {
                printf("Player 2, enter an answer from the above choices: ");
                scanf("%d", &Player2Ans); // stores the player 2s answer

                if (AnswerChecker(Ans, Player2Ans)) // checks if the answer of the player is the same with the given 4 options
                {
                    printf("\n\nInvalid Answer. Pick from the choices above.\n"); // if not part this line will print and ask the player again
                    ValidAns = 0; // if not met this line will loop and ask for the players answer the same with the options given
                } else if (Player2Ans == Player1Ans) 
                { 
                printf("\n\nYou cannot pick the same answer as Player 1. Please choose a different answer.\n"); //  if players 2s answer is same with player 1 it will ask player 2 again
                ValidAns = 0; // if not met this line will loop and ask for the players answer the same with the options given
                } else 
                {
                    printf("\n");
                    ValidAns = 1; // will end the loop if the answer of the player is part of the options given
                }
            } while (!ValidAns); // will loop when not 1

            // Award points to both players
            int Player1Points = randomInRange(0, 75); // generates players 1s points
            int Player2Points = randomInRange(0, 75); // generates player 2s points
            OneScore += Player1Points; // will store and add the points attained to player 1s score
            TwoScore += Player2Points; // will store and add the points attained to player 2s score

            
            printf("Points for this question:\n");
            printf("Player 1 earned %d points. Total score: %d Points\n", Player1Points, OneScore);// these 2 codes will print the total score of each player
            printf("Player 2 earned %d points. Total score: %d Points\n", Player2Points, TwoScore);
            sleep(2); // will delay the program for 2 seconds
            
    printf("\n Do you want to continue the game? (Y/N):");
    scanf(" %c", &Continue); // will ask after each question if they want to continue

       if (Continue == 'N' || Continue == 'n') // if n or N pressed it will automatically go back to the Main Menu
       {
        system("cls"); // clears the console
        printf("\n\nThank you For playing!");
        printf("\nPlayer 1 earned %d points. Total score: %d Points", Player1Points, OneScore); //These 2 codes will print the scores of each player attained
        printf("\nPlayer 2 earned %d points. Total score: %d Points", Player2Points, TwoScore);
        printf("\nGoing back to the Main Menu");
        sleep(5);
        break; // go backs to the main menu
       }
        }
    }

    
    if (Continue != 'N' && Continue != 'n') // if n or N is not pressed it will progress through the function
    {
    system("cls");
    printf("\n==================== FINAL SCORES ====================\n"); // these 2 codes print the final score of each player
    printf("Player 1: %d points\n", OneScore);
    printf("Player 2: %d points\n", TwoScore);

    if (OneScore > TwoScore) // if player 1 scores more than player 2, player 1 will progress to the Jackpot Round
    {
        printf("\nPlayer 1 wins! Congratulations!\n");
        printf("You will be moving on to the Jackpot round! Goodluck\n");
        sleep(5);
        JackpotRound();
    } else if (TwoScore > OneScore) // if player 2 scores more than player 1, player 2 will progress to the Jackpot Round
    {
        printf("\nPlayer 2 wins! Congratulations!\n");
        printf("You will be moving on to the Jackpot round! Goodluck\n");
        sleep(5);
        JackpotRound();
    } else 
    {
        printf("\nIt's a tie! Great job, both players!\n"); // if its a tie it will just go back to tha main menu for a new game
        MainMenu();
    }

    sleep(5); // delays the program for 5 seconds
  
    }
}
/*
Description: This function asks the player if he/she wants to paly single player or 2 player
Precondition: Only accepts 1 or 2
*/

int Gamemode()
{
int gamemode = 0;
while (gamemode != 1 && gamemode != 2) // if not 1 or 2 pressed the codes below will print
    {
    printf("\n                                                 Select Game Mode\n");
    printf("                                                  |1| Single Player\n");
    printf("                                                  |2| Two Players\n");
    printf("                                                    Option: ");
    scanf("%d", &gamemode); // stores the players choice of mode

  if (gamemode == 1) // if 1 it will start the single player mode
    {
    SinglePlayerMode();
    } 
    else if (gamemode == 2) // if 2 it will start the two player mode
    {
    TwoPlayer();
    } 
    else 
    {
    printf("Invalid option. Please select 1 or 2\n"); // if not 1 or 2 it will ask the player to input again
    gamemode = 0; // will continously loop
    }
    }

}
/*
Description: This is the function which prints the randomly generated question along with its range of random answers
Precondition: Only accepts postive whole numbers that are within the range of each question
*/

int JackpotRound() 
   {
char *Questions[12] = //organizes the question with its own given number
{
"How many days a year do people typically take short weekend trips?", // 1 to 10         0 x
"How many movies do people watch in a month?", // 5 to 15                                1 x
"On average, how many cups of coffee do people drink per day?", // 1 to 5                2 x
"On average, how many emails do people receive per day?", // 10 to 30                    3 x
"How many unique hobbies do people typically have?", // 1 to 5                           4 x
"How many cups of coffee does the average person drink in a day?", // 1 to 5             5 x
"How many online streaming services do people subscribe to?", // 1 to 5                  6 x
"How many different apps do people use regularly on their phone?", // 1 to 10            7 x
"How many miles do drivers typically drive in a month?", // 300 to 500                   8 x
"How many personal items (clothes, gadgets, etc.) do people usually buy in a year?", // 10 to 30      9 x  
"How many hours do people spend traveling each week on average?", // 5 to 15             10 x
"How many hours do people spend traveling for leisure each year?", // 10 to 30           11 x
};

int AskedQues[MAX_QUES] = {0};  // tracks which questions have been asked
    int Score = 0;                 // tracks the players score
    char Continue = 'Y';           // default to continue playing
    int QuesNum = 0;

   
    while (QuesNum < 5 && (Continue == 'Y' || Continue == 'y')) // loop to ask up to 5 questions or until the player decides to quit 
    {
        system("cls"); // clear screen
        printf("%38s", "-==================== JACKPOT ROUND ====================\n\n\n");

        
        int RandomQues;
        int MoreRandom;
        do {
            MoreRandom =  RandomQuesGenerator(MAX_QUES); // Generate a unique random question
            RandomQues = RandomNumGenerator(MoreRandom); // Randomizes the Question more.
        } while (AskedQues[RandomQues]);

        AskedQues[RandomQues] = 1;  //mark question as asked
        QuesNum++;                  //increment the number of questions

        
        printf("Question:\n%s\n\n", Questions[RandomQues]);
        int Ans[4];
        printf("%s\n", numchoices(RandomQues, Ans));// display the question and choices

       
        int PlayerAns;
        int ValidAns = 0;
        do {
            printf("Enter an answer from the above choices: ");
            scanf("%d", &PlayerAns);// get the player's answer
            ValidAns = !AnswerChecker(Ans, PlayerAns); //checks if the answer given is part of the options
            if (!ValidAns) 
            {
                printf("\nInvalid Answer. Pick from the choices above.\n");
            }
        } while (!ValidAns);

        
        int points = randomInRange(0, 90);  // random points between 0 and 85
        Score += points;
        printf("\nYou earned %d points. Total score: %d\n", points, Score); // prints the points earned per question and total score
        sleep(2); // delays for 2 seconds

        
        printf("\nDo you want to continue the game? (Y/N): ");// ask the player if they want to continue
        scanf(" %c", &Continue);
    }

    
    system("cls");
    printf("\n==================== FINAL SCORES ====================\n");
    printf("\nFinal Score: %d\n", Score); // prints the final score of the player

    if (Continue == 'N' || Continue == 'n') // if N or n is inputted it will loop back to the main Menu
    {
        printf("Thank you for playing! Returning to the main menu...\n");
        sleep(2);
        system("cls");// delays for 2 seconds
        MainMenu();
    }

  
    if (Score >= 150) // if the players score is more than 150 he wins the 200,000 pesos prize
    {
        printf("Congratulations! YOU WON 200,000 PESOS!!\n");
        printf("Thank you For Playing!");
        printf("Moving you back to the Main Menu...");
        sleep(3);
        
    } else { // if not he will be then automatically go back to the main menu
        printf("Sorry, you needed %d more points to advance.\n", 150 - Score); // if not it will show the score needed by the player to win and go back to the mainmenu
        printf("THANK YOU FOR PLAYING!!!");
    }

    sleep(5);
    MainMenu();
}

/*
Description: This randomizes from 1 to 12 on what question to choose\
Precondition: 

@return = it returns the randomized picked number
*/

int RandomQuesGenerator()
{
    int RandomGen;
return rand() % 12; // generates an answer from 1 to 12

}

/*
Description: This function further randomizes the number got from the precvious random generator
Precondition: 
    @param = RandomNum is not a negative number, it is the generated number from the previous function

@return = it returns the randomized picked number
*/
int RandomNumGenerator(int RandomNum)
{
    int RandomNumber;
    RandomNumber = (rand() % 3 ) + 1; // randomly pics a number from 1 to 3
        switch (RandomNumber) // stores RandomNumber to switch case
        {
            case 1: //if the random generator generates 1, it will use addition method to further randomize the number
            int Random1;
            Random1 = (RandomNum + 4 ) % 12 + 1; // addition and produces a number from 1 to 12
            return Random1; // returns the random number
            
            case 2: // if the random generator generates 2, it will use subtraction method to further randomize the number
            int Random2;
            Random2 = ((RandomNum - 4 ) % 12 + 12) % 12; // subtract and produces a number from 1 to 12
            return Random2; // returns the random number

            case 3: // if the random generator generates 2, it will use multiplication method to further randomize the number
            int Random3;
            Random3 = ((RandomNum * 4 ) % 12 + 12) % 12; // multiplication and produces a number from 1 to 12
            return Random3; // returns the random number
        }
    return RandomNum; // returns the random number
}
/*
Description: This function is basically the central of the system where it navigates what the player wants to see
Precondition: 
    @param = MainMenuInt is a character where it only accepts H, P or Q

*/


void MainMenuswitch(char MainMenuInt) // processes the input of the player
{
    
    
        switch(MainMenuInt) // switch statement the players answer
        {
        break;
        case 'H':  //if H or h is inputted it will go to the How to play function
        case 'h': 
            system("cls");
            HowtoPlay();  
            break;
        case 'P': //if P or p is inputted it will show the gamemode function
        case 'p': 
            system("cls");
            Gamemode(); 
            break;
        case 'q': // if Q or q is inputted it will exit the code
        case 'Q':
        system("cls");
        printf("\n\n""%65s","Exiting Game...\n");
        break;
        default:
        system("cls");
        break;
        
    }
     
}

// Main code
int main()
{
    char MainMenuInt; 
 
 do
 {
        MainMenu();
        scanf("%c", &MainMenuInt); // This stores the players input chose from the Main Menu
        MainMenuswitch(MainMenuInt); // the character stored will proceed to the MainMenuSwitch function
 }
    while (MainMenuInt != 'q' && MainMenuInt != 'Q'); // if not Q or q pressed it will not end the program

    return 0;
}
