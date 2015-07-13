#include "Graph.h"
#include "SpriteBatch.h"
#include "Texture.h"
#include "MathLib.h"
#include <stdlib.h>
#include <queue>
using namespace MathLib;

Vector2 lerp(Vector2 a, Vector2 b, float time){
	return ((1 - time) * a + time * b);
}

Node::Node(Vector2 a_Data){
	data = a_Data;
	N = NULL;
	F = std::numeric_limits<float>().max();
	G = std::numeric_limits<float>().max();
}

Node::~Node(){
	std::vector<Edge*>::iterator iter = a_edgy.begin();
	while (iter != a_edgy.end()){
		// Deletes data.
		delete (*iter);
		// Erase iter.
		iter = a_edgy.erase(iter);
	}
}

void Node::DrawEdges(SpriteBatch* m_SpriteBatch){
	std::vector<Edge*>::iterator iter = a_edgy.begin();
	while (iter != a_edgy.end()){
		m_SpriteBatch->DrawLine(data.x, data.y, (*iter)->b_node->data.x, (*iter)->b_node->data.y, 2.f);

		Vector2 temp = lerp((*iter)->b_node->data, data, 0.25f);
		m_SpriteBatch->SetRenderColor(255, 0, 0, 255);
		m_SpriteBatch->DrawLine((*iter)->b_node->data.x, (*iter)->b_node->data.y, temp.x, temp.y, 2.f);
		m_SpriteBatch->SetRenderColor(255, 255, 255, 255);
		iter++;
	}
}

Edge::Edge(Node* a, Node* b, float cost){
	a_node = a;
	b_node = b;
	a_cost = cost;
}

Graph::~Graph(){
	std::vector<Node*>::iterator iter = a_list.begin();
	while (iter != a_list.end()){
		// Deletes data.
		delete (*iter);
		// Erase iter.
		iter = a_list.erase(iter);
	}
}

void Graph::AddNode(Vector2 a_Position)
{
	// Add node at a_Position to node list. Has no edges.
	a_list.push_back(new Node(a_Position));
}

void Graph::AddEdge(Node* a_one, Node* a_two, float cost)
{
	// Check if edge already exists.
	std::vector<Edge*>::iterator iter = a_one->a_edgy.begin();
	while (iter != a_one->a_edgy.end()){
		if ((*iter)->b_node == a_two){
			return;
		}
		iter++;
	}

	// Make the graph a directed graph.
	if (directed)
	{
		iter = a_two->a_edgy.begin();
		while (iter != a_two->a_edgy.end()){
			if ((*iter)->b_node == a_one){
				return;
			}
			iter++;
		}
	}

	// Add edge to node_a's edge list.
	a_one->a_edgy.push_back(new Edge(a_one, a_two, cost));
}

void Graph::RemoveEdge(Node* a_one, Node* a_two)
{
	// Start at beginning of edge list.
	std::vector<Edge*>::iterator iter = a_one->a_edgy.begin();
	// Loop through to find if current edge is connected to b_node.
	while (iter != a_one->a_edgy.end())
	{
		if ((*iter)->b_node == a_two)
		{
			// We found the edge.
			// Delete data, and remove the pointer from edge list.
			delete (*iter);
			a_one->a_edgy.erase(iter);
			
			// End loop. (Jump ahead).
			iter = a_one->a_edgy.end();
		}
		else
		{
			// Increase iter.
			iter++;
		}
	}
}

void Graph::RemoveNode(Node* node)
{

	// Safety check.
	std::vector<Node*>::iterator iter = std::find(a_list.begin(), a_list.end(), node);
	if (iter != a_list.end())
	{
		// Start at beginning of node list.
		iter = a_list.begin();
		while (iter != a_list.end())
		{
			// If not comparing to self.
			if ((*iter) != node)
			{
				// Remove input node from iter node.
				RemoveEdge((*iter), node);
				iter++;
			}
			else
			{
				// Increase iter.
				iter++;
			}
		}

		// All edges should be deleted by this point.
		// Delete pointer and then data if found.
		delete node;
		iter = std::find(a_list.begin(), a_list.end(), node);
		if (iter != a_list.end())
		{
			a_list.erase(iter);

		}
	}
}

