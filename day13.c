char* clearDigits(char* s) {
    char stack[100005];
    int top = -1;

    for (int i = 0; s[i] != '\0'; i++) {
        if (!isdigit(s[i])) {
            // Push non-digit
            stack[++top] = s[i];
        } else {
            // Digit found → remove closest left non-digit
            if (top >= 0)
                top--;
        }
    }

    // Convert stack to string
    stack[top + 1] = '\0';

    // Copy result into s
    strcpy(s, stack);
    return s;
}