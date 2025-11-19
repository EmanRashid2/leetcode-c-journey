char * longestCommonPrefix(char ** strs, int strsSize){
    if (strsSize == 0) return strdup(""); // No strings

    // Start with the first string as the prefix
    char* prefix = strdup(strs[0]);
    int prefixLen = strlen(prefix);

    for (int i = 1; i < strsSize; i++) {
        int j = 0;
        // Compare characters of prefix with current string
        while (j < prefixLen && strs[i][j] != '\0' && prefix[j] == strs[i][j]) {
            j++;
        }
        prefixLen = j; // Update prefix length
        prefix[prefixLen] = '\0'; // Truncate prefix

        if (prefixLen == 0) break; // No common prefix
    }

    return prefix;
}

