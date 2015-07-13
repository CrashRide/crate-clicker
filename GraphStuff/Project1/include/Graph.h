#pragma once
#include <vector>
#include <deque>
#include <list>
class SpriteBatch;
class Texture;
#include "MathLib.h"
using namespace MathLib;
using namespace std;

struct Edge;

struct Node
{
	Node(Vector2 a_Data);
	~Node();
	Node* N;
	float G;
	Vector2 data;
	vector<Edge*> a_edgy;
	void DrawEdges(SpriteBatch* m_SpriteBatch);
	bool traversed = false;
};

struct Edge
{
	Edge(Node* a, Node* b, float cost);
	Node* a_node;
	Node* b_node;
	float a_cost;

};

class Graph
{
public:
	~Graph();
	void AddNode(Vector2 a_Position);
	void AddEdge(Node* a_one, Node* a_two, float cost);
	void RemoveEdge(Node* a_one, Node* a_two);
	void RemoveNode(Node* node);
	void Draw(Texture* a_Texture, SpriteBatch* m_SpriteBatch);
	void BFS(Node* startNode);
	void DSP(Node* startNode, Node* endNode);
	int GetSize();
	Node* operator[](int index);

	// Directed. Maybe make private.
	bool directed;

private:
	vector<Node*> a_list;
	
};