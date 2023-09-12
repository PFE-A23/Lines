#ifndef __Primitive_h_
#define __Primitive_h_

#include <SVL.h>

class drwDrawingContext;

class Primitive {

  enum RenderState { Done, Active, Dirty };

public:
  Primitive()
      : m_color(1.0, 1.0, 1.0, 1.0), m_boundingBox(0.0, 0.0, 0.0, 0.0) {}
  virtual ~Primitive() {}

  void Draw(drwDrawingContext &context) { InternDraw(context); }

  void SetColor(double r, double g, double b) { SetColor(r, g, b, 1.0); }
  void SetColor(double r, double g, double b, double a) {
    SetColor(Vec4(r, g, b, a));
  }
  void SetColor(const Vec4 &col) { m_color = col; }
  void SetRenderState(RenderState state) { m_renderState = state; }
  virtual const Box2d &BoundingBox() { return m_boundingBox; }

protected:
  virtual void InternDraw(drwDrawingContext &context) = 0;

  Vec4 m_color;
  RenderState m_renderState;
  Box2d m_boundingBox;
};

#endif
