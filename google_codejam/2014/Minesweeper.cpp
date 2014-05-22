
#include <stdio.h>
#include <string.h>

#define N 50

char mines[N][N];


int putMines(int R0, int R1, int C0, int C1, int M, int f) {
    int j;
    int sR = R1 - R0;
    int sC = C1 - C0;
    if (sR == 0) return M;
    if (sC == 0) return M;

    if (sR > sC && sR > 2 && M >= C1 - C0) {
	M -= C1 - C0;
	for(j = C0; j < C1; j++) mines[R0][j] = '*';
	return (M > 0) ? putMines(R0 + 1, R1, C0, C1, M, f) : 0;
    }
    if (sC > 2 && M >= R1 - R0) {
	M -= R1 - R0;
	for (j = R0; j < R1; j++) mines[j][C0] = '*';
	return (M > 0) ? putMines(R0, R1, C0 + 1, C1, M, f) : 0;
    }
    if (sR > 2 && M >= C1 - C0) {
	M -= C1 - C0;
	for(j = C0; j < C1; j++) mines[R0][j] = '*';
	return (M > 0) ? putMines(R0 + 1, R1, C0, C1, M, f) : 0;
    }
    if (sR > sC && (sC > 2 || f)) {
	for (j = R0; M > 0 && j < R1 - 2 + 2 * f; j++) {
	    mines[j][C0] = '*';
	    M--;
	}
	return (M > 0) ? putMines(R0, R1, C0 + 1, C1, M, f) : 0;
    }
    if (sR > 2 || f) {
	for (j = C0; M > 0 && j < C1 - 2 + 2 * f; j++) {
	    mines[R0][j] = '*';
	    M--;
	}
	return (M > 0) ? putMines(R0 + 1, R1, C0, C1, M, f) : 0;
    }
    return M;
 }

main() {
    int i, T;
    int R, C, M;
    int j, k;
    int mR, fill, mine, cr, cc;
    int d, rC, U;

    scanf("%d\n", &T);
    for (i = 0; i < T; i++) {
	printf("Case #%d:\n", i + 1);
	scanf("%d %d %d", &R, &C, &M);

	cr = R - 1;
	cc = C - 1;

	memset(mines, (int)'.', N * N);
	M = putMines(0, R, 0, C, M, (R * C - M) == 1);

	if ( M ) printf("Impossible\n");
	else {
	    mines[cr][cc] = 'c';
	    for (k = 0; k < R; k++) {
		for (j = 0; j < C; j++) {
		    printf("%c", mines[k][j]);
		}
		printf("\n");
	    }
	}
    }
}
