int romanCharToInt(char c) {
    switch(c) {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default: return 0; // Should not happen for valid input
    }
}

int romanToInt(char * s){
    int total = 0;
    int i = 0;
    while(s[i] != '\0') {
        int current = romanCharToInt(s[i]);
        int next = romanCharToInt(s[i+1]);

        if (next > current) {
            // Subtractive notation (IV, IX, etc.)
            total += (next - current);
            i += 2; // Skip next character as it's part of subtraction
        } else {
            total += current;
            i++;
        }
    }
    return total;
}

