/*----------------------------------------------------------------------------
- Kemal Yavuz - Role: Quiz Creator and Debugger
- Created the random quiz system to avoid repeating quizzes.                 
- Wrote the quizzes and placed them in functions.
- Wrote the code to allocate random quizzes based on the random generated seed.									
- Wrote the code to enable the user to quit the quizzes.
- Wrote the code to calculate the statistics regarding quiz scores.			 			         
-----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
-								Includes									 -
-----------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
/*----------------------------------------------------------------------------
-	                            Functions Prototypes                         -
-----------------------------------------------------------------------------*/
bool userInput(int luckyNumber);
int selectQuiz(int randomQuiz);
int quiz1(double quiz1Score, double average1);
int quiz2(double quiz2Score, double average2);
int quiz3(double quiz3Score, double average3);
/*----------------------------------------------------------------------------
-	                                Notes                                    -
-----------------------------------------------------------------------------*/

// Compile with gcc Quiz.c -o Quiz
// Run with ./Quiz.exe

/*----------------------------------------------------------------------------
-								Implementation			                     -
-----------------------------------------------------------------------------*/
int main(void){

   srand(time(NULL));

   int luckyNumber, invalidInput, randomQuiz, quizzes[3];
   double quiz1Score, quiz2Score, quiz3Score, overallAverage = 0, average1, average2, average3;
   
   printf("Welcome to Quiz Me!\n\n");
   printf("Available quizzes:\n\n");
   printf("Quiz 1\nQuiz 2\nQuiz 3\n\n");
   printf("Enter lucky number between 1 and 9 to pick random quiz: ");
   scanf("%d", &luckyNumber);
   invalidInput = userInput(luckyNumber);

   while(invalidInput == true){
      printf("\nInvalid input, please enter again.");
      printf("\n\nEnter lucky number between 1 and 9 to pick random quiz: ");
      scanf("%d", &luckyNumber);
      invalidInput = userInput(luckyNumber);
   }

   randomQuiz = (rand() % (luckyNumber + 3)) + 1;
   quizzes[0] = selectQuiz(randomQuiz);

   randomQuiz = (rand() % (luckyNumber + 3)) + 1;
   quizzes[1] = selectQuiz(randomQuiz);

   while (quizzes[1] == quizzes[0]){
      randomQuiz = (rand() % (luckyNumber + 3)) + 1;
      quizzes[1] = selectQuiz(randomQuiz);
   }

   randomQuiz = (rand() % (luckyNumber + 3)) + 1;
   quizzes[2] = selectQuiz(randomQuiz);

   while ((quizzes[2] == quizzes[0]) || (quizzes[2] == quizzes[1])){
      randomQuiz = (rand() % (luckyNumber + 3)) + 1;
      quizzes[2] = selectQuiz(randomQuiz);
   }

   char quitOrPlay[10];
   bool stop = true;
   double n = 0;

   while (stop == true){
	   
      for (int i = 0; i < sizeof(quizzes[3]); i++){
         if (quizzes[i] == 0){
            overallAverage = overallAverage + quiz1(quiz1Score, average1);
			n = n + 1;
         } else if (quizzes[i] == 1){
            overallAverage = overallAverage + quiz2(quiz1Score, average2);
			n = n + 1;
         } else if (quizzes[i] == 2){
            overallAverage = overallAverage + quiz3(quiz3Score, average3);
			n = n + 1;
         }
		 
		 overallAverage = overallAverage / n;
		 
		 if (n > 1){
			 printf("Your average score over all quizzes = %.2lf%%\n", overallAverage / 15 * 100);
		 }
		 
         printf("Enter Q to quit, or anything else to continue: ");
         scanf("%s", &quitOrPlay[10]);

         if (quitOrPlay[10] == 'Q'){
			stop = false;
            break;
         }
      }
   }

   return 0;
}

bool userInput(int luckyNumber){

   int input;

   if ((luckyNumber > 9) || (luckyNumber < 1)){
      input = true;
   } else if ((luckyNumber <= 9) && (luckyNumber >= 1)){
      input = false;
   } 
   
   return input;
}

int selectQuiz(int randomQuiz){

   randomQuiz = randomQuiz % 3;

   return randomQuiz;
}

int quiz1(double quiz1Score, double average1){
	
	int i = 0;
	double n1 = 0;
	double total1 = 0;

	while(i != 1){	

		char truefalse[10];
		char multiple[10];
		char blanks[10];
		
		quiz1Score = 0;
		n1 = n1 + 1;
		
		printf("\n\t\tQUIZ 1\n\n");
		printf("\n1. The variable declaration below is valid in C.\n\ndouble 1453FatihSultanMehmet;\n\n(T)True\n(F)False\n\n");
		scanf("%s", &truefalse[10]);
		
		if (truefalse[10] == 'F'){
			printf("Your answer is correct!\n\n");
			quiz1Score = quiz1Score + 5;
			total1 = total1 + 5;
		} else {
			printf("Your answer is incorrect!\n\n");
		}
		
		printf("\n2. What is the output of this program?\n\n#include <stdio.h>\n\nint main(){\nint x, y, z, result;\nx = 3;\ny = 5;\nz = 7;\n\nscanf(“%%d”, &z);\n\nresult = x + y + z;\n\nprintf(“%%d”, result);\n\nreturn 0;\n}\nA) 15\nB) 35\nC) 357\nD) Depends on the user input\n\n");
		scanf("%s", &multiple[10]);
		
		if (multiple[10] == 'D'){
			printf("Your answer is correct!\n\n");
			quiz1Score = quiz1Score + 5;
			total1 = total1 + 5;
		} else {
			printf("Your answer is incorrect!\n\n");
		} 
		
		printf("\n3. What must be in the blank to store the variable in this program in the right data type?\n\nint userInput;\n\nscanf(“%%[_]”, &userInput);\n\n[_]\n\n");
		scanf("%s", &blanks[10]);
		
		if (blanks[10] == 'd'){
			printf("Your answer is correct!\n\n");
			quiz1Score = quiz1Score + 5;
			total1 = total1 + 5;
		} else {
			printf("Your answer is incorrect!\n\n");
		}
		
		average1 = total1 / n1;
		printf("You average over all attempts on Quiz 1 is %.2lf%%\n", average1 / 15 * 100);
		printf("You scored %.0lf/15\n", quiz1Score);
		
		if (quiz1Score != 15){
			i = 0;
			printf("Please retake the quiz until you get all of the questions correct.\n\n");
		} else if (quiz1Score == 15){
			i = 1;
		}
}
	
	return average1;
}

