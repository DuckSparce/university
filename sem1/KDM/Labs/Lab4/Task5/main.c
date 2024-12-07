#include <stdio.h>
#include <string.h>

char* findSDNF(char[250]);

// FDNF - Full Disjunctive Normal Form
// SDNF - Shortened Disjunctive Normal Form

int main()
{
    printf("Enter your FDNF (space is considered end of input):\n");
    char FDNF[250];
    scanf("%s", &FDNF);

    // 17 - all possible combinations + last cell for 2 as identificator of an end
    // 4 - actual set of 0/1
    int matrix[17][4] = { 0 };

    // STEP 1 - rewrite formula to matrix form
    int row = 0;
    int isPositive = 1;
    char ch = FDNF[0];
    for (int i = 0; ch;) {
        if (ch == '(') {
            i++;
            ch = FDNF[i];
            while (ch != ')') {
                switch (ch) {
                case 'W':
                    matrix[row][0] = isPositive;
                    break;
                case 'X':
                    matrix[row][1] = isPositive;
                    break;
                case 'Y':
                    matrix[row][2] = isPositive;
                    break;
                case 'Z':
                    matrix[row][3] = isPositive;
                    break;
                case '^':
                    isPositive = 1;
                    break;
                case '!':
                    isPositive = 0;
                    break;
                default:
                    printf("Something went wrong. End of program.");
                    return 1;
                }
                i++;
                ch = FDNF[i];
            }
            row++;
        } else if (ch != 'v') {
            printf("Something went wrong. End of program.");
            return 1;
        }
        isPositive = 1;
        i++;
        ch = FDNF[i];
    }
    matrix[row][0] = 2;

    // STEP 2 - sort EC by number of 1
    // 5 - groups by number of 1
    // 10 - approximate maximum of possible combinations of 1
    // 4 - actual set of 0/1
    int sortedMatrix[5][20][4] = { [0][0][0] = 2, [1][0][0] = 2, [2][0][0] = 2, [3][0][0] = 2, [4][0][0] = 2 };
    int rows[5] = { 0 };
    for (int i = 0; matrix[i][0] != 2; i++) {
        int count = 0;

        for (int j = 0; j < 4; j++) {
            count += matrix[i][j];
        }

        for (int j = 0; j < 4; j++) {
            sortedMatrix[count][rows[count]][j] = matrix[i][j];
        }

        sortedMatrix[count][rows[count] + 1][0] = 2;
        rows[count]++;
    }

    // STEP 3 - perform all possible combinations of EC
    int resultMatrix[5][20][4] = { [0][0][0] = 2, [1][0][0] = 2, [2][0][0] = 2, [3][0][0] = 2, [4][0][0] = 2 };
    for (int i = 0; i < 4; i++) {
        int row = 0;
        for (int j1 = 0; sortedMatrix[i][j1][0] != 2; j1++) {
            for (int j2 = 0; sortedMatrix[i][j2][0] != 2; j2++) {
                int column = -1;

                // Find the position of separate bits if only one pair
                for (int k = 0; k < 4; k++) {
                    if ((sortedMatrix[i][j1][k] == 1 && sortedMatrix[i + 1][j2][k] == 0) || (sortedMatrix[i][j1][k] == 0 && sortedMatrix[i + 1][j2][k] == 1)) {
                        if (column == -1) {
                            column = k;
                        } else {
                            column = -1;
                            break;
                        }
                    }
                }

                if (column != -1) {
                    resultMatrix[i][row][0] = sortedMatrix[i][j1][0];
                    resultMatrix[i][row][1] = sortedMatrix[i][j1][1];
                    resultMatrix[i][row][2] = sortedMatrix[i][j1][2];
                    resultMatrix[i][row][3] = sortedMatrix[i][j1][3];
                    resultMatrix[i][row][column] = -1;
                    row++;
                    resultMatrix[i][row][0] = 2;
                }
            }
        }
    }

    // Output table
    for (int i = 0; i < 5; i++) {
        for (int j = 0; resultMatrix[i][j][0] != 2; j++) {
            for (int k = 0; k < 4; k++) {
                if (resultMatrix[i][j][k] == -1) {
                    printf("- ");
                } else {
                    printf("%d ", resultMatrix[i][j][k]);
                }
            }
            printf("\n");
        }
    }

    // Output final result
    printf("SDNF:\n");
    char result[250] = "";
    for (int i = 0; i < 5; i++) {
        for (int j = 0; resultMatrix[i][j][0] != 2; j++) {
            strcat(result, "(");

            for (int k = 0; k < 4; k++) {
                switch (resultMatrix[i][j][k]) {
                case -1:
                    break;
                case 0:
                    strcat(result, "!");
                case 1:
                    switch (k) {
                    case 0:
                        strcat(result, "W^");
                        break;
                    case 1:
                        strcat(result, "X^");
                        break;
                    case 2:
                        strcat(result, "Y^");
                        break;
                    case 3:
                        strcat(result, "Z^");
                        break;
                    default:
                        printf("Something went wrong. End of program.");
                        return 1;
                    }
                    break;
                default:
                    printf("Something went wrong. End of program.");
                    return 1;
                }
            }

            result[strlen(result) - 1] = '\0';
            strcat(result, ")v");
        }
    }
    result[strlen(result) - 1] = '\0';

    printf("%s", result);
}