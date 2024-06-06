//
// Created by dell on 26-05-2024.
//

#ifndef IDDFSSOLVER_H
#define IDDFSSOLVER_H
#include "bits/stdc++.h"
#include "../Model/RubiksCube.h"
#include "DFSSolver.h"
// Typename T: RubiksCube Representation used (3d, 1d, Bitboard)
// Typename H: Corresponding Hash function
template <typename T,typename H>
class IDDFSSolver {
private:
    vector<RubiksCube::MOVE> moves;
    uint8_t max_depth;
public:
    T rubikscube;

    IDDFSSolver(T _rubikscube,uint8_t dep=8) {
        max_depth=dep;
        rubikscube=_rubikscube;
    }
    vector<RubiksCube::MOVE> solve() {
        for(int i=1;i<max_depth;i++) {
            DFSSolver<T,H> dfs_solver(rubikscube,i);
            moves=dfs_solver.solve();
            if(dfs_solver.rubikscube.isSolved()) {
                rubikscube=dfs_solver.rubikscube;
                break;
            }
        }
        return moves;
    }
};
#endif //IDDFSSOLVER_H