int quiz2(double quiz2Score, double average2){
	
	int i = 0;
	double n2 = 0;
	double total2 = 0;

	while(i != 1){	

		char truefalse[10];
		char multiple[10];
		char blanks[10];
		
		quiz2Score = 0;
		n2 = n2 + 1;
		
		printf("\n\t\tQUIZ 2\n\n");
		printf("\n1. C library - <math.h> contains various math operation functions including square root and power operations.\n\n(T)True\n(F)False\n\n");
		scanf("%s", &truefalse[10]);
		
		if (truefalse[10] == 'T'){
			printf("Your answer is correct!\n\n");
			quiz2Score = quiz2Score + 5;
			total2 = total2 + 5;
		} else {
			printf("Your answer is incorrect!\n\n");
		}
		
		printf("\n2. What is the output of this program?\n\n#include <stdio.h>\n#include <math.h>\n\nint main(){\n\ndouble x, y, result;\nx = 3;\ny = 4;\n\nresult = sqrt(pow(x, 2.0) + pow(y, 2.0));\n\nprintf(“%%.2lf”, result);\n\nreturn 0;\n}\n\nA)4.00\nB)5.00\nC)7.00\nD)14.00\n\n");
		scanf("%s", &multiple[10]);
		
		if (multiple[10] == 'B'){
			printf("Your answer is correct!\n\n");
			quiz2Score = quiz2Score + 5;
			total2 = total2 + 5;
		} else {
			printf("Your answer is incorrect!\n\n");
		} 

		printf("\n3. What symbol must be used in the blank to scan the variable in this program in the right way?\n\nint numValue;\nscanf(“%%d”, [_]numValue);\n\n[_]\n\n");
		scanf("%s", &blanks[10]);
		
		if (blanks[10] == '&'){
			printf("Your answer is correct!\n\n");
			quiz2Score = quiz2Score + 5;
			total2 = total2 + 5;
		} else {
			printf("Your answer is incorrect!\n\n");
		}
		
		average2 = total2 / n2;
		printf("You average over all attempts on Quiz 2 is %.2lf%%\n", average2 / 15 * 100);
		printf("You scored %.0lf/15\n", quiz2Score);
		
		if (quiz2Score != 15){
			i = 0;
			printf("Please retake the quiz until you get all of the questions correct.\n\n");
		} else if (quiz2Score == 15){
			i = 1;
		}
}
	
   return average2;
}

int quiz3(double quiz3Score, double average3){

	int i = 0;
	double n3 = 0;
	double total3 = 0;

	while(i != 1){	

		char truefalse[10];
		char multiple[10];
		char blanks[10];

		quiz3Score = 0;
		n3 = n3 + 1;
		
		printf("\n\t\tQUIZ 3\n\n");
		printf("\n1. The compiler will create 6 size arrays for this string.\n\nchar str[] = “Apple”;\n\n(T)True\n(F)False\n\n");
		scanf("%s", &truefalse[10]);
		
		if (truefalse[10] == 'T'){
			printf("Your answer is correct!\n\n");
			quiz3Score = quiz3Score + 5;
			total3 = total3 + 5;
		} else {
			printf("Your answer is incorrect!\n\n");
		}
		
		printf("\n2. What will be the output of this program?\n\n#include <stdio.h>\n#include <string.h>\n\nint main(){ \n\nchar str1[] = “Red”;\nchar str2[] = “Blue”;\nstrcpy(str1, str2);\nprintf(“%%d”, strlen(str1));\n\nreturn 0;\n}\n\nA) 3\nB) 4\nC) 7\nD) Does not compile\n\n");
		scanf("%s", &multiple[10]);
		
		if (multiple[10] == 'B'){
			printf("Your answer is correct!\n\n");
			quiz3Score = quiz3Score + 5;
			total3 = total3 + 5;
		} else {
			printf("Your answer is incorrect!\n\n");
		} 

		printf("\n3. What must be in the blank to print the variable in this program in the right data type?\n\nchar str1[20] = “character”;\nprintf(“%%[_]”, str1);\n\n[_]\n\n");
		scanf("%s", &blanks[10]);
		
		if (blanks[10] == 's'){
			printf("Your answer is correct!\n\n");
			quiz3Score = quiz3Score + 5;
			total3 = total3 + 5;
		} else {
			printf("Your answer is incorrect!\n\n");
		}
		
		average3 = total3 / n3;
		printf("You average over all attempts on Quiz 3 is %.2lf%%\n", average3 / 15 * 100);
		printf("You scored %.0lf/15\n", quiz3Score);
		
		if (quiz3Score != 15){
			i = 0;
			printf("Please retake the quiz until you get all of the questions correct.\n\n");
		} else if (quiz3Score == 15){
			i = 1;
		}
	}

   return average3;
}