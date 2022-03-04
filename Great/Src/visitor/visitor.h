#ifndef VISITOR_H
#define VISITOR_H

#include "../parser/node/node.h"
#include "type/type.h"

Type *visit(Node *node);

#endif
