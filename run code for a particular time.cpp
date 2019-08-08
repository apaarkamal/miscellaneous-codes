clock_t tt = clock();
    while (1) {
        clock_t z = clock() - tt;
        if ((double)z / CLOCKS_PER_SEC > 0.47)break;
    }