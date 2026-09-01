class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();

        int sr = 0, sc = 0;
        int cnt = 0;

        // Give every litter cell a bit number
        vector<vector<int>> id(m, vector<int>(n, -1));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (classroom[i][j] == 'S') {
                    sr = i;
                    sc = j;
                }

                if (classroom[i][j] == 'L') {
                    id[i][j] = cnt++;
                }
            }
        }

        // No litter
        if (cnt == 0)
            return 0;

        int fullMask = (1 << cnt) - 1;

        /*
            State:
            row, col, remaining energy, collected litter mask
        */

        struct State {
            int r, c, e, mask;
        };

        queue<State> q;

        // visited[r][c][energy][mask]
        vector<vector<vector<vector<bool>>>> visited(
            m,
            vector<vector<vector<bool>>>(
                n,
                vector<vector<bool>>(
                    energy + 1,
                    vector<bool>(1 << cnt, false)
                )
            )
        );

        q.push({sr, sc, energy, 0});
        visited[sr][sc][energy][0] = true;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        int moves = 0;

        while (!q.empty()) {

            int sz = q.size();

            while (sz--) {

                State cur = q.front();
                q.pop();

                int r = cur.r;
                int c = cur.c;
                int e = cur.e;
                int mask = cur.mask;

                // All litter collected
                if (mask == fullMask)
                    return moves;

                // No energy left
                if (e == 0)
                    continue;

                for (int k = 0; k < 4; k++) {

                    int nr = r + dr[k];
                    int nc = c + dc[k];

                    // Boundary check
                    if (nr < 0 || nr >= m ||
                        nc < 0 || nc >= n)
                        continue;

                    // Cannot enter obstacle
                    if (classroom[nr][nc] == 'X')
                        continue;

                    int newEnergy;
                    int newMask = mask;

                    /*
                        Moving normally costs 1 energy.

                        But when we enter R, energy is
                        immediately restored to maximum.
                    */
                    if (classroom[nr][nc] == 'R') {
                        newEnergy = energy;
                    }
                    else {
                        newEnergy = e - 1;
                    }

                    // Collect litter
                    if (classroom[nr][nc] == 'L') {
                        int bit = id[nr][nc];
                        newMask |= (1 << bit);
                    }

                    // Avoid repeated states
                    if (!visited[nr][nc][newEnergy][newMask]) {

                        visited[nr][nc][newEnergy][newMask] = true;

                        q.push({
                            nr,
                            nc,
                            newEnergy,
                            newMask
                        });
                    }
                }
            }

            moves++;
        }

        return -1;
    }
};