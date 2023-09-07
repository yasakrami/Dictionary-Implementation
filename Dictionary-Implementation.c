#include <stdio.h>   
#include <string.h>   
#include <ctype.h>  
  
  
#define SIZE 10   
#define LETTERS 20   
   
struct dictionary {   
    char eng[LETTERS];   
    char turk[LETTERS];   
};   
 
int main() {   
    struct dictionary dict[SIZE];   
    int next[SIZE];   
    int size = 0;   
    int initial = -1;   
   
    char input[LETTERS];   
    int inp = 0;   
    for (int i = 0; i < SIZE; i++) {   
        next[i] = i + 1;   
    }   
    next[SIZE - 1] = -1;   
     
     
    while (inp != 4) {   
        printf("\n<<Welcome to the Dictionary of Arrays>>\n");  
        printf("\n\nOptions:\n");   
        printf("1)Adding a new word\n");   
        printf("2)Deleting a word\n");   
        printf("3)Viewing the dictionary\n");   
        printf("4)Quit\n");   
        printf("\nEnter your choice: ");   
        scanf("%d", &inp);   
        switch (inp) {   
            case 1:   
                if (size >= SIZE) {   
                    printf("No other elements can be added!\n");   
                }  
                else {   
                    printf("English word: ");   
                    scanf("%s", input);   
                    for (int i = 0; i < strlen(input); i++) {   
                        input[i] = tolower(input[i]);   
                    }   
                    strcpy(dict[size].eng, input);   
                    printf("Turkish word: ");   
                    scanf("%s", input);   
                    strcpy(dict[size].turk, input);   
                    int now = initial;   
                    int pre = -1;   
                    while (now != -1 && strcmp(dict[now].eng, dict[size].eng) < 0) {   
                        pre = now;   
                        now = next[now];   
                    }   
                    if (pre == -1) {   
                        next[size] = initial;   
                        initial = size;   
                    } else {   
                        next[pre] = size;   
                        next[size] = now;   
                    }   
                    size++;   
                    printf("The word is added\n");   
                }   
                break;   
                   
        case 2:  
            if (size == 0) {  
                printf("There is no element\n");  
            }   
            else {  
                
                printf("Enter the english word:");  
                scanf("%s", input);  
                for (int i = 0; i < strlen(input); i++) {  
                    input[i] = tolower(input[i]);  
                }  
                while(getchar() != '\n');  
                int now = initial;  
                int pre = -1;  
                int delete = -1;  
                while (now != -1) {  
                    if (strcmp(dict[now].eng, input) == 0) {  
                        delete = now;  
                        break;  
                    }  
                    pre = now;  
                    now = next[now];  
                }  
                  
                if (delete == -1) {  
                    printf("'%s' is not an element of dictionary\n", input);  
                } else {  
                    if (pre == -1) {  
                        initial = next[delete];  
                    } else {  
                        next[pre] = next[delete];  
                    }  
                    if (delete == size - 1) {  
                        next[delete] = -1;  
                    } else {  
                        next[delete] = next[size - 1];  
                        strcpy(dict[delete].eng, dict[size - 1].eng);  
                        strcpy(dict[delete].turk, dict[size - 1].turk);  
                        pre = -1;  
                        now = initial;  
                        while (now != -1) {  
                            if (next[now] == size - 1) {  
                                pre = now;  
                                break;  
                            }  
                            now = next[now];  
                        }
if (pre == -1) {  
                            initial = delete;  
                        } else {  
                            next[pre] = delete;  
                        }  
                    }  
                    size--;  
                    printf("'%s' is removed from the dictionary.\n", input);  
                }  
            }  
            break;  
            case 3:   
                if (size == 0) {   
                    printf("No element to delete\n");   
                }   
                else {   
                    printf("<English>  <Turkish>\n");   
                      
                    int now = initial;   
                    while (now != -1) {   
                        printf("<%s>\t\t<%s>\n", dict[now].eng, dict[now].turk);   
                        now = next[now];   
                    }   
                }   
                break;   
            case 4:   
                printf("Finish\n");   
                break;   
            default:   
                printf("Choose again\n");   
        }   
    }   
   
    return 0;   
}


