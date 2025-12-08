
// --- DEFI 3 : Labyrinthe (Mode Défi Algorithmique) ---
#define TAILLE_LABY 10

void genererLabyrinthe(int map[TAILLE_LABY][TAILLE_LABY]) {
    // Initialisation : Murs partout (1)
    for (int i = 0; i < TAILLE_LABY; i++) {
        for (int j = 0; j < TAILLE_LABY; j++) {
            map[i][j] = 1;
        }
    }

    // Stack pour la methode DFS
    int stack[100][2]; // Pile pour stocker les coordonnées
    int top = 0;

    // Début : Point (1, 1) est le départ
    int px = 1, py = 1;
    map[px][py] = 2; // Marqueur de départ (2)

    stack[top][0] = px;
    stack[top][1] = py;
    top++;

    // Mouvements possibles (de 2 cases pour sauter le mur)
    int dx[] = {-2, 2, 0, 0};
    int dy[] = {0, 0, -2, 2};

    while (top > 0) {
        // Pop de la pile
        top--;
        px = stack[top][0];
        py = stack[top][1];

        // Créer un tableau d'indices de direction et les mélanger
        int directions[] = {0, 1, 2, 3};
        for (int i = 0; i < 4; i++) {
            int j = rand() % 4;
            int temp = directions[i];
            directions[i] = directions[j];
            directions[j] = temp;
        }

        // Essayer les directions mélangées
        for (int i = 0; i < 4; i++) {
            int dir = directions[i];
            int nx = px + dx[dir];
            int ny = py + dy[dir];

            // Vérifier si la nouvelle position est valide et encore mur (1)
            if (nx > 0 && nx < TAILLE_LABY - 1 && ny > 0 && ny < TAILLE_LABY - 1 && map[nx][ny] == 1) {
                // Percer le mur au milieu (Chemin = 0)
                map[px + dx[dir] / 2][py + dy[dir] / 2] = 0;

                // Percer la nouvelle cellule (Chemin = 0)
                map[nx][ny] = 0;

                // Pousser la nouvelle position sur la pile
                stack[top][0] = nx;
                stack[top][1] = ny;
                top++;
            }
        }
    }