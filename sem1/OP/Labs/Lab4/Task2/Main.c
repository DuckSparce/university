#include <math.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#define MAXCHARS 1000

int main()
{
    time_t rawtime;
    char timeBuffer[MAXCHARS];
    time(&rawtime);
    strftime(timeBuffer, 25, "[%Y-%m-%d %H:%M:%S]", localtime(&rawtime));

    FILE *logFile = fopen("logFile.txt", "w");
    if (logFile == NULL)
    {
        perror("Error opening the log file.");
        return 1;
    }

    // log
    char logBuffer[MAXCHARS] = " Program started.\n";
    fputs(strcat(timeBuffer, logBuffer), logFile);

    // 1. Prepare the source binary file
    FILE *givenDataFile = fopen("givenData.bin", "wb");
    if (givenDataFile == NULL)
    {
        perror("Error opening the input data file.");
        return 1;
    }
    double tempX, tempY, tempZ;

    printf("Enter x: ");
    scanf("%lf", &tempX);
    fwrite(&tempX, sizeof(double), 1, givenDataFile);

    printf("Enter y: ");
    scanf("%lf", &tempY);
    fwrite(&tempY, sizeof(double), 1, givenDataFile);

    printf("Enter z: ");
    scanf("%lf", &tempZ);
    fwrite(&tempZ, sizeof(double), 1, givenDataFile);

    // 2. Read values from the source file
    freopen("givenData.bin", "rb", givenDataFile);

    double x, y, z;
    fread(&x, sizeof(double), 1, givenDataFile);
    fread(&y, sizeof(double), 1, givenDataFile);
    fread(&z, sizeof(double), 1, givenDataFile);

    // log
    time(&rawtime);
    strftime(timeBuffer, 25, "[%Y-%m-%d %H:%M:%S]", localtime(&rawtime));
    sprintf(logBuffer, " Parameters file 'givenData.bin' opened. X = %lf, Y = %lf, Z = %lf.\n", x, y, z);
    fputs(strcat(timeBuffer, logBuffer), logFile);

    fclose(givenDataFile);

    // 3. Solve the arithmetic expression
    double result = pow(1 + pow(tan(z / 2), 2), sqrt(fabs(y) + x));
    printf("Result: %lf\n", result);

    // log
    time(&rawtime);
    strftime(timeBuffer, 25, "[%Y-%m-%d %H:%M:%S]", localtime(&rawtime));
    sprintf(logBuffer, " Expression calculated. Result = %lf.\n", result);
    fputs(strcat(timeBuffer, logBuffer), logFile);

    // 4. Write the answer to the result file
    int formatIdentifier = 0;
    printf("Enter the result file format: 0 - .bin, otherwise - .txt. ");
    scanf("%d", &formatIdentifier);

    if (formatIdentifier == 0)
    {
        FILE *resultFile = fopen("result.bin", "wb");
        if (resultFile == NULL)
        {
            perror("Error opening the result file.");
            return 1;
        }
        fwrite(&result, sizeof(double), 1, resultFile);
        fclose(resultFile);

        // log
        time(&rawtime);
        strftime(timeBuffer, 25, "[%Y-%m-%d %H:%M:%S]", localtime(&rawtime));
        sprintf(logBuffer, " Output file 'result.bin' saved.\n");
        fputs(strcat(timeBuffer, logBuffer), logFile);
    }
    else
    {
        FILE *resultFile = fopen("result.txt", "w");
        if (resultFile == NULL)
        {
            perror("Error opening the result file.");
            return 1;
        }
        char buffer[MAXCHARS];
        sprintf(buffer, "%lf", result);
        fputs(buffer, resultFile);
        fclose(resultFile);

        // log
        time(&rawtime);
        strftime(timeBuffer, 25, "[%Y-%m-%d %H:%M:%S]", localtime(&rawtime));
        sprintf(logBuffer, " Output file 'result.txt' saved.\n");
        fputs(strcat(timeBuffer, logBuffer), logFile);
    }
    printf("The result is written to the result file.");
    
    // log
    time(&rawtime);
    strftime(timeBuffer, 25, "[%Y-%m-%d %H:%M:%S]", localtime(&rawtime));
    sprintf(logBuffer, " Program ended.\n");
    fputs(strcat(timeBuffer, logBuffer), logFile);

    fclose(logFile);

    return 0;
}