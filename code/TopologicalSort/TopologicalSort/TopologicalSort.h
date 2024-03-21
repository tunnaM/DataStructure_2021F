#pragma once
#ifndef TOPOLOGICALSORT_H
#define TOPOLOGICALSORT_H

#include <stdlib.h>
#include "Status.h"
#include "AdjacencyList.h"

Status TopologicalSort(ALGraph G);
void FindInDegree(ALGraph G, int indegree[]);

#endif

