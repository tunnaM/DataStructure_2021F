#pragma once
#ifndef TOPOLOGICALORDER_H
#define TOPOLOGICALORDER_H

#include <stdlib.h>
#include "Status.h"
#include "AdjacencyList.h"
#include "Stack.h"

int ve[MAX_VERTEX_NUM];

Status TopologicalOrder(ALGraph G, SqStack* T);
void FindInDegree(ALGraph G, int indegree[]);

#endif