void Graph::Draw(Texture* a_Texture, SpriteBatch* m_SpriteBatch){
	// Cycle through all nodes and draw at location, then call DrawEdges on node.
	std::vector<Node*>::iterator iter = a_list.begin();
	while (iter != a_list.end()){
		(*iter)->DrawEdges(m_SpriteBatch);
		iter++;
	}
	iter = a_list.begin();
	while (iter != a_list.end()){
		m_SpriteBatch->DrawSprite(a_Texture, (*iter)->data.x, (*iter)->data.y);
		iter++;
	}
}

void Graph::BFS(Node* startNode){
	// Create variables.
	deque<Node*> a_openList;
	list <Node*> a_closedList;
	Node* currentNode = nullptr;

	// Add start node to list.
	a_openList.push_back(startNode);

	// While list is not empty.
	while (!a_openList.empty()){

		// Current node = next item.
		currentNode = (*a_openList.begin());

		// Process item.
		std::cout << "Node on stack: " << currentNode->data.x << ", " << currentNode->data.y << "\n";
	
		// Remove current node from list.
		a_openList.erase(std::find(a_openList.begin(), a_openList.end(), currentNode));
		// Add current node to closed list.
		a_closedList.push_back(currentNode);

		// For all connections in currentNodes add to open list.
		std::vector<Edge*>::iterator iter = currentNode->a_edgy.begin();
		while (iter != currentNode->a_edgy.end()){
			if (std::find(a_closedList.begin(), a_closedList.end(), (*iter)->b_node) == a_closedList.end())
			{
				if (std::find(a_openList.begin(), a_openList.end(), (*iter)->b_node) == a_openList.end())
				{
					a_openList.push_back((*iter)->b_node);
				}
			}
			iter++;
		}
	}
}

void Graph::DSP(Node* startNode, Node* endNode)
{
	priority_queue<Node*> a_openList;
	Node* currentNode = startNode;
	currentNode->N = currentNode;
	currentNode->G = 0.0f;
	a_openList.push(currentNode);

	while (!a_openList.empty())
	{
		currentNode = a_openList.top();
		a_openList.pop();
		currentNode->traversed = true;

		std::vector<Edge*>::iterator iter = currentNode->a_edgy.begin();
		while (iter != currentNode->a_edgy.end())
		{
			if (!(*iter)->b_node->traversed)
			{
				if ((currentNode->G + (*iter)->a_cost) < (*iter)->b_node->G)
				{
					(*iter)->b_node->N = currentNode;
					(*iter)->b_node->G = (currentNode->G + (*iter)->a_cost);
					a_openList.push((*iter)->b_node);
				}
			}
			iter++;
		}

	}
}

void Graph::AStar(Node* startNode, Node* endNode)
{
	priority_queue<Node*> a_openList;
	Node* currentNode = startNode;
	currentNode->N = currentNode;
	currentNode->G = 0.0f;
	a_openList.push(currentNode);

	while (!a_openList.empty())
	{
		currentNode = a_openList.top();
		a_openList.pop();
		currentNode->traversed = true;

		std::vector<Edge*>::iterator iter = currentNode->a_edgy.begin();
		while (iter != currentNode->a_edgy.end())
		{
			if (!(*iter)->b_node->traversed)
			{
				if ((currentNode->G + (*iter)->a_cost + Vector2(currentNode->data - endNode->data).SqrMagnatude()) < (*iter)->b_node->F)
				{
					(*iter)->b_node->N = currentNode;
					(*iter)->b_node->G = (currentNode->G + (*iter)->a_cost);
					(*iter)->b_node->F = (currentNode->G + (*iter)->a_cost + Vector2(currentNode->data - endNode->data).SqrMagnatude());
					a_openList.push((*iter)->b_node);
				}
			}
			iter++;
		}

	}
}

int Graph::GetSize(){ return a_list.size(); }

Node* Graph::operator[](int index){
	std::vector<Node*>::iterator iter = a_list.begin() + index;
	return (*iter);
}