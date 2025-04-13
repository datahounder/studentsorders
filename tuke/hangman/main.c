#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void hangman(int n){ //������� ��������� �� ����� ����������� ��������
    switch (n) {
    case 9: printf("  ____ |\n |   | |\n |   O |\n |  /|\\|\n_|_ / \\|  "); break;
    case 8: printf("  ____ |\n |   | |\n |   O |\n |  /|\\|\n_|_ /  |  "); break;
    case 7: printf("  ____ |\n |   | |\n |   O |\n |  /|\\|\n_|_    |  "); break;
    case 6: printf("  ____ |\n |   | |\n |   O |\n |  /| |\n_|_    |  "); break;
    case 5: printf("  ____ |\n |   | |\n |   O |\n |   | |\n_|_    |  "); break;
    case 4: printf("  ____ |\n |   | |\n |   O |\n |     |\n_|_    |  "); break;
    case 3: printf("  ____ |\n |     |\n |     |\n |     |\n_|_    |  "); break;
    case 2: printf("       |\n |     |\n |     |\n |     |\n_|_    |  "); break;
    case 1: printf("       |\n       |\n       |\n       |\n___    |  "); break;
    case 0: printf("       |\n       |\n       |\n       |\n       |  "); break;
    }
}
int main()
{
    system("chcp 1251");
    system("cls");
    FILE* txt;
    char word[80], enterLetter[33] = {0}, scanChar;
    double buffer;
    int i, flag = 0, sizeFile = 0, rndStr, sizeWord, guessChar, guessErr = 0, countLetter = 0;
    srand(time(NULL));
    if (!(txt = fopen("slova.txt", "r"))){ // ��������� ������ �� ���� �� �������
        printf("������ �������� �����!");
        return 1;
    }
    while (fscanf(txt, "%s", &buffer) != EOF) // �������� ���������� ����� � ����� �� �������
        sizeFile++;
    rndStr = rand() % sizeFile; // �������� ��������� ����� ������ �� �����
    fseek(txt, 0, SEEK_SET); // ��������� ������ �� ������ �����
    for (i = 0; i < rndStr; i++){ // �������� ��������� ������ � ������� rndStr (��� ����� ���������� �����)
        fscanf(txt, "%s", word);
    }
    fclose(txt);
    sizeWord = strlen(word); // ������� ���������� ���� � ������
    char *secretWord = (char*)calloc(sizeWord, sizeof(char)); // ����������� ����� ������ ������, � ������� ����� ������������ ���=�������� �����
    memset(secretWord, '_', sizeWord); // ��������� ��� ������� ���������������
    guessChar = sizeWord;
    while (guessChar >= 0 && guessErr <= 9) {
        if (flag == 1){guessErr++;} // ���� ����� 1 ��� ������������ �����
        system("cls");
        hangman(guessErr);
        if (guessChar == 0){ // ���� ���������� ������������ ���� = 0, �� ������
            printf("%s", word);
            printf("\n�� ��������!");
            free(secretWord);
            getchar();
            return 0;
        }
        if (guessErr == 9){ // ���� ���������� �������� ���������� ���� = 9, �� ���������
            printf("%s", word);
            printf("\n�� ���������(");
            free(secretWord);
            getchar();
            return 0;
        }
        printf("%s", secretWord);
        printf("\n�������� �����:\n");
        printf("%s", enterLetter);
        printf("\n������� �����: ");
        scanChar = getchar();
        getchar();
        if (!((((int)scanChar >= -64 && (int)scanChar <= -33) || (int)scanChar == -88) || (((int)scanChar >= -32 && (int)scanChar <= -1) || (int)scanChar == -72))){ // ������� �� �������� �������� �� �����������
            continue;
        } else if ((int)scanChar >= -32 && (int)scanChar <= -1) { // ������� ����� ������������� � ���������
            scanChar = (char)((int)scanChar - 32);
        } else if ((int)scanChar == -72) { // ��� ������ �
            scanChar = (char)(-88);
        }
        flag = 1;
        for (i = 0; i < sizeWord; i++){ // ���� ��������� ������ ����� �� ������������ ��������
            if (word[i] == scanChar) {
                if (!(strchr(secretWord + i, scanChar))) { // ���� ����� ����� ��� �� ���� ��������, �� �����������
                    flag = 0;
                    guessChar--;
                    secretWord[i] = word[i];
                }
            } else if (strchr(enterLetter, scanChar)) { // ���� ����� ��� ���� �������
                flag = 0;
            }
        }
        if (!(strchr(enterLetter, scanChar))){ // ������ � ������ �������� ����
            enterLetter[countLetter++] = scanChar;
        }
    }
    free(secretWord);
    return 0;
}
