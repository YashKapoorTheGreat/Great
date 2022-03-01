#ifndef VISITOR_H
#define VISITOR_H

#include "../parser/node/node.h"
#include "value/value.h"

Value *visit(Node *node);

#endif
