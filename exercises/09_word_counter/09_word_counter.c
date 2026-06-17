#include <stdio.h>
#include <string.h>
int main() {
    char str[]="Don't ask what your country can do for you, but ask what you can do for your country.";
    int wordCount = 0;
    
    char * token = strtok (str, " ");
    while (token != NULL) { ++wordCount; token = strtok(NULL, " "); }
    printf("单词数量: %d\n", wordCount);
    
    return 0;
}
