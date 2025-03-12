#include <stdio.h>

void find_combinations(int score) 
{
    int td_2pt, td_fg, td, fg, safety;

    printf("Possible combinations of scoring plays if a team’s score is %d:\n", score);

    //This giant nested loop sequence essentially tests every possible combination while holding certain variables constant and checks to see if it equals the target score
    //If the target score is reached then only the combination is rpinted
    //This loops through possible counts of Touchdowns + 2-point conversion (8 points each)
    for (td_2pt = 0; td_2pt * 8 <= score; td_2pt++) {
        // This loops through possible counts of Touchdowns + Field Goal (7 points each)
        for (td_fg = 0; td_fg * 7 + td_2pt * 8 <= score; td_fg++) {
            // This loops through possible counts of regular Touchdowns (6 points each)
            for (td = 0; td * 6 + td_fg * 7 + td_2pt * 8 <= score; td++) {
                // This loops through possible counts of Field Goals (3 points each)
                for (fg = 0; fg * 3 + td * 6 + td_fg * 7 + td_2pt * 8 <= score; fg++) {
                    // This loops through possible counts of Safeties (2 points each)
                    for (safety = 0; safety * 2 + fg * 3 + td * 6 + td_fg * 7 + td_2pt * 8 <= score; safety++) {
                        // If the sum of all scoring plays equals the target score, print the combination
                        if (safety * 2 + fg * 3 + td * 6 + td_fg * 7 + td_2pt * 8 == score) {
                            printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n",
                                   td_2pt, td_fg, td, fg, safety);
                        }
                    }
                }
            }
        }
    }
}

int main() {
    int score;

    // This loops to keep asking the user for a score until they enter 0 or 1
    while (1) {
        printf("Enter the NFL score (0 or 1 to STOP): ");
        scanf("%d", &score); //This scans the user input annd stores it in score
        
        // If input is 0 or 1, terminate the program before the fin
        if (score <= 1) break;

        // This finds and displays all possible scoring combinations for the given score
        find_combinations(score);
    }

    return 0;
}
