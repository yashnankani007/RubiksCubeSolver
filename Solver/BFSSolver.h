//
// Created by dell on 26-05-2024.
//

#ifndef BFSSOLVER_H
#define BFSSOLVER_H

#include "bits/stdc++.h"
#include "../Model/RubiksCube.h"
// Typename T: RubiksCube Representation used (3d, 1d, Bitboard)
// Typename H: Corresponding Hash function
template <typename T,typename H>
class BFSSolver {
private:
    vector<RubiksCube::MOVE> moves;
    unordered_map<T,bool,H> visited;
    unordered_map<T,RubiksCube::MOVE,H> move_done;
    T bfs() {
        queue<T> cube_config_queue;
        cube_config_queue.push(rubikscube);
        visited[rubikscube]=true;
        while(!cube_config_queue.empty()) {
            T top_cube=cube_config_queue.front();
            cube_config_queue.pop();
            if(top_cube.isSolved())
                return top_cube;
            for (uint8_t move=0;move<18;move++) {
                T curr=top_cube;
                curr.move(RubiksCube::MOVE(move));
                if(visited[curr])continue;
                visited[curr]=true;
                move_done[curr]=RubiksCube::MOVE(move);
                cube_config_queue.push(curr);
                curr.invert(RubiksCube::MOVE(move));
            }
        }
        return rubikscube;
    }
public:
    T rubikscube;
    BFSSolver(T _rubikscube) {
        rubikscube=_rubikscube;
    }
    vector<RubiksCube::MOVE> solve() {
        T solved_cube=bfs();
        assert(solved_cube.isSolved());
        T curr_cube=solved_cube;
        while(!(curr_cube==rubikscube)) {
            RubiksCube::MOVE move=RubiksCube::MOVE(move_done[curr_cube]);
            curr_cube.invert(move);
            moves.push_back(move);
        }
        rubikscube=solved_cube;
        reverse(moves.begin(),moves.end());
        return moves;
    }
};
#endif //BFSSOLVER_H
