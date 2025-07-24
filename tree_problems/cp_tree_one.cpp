/* Alex is playing a game in Hackerland and needs to collect coins from various locations. THe city is represented as a tree with n vertices labelled from 0 to n - 1. There is an array called coins of size n, where coins[i] is either 0 or 1, where 1 means the vertex contains a coin.

Alex must travel the tree's edges to collect all the coins. Alex can choose any vertex, but must start and end at that vertex. The path can traverse the same edge multiple times, and all edges are bidirectional.

Return the number of edges in the shortest path along which Alex can collect all the coins.
LeetCode: 2603

Example:
tree_nodes = 11
tree_from = [0,0,0,1,1,3,4,6,7,8]
tree_to = [1,2,6,3,4,10,5,7,8,9]
coin = [0,0,1,1,0,0,0,0,0,1,1]
*/
// function signature

#include <bits/stdc++.h>
using namespace std;

int getMinPath(vector<int> coins, int tree_nodes, vector<int> tree_from, vector<int> tree_to) {
}

int main() {
	vector<int> coins = {0,0,1,1,0,0,0,0,0,1,1};
	vector<int> tree_from = {0,0,0,1,1,3,4,6,7,8};
	vector<int> tree_to = {1,2,6,3,4,10,5,7,8,9};
	int tree_nodes = 11;
 	cout<<getMinPath(coins, tree_nodes, tree_from, tree_to);
}
