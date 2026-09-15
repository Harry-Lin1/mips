int nucleotide_counts_goto(const char *dna, int counts[4]) {
    int i = 0;
    while (i < 4) {
        counts[i] = 0;
        i++;
    }

    const char *ptr = dna;

loop_start:
    if (*ptr == '\0') goto done;

    char current = *ptr;

    if (current == 'A') goto inc_a;
    if (current == 'C') goto inc_c;
    if (current == 'G') goto inc_g;
    if (current == 'T') goto inc_t;

    return -1; // Error for invalid character

inc_a:
    counts[0]++;
    goto next_char;
inc_c:
    counts[1]++;
    goto next_char;
inc_g:
    counts[2]++;
    goto next_char;
inc_t:
    counts[3]++;
    goto next_char;

next_char:
    ptr++;
    goto loop_start;

done:
    return 0;
}



