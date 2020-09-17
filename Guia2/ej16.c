#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>


int main() {
    /*   0 1 2  3
     * 0 . - \0 d
     * 1 a d e  r
     * 2 q e f  z
     */
    char morse[36][10] = {
            ".-",  // a   -> 0
            "-...", // b
            "-.-.", // c
            "-..",  // d
            ".",    // .....
            "..-.",
            "--.",
            "....",
            "..",
            ".---",
            "-.-",
            ".-..",
            "--",
            "-.",
            "---",
            ".--.",
            "--.-",
            ".-.",
            "...",
            "-",
            "..-",
            "...-",
            ".--",
            "-..-",
            "-.--",
            "--..", // z
            "-----", // 0
            ".----", // 1
            "..---", // 2
            // ............
    };


    char palabra[] = "hol1 SOS va";
    int idx;

    for (int i = 0; i < strlen(palabra); ++i) {
        if(palabra[i] != ' '){
            idx = tolower(palabra[i]) - 97;
            if(idx < 0)
                idx = palabra[i] - 48 + 26;

            printf("%s   ", morse[idx]);
        }else{
            printf("\n");
        }
    }


    return 0;
}
