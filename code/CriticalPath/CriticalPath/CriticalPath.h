#ifndef CRITICALPATH_H
#define CRITICALPATH_H

#include <stdlib.h>
#include "Status.h"
#include "AdjacencyList.h"
#include "Stack.h"
#include "TopologicalOrder.h"

Status CriticalPath(ALGraph G);

#endif