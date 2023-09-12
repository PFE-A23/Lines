#ifndef LINE_H
#define LINE_H

#include "LinePrimitive.h"
#include "drwDataArray.h"

class drwSWFWriter;
class Vec3;

class Line : public LinePrimitive {

public:
  Line();
  ~Line();

  virtual void StartPoint(double x, double y, double pressure);
  virtual void EndPoint(double x, double y, double pressure);
  virtual void AddPoint(double x, double y, double pressure);

  void SetWidth(double width) { m_lineWidth = width; }

protected:
  void InternDraw(drwDrawingContext &context);

  double m_lineWidth;

  drwVec2Array m_pointTable;
  drwIndexArray m_pointIndex;
};

#endif
