import java.util.Random;
import java.util.Scanner;

public class Game {
    public static void main(String[] args) {

           /* 0: ROCK
       1: SCISSORS
       2: PAPER */

        Random rNum = new Random();
        Scanner input = new Scanner(System.in);

        System.out.println("                   WELCOME TO THE ROCK PAPER SCISSORS GAME                  ");

        String userName ="";
        System.out.print("Enter your Name: ");
        userName = input.nextLine();
        String options = "";
        System.out.println("\nType 'start' to start the game .\n'help' to see the rules again.");
        System.out.print("$ ");
        options = input.next();
        while (options.equals("help")) {
            System.out.println("##################################################################################################");
            System.out.println("The rules to play it are pretty simple.\n" +
                    "The game is played where players deliver hand signals that will represent the elements of the game; rock, paper and scissors. \nThe outcome of the game is determined by 3 simple rules:\n" +
                    "\n" +
                    "\n1. Rock wins against scissors.\n" +
                    "\n2. Scissors win against paper.\n" +
                    "\n3. Paper wins against rock.");
            System.out.println("\nAs per the game:\nRock is represented by 0\nScissors is represented by 1\nPaper is represented by 2");
            System.out.println("##################################################################################################");
            System.out.println("\nType 'start' to start the game .\n'help' to see the rules again.");
            System.out.print("$ ");
            options = input.next();


        }

        System.out.println("===============GAME STARTS NOW=================");


        System.out.
                print("PRESS 0 : ROCK\nPRESS 1 : SCISSORS\nPRESS 2 : PAPER\n\n");

        int userScore = 0;
        int computerScore = 0;
        int numTimes = 5;
        while (numTimes > 0) {

            System.out.print("\n["+userName+"@localhost]$ ");
            int computerChoice = rNum.nextInt(3);


            int userChoice = input.nextInt();

            if (computerChoice == 0) {
                System.out.println("[robot@localhost]$ " + computerChoice);

                switch (userChoice) {
                    case 0:


                        userScore += 0;
                        System.out.print("TIE\n");

                        break;


                    case 1:


                        userScore--;
                        System.out.print("YOU LOST ONE POINT\n");

                        break;


                    case 2:


                        userScore++;
                        System.out.print("YOU WON ONE POINT\n");
                        break;


                    default:

                        System.out.print("😮 INVALID CHOICE.PLEASE ENTER THE VALID CHOICE 🤨\n");
                        continue;

                }
            } else if (computerChoice == 1) {

                System.out.println("[robot@localhost]$ " + computerChoice);

                switch (userChoice) {
                    case 0:

                        userScore++;

                        System.out.print("YOU WON ONE POINT\n");

                        break;


                    case 1:


                        userScore += 0;
                        System.out.print("TIE\n");
                        break;


                    case 2:


                        userScore--;
                        System.out.print("YOU LOST ONE POINT\n");
                        break;


                    default:

                        System.out.print("😮 INVALID CHOICE.PLEASE ENTER THE VALID CHOICE 🤨\n");

                        continue;

                }

            }
            if (computerChoice == 2) {

                System.out.println("[robot@localhost]$ " + computerChoice);

                switch (userChoice) {
                    case 0:

                        userScore--;
                        System.out.print("YOU LOST ONE POINT\n");

                        break;

                    case 1:

                        userScore++;
                        System.out.print("YOU WON ONE POINT\n");

                        break;

                    case 2:

                        userScore += 0;
                        System.out.print("TIE\n");

                        break;

                    default:

                        System.out.print("😮 INVALID CHOICE.PLEASE ENTER THE VALID CHOICE 🤨\n");
                        continue;

                }

            }

            numTimes--;
        }

        System.out.println("\n===========GAME RESULTS===========");
        if (userScore < computerScore) {

            System.out.println("😥 😥 You lost the game by " + (computerScore - userScore) + " points.\nBETTER LUCK NEXT TIME.");
        } else if (userScore > computerScore) {

            System.out.println("😎 😎 You won the game by " + (userScore - computerScore) + " points.");
        } else {
            System.out.println("😑 😑 IT'S A TIE");
        }
    }
}
