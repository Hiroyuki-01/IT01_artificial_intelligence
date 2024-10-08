/**
 * @file func.c
 * @date 2016/10/04
 * @author Yuta Kobiyama (m5191140@u-aizu.ac.jp)
 * @brief DFSおよびBFSの実装。
 * @details
 *  人工知能、第二演習\n
 *  Copyright (C) 2016 System Intelligence Laboratory, All Rights Reserved
 */

#include "prog_02.h"
#include <stdbool.h>
#include <stdio.h>


static void dfs_visit(Graph const*, VertexState*, size_t);


/**
 * @brief 深さ優先探索（DFS）の関数。
 * @param g 指定されたグラフへのポインタ。
 */
void dfs(Graph const* g)
{
    printf("DFS: ");

    // 全ての頂点の状態をUNVISITEDにリセットする。
    VertexState vertex_states[MAX_VERTEX_SIZE];
    for (size_t i = 0; i < g->vertex_count; i++) {
        vertex_states[i] = UNVISITED;
    }

    // TODO: 1. DFSを開始するための引数を設定する。
    dfs_visit(g,vertex_states,g->vertex_starting_search);
    putchar('\n');
}


/**
 * @brief DFSの再帰呼び出し用関数。
 * @param g 指定されたグラフへのポインタ。
 * @param vertex_states 頂点の状態配列へのポインタ。
 * @param current_vertex 現在注目している頂点。
 */
static void dfs_visit(Graph const* g, VertexState* vertex_states, size_t current_vertex)
{
    // 現在の頂点番号を表示する。
    printf("%zu ", current_vertex);

    // TODO: 2. 現在の頂点の状態を変更する。
    vertex_states[current_vertex] = VISITED;

    // 子頂点をループする。
    for (size_t i = 0; i < g->vertex_count; i++) {
        // TODO: 3. i番目の頂点が未訪問かつ現在の頂点と接続されている場合、再帰的にi番目の頂点を訪問する。
        if ((vertex_states[i] == UNVISITED) && (g->adjacent_matrix[current_vertex][i] == CONNECTED)) {
            dfs_visit(g, vertex_states, i);
        }
    }
}


/**
 * @brief 幅優先探索（BFS）の関数。
 * @param g 指定されたグラフへのポインタ。
 */
void bfs(Graph const* g)
{
    printf("BFS: ");

    // 全ての頂点の状態をUNVISITEDにリセットする。
    VertexState vertex_states[MAX_VERTEX_SIZE];
    for (size_t i = 0; i < g->vertex_count; i++) {
        vertex_states[i] = UNVISITED;
    }

    // 探索プロセスを追跡するためのキューを初期化する。
    s_queue_init(NULL);

    // TODO: 4. BFSを開始するための引数を設定する。
    // 探索を開始する頂点を設定する。
    s_queue_enqueue(g->vertex_starting_search);

    // TODO: 5. 探索開始のため、開始頂点の状態を設定する。
    // 開始頂点がキューにあり、その状態をVISITEDにする。
    vertex_states[g->vertex_starting_search] = VISITED;

    while (s_queue_is_empty() == false) {
        size_t current_vertex = s_queue_dequeue();
        printf("%zu ", current_vertex);

        // 子頂点をループする。
        for (size_t i = 0; i < g->vertex_count; i++) {
            // TODO: 6. i番目の頂点が未訪問かつ現在の頂点と接続されている場合、キューに追加する。
            if (vertex_states[i] == UNVISITED && g->adjacent_matrix[current_vertex][i] == CONNECTED) {
                vertex_states[i] = VISITED;
                s_queue_enqueue(i);
            }
        }
    }

    putchar('\n');
}