/* Pseudocode:

DEFINE SIZE as 10
DEFINE LETTERS as 20

STRUCT dictionary
    DECLARE eng as array of LETTERS characters
    DECLARE turk as array of LETTERS characters
END STRUCT

DECLARE dict as array of SIZE dictionary structures
DECLARE next as array of SIZE integers
DECLARE size as integer and set to 0
DECLARE initial as integer and set to -1
DECLARE input as array of LETTERS characters
DECLARE inp as integer and set to 0

FOR i = 0 to SIZE-1
    SET next[i] to i + 1
END FOR
SET next[SIZE - 1] to -1
WHILE inp != 4 DO
    PRINT "Welcome to the Dictionary of Arrays"
    PRINT "Options:"
    PRINT "1) Adding a new word"
    PRINT "2) Deleting a word"
    PRINT "3) Viewing the dictionary"
    PRINT "4) Quit"
    PRINT "Enter your choice: "
    SCAN inp

    SWITCH inp DO
        CASE 1:
            IF size >= SIZE THEN
                PRINT "No other elements can be added!"
            ELSE
                PRINT "English word: "
                SCAN input
                FOR i = 0 to length of input - 1
                    input[i] = tolower(input[i])
                END FOR
                SET dict[size].eng to input

                PRINT "Turkish word: "
                SCAN input
                SET dict[size].turk to input

                SET now to initial
                SET pre to -1
                WHILE now != -1 AND strcmp(dict[now].eng, dict[size].eng) < 0 DO
                    SET pre to now
                    SET now to next[now]
                END WHILE

                IF pre == -1 THEN
                    SET next[size] to initial
                    SET initial to size
                ELSE
                    SET next[pre] to size
                    SET next[size] to now
                END IF

                INCREMENT size
                PRINT "The word is added"
            END IF
            BREAK
            CASE 2:
            IF size EQUALS 0 THEN
                PRINT "There is no element"
            ELSE
                PRINT "Enter the english word:"
                SCANF input
                FOR i = 0 TO strlen(input) DO
                    input[i] = tolower(input[i])
                ENDFOR
                WHILE (getchar() NOT EQUALS '\n')
                    DO
                    continue
                ENDWHILE
                now = initial
                pre = -1
                delete = -1
                WHILE (now NOT EQUALS -1)
                    DO
                    IF (strcmp(dict[now].eng, input) EQUALS 0)
                        THEN
                        delete = now
                        BREAK
                    ENDIF
                    pre = now
                    now = next[now]
                ENDWHILE
                IF (delete EQUALS -1)
                    THEN
                    PRINT "'%s' is not an element of dictionary", input
                ELSE
                    IF (pre EQUALS -1)
                        THEN
                        initial = next[delete]
                    ELSE
                         next[pre] = next[delete]        
                    ENDIF
                    IF (delete EQUALS size - 1)
                    THEN
                        next[delete] = -1
                    ELSE
                        next[delete] = next[size - 1]
                        strcpy(dict[delete].eng, dict[size - 1].eng)
                        strcpy(dict[delete].turk, dict[size - 1].turk)
                    pre = -1
                    now = initial
                    WHILE (now NOT EQUALS -1)
                    DO
                        IF (next[now] EQUALS size - 1)
                    THEN
                        pre = now
                    BREAK
                    ENDIF
                    now = next[now]
                    ENDWHILE
                    IF (pre EQUALS -1)
                        THEN
                        initial = delete
                    ELSE
                        next[pre] = delete
                    ENDIF
                    size = size - 1
                    PRINT "'%s' is removed from the dictionary.", input
                    ENDIF
            CASE 3:
                 IF SIZE == 0:
                    PRINT "NO ELEMENT TO DELETE"
                ELSE:
                     PRINT "<ENGLISH>  <TURKISH>"
                NOW = INITIAL
                WHILE NOW != -1:
                    PRINT "<%s>\t\t<%s>\n" % (DICT[NOW].ENG, DICT[NOW].TURK)
                    NOW = NEXT[NOW]
                END WHILE
                END IF
                BREAK
            CASE 4:
                 PRINT "FINISH"
                BREAK
            DEFAULT:
                PRINT "CHOOSE AGAIN"
            END SWITCH
RETURN 0

END


*/