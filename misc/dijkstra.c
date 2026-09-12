#include <assert.h>
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define Infinity INT_MAX
#define MaxVertices SCHAR_MAX

struct edge {
	char vertices[2];
	int weight;
};

struct dijkstra_ret {
	int distance;
	char *vertices;
	int n;
};

static struct dijkstra_ret
dijkstra(struct edge *edges, int n, char start, char end)
{
	int *distance;
	bool *explored;
	char *parent;
	char v, w;
	int nearest;
	int weight;
	int i;
	struct dijkstra_ret ret = {0};

	assert(n > 0);
	assert(start > ' ' && start <= '~');
	assert(end > ' ' && end <= '~');

	distance = malloc(MaxVertices * sizeof(*distance));
	explored = malloc(MaxVertices * sizeof(*explored));
	parent = malloc(MaxVertices * sizeof(*parent));
	for (i = 0; i < MaxVertices; i++) {
		distance[i] = Infinity;
		explored[i] = false;
		parent[i] = 0;
	}
	v = start;
	distance[v] = 0;
	explored[v] = true;
	while (!explored[end]) {
		// Update estimates
		for (i = 0; i < n; i++) {
			w = 0;
			weight = edges[i].weight;

			assert(weight >= 0);

			if (v == edges[i].vertices[0]
			&& !explored[edges[i].vertices[1]])
				w = edges[i].vertices[1];
			else if (v == edges[i].vertices[1]
			&& !explored[edges[i].vertices[0]])
				w = edges[i].vertices[0];

			if (w != 0) {
				assert(w > ' ' && w <= '~');

				if (distance[w] > distance[v] + weight) {
					distance[w] = distance[v] + weight;
					parent[w] = v;
				}
			}
		}

		// Choose next vertex
		nearest = end;
		for (i = 0; i < MaxVertices; i++)
			if (!explored[i] && distance[i] < distance[nearest])
				nearest = i;
		v = nearest;
		explored[v] = true;
	}

	// Reconstruct the path
	for (v = end; v != 0; v = parent[v]) {
		ret.vertices = realloc(ret.vertices, (ret.n + 1) * sizeof(*ret.vertices));
		ret.vertices[ret.n++] = v;
		if (v == start)
			break;
	}
	for (i = 0; i < ret.n / 2; i++) {
		v = ret.vertices[i];
		ret.vertices[i] = ret.vertices[ret.n - 1 - i];
		ret.vertices[ret.n - 1 - i] = v;
	}
	ret.distance = distance[end];
	ret.vertices = realloc(ret.vertices, (ret.n + 1) * sizeof(*ret.vertices));
	ret.vertices[ret.n] = '\0';

	free(distance);
	free(explored);
	free(parent);
	return ret;
}

int
main(void)
{
	struct edge edges[] = {
		{{'A', 'C'}, 3},
		{{'A', 'F'}, 2},
		{{'C', 'F'}, 2},
		{{'C', 'E'}, 1},
		{{'C', 'D'}, 4},
		{{'D', 'B'}, 1},
		{{'F', 'E'}, 3},
		{{'F', 'B'}, 6},
		{{'F', 'G'}, 5},
		{{'E', 'B'}, 2},
		{{'G', 'B'}, 2},
	};
	struct dijkstra_ret ret;
	int i;

	ret = dijkstra(edges, sizeof(edges) / sizeof(edges[0]), 'A', 'B');
	if (ret.n > 0)
		printf("Solution: start=%c, end=%c, distance=%d, vertices=%s\n", ret.vertices[0], ret.vertices[ret.n - 1], ret.distance, ret.vertices);
	free(ret.vertices);
	return 0;
}
