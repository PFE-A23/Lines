#ifndef __Node_h_
#define __Node_h_

#include "IncludeGl.h"
#include "SharedPtrMacro.h"
#include "macros.h"
#include <SVL.h>

class Primitive;
class drwSWFWriter;
class drwDrawingContext;

class Node {

public:
  SharedPtrMacro(Node);

  Node();
  ~Node();

  void Draw(drwDrawingContext &context);

  SetMacro(Position, Vec2);
  GetMacro(Position, Vec2);

  void SetPrimitive(Primitive *prim) { ThePrimitive = prim; }
  Primitive *GetPrimitive() { return ThePrimitive; }

  GetMacro(Id, GLuint);

  SetMacro(IsHidden, bool);

protected:
  bool IsHidden;
  Vec2 Position;
  Primitive *ThePrimitive;

  GLuint Id;

  // Next id to be attributed
  static GLuint NextId;
};

#endif
