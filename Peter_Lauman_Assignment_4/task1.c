#include <stdio.h>

int main()
{
    int score;
    int td2, td1, td, fg, safety;

    while (1)
    {
        printf("Enter the NFL score (Enter 1 to stop): ");
        scanf("%d", &score);

        // Stop the program when the user enters 1
        if (score == 1)
        {
            break;
        }

        // Check for invalid negative scores
        if (score < 0)
        {
            printf("Invalid score. Please enter a non-negative score.\n");
            continue;
        }

        printf("Possible combinations of scoring plays if a team's score is %d:\n", score);

        // Try every possible combination of scoring plays
        for (td2 = 0; td2 <= score / 8; td2++)
        {
            for (td1 = 0; td1 <= score / 7; td1++)
            {
                for (td = 0; td <= score / 6; td++)
                {
                    for (fg = 0; fg <= score / 3; fg++)
                    {
                        for (safety = 0; safety <= score / 2; safety++)
                        {
                            // Check if this combination equals the entered score
                            if ((td2 * 8) + (td1 * 7) + (td * 6) +
                                (fg * 3) + (safety * 2) == score)
                            {
                                printf("%d TD + 2pt, %d TD + FG, %d TD, "
                                       "%d 3pt FG, %d Safety\n",
                                       td2, td1, td, fg, safety);
                            }
                        }
                    }
                }
            }
        }
    }

    return 0;
}