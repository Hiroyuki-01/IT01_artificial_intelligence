# EX_02

## Task
Submit the answer of each exercise within one week.

Before starting, read the source codes carefully, and try to
understand.  Do not forget (MUST!) to write a report in the
file summary_XX.txt. You may use English or Japanese.

Many comments are included in the `func.c` program.

## Summary of today's homework
The purpose of this homework is to make a program that can traverse
(depth first or breadth first) from a given initial node, visit all
other nodes, and print out the visited nodes.

幅優先探索(BFS)と深さ優先探索(DFS)を用いて、指定した頂点から、全ての頂
点を訪問し、訪問した順番で頂点の番号を出力するプログラムを作成する。

The program `func.c` is incomplete. You should complete the program by
following the comments written in the program.

コメントに従ってプログラム`func.c`を完成せよ。

## File to revise/complete

* `func.c` - add something in places marked by `TODO`
* `summary_XX.txt` (XX=exercise number) - write a report for this exercise in Japanese or English.

## To validate your answer

You can validate your answer using the following commands.

以下のコマンドで、プログラムをコンパイル、実行し、正しく実装できていることを確認できます（gccも自動でしてくれます）。

```sh
$ make test
```

If there is nothing after the line `diff ...`, your answer is correct.

以下のように`diff ...`の後に何も出力が出ていなければ正しく実装できていることになります。

```sh
$ make test
diff -y --suppress-common-lines answer_XX.txt result_XX.txt
```

where XX is the exercise number.

## Explanation of `prog_02.c`
- Build a graph based on data imported from the keyboard or an input file (`bool init_garph()`).
- inputファイルを読み込みグラフを初期化する。(`bool init_garph()`)

- Run `dfs()` and `bfs()` based on the built graph. (`dfs()` and `bfs()` are defined in `func.c`)
- 読み込んだグラフを用いて、`dfs()`, `bfs()`を実行する。(`dfs()`, `bfs()`は`func.c`で定義されている)

## prog_02.h
Definition of the graph structure is given in the header file.  
グラフ構造の定義

### vertex_state
```c
enum vertex_state {
    VISITED,   //!< Take this value if the vertex is visited.
    UNVISITED, //!< Take this value if the vertex is unvisited.
};
typedef enum vertex_state VertexState;
```

### edge_state
```c
enum edge_state {
    NOT_CONNECTED = 0, //!< Take this value if the edge does not exist.
    CONNECTED,         //!< Take this value if the edge exists.
};
``` 

### graph
```c
struct graph {
    EdgeState adjacent_matrix[MAX_VERTEX_SIZE][MAX_VERTEX_SIZE]; //!< The adjacent matrix.
    size_t vertex_count;                                         //!< The number of vertices.
    size_t vertex_starting_search;                               //!< The starting vertex for search.
};
``` 

## func.c
This is the file to revise/complete.  
このファイルのプログラムの穴埋めを行なう。

### dfs()
```
1. Initialize all nodes, to make them unvisited.
各ノードの初期化。各ノードをunvisited状態にしておく。

2. Traverse using `dfs_visit()`.
`dfs_visit()`で探索を行う。
```

### dfs_visit()
open list (stack) is implemented implicitly using a recursive function.  
open listの処理は再帰を使って(FILO)実装している。

### bfs()

```
1. Initialize all nodes, to make them unvisited.
各ノードの初期化。各ノードをunvisited状態にしておく。

2. Set the initial state, and change it to `visited`.
スタート位置の設定、スタート位置のノードの状態をvisitedに変更。

3. If the open list is not empty, go to 4; otherwise, stop.
open listが空でない場合、4へ。空の場合、終了。

4. Get one node from the open list, and use this node as the `current node`.
Find all child nodes of the current node, and put each of them to the
open list if it is `unvisited`.

open listから一つ取り出し、現在の位置のノードとする。現在の位置のノー
ドに隣接しているノードの中で、unvisited状態のノードをvisit状態に変更し
て、open listに入れる。3へ。
```
Here, open list is implemented using a queue.  
open listはqueue(FIFO)で実装してある。

## s_queue.c
- Implmentatoin of a sortable queue.
BFSに用いるsortable queueの実装。

### void s_queue_enqueue(size_t element)
- Insert a datum to the queue.
要素をキューに追加する。

### size_t s_queue_dequeue(void)
- Get (delete) a datum from the queue.
要素をキューから取り出す。

## s_queue.h
- Definition of the queue.
queueに使う関数の宣言。



