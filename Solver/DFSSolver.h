//
// Created by dell on 26-05-2024.
//

#ifndef DFSSOLVER_H
#define DFSSOLVER_H

#include "bits/stdc++.h"
#include "../Model/RubiksCube.h"
// Typename T: RubiksCube Representation used (3d, 1d, Bitboard)
// Typename H: Corresponding Hash function
template <typename T,typename H>
class DFSSolver {
private:
    vector<RubiksCube::MOVE> moves;
    uint8_t max_depth;
    bool dfs(uint8_t depth) {
        if(rubikscube.isSolved()) return true;
        if(depth>max_depth) return false;
        for(int i=0;i<18;i++) {
            moves.push_back(RubiksCube::MOVE(i));
            rubikscube.move(RubiksCube::MOVE(i));
            if(dfs(depth+1))return true;
            rubikscube.invert(RubiksCube::MOVE(i));
            moves.pop_back();
        }
        return false;
    }
public:
    T rubikscube;
    DFSSolver(T _rubikscube,uint8_t dep=8) {
        max_depth=dep;
        rubikscube=_rubikscube;
    }
    vector<RubiksCube::MOVE> solve() {
        dfs(1);
        return moves;
    }
};
#endif //DFSSOLVER_H
