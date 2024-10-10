/**
 * @file prog_02.h
 * @date 2016/10/06
 * @author Yuta Kobiyama (m5191140@u-aizu.ac.jp)
 * @brief メインヘッダーファイル。
 * @details
 *  人工知能、第二演習\n
 *  Copyright (C) 2016 System Intelligence Laboratory, All Rights Reserved
 */

#ifndef PROG_02_H
#define PROG_02_H


#include "s_queue.h"
#include <stddef.h>


/**
 * @brief この列挙型は数値定数を持ちます。
 */
enum {
    MAX_VERTEX_SIZE = MAX_QUEUE_SIZE, //!< 頂点数の最大値を定義します。
};

/**
 * @enum vertex_state
 * @brief この列挙型は頂点の状態を定義します。
 */
enum vertex_state {
    VISITED,   //!< 頂点が訪問済みである場合にこの値を取ります。
    UNVISITED, //!< 頂点が未訪問である場合にこの値を取ります。
};
typedef enum vertex_state VertexState;

/**
 * @enum edge_state
 * @brief この列挙型はエッジの有無を定義します。
 */
enum edge_state {
    NOT_CONNECTED = 0, //!< エッジが存在しない場合にこの値を取ります。
    CONNECTED,         //!< エッジが存在する場合にこの値を取ります。
};
typedef enum edge_state EdgeState;

/**
 * @struct graph
 * @brief この構造体はグラフを定義します。
 */
struct graph {
    EdgeState adjacent_matrix[MAX_VERTEX_SIZE][MAX_VERTEX_SIZE]; //!< 隣接行列。
    size_t vertex_count;                                         //!< 頂点の数。
    size_t vertex_starting_search;                               //!< 探索を開始する頂点。
};
typedef struct graph Graph;


extern void dfs(Graph const*);
extern void bfs(Graph const*);


#endif
